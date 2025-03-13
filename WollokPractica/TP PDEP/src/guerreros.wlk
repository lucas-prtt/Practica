class Guerrero {
  var vida
  const armas = []
  const items = []

  method agarrarArma(arma) {
    armas.add(arma)
  }

  method agarrarObjeto(unObjeto) {
    items.add(unObjeto)
  }
  
  method desecharObjeto(unObjeto) {
    items.remove(unObjeto)
  }
  
  method tieneDeVidaAlMenos(unaVida) = vida >= unaVida
  
  method cantidadDeItems() = items.size()
  
  method cuantoDeCiertoItem(item) = items.occurrencesOf(item)
  
  method vida() = vida
  
  method tieneAlgunArma() = self.cantidadDeArmas() > 0
  
  method cantidadDeArmas() = armas.size()

  method poderDeArmas() = armas.sum({arma => arma.poder()})
  
  method sumarVida(cuantaVida) {
    vida += cuantaVida
  }
  
  method restarVida(cuantaVida) {
    vida -= cuantaVida
  }

  method multiplicarVida(factorVida){
    vida *= factorVida
  }
  
  method fueraDeCombate() = vida <= 0 

  method puedeRecorrerZona(zona) = zona.recorriblePorGuerrero(self)
  
  method recorrerZona(zona) {
    zona.recorrerPorGuerrero(self)
  }
  
  method recorrerCamino(camino) {
    camino.recorrerPorGuerrero(self)
  }
  
  method puedeRecorrerCamino(camino) {
    return camino.recorriblePorGuerrero(self)
  }
  
  method duplicar()
  
}

class Hobbit inherits Guerrero {
  method poder() = vida + self.poderDeArmas() + self.cantidadDeItems()
  
  override method duplicar() = new Hobbit(
    vida = vida,
    armas = armas,
    items = items
  )
}

class Enano inherits Guerrero {
  const factorDePoder
  
  method poder() = vida + self.poderDeArmas() * factorDePoder
  
  override method duplicar() = new Enano(
    vida = vida,
    armas = armas,
    items = items,
    factorDePoder = factorDePoder
  )
}


class Elfo inherits Guerrero {
  const destreza
  
  method poder() = vida + self.poderDeArmas() * (destreza + elfo.valor())
  
  override method duplicar() = new Elfo(
    vida = vida,
    armas = armas,
    items = items,
    destreza = destreza
  )
}
object elfo {
  var property valor = 2
}

class Humano inherits Guerrero {
  const limitadorDePoder
  
  method poder() = vida * self.poderDeArmas() / limitadorDePoder
  
  override method duplicar() = new Humano(
    vida = vida,
    armas = armas,
    items = items,
    limitadorDePoder = limitadorDePoder
  )
}

object maiar {
  var property factorPoder = 15
  var property factorAmenazado = 300
}

class Maiar inherits Guerrero {

  method sumatoriaPoderArmas() = self.poderDeArmas() * 2 
  
  method poder() {
    if (vida >= 10) {
      return vida * maiar.factorPoder() + self.sumatoriaPoderArmas()
    } else {
      return vida * maiar.factorAmenazado() + self.sumatoriaPoderArmas()
    }
  }
  
  override method duplicar() = new Maiar(
    vida = vida,
    armas = armas,
    items = items
  )
}

class TomBombadil inherits Guerrero {
  method poder() = 10000000
  
  override method duplicar() = new TomBombadil(
    vida = vida,
    armas = armas,
    items = items
  )
  
  override method puedeRecorrerZona(_) = true
  override method puedeRecorrerCamino(_) = true
  override method recorrerCamino(_) {}
  override method recorrerZona(_) {}
}

class Gollum inherits Hobbit {
  override method poder() = super() / 2
  
  override method duplicar() = new Gollum(
    vida = vida,
    armas = armas,
    items = items
  )
}