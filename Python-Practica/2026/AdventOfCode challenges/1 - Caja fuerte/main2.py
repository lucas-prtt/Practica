file = open("./1 - Caja fuerte/puzzle-input.txt")
from math import ceil, floor
def sgn(n:int):
    return n / abs(n)
# Ejecutar desde carpeta AdventOfCode para que encuentre el archivo
def convert(giro): 
    num = int(giro[1:])
    if(giro[0] == 'L'):
        return -num
    elif(giro[0] == 'R'):
        return num
    else:
        raise Exception("Primer caracter no es ni L ni R: " + giro)
    
girosEnteros = list(map(convert, file.readlines()))
#print(girosEnteros)

valorCaja = 50
codigo = 0
def girarPositivo():
    global codigo
    global valorCaja
    valorCaja+=1
    if(valorCaja > 99):
        valorCaja-=100
    if(valorCaja == 0):
        codigo+=1
def girarNegativo():
    global valorCaja
    global codigo
    valorCaja-=1
    if(valorCaja == 0):
        codigo+=1
    if(valorCaja < 0):
        valorCaja+=100
# Simulacion literal
for giro in girosEnteros:
    #print(f"Actual: {valorCaja} - Gira: {giro}")
    if giro < 0:
        for i in range(abs(giro)):
            girarNegativo()
    elif giro > 0:
        for i in range(abs(giro)):
            girarPositivo()

print(codigo)