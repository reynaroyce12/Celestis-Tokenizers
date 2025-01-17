#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Tokenizer(FILE *inputText, FILE *outputText) {
    size_t bufferSize = 1024;
    char *textBuffer = (char *)malloc(bufferSize);
    char *currentToken = (char *)malloc(bufferSize);
    if (!textBuffer || !currentToken) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    size_t currentIndex = 0;
    while (fgets(textBuffer, bufferSize, inputText)) {
        size_t i = 0;
        while (textBuffer[i] != '\0') {
            int isAlnum = isalnum((unsigned char)textBuffer[i]);  
            if (isAlnum) {

                if (currentIndex >= bufferSize - 1) {
                    bufferSize *= 2; 
                    currentToken = (char *)realloc(currentToken, bufferSize);
                    if (!currentToken) {
                        fprintf(stderr, "Memory reallocation failed\n");
                        free(textBuffer);
                        return;
                    }
                }

                currentToken[currentIndex] = textBuffer[i];
                currentIndex++;
            }

            if (!isAlnum && currentIndex > 0) {
                currentToken[currentIndex] = '\0';  
                fprintf(outputText, "%s ", currentToken);  
                currentIndex = 0; 
            }

            i++; 
        }

        if (currentIndex > 0) {
            currentToken[currentIndex] = '\0'; 
            fprintf(outputText, "%s ", currentToken);  
        }

        currentIndex = 0;  
    }

    free(textBuffer);
    free(currentToken);
}





// Loose strtok function and manually go over them (implement like strtok from sctratch)

// FOr all programs
// Measure only the tokenization 
    // Read everythign in memory
    // Tokenize all of the file
    // Write

// Allocate the memory for the output buffers before tokenizing