import Enfermedades.*

class Persona {
  var property celulas
  var property temperatura
  const property enfermedades = []
  method vivir() {
    self.sufrir() //self.empeorar()
  }

  method vivir(dias){
    dias.times({a => self.vivir()})
  }
  
  method sufrir() {
    enfermedades.forEach({ enfermedad => enfermedad.atacar(self) })
  }
  
  method empeorar() {
    enfermedades.forEach({ enfermedad => enfermedad.reproducir() })
  }
  
  method contraer(enfermedad) {
    enfermedades.add(enfermedad)
  }
  
  //Crea una enfermedad pedida y la añade
  method aumentarTemperatura(grados) {
    if (temperatura < (45 - grados)) {
      temperatura += grados
    } else {
      temperatura = 45
    }
  }
  
  method destruirCelulas(celulasDestruidas) {
    if (celulas > celulasDestruidas) {
      celulas -= celulasDestruidas
    } else {
      celulas = 0
    }
  }
  
  method estaEnComa() = (celulas <= 1000000) or (temperatura == 45)

  method celulasAmenazadasPorEnfermedadesAgresivas() = self.enfermedades().filter({enfermedad => enfermedad.agresiva(self)}).map({enfermedad => enfermedad.celulasAmenazadas()}).sum()

  method enfermedadConMasCelulasAmenazadas() = self.enfermedades().max({enfermedad => enfermedad.celulasAmenazadas()})

  method medicar(dosis) {
    enfermedades.forEach({enfermedad => enfermedad.atenuar(15*dosis)})
    enfermedades.removeAllSuchThat({enfermedad => enfermedad.curada()})
  }
}

class Medico inherits Persona{
    var dosis

    method cambiarDosis(nuevaDosis){
        dosis=nuevaDosis
    }
    method atender(paciente){
        paciente.medicar(dosis)
    }
    override method contraer(enfermedad){
        super(enfermedad)
        self.atender(self)
    }
}

class JefeDeDepartamento inherits Medico(dosis = 0){
    const subordinados = #{}
    method contratar(medico){
        subordinados.add(medico)
    }
    override method atender(paciente){
        subordinados.anyOne().atender(paciente)
    }
}


