from math import sqrt, pow
import time

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


def allBoxesDistancesList(availableBoxes : list[JunctionBox]) -> list[tuple[JunctionBox, JunctionBox, int]]:
    allDistances = []
    for box1 in availableBoxes:
        for box2 in availableBoxes[availableBoxes.index(box1)+1:]:
            allDistances.append((box1, box2, box1.distance(box2)))
    return allDistances # n(n+1/2)-n cajas

def msSince(startTime):
    return (time.perf_counter_ns()-startTime)/1000000


startTime = time.perf_counter_ns()
boxes = parse(file)
print("{} boxes parsed in {} ms".format(len(boxes), msSince(startTime)))
startTime = time.perf_counter_ns()
boxesDistances = allBoxesDistancesList(boxes)
print("{} distances calculated in {} ms. SizeOf: {} kb".format(len(boxesDistances), msSince(startTime), boxesDistances.__sizeof__()/1024))
startTime = time.perf_counter_ns()
boxesDistances.sort(key = lambda x : x[2])
print("List of {} elements sorted in {} ms".format(len(boxesDistances), msSince(startTime)))

#for i in range(5):
#    print(boxesDistances[i])




