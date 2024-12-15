class cosa:
    cantidad = 0
    def __init__(self, *a):
        for i in a:
            self.cantidad+=1
        for i, v in enumerate(a):
            setattr(self, "atributoNumero{}".format(i), v)
            
    
unaCosa = cosa(2, 4, 5, 67, 23)
for x in range(unaCosa.cantidad):
    temp = getattr(unaCosa, "atributoNumero{}".format(x))
    print (temp)
    
