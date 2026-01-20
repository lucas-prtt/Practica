import re
from functools import reduce
from itertools import combinations_with_replacement, combinations
file = open("./10 - Fabrica/test.txt")
class Button:
    def __init__(self, voltages:list[int]):
        self.voltages= voltages
    def __repr__(self):
        return f"({",".join(map(str, self.voltages))})"
    def press(self, voltages:list[bool]) -> None:
        for i in self.voltages:
            voltages[i] += 1

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

def validForParity(parityGoal:list[int], buttons:list[Button]):
    # 1 = impar, 0 = par
    voltages = [0 for x in range(len(parityGoal))]
    for b in buttons:
        b.press(voltages)
    return all(map(lambda x : x[0]%2 == x[1]%2, zip(voltages, parityGoal)))


machines = []

for line in file.readlines():
    machines.append(Machine(line))


def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    for i in range(1, sum(machine.voltage)):
        for sol in combinations_with_replacement(availableButtons, i):
            if(validSequence(machine.voltage, sol)):
                return sol

def findForParity(machine = [Machine], voltages = list[int]) -> list[Button]:
    availableButtons = machine.buttons
    for i in range(1, len(availableButtons)+1):
        for sol in combinations(availableButtons, i):
            if(validForParity(voltages, sol)):
                return sol



i = 0

for m in machines: 
    i+=1 
    print(f"MAQUINA - {i}")
    print(findSolution(m))
    print(findForParity(m, m.voltage))
