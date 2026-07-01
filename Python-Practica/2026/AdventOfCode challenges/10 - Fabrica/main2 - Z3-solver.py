import re
from functools import reduce
from itertools import combinations
import z3
file = open("./10 - Fabrica/puzzle-input.txt")
class Button:
    def __init__(self, voltages:list[int]):
        self.voltages = voltages
    def __repr__(self):
        return f"({",".join(map(str, self.voltages))})"
    def press(self, voltages:list[bool]) -> list[bool]:
        newVoltages = voltages[:]
        for i in self.voltages:
            newVoltages[i]+=1
        return newVoltages

class Machine:
    def __init__(self, line:str):
        buttons = re.findall(r"\((\d+(?:,\d+)*)\)", line)
        self.buttons = list(map(lambda x: Button(list(map(int, str(x).removeprefix("(").removesuffix(")").split(",")))),buttons))
        voltage = re.search(r"\{(\d+(?:,\d+)*)\}", line).group()
        self.target_voltage = list(map(int, voltage.removesuffix("}").removeprefix("{").split(",")))
    def __repr__(self):
        return f"{self.buttons} - {self.target_voltage}"
    def validSequence(self, buttons:list[Button]):
        return self.target_voltage == (reduce(lambda l, b:b.press(l), buttons, [0 for i in range(len(self.target_voltage))]))
    def afterPresses(self, buttons:list[int]):
        r = [0 for i in range(len(self.target_voltage))]
        for i, b in enumerate(self.buttons):
            for v in b.voltages:
                r[v] += buttons[i]
        return r
    
machines = []
for line in file.readlines():
    machines.append(Machine(line))
def listWithout(list:list, element):
    l = list[:]
    l.remove(element)
    return l

def voltageValue(buttonPresses : list[int], buttons : list[Button], voltageIndex : int) -> int:
    retVoltage = 0
    for i, b in enumerate(buttons):
        if(b.voltages.__contains__(voltageIndex)):
            retVoltage += buttonPresses[i]
    return retVoltage
def findSolution(machine : Machine) -> list[Button]:
    s = z3.Optimize()
    availableButtons = machine.buttons
    z3presses = [z3.Int(f"{i}") for i in range(len(availableButtons))]
    for i in range(len(machine.buttons)):
        s.add(z3presses[i] >= 0)
    for i in range(len(machine.target_voltage)):
        s.add(voltageValue(z3presses, availableButtons, i) == machine.target_voltage[i])    
    
    total_presses = z3.Sum(z3presses)
    s.minimize(total_presses)
    s.check()
    model = s.model()
    presses = [model.evaluate(v).as_long() for v in z3presses]
    return presses

i = 0

for m in machines: 
    sol = findSolution(m)
    print(f"SOLVED:{m}  -  {sol}")
    i+=sum(sol)
print(f"PRESSES: {i}")