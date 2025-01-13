import re

def Tokenize(text):
    return re.findall(r'\w+', text)