class Persona {
  const sueniosPendientes = []
  const sueniosCumplidos = []
  const carrerasInteresantes = []
  const carrerasCompletadas = []
  var hijos = 0
  const sueldoBuscado
  var personalidad

  method cumplirSuenio(suenio) {
    if (!self.puedeCumplir(suenio)) {
      throw new Exception(message = "No se puede cumplir el sueño")
    }
    self.agregarSuenioCumplido(suenio)
    self.removerSuenioPendiente(suenio)
    suenio.cumplir(self)
  }
  
  method agregarSuenioCumplido(suenio) {
    sueniosCumplidos.add(suenio)
  }
  
  method removerSuenioPendiente(suenio) {
    sueniosPendientes.remove(suenio)
  }
  
  method puedeCumplir(suenio) = true
  
  method leInteresaEstudiar(carrera) = carrerasInteresantes.contains(carrera)
  
  method yaEstudio(carrera) = carrerasCompletadas.contains(carrera)
  
  method recibirseDe(carrera) {
    carrerasCompletadas.add(carrera)
  }
  
  method cuantosHijos() = hijos
  
  method tenerHijo() {
    hijos += 1
  }
  
  method aceptaSueldo(unSueldo) = unSueldo >= sueldoBuscado
  
  method sueniosCumplidos() = sueniosCumplidos
  
  method sueniosPendientes() = sueniosPendientes

method cumplirUnSuenio() {
    self.cumplirSuenio(personalidad.eleccion(self))
}

method fluctuarPersonalidad(){
    personalidad = personalidad.siguientePersonalidad()
}

method nivelDeFelicidad() = sueniosCumplidos.sum{suenio => suenio.felicidonios()}
method nivelDeAmbicion() = sueniosPendientes.sum{suenio => suenio.felicidonios()}
method esFeliz() = self.nivelDeFelicidad() > self.nivelDeAmbicion()
method cantidadDeSueniosTotales() = sueniosCumplidos.size() + sueniosPendientes.size()
method cantidadFelicidoniosTotales() = self.nivelDeFelicidad() + self.nivelDeAmbicion()
method esAmbicioso() = (self.cantidadDeSueniosTotales() > 3) and (self.cantidadFelicidoniosTotales() > 100)

}