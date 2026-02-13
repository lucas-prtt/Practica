# Metodo recursivo. Tarda demasiados

file = open("./7 - Laboratorios/puzzle-input.txt")
#file = open("./7 - Laboratorios/test.txt")
timelines = 0
linesList = file.readlines()

def createTimeline(line:str, level:int):
    global timelines
    timelines +=1
    #print(timelines)
    propagate(line, level+1)
    

def propagate(line:str, nextLineLevel:int):
    if(nextLineLevel >= len(linesList)):
        return
    nextLine = linesList[nextLineLevel]
    propagatedNextLine = str(nextLine)
    def setRay(line : int, location:int):
        return line[:location] + "|" + line[location+1:]
    def createTimelineWithRayIn(location:int, timeLineLevel:int):
        t = setRay(propagatedNextLine, location)
        createTimeline(t, timeLineLevel)
    for i, c in enumerate(list(line)):
        match c:
            case "S":
                if(nextLine[i] == "^"):
                    propagate(setRay(propagatedNextLine, i-1), nextLineLevel+1)
                    createTimelineWithRayIn(i+1, nextLineLevel)
                elif(nextLine[i] == "."):
                    propagate(setRay(propagatedNextLine, i), nextLineLevel+1)
            case "^":
                pass
            case ".":
                pass
            case "|":
                if(nextLine[i] == "^"):
                    propagate(setRay(propagatedNextLine, i-1), nextLineLevel+1)
                    createTimelineWithRayIn(i+1, nextLineLevel)
                elif(nextLine[i] == "."):
                    propagate(setRay(propagatedNextLine, i), nextLineLevel+1)
            case _:
                pass
    return propagatedNextLine

createTimeline(linesList[0], 0)


print(timelines)

