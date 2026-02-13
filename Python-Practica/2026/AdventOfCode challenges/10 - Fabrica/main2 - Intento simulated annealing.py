import re
from functools import reduce
import math
import random
from itertools import combinations_with_replacement, combinations
file = open("./10 - Fabrica/puzzle-input.txt")
class Button:
    def __init__(self, voltages:list[int]):
        self.voltages= voltages
    def __repr__(self):
        return f"({",".join(map(str, self.voltages))})"
    def press(self, voltages:list[bool]) -> None:
        for i in self.voltages:
            voltages[i] += 1
    def unpress(self, voltages:list[bool]) -> None:
        for i in self.voltages:
            voltages[i] -= 1
    
class Machine:
    def __init__(self, line:str):
        buttons = re.findall(r"\((\d+(?:,\d+)*)\)", line)
        self.buttons = list(map(lambda x: Button(list(map(int, str(x).removeprefix("(").removesuffix(")").split(",")))),buttons))
        voltage = re.search(r"\{(\d+(?:,\d+)*)\}", line).group()
        self.voltage = list(map(int, voltage.removesuffix("}").removeprefix("{").split(",")))
    def __repr__(self):
        return f"{self.buttons} - {self.voltage}"
def validSequence(voltagesGoal:list[int], buttons:list[Button]):
    voltages = [0 for x in range(len(voltagesGoal))]
    for b in buttons:
        b.press(voltages)
    return all(map(lambda x : x[0] == x[1], zip(voltages, voltagesGoal)))


machines = []

for line in file.readlines():
    machines.append(Machine(line))

def solRating(buttons : list[Button], voltages : list[int]):
    v = [0 for x in range(len(voltages))]
    for b in buttons:
        b.press(v)
    distanciaACorrecta = sum(map(lambda x : abs(x[0]-x[1]), zip(voltages, v)))
    cantidadDePulsaciones = len(buttons)
    return distanciaACorrecta, cantidadDePulsaciones

def esMejorSegundoRating(rating1, rating2):
    if(rating1[0] < rating2[0]):
        return False
    elif(rating1[0] > rating2[0]):
        return True
    else:
        return rating1[1] > rating2[1]

def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    voltages = machine.voltage
    coolingRate = 0.9995
    # Simulated annealing?
    best = []
    bestRating = solRating(best, voltages)
    curr = [availableButtons[0] for x in range(10)]
    def getVecino(initialSol:list[Button]):
        action = random.randrange(0, 3)
        sol2 = initialSol[:]
        if(action == 0):# Replace
            if(len(sol2) == 0):
                return sol2
            i = random.randrange(0, len(sol2))
            removed = sol2.pop(i)
            sol2.append(availableButtons[random.randrange(0, len(availableButtons))])
        elif(action == 1):# Remove
            i = random.randrange(0, len(sol2))
            removed = sol2.pop(i)
        elif(action == 2):# Add
            sol2.append(availableButtons[random.randrange(0, len(availableButtons))])
        else:
            raise Exception("Random dio valor no permitido")
        return sol2
    temp = 20
    while(temp > 0.1):
        compared = getVecino(curr)
        currRating = solRating(curr, voltages)
        neighbourRating = solRating(compared, voltages)
        diff = neighbourRating[0] - currRating[0]
        if(esMejorSegundoRating(currRating, neighbourRating)):
            curr = compared
            if(esMejorSegundoRating(bestRating, neighbourRating)):
                best = compared
                bestRating = solRating(best, voltages)
        else:
            if random.uniform(0, 1) < math.exp(-diff / temp):
                curr = compared
        temp *= coolingRate
    return best, bestRating



i = 0

print(findSolution(machines[0]))