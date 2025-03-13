import TipoPanelista.*
class Panelista{
    var estrellas = 0
    const tipoPanelista 
    method estrellas() = estrellas
    method darRemateGracioso(tematica){
        tipoPanelista.rematar(self, tematica)
    }
    method sumarEstrellas(cuantas){
        estrellas += cuantas
    }
    method opinarTematica(tematica){
        self.sumarEstrellas(tematica.valorOpinion(self))
    }
    method valorOpinionDeporte() = tipoPanelista.valorOpinarDeDeporte()
    method valorOpinionFarandula(gravedadFarandula) = tipoPanelista.valorOpinarDeFarandula(gravedadFarandula)

}

