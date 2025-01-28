#include "../include/processDirectory.hpp"
#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void ProcessDirectory(const char *inputDirectory, const char *outputDirectory) {
    DIR *directory = opendir(inputDirectory);

    if (!directory) {
        perror("Error opening input directory");
        return;
    }

    struct dirent *entry;
    while((entry = readdir(directory)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char inputPath[1024], outputPath[1024];
        snprintf(inputPath, sizeof(inputPath), "%s/%s", inputDirectory, entry->d_name);
        snprintf(outputPath, sizeof(outputPath), "%s/%s", outputDirectory, entry->d_name);

        struct stat st;

        if (stat(inputPath, &st) == 0 && S_ISDIR(st.st_mode)) {
            mkdir(outputPath, 0755);
            ProcessDirectory(inputPath, outputPath);
        } else {
            FILE *inputFile = fopen(inputPath, "r");
            if (inputFile) {
                FILE *outputFile = fopen(outputPath, "w");
                if (outputFile) {
                    Tokenizer(inputFile, outputFile);
                    fclose(outputFile);
                }
                fclose(inputFile);
            } else {
                printf("Error opening input file");
            }
        }

    }
    closedir(directory);
}

// For all three cpp solutions, use the cpp method to iterate over the files and extract the contents
// Char pointer (c_str)