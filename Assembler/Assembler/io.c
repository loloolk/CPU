#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE* openFile(char* filename, char* mode) {
    FILE* file = fopen(filename, mode);

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    return file;
}
void closeFile(FILE* file) {
    fclose(file);
}

void readLine(FILE* file, char* buffer) {
    if (fgets(buffer, 100, file) == NULL) {
        printf("Error: Could not read line from file\n");
        exit(1);
    }
}