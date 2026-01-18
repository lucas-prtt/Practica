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
        return f"({",".join(map(str, self.lights))})"
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
    def validSequence(self, buttons:list[Button]):
        nvoltage = [0] * len(self.voltage)
        for b in buttons:
            b.press(nvoltage)
        return self.isCorrect(nvoltage)
machines = []
for line in file.readlines():
    machines.append(Machine(line))
def listWithout(list:list, element):
    l = list[:]
    l.remove(element)
    return l
def findSolution(machine : Machine) -> list[Button]:
    # El orden no importa, se puede repetir el boton, combinaciones con repeticiones
    # No tiene sentido presionar botones que modifican los numeros que ya estan correctos
    # Si un "Camino" se pasa en un numero de entrada, no tiene sentido intentar agregar mas cosas
    availableButtons = machine.buttons
    for i in range(1, sum(machine.voltage)):
        for sol in combinations_with_replacement(availableButtons, i):
            if(machine.validSequence(sol)):
                return sol

i = 0
t1 = time.perf_counter_ns()
for m in machines*10: 
    i+=len(findSolution(m))
print(f"Solved in {msSince(t1)} ms")
print(i)