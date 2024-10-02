class EnfermedadInfecciosa{
  var property celulasAmenazadas
  method agresiva(persona) = (persona.celulas()/10) < celulasAmenazadas
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