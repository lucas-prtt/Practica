

file = open("./5 - Cafeteria/puzzle-input.txt")

#file = open("./5 - Cafeteria/test.txt")
fileLines = iter(file.readlines())
class Range:
    def __init__(self, min : int, max : int):
        self.min = min
        self.max = max
    @classmethod
    def from_string(cls, line: str) -> "Range":
        if "-" in line:
            min_, max_ = map(int, line.split("-"))
            return cls(min_, max_)
        raise Exception
    def overlaps(self, range):
        return(range.min < self.max < range.max or range.min < self.min < range.max or self.min < range.min < self.max) # Ultima comparacion para cuando self envuelve a range completamente, da igual si es maximo o minimo
    def elements(self):
        return self.max - self.min + 1
    def __str__(self):
        return "(Rango - {} hasta {})".format(self.min, self.max)
    def contains(self, num):
        return self.min<=num<=self.max
def merge(range1, range2):
    return(Range(range1.min if range1.min < range2.min else range2.min, range1.max if range1.max > range2.max else range2.max))

unmerged = []
evaluated = []
# Parsear
for line in fileLines:
    if(line == "\n"):
        break
    range = Range.from_string(line)
    unmerged.append(range)
for line in fileLines:
    evaluated.append(int(line))
# print(list(map(str, unmerged)))
# Mergear
merged = []
while(len(unmerged) > 0):
    mergingRange = unmerged.pop(0)
    while(True):
        overlapping = next((x for x in unmerged if mergingRange.overlaps(x)), None)
        if(overlapping != None):
            unmerged.remove(overlapping)
            #print("Merging {} -> Overlaps with {}".format(mergingRange, overlapping))
            mergingRange = merge(mergingRange, overlapping)
        else:
            break
    merged.append(mergingRange)

#print(list(map(str, merged)))
#print(list(evaluated))

freshAmount = 0
for e in evaluated:
    if(any(map(lambda x : x.contains(e), merged))):
        freshAmount+=1
print(freshAmount)
