import consumos.*


class Linea {
    const consumos = []
    method consumosEntre(fechaInicial, fechaFinal) = consumos.filter{consumo => consumo.fechaEntre(fechaInicial, fechaFinal)}
    method costoTotalEntre(fechaInicial, fechaFinal) = self.consumosEntre(fechaInicial, fechaFinal).sum{consumo => consumo.costo()}
    method cantidadDeConsumos(fechaInicial, fechaFinal) = self.consumosEntre(fechaInicial, fechaFinal).size()
    method costoPromedioEntre(fechaInicial, fechaFinal) = self.costoTotalEntre(fechaInicial, fechaFinal) / self.cantidadDeConsumos(fechaInicial, fechaFinal)
    method costoTotal30Dias() = self.costoTotalEntre(new Date().minusDays(30), new Date())
}




const unaLinea = new Linea()


