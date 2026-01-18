from typing import overload
from itertools import chain
from collections import deque
from PIL import Image

# Cuando pide prompt de lado interno, para este input sirve 100, 50.

def getLines(geometry:list[tuple[int, int]]):
    for j in range(len(geometry)-2):
        yield (geometry[j], geometry[j+1])
    yield (geometry[len(geometry)-1], geometry[0])


def parse() -> list[(int, int)]:
    file = open("./9 - Cine/puzzle-input.txt")
    points = []
    for line in file.readlines():
        x, y = map(int, map(str.strip, line.split(",")))
        points.append((x, y))
    return points

points = parse()

def area(point1:tuple[int, int], point2:tuple[int, int]) -> int:
    return (abs(point1[0] - point2[0])+1) * (abs(point1[1] - point2[1])+1)

def fillFromPoint(matrix, start):
    n, m = len(matrix), len(matrix[0])
    stack = [start]
    while stack:
        x, y = stack.pop()
        if 0 <= x < n and 0 <= y < m and matrix[x][y] == False:
            matrix[x][y] = True
            stack.extend([(x+1,y), (x-1,y),(x,y+1), (x,y-1)])

def makeXYIndex(points:list[tuple[int, int]]) -> tuple[list[int], list[int]]:
    xCordinates = []
    yCordinates = []
    for p in points:
        if(not xCordinates.__contains__(p[0])):
            xCordinates.append(p[0])
        if(not yCordinates.__contains__(p[1])):
            yCordinates.append(p[1])
    xCordinates.sort()
    yCordinates.sort()
    view = [[False for _ in range(len(xCordinates))] for _ in range(len(yCordinates))]
    for p in points:
        view[yCordinates.index(p[1])][xCordinates.index(p[0])] = True
    for (p1x, p1y), (p2x, p2y) in getLines(points):
        p1x, p2x = sorted((p1x, p2x))
        p1y, p2y = sorted((p1y, p2y))
        for i in range(xCordinates.index(p1x),xCordinates.index(p2x)+1):
            for j in range(yCordinates.index(p1y), yCordinates.index(p2y)+1):
                view[j][i] = True
    fillFromPoint(view, (int(input("Ingrese un punto interno para comenzar el algoritmo (x):")), int(input(" (y)"))))
    return xCordinates, yCordinates, view

xIndex, yIndex, view = makeXYIndex(points)
def printView():
    w = 1
    for row in view:
        print("".join(cell.rjust(w) for cell in map(lambda x : "1" if x else "0", row)))
def writeViewToFile(filename: str):
    with open(filename, "w", encoding="utf-8") as f:
        for row in view:
            f.write("".join("1" if x else "0" for x in row) + "\n")
def view_to_image(filename: str):
    height = len(view)
    width = len(view[0])
    img = Image.new("1", (width, height))
    pixels = img.load()
    for y in range(height):
        for x in range(width):
            pixels[x, y] = 1 if view[y][x] else 0

    img.save(filename)

#printView()
#view_to_image("matriz.png")

def isValidSquare(p1, p2):
    i1x, i1y = xIndex.index(p1[0]), yIndex.index(p1[1])
    i2x, i2y = xIndex.index(p2[0]), yIndex.index(p2[1])
    i1x, i2x = sorted((i1x, i2x))
    i1y, i2y = sorted((i1y, i2y))
    iSquare = list(map(lambda l : l[i1x: i2x+1], view[i1y:i2y+1]))
    return all(list(chain.from_iterable(iSquare)))

maxPair = None
maxArea = 0
for p1 in points:
    for p2 in points[points.index(p1)+1:]:
        a = area(p1, p2)
        if(a > maxArea and isValidSquare(p1, p2)): 
            isValidSquare(p1, p2)
            maxArea = a
            maxPair = p1, p2
print(maxPair, maxArea)



