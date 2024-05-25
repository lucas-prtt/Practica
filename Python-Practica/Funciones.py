def recordar():
    temp = 2
    lista = []
    print('Rec\n')
    temp = int(input())
    while temp!=0:
        lista.append(temp) 
        temp = int(input())

    print("Do you want to sort??\n(Y/N)")
    rta = ''
    while rta not in ('y', 'n', 'Y', 'N') :
        rta = input()
        if rta in ('Y', 'y'):
            lista.sort()
    for x in lista:
        print(x)
    input()

recordar()