class Enfermedad{
  var property celulasAmenazadas
  method atenuar(cantidadDeCelulas) {
    celulasAmenazadas -= cantidadDeCelulas
  }
  method curada() = celulasAmenazadas<=0
}


class EnfermedadInfecciosa inherits Enfermedad{
  method agresiva(persona) = (persona.celulas()/10) < celulasAmenazadas
  method atacar(persona){
    persona.aumentarTemperatura(celulasAmenazadas/1000)
  }
  method reproducir(){
    celulasAmenazadas = celulasAmenazadas * 2
  }
} 
class EnfermedadAutoinmune inherits Enfermedad{
  var duracion = 0
  method agresiva(persona) = duracion > 30
  method atacar(persona){
    persona.destruirCelulas(celulasAmenazadas)
    duracion = duracion + 1
  }
  method reproducir(){}
}

class LaMuerte {
  method agresiva(_) = true
  method atacar(paciente){
    paciente.aumentarTemperatura(-9)
  }
  method atenuar(_){}
  method celulasAmenazadas() = 0
  method curada() = false
}