class Espada {
  const origen
  const multiplicador
  
  method initialize(){
    if (multiplicador < 1)
      throw new DomainException(message = "no puede tener un multiplicador de espada menor a 1")
    if (multiplicador > 20) 
      throw new DomainException(message = "no puede tener un multiplicador de espada mayor a 20")
    }

  method poder() = multiplicador * origen.poder()

}

class Origen {
  const poder // const property poder
  
  method poder() = poder
}

// Origenes
const elfico = new Origen(poder = 25)

const enano = new Origen(poder = 20)

const humano = new Origen(poder = 15)


class Baculo {
  const poder // const property poder
  method poder() = poder
}

class Daga inherits Espada {
  override method poder() = super() / 2
}

class Arco {
  
  const longitud
  var tension = 40
  
  method tension(tensionEnKg) {
    tension = tensionEnKg
  }
  
  method poder() = 0.1 * longitud * tension
}

class Hacha {

  const largoMango
  const pesoHoja
  
  method poder() = largoMango * pesoHoja
}