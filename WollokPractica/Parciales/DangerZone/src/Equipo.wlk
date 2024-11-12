class Equipo{
    const integrantes = #{}
    method agregarIntegrante(unIntegrante) { integrantes.add(unIntegrante)}
    method quitarIntegrante(unIntegrante) {integrantes.remove(unIntegrante)} 
    method completarMision(mision){
        integrantes.forEach{integrante => 
        integrante.perderVida(mision.dificultad() / 3)
        }
        integrantes.filter{integrante => integrante.estaVivo()}.forEach{integrante => integrante.completarMision(mision)}
    }
    method alguienPuedeUsarHabilidad(unaHabilidad) = integrantes.any{integrante=> integrante.puedeUsarHabilidad(unaHabilidad)}
    method puedeCompletarMision(mision) = mision.completalePorEquipo(self)
}