import guerreros.*
import objetos.*

class Efecto{
    method aplicarEfectoAGuerrero(guerrero)
    method aplicarEfectoAGrupo(integrantes){
        integrantes.forEach{guerrero => self.aplicarEfectoAGuerrero(guerrero)}
    }
}

class PerderObjetos inherits Efecto{
    const objeto 
    const cantidad
    override method aplicarEfectoAGuerrero(guerrero){
        cantidad.times{_ => guerrero.desecharObjeto(objeto)}
    }
}

class GanarObjetos inherits Efecto{
    const objeto 
    const cantidad
    override method aplicarEfectoAGuerrero(guerrero){
        cantidad.times{_ => guerrero.agarrarObjeto(objeto)}
    }
}

class SumarVida inherits Efecto{
    const cantidad
    override method aplicarEfectoAGuerrero(guerrero){
        guerrero.sumarVida(cantidad)
    }
}

class RestarVida inherits Efecto{
    const cantidad
    override method aplicarEfectoAGuerrero(guerrero){
        guerrero.restarVida(cantidad)
    }
}

class MultiplicarVida inherits Efecto{
    const factor
    override method aplicarEfectoAGuerrero(guerrero){
        guerrero.multiplicarVida(factor)
    }
}


object ningunEfecto {
    method aplicarEfectoAGuerrero(_){}
    method aplicarEfectoAGrupo(_){}
}

const restar10DeVida = new RestarVida(cantidad = 10)
const sumar1DeVida = new SumarVida(cantidad = 1)
const aumentar30PorcientoDeVida = new MultiplicarVida(factor = 1.3)
const ganar1PanDeLembas = new GanarObjetos(objeto = panDeLembas, cantidad = 1)
const restar15DeVida = new RestarVida(cantidad = 15)
const perder1CapaElfica = new PerderObjetos(objeto = capaElfica, cantidad = 1)
const ganar1VinoCaliente = new GanarObjetos(objeto = vinoCaliente, cantidad = 1)
const duplicarVida = new MultiplicarVida(factor = 2)



