import os 
import time
from tokenizer import Tokenize
import pprint

def process_directories(input_folder, output_folder="output"):
    file_contents = {}

    for dirpath, dirname, files in os.walk(input_folder):
        relative_path = os.path.relpath(dirpath, input_folder)
        output_path = os.path.join(output_folder, relative_path)
        os.makedirs(output_path, exist_ok=True)

        for file in files:
            input_file = os.path.join(dirpath, file)
            with open(input_file, 'r', encoding='utf-8') as source_file:
                file_contents[input_file] = source_file.read()

    start_time = time.time()
    tokenized_output = {file: Tokenize(content) for file, content in file_contents.items()}
    end_time = time.time()

    elapsed_time = round(end_time - start_time, 2)

    for file, tokens in tokenized_output.items():
        relative_path = os.path.relpath(file, input_folder)
        output_file = os.path.join(output_folder, relative_path)

        with open(output_file, 'w', encoding='utf-8') as destination_file:
            destination_file.write(' '.join(tokens))

    return elapsed_time
