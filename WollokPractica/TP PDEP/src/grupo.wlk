import exceptions.*
class GrupoDeGuerreros {
  const integrantes = #{} //Set de guerreros
  
  method integrantesEnCondiciones() = integrantes.filter{guerrero => !guerrero.fueraDeCombate()}

  method agregarIntegrante(guerrero) {
    integrantes.add(guerrero)
  }

  method removerIntegrante(guerrero) {
    integrantes.remove(guerrero)
  }
  
  method puedeRecorrerZona(zona) = zona.recorriblePorGrupo(self.integrantesEnCondiciones())
  
  method recorrerZona(zona) {
    zona.recorrerPorGrupo(self.integrantesEnCondiciones())
  }

  method duplicar() {
    // return new GrupoDeGuerreros(integrantes = integrantes.map { guerrero => guerrero.duplicar() })


    const copia = new GrupoDeGuerreros()
    integrantes.forEach(
      { guerrero => copia.agregarIntegrante(guerrero.duplicar()) }
    )
    return copia
  }
  
  method puedeRecorrerCamino(camino) = camino.recorriblePorGrupo(self)

  method recorrerCamino(camino){
    camino.recorrerPorGrupo(self)
  }

}