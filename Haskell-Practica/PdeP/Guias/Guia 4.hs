sumarLista :: Num x => [x]->x
sumarLista x 
    |null x = 0 
    |otherwise = head x + (sumarLista . tail) x 

contarLista ::[x]->Integer
contarLista x 
    |null x = 0 
    |otherwise = 1 + (contarLista . tail) x 


ejemploFrecuencias = [80, 100, 120, 128, 130, 123, 125]

promedioIntegers ::Fractional x => [Integer]->x
promedioIntegers x = ((flip (/) (fromInteger . toInteger . length $ x)) .fromInteger . toInteger . sumarLista) x

promedioFrecuenciaCardiaca :: Fractional x => x
promedioFrecuenciaCardiaca = promedioIntegers ejemploFrecuencias

indiceLista::Integer->[Integer]->Integer
indiceLista num lista = (toInteger . length) lista - indiceaux num lista 

indiceaux :: Integer -> [Integer]->Integer
indiceaux num lista = 
        if null lista then -1
        else if head lista == num then toInteger . length $ lista
        else (indiceaux num) . tail $ lista

otroIndice:: Integer -> [Integer] -> Integer
otroIndice num lista = otroIndiceAux num lista 0

otroIndiceAux:: Integer -> [Integer] -> Integer -> Integer 
otroIndiceAux num lista indice=
    if null lista then -1
    else if (num ==) . head $ lista then indice
    else  otroIndiceAux num (tail lista) (indice+1)

frecuenciaCardiacaMinuto :: Int -> Integer 
frecuenciaCardiacaMinuto x = ejemploFrecuencias !! (div x 10)

tiempos = [0, 10, 20, 30, 40, 50, 60]

altFrecuenciaCardiacaMinuto :: Integer -> Integer
altFrecuenciaCardiacaMinuto x = (!!) ejemploFrecuencias . fromInteger . flip otroIndice tiempos $ x
-- La funcion !! SOLO toma Int, no Integer

concatenar :: [[x]]->[x]
concatenar x =
    if null x then []
    else head x ++ (concatenar . tail) x

reversa :: [x] -> [x]
reversa palabra = 
    if null palabra then []
    else [last palabra] ++ (reversa . init) palabra

esCapicua :: [[Char]] -> Bool
esCapicua cadenas = concatenar cadenas == (reversa.concatenar) cadenas

neuquen = ["ne", "uqu", "en"]

duracionLlamadas = (("horarioReducido", [20, 10, 25, 15]), ("horarioNormal",[10, 5, 8, 2, 9, 10]))


cuandoHabloMasMinutos = flip compararSobreLlamadas sumarLista duracionLlamadas
cuandoHizoMasLlamadas = flip compararSobreLlamadas contarLista duracionLlamadas

compararSobreLlamadas :: Integral x => ((String, [x]),(String, [x])) -> ([x] -> x) -> String
compararSobreLlamadas ((hRed, dataRed),(hNor, dataNor)) funcion
    |masEnHorarioReducido = hRed
    |masEnHorarioNormal = hNor
    |otherwise = "Igual"
    where
        masEnHorarioNormal = horasreducidas < horasnormales
        masEnHorarioReducido = horasreducidas > horasnormales
        horasnormales = funcion dataNor
        horasreducidas = funcion dataRed

existsAny :: (x->Bool) -> (x, x, x) -> Bool
existsAny fn (el1, el2, el3) = fn el1 || fn el2 || fn el3

mejor :: (Num n, Ord n)=> (x->n) -> (x->n) -> x -> n
mejor f1 f2 val
    |f1 val > f2 val = f1 val
    |otherwise = f2 val

aplicarPar :: (x->y) -> (x, x) -> (y, y)
aplicarPar f (x, y) = (f x, f y)

parDeFns :: (x->y) -> (x->z) -> x -> (y, z)
parDeFns f1 f2 val = (f1 val, f2 val)

esMultiplo :: Integral x => x -> x -> Bool
esMultiplo x y = (==0) . (mod x) $ y

esMultiploDeAlguno :: (Integral x) => x -> [x] -> Bool
esMultiploDeAlguno num lista= any (esMultiplo num) lista

promedios :: Fractional x => [[x]] -> [x]
promedios listaDeListas = map (promedio) listaDeListas

promedio :: (Fractional x) => [x] -> x
promedio lista = (flip (/) . fromInteger . contarLista $ lista) (sumarLista lista)

promediosSinAplazos :: (Fractional x, Ord x) => [[x]] -> [x]
promediosSinAplazos listaDeListas = promedios . map (filter (>=4)) $ listaDeListas  

mejoresNotas :: (Fractional x, Ord x) => [[x]] -> [x]
mejoresNotas todasLasNotas = map maximum todasLasNotas
{- 
mejoresNotas todasLasNotas = map mejornota todasLasNotas 
    where 
        mejornota :: (Fractional x, Ord x) =>  [x] -> x
        mejornota notas
            | contarLista notas == 1 = head notas
            | otherwise = max (head notas) (mejornota (tail notas)) 
-}

aprobo :: (Num x, Ord x) => [x] -> Bool
aprobo notas = not (minimum notas < 6)










