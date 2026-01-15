file = open("./7 - Laboratorios/puzzle-input.txt")
#file = open("./7 - Laboratorios/test.txt")
totalSplits = 0

def propagate(line:str, nextLine:str):
    global totalSplits
    propagatedNextLine = str(nextLine)
    def setRay(*locations:int):
        nonlocal propagatedNextLine
        for location in locations:
            propagatedNextLine = propagatedNextLine[:location] + "|" + propagatedNextLine[location+1:]
    
    for i, c in enumerate(list(line)):
        match c:
            case "S":
                if(nextLine[i] == "^"):
                    setRay(i+1, i-1)
                    totalSplits+=1
                elif(nextLine[i] == "."):
                    setRay(i)
            case "^":
                pass
            case ".":
                pass
            case "|":
                if(nextLine[i] == "^"):
                    setRay(i+1, i-1)
                    totalSplits+=1
                elif(nextLine[i] == "."):
                    setRay(i)
            case _:
                pass
    return propagatedNextLine

linesIt = file.readlines()
changingLine = linesIt.pop(0)
#print(changingLine.strip())
for nextLine in linesIt:
    changingLine = propagate(changingLine, nextLine)
    #print(changingLine.strip())

print(totalSplits)

