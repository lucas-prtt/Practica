class Reserva{
    const cliente 
    const empleado
    method disponiblePara(unaPersona) = cliente === unaPersona 
    method empleadoQueReservo(unEmpleado) = empleado === unEmpleado
}


object sinReserva{
    method disponiblePara(unaPersona) = true
    method empleadoQueReservo(unEmpleado) = false
}