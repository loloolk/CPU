#pragma once

// typedef struct stack {
//     unsigned short* data;
//     unsigned short offset;
// } stack_t;

unsigned short data[1 << 16];
unsigned short offset = 0;

void push(unsigned short value) {
    data[offset++] = value;
}

unsigned short pop() {
    return data[--offset];
}