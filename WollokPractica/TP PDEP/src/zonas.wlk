import exceptions.*
import armas.*
import guerreros.*
import requerimientos.*
import grupo.*
import efectos.*
import objetos.*

class Zona {
  //Si no se especifica tomo que no tiene ningun requisito o efecto
  const requisitoIndividual = ningunRequisito
  const requisitoGrupal = ningunRequisito
  const efectoIndividual = ningunEfecto
  const efectoGrupal = ningunEfecto
  var property zonasLimitrofes = []
  const region
  
  method region() = region
  
  method limitaCon(otraZona) = self.limitaAux(otraZona) or otraZona.limitaAux(self)
  
  method limitaAux(otraZona) = zonasLimitrofes.contains(otraZona)
  
  method recorriblePorGuerrero(guerrero) = requisitoIndividual.guerreroCumpleRequerimiento(guerrero)
  
  method recorrerPorGuerrero(guerrero) {
    if (!self.recorriblePorGuerrero(guerrero)) {
      throw new GuerreroNoPuedeRecorrerZonaException(
        message = (guerrero + " no puede recorrer ") + self
      )
    }
    efectoIndividual.aplicarEfectoAGuerrero(guerrero)
  }
  
  method recorriblePorGrupo(grupo) = requisitoGrupal.grupoCumpleRequerimiento(grupo)
  
  method recorrerPorGrupo(grupo) {
    if (!self.recorriblePorGrupo(grupo)) {
      throw new GuerreroNoPuedeRecorrerZonaException(
        message = (grupo + " no puede recorrer ") + self
      )
    }
    efectoGrupal.aplicarEfectoAGrupo(grupo)
  }
}

const lebennin = new Zona(
  requisitoIndividual = masDe1500DePoder,
  requisitoGrupal = masDe1500DePoder,
  zonasLimitrofes = [belfalas, minasTirith],
  region = gondor
)

const minasTirith = new Zona(
  requisitoIndividual = tieneAlgunArma,
  requisitoGrupal = tener10Lembas,
  efectoIndividual = restar10DeVida,
  efectoGrupal = restar15DeVida,
  region = gondor
)

const lossarnach = new Zona(
  requisitoIndividual = ningunRequisito,
  efectoIndividual = sumar1DeVida,
  region = desconocida
)

const bosqueDeFangorn = new Zona(
  requisitoGrupal = tieneAlgunArma,
  efectoGrupal = perder1CapaElfica,
  zonasLimitrofes = [],
  region = rohan
)

const edoras = new Zona(
  efectoGrupal = ganar1VinoCaliente,
  zonasLimitrofes = [bosqueDeFangorn, estemnet],
  region = rohan
)

const estemnet = new Zona(
  requisitoGrupal = tener3CapasElficas,
  efectoGrupal = duplicarVida,
  zonasLimitrofes = [bosqueDeFangorn],
  region = rohan
)

const belfalas = new Zona(
  efectoGrupal = ganar1PanDeLembas,
  zonasLimitrofes = [lamedon],
  region = gondor
)

const lamedon = new Zona(
  efectoGrupal = aumentar30PorcientoDeVida,
  zonasLimitrofes = [edoras],
  region = desconocida
)