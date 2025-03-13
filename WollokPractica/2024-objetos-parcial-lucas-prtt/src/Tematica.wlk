import Panelista.*
import TipoPanelista.*


class Tematica{
    const titulo
    method palabrasTitulo() = titulo.words().size()
}
class TematicaFilosofica inherits Tematica{
    method interesante() = self.palabrasTitulo() > 20
    method valorOpinion(panelista) = 1
}

class TematicaFarandula inherits Tematica{
    const involucrados // Lista de objetos (panelistas / ¿personas?)
    method interesante() = involucrados.size() >= 3
    method valorOpinion(panelista) = 
    if (involucrados.contains(panelista)){
        return panelista.valorOpinionFarandula(involucrados.size())
    }else{
        return 1
    }
    
}

class TematicaDeportiva inherits Tematica{
    method interesante() = self.contienePalabraEnTitulo("Messi")
    method contienePalabraEnTitulo(unaPalabra) = titulo.words().contains(unaPalabra)
    method valorOpinion(panelista) = panelista.valorOpinionDeporte()
    
}


class TematicaMoral inherits Tematica{
    method interesante() = false
    method valorOpinion(panelista) = 1
}

class TematicaEconomica inherits Tematica{
    method interesante() = false
    method valorOpinion(panelista) = 1
}

class TematicaMixta inherits Tematica{
    const subtematicas // Lista de tematicas
    method interesante() = subtematicas.any{subtematica => subtematica.interesante()}
    method valorOpinion(panelista) = subtematicas.sum{subtematica => subtematica.valorOpinion(panelista)}
}


