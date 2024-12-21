class Token:
    def __init__(self, type, val):
        setattr(self, "type", type)
        setattr(self, "val", val)
    def __repr__(self):
        return "<Objeto Token: Tipo: {}, Valor: {}>".format(self.type, self.val)


def scan(string):
    index = 0
    token = None
    def scanNumber(string, index):
        start = index
        while index < len(string) and string[index] in "0123456789.-":
            index += 1
        value = float(string[start:index])
        return value, index-start

    def scanString(string, index):
        start = index
        index += 1 # Skip de <"> 
        # No toma caracter de escape
        while (index < len(string) and string[index] != '"'):
            index +=1
        index += 1 # Skip de <"> 
        return string[start+1:index-1], index-start
        

    while string[index] == " ":
        index += 1

    match(string[index]):
        case "{":
            index+=1
            token = Token("{", None)
        case "}":
            index+=1
            token = Token("}", None)
        case ":":
            index+=1
            token = Token(":", None)
        case '"':
            value, long = scanString(string, index)
            index += long
            token = Token("String", value)
        case '[':
            index+=1
            token = Token("[", None)
        case ']':
            index+=1
            token = Token("]", None)
        case ',':
            index+=1
            token = Token(",", None)
        case _:
            if string[index] in "0123456789.-":
                value, long = scanNumber(string, index)
                index += long
                token = Token("Number", value)
            else:
                raise Exception("Error de scanner en indice del string: {} \n".format(index))
    return token, string[index:]