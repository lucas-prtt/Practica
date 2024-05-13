-- En base a la fotocopia de tarea del 24/4/2024

{--}
data Sustancia = Sustancia{
    tipoDeSustancia :: TipoDeSustancia,
    grupoDeSustancia :: GrupoDeSustancia
}deriving (Eq, Show)

data TipoDeSustancia = Elemento {
    nombreElemento :: String,
    simboloQuimico :: String,
    numeroAtomico :: Integer
} | Compuesto{
    nombreCompuesto :: String,
    componente :: [(Sustancia, Integer)]
} deriving (Eq, Show)

data GrupoDeSustancia = Metal | NoMetal | Halogeno | GasNoble deriving (Eq, Show) 

data Conductividad = Termica | Electrica deriving (Eq, Show)



hidrogeno = Sustancia (Elemento "Hidrogeno" "H" 1 ) NoMetal 
oxigeno = Sustancia (Elemento "Oxigeno" "O" 8 ) NoMetal
agua = Sustancia (Compuesto "Agua" [(hidrogeno, 2),(oxigeno, 1)]) NoMetal 
--Para probar ↓
hierro = Sustancia (Elemento "Hierro" "Fe" 26) Metal
fluor = Sustancia (Elemento "Fluor" "F" 9) NoMetal
elementorarito = Sustancia (Elemento "Terminoenunnumero7" "?" (-1)) NoMetal
cloro = Sustancia (Elemento "Cloro" "Cl" 17) NoMetal
sodio = Sustancia (Elemento "Sodio" "Na" 11) Metal

conduce :: Sustancia -> Conductividad -> Bool
conduce sust tipo
    |tipo == Termica = conductividadTermicaBuena sust
    |tipo == Electrica = conductividadElectricaBuena sust

conductividadTermicaBuena :: Sustancia -> Bool
conductividadTermicaBuena sust 
    |sugrupo == Metal = True
    |sugrupo == Halogeno = True
    |otherwise = False
    where sugrupo = grupoDeSustancia sust 
conductividadElectricaBuena :: Sustancia -> Bool
conductividadElectricaBuena sust 
    |sugrupo == Metal = True
    |sugrupo == GasNoble = True
    |otherwise = False
    where sugrupo = grupoDeSustancia sust 



esVocal :: Char -> Bool
esVocal letra = elem letra "aeiouAEIOU"

sacarTodasLasUltimasVocales :: String -> String
sacarTodasLasUltimasVocales texto
    | (esVocal . last) texto = (sacarTodasLasUltimasVocales . init) texto
    | otherwise = texto

terminaEnAlgunaDeEstas :: String -> [Char] -> Bool
terminaEnAlgunaDeEstas palabra ultimasLetras = elem (last palabra) ultimasLetras

nombreDeUnion :: Sustancia -> String
nombreDeUnion sust 
    |casoConsonante = elnombre ++ "uro"
    |casoVocal = sacarTodasLasUltimasVocales elnombre ++ "uro"
    |otherwise = "Error: nombre raro no termina en una letra"
    where 
    casoConsonante = terminaEnAlgunaDeEstas elnombre "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
    casoVocal = terminaEnAlgunaDeEstas elnombre "aeiouAEIOU"
    elnombre = nombreDeLoQueSea sust

nombreDeElemento :: Sustancia -> String
nombreDeElemento sust = nombreElemento . tipoDeSustancia $ sust

simboloDeElemento :: Sustancia -> String
simboloDeElemento sust = simboloQuimico . tipoDeSustancia $ sust

nombreDeCompuesto :: Sustancia -> String
nombreDeCompuesto sust = nombreCompuesto . tipoDeSustancia $ sust

{- ESTO NO FUNCIONA
esElemento :: Sustancia -> Bool
esElemento sust = tipoDeSustancia sust == Elemento{} 
Tira Error al ejecutar la funcion -}

esTipoDeSustanciaElemento (Elemento _ _ _) = True
esTipoDeSustanciaElemento (Compuesto _ _) = False
esElemento :: Sustancia->Bool
esElemento sust = esTipoDeSustanciaElemento (tipoDeSustancia sust)


nombreDeLoQueSea :: Sustancia -> String
nombreDeLoQueSea sust 
    |esElemento sust= nombreDeElemento sust
    |otherwise = nombreDeCompuesto sust

combinar :: Sustancia -> Sustancia -> String
combinar sust1 sust2 = (nombreDeUnion sust1) ++ " de " ++ (nombreDeElemento sust2)

nombreDeMezcla :: [Sustancia] -> String
nombreDeMezcla cosasQueSeMezclan
    |elementosRestantes == 0 = ""
    |elementosRestantes == 1 =  nombreDeLoQueSea (head cosasQueSeMezclan)
    |elementosRestantes >1 = nombreDeUnion (head cosasQueSeMezclan) ++ " de " ++ nombreDeMezcla (tail cosasQueSeMezclan)
    |otherwise = "Error en funcion nombreDeMezcla"
    where elementosRestantes = length cosasQueSeMezclan 


mezclar :: [Sustancia] -> Sustancia
mezclar cosasQueSeMezclan = Sustancia (Compuesto (nombreDeMezcla cosasQueSeMezclan) (countYGroupByComponentes cosasQueSeMezclan)) NoMetal

countYGroupByComponentes :: [Sustancia] -> [(Sustancia, Integer)]
countYGroupByComponentes susts
    |null susts = []
    |otherwise = [(head susts, contar (head susts) susts)] ++ countYGroupByComponentes (sacarOcurrenciasDelPrimero susts)

sacarOcurrenciasDelPrimero :: Eq x => [x] -> [x]
sacarOcurrenciasDelPrimero lista = filter (\x -> x/=(head lista)) lista

contar :: Eq x => x -> [x] -> Integer
contar elemento lista
    | null lista = 0
    | elemento == head lista = 1 + contar elemento (tail lista)
    | otherwise = contar elemento (tail lista)

formula :: Sustancia -> String
formula sust 
    | esElemento sust = simboloDeElemento sust
    | otherwise = "(" ++ concatenar( listaDeComponentes (componente (tipoDeSustancia sust))) ++ ")"


simboloYCantidad :: (Sustancia, Integer) -> String
simboloYCantidad (sust, cant)
    | esElemento sust = simboloDeElemento sust ++ omitirSiEsUnoSolo cant
    | otherwise = formula sust ++ omitirSiEsUnoSolo cant

listaDeComponentes :: [(Sustancia, Integer)] -> [String]
listaDeComponentes lista = map simboloYCantidad lista 

omitirSiEsUnoSolo :: Integer -> String
omitirSiEsUnoSolo num
    |num == 1 = ""
    |otherwise = show num

concatenar :: [[x]]->[x]
concatenar x
    | null x = []
    | otherwise = head x ++ (concatenar . tail) x


