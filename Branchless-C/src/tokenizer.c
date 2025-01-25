#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void Tokenizer(FILE *input, FILE *output) {
    size_t bufferSize = 1024;
    char *textBuffer = (char *)malloc(bufferSize);
    char *currentToken = (char *)malloc(bufferSize);
    !textBuffer || !currentToken ? (fprintf(stderr, "Memory allocation failed\n"), exit(1)) : (void)0;

    size_t currentIndex = 0;
    while(fgets(textBuffer, sizeof(textBuffer), input)) {
        size_t i = 0;

        // iterating through each character in the text buffer until null
        while(textBuffer[i] != '\0') {
            int isAlnum = isalnum((unsigned char)textBuffer[i]);
            // if currentIndex is reaching the end of the current allocated memory, it is reallocated
            currentIndex = isAlnum ? (currentIndex >= bufferSize - 1 ? (bufferSize *= 2, currentToken = (char *)realloc(currentToken, bufferSize), currentIndex) : currentIndex) : currentIndex;
            
             // if the current character is alphanumeric, it is stored & currentIndex is incremented
            currentToken[currentIndex] = isAlnum ? textBuffer[i] : currentToken[currentIndex];
            currentIndex += isAlnum ? 1 : 0;

            // if the current character is not alphanumeric, adds a terminator to end that current token, writes to file and resets current index
            currentIndex = !isAlnum && currentIndex > 0 ? (currentToken[currentIndex] = '\0', fprintf(output, "%s ", currentToken), currentIndex = 0, currentIndex) : currentIndex;
            i++;
        }

        // Check to see if there is any remaining token
        currentIndex = currentIndex > 0 ? (currentToken[currentIndex] = '\0', fprintf(output, "%s ", currentToken), 0) : currentIndex;
        currentIndex = 0;
    }

    free(textBuffer);
    free(currentToken);
}


// Tokenizer with condiitonals

// void Tokenizer(FILE *inputText, FILE *outputText) {
//     size_t bufferSize = 1024;
//     char *textBuffer = (char *)malloc(bufferSize);
//     char *currentToken = (char *)malloc(bufferSize);
//     if (!textBuffer || !currentToken) {
//         fprintf(stderr, "Memory allocation failed\n");
//         return;
//     }

//     size_t currentIndex = 0;
//     while (fgets(textBuffer, bufferSize, inputText)) {
//         size_t i = 0;
//         while (textBuffer[i] != '\0') {
//             int isAlnum = isalnum((unsigned char)textBuffer[i]);  
//             if (isAlnum) {

//                 if (currentIndex >= bufferSize - 1) {
//                     bufferSize *= 2; 
//                     currentToken = (char *)realloc(currentToken, bufferSize);
//                     if (!currentToken) {
//                         fprintf(stderr, "Memory reallocation failed\n");
//                         free(textBuffer);
//                         return;
//                     }
//                 }

//                 currentToken[currentIndex] = textBuffer[i];
//                 currentIndex++;
//             }

//             if (!isAlnum && currentIndex > 0) {
//                 currentToken[currentIndex] = '\0';  
//                 fprintf(outputText, "%s ", currentToken);  
//                 currentIndex = 0; 
//             }

//             i++; 
//         }

//         if (currentIndex > 0) {
//             currentToken[currentIndex] = '\0'; 
//             fprintf(outputText, "%s ", currentToken);  
//         }

//         currentIndex = 0;  
//     }

//     free(textBuffer);
//     free(currentToken);
// }




// Loose strtok function and manually go over them (implement like strtok from sctratch) ✅

// FOr all programs
// Measure only the tokenization 
    // Read everythign in memory
    // Tokenize all of the file
    // Write

// Allocate the memory for the output buffers before tokenizing


// cmake -S . -B build -DCMAKE_BUILD_TYPE=Release 
// cmake --build build --config Release 