#include <iostream>
#include <chrono>
#include "tokenizer.hpp"

int main() {
    std::string inputDirectory, outputDirectory;

    inputDirectory = "/home/royce_server2/Tokenizers/dataset1";
    outputDirectory = "/home/royce_server2/Tokenizers/Tokenizer-cpp/output";


    auto startTime = std::chrono::high_resolution_clock::now();

    try {
        std::filesystem::create_directories(outputDirectory);
        processDirectory(inputDirectory, outputDirectory);
        std::cout << "Tokenization complete. Output saved to " << outputDirectory << std::endl;
        
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

    std::cout << "Execution Time: " << duration.count() << " seconds" << std::endl;
    
    return 0;
}