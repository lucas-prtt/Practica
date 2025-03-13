class Argumento {
  const naturalezas // Set con uno a 4 objetos
  const descripcion
  
  method enriquecedor() = naturalezas.all(
    { naturaleza => naturaleza.enriquecedor(self) }
  )
  
  method masDe10Palabras() = descripcion.words().size() >= 10
  
  method esPregunta() = descripcion.charAt(descripcion.size() - 1) == "?"
}