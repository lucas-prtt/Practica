
file = open("./3 - Lobby/puzzle-input.txt")

def maxVoltage(bank):
    listaNumerica = list(map(lambda l : int(l) if str(l).isnumeric() else -1, list(bank))) #-1 para el \n para que no me tire error de parseo. Se puede hacer mas prolijo, pero para este caso anda
    n1 = max(listaNumerica[:len(listaNumerica)-1]) # No toma el ultimo, ya que quedaria de un digito
    i = listaNumerica.index(n1) # Agarre la primera ocurrencia, dejando mas opciones para el segundo mayor numero
    n2 = max(listaNumerica[i+1:]) # +1 para no incluir el maximo.
    return n1 * 10 + n2

acum = 0
for i, line in enumerate(file.readlines()):
    voltage = maxVoltage(line)
    print("bank {} --> {}".format(i, voltage))
    acum+=voltage

print("TOTAL: {}".format(acum))
