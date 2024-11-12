import PuestosLaborales.*
class Agente{
    const habilidades
    var tipo
    var salud
    method incapacitado() = salud < self.saludCritica()
    method saludCritica() = tipo.saludCritica()
    method ganarEstrella(){tipo.ganarEstrella()}
    method salud() = salud
    method estrellas() = tipo.estrellas()
    method transformarEnEspia() {
        if(tipo.esEspia()){throw new Exception(message = "Ya es espia")}
        else if(tipo.masDe3Estrellas()){throw new Exception(message = "No puede ser espia aun")}
        else{tipo = espia}
    }
    method estaVivo() = salud > 0
    method puedeUsarHabilidad(unaHabilidad) = habilidades.contains(unaHabilidad) and !self.incapacitado()
    method aprenderHabilidad(unaHabilidad) = habilidades.add(unaHabilidad)
    method ganarVida(magnitud){salud += magnitud}
    method perderVida(magnitud){salud -= magnitud}
    method completarMision(mision){
        tipo.completarMision(mision, self)
    }
    method puedeCompletarMisionSolo(mision) = mision.completablePorIndividuo(self)
    method completarMisionSolo(mision){
        if (self.puedeCompletarMisionSolo(mision)){
            self.completarMision(mision)
            self.perderVida(mision.dificultad())
        }else{
            throw new Exception(message = "No pudo completar mision")
        }
    }
    method aprenderHabilidadesDeMision(mision) {
        mision.enseniarHabilidades(self)
    }
    
}

class Jefe inherits Agente{
    const subordinados = #{}
    override method puedeUsarHabilidad(unaHabilidad) = super(unaHabilidad) or subordinados.any{empleado => empleado.puedeUsarHabilidad(unaHabilidad)}
    method agregarSubordinado(unSubordinado) {subordinados.add(unSubordinado)}
    method quitarSubordinado(unSubordinado) {subordinados.remove(unSubordinado)}
}

