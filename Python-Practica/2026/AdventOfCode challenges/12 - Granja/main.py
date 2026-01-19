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

