#include "Assembler/assembler.c"

int main(int argc, char** argv) {
    char* input = "input.txt";
    char* output = "output.txt";

    assemble(input, output);

    return 0;
}