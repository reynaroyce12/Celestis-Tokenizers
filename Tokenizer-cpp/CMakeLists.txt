cmake_minimum_required(VERSION 3.22)

project(Tokenizer
        VERSION 1.0
        DESCRIPTION "C++ Tokenizer"
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Tokenizer
               src/main.cpp
               src/tokenizer.cpp
            )

target_include_directories(Tokenizer PUBLIC include)
