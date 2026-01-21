import re
import cProfile
import pstats
from functools import reduce
from itertools import combinations_with_replacement, combinations
import time
debug = True
if(debug):
    profiler = cProfile.Profile()
    profiler.enable()
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

pressButtonsMemo = dict()
def pressButtons(voltages:int,buttons:list[Button]) -> list[int]:
    key = voltages, tuple(buttons)
    mem = pressButtonsMemo.get(key)
    if(mem != None):
        return mem
    voltages = [0 for x in range(voltages)]
    for b in buttons:
        b.press(voltages)
    pressButtonsMemo[key] = voltages
    return voltages


getParityMemo = dict()
def getParitys(parityGoal:list[int]) -> list[int]:
    return [x%2 for x in parityGoal] # 0 o 1 segun paridad

def matchesParity(numbers:list[int], paritys:list[int]):
    return all(map(lambda x : x[0]%2 == x[1], zip(numbers, paritys)))
    

def validForParity(parityGoal:list[int], buttons:list[Button]):
    paritys = getParitys(parityGoal)
    voltages = pressButtons(len(parityGoal), buttons)
    return matchesParity(voltages, paritys)


machines = []

for line in file.readlines():
    machines.append(Machine(line))


def findSolution(machine : Machine) -> list[Button]:
    availableButtons = machine.buttons
    voltages = machine.voltage
    #print(f"Called: {availableButtons}, {voltages}")
    return findSolutionRec(availableButtons, voltages)

def voltagesSubstracting(buttons : list[Button], voltages):
    v = voltages[:]
    for b in buttons:
        b.unpress(v) # Modifica lista, quedan todos los voltages pares
    return v

def findSolutionRec(buttons : list[Button], voltagesParam : list[int]):
    if(debug):
        global start
        if(time.perf_counter()-start>20):
            start = time.perf_counter()  
            stats = pstats.Stats(profiler)
            stats.strip_dirs()
            stats.sort_stats(pstats.SortKey.TIME)
            stats.print_stats()
    # Va a dividir los problemas en 2 hasta poderlos resolver. Puede que sea buena idea guardar los resultados parciales en un diccionario para agilizar. No estoy seguro que sea la solucion optima, pero al menos me va a dar una solucion. Luego veo como optimizarla
    #print(f"Called: {voltagesParam}")
    paritySolutions = dict()
    for paritySolution in list(findForParity(buttons, voltagesParam)):
        try: 
            voltagesAfterParitySolution = tuple(voltagesSubstracting(paritySolution, voltagesParam))
        except:
            continue
        existing = paritySolutions.get(voltagesAfterParitySolution)

        if(existing == None or len(paritySolution) < len(existing)):
            paritySolutions[voltagesAfterParitySolution] = paritySolution 
            continue
            # Nomas se queda con las soluciones mas cortas si producen el mismo resultado
    #print(voltagesParam)
    #print(f"{paritySolAndResult}") 
    bestSol = None
    for evenVoltage in paritySolutions.keys():
        if(all(map(lambda x: x == 0, evenVoltage))):
            return []
        try:
            partialVoltages = list(map(lambda x : int(x/2), evenVoltage))
            partialSol = findSolutionRec(buttons, partialVoltages)
            sol = []
            sol.extend(paritySolutions[evenVoltage])
            sol.extend(partialSol)
            sol.extend(partialSol)
            if(bestSol == None):
                bestSol = sol
                #print(f"NEW BEST SOL: {bestSol}")
            else:
                if(len(sol)<len(bestSol)):
                    bestSol = sol
                    #print(f"NEW BEST SOL: {bestSol}")
        except Exception as e:
            #print(e)
            pass 
    if(bestSol != None):
        return bestSol
    raise Exception("bestSol == None", buttons, voltagesParam)


# Problema aca Llama a validForParity muchas veces. Toma el 99% del tiempo de computo en esta funcion y las subfunciones que llama
# Hay que encontrar un mejor algoritmo que el iterativo para hallar las combinaciones correctas
def findForParity(buttons : list[Button], voltages = list[int]):
    ans = []
    for i in range(0, len(buttons)+1):
        for sol in combinations(buttons, i):
            if(validForParity(voltages, sol)):
                ans.append(sol)
    return ans


i = 0
it = 0
start = time.perf_counter()
for m in machines: 
    sol = findSolution(m)
    i+=len(sol)
    it+=1
    print(it, i)
    #print(f"SOLUCION: ({len(sol)}), {sol}")
print(f"Pulsaciones: {i}")
print(f"Tiempo: {time.perf_counter()-start:.2f} s")
