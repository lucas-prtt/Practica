import re
from functools import reduce
file = open("./10 - Fabrica/puzzle-input.txt")
class Button:
    def __init__(self, lights:list[int]):
        self.lights = lights
    def __repr__(self):
        return f"({",".join(map(str, self.lights))})"
    def press(self, lights:list[bool]) -> list[bool]:
        newLights = lights[:]
        for i in self.lights:
            newLights[i] = not newLights[i]
        return newLights

class Machine:
    def __init__(self, line:str):
        lights = re.search(r"\[[.#]+\]", line).group()
        self.lights = list(map(lambda x : True if x == "#" else False, lights.removeprefix("[").removesuffix("]")))
        buttons = re.findall(r"\((\d+(?:,\d+)*)\)", line)
        self.buttons = list(map(lambda x: Button(list(map(int, str(x).removeprefix("(").removesuffix(")").split(",")))),buttons))
        voltage = re.search(r"\{(\d+(?:,\d+)*)\}", line).group()
        self.voltage = list(map(int, voltage.removesuffix("}").removeprefix("{").split(",")))
    def __repr__(self):
        return f"{self.lightRep(self.lights)} - {self.buttons} - {self.voltage}"
    def isOn(self, lights:list[bool]):
        return all(map(lambda l: l[0] == l[1],zip(self.lights, lights)))
    def lightRep(self, lights: list[bool]):
        return "▕" + "".join(list(map(lambda b : "█" if b else "░", lights))) + "▏"
    def validSequence(self, buttons:list[Button]):
        # Supongo que los buttons son parte de los asignados
        return self.isOn(reduce(lambda l, b:b.press(l), buttons, [False] * len(self.lights)))

machines = []
for line in file.readlines():
    machines.append(Machine(line))
def listWithout(list:list, element):
    l = list[:]
    l.remove(element)
    return l
def findSolution(machine : Machine) -> list[Button]:
    # IMPLEMENTADO - Apretar un boton dos veces no tiene sentido. Max una vez por boton
    # NO IMPLEMENTADO - El orden de los botones no altera el resultado
    # NO APLICA EN EL INPUT - Si dos botones son iguales, se puede simplificar considerando que es uno solo
    availableButtons = machine.buttons
    queue = [] # tuple[list[Button], list[Button]] -> (Boton)
    for button in availableButtons:
        queue.append(([button], listWithout(availableButtons, button)))
    while queue:
        sol = queue.pop(0)
        if(machine.validSequence(sol[0])):
            return sol[0]
        else:
            for notSelected in sol[1]:
                queue.append((sol[0] + [notSelected], listWithout(sol[1], notSelected)))

i = 0

for m in machines: 
    print(m, i)
    i+=len(findSolution(m))
print(i)