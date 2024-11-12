object oficinista{
    method saludCritica(estrellas) = 40 - 5*estrellas
    method esEspia() = false
    method completarMision(mision, empleado) = empleado.ganarEstrella()
}


object espia{
    method saludCritica(estrellas) = 15
    method esEspia() = true
    method completarMision(mision, empleado) = empleado.aprenderHabilidadesDeMision(mision)
}