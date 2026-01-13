#file = open("./4 - Impresoras/puzzle-input.txt")
file = open("./4 - Impresoras/puzzle-input.txt")
rollsMap = list(map(lambda row : list(row.removesuffix("\n")), list(file.readlines())))

# rollsMap es una matriz con los caracteres del archivo
bordersX = 0, len(rollsMap[0])-1
bordersY = 0, len(rollsMap)-1
def outOfBounds(x, y):
    return not(bordersX[0]<=x<=bordersX[1] and bordersY[0]<=y<=bordersY[1])

def isFilled(x, y):
    return not outOfBounds(x, y) and rollsMap[x][y] == "@"

def filledAdjacents(x, y):
    adjacents = 0
    for x2 in range(-1, 2):
        for y2 in range(-1, 2):
            if(isFilled(x2+x, y2+y) and (x2 != 0 or y2 != 0)):
                adjacents += 1
    return adjacents
def isAccesible(x, y):
    return filledAdjacents(x, y) < 4

removable = 0
for x in range(len(rollsMap)):
    #printLine = ""
    for y in range(len(rollsMap[0])):
        #printLine = printLine + str(filledAdjacents(x, y))
        if(isFilled(x, y) and isAccesible(x, y)):
            removable += 1

    #print(printLine)




print(removable)