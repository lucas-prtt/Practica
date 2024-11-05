import consumos.*

class Linea {
  const consumos = []
  const paquetes = []
  
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

  method puedeRealizarConsumo(consumo) = paquetes.any{paquete => paquete.puedeSatsifacer(consumo)}

    method realizarConsumo(consumo){
        if (!self.puedeRealizarConsumo(consumo)){
            throw new Exception(message = "No puede realizar este consumo. Ningun paquete se lo permite")
        }
        consumos.add(consumo)
        paquetes.reverse().find{paquete => paquete.puedeSatisfacerConsumo(consumo)}.satisfacer(consumo)
    }

}

const unaLinea = new Linea()
