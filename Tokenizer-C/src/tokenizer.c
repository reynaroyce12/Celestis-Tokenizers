#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <ctype.h>
#include <string.h>


void Tokenizer(char *content, FILE *output) {
    char delimitters[128];
    int index = 0;

    for (int i = 0; i < 128; i++) {
        if (isprint(i) && !isalnum(i)) {
            delimitters[index++] = (char)i;
        }
    }
    delimitters[index] = '\0'; 

    char *token = strtok(content, delimitters);  

    while (token != NULL) {
        fprintf(output, "%s ", token);  
        token = strtok(NULL, delimitters);
    }
}

