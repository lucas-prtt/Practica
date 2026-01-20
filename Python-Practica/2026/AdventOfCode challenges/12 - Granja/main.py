import re

fileName = "./12 - Granja/puzzle-input.txt"

class Gift:
    def __init__(self, lines):
        self.coords = set()
        for i, l in enumerate(lines):
            for j, c in enumerate(l):
                if(c == "#"):
                    self.coords.add((int(j), int(i)))
    def __repr__(self):
        return(f"(Gift {self.coords})")

class Region:
    regex = re.compile("([0-9]+)x([0-9]+): ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)")

    def __init__(self, line):
        numbers = self.regex.search(line).groups()
        self.width = int(numbers[0])
        self.height = int(numbers[1])
        self.gifts = list(map(int, numbers[2:]))
    def __repr__(self):
        return f"(Region {self.width}x{self.height} - {sum(self.gifts)} gifts)"

def parse():
    file = open(fileName)
    gifts = []
    regions = []
    curGift = []
    for line in file.readlines():
        if(line == "\n"):
            gifts.append(Gift(curGift))
            curGift.clear()
        elif(line.__contains__("x")):
            regions.append(Region(line.removesuffix("\n")))
        elif(line.__contains__(":")):
            continue
        else:
            curGift.append(line.removesuffix("\n"))
    return gifts, regions    

gifts, regions = parse()

def obviouslyPosible(region):
    #print(f"{((region.width - region.width % 3) * (region.height - region.height % 3))/9 >= sum(region.gifts)} - {(region.width, region.height)} - {((region.width - region.width % 3), (region.height - region.height % 3))} - {sum(region.gifts)}" )
    if(((region.width - region.width % 3) * (region.height - region.height % 3))/9 >= sum(region.gifts)):
        return True
    return False
def obviouslyImposible(region):
    #print(f"{region.width * region.height < sum(map(lambda x : len(gifts[x[0]].coords) * x[1] , enumerate(region.gifts)))} - {region.width}x{region.height} - {region.width * region.height} - {sum(map(lambda x : len(gifts[x[0]].coords) * x[1] , enumerate(region.gifts)))}")
    if(region.width * region.height < sum(map(lambda x : len(gifts[x[0]].coords) * x[1] , enumerate(region.gifts)))):
        return True
    return False

regionsImposibleToArrange = []
regionsPosibleToArrange = []

regionsImposibleToArrange.extend(list(filter(lambda x : obviouslyImposible(x), regions)))
regionsPosibleToArrange.extend(list(filter(lambda x : obviouslyPosible(x), regions)))
undecidedRegions = list(regions)
for i in regionsImposibleToArrange + regionsPosibleToArrange:
    undecidedRegions.remove(i)
print("Filtro inicial:")
print(f"Regiones totales: {len(regions)}")
print(f"Regiones descartadas como obviamente invalidas: {len(regionsImposibleToArrange)}")
print(f"Regiones descartadas como obviamente validas: {len(regionsPosibleToArrange)}")
print(f"Regiones restantes a analizar: {len(undecidedRegions)}")
# Con mi puzzle input, no me hizo falta ir dando vueltas y probar que encajen, me quedo:
# Regiones totales: 1000
# Regiones descartadas como obviamente invalidas: 528
# Regiones descartadas como obviamente validas: 472
# Regiones restantes a analizar: 0

