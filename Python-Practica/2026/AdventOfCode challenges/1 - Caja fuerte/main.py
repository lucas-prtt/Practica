file = open("./1 - Caja fuerte/puzzle-input.txt")
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
iteraciones = 0

for giro in girosEnteros:
    valorCaja+=giro
    while(valorCaja>99):
        valorCaja-=100
    while(valorCaja<0):
        valorCaja+=100
    if(valorCaja == 0):
        codigo += 1
print(iteraciones)
print(codigo)
