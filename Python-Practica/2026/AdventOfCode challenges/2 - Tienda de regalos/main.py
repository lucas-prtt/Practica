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
    digits = floor(log(id, 10)) + 1
    if(digits%2): # Impares da 1 -> True, Pares da 0 -> False
       return False # Los de 3, 5, 7... digitos nunca cumplen
    
    halfIndex = int(digits/2)
    separator = pow(10, halfIndex)
    # print(str(halfIndex) + " - " + str(digits)  + " - " + str(separator) + " - " + str(id) + "       ::       " + str(id % separator) + " - " + str(id/separator))
    # Ej: numero 123456, half = 3, separator = 1000, queda el if(456 == 123)
    if(id % separator == floor(id / separator)):
        return True
    else:
        return False
    
acum = 0

for numbersRange in parse(file.read()):
    for number in numbersRange.numbers():
        if(isInvalid(number)):
            acum += number

print(acum)
