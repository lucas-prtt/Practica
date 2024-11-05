class Consumo {
  const fechaDeConsumo
method diaDeSemana() = fechaDeConsumo.dayOfweek()
  method diaDeSemanaEntre(dias) = dias.any{dia => dia == self.diaDeSemana()}
  method fechaEntre(inicio, fin) = fechaDeConsumo.between(inicio, fin)
}

class ConsumoDeInternet inherits Consumo {
  const megabytes
  
  method menosMegabytesQue(cantidad) = megabytes <= cantidad
  method esLlamada() = false
  method esInternet() = true
  method megabytes() = megabytes
  
  method costo() = consumo.costoInternet() * megabytes
}

class ConsumoDeLlamada inherits Consumo {
  const segundos
  
  method menosMegabytesQue(cantidad) = false
  method esLlamada() = true
  method esInternet() = false
  method megabytes() = 0

  method costo() = consumo.costoFijoLlamada().max(
    (consumo.costoVariableLlamada() * (segundos - 30)) + consumo.costoFijoLlamada()
  )
}

object consumo {
  var property costoFijoLlamada = 1
  var property costoVariableLlamada = 0.05
  var property costoInternet = 0.1
}