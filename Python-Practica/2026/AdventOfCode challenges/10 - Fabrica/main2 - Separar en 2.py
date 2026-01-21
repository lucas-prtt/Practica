import re
from functools import reduce
from itertools import combinations_with_replacement, combinations
import time
file = open("./10 - Fabrica/test.txt")
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
            if(voltages[i]<0):
                raise Exception("No se pudo reducir el voltaje por debajo de 0")
    
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
    voltages = [0 for x in range(len(parityGoal))]
    for b in buttons:
        b.press(voltages)
    return all(map(lambda x : x[0]%2 == x[1]%2, zip(voltages, parityGoal)))


machines = []

for line in file.readlines():
    machines.append(Machine(line))


def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    voltages = machine.voltage
    #print(f"Called: {availableButtons}, {voltages}")
    return findSolutionRec(availableButtons, voltages)

def findSolutionRec(buttons : list[Button], voltagesParam : list[int]):
    # Va a dividir los problemas en 2 hasta poderlos resolver. Puede que sea buena idea guardar los resultados parciales en un diccionario para agilizar. No estoy seguro que sea la solucion optima, pero al menos me va a dar una solucion. Luego veo como optimizarla
    #print(f"Called: {voltagesParam}")
    paritySols = list(findForParity(buttons, voltagesParam))
    #print(f"{paritySols}") 

    for paritySol in paritySols:
        voltages = voltagesParam[:]
        if(all(map(lambda x: x == 0, voltages))):
            return []
        try:
            sol = []
            for b in paritySol:
                b.unpress(voltages) # Modifica lista, quedan todos los voltages pares
            sol.extend(paritySol)
            partialVoltages = list(map(lambda x : int(x/2), voltages))
            partialSol = findSolutionRec(buttons, partialVoltages)
            sol.extend(partialSol)
            sol.extend(partialSol)
            return sol
        except:
            pass 
    raise Exception("No se pudo resolver", buttons, voltagesParam)

        

def findForParity(buttons : list[Button], voltages = list[int]):
    for i in range(0, len(buttons)+1):
        for sol in combinations(buttons, i):
            if(validForParity(voltages, sol)):
                yield list(sol)



i = 0
it = 0
start = time.perf_counter()
for m in machines: 
    sol = findSolution(m)
    i+=len(sol)
    it+=1
    print(it, i)
    print(f"SOLUCION: ({len(sol)}), {sol}")
print(f"Pulsaciones: {i}")
print(f"Tiempo: {time.perf_counter()-start:.2f} s")
