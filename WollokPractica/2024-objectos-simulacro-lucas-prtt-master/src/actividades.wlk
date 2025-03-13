object tomarVino{
    method realizar(filosofo){
        filosofo.reducirNivelIluminacion(10)
        filosofo.agregarHonorifico("el borracho")
    }
}
class JuntarseCon{
    const conQuienSeJunta
    method realizar(filosofo){
        filosofo.aumentarNivelIluminacion(conQuienSeJunta.decimaParteDeNivelIluminacion())
    }
}
object admirarPaisaje{
    method realizar(_){}
}

class MeditarBajoCascada{
    const alturaCascada
    method realizar(filosofo){
        filosofo.aumentarNivelIluminacion(alturaCascada*10)
    }
}

class PracticarDeporte{
    const dias
    method realizar(filosofo){
        filosofo.rejuvenecer(dias)
    }
}

const practicarFutbol = new PracticarDeporte(dias = 1)
const practicarPolo = new PracticarDeporte(dias = 2)
object practicarWaterpolo {
    method realizar(filosofo){
        2.times{_ => filosofo.realizarActividad(practicarPolo)}
    }
}
