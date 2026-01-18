import re
file = open("./10 - Fabrica/test.txt")
class Button:
    def __init__(self, lights:list[int]):
        self.lights = lights
    def __repr__(self):
        return f"({",".join(map(str, self.lights))})"

class Machine:
    def __init__(self, line:str):
        lights = re.search(r"\[[.#]+\]", line).group()
        self.targetLights = list(map(lambda x : True if x == "#" else False, lights.removeprefix("[").removesuffix("]")))
        self.lights = list(False for i in range(self.targetLights.__len__()))
        buttons = re.findall(r"\((\d+(?:,\d+)*)\)", line)
        self.buttons = list(map(lambda x: Button(list(map(int, str(x).removeprefix("(").removesuffix(")").split(",")))),buttons))
        voltage = re.search(r"\{(\d+(?:,\d+)*)\}", line).group()
        self.voltage = list(map(int, voltage.removesuffix("}").removeprefix("{").split(",")))
    def __repr__(self):
        return f"{self.lightRep(self.lights)}/{self.lightRep(self.targetLights)} - {self.buttons} - {self.voltage} - {"ON" if self.isOn() else "OFF"}"
    def isOn(self):
        return all(map(lambda l: l[0] == l[1],zip(self.lights, self.targetLights)))
    def lightRep(self, lights: list[bool]):
        return "▕" + "".join(list(map(lambda b : "█" if b else "░", lights))) + "▏"

machines = []
for line in file.readlines():
    machines.append(Machine(line))
for m in machines: print(m)