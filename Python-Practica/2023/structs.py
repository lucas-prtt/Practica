class Estudiante:
    def __init__(self, inputnombre, inputnota) -> None:
        self.nombre = inputnombre
        self.notas = [inputnota]
    pass

def enumerarnotas(notas):
    todaslasnotas = ""
    for x in notas:
        todaslasnotas = x +" - " + todaslasnotas
    todaslasnotas = todaslasnotas.strip(" -")
    print(todaslasnotas)

Estudiantes = []
inputnombre = ""
inputnombre = input("Nombre: ")
inputnota = 0
while inputnombre!="":
    inputnota = input("Nota: ")
    repetido = False
    pos = 0
    for x in range(0, Estudiantes.__len__()):
        if Estudiantes[x].nombre == inputnombre:
            repetido = True
            pos = x
    if repetido:
        Estudiantes[pos].notas.append(inputnota)
    else:
        nuevo = Estudiante(inputnombre, inputnota)
        Estudiantes.append(nuevo)
    inputnombre = input("Nombre: ")

print("  ---- ---- ---- ---- ----\n")
for x in Estudiantes:
    print(x.nombre)
    enumerarnotas(x.notas)
