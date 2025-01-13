#include "tokenizer.hpp"
#include <fstream>
#include <regex>
#include <iostream>

std::string tokenize(const std::string& text) {
    std::regex regex_pattern("\\w+");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), regex_pattern);
    auto words_end = std::sregex_iterator();
    std::string result;

    for (auto itr = words_begin; itr != words_end; ++itr) {
        result = result + itr->str() + " ";
    }

    return result;
}

void processDirectory(const fs::path& inputDirectory, const fs::path& outputDirectory) {
    for (const auto& entry : fs::recursive_directory_iterator(inputDirectory)) {
        if (fs::is_directory(entry)) {
            fs::create_directories(outputDirectory / fs::relative(entry, inputDirectory));
        } else if (fs::is_regular_file(entry)) {
            std::ifstream inputFile;
            inputFile.open(entry.path());
            if (!inputFile.is_open()) {
                std::cout<< "Could not open file: " << entry.path() << std::endl;
                continue;
            }

            std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();

            std::string tokenizedText = tokenize(content);

            fs::path outputFilePath = outputDirectory / fs::relative(entry.path(), inputDirectory);
            std::ofstream outputFile;
            outputFile.open(outputFilePath);
            if(!outputFile.is_open()) {
                std::cout << "Could not write to file: " << outputFilePath << std::endl;
                continue;
            }

            outputFile << tokenizedText;
            outputFile.close();

        }
    }
}

