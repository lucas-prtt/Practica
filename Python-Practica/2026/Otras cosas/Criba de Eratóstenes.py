from math import sqrt

def isPrime(num):
    for i in range(2, int(sqrt(num))+1):
        if(num % i == 0):
            return False
    
    return True

def deleteMultiples(lista, num):
    for i in range(num * num, lista[-1] + 1, num):
        if i in lista:
            lista.remove(i)
    

def listaDePrimos(max):
    lista = list(range(2, max))
    for i in lista:
        if(isPrime(i)):
            deleteMultiples(lista, i)
            yield i

max = int(input())

for i in listaDePrimos(max):
    print(str(i))