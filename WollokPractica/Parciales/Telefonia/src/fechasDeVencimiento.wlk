class FechaDeVencimiento{
    const fecha
    method vencido() = fecha <= new Date()
}

object noVence{
    method vencido() = false
}