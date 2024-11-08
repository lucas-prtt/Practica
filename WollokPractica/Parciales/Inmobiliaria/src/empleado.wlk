import empresa.*

class Empleado{
    const operaciones = []
    method comisionesTotales() = operaciones.sum{op => op.comision()}
    method operacionesTotales() = operaciones.size()
    method realizarOperacion(operacion, cliente) { 
        if (operacion.disponiblePara(cliente)){
            throw new Exception(message = "Propiedad reservada, no se pudo concretar la operacion")
        }
        operaciones.add(operacion)
    }
    method reservarACliente(cliente, inmueble){
        inmueble.reservar(self, cliente)
    }

    method inmueblesReservados() = empresa.inmueblesReservadosPorEmpleado(self)
    method inmueblesOperados() = operaciones.map{op => op.propiedad()}
    method zonasOperadas() = self.inmueblesOperados().map{inm => inm.zona()}.withoutDuplicates()
    method vaATenerProblemasCon(otroEmpleado){
        const inmueblesReservados = self.inmueblesReservados()
        
    }

    method compitenPorZona(otroEmpleado) = self.zonasOperadas().any{zona => otroEmpleado.zonasOperadas().contains(zona)}
}
