class Consumo {
  const fechaDeConsumo
  method fechaEntre(inicio, fin) = fechaDeConsumo.between(inicio, fin)
}

class ConsumoDeInternet inherits Consumo {
    const megabytes
  method costo() = consumo.costoInternet() * megabytes
}

class ConsumoDeLlamada inherits Consumo {
    const segundos
  method costo() = consumo.costoFijoLlamada().max(
    (consumo.costoVariableLlamada() * (segundos - 30)) + consumo.costoFijoLlamada()
  )
}

object consumo {
  var property costoFijoLlamada = 1
  var property costoVariableLlamada = 0.05
  var property costoInternet = 0.1
}