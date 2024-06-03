import Data.List (genericLength)

data Turista = Turista{
    cansancioDeTurista :: Int,
    estresDeTurista :: Int,
    turistaAcompañado :: Bool,
    idiomasDeTurista :: [Idioma]
} deriving (Eq, Show)

type Idioma = String


irALaPlaya :: Turista -> Turista
irALaPlaya turista
    | not . turistaAcompañado $ turista = modificarCansancio (subtract 5) turista
    | otherwise        = modificarEstres (subtract 1) turista

modificarCansancio :: (Int->Int) -> Turista -> Turista
modificarCansancio operacion turista = turista{cansancioDeTurista = operacion . cansancioDeTurista $ turista}

modificarEstres :: (Int->Int) -> Turista -> Turista
modificarEstres operacion turista = turista{estresDeTurista = operacion . estresDeTurista $ turista}

modificarAcompañamiento :: Bool -> Turista -> Turista
modificarAcompañamiento acompañado turista = turista{turistaAcompañado = acompañado}

agregarIdioma :: Idioma -> Turista -> Turista
agregarIdioma idioma turista = turista{idiomasDeTurista = (idioma :) . idiomasDeTurista $ turista}

apreciar :: String -> Turista -> Turista
apreciar elemento = modificarEstres (subtract . genericLength $ elemento)

hablarIdioma :: Idioma -> Turista -> Turista
hablarIdioma idioma = agregarIdioma idioma . modificarAcompañamiento True

caminar :: Int -> Turista -> Turista
caminar minutos = modificarCansancio (+ intensidad) . modificarEstres (subtract intensidad)
    where intensidad = div minutos 4

data Marea = Fuerte | Moderada | Tranquila

paseoEnBarco :: Marea -> Turista -> Turista
paseoEnBarco Fuerte = modificarCansancio (+10) . modificarEstres (+6)
paseoEnBarco Moderada = id
paseoEnBarco Tranquila = caminar 10 . apreciar "mar" . hablarIdioma "Aleman"

ana :: Turista
ana = Turista 0 21 True ["Español"]
beto :: Turista
beto = Turista 15 15 False ["Aleman"]
cathi :: Turista
cathi = agregarIdioma "Catalan" beto

modificarEstresPorcentaje :: Int -> Turista -> Turista
modificarEstresPorcentaje porcentaje turista = modificarEstres (subtract . flip div 100 . (* (porcentaje + 100) ). estresDeTurista $ turista) turista


hacerExcursion :: (Turista -> Turista) -> Turista -> Turista
hacerExcursion actividad = modificarEstresPorcentaje (-10) . actividad

type Indice = Turista -> Int

deltaSegun :: (a -> Int) -> a -> a -> Int
deltaSegun f algo1 algo2 = f algo1 - f algo2

type Excursion = Turista -> Turista

deltaExcursionSegun :: Indice -> Turista -> Excursion -> Int
deltaExcursionSegun indice turista excursion = deltaSegun indice turista (excursion turista)


esEducativa :: Turista -> Excursion -> Bool
esEducativa turista = (>0) . deltaExcursionSegun cuantosIdiomas turista

cuantosIdiomas :: Turista -> Int
cuantosIdiomas = genericLength . idiomasDeTurista

esDesestresante :: Turista -> Excursion -> Bool
esDesestresante turista = (<0) . deltaExcursionSegun estresDeTurista turista

type Tour = [Excursion]

completo :: Tour
completo = [caminar 20, apreciar "cascada", caminar 40, irALaPlaya, hablarIdioma "melmacquiano"]

ladoB :: Excursion -> Tour
ladoB excursion = [paseoEnBarco Tranquila, excursion, caminar 120]

islaVecina :: Marea -> Tour
islaVecina Fuerte = viajarHacerYVolver Fuerte $ apreciar "algo"
islaVecina marea = viajarHacerYVolver marea irALaPlaya

viajarHacerYVolver :: Marea -> Excursion -> Tour 
viajarHacerYVolver marea excursion = [paseoEnBarco marea, excursion, paseoEnBarco marea]

realizarTour :: Tour -> Turista -> Turista
realizarTour tour = pasarPorExcursiones tour . modificarEstresPorcentaje 10 

pasarPorExcursiones :: Tour -> Turista -> Turista
pasarPorExcursiones = flip (foldl (flip hacerExcursion))

esExcursionConvincente :: Excursion -> Turista -> Bool
esExcursionConvincente excursion turista =  (&& esDesestresante turista excursion) . turistaAcompañado . hacerExcursion excursion $ turista

esTourConvincente :: Turista -> Tour -> Bool
esTourConvincente turista = any (flip esExcursionConvincente turista)

algunTourConvincente :: Turista -> [Tour] -> Bool
algunTourConvincente turista = any (esTourConvincente turista)

cansancioMasEstres :: Turista -> Int
cansancioMasEstres turista = cansancioDeTurista turista + estresDeTurista turista

espiritualidad :: Tour -> Turista -> Int
espiritualidad tour turista = deltaSegun cansancioMasEstres turista (realizarTour tour turista)

efectividad :: Tour -> [Turista] -> Int
efectividad tour = sum . map (espiritualidad tour) . filter (flip esTourConvincente tour)



