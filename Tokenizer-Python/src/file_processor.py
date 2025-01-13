import os 
from tokenizer import Tokenize

def process_directories(input_folder, output_folder="output"):
    for dirpath, dirname, files in os.walk(input_folder):
        relative_path = os.path.relpath(dirpath, input_folder)
        output_path = os.path.join(output_folder, relative_path)
        os.makedirs(output_path, exist_ok=True)

        for file in files:
            input_file = os.path.join(dirpath, file)
            output_file = os.path.join(output_path, file)

            with open(input_file, 'r', encoding='utf-8') as source_file:
                content = source_file.read()

            tokens = Tokenize(content)

            with open(output_file, 'w', encoding='utf-8') as destination_file:
                destination_file.write(' '.join(tokens))


