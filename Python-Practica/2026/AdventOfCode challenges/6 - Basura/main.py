from functools import reduce
import re
def readFile() -> tuple[list[list[int]], list[str]]:
    file = open("./6 - Basura/puzzle-input.txt")

    numberLines = []
    line = file.readline()
    while(line[0] not in "+*"):
        numberLines.append(list(map(int,re.split(r'\s+', line.strip()))))
        line = file.readline()
    opLine = re.split(r'\s+', line.strip())
    return numberLines, opLine

def mult(values:list):
    return reduce(lambda x, y: x*y, values, 1)

def getOperations() -> tuple[list[list[int]], list[callable]]:
    numLines, opLine = readFile()
    numbers = list(list(t) for t in zip(*numLines))
    operations = list(map(lambda char : sum if char == "+" else mult if char == "*" else None, opLine))
    return numbers, operations

numbers, operations = getOperations()
total = 0
for operands, operation in zip(numbers, operations):
    result = operation(operands)
    total += result

print(total)