import consumos.*
import calidad.*

class Linea {
  var calidad = estandar
  var deuda = 0
  const consumos = []
  var paquetes = []
  
  method adeudar(dinero) {
    deuda += dinero
  }
  
  method agregarPaquete(paquete) {
    paquetes.add(paquete)
  }
  
  method consumosEntre(fechaInicial, fechaFinal) = consumos.filter(
    { consumo => consumo.fechaEntre(fechaInicial, fechaFinal) }
  )
  
  method costoTotalEntre(fechaInicial, fechaFinal) = self.consumosEntre(
    fechaInicial,
    fechaFinal
  ).sum({ consumo => consumo.costo() })
  
  method cantidadDeConsumos(fechaInicial, fechaFinal) = self.consumosEntre(
    fechaInicial,
    fechaFinal
  ).size()
  
  method costoPromedioEntre(fechaInicial, fechaFinal) = self.costoTotalEntre(
    fechaInicial,
    fechaFinal
  ) / self.cantidadDeConsumos(fechaInicial, fechaFinal)
  
  method costoTotal30Dias() = self.costoTotalEntre(
    new Date().minusDays(30),
    new Date()
  )
  
  method puedeRealizarConsumo(consumo) = paquetes.any(
    { paquete => paquete.puedeSatsifacer(consumo) }
  )
  
  method realizarConsumo(consumo) {
    if (!self.puedeRealizarConsumo(consumo)) calidad.adeudar(self, consumo)
    else paquetes.reverse().find(
        { paquete => paquete.puedeSatisfacerConsumo(consumo) }
      ).satisfacer(consumo)
    consumos.add(consumo)
  }
  
  method limpiezaDePaquetes() {
    paquetes = paquetes.filter({ paquete => paquete.valido() })
  }
}