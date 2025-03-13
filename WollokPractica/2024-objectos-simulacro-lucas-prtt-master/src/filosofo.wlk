import actividades.*

class Filosofo {
  const nombre
  const honorificos
  var nivelIluminacionBase
  var edadEnDias
  const actividades = #{}
  
  method nivelIluminacion() = nivelIluminacionBase + self.iluminacionExtraPorEdad()
  
  method presentarse() = (nombre + ", ") + self.listar(honorificos)
  
  method listar(setDeStrings) = setDeStrings.join(", ")
  
  method estaEnLoCorrecto() = self.nivelIluminacion() >= 1000
  
  method realizarActividad(actividad) {
    actividad.realizar(self)
  }
  
  method agregarHonorifico(honorifico) {
    honorificos.add(honorifico)
  }
  
  method reducirNivelIluminacion(cuanto) {
    nivelIluminacionBase -= cuanto
  }

  method aumentarNivelIluminacion(cuanto) {
    nivelIluminacionBase += cuanto
  }
  
  method decimaParteDeNivelIluminacion() = self.nivelIluminacion() / 10
  
  method edadEnDias() = edadEnDias
  
  method rejuvenecer(dias) {
    edadEnDias -= dias
  }
  
  method envejecer(dias) {
    edadEnDias += dias
  }
  
  method edad() = (edadEnDias / 365).truncate(0)
  
  method vivirUnDia() {
    self.envejecer(1)
    actividades.forEach({ actividad => actividad.realizar(self) })
    self.actualizarHonorificos()
  }
  
  method actualizarHonorificos() {
    if (self.edad() >= 60) honorificos.add("el sabio")
    else honorificos.remove("el sabio")
      // Pierde el titulo si rejuvenece demasiado
  }
  
  method iluminacionExtraPorEdad() = self.edad() * 10
}

class FilosofoContemporaneo inherits Filosofo {
  override method presentarse() = "hola"
  
  override method nivelIluminacion() = 
  if (actividades.contains(admirarPaisaje)) {
    return super()
  } else {
    return super() * 5
  }
}