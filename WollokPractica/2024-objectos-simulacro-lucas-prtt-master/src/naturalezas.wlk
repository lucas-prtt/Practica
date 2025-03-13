
object estoica{
    method enriquecedor(_) = true
}
object moralista{
    method enriquecedor(argumento) = argumento.masDe10Palabras() 
}

object esceptica{
    method enriquecedor(argumento) = argumento.esPregunta()
}

object cinica{
    method enriquecedor(_) = 0.randomUpTo(1) <=0.3
}


