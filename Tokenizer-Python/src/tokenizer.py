import re


def Tokenize(text):
    return re.findall(r'[a-zA-Z0-9]+', text)

# Modify to not include underscore ✅