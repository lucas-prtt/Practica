def parse() -> list[(int, int)]:
    file = open("./9 - Cine/test.txt")
    points = []
    for line in file.readlines():
        x, y = map(int, map(str.strip, line.split(",")))
        points.append((x, y))
    return points

points = parse()

def area(point1:tuple[int, int], point2:tuple[int, int]) -> int:
    return (abs(point1[0] - point2[0])+1) * (abs(point1[1] - point2[1])+1)

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
    view = [["." for _ in range(len(xCordinates))] for _ in range(len(yCordinates))]

    for p in points:
        view[yCordinates.index(p[1])][xCordinates.index(p[0])] = str("x")
    return xCordinates, yCordinates, view

xIndex, yIndex, view = makeXYIndex(points)
def printView():
    w = 3
    print(" " * w + "".join(str(x).rjust(w) for x in xIndex))
    for y, row in zip(yIndex, view):
        print(str(y).rjust(w) + "".join(cell.rjust(w) for cell in row))

printView()