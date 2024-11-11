object empresa{
    const empleados = []
    const inmuebles = []
    method inmueblesReservadosPorEmpleado(empleado) = inmuebles.filter{inmueble => inmueble.fueReservadoPor(empleado)}    method contratar(empleado) = empleados.add(empleado)
    method agregarInmueble(unInmueble) {inmuebles.add(unInmueble)}
    method empleadoConMas(criterio) = empleados.max{empleado => criterio.magnitud(empleado)}
    
}

object comisiones{
    method magnitud(empleado) = empleado.comisionesTotales()
}

object operaciones{
    method magnitud(empleado) = empleado.operacionesTotales()
}

object reservas{
    method magnitud(empleado) = empresa.inmueblesReservadosPorEmpleado(empleado).size()
}