import Text.Show.Functions
import Data.List

-- Funciones que tal vez te pueden servir, tal vez no

-- Main*> :t takeWhile
-- takeWhile :: (a -> Bool) -> [a] -> [a]
-- Main*> takeWhile even [2,4,6,5,6,7,8,9]
-- [2,4,6]

-- Main*> :t genericLength
-- genericLength :: Num i => [a] -> i
-- Main*> genericLength [2,4,6,5,6,7,8,9]
-- 8






--      Punto 1

data Guerrero = Guerrero {
    nombreGuerrero :: String,
    ki :: Float,
    raza :: Raza,
    cansancio :: Float,
    personalidad :: Personalidad
} deriving (Show, Eq)

data Raza = Humano | Namekiano | Saiyajin deriving (Show, Eq)

gohan :: Guerrero
gohan = Guerrero "Gohan" 10000 Saiyajin 0 Perezozo






--      Punto 2

type Ejercicio = Actividad 
-- Generalizo el concepto de actividad para no considerar luego el descanso como un ejercicio
type Actividad = Guerrero -> Guerrero

esPoderoso :: Guerrero -> Bool
esPoderoso guerrero = ((>8000) . ki) guerrero || (( == Saiyajin ) . raza ) guerrero

modificarKi :: (Float -> Float) -> Guerrero -> Guerrero
modificarKi funcion guerrero = guerrero {ki = funcion . ki $ guerrero}

modificarCansancio :: (Float -> Float) -> Guerrero -> Guerrero
modificarCansancio funcion guerrero = guerrero {cansancio = funcion . cansancio $ guerrero}

hacerEjercicio :: (Float -> Float) -> (Float -> Float) -> Ejercicio
hacerEjercicio efectoCansancio efectoKi = modificarKi efectoKi . modificarCansancio efectoCansancio


pressDeBanca :: Ejercicio
pressDeBanca = hacerEjercicio (+100) (+90)

hacerCalistemia :: Ejercicio
hacerCalistemia = hacerEjercicio (+50) id

saltosACajon :: Float -> Ejercicio
saltosACajon centimetros = hacerEjercicio (+ centimetros / 5) (+ centimetros / 10)

snatch :: Ejercicio
snatch guerrero
    |esExperimentado guerrero = hacerEjercicio (aumentarPorcentajeFloat 10) (aumentarPorcentajeFloat 5) guerrero
    |otherwise = hacerEjercicio (+50) id guerrero



esExperimentado :: Guerrero -> Bool
esExperimentado = (>22000) . ki

aumentarPorcentajeFloat :: Float -> Float -> Float
aumentarPorcentajeFloat porcentaje = (*(1+porcentaje/100))

--segunda hoja

estaCansado :: Guerrero -> Bool
estaCansado = cansancioMayorAPorcentajeDeKi 44

estaExhausto :: Guerrero -> Bool
estaExhausto = cansancioMayorAPorcentajeDeKi 72

cansancioMayorAPorcentajeDeKi :: Float -> Guerrero -> Bool
cansancioMayorAPorcentajeDeKi porcentaje guerrero = (porcentajeDeFloat porcentaje . ki) guerrero < cansancio guerrero

porcentajeDeFloat :: Float -> Float -> Float
porcentajeDeFloat porcentaje = (/100) . (*porcentaje)






--     Punto 3 
realizarEjercicio :: Guerrero -> Ejercicio -> Guerrero
realizarEjercicio guerrero ejercicio
    |estaExhausto guerrero = modificarKi (*0.98) guerrero 
    |estaCansado guerrero = (duplicarEfectoKi guerrero . cuadruplicarEfectoCansancio guerrero $ ejercicio) guerrero
    |otherwise = ejercicio guerrero

duplicarEfectoKi :: Guerrero -> Ejercicio -> Ejercicio
duplicarEfectoKi guerrero ejercicio = modificarKi (+cuantoCriterioModificadoConEjercicio ki guerrero ejercicio) . ejercicio

type Criterio = (Guerrero -> Float)

cuantoCriterioModificadoConEjercicio :: Criterio -> Guerrero -> Ejercicio -> Float -- Devuelve la cantidad de un criterio que se modifico con el ejercicio
cuantoCriterioModificadoConEjercicio criterio guerrero ejercicio = criterio (ejercicio guerrero) - criterio guerrero

cuadruplicarEfectoCansancio :: Guerrero -> Ejercicio -> Ejercicio
cuadruplicarEfectoCansancio guerrero ejercicio= modificarCansancio (+ 3 * cuantoCriterioModificadoConEjercicio cansancio guerrero ejercicio) . ejercicio





--     Punto 4
data Personalidad = Sacado | Perezozo | Tramposo deriving (Eq, Show)


type Descanso = Actividad
type Rutina = [Actividad]

armarUnaRutina :: Guerrero -> Rutina -> Rutina
armarUnaRutina guerrero rutina
    | personalidad guerrero == Sacado       = filter (actividadDescansa guerrero) rutina
    | personalidad guerrero == Perezozo     = intersperse (descansar 5) rutina
    | personalidad guerrero == Tramposo     = filter (actividadEjercita guerrero) rutina

actividadDescansa :: Guerrero -> Actividad -> Bool
actividadDescansa guerrero act = (cansancio . act) guerrero < cansancio guerrero

actividadEjercita :: Guerrero -> Actividad -> Bool
actividadEjercita guerrero= not . actividadDescansa guerrero

--Si se quisiera hacer una rutina con ejercicios infinitos, no se podría determinar la rutina, puesto que las funciones filter y intersperse no paran de evaluar una lista hasta que esta se termine, por lo tanto la lazy evaluation de haskell no es suficiente para que se pueda determinar la rutina



--      Punto 5
hacerRutina :: Rutina -> Guerrero -> Guerrero 
hacerRutina rutina guerrero = foldl (flip ($)) guerrero rutina
-- Se supone que la rutina ya tiene incorporado la funcion RealizarEjercicio en la lista

-- Si utilizara la funcion de realizarEjercicio en vez de fold $, se aplicaria no solo a los ejercicios sino tambien a los descansos





--    Punto 6
descansar :: Float -> Descanso
descansar minutos = modificarCansancio (subtract $ sumatoriaDe1AN minutos)

sumatoriaDe1AN :: Float -> Float
sumatoriaDe1AN n = sum [1..n]





--    Punto 7 
descansoOptimo :: Guerrero -> Float
descansoOptimo guerrero = cuentaDeDescansoOptimo (cansancio guerrero)

cuentaDeDescansoOptimo :: Float -> Float --La separo en otra funcion para poder probarla mas facilmente
cuentaDeDescansoOptimo n = genericLength $ takeWhile (<n) (map sumatoriaDe1AN [0..])



