
object estandar{
    method adeudar(_linea, _consumo){
        throw new Exception(message = "No puede realizar este consumo")
    }
}

object black{
    method adeudar(linea, consumo){
        linea.adeudar(consumo.costo())
    }
}

object platinum{
    method adeudar(_linea, _consumo){}
}

