#include "CPU/CPU.c"

#include <stdio.h>

int main() {
    FILE* file = fopen("ROM.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open ROM.txt\n");
        return 1;
    }

    unsigned short address = 0;
    while (fscanf(file, "%u", &ROM[address++]) != EOF);
    
    fclose(file);

    execute();

    // status();
    return 0;
}