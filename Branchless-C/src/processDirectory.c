#include "../include/processDirectory.hpp"
#include "../include/tokenizer.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void CreateOutputDirectory(const char *path)
{
    char tempBuffer[1024];

    snprintf(tempBuffer, sizeof(tempBuffer), "%s", path);
    for (char *p = tempBuffer + 1; *p; p++)
    {
        if (*p == '/')
        {
            *p = '\0';
            mkdir(tempBuffer, 0755);
            *p = '/';
        }
    }
    mkdir(tempBuffer, 0755);
}

void ProcessDirectory(const char *inputDirectory, const char *outputDirectory, double *totalTokenizationTime)
{
    DIR *directory = opendir(inputDirectory);

    if (directory == NULL)
    {
        printf("Error opening input directory\n");
        return;
    }

    struct dirent *entry;
    char *combinedContent = (char *)malloc(1); //buffer for combined content
    size_t combinedContentSize = 0;

    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char input_path[1024], output_path[1024];
        snprintf(input_path, sizeof(input_path), "%s/%s", inputDirectory, entry->d_name);
        snprintf(output_path, sizeof(output_path), "%s/%s", outputDirectory, entry->d_name);

        struct stat st;
        if (stat(input_path, &st) == 0 && S_ISDIR(st.st_mode))
        {

            CreateOutputDirectory(output_path);
            ProcessDirectory(input_path, output_path, totalTokenizationTime);
        }
        else if (entry->d_type == DT_REG)
        {

            FILE *inputFile = fopen(input_path, "r");
            if (inputFile == NULL)
            {
                printf("Error opening input file: %s\n", input_path);
                continue;
            }

            fseek(inputFile, 0, SEEK_END);
            long fileSize = ftell(inputFile);
            rewind(inputFile);


            char *content = (char *)malloc(fileSize + 1);
            if (content == NULL)
            {
                printf("Memory allocation failed for file: %s\n", input_path);
                fclose(inputFile);
                continue;
            }

            fread(content, 1, fileSize, inputFile); 
            content[fileSize] = '\0';
            fclose(inputFile);


            combinedContent = (char *)realloc(combinedContent, combinedContentSize + fileSize + 1);
            memcpy(combinedContent + combinedContentSize, content, fileSize + 1);
            combinedContentSize += fileSize;

            free(content); 


            CreateOutputDirectory(outputDirectory);


            FILE *outputFile = fopen(output_path, "w");
            if (outputFile == NULL)
            {
                printf("Error opening output file: %s\n", output_path);
                continue;
            }


            clock_t startTokenization = clock();


            Tokenizer(combinedContent, outputFile);

            clock_t endTokenization = clock();
            double timeSpent = ((double)(endTokenization - startTokenization)) / CLOCKS_PER_SEC;

            *totalTokenizationTime += timeSpent;

            fclose(outputFile);
        }
    }

    closedir(directory); 
}
