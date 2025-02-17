#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#include "../include/processDirectory.hpp"

int main() {
    const char *inputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/datasets/test_dir";
    const char *outputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/Branchless-C/output";

    mkdir(outputDirectory, 0755);

    double totalTokenizationTime = 0.0; 

    ProcessDirectory(inputDirectory, outputDirectory, &totalTokenizationTime);

    printf("Total tokenization time: %f seconds\n", totalTokenizationTime);

    return 0;
}
