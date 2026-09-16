`timescale 1ns/1ps

module tb_RISCV_Pipeline;
  reg clk;
  reg rst_n;

  RISCV_Pipeline dut (
    .clk(clk),
    .rst_n(rst_n)
  );

  initial clk = 0;
  always #5 clk = ~clk;

  // -------------------------------------------------------------------
  // Canary
  // -------------------------------------------------------------------
  localparam CANARY_WORD_IDX = 32'd0; // <-- TODO: set từ .map file
  localparam [31:0] CANARY_VALUE = 32'hDEADBEEF;

  // -------------------------------------------------------------------
  // Stack profiling — địa chỉ đỉnh stack (__stack_top)
  // -------------------------------------------------------------------
  localparam [31:0] STACK_TOP_BYTE = 32'd5120; // <-- TODO: set từ .map (giá trị khởi tạo của sp)

  integer fd;
  reg loaded;

  initial begin
    $display("========================================");
    $display(" RISC-V Pipeline Test: Recursion/Iteration");
    $display("========================================");

    loaded = 0;

    fd = $fopen("imem.hex", "r");
    if (fd != 0) begin
      $fclose(fd);
      $readmemh("imem.hex", dut.IMEM_inst.memory);
      $display("[TB] Loaded: imem.hex");
      loaded = 1;
    end

    if (!loaded) begin
      $display("[TB] *** ERROR *** Cannot find imem.hex!");
      $finish;
    end

    dut.DMEM_inst.memory[CANARY_WORD_IDX] = CANARY_VALUE;
    $display("[TB] Canary pre-loaded at DMEM word idx %0d = 0x%08h",
              CANARY_WORD_IDX, CANARY_VALUE);

    rst_n = 0;
    #20;
    rst_n = 1;
    $display("[TB] Reset released, simulation started");
  end

  integer cycle = 0;

  always @(posedge clk) begin
    cycle <= cycle + 1;
    if (cycle % 200 == 0 && cycle > 0)
      $display("[TB] Cycle %0d, PC=0x%08h", cycle, dut.PC_F);
  end

  // -------------------------------------------------------------------
  // Hardware counters cho CPI + Hazard breakdown
  //
  // LƯU Ý VỀ CÁCH ĐẾM (đã sửa so với bản trước):
  //
  //   Mỗi lần PCSel_E=1 (branch/jump taken), CÓ 2 lệnh bị squash, không
  //   phải 1:
  //     - lệnh đang ở ID lúc đó  -> bị chặn qua bubble_id_ex (cùng cycle)
  //     - lệnh đang ở IF lúc đó  -> bị flush_if_id xoá thành NOP, nhưng
  //       NOP này chỉ thật sự "biến mất" khi nó trôi từ ID sang EX ở
  //       CYCLE KẾ TIẾP. Ở cycle kế tiếp đó, bubble_id_ex thường đã về 0
  //       (trừ khi đúng lúc lại có hazard khác), nên nếu chỉ check
  //       bubble_id_ex thì NOP này bị đếm nhầm thành 1 lệnh thật.
  //
  //   Cách sửa: giữ thêm 1 bit trễ PCSel_E_d1, và loại trừ luôn cycle đó
  //   khỏi instr_count. Nhờ vậy instr_count phản ánh đúng số lệnh THẬT
  //   sự commit qua EX, không lẫn NOP "ma".
  //
  //   Tương tự, flush_count bên dưới đếm SỐ SỰ KIỆN redirect (không phải
  //   số cycle lãng phí). Số cycle lãng phí thực tế = flush_count * 2.
//   Cả hai được báo cáo riêng, có nhãn rõ ràng, để không bị nhầm lẫn
  //   giữa "tần suất rẽ nhánh" và "chi phí cycle".
  // -------------------------------------------------------------------
  integer instr_count;   // số lệnh thực sự "commit" qua EX (đã loại cả 2 loại bubble)
  integer stall_count;   // số cycle bị Load-Use stall (1 cycle/lần, đúng bằng số sự kiện)
  integer flush_count;   // số SỰ KIỆN redirect do rẽ nhánh/nhảy (PCSel_E) -- KHÔNG phải số cycle lãng phí
  reg     pipeline_filled;
  reg     PCSel_E_d1;    // PCSel_E trễ 1 cycle, dùng để bắt NOP "ma" do flush_if_id

  initial begin
    instr_count     = 0;
    stall_count     = 0;
    flush_count     = 0;
    pipeline_filled = 1'b0;
    PCSel_E_d1      = 1'b0;
  end

  // Bỏ qua 2 cycle đầu (fill pipeline, Instr_D vẫn là NOP mặc định do reset)
  always @(posedge clk) begin
    if (rst_n && !pipeline_filled && cycle >= 2)
      pipeline_filled <= 1'b1;

    if (rst_n && pipeline_filled) begin
      // Một lệnh chỉ được tính là "commit" nếu:
      //   (1) cycle này không có bubble do stall/redirect đang diễn ra, VÀ
      //   (2) cycle TRƯỚC đó không phải là một redirect event (nếu có,
      //       lệnh đang trôi vào EX cycle này thực chất là NOP do flush)
      if (!dut.bubble_id_ex && !PCSel_E_d1)
        instr_count <= instr_count + 1;

      // Đếm riêng nguyên nhân bubble (theo SỰ KIỆN, không nhân hệ số)
      if (dut.stall_load)
        stall_count <= stall_count + 1;
      if (dut.PCSel_E)
        flush_count <= flush_count + 1;
    end

    // Cập nhật bit trễ mỗi cycle (kể cả ngoài pipeline_filled, để luôn đồng bộ)
    PCSel_E_d1 <= dut.PCSel_E;
  end

  // -------------------------------------------------------------------
  // Stack usage — theo dõi đáy thấp nhất mà sp (x2) chạm tới
  //
  // LƯU Ý (đã sửa so với bản trước):
  //
  //   Bản cũ bắt đầu track min_sp ngay khi rst_n deassert, với điều kiện
  //   loại trừ duy nhất là "registers[2] != 0". Nhưng trong lúc crt0
  //   khởi tạo sp (lui sp,0x1 -> addi sp,sp,1024), regfile có một
  //   khoảnh khắc TRUNG GIAN sp = 4096 (giá trị của riêng lệnh `lui`,
  //   trước khi `addi` cộng thêm 1024 để ra sp thật = 5120). Giá trị
  //   4096 này bị bắt nhầm thành "min_sp" và không bao giờ bị thay thế
  //   nếu chương trình (như bản iterative) không bao giờ đẩy sp xuống
  //   sâu hơn 4096 thật sự -> Max stack usage bị báo sai (dư ra ~1KB
  //   không có thật).
  //
  //   Cách sửa: chỉ bắt đầu track min_sp SAU KHI sp đã chạm ĐÚNG giá trị
  //   đỉnh thật (STACK_TOP_BYTE) lần đầu tiên -- tức là sau khi chuỗi
  //   lệnh khởi tạo sp trong crt0 đã hoàn tất trọn vẹn, không còn giá
  //   trị trung gian nào lọt qua được nữa.
  // -------------------------------------------------------------------
  integer min_sp;
  integer min_sp_cycle;
reg     sp_initialized;   // NEW: chỉ track min_sp sau khi sp đã setup xong lần đầu

  initial begin
    min_sp         = STACK_TOP_BYTE; // khởi tạo bằng đỉnh stack ban đầu
    min_sp_cycle   = 0;
    sp_initialized = 1'b0;           // NEW
  end

  always @(posedge clk) begin
    // NEW: đánh dấu "đã init xong" ngay lần đầu tiên sp CHẠM ĐÚNG đỉnh thật
    if (rst_n && !sp_initialized &&
        dut.Reg_inst.registers[2] == STACK_TOP_BYTE)
      sp_initialized <= 1'b1;

    // CHANGED: chỉ track min sau khi sp_initialized, thay vì rst_n && != 0
    if (rst_n && sp_initialized &&
        dut.Reg_inst.registers[2] < min_sp) begin
      min_sp       <= dut.Reg_inst.registers[2];
      min_sp_cycle <= cycle;
    end
  end

  // -------------------------------------------------------------------
  // Done detection
  // -------------------------------------------------------------------
  reg        done_reported;
  integer    done_cycle;

  initial begin
    done_reported = 1'b0;
    done_cycle    = -1;
  end

  always @(posedge clk) begin
    if (rst_n && !done_reported &&
        dut.Is_Jump_E && (dut.PC_target_E == dut.PC_E)) begin
      done_cycle    = cycle;
      done_reported <= 1'b1;
      $display("[TB] *** HALT LOOP REACHED *** at cycle %0d, PC=0x%08h",
                cycle, dut.PC_E);
    end
  end

  always @(posedge clk) begin
    if (cycle < 70) begin
      $display("[TRACE] cycle=%0d  PC_D=0x%08h Instr_D=0x%08h  PCSel_E=%b stall_load=%b",
                cycle, dut.PC_D, dut.Instr_D, dut.PCSel_E, dut.stall_load);
    end
  end

  // Giữ lại cảnh báo overlap để debug, nhưng lưu ý: về mặt thiết kế,
  // stall_load và PCSel_E được suy ra từ CÙNG một lệnh đang ở EX
  // (Is_Load_E vs Is_Branch_E/Is_Jump_E loại trừ lẫn nhau khi decode),
  // nên dòng này về lý thuyết không bao giờ nên in ra. Nếu nó VẪN in ra
  // trong sim thật, đó là dấu hiệu có bug ở control_unit hoặc hazard_detect.
  always @(posedge clk) begin
    if (dut.stall_load && dut.PCSel_E)
      $display("[HAZARD-OVERLAP] cycle=%0d - stall_load and PCSel_E both 1! (should be impossible by design -- check control_unit decode)", cycle);
  end

  initial begin
    #300000;
    if (!done_reported) begin
      $display("[TB] *** WARNING *** Program never reached the halt loop within timeout.");
    end
    report_result;
    $finish;
  end

  always @(posedge clk) begin
    if (done_reported && cycle == done_cycle + 5) begin
      report_result;
      $finish;
    end
  end

  // -------------------------------------------------------------------
  // Báo cáo tổng hợp — CPI, hazard breakdown, stack footprint
  // -------------------------------------------------------------------
  task report_result;
    reg [31:0] canary_now;
    reg [31:0] a0;
    real cpi;
    integer stack_used_bytes;
    integer flush_penalty_cycles;   // = flush_count * 2, chi phí cycle thực tế
    integer total_overhead_cycles;
    begin
canary_now           = dut.DMEM_inst.memory[CANARY_WORD_IDX];
      a0                   = dut.Reg_inst.registers[10];
      cpi                  = (instr_count > 0) ? (real'(cycle) / real'(instr_count)) : 0.0;
      stack_used_bytes      = STACK_TOP_BYTE - min_sp;
      flush_penalty_cycles  = flush_count * 2;
      total_overhead_cycles = stall_count + flush_penalty_cycles;

      $display("========================================");
      $display("[TB] Simulation finished at cycle %0d", cycle);
      $display("[TB] a0 (status) = %0d (0 = pass, nonzero = fail)", $signed(a0));
      $display("[TB] Canary now  = 0x%08h (expected 0x%08h)", canary_now, CANARY_VALUE);

      if (!done_reported) begin
        $display("[TB] *** INCONCLUSIVE *** halt loop never reached -- so on numbers below are NOT trustworthy");
      end else if (a0 == 32'd0)
        $display("[TB] *** PASS *** status == 0");
      else
        $display("[TB] *** FAIL *** status == %0d", $signed(a0));

      if (canary_now !== CANARY_VALUE)
        $display("[TB] *** NOTE *** Canary corrupted -> stack overflow occurred");
      else
        $display("[TB] Canary intact -> no stack overflow detected");

      if (done_reported)
        $display("[TB] Cycles to completion = %0d", done_cycle);

      $display("[TB] Key registers:");
      $display("  x1(ra)  = %0d", dut.Reg_inst.registers[1]);
      $display("  x2(sp)  = %0d", dut.Reg_inst.registers[2]);
      $display("  x10(a0) = %0d", dut.Reg_inst.registers[10]);

      $display("----------------------------------------");
      $display("[REPORT] --- Architecture / Trade-off metrics ---");
      $display("[REPORT] Total cycles                       = %0d", cycle);
      $display("[REPORT] Instruction count (IC, corrected)  = %0d", instr_count);
      $display("[REPORT] CPI (corrected)                    = %0.3f", cpi);
      $display("[REPORT] --- Hazard breakdown ---");
      $display("[REPORT] Load-Use stall events/cycles       = %0d (%0.1f%% of total)",
                stall_count, 100.0 * real'(stall_count) / real'(cycle));
      $display("[REPORT] Branch/Jump redirect EVENTS        = %0d", flush_count);
      $display("[REPORT] Branch/Jump flush PENALTY cycles   = %0d (2 x events, %0.1f%% of total)",
                flush_penalty_cycles, 100.0 * real'(flush_penalty_cycles) / real'(cycle));
      $display("[REPORT] Total hazard overhead cycles       = %0d (%0.1f%% of total)",
                total_overhead_cycles, 100.0 * real'(total_overhead_cycles) / real'(cycle));
      $display("[REPORT] --- Stack usage ---");
      $display("[REPORT] Stack top (byte)                   = %0d", STACK_TOP_BYTE);
      $display("[REPORT] Min sp reached (byte)               = %0d (at cycle %0d)", min_sp, min_sp_cycle);
      $display("[REPORT] Max stack usage (bytes)             = %0d", stack_used_bytes);
      $display("----------------------------------------");
    end
  endtask

  initial begin
    $dumpfile("waveform.vcd");
$dumpvars(0, tb_RISCV_Pipeline);
  end

endmodule
