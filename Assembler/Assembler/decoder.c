#pragma once

enum DECODE_TABLE {
    // No Operation
    NOOP,

    // Register Input
    MOVE,
    IMMEDIATE,
    RESET,

    // Stack Operations
    PUSH,
    POP,

    // Arithmetic Operations
    ADD,
    SUB,
    AND,
    OR,
    NAND,
    NOR,
    XOR,
    XNOR,
    NOT,
    RSHIFT,
    LSHIFT,

    // Comparison Operations
    GREATER,
    EQUAL,
    NOT_EQUAL,
    LESS,

    // Immediate Arithmetic Operations
    ADDI,
    SUBI,

    // Immediate Comparison Operations
    GREATERI,
    EQUALI,
    NOT_EQUALI,
    LESSI,

    // Immediate Control Flow Operations
    JUMPI,

    // TEMP/DEBUG
    DBG,
    EXIT
};