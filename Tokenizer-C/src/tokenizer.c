#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Tokenizer(FILE *input, FILE *output) {
    char textBuffer[1024];

    while (fgets(textBuffer, sizeof(textBuffer), input)) {
        char *token = strtok(textBuffer, " \t\n");

        while (token != NULL) {
            int isAlnum = 1;

            for (int i = 0; token[i] != '\0'; i++) {
                if (!isalnum(token[i])) {
                    isAlnum = 0;
                    break;
                }
            }

            if (isAlnum) {
                fprintf(output, "%s ", token); 
            }
            token = strtok(NULL, " \t\n");
        }
    }
}


// Pass a list of delimitters (All possible from the ASCII list)
// Ctype library to generate all the printable chars (isprint funciton)