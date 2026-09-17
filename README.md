# Recursive on RISC-V Pipeline

This project implements a 5-stage RISC-V pipeline in Verilog, designed to execute instructions in a realistic pipelined processor architecture. The design focuses on correct instruction flow, hazard handling, data forwarding, and branch resolution, while validating behavior using recursive software programs and simulation-based testbenches.

## Project Overview

The system is built around a simplified RISC-V processor pipeline with the following stages:

1. IF – Instruction Fetch
2. ID – Instruction Decode
3. EX – Execute
4. MEM – Memory Access
5. WB – Write Back

The design includes essential pipeline control logic to handle:

- Data hazards
- Control hazards
- Load-use hazards
- Forwarding between pipeline stages
- Branch and jump target resolution

This project is intended for digital logic design and computer architecture study, with emphasis on how a processor behaves under real execution conditions.

## Objectives

The main objectives of this project are:

- Implement a RISC-V pipeline in Verilog
- Understand instruction flow through multiple pipeline stages
- Resolve hazard conditions in a correct and efficient manner
- Support branch/jump behavior and data forwarding
- Validate processor correctness using recursive software workloads
- Analyze stack usage and memory safety under nested function calls

## Features

- 32-bit RISC-V pipeline architecture
- Register file and instruction memory
- Data memory and immediate generation
- Control unit and main decoder
- ALU and branch comparison logic
- Forwarding unit for operand bypassing
- Hazard detection logic for stalls
- Branch/jump resolution with PC correction
- Recursive software test program to stress pipeline hazards

## Pipeline Structure

The processor is organized as a conventional pipeline, with intermediate registers between stages:

- IF/ID
- ID/EX
- EX/MEM
- MEM/WB

These stage boundaries enable parallel instruction execution while preserving data integrity and controlling the flow of signals between cycles.

## Repository Structure

```text
.
├── MEM/               # Memory-related files or outputs
├── build/             # Build and generated artifacts
├── rtl/               # Verilog RTL implementation
│   ├── ALU.v
│   ├── ALU_decoder.v
│   ├── Branch_Comp.v
│   ├── Branch_Resovle.v
│   ├── control_unit.v
│   ├── DMEM.v
│   ├── EX_MEM_reg.v
│   ├── Forwarding_unit.v
│   ├── Hazard_Detect.v
│   ├── ID_EX_reg.v
│   ├── IF_ID_reg.v
│   ├── IMEM.v
│   ├── Imm_gen.v
│   ├── main_decoder.v
│   ├── MEM_WB_reg.v
│   ├── PC.v
│   ├── RegisterFile.v
│   └── RISCV_Pipeline.v
├── sw/                # Software test programs and startup files
│   ├── crt0.S
│   ├── linker.ld
│   ├── README.txt
│   ├── test.C
│   └── test2.C
├── tb/                # Simulation testbenches
│   ├── TBforTrackingStackFrame.v
│   └── tb_RISCV_Pipeline.v
└── README.md
