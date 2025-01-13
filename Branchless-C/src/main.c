#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#include "../include/processDirectory.hpp"

int main() {
    const char *inputDirectory = "/Users/reynaroyce/Desktop/Celestis-Tokenizers/dataset1";
    const char *outputDirectory = "/Users/reynaroyce/Desktop/Celestis-Tokenizers/Branchless-C/output";

    clock_t startTime = clock();

    mkdir(outputDirectory, 0755);
    ProcessDirectory(inputDirectory, outputDirectory);

    clock_t endTime = clock();
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Execution Time: %.2f seconds\n", timeTaken);
}
