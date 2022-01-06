# Fives Processor
My first attempt at a 16-bit RISC processor, circa March 2019.

## Features
 - 32 16-bit GPRs, with hardwired zero and stack pointer registers
 - most arithmetic and logical operations have byte and word variants
 - no status registers, just compare and branch
 - dedicated IO instructions
 - wildly ambitious expectations of hardware floating-point support

## Layout
 - `common`: A small C helper library
 - `processor/hardware`: (incomplete) Verilog for a hardware implementation
 - `processor/soft_sim`: Processor simulator in C, builds with... autotools...
 - `processor/uarch_sim`: (incomplete) Verilog for a high-level hardware simulator
