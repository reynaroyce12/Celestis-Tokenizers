#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// One single allocation and read the data using c++ method and read all of the bbytes (Instead of multiple allocations and reallocations using malloc)
// Instead of passing the file, pass the buffer (use c++ style iterator)

void Tokenizer(char *content, FILE *output) {
    size_t bufferSize = strlen(content);  // Get the size of the content
    char *currentToken = (char *)malloc(1024);  // Allocate initial token buffer
    size_t currentIndex = 0;
    char *current = content;

    // Check if memory allocation failed
    !currentToken ? (fprintf(stderr, "Memory allocation failed\n"), exit(1)) : (void)0;

    // Iterate through the content using pointer arithmetic (like C++ iterator)
    while (current - content < bufferSize) {
        int isAlnum = isalnum((unsigned char)*current);

        // Handle the alphanumeric and non-alphanumeric cases using ternary operators
        currentIndex = isAlnum
            ? (currentIndex >= 1023
                ? (currentToken = (char *)realloc(currentToken, (currentIndex * 2)), currentIndex)
                : currentIndex)
            : currentIndex;

        currentToken[currentIndex] = isAlnum
            ? *current
            : currentToken[currentIndex];

        currentIndex = isAlnum ? currentIndex + 1 : currentIndex;

        // Handle token output when a non-alphanumeric character is found using ternary
        currentIndex = (!isAlnum && currentIndex > 0)
            ? (currentToken[currentIndex] = '\0', fprintf(output, "%s ", currentToken), currentIndex = 0)
            : currentIndex;

        current++;  // Move to the next character in the buffer
    }

    // Check if there is any remaining token after the loop using ternary
    currentIndex = (currentIndex > 0)
        ? (currentToken[currentIndex] = '\0', fprintf(output, "%s ", currentToken), 0)
        : currentIndex;

    // Free the allocated memory for the token buffer
    free(currentToken);
}



// cmake -S . -B build -DCMAKE_BUILD_TYPE=Release 
// cmake --build build --config Release 