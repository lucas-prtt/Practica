import consumos.*
import fechasDeVencimiento.*

class Paquete{
    const fechaDeVencimiento = noVence
    method estaVencido() = fechaDeVencimiento.vence()
}
class PaqueteSaldo inherits Paquete{
    var saldo
    method puedeSatifacer(consumo) = saldo >= consumo.costo()
    method satisfacer(consumo){
        saldo -= consumo.costo()
    }
}

class PaqueteMegasLibres inherits Paquete{
    var megas
    method puedeSatifacer(consumo) = consumo.menosMegabytesQue(megas)
    method satisfacer(consumo) {
        megas -= consumo.megabytes()
    }
}

class LlamadasGratis inherits Paquete{
    method puedeSatisfacer(consumo) = consumo.esLlamada()
    method satisfacer(){}
}
class InternetGratisDurante inherits Paquete{
    const dias = []
    method puedeSatisfacer(consumo) = consumo.esInternet() and consumo.diaDeSemanaEntre(dias)
    method satisfacer(){}
}


