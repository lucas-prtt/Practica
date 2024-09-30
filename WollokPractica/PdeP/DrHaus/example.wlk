class persona{
  var property celulas = 4000000
}

const malaria = new enfermedad(celulasInfectadas = 500)

class enfermedad{
  var property celulasInfectadas
  method agresiva(Persona) = Persona.celulas() > (celulasInfectadas/10)
}