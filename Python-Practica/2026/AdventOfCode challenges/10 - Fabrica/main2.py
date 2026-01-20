import re
from functools import reduce
from itertools import combinations_with_replacement
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
    def validSequence(self, buttons:list[Button]):

        voltages = [0 for x in range(len(self.voltage))]
        for b in buttons:
            b.press(voltages)
        return all(map(lambda x : x[0] == x[1], zip(voltages, self.voltage)))

machines = []

for line in file.readlines():
    machines.append(Machine(line))


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