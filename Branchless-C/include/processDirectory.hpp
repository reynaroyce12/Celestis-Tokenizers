#ifndef PROCESSDIRECTORY_HPP
#define PROCESSDIRECTORY_HPP

#include <stdio.h>

void ProcessDirectory(const char *inputDirectory, const char *outputDirectory, double *totalTokenizationTime);
void CreateOutputDirectory(const char *path);

#endif