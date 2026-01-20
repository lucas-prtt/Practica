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

def validForMultiple(multiple : int, parityGoal:list[int], buttons:list[Button]):
    # 1 = impar, 0 = par
    voltages = [0 for x in range(len(parityGoal))]
    for b in buttons:
        b.press(voltages)
    return all(map(lambda x : x[0]%multiple == x[1]%multiple, zip(voltages, parityGoal)))


machines = []

for line in file.readlines():
    machines.append(Machine(line))


def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    voltages = machine.voltage
    return findSolutionRec(availableButtons, voltages)

def findSolutionRec(buttons : list[Button], voltagesParam : list[int]):
    voltages = voltagesParam[:] # Por las dudas creo lista duplicada
    # Va a dividir los problemas en 2 hasta poderlos resolver. Puede que sea buena idea guardar los resultados parciales en un diccionario para agilizar. No estoy seguro que sea la solucion optima, pero al menos me va a dar una solucion. Luego veo como optimizarla
    m = 0
    for i in range(1, int(sum(voltages)/2)):
        paritySol = findForMultiple(i, buttons, voltages)
        m = i
        if(paritySol == None):
            break
    if(paritySol == None):
        for i in range(1, sum(voltages)):
            for sol in combinations_with_replacement(buttons, i):
                if(validSequence(voltages, sol)):
                    return sol
        raise Exception("No se pudo resolver", buttons, voltages)
    else:
        sol = []
        for b in paritySol:
            b.unpress(voltages) # Modifica lista, quedan todos los voltages pares
        sol.extend(paritySol)
        partialVoltages = list(map(lambda x : int(x/m), voltages))
        partialSol = findSolutionRec(buttons, partialVoltages)
        # Dividir problema en 2 y llamar recursivamente. Un solo llamado alcanza, ya que son iguales
        for i in range(m):
            sol.extend(partialSol)
        return sol 
    

def findForMultiple(multiple : int, buttons : list[Button], voltages = list[int]) -> list[Button]:
    for i in range(1, len(buttons)+1):
        for sol in combinations(buttons, i):
            if(validForMultiple(multiple, voltages, sol)):
                return list(sol)



i = 0

for m in machines: 
    i+=len((findSolution(m)))
    print(i)

print(i) # Debe ser 33 en test