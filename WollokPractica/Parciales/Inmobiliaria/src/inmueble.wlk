import zona.*
import reserva.*
class Inmueble{
    const zona
    var reserva = sinReserva
    method valorDeZona() = zona.valorExtra()
    method zona() = zona
    method valorIntrinsico()
    method valor() = self.valorIntrinsico() + self.valorDeZona()
    method disponiblePara(cliente) = reserva.disponiblePara(cliente)
    method fueReservadoPorEmpleado(empleado) = reserva.empleadoQueReservo(empleado)
    method reservar(empleado, cliente){
        reserva = new Reserva(cliente = cliente, empleado = empleado)
    }
    method anularReserva(){
        reserva = sinReserva
    }
}

class Casa inherits Inmueble{
    const valor 
    override method valorIntrinsico() = valor
}

class Ph inherits Inmueble{
    const area
    override method valorIntrinsico() = 500000.max(14000 * area) 
}

class Departamento inherits Inmueble{
    const ambientes
    override method valorIntrinsico() = 300000*ambientes

}

