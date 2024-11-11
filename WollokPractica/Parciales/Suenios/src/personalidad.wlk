object realista{
    method eleccion(persona) = persona.sueniosPendientes().max{unSuenio => unSuenio.felicidonios()}
    method siguientePersonalidad() = obsesivo
}

object alocado{
    method eleccion(persona) = persona.sueniosPendientes().anyOne()
    method siguientePersonalidad() = realista
}

object obsesivo{
    method eleccion(persona) = persona.sueniosPendientes().first()
    method siguientePersonalidad(){
        throw new Exception(message = "Un obsesivo np puede fluctuar su personalidad")
    }
}