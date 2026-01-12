from math import pow
file = open("./3 - Lobby/puzzle-input.txt")

def maxVoltage(bank : str, batteries : int):
    voltage = 0
    bank = bank.removesuffix('\n')
    listaNumerica = list(map(int, list(bank)))
    for NBateria in range(batteries).__reversed__():
        maximo = max(listaNumerica[:len(listaNumerica) - NBateria]) # No son elegibles los que esten muy cerca del final, ya que podria forzar a que no se usen todos los digitos, lo que causa que siempre sea mas chico que cualquiera que si use todos los digitos
        indice = listaNumerica.index(maximo)
        listaNumerica = listaNumerica[indice + 1:]
        voltage += maximo * pow(10, NBateria)
    return voltage

acum = 0
for i, line in enumerate(file.readlines()):
    voltage = maxVoltage(line, 12)
    print("bank {} --> {}".format(i, voltage))
    acum+=voltage

print("TOTAL: {}".format(acum))