import re
from typing import Callable
input = "./11 - Reactor/puzzle-input.txt"
def find(criteria:Callable, flist:list):
    return next(filter(criteria, flist))
class Device:
    def __init__(self, this:str, connected:list[str]):
        self.code = this
        self.connectionCodes = connected
        if self.connectionCodes.__contains__("out"):
            self.isFinal = True
            self.connectionCodes.remove("out")
        else:
            self.isFinal = False
        self.connections = []
    def connect(self, device):
        self.connections.append(device)
    def __repr__(self):
        return f"({self.code}, {"Final" if self.final else "NonFinal"}, {len(self.connections)})"
    def pathsToOut(self):
        if(self.isFinal):
            return 1
        i = 0
        for c in self.connections:
            i+=c.pathsToOut()
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
            connectedDevice = findDevice(connectedCode)
            device.connect(connectedDevice)
    return devices

devices = parse()
def findDevice(code:str) -> Device: return find(lambda x:x.code == code, devices)

me = findDevice("you")
print(me.pathsToOut())


