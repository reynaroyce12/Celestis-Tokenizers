#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Tokenizer(FILE *input, FILE *output) {
    char textBuffer[1024];

    char delimitters[128];
    int index = 0;

    for (int i = 0; i < 128; i++) {
        if (isprint(i) && !isalnum(i)) {
            delimitters[index++] = (char)i;
        }
    }
    delimitters[index] = '\0';

    while(fgets(textBuffer, sizeof(textBuffer), input)) {
        char *token = strtok(textBuffer, delimitters);

        while (token != NULL) {
            fprintf(output, "%s ", token);
            token = strtok(NULL, delimitters);
        }
    }
}

// Pass a list of delimitters (All possible from the ASCII list)  ✅
// Ctype library to generate all the printable chars (isprint funciton) ✅