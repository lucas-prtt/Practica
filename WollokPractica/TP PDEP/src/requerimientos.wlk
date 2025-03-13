//  REQUERIMIENTO GENERAL DE ITEMS
import objetos.*

class RequerimientoDeItem {
  const item
  const cantidad
  
  method guerreroCumpleRequerimiento(guerrero) = guerrero.cuantoDeCiertoItem(item) >= cantidad
  
  method grupoCumpleRequerimiento(integrantes) = 
  integrantes.sum({ guerrero => guerrero.cuantoDeCiertoItem(item) }) >= cantidad
}


//   REQUERIMIENTO GENERAL DE GUERREROS
class RequerimientoDeGuerrero {
  
  method guerreroCumpleRequerimiento(guerrero)
  
  method grupoCumpleRequerimiento(integrantes) = integrantes.any(
    { guerrero => self.guerreroCumpleRequerimiento(guerrero) }
  )
}


//   REQUERIMIENTOS PARTICULARES DE GUERREROS (expresados mediante un parametro)

class RequerimientoDeVida inherits RequerimientoDeGuerrero(){
  const vida
  override method guerreroCumpleRequerimiento(guerrero) = guerrero.tieneDeVidaAlMenos(vida)
}

class RequerimientoDeArmas inherits RequerimientoDeGuerrero(){
  const armas
  override method guerreroCumpleRequerimiento(guerrero) = guerrero.cantidadDeArmas() >= armas
}

class RequerimientoDePoder inherits RequerimientoDeGuerrero(){
  const poder
  override method guerreroCumpleRequerimiento(guerrero) = guerrero.poder() >= poder
}


//   SIN REQUISITOS
object ningunRequisito{
  method guerreroCumpleRequerimiento(_) = true
  method grupoCumpleRequerimiento(_) = true
}                     




//  REQUERIMIENTOS PARTICULARES DE LOS EJEMPLOS (¿se puede poner en tests?)

const masDe1500DePoder = new RequerimientoDePoder(poder = 1500)

const tieneAlgunArma = new RequerimientoDeArmas(armas = 1)

const tener10Lembas = new RequerimientoDeItem(item = lemba, cantidad = 10)

const tener3CapasElficas = new RequerimientoDeItem(
  item = capaElfica,
  cantidad = 3
)




