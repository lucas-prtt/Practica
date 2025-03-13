class Emision{
    const tematicas
    const panelistas
    var emitido = false // Para definir si se emitio al menos una vez
    method puedeEmitir() = panelistas.size() >= 2 and self.mitadDeTematicasInteresantes()
    method mitadDeTematicasInteresantes() = (tematicas.count{tematica => tematica.interesante()}) >= (tematicas.size()/2)
    method emitir(){
        self.verificarEmision()
        tematicas.forEach{tematica => 
            panelistas.forEach{
                panelista => 
                panelista.opinarTematica(tematica)
                panelista.darRemateGracioso(tematica)
            }
        }
        emitido = true
    }

    method panelistaEstrella() {
        self.verificarEmisionPrevia()
        return panelistas.max{ panelista => panelista.estrellas()}
    }
    method verificarEmision(){
        if (!self.puedeEmitir()){
            throw new Exception(message = "No se puede emitir")
        }
    }
    method verificarEmisionPrevia(){
        if (!emitido){throw new Exception(message = "Aun no se emitio nunca")}
    }
}