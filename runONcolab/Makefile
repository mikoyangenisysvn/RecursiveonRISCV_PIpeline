#=============================================================================
# Generic RISC-V / Verilog Makefile
#=============================================================================

# ============================================
# CHỈ SỬA PHẦN NÀY CHO MỖI ĐỒ ÁN
# ============================================
RTL_TOP        = RISCV_Pipeline
TB_TOP         = tb_RISCV_Pipeline
ARCH           = rv32i
ABI            = ilp32
# ============================================

#--------------------------------------------------------------------------
# Toolchain
#--------------------------------------------------------------------------
RISCV_PREFIX  ?= riscv-none-elf
CC             = $(RISCV_PREFIX)-gcc
OBJCOPY        = $(RISCV_PREFIX)-objcopy
OBJDUMP        = $(RISCV_PREFIX)-objdump

IVERILOG       = iverilog
VVP            = vvp
VERILATOR      = verilator
YOSYS          = yosys

#--------------------------------------------------------------------------
# Directories
#--------------------------------------------------------------------------
BUILD_DIR      = build
MEM_DIR        = mem
RTL_DIR        = rtl
TB_DIR         = tb
SW_DIR         = sw

#--------------------------------------------------------------------------
# Auto-detect sources
#--------------------------------------------------------------------------
C_SRCS         = $(wildcard $(SW_DIR)/*.c)
ASM_SRCS       = $(wildcard $(SW_DIR)/*.S)
ALL_SRCS       = $(ASM_SRCS) $(C_SRCS)

LD_SCRIPT      = $(wildcard $(SW_DIR)/*.ld)
ifeq ($(LD_SCRIPT),)
  LD_SCRIPT    = $(SW_DIR)/linker.ld
endif

#--------------------------------------------------------------------------
# Outputs
#--------------------------------------------------------------------------
ELF            = $(BUILD_DIR)/test.elf
IMEM_BIN       = $(BUILD_DIR)/imem.bin
DMEM_BIN       = $(BUILD_DIR)/dmem.bin
IMEM_HEX       = $(MEM_DIR)/imem.hex
DMEM_HEX       = $(MEM_DIR)/dmem_init.hex
DISASM_OUT     = $(BUILD_DIR)/test.dis
SYNTH_NETLIST  = $(BUILD_DIR)/synth.v
SYNTH_RPT      = $(BUILD_DIR)/synth.rpt
LEC_RPT        = $(BUILD_DIR)/lec.rpt
ICARUS_VVP     = $(BUILD_DIR)/sim.vvp
# File log cho ket qua sim (duoc ghi lai moi lan chay make run / run_icarus /
# run_verilator, khong bi mat khi chay lan sau vi moi lan deu ghi de).
ICARUS_LOG     = $(BUILD_DIR)/icarus_sim.txt
VERILATOR_LOG  = $(BUILD_DIR)/verilator_sim.txt

#--------------------------------------------------------------------------
# Flags
#--------------------------------------------------------------------------
# NOTE: Da doi -O2 -> -O0.
# Ly do: o -O2, GCC co the chung minh recursive_sum(100) va reference_sum(100)
# la constant-foldable (tham so 100 la hang so bien dich, ca hai ham deu thuan
# tuy), nen no xoa het loi goi de quy va khoi if(result != expected), chi con
# lai phan kiem tra STACK_CANARY (vi bien do la volatile). Ket qua: chuong
# trinh khong con "de quy that" de stress-test pipeline/stack nhu y do ban dau.
# -O0 giu nguyen prologue/epilogue chuan cho moi lan goi ham, dung nhu comment
# trong main.c mo ta.
CFLAGS         = -march=$(ARCH) -mabi=$(ABI) -O0 -Wall -nostdlib -ffreestanding
LDFLAGS        = -T $(LD_SCRIPT) -nostdlib
# LIBS: ARCH=rv32i khong co phan cung nhan/chia (khong co extension M), nen
# cac phep toan nhu n*(n+1) trong reference_sum() duoc GCC bien dich thanh
# loi goi ham phan mem __mulsi3 (nam trong libgcc). -nostdlib loai bo moi
# thu vien chuan bao gom ca libgcc, nen phai them lai -lgcc rieng de linker
# tim thay __mulsi3/__divsi3/...
# QUAN TRONG: -lgcc phai dung o day (bien LIBS rieng), duoc them SAU
# $(ALL_SRCS) trong rule bien dich ben duoi -- vi GNU ld chi quet mot thu
# vien tinh (.a) MOT LAN, theo thu tu trai->phai, de giai quyet cac symbol
# con thieu TINH DEN THOI DIEM DO. Neu dat -lgcc trong LDFLAGS (dung truoc
# $(ALL_SRCS) trong dong lenh), linker doc libgcc.a truoc khi biet test.c
# can __mulsi3, nen van bao "undefined reference" y het nhu chua co -lgcc.
LIBS           = -lgcc

#--------------------------------------------------------------------------
# Phony Targets
#--------------------------------------------------------------------------
.PHONY: all hex disasm run run_icarus run_verilator syn lec wave clean help
all: hex disasm

help:
	@echo "Targets:"
	@echo "  make hex          - Compile -> ELF -> BIN -> HEX"
	@echo "  make disasm       - Disassemble ELF"
	@echo "  make run          - Run Icarus + Verilator"
	@echo "  make run_icarus   - Run Icarus Verilog"
	@echo "  make run_verilator- Run Verilator"
	@echo "  make syn          - Synthesize with Yosys (writes synth.rpt)"
	@echo "  make lec          - Logic Equivalence Check (writes lec.rpt)"
	@echo "  make clean        - Clean everything"

#--------------------------------------------------------------------------
# Build dir
#--------------------------------------------------------------------------
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

#--------------------------------------------------------------------------
# Compile -> ELF
#--------------------------------------------------------------------------
$(ELF): $(ALL_SRCS) $(LD_SCRIPT) | $(BUILD_DIR)
ifeq ($(ALL_SRCS),)
	$(error "Khong tim thay file .c hay .S nao trong $(SW_DIR)/")
endif
	@echo "[GCC] Sources: $(ALL_SRCS)"
	$(CC) $(CFLAGS) $(LDFLAGS) $(ALL_SRCS) $(LIBS) -o $@

#--------------------------------------------------------------------------
# ELF -> BIN
#--------------------------------------------------------------------------
$(IMEM_BIN): $(ELF)
	@echo "[OBJCOPY] .text -> $@"
	$(OBJCOPY) -O binary --only-section=.text $< $@

$(DMEM_BIN): $(ELF)
	@echo "[OBJCOPY] .data -> $@"
	$(OBJCOPY) -O binary --only-section=.data $< $@ 2>/dev/null || \
	$(OBJCOPY) -O binary --only-section=.sdata $< $@ 2>/dev/null || \
	touch $@

#--------------------------------------------------------------------------
# BIN -> HEX
#--------------------------------------------------------------------------
$(IMEM_HEX): $(IMEM_BIN)
	@mkdir -p $(MEM_DIR)
	od -An -tx4 -w4 -v $< | tr -d ' ' > $@

$(DMEM_HEX): $(DMEM_BIN)
	@mkdir -p $(MEM_DIR)
	od -An -tx4 -w4 -v $< | tr -d ' ' > $@

hex: $(IMEM_HEX) $(DMEM_HEX)

#--------------------------------------------------------------------------
# Disassembly
#--------------------------------------------------------------------------
$(DISASM_OUT): $(ELF)
	@echo "[OBJDUMP] Disassembling $<"
	$(OBJDUMP) -d -M no-aliases $< > $@

disasm: $(DISASM_OUT)

#--------------------------------------------------------------------------
# Simulation
#--------------------------------------------------------------------------
run: hex run_icarus run_verilator

run_icarus: hex $(ICARUS_VVP)
	@echo "[VVP] Running Icarus..."
	@echo "[VVP] Log se duoc ghi vao $(ICARUS_LOG)"
	$(VVP) $(ICARUS_VVP) 2>&1 | tee $(ICARUS_LOG)

$(ICARUS_VVP): $(RTL_DIR)/$(RTL_TOP).v $(TB_DIR)/$(TB_TOP).v | $(BUILD_DIR)
	$(IVERILOG) -g2012 -o $@ $^

run_verilator: hex
	@echo "[VERILATOR] Building & running..."
	rm -rf obj_dir
	$(VERILATOR) --binary -j 0 -Wall --trace -Wno-fatal \
		--top-module $(TB_TOP) \
		$(RTL_DIR)/$(RTL_TOP).v \
		$(TB_DIR)/$(TB_TOP).v
	@echo "[VERILATOR] Log se duoc ghi vao $(VERILATOR_LOG)"
	./obj_dir/V$(TB_TOP) 2>&1 | tee $(VERILATOR_LOG)

#--------------------------------------------------------------------------
# Synthesis (always re-run, writes report)
#--------------------------------------------------------------------------
syn: $(SYNTH_NETLIST)

$(SYNTH_NETLIST): $(RTL_DIR)/$(RTL_TOP).v | $(BUILD_DIR)
	@echo "[YOSYS] Synthesizing..."
	$(YOSYS) -p " \
		read_verilog $<; \
		hierarchy -top $(RTL_TOP); \
		flatten; \
		synth; \
		opt; \
		rename -top $(RTL_TOP)_gate; \
		write_verilog -noattr $@ \
	" 2>&1 | tee $(SYNTH_RPT)



#--------------------------------------------------------------------------
# LEC (always re-run, writes report)
#--------------------------------------------------------------------------
lec: syn
	@echo "[YOSYS] Running LEC..."
	$(YOSYS) -p " \
		read_verilog $(RTL_DIR)/$(RTL_TOP).v; \
		hierarchy -top $(RTL_TOP); \
		flatten; \
		design -save gold; \
		read_verilog $(SYNTH_NETLIST); \
		hierarchy -top $(RTL_TOP)_gate; \
		design -save gate; \
		design -copy-from gold -as gold $(RTL_TOP); \
		design -copy-from gate -as gate $(RTL_TOP)_gate; \
		equiv_make gold gate equiv; \
		hierarchy -top equiv; \
		clean; \
		equiv_simple -seq 5; \
		equiv_induct -seq 5; \
		equiv_status -assert \
	" 2>&1 | tee $(LEC_RPT)




#--------------------------------------------------------------------------
# GTKWave
#--------------------------------------------------------------------------
GTKWAVE    = gtkwave
VCD_FILE   ?= trace.vcd

wave:
	@echo "[GTKWAVE] Opening $(VCD_FILE)..."
	$(GTKWAVE) $(VCD_FILE) &


#--------------------------------------------------------------------------
# Clean
#--------------------------------------------------------------------------
clean:
	rm -rf $(BUILD_DIR)/* $(MEM_DIR)/*.hex obj_dir
	@echo "Clean done."