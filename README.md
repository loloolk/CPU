# CPU

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Description:
A 16-bit CPU, made with logisim evolution. This contains the CPU's Circuitry in `CPU`, an assembler for the CPU (from assembly to machine code) in `Assembler` and a Virtual Machine for the CPU in `VM`.

## Quick Start (CPU Simulation):
1) Download [logisim evolution](https://sourceforge.net/projects/logisimevolution/)
2) Open `CPU/CPU.circ` in logisim evolution
3) Open `Assembler/input.txt` and put in your code
4) Run the `Assembler/main.c` file
5) Copy the `Assembler/outut.txt` into the ROM chips
6) Run the CPU

## ASSEMBLER INSTRUCTIONS:
The Program currently made calculates the first few fibonacci numbers, and prints them out.

In `Assembler/input.txt` put in your code, and run it. it will give you the nesessary inputs for the 4 ROM chips.
1) NOOP: No operation, nothing happens.
2) MOV [Reg] [Reg]: Moves the values in the first register, to the second register.
3) IMM [Val] [Reg]: Moves the value immediately into the designated register.
4) PUSH [Reg]: Pushes the value in the register onto the stack. NOTE: Does not clear register.
5) POP [Reg]: Takes the top value on the stack, and puts it into the register.

6) RES [Reg]: Resets the register to 0x0000.
7) ADD [Reg] [Reg] [Reg]: Adds the first two registers, and puts it into the third register.
8) SUB [Reg] [Reg] [Reg]: Subtracts ^
9) AND [Reg] [Reg] [Reg]: Ands ^
10) OR [Reg] [Reg] [Reg]: Ors
11) NAND [Reg] [Reg] [Reg]: Nands ^
12) NOR [Reg] [Reg] [Reg]: Nors ^
13) XOR [Reg] [Reg] [Reg]: Xors ^
14) XNOR [Reg] [Reg] [Reg]: Xnors ^
15) NOT [Reg] [Reg]: Nots the first register, and puts it into the second register.
16) SHR [Reg] [Reg]: Shifts right ^
17) SHL [Reg] [Reg]: Shifts left ^
18) IGT [Reg] [Reg] [Val]: Checks if the first register is greater than the second register, and if it is it jumps to the designated address in the program. NOTE: Address is in hex.
19) IEQ [Reg] [Reg] [Val]: ^ is equal to ^
20) INEQ [Reg] [Reg] [Val]: ^ is not equal to ^
21) ILT [Reg] [Reg] [Val]: ^ is less than ^
22) ADDi [Reg] [Val] [Reg]: Adds the first register with the value, and puts it in the second register. NOTE: Value is in hex.
23) SUBi [Reg] [Val] [Reg]: Subtracts ^
24) IGTi [Reg] [Val] [Val]: Checks if the register is greater than the value, and if it is, jumps to the address in the program. NOTE: Both values are in hex.
25) IEQi [Reg] [Val] [Val]: ^ is equal to ^
26) INEQi [Reg] [Val] [Val]: ^ is not equal to ^
27) ILTi [Reg] [Val] [Val]: ^ is less than ^
28) JMP [Val]: Immediately jumps to the address in the program. NOTE: Value is in hex.

29) DBG: Additional command for debugging purposes. Will print out the values of the registers if running in VM. Do not use for CPU simulation.
30) EXIT: Additional command for debugging purposes. Will exit the program if running in VM. Do not use for CPU simulation.

## VM INSTRUCTIONS:
The Program currently compiled calculates the first few fibonacci numbers, and prints them out.
1) In `VM/ROM.txt` put in your code in machine code (from the assembler)
2) Run the `VM/main.c` file
NOTE: There is no GUI for the VM, so using the display screen will not work.

## License
This project is licensed under the [MIT License](LICENSE).