from math import sqrt, pow

file = open("./8 - Playground/puzzle-input.txt")
class JunctionBox:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def __repr__(self):
        return "(JunctionBox: {}, {}, {})".format(self.x, self.y, self.z)
    def distance(self, otherBox):
        return sqrt(pow(otherBox.x - self.x, 2) + pow(otherBox.y - self.y, 2) + pow(otherBox.z - self.z, 2))




def parse (file) -> list[JunctionBox]:
    boxes = []
    for line in file.readlines():
        x, y, z = map(int, line.split(","))
        boxes.append(JunctionBox(x, y, z))
    return boxes

boxes = parse(file)

def findClosestBox(availableBoxes: list[JunctionBox], box : JunctionBox) -> JunctionBox:
    minBox = availableBoxes[0]
    minDistance = minBox.distance(box)
    for evalBox in availableBoxes[1:]:
        distance = box.distance(evalBox)
        if(distance < minDistance):
            minDistance = distance
            minBox = evalBox
    return minBox

def pairDistance(pair : tuple[JunctionBox, JunctionBox]):
    return pair[0].distance(pair[1])

def findClosestPair(availableBoxes: list[JunctionBox]):
    minPair = availableBoxes[0], availableBoxes[1]
    minDistance = pairDistance(minPair)
    for box in availableBoxes:
        closestBox = findClosestBox(availableBoxes, box)
        distance = closestBox.distance(box)
        if(distance < minDistance):
            minDistance = distance
            minPair = box, closestBox
    return minPair

for i in range(10):
    print(findClosestPair(boxes))
# Muy lento. Pensar manera de almacenar resultados intermedios. Calcular la distancia miles de veces tarda mucho


