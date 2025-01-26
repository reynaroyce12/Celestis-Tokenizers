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

float processDirectoryAndTokenize(const fs::path& inputDirectory, const fs::path& outputDirectory) { 
    std::vector<std::string> fileContents;
    std::vector<fs::path> outputPaths;

    for (const auto& entry : fs::recursive_directory_iterator(inputDirectory)) {
        if (fs::is_regular_file(entry)) {
            std::ifstream inputFile(entry.path());
            if (!inputFile.is_open()) {
                std::cout << "Could not open file: " << entry.path() << std::endl;
                continue;
            }

            std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            fileContents.push_back(content);
            outputPaths.push_back(outputDirectory / fs::relative(entry.path(), inputDirectory));
        }
    }

    std::vector<std::string> tokenizedTexts;
    auto tokenizationStart = std::chrono::high_resolution_clock::now();

    for (const auto& content : fileContents) {
        tokenizedTexts.push_back(tokenize(content));
    }

    auto tokenizationEnd = std::chrono::high_resolution_clock::now();
    auto tokenizationDuration = std::chrono::duration_cast<std::chrono::seconds>(tokenizationEnd - tokenizationStart);
    auto elapsedTime = tokenizationDuration.count();

    for (size_t i = 0; i < tokenizedTexts.size(); ++i) {
        const auto& tokenizedText = tokenizedTexts[i];
        const auto& outputFilePath = outputPaths[i];

        fs::create_directories(outputFilePath.parent_path());

        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::cout << "Could not write to file: " << outputFilePath << std::endl;
            continue;
        }

        outputFile << tokenizedText;
        outputFile.close();

    }
    return elapsedTime;
}

