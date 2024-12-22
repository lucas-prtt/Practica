from scanner import scan, nextToken



class JsonObject:
    jsonString = None
    def __repr__(self):
        return "Parsed object: {}".format(str(self.__dict__))

    def __init__(self, jsonString):
        self.jsonString = jsonString
        self.parse()
        pass
    def match(self, type):
         
        tok, self.jsonString = scan(self.jsonString)
        if tok.type != type:
            raise Exception("Match error: Expected:<{}>, Actual:<{}>".format(type, tok.type()))
    def skip(self):
         
        self.match(nextToken(self.jsonString).type)
    def attList(self):
        self.att()
         
        while(nextToken(self.jsonString).type == ","):
            self.match(",")
            self.att()
    def att(self):
        def next() : return nextToken(self.jsonString)
        id = next().val
        self.match("String")
        self.match(":")
        val = self.element()
        setattr(self, id, val)
    def element(self):
        def next() : return nextToken(self.jsonString)
        def skip() : self.skip()
        val = None
        if next().type in ["String", "Number"]:
            val = next().val
            skip()
        elif next().type == "{":
            val = JsonObject(self.jsonString)
            opened = 1
            closed = 0
            while(opened > closed):
                if next().type == "{":
                    opened += 1
                elif next().type == "}":
                    closed += 1
                skip()
            pass
        elif next().type == "[":
            val = self.elementList()
            pass
        else:
            raise Exception("Unvalid argument <{}>".format(next().type))
        return val
    def elementList(self):
         

        lista = []
        def newElement() : lista.append(self.element())

        lista.append(self.element())
        while(nextToken(self.jsonString) == ","):
            self.match(",")
            lista.append(self.element())
        return lista


    def parse(self):
        def next() : return nextToken(self.jsonString)
        def match(char) : self.match(char)

        match("{")
        
        if next().type != "}":
            self.attList()

        match("}")





a = JsonObject('{"Hola" : 2}')
print(a)
