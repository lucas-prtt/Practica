file = open("./9 - Cine/puzzle-input.txt")

def parse(file) -> list[(int, int)]:
    points = []
    for line in file.readlines():
        x, y = map(int, map(str.strip, line.split(",")))
        points.append((x, y))
    return points

def area(point1:tuple[int, int], point2:tuple[int, int]) -> int:
    return (abs(point1[0] - point2[0])+1) * (abs(point1[1] - point2[1])+1)

def linesCollide(line1:tuple[tuple[int, int], tuple[int, int]], line2:tuple[tuple[int, int], tuple[int, int]]) -> bool:
    # Solo pueden ser verticales y horizontales
    (x1, y1), (x2, y2) = line1
    (x3, y3), (x4, y4) = line2
    # false = Vertical, true = Horizontal
    h1 = y1 == y2
    h2 = y3 == y4
    if h1 == h2:
        # Si se superponen cuento como que no se cruzan
        return False
    if h1:
        x1, x2 = sorted((x1, x2))
        y3, y4 = sorted((y3, y4))
        return x1 < x3 < x2 and y3 < y1 < y4
    else:
        x3, x4 = sorted((x3, x4))
        y1, y2 = sorted((y1, y2))
        return x3 < x1 < x4 and y1 < y3 < y2


def horizontalRaycastCollides(line:tuple[tuple[int, int], tuple[int, int]], point:tuple[int, int]) -> bool:
    # Solo pueden ser verticales y horizontales
    (x1, y1), (x2, y2) = line
    # false = Vertical, true = Horizontal
    h1 = y1 == y2
    if h1:  # Si se superponen cuento como que no se cruzan
        return False # Raycast horizontal
    
    x1, x2 = sorted((x1, x2))
    y1, y2 = sorted((y1, y2))
    return point[0] <= x1 and y1 <= point[1] <= y2 # Raycast a la derecha

def getLines(geometry:list[tuple[int, int]]):
    for j in range(len(geometry)-2):
        yield (geometry[j], geometry[j+1])
    yield (geometry[len(geometry)-1], geometry[0])

def pointInside(geometry:list[tuple[int, int]], point:tuple[int, int]) -> bool:
    # Segun internet, se puede usar RayCasting o algoritmo radial
    i = 0
    for line in getLines(geometry):
        i += 1 if horizontalRaycastCollides(line, point) else 0
    return bool(i%2)

def rectInside(geometry:list[tuple[int, int]], point1:tuple[int, int], point2:tuple[int, int]) -> bool:
    # Si hay un punto entre los 4, False
    # Si hay colision de los bordes, False
    # Si un punto aleatorio dentro del cuadrado no esta en la geometria, False
    # Sino True (No es ningun teorema. Me lo invente yo. Capaz que anda)
    puntoIntermedio = ((point1[0] + point2[0])/2, (point1[1] + point2[1])/2)
    if(not pointInside(geometry, puntoIntermedio)):
        return False
    corners = [point1, (point1[0], point2[1]), point2, (point1[1], point2[0])]
    for c in corners:
        if pointInside(geometry, c):
            return False
    for border in [(corners[0], corners[1]), (corners[1], corners[2]), (corners[2], corners[3]), (corners[3], corners[0])]:
        for geometryLine in getLines(geometry):
            if(linesCollide(geometryLine, border)):
                return False
    return True

points = parse(file)
# Los puntos describen una gemoetria cerrada. El cuadrado elegido debe estar dentro de esta geometria

maxPoints = points[0], points[1]
maxArea = area(points[0], points[1])
iterations = 0
for i in points:
    iterations+=1
    for j in points[points.index(i)+1:]:
        a = area(i, j)
        if(a>maxArea and rectInside(points, i, j)):
            maxPoints = i, j
            maxArea = a

    print(iterations)
# Directo pero demasiado ineficiente. La verificacion de que este en el rectangulo es un cuello de botella y el resultado que produce es demasiado bajo, posiblemente porque estoy limitando mas de la cuenta
# Es necesario encontrar una manera de reducir las ejecuciones de rectInside() cuando no es necesario, ver si se puede agilizar y mas importante, verificar bien casos bordes donde se esten poniendo algunos validos como invalidos
print(maxArea, maxPoints)

