import re
from functools import reduce
from itertools import combinations_with_replacement
file = open("./10 - Fabrica/puzzle-input.txt")
class Button:
    def __init__(self, voltages:list[int]):
        self.voltages = voltages
    def __repr__(self):
        return f"({",".join(map(str, self.lights))})"
    def press(self, voltage:list[int]) -> list[bool]:
        newVoltage = voltage[:]
        for i in self.voltages:
            newVoltage[i] += 1
        return newVoltage

class Machine:
    def __init__(self, line:str):
        buttons = re.findall(r"\((\d+(?:,\d+)*)\)", line)
        self.buttons = list(map(lambda x: Button(list(map(int, str(x).removeprefix("(").removesuffix(")").split(",")))),buttons))
        voltage = re.search(r"\{(\d+(?:,\d+)*)\}", line).group()
        self.voltage = list(map(int, voltage.removesuffix("}").removeprefix("{").split(",")))
    def __repr__(self):
        return f"{self.buttons} - {self.voltage}"
    def isCorrect(self, voltages:list[int]):
        return all(map(lambda l: l[0] == l[1],zip(self.voltage, voltages)))
    def validSequence(self, buttons:list[Button]):
        # Supongo que los buttons son parte de los asignados
        return self.isCorrect(reduce(lambda l, b:b.press(l), buttons, [0] * len(self.voltage)))

machines = []
for line in file.readlines():
    machines.append(Machine(line))
def listWithout(list:list, element):
    l = list[:]
    l.remove(element)
    return l
def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    for i in range(1, sum(machine.voltage)):
        for sol in combinations_with_replacement(availableButtons, i):
            if(machine.validSequence(sol)):
                return sol

i = 0

for m in machines: 
    i+=len(findSolution(m))
print(i)