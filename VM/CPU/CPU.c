#pragma once

#include <stdio.h>
#include "decoder.c"
#include "stack.c"

unsigned short input = 0; /// implement step by step system later
unsigned short REGISTERS[7] = {0}; // 8th register is input
unsigned short output[1 << 8] = {0};

unsigned short PROGRAM_COUNTER = 0;
unsigned short ROM[1 << 8] = {0xffff};

void status();

void execute() {
    printf("Executing...\n");
    while (1) {
        unsigned short opcode = ROM[PROGRAM_COUNTER++];
        unsigned short operand1 = ROM[PROGRAM_COUNTER++];
        unsigned short operand2 = ROM[PROGRAM_COUNTER++];
        unsigned short operand3 = ROM[PROGRAM_COUNTER++];

        switch (opcode) {
            case NOOP:
                break;
            
            case MOVE:
                REGISTERS[operand3] = REGISTERS[operand1];
                break;
            case IMMEDIATE:
                REGISTERS[operand3] = operand1;
                break;
            case RESET:
                REGISTERS[operand1] = 0;
                break;
            
            case PUSH:
                push(REGISTERS[operand1]);
                break;
            case POP:
                REGISTERS[operand3] = pop();
                break;
            
            case ADD:
                REGISTERS[operand3] = REGISTERS[operand1] + REGISTERS[operand2];
                break;
            case SUB:
                REGISTERS[operand3] = REGISTERS[operand1] - REGISTERS[operand2];
                break;
            case AND:
                REGISTERS[operand3] = REGISTERS[operand1] & REGISTERS[operand2];
                break;
            case OR:
                REGISTERS[operand3] = REGISTERS[operand1] | REGISTERS[operand2];
                break;
            case NAND:
                REGISTERS[operand3] = ~(REGISTERS[operand1] & REGISTERS[operand2]);
                break;
            case NOR:
                REGISTERS[operand3] = ~(REGISTERS[operand1] | REGISTERS[operand2]);
                break;
            case XOR:
                REGISTERS[operand3] = REGISTERS[operand1] ^ REGISTERS[operand2];
                break;
            case XNOR:
                REGISTERS[operand3] = ~(REGISTERS[operand1] ^ REGISTERS[operand2]);
                break;
            case NOT:
                REGISTERS[operand3] = ~REGISTERS[operand1];
                break;

            case GREATER:
                if (REGISTERS[operand1] > REGISTERS[operand2])
                    PROGRAM_COUNTER = operand3;
                break;
            case EQUAL:
                if (REGISTERS[operand1] == REGISTERS[operand2])
                    PROGRAM_COUNTER = operand3;
                break;
            case NOT_EQUAL:
                if (REGISTERS[operand1] != REGISTERS[operand2])
                    PROGRAM_COUNTER = operand3;
                break;
            case LESS:
                if (REGISTERS[operand1] < REGISTERS[operand2])
                    PROGRAM_COUNTER = operand3;
                break;

            case ADDI:
                REGISTERS[operand3] = REGISTERS[operand1] + operand2;
                break;
            case SUBI:
                REGISTERS[operand3] = REGISTERS[operand1] - operand2;
                break;
            case GREATERI:
                if (REGISTERS[operand1] > operand2)
                    PROGRAM_COUNTER = operand3;
                break;
            case EQUALI:
                if (REGISTERS[operand1] == operand2)
                    PROGRAM_COUNTER = operand3;
                break;
            case NOT_EQUALI:
                if (REGISTERS[operand1] != operand2)
                    PROGRAM_COUNTER = operand3;
                break;
            case LESSI:
                if (REGISTERS[operand1] < operand2)
                    PROGRAM_COUNTER = operand3;
                break;
            
            case JUMPI:
                PROGRAM_COUNTER = operand3 * 4;
                break;

            case DBG:
                status();
                break;
            case EXIT:
                return;
        }
    }
}

void status() {
    printf("Registers: ");
    for (int i = 0; i < 7; i++)
        printf("R%d: %d ", i, REGISTERS[i]);
    printf("Input: %d\n", input);
    printf("Program Counter: %d\n", PROGRAM_COUNTER);
    printf("Stack: ");
    for (int i = 0; i < offset; i++)
        printf("%d ", data[i]);
    printf("\n");
}
