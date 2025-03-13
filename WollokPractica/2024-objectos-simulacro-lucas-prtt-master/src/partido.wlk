class Partido{
    const filosofo
    const argumentos
    method partidoEnriquecedor() = filosofo.estaEnLoCorrecto() and self.argumentosEnriquecedores()
    method argumentosEnriquecedores() = argumentos.count{arg => arg.enriquecedor()} / argumentos.size() >= 0.5
}