class Suenio{
    const felicidonios
    method felicidonios() = felicidonios
}

class RecibirseDeCarrera inherits Suenio{
    method puedeCumplir(persona) = persona.leInteresaEstudiar(self) and persona.yaEstudio(self).not()
    method cumplir(persona) {persona.recibirseDe(self)}
}
class TenerHijo inherits Suenio{
    method puedeCumplir(persona) = true
    method cumplir(persona) {persona.tenerHijo()}
}

class AdoptarHijos inherits Suenio{
    const cuantos
    method puedeCumplir(persona) = persona.cuantosHijos() <= 0
    method cumplr(persona) {cuantos.times{=> persona.tenerHijo()}}
}

class Viajar inherits Suenio{
    method puedeCumplir(persona) = true
    method cumplir(persona) {}
}

class ConseguirTrabajo inherits  Suenio{
    const sueldo
    method puedeCumplir(persona) = persona.aceptaSueldo(sueldo)
    method cumplirSuenio(){}
}

class SuenioMultiple inherits Suenio{
    const suenios
    method puedeCumplir(persona)  = suenios.all{unSuenio => unSuenio.puedeCumplir(persona)}
    method cumplir(persona) {suenios.forEach{unSuenio => unSuenio.cumplir()}
    }
}


