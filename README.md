# CPU
A 16-bit CPU, made with logisim evolution, and a (badly made) program that converts the .alt file from sudo assembly  (pretty understandable if you read the code) int the nessecary inputs for the CPU.

INSTRUCTIONS (for c++ file)
In "code.alt" put in your code, and run it. it will give you the nesessary inputs for the 4 ROM chips.
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

REGISTERS:
R0: Register 0
R1: Register 1
R2: Register 2
R3: Register 3
R4: Register 4
R5: Register 5
R6: Register 6
IP: Input NOTE: Do not use as second condition.
OU: Output NOTE: Do not use as first condition.
DIS: Display screen (RGB 565 format)
