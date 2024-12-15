import time

#string
Abc = "Hola"

print(Abc)

print(type(Abc))

Def = "Mundo"
Caf = Abc + Def

print(Caf)
print(Abc+Def)
print(Abc + Def)
print("\n\n\n")

#int

Manzanas = 30
Naranjas = 50
print(Naranjas+Manzanas)
print("es un "+ str(type(Manzanas+Naranjas)))

#float
Money = 1150.25
print(Money)

#bool
Feliz = True
print(Feliz)
print(type(Feliz))

#list
print("\n\n\n")

numerospiola = {12, 15, 568, 47}
saludos = {"Hola", "Hello", "Guten tag", 410, True}

#Tuples _ Listas invariables

pares = (2, 4, 6, 8, 10, 12, 14, 16, 18, 20)

print(type(pares))
print(type(numerospiola))

#Diccionarios

Datos = {"Name":"Lucas",
"Apellido" : "Presotto",
"Hotel" : "Trivago"}

print(type(Datos))
time.sleep(4)
