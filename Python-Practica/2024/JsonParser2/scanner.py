class Token:
    def __init__(self, type, val):
        setattr(self, "tipo", type)
        setattr(self, "valor", val)
    def __repr__(self):
        return "<Objeto Token: Tipo: {}, Valor: {}>".format(self.tipo, self.valor)


def scan(string):
    index = 0
    tokens = []

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
                
    def newToken(type, val):
        tokens.append(Token(type, val))
        
    while index < len(string):
        match(string[index]):
            case "{":
                index+=1
                newToken("{", None)
            case "}":
                index+=1
                newToken("}", None)
            case " ":
                index+=1
            case ":":
                index+=1
                newToken("}", None)
            case '"':
                value, long = scanString(string, index)
                index += long
                newToken("String", value)
            case '[':
                index+=1
                newToken("[", None)
            case ']':
                index+=1
                newToken("]", None)
            case ',':
                index+=1
                newToken(",", None)
            case _:
                if string[index] in "0123456789.-":
                    value, long = scanNumber(string, index)
                    index += long
                    newToken("Number", value)
                else:
                    raise Exception("Error de scanner en indice del string: {} \n".format(index))
    return tokens