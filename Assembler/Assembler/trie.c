#pragma once

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "decoder.c"

typedef struct TRIE_NODE {
    char value;
    short correspondent;

    char opcodes;

    struct TRIE_NODE* children[26];
} TRIE_NODE;

TRIE_NODE* createNode(char value) {
    TRIE_NODE* node = (TRIE_NODE*)malloc(sizeof(TRIE_NODE));
    node->value = value;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    return node;
}

TRIE_NODE* insert(TRIE_NODE* root, char* word) {
    TRIE_NODE* current = root;

    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode(word[i]);
        }

        current = current->children[index];
    }

    return root;
}

TRIE_NODE* insertWord(TRIE_NODE* root, char* word, short correspondent, char opcodes) {
    TRIE_NODE* current = root;

    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode(word[i]);
        }

        current = current->children[index];
    }

    current->correspondent = correspondent;
    current->opcodes = opcodes;

    return root;
}

TRIE_NODE* opcodeTrie() {
    TRIE_NODE* root = createNode(' ');

    root = insertWord(root, "noop", NOOP, 0b0);

    root = insertWord(root, "mov", MOVE, 0b101);
    root = insertWord(root, "imm", IMMEDIATE, 0b101);
    root = insertWord(root, "res", RESET, 0b100);

    root = insertWord(root, "push", PUSH, 0b100);
    root = insertWord(root, "pop", POP, 0b001);

    root = insertWord(root, "add", ADD, 0b111);
    root = insertWord(root, "sub", SUB, 0b111);
    root = insertWord(root, "and", AND, 0b111);
    root = insertWord(root, "or", OR, 0b111);
    root = insertWord(root, "nand", NAND, 0b111);
    root = insertWord(root, "nor", NOR, 0b111);
    root = insertWord(root, "xor", XOR, 0b111);
    root = insertWord(root, "xnor", XNOR, 0b111);
    root = insertWord(root, "not", NOT, 0b101);
    root = insertWord(root, "shr", RSHIFT, 0b101);
    root = insertWord(root, "shl", LSHIFT, 0b101);

    root = insertWord(root, "igt", GREATER, 0b111);
    root = insertWord(root, "ieq", EQUAL, 0b111);
    root = insertWord(root, "ineq", NOT_EQUAL, 0b111);
    root = insertWord(root, "ilt", LESS, 0b111);

    root = insertWord(root, "addi", ADDI, 0b111);
    root = insertWord(root, "subi", SUBI, 0b111);
    
    root = insertWord(root, "igti", GREATERI, 0b111);
    root = insertWord(root, "ieqi", EQUALI, 0b111);
    root = insertWord(root, "ineqi", NOT_EQUALI, 0b111);
    root = insertWord(root, "ilti", LESSI, 0b111);

    root = insertWord(root, "jmpi", JUMPI, 0b101);

    root = insertWord(root, "dbg", DBG, 0b000);
    root = insertWord(root, "exit", EXIT, 0b000);

    return root;
}