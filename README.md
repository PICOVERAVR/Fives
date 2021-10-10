# Fives Processor
My first attempt at a 16-bit RISC processor, circa March 2019.

## Features
 - 31 (not 32!) 16-bit GPRs
 - register-register operands
 - IO instructions
 - `SEX` instruction for sign extension
 - ambitions of floating-point hardware support

## Layout
 - `common`: A small C helper library
 - `processor/hardware`: Verilog source files
 - `processor/soft_sim`: Processor simulator in C, builds with autotools :/
 - `processor/uarch_sim`: An incomplete Verilog microarchitecture simulator

