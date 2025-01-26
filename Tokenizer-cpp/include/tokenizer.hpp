#ifndef TOKENIZER_H
#define TOKENIZER_H


#include <string>
#include <filesystem>

namespace fs = std::filesystem;

std::string tokenize(const std::string& text);

float processDirectoryAndTokenize(const fs::path& inputDirectory, const fs::path& outputDirectory);

#endif