class Operacion{
    const propiedad
    method propiedad() = propiedad
    method disponiblePara(cliente) = propiedad.disponiblePara(cliente)
}

class Alquiler inherits Operacion{
    const mesesDeAlquiler
    method comision() = propiedad.valor() * mesesDeAlquiler / 50000
}
class Venta inherits Operacion{
    method comision() = propiedad.valor() * venta.tasaComision() / 100
}

object venta{
    var property tasaComision = 1.5
}