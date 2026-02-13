file = open("./9 - Cine/puzzle-input.txt")

def parse(file) -> list[(int, int)]:
    points = []
    for line in file.readlines():
        x, y = map(int, map(str.strip, line.split(",")))
        points.append((x, y))
    return points

def area(point1:tuple[int, int], point2:tuple[int, int]) -> int:
    return (abs(point1[0] - point2[0])+1) * (abs(point1[1] - point2[1])+1)

points = parse(file)
maxPoints = points[0], points[1]
maxArea = area(points[0], points[1])
#(Un doble for, la manera mas directa posible)
for i in points:
    for j in points[points.index(i)+1:]:
        a = area(i, j)
        if(a>maxArea):
            maxPoints = i, j
            maxArea = a

print(maxArea)