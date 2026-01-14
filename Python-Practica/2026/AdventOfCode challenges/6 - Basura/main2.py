from functools import reduce
import re
def addDigit(base, num) -> int:
    return base * 10 + num

def readFile() -> tuple[list[str], str]:
    file = open("./6 - Basura/puzzle-input.txt")

    numberLines = []
    line = file.readline()
    while(line[0] not in "+*"):
        numberLines.append(line)
        line = file.readline()
    opLine = line

    return numberLines, opLine

def mult(values:list):
    return reduce(lambda x, y: x*y, values, 1)

def symbolToFunction(s:str) -> callable:
    return (lambda char : sum if char == "+" else mult if char == "*" else None)(s)

def getOperations() -> tuple[list[list[int]], list[callable]]:
    numLines, opLine = readFile()
    allNumbers = []
    operations = []
    currNumbers = []
    def readNumber(lines, column) -> int:
        empty = True
        newNum = 0
        for line in lines:
            if(line[i] != " "):
                newNum = addDigit(newNum, int(line[i]))
                empty = False    
        if(not empty):
            return newNum
        else:
            return None
    

    for i, c in enumerate(opLine):
        if(c in "+*" and currNumbers != []):
            allNumbers.append(currNumbers)
            currNumbers = []
        newNum = readNumber(numLines, i)
        if(newNum != None):
            currNumbers.append(readNumber(numLines, i))
 
    allNumbers.append(currNumbers)

    operations = list(map(symbolToFunction, opLine.split()))    
    return allNumbers, operations

numbers, operations = getOperations()
total = 0
for operands, operation in zip(numbers, operations):
    result = operation(operands)
    total += result

print(total)