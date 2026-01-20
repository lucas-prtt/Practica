from math import pow, floor, log

file=open("./2 - Tienda de regalos/puzzle-input.txt")


class Range:
    def __init__(self, min, max):
        self.max = int(max)
        self.min = int(min)
    def numbers(self):
        return range(self.min, self.max)
'''
ej = Range(10, 20)
for i in ej.numbers():
    print(str(i))
'''

def parse(text):
    ranges = str(text).split(",")
    for r in ranges:
        numbers = r.split("-")
        yield Range(numbers[0], numbers[1])


def isInvalid(id : int):
    idstr = str(id)
    for i in range(1, int(len(idstr)/2)+1):
        temp = str(idstr)
        pattern = "".join(list(idstr)[0:i])
        while(temp.startswith(pattern)):
            temp = temp.removeprefix(pattern)
        if(temp == ""):
            #print(f"TRUE {idstr}")
            return True
    return False

acum = 0

for numbersRange in parse(file.read()):
    for number in numbersRange.numbers():
        if(isInvalid(number)):
            acum += number

print(acum)
