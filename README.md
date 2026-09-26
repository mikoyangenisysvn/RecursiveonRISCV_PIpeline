# Recursive on RISC-V Pipeline

A learning-oriented implementation of a 32-bit, five-stage RISC-V pipeline. The project combines Verilog RTL, RISC-V software, memory images, and simulation outputs to study instruction flow, hazards, forwarding, branching, and recursive function calls.

> **Status:** This repository is an educational project. Build and simulation commands are provided in `runONcolab/Makefile`.

## Overview

The processor follows the classic five-stage pipeline:

1. **IF — Instruction Fetch**
2. **ID — Instruction Decode**
3. **EX — Execute**
4. **MEM — Memory Access**
5. **WB — Write Back**

Pipeline registers are used to transfer control and data signals between stages:

- `IF_ID_reg`
- `ID_EX_reg`
- `EX_MEM_reg`
- `MEM_WB_reg`

The design includes logic for data and control hazards, load-use stalls, operand forwarding, and branch/jump target resolution. Recursive software tests are used to exercise stack frames and dependent instructions.

## Main Features

- 32-bit RISC-V pipeline
- Register file, ALU, immediate generator, instruction memory, and data memory
- Main control and ALU decoders
- Forwarding for resolving data dependencies
- Hazard detection and pipeline stalls
- Branch comparison and branch/jump resolution
- Recursive C test program with RISC-V startup and linker files
- Icarus Verilog and Verilator simulation targets
- Optional Yosys synthesis and logic-equivalence-check targets
- Disassembly and memory-image generation from an ELF file

## Repository Structure

The tree below reflects the current contents of the `main` branch. `build/`, `runONcolab/build/`, and `runONcolab/obj_dir/` contain generated outputs and are not required source files.

```text
.
├── MEM/
│   ├── IMEM.hex
│   └── IMEM2.hex
├── README.md
├── build/
│   ├── test.dis
│   └── test2.dis
├── rtl/
│   ├── ALU.v
│   ├── ALU_decoder.v
│   ├── Branch_Comp.v
│   ├── Branch_Resovle.v
│   ├── DMEM.v
│   ├── EX_MEM_reg.v
│   ├── Forwarding_unit.v
│   ├── Hazard_Detect.v
│   ├── ID_EX_reg.v
│   ├── IF_ID_reg.v
│   ├── IMEM.v
│   ├── Imm_gen.v
│   ├── MEM_WB_reg.v
│   ├── PC.v
│   ├── RISCV_Pipeline.v
│   ├── RegisterFile.v
│   ├── control_unit.v
│   └── main_decoder.v
├── runONcolab/
│   ├── Makefile
│   ├── build/                  # Generated ELF, BIN, logs, and simulation files
│   ├── mem/
│   │   ├── dmem_init.hex
│   │   └── imem.hex
│   ├── obj_dir/                # Generated Verilator files
│   ├── pipeline.vcd
│   ├── recursive/
│   │   └── readME.md
│   ├── rtl/
│   │   └── RISCV_Pipeline.v
│   ├── sw/
│   │   ├── crt0.S
│   │   ├── linker.ld
│   │   └── test.c
│   ├── tb/
│   │   └── tb_RISCV_Pipeline.v
│   └── waveform.vcd
├── sw/
│   ├── README.txt
│   ├── crt0.S
│   ├── linker.ld
│   ├── test.C
│   └── test2.C
└── tb/
    ├── TBforTrackingStackFrame.v
    └── tb_RISCV_Pipeline.v
```

## Requirements

Install the tools required by the targets you intend to use:

- GNU Make
- RISC-V GCC/binutils toolchain with the `riscv-none-elf-` prefix
- Icarus Verilog (`iverilog`, `vvp`)
- Verilator
- Optional: Yosys for synthesis and equivalence checking
- Optional: GTKWave for viewing VCD waveforms

## Build and Run

The Makefile is located in `runONcolab/`, so run the commands from that directory:

```bash
cd runONcolab

# Show all available targets
make help

# Build the RISC-V program, generate memory images, and disassemble the ELF
make hex disasm

# Run both Icarus Verilog and Verilator simulations
make run

# Run one simulator only
make run_icarus
make run_verilator
```

Generated files are placed in `runONcolab/build/`, `runONcolab/mem/`, and `runONcolab/obj_dir/`. Simulation logs are written to `runONcolab/build/icarus_sim.txt` and `runONcolab/build/verilator_sim.txt`.

To remove generated files:

```bash
cd runONcolab
make clean
```

## Synthesis and Formal Checking

The Makefile also provides optional Yosys targets:

```bash
cd runONcolab
make syn   # Generate a synthesized netlist and synthesis report
make lec   # Run logic equivalence checking
```

## Test Programs

The software sources in `sw/` and `runONcolab/sw/` contain startup assembly, linker scripts, and recursive C programs. These programs are intended to test:

- Nested function calls and stack-frame handling
- Data dependencies and load-use hazards
- Forwarding and pipeline stalls
- Branch and jump behavior
- Instruction and data memory initialization

Compilation uses `-O0` in the provided Makefile so recursive calls and function prologues/epilogues remain visible during simulation.

## Waveforms

When waveform tracing is enabled, the simulation can produce VCD files such as `runONcolab/waveform.vcd` or `runONcolab/pipeline.vcd`. Open a waveform with GTKWave:

```bash
gtkwave runONcolab/waveform.vcd
```

The exact VCD filename depends on the testbench and simulator configuration.

## References

- [RISC-V International](https://riscv.org/)
- [RISC-V ISA Specifications](https://riscv.org/technical/specifications/)

## License

No license file is currently included. Add a license before distributing or reusing this project outside its intended educational context.

## Author

mikoyangenisysvn
