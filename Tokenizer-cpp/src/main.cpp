#include <iostream>
#include <chrono>
#include "tokenizer.hpp"

// Run with config --build build --config release


int main() {
    std::string inputDirectory, outputDirectory;

    inputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/datasets/dataset1";
    outputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/Tokenizer-cpp/output";


    // auto startTime = std::chrono::high_resolution_clock::now();

    try {
        std::filesystem::create_directories(outputDirectory);
        float elapsedTime = processDirectoryAndTokenize(inputDirectory, outputDirectory);
        std::cout << "Tokenization complete. Output saved to " << outputDirectory << std::endl;
        std::cout << "Execution Time: " << elapsedTime << " seconds" << std::endl;
        
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    // auto endTime = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

    
    return 0;
}