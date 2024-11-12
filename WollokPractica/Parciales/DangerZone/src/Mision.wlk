class Mision{
    const dificultad
    const habilidadesRequeridas = #{}
    method dificultad() = dificultad
    method completablePorIndividuo(individuo) = habilidadesRequeridas.all{habilidad => individuo.puedeUsarHabilidad(habilidad)}
    method completablePorEquipo(equipo) = habilidadesRequeridas.all{habilidad => equipo.alguienPuedeUsarHabilidad(habilidad)}
    method enseniarHabilidades(empleado) = habilidadesRequeridas.forEach({habilidad => empleado.aprenderHabilidad(habilidad)})
}