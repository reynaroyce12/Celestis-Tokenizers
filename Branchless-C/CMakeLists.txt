cmake_minimum_required(VERSION 3.22)

project(Branchless-Tokenizer
        VERSION 1.0
        DESCRIPTION "C Branchless Tokenizer"
        LANGUAGES C)


set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)


add_executable(Branchless-Tokenizer
               src/main.c
               src/tokenizer.c
               src/processDirectory.c
            )

target_include_directories(Branchless-Tokenizer PUBLIC include)
