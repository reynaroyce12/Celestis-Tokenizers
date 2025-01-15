#include "../include/tokenizer.hpp"
#include <string.h>
#include <ctype.h>
#include <stdio.h>


void Tokenizer(FILE *inputText, FILE *outputText) {
    char textBuffer[1024];

    while(fgets(textBuffer, sizeof(textBuffer), inputText)) {
        char *token = strtok(textBuffer, " \t\n");

        while(token != NULL) {
            
            int isAlnum = 1;
            for (int i = 0; token[i] != '\0'; i++) {
                isAlnum = (('0' <= token[i] && token[i] <= '9') || 
                           ('a' <= token[i] && token[i] <= 'z') || 
                           ('A' <= token[i] && token[i] <= 'Z')) 
                           ? isAlnum 
                           : 0;
            }

            isAlnum ? fprintf(outputText, "%s ", token) : 0;
            
            token = strtok(NULL, " \t\n");
        }
    }
}

// Loose strtok function and manually go over them (implement like strtok from sctratch)

// FOr all programs
// Measure only the tokenization 
    // Read everythign in memory
    // Tokenize all of the file
    // Write

// Allocate the memory for the output buffers before tokenizing