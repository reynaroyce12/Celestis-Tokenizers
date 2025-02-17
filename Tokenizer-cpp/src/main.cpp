#include <iostream>
#include <chrono>
#include "tokenizer.hpp"



int main() {
    std::string inputDirectory, outputDirectory;

    inputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/datasets/test_dir";
    outputDirectory = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/Tokenizer-cpp/output";


    try {
        std::filesystem::create_directories(outputDirectory);
        float elapsedTime = processDirectoryAndTokenize(inputDirectory, outputDirectory);
        std::cout << "Tokenization complete. Output saved to " << outputDirectory << std::endl;
        std::cout << "Execution Time: " << elapsedTime << " seconds" << std::endl;
        
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
    
    return 0;
}