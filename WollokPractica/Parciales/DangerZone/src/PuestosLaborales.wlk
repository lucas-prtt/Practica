class Oficinista{
    var estrellas = 0
    method saludCritica() = 40 - 5*estrellas
    method ganarEstrella(){estrellas += 1}
    method masDe3Estrellas() = estrellas>3
    method esEspia() = false
    method estrellas() = estrellas
    method completarMision(mision, empleado) = empleado.ganarEstrella()
}

object espia{
    method saludCritica() = 15
    method instanciar() = self
    method esEspia() = true
    method estrellas(){throw new DomainException(message = "Espia no tiene estrellas")}
    method completarMision(mision, empleado) = empleado.aprenderHabilidadesDeMision(mision)
}