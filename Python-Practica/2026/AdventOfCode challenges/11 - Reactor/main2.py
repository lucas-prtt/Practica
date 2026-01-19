import re
from typing import Callable
input = "./11 - Reactor/puzzle-input.txt"
def find(criteria:Callable, flist:list):
    return next(filter(criteria, flist))
class Device:
    def __init__(self, this:str, connected:list[str]):
        self.code = this
        self.connectionCodes = connected
        self.connections = []
        self.calculatedPaths = dict()
    def connect(self, device):
        self.connections.append(device)
    def __repr__(self):
        return f"({self.code}, {"Final" if self.final else "NonFinal"}, {len(self.connections)})"
    def pathsTo(self, target:str):
        preCalc = self.calculatedPaths.get(target)
        if(preCalc != None):
            return preCalc
        if(self.connectionCodes.__contains__(target)):
            return 1
        i = 0
        for c in self.connections:
            i+=c.pathsTo(target)
        self.calculatedPaths[target] = i
        return i

def parse():    
    devices = []
    file = open(input)
    def findDevice(code:str):
        return find(lambda x : x.code == code, devices)
    for line in file.readlines():
        origin = re.search(r"[a-z]{3}:", line).group().removesuffix(":")
        dest = list(map(str.strip, re.findall(" [a-z]{3}", line)))
        devices.append(Device(origin, dest))
    for device in devices:
        for connectedCode in device.connectionCodes:
            if(connectedCode != "out"):
                connectedDevice = findDevice(connectedCode)
                device.connect(connectedDevice)
    return devices

devices = parse()
def findDevice(code:str) -> Device: return find(lambda x:x.code == code, devices)

me = findDevice("svr")
print(me.pathsTo("out"))


