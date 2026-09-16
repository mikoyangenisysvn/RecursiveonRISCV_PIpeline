//stack tracking tb
// =============================================================================
// tb_stack_observer.v
// Testbench quan st QU TRNH SINH STACK FRAME theo thi gian thc.
// Khc vi tb_RISCV_Pipeline gc (ch tng kt CPI/hazard  cui), bn ny
// in ra TNG S KIN ngay lc n xy ra:
//   - Mi ln sp (x2) thay i  -> bit ang PUSH (call) hay POP (return),
//     v ang   su  quy bao nhiu.
//   - Mi ln CPU ghi vo vng stack (addr nm trong di stack) -> bit
//     gi tr g c ct vo frame no, ti a ch no.
// =============================================================================

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
  // Canary + load chng trnh (gi nguyn nh bn gc)
  // -------------------------------------------------------------------
  localparam CANARY_WORD_IDX = 32'd0;
  localparam [31:0] CANARY_VALUE = 32'hDEADBEEF;
  localparam [31:0] STACK_TOP_BYTE = 32'd5120; // = 0x1400, __stack_top

  // Ngng  phn bit "vng stack" vi ".data/.bss/.canary":
  // frame u tin ca recursive_sum(100) bt u ngay di __stack_top,
  // nn ch cn addr < STACK_TOP_BYTE v addr >= STACK_LOW_GUESS l coi
  // nh ang ghi vo stack. t STACK_LOW_GUESS thp hn mc dng thc t
  // mt cht  chc chn khng b st frame no.
  localparam [31:0] STACK_LOW_GUESS = 32'd1024; // 0x400 + 0x300, tu chnh nu cn

  integer fd;
  reg loaded;

  initial begin
    $display("========================================");
    $display(" Stack Frame Observer");
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
    $display("----------------------------------------");
  end

  integer cycle = 0;
  always @(posedge clk) cycle <= cycle + 1;

  // -------------------------------------------------------------------
  // 1) THEO DI SP (x2) THAY I  ->  PUSH / POP +  su  quy
  // -------------------------------------------------------------------
  reg [31:0] sp_prev;
  integer    depth;       // so frame dang mo (do sau de quy HIEN TAI)
  integer    max_depth;   // do sau LON NHAT tung dat toi (khong giam)
  reg        sp_tracking; // chi bat dau track sau khi sp da init xong (= STACK_TOP_BYTE)

  initial begin
    sp_prev     = 32'd0;
    depth       = 0;
    max_depth   = 0;
    sp_tracking = 1'b0;
  end

  always @(posedge clk) begin
    if (rst_n) begin
      if (!sp_tracking) begin
        // Ch crt0 khi to xong sp = __stack_top ri mi bt u theo di,
        // trnh bt nhm gi tr trung gian lc lui/addi dng sp.
        if (dut.Reg_inst.registers[2] == STACK_TOP_BYTE) begin
          sp_tracking <= 1'b1;
          sp_prev     <= dut.Reg_inst.registers[2];
          $display("[SP ] cycle=%0d  sp initialized = 0x%08h (top of stack)",
                    cycle, dut.Reg_inst.registers[2]);
        end
      end else if (dut.Reg_inst.registers[2] != sp_prev) begin
        if (dut.Reg_inst.registers[2] < sp_prev) begin
          depth = depth + 1;
          if (depth > max_depth) max_depth = depth;
          $display("[SP ] cycle=%0d  PUSH  sp: 0x%08h -> 0x%08h  (depth=%0d, frame size=%0d B)",
                    cycle, sp_prev, dut.Reg_inst.registers[2], depth,
                    sp_prev - dut.Reg_inst.registers[2]);
        end else begin
          $display("[SP ] cycle=%0d  POP   sp: 0x%08h -> 0x%08h  (depth=%0d, frame size=%0d B)",
                    cycle, sp_prev, dut.Reg_inst.registers[2], depth,
                    dut.Reg_inst.registers[2] - sp_prev);
          depth = depth - 1;
        end
        sp_prev <= dut.Reg_inst.registers[2];
      end
    end
  end

  // -------------------------------------------------------------------
  // 2) THEO DI TNG LN GHI VO VNG STACK
  //    (bt trc tip ti cng vo ca Data_Memory: MemRW_M + ALU_out_M)
  // -------------------------------------------------------------------
  always @(posedge clk) begin
    if (rst_n && dut.MemRW_M &&
        dut.ALU_out_M >= STACK_LOW_GUESS && dut.ALU_out_M < STACK_TOP_BYTE) begin
      $display("[MEM] cycle=%0d  STORE addr=0x%08h  data=0x%08h  (offset from stack top = -%0d B, depth~=%0d)",
                cycle, dut.ALU_out_M, dut.DataB_M,
                STACK_TOP_BYTE - dut.ALU_out_M, depth);
    end
  end

  // -------------------------------------------------------------------
  // Done detection + kt thc m phng (rt gn t bn gc)
  // -------------------------------------------------------------------
  reg     done_reported;
  integer done_cycle;

  initial begin
    done_reported = 1'b0;
    done_cycle    = -1;
  end

  always @(posedge clk) begin
    if (rst_n && !done_reported &&
        dut.Is_Jump_E && (dut.PC_target_E == dut.PC_E)) begin
      done_cycle    = cycle;
      done_reported <= 1'b1;
      $display("----------------------------------------");
      $display("[TB] *** HALT LOOP REACHED *** at cycle %0d", cycle);
    end
  end

  initial begin
    #300000;
    if (!done_reported)
      $display("[TB] *** WARNING *** timeout, cha ti halt loop.");
    $display("[TB] Max recursion depth observed = %0d", max_depth);
    $display("[TB] a0 (status) = %0d", $signed(dut.Reg_inst.registers[10]));
    $finish;
  end

  always @(posedge clk) begin
    if (done_reported && cycle == done_cycle + 5) begin
      $display("[TB] Max recursion depth observed = %0d", max_depth);
      $display("[TB] a0 (status) = %0d", $signed(dut.Reg_inst.registers[10]));
      $finish;
    end
  end

  initial begin
    $dumpfile("waveform.vcd");
    $dumpvars(0, tb_RISCV_Pipeline);
  end

endmodule
