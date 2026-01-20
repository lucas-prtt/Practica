import re
from functools import reduce
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
    #print(f"Called: {buttons}, {voltagesParam}")
    paritySols = list(findForParity(buttons, voltagesParam))
    #print(f"{paritySols}")
    def solvable(voltages):
        return sum(voltages) / len(voltages) < 2
    
    for paritySol in paritySols:
        voltages = voltagesParam[:]
        if(solvable(voltages)):
            for i in range(1, sum(voltages)):
                for sol in combinations_with_replacement(buttons, i):
                    if(validSequence(voltages, sol)):
                        return sol
            raise Exception("No se pudo resolver", buttons, voltages)
        else:
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

        

def findForParity(buttons : list[Button], voltages = list[int]) -> list[Button]:
    for i in range(0, len(buttons)+1):
        for sol in combinations(buttons, i):
            if(validForParity(voltages, sol)):
                yield list(sol)



i = 0

for m in machines: 
    sol = findSolution(m)
    print(f"SOLUCION: ({len(sol)}), {sol}")

