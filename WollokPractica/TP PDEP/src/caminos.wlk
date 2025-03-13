import exceptions.*
import zonas.*
class Camino{
    const ubicaciones
    method recorrerPorGuerrero(guerrero){
        if(!guerrero.puedeRecorrerCamino(self)){
            throw new GuerreroNoPuedeRecorrerCaminoException(
            message = (("" + guerrero) + " no puede recorrer ") + self
            )}
        ubicaciones.forEach({ unaZona => guerrero.recorrerZona(unaZona) })
        }


    method recorriblePorGuerrero(guerrero){
        const clonGuerreroTemporal = guerrero.duplicar()
        var valido = true
        ubicaciones.forEach{
            lugarDelCamino => if (!clonGuerreroTemporal.puedeRecorrerZona(lugarDelCamino)) {
            valido = false
            } else {
            clonGuerreroTemporal.recorrerZona(lugarDelCamino)
            }
        }
        return valido
    }

    method recorrerPorGrupo(grupo){
    if (!grupo.puedeRecorrerCamino(self)){
      throw new GrupoNoPuedeRecorrerCaminoException(message = ("" + grupo + " no puede recorrer" + self))
    } 
        ubicaciones.forEach{zona => grupo.recorrerZona(zona)}
    }

    method esValido(){
        var esValido = true
        var primerElemento = true
        ubicaciones.fold(ubicaciones.first(),
        {
            zonaAnterior, zonaActual => 
            if(!zonaAnterior.limitaCon(zonaActual) and !primerElemento)
            esValido = false
            primerElemento = false
            return zonaActual})
        return esValido
    }

    method regionesQueRecorre() = ubicaciones.map({zona => zona.region()}).asSet()

    method recorriblePorGrupo(grupo){
        const copiaDeGrupo = grupo.duplicar()
        var valido = true
        ubicaciones.forEach
            { zona => if (copiaDeGrupo.puedeRecorrerZona(zona)) {
            copiaDeGrupo.recorrerZona(zona)
            } else {
            valido = false
            } }
            return valido
    }
}