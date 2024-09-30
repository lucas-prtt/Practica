class Persona{
  var property celulas
  var property temperatura
  var coma = false
  const enfermedades = []

  method vivir(){
    self.sufrir()
    self.empeorar()
  }

  method sufrir(){
    enfermedades.forEach({enfermedad => enfermedad.atacar(self)})
  }
  method empeorar(){
    enfermedades.forEach({enfermedad => enfermedad.reproducir()})
  }



  method contraer(enfermedad){
    enfermedades.add(enfermedad)
  }

  //Crea una enfermedad pedida y la añade
  method contraerUnaInfeccion(celulasAfectadas){
    const nuevaEnfermedad = new EnfermedadInfecciosa(celulasAmenazadas = celulasAfectadas)
    enfermedades.add(nuevaEnfermedad)
  }
  method contraerUnaEnfermedadAutoinmune(celulasAfectadas){
    const nuevaEnfermedad = new EnfermedadAutoinmune(celulasAmenazadas = celulasAfectadas)
    enfermedades.add(nuevaEnfermedad)
  }


  
  method aumentarTemperatura(grados){
    if (temperatura<(45-grados)) {
      temperatura = temperatura + grados
    }else{
      temperatura = 45
    }
    if (temperatura == 45) {
      coma = true
    }
  }

  method destruirCelulas(celulasDestruidas){
    if(celulas>celulasDestruidas){
      celulas = celulas - celulasDestruidas
    }else{
      celulas = 0
    }
    if (celulas <=1000000){
      coma = true
    }
  }
method estaEnComa() = coma
}


class EnfermedadInfecciosa{
  var property celulasAmenazadas
  method agresiva(persona) = persona.celulas() > (celulasAmenazadas/10)
  method atacar(persona){
    persona.aumentarTemperatura(celulasAmenazadas/1000)
  }
  method reproducir(){
    celulasAmenazadas = celulasAmenazadas * 2
  }
}
class EnfermedadAutoinmune{
  var property celulasAmenazadas
  var duracion = 0
  method agresiva(persona) = duracion > 30
  method atacar(persona){
    persona.destruirCelulas(celulasAmenazadas)
    duracion = duracion + 1
  }
  method reproducir(){}
}


// Ejemplos de enfermedades y personas

const malaria = new EnfermedadInfecciosa(celulasAmenazadas = 500)
const otitis = new EnfermedadInfecciosa(celulasAmenazadas = 100)
const lupus = new EnfermedadAutoinmune(celulasAmenazadas = 100)
const otraMalaria = new EnfermedadInfecciosa(celulasAmenazadas = 800)
const logan = new Persona(celulas = 3000000, temperatura = 36)
const frank = new Persona(celulas = 3500000, temperatura = 36)

