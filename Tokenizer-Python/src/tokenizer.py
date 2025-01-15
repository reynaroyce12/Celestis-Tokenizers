import re



# Modify to not include underscore

def Tokenize(text):
    return re.findall(r'\w+', text)