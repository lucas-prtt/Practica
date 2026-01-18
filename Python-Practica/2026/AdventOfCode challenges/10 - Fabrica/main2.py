import re
from functools import reduce
import time
from itertools import combinations_with_replacement
file = open("./10 - Fabrica/test.txt")
def msSince(startTime):
    return (time.perf_counter_ns()-startTime)/1000000

class Button:
    def __init__(self, voltages:list[int]):
        self.voltages = voltages
    def __repr__(self):
        return f"({",".join(map(str, self.voltages))})"
    def press(self, voltage:list[int]) -> None:
        for i in self.voltages:
            voltage[i] += 1

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
    def voltageAfterPressing(self, buttons:list[Button]):
        nvoltage = [0] * len(self.voltage)
        for b in buttons:
            b.press(nvoltage)
        return nvoltage
    def validSequence(self, buttons:list[Button]):
        return self.isCorrect(self.voltageAfterPressing(buttons))
    def unfixable(self, buttons:list[Button]):
        return any(map(lambda x: x[0]<x[1], zip(self.voltage, self.voltageAfterPressing(buttons))))
machines = []
def sortByVoltages(buttons : list[Button]):
    buttons.sort(key=lambda x : len(x.voltages), reverse=True)
for line in file.readlines():
    machines.append(Machine(line))
def listWithout(list:list, element):
    l = list[:]
    l.remove(element)
    return l
def findSolution(machine : Machine) -> list[Button]:
    buttons = machine.buttons
    voltage = machine.voltage[:]
    matrizGaussiana = list([] for x in range(len(buttons) + 1))
    for n, i in enumerate(buttons):
        for j in range(len(machine.voltage)):
            matrizGaussiana[n].append(0)
        for v in i.voltages:
            matrizGaussiana[n][v] = 1
    for i in voltage:
        matrizGaussiana[len(matrizGaussiana)-1].append(i)
    print(matrizGaussiana)
    
i = 0
t1 = time.perf_counter_ns()
for m in machines: 
    sol = findSolution(m)
    print(sol)
print(f"Solved in {msSince(t1)} ms")
print(i)