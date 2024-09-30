object pepita{
    var energia = 1000
    var ubicacion = buenosAires
    method volar(kilometros){
        energia -= self.costoEnergetico(kilometros)
    }
    method comer(gramos){
        energia = energia + gramos * 4
    }
    method ubicacion(){
        return ubicacion
    }
    method ir(lugar){
        self.volar(lugar.distancia(ubicacion))        
        ubicacion = lugar
    }
    method puedoIr(lugar){
        const costo = self.costoEnergetico(lugar.distancia(ubicacion))
        return costo<=energia
    }
    method costoEnergetico(kilometros){
        return 10 + kilometros
    }
}


object buenosAires{
    const kilometro = 0
    method distancia(lugar){
        const distancia = kilometro - lugar.kilometro()
        return distancia.abs()
    }
    method kilometro(){
        return kilometro
    }
}
object santaFe{
    const kilometro = 500
    method distancia(lugar){
        const distancia = kilometro - lugar.kilometro()
        return distancia.abs()
    }
    method kilometro(){
        return kilometro
    }
}
object cordoba{
    const kilometro = 1000
    method distancia(lugar){
        const distancia = kilometro - lugar.kilometro()
        return distancia.abs()
    }
    method kilometro(){
        return kilometro
    }
}
object tucuman{
    const kilometro = 2000
    method distancia(lugar){
        const distancia = kilometro - lugar.kilometro()
        return distancia.abs()
    }
    method kilometro(){
        return kilometro
    }
}


