object celebridad{
    method rematar(panelista, tematica){
        panelista.sumarEstrellas(3)
    }
    method valorOpinarDeDeporte() = 1
    method valorOpinarDeFarandula(gravedadFarandula) = gravedadFarandula
}

class Colorado{
    var gracia = 0
    method rematar(panelista, tematica){
        panelista.sumarEstrellas(self.estrellasASumar())
        gracia+=1
    }
    method estrellasASumar() = gracia/5
    method valorOpinarDeDeporte() = 1
    method valorOpinarDeFarandula(gravedadDeFarandula) = 1
}

class ColoradoPeluca inherits Colorado{
    override method estrellasASumar() = super() + 1
}

object viejo{
    method rematar(panelista, tematica){
        panelista.sumarEstrellas(tematica.palabrasTitulo())
    }
    method valorOpinarDeDeporte() = 1
    method valorOpinarDeFarandula(gravedadDeFarandula) = 1
}

object deportivo{
    method rematar(panelista, tematica){}
    method valorOpinarDeDeporte() = 5
    method valorOpinarDeFarandula(gravedadDeFarandula) = 1
}



