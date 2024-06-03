import Data.List (genericLength)

data Turista = Turista{
    cansancioDeTurista :: Integer,
    estresDeTurista :: Integer,
    turistaAcompañado :: Bool,
    idiomasDeTurista :: [Idioma]
} deriving (Eq, Show)

type Idioma = String


irALaPlaya :: Turista -> Turista
irALaPlaya turista
    | not . turistaAcompañado $ turista = modificarCansancio (subtract 5) turista
    | otherwise        = modificarEstres (subtract 1) turista

modificarCansancio :: (Integer->Integer) -> Turista -> Turista
modificarCansancio operacion turista = turista{cansancioDeTurista = operacion . cansancioDeTurista $ turista} 

modificarEstres :: (Integer->Integer) -> Turista -> Turista
modificarEstres operacion turista = turista{estresDeTurista = operacion . estresDeTurista $ turista} 

modificarAcompañamiento :: Bool -> Turista -> Turista
modificarAcompañamiento acompañado turista = turista{turistaAcompañado = acompañado} 

agregarIdioma :: Idioma -> Turista -> Turista
agregarIdioma idioma turista = turista{idiomasDeTurista = (idioma :) . idiomasDeTurista $ turista}

apreciar :: String -> Turista -> Turista
apreciar elemento = modificarEstres (subtract . genericLength $ elemento)

hablarIdioma :: Idioma -> Turista -> Turista
hablarIdioma idioma = agregarIdioma idioma . modificarAcompañamiento True

caminar :: Integer -> Turista -> Turista
caminar minutos = modificarCansancio (+ intensidad) . modificarEstres (subtract intensidad)
    where intensidad = div minutos 4

data Marea = Fuerte | Moderada | Tranquila

paseoEnBarco :: Marea -> Turista -> Turista
paseoEnBarco Fuerte = modificarCansancio (+10) . modificarEstres (+6)
paseoEnBarco Moderada = id
paseoEnBarco Tranquila = caminar 10 . apreciar "mar" . hablarIdioma "Aleman"







