import consumos.*
import fechasDeVencimiento.*

class Paquete{
    const fechaDeVencimiento = noVence
    method valido() = not (self.acabado() or self.estaVencido())
    method estaVencido() = fechaDeVencimiento.vence()
    method acabado()
    }
class PaqueteSaldo inherits Paquete{
    var saldo
    override method acabado() = saldo == 0
    method puedeSatisfacer(consumo) = saldo >= consumo.costo()
    method satisfacer(consumo){
        saldo -= consumo.costo()
    }
}

class PaqueteMegasLibres inherits Paquete{
    var megas
    override method acabado() = megas == 0
    method puedeSatisfacer(consumo) = consumo.menosMegabytesQue(megas)
    method satisfacer(consumo) {
        megas -= consumo.megabytes()
    }
}

class LlamadasGratis inherits Paquete{
    override method acabado() = false
    method puedeSatisfacer(consumo) = consumo.esLlamada()
    method satisfacer(){}
}
class InternetGratisDurante inherits Paquete{
    const dias = []
    override method acabado() = false
    method puedeSatisfacer(consumo) = consumo.esInternet() and consumo.diaDeSemanaEntre(dias)
    method satisfacer(){}
}

class PaqueteMegasLibresPlusPlus inherits PaqueteMegasLibres{
    override method puedeSatisfacer(consumo) = super(consumo) or consumo.menosMegabytesQue(0.1)
    override method acabado() = false
}


