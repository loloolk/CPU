#pragma once

#include "trie.c"
#include "io.c"

void assemble(char* input_file, char* output_file) {
    FILE* input = openFile(input_file, "r");
    FILE* output = openFile(output_file, "wb");
    char buffer[100];

    TRIE_NODE* root = opcodeTrie();

    while (1) {
        // Get line from input file
        readLine(input, buffer);
        
        // Check trie for opcode
        TRIE_NODE* current = root;
        int i = 0;

        // Traverse trie until end of opcode
        for (i; i < strlen(buffer) && buffer[i] != ' ' && buffer[i] != '\n'; i++) {
            int index = buffer[i] - 'a';

            if (current->children[index] == NULL) {
                printf("Error: Invalid opcode\n");
                exit(1);
            }

            current = current->children[index];
        }
        // Write opcode to output file
        fprintf(output, "%hu ", current->correspondent);

        for (int j = 0; j < 3; j++) {
            unsigned short num = 0;
            int t = 0b100 >> j;

            if (current->opcodes & t) {
                while (buffer[++i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0') {
                    num = num * 10 + (buffer[i] - '0');
                }
            }
            fprintf(output, "%hu ", num);
        }

        if (feof(input)) {
            break;
        }
    }

    fclose(input);
    fclose(output);
}