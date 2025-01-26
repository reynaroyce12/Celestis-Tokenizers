import os
import sys

from file_processor import process_directories

def main():

    input_folder = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/datasets/dataset1"
    output_folder = "/Users/reynaroyce/Documents/vava/Development/Celestis-Tokenizers/Tokenizer-Python/output"

    if not os.path.exists(input_folder):
        print(f"Input directory {input_folder} does not exist!")
        sys.exit(1)

    elapsed_time = process_directories(input_folder, output_folder)

    print(f"Execution time: {elapsed_time} seconds")


if __name__ == "__main__":
    main()