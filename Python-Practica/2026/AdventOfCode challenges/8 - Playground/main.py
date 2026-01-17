from math import sqrt, pow
import time

file = open("./8 - Playground/puzzle-input.txt")
connectionsAmount = 1000


class JunctionBox:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
        self.connectedBoxes = []

    def connect(self, junctionBox):
        self.connectedBoxes.append(junctionBox)
        junctionBox.connectedBoxes.append(self)

    def getCircuit(self):
        connected = self.circuitBoxesRecursive([])
        return connected

    def circuitBoxesRecursive(self, ignored:list): # Lista en caso que hubiera ciclos, aunque dado el desafio no deberia haber
        connections = [self]
        #print("Connections self {} - connectedBoxes: {}".format(self, self.connectedBoxes))
        for jb in filter(lambda x : not ignored.__contains__(x), self.connectedBoxes):
            newConnections = jb.circuitBoxesRecursive(connections)
            #print("{} connections extended by: {}".format(self, newConnections))
            connections.extend(newConnections)
        return connections

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

def connectClosestTogether(boxes:list[JunctionBox], boxesDistances:list[tuple[JunctionBox, JunctionBox, float]]):
    connections = 0
    requiredConnections = min(len(boxes), connectionsAmount)
    while(connections < requiredConnections):
        box1, box2, distance = boxesDistances.pop(0)
        if(not box1.getCircuit().__contains__(box2)): # O el reciproco implicitamente (Conexiones bidireccionales)
            box1.connect(box2)
            #print("Connected {} with {}".format(box1, box2))
            connections+=1
        else:
            #print("Skipped connection between {} and {}".format(box1, box2))
            connections+=1 # Inicialmente pense que este no contaba, pero al parecer si cuenta en el ejemplo
    return

def nonRepeatingCircuits(boxes : list[JunctionBox]):
    seenBoxes = []
    circuits = []
    for box in boxes:
        if(seenBoxes.__contains__(box)):
            continue
        else:
            circuit = box.getCircuit()
            seenBoxes.extend(circuit)
            circuits.append(circuit)
    return circuits


startTime = time.perf_counter_ns()
boxes = parse(file)
print("{} boxes parsed in {} ms".format(len(boxes), msSince(startTime)))
startTime = time.perf_counter_ns()
boxesDistances = allBoxesDistancesList(boxes)
print("{} distances calculated in {} ms. SizeOf: {} kb".format(len(boxesDistances), msSince(startTime), boxesDistances.__sizeof__()/1024))
startTime = time.perf_counter_ns()
boxesDistances.sort(key = lambda x : x[2])
print("List of {} elements sorted in {} ms".format(len(boxesDistances), msSince(startTime)))
startTime = time.perf_counter_ns()
connectClosestTogether(boxes, boxesDistances)
print("Closest boxes connected in {} ms".format(msSince(startTime)))

circuits = nonRepeatingCircuits(boxes)
circuits.sort(key=len, reverse=True)

print(len(circuits[0])*len(circuits[1])*len(circuits[2]))






