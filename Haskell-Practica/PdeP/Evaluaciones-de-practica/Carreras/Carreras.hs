--11:10


data Auto = Auto{
    color :: Color,
    velocidad :: Int,
    distancia :: Int
} deriving (Show, Eq)

type Color = String

type Carrera = [Auto]

estaCerca :: Auto -> Auto -> Bool
estaCerca a1 = (<10) . abs . subtract (distancia a1) . distancia

vaTranquilo :: Auto -> Carrera -> Bool
vaTranquilo auto carrera = not $ any (estaCerca auto) carrera

gana :: Auto -> Auto -> Bool
gana a1 = (distancia a1 >) . distancia

puesto :: Auto -> Carrera -> Int
puesto auto = (1+) . length . filter ((/= color auto) . color) . filter (not . gana auto)

mario :: Auto
mario = Auto "Rojo" 30 14

carreraDeEjemplo :: [Auto]
carreraDeEjemplo = [Auto "Verde" 2 6, Auto "Azul" 205 3, Auto "Naranja" 1 1000, mario]

--12:30
--Punto 2 
modificarDistancia :: (Int -> Int) -> Auto -> Auto
modificarDistancia f auto = auto{distancia = f . distancia $ auto}
modificarVelocidad :: (Int -> Int) -> Auto -> Auto
modificarVelocidad f auto = auto{velocidad = f . velocidad $ auto}

correr :: Int -> Auto -> Auto
correr tiempo auto = modificarDistancia (+ tiempo * velocidad auto) auto

reducirVelocidad :: Int -> Auto -> Auto
reducirVelocidad reduccion auto 
    |velocidad auto > reduccion = modificarVelocidad (subtract reduccion) auto
    |otherwise = modificarVelocidad (const 0) auto

-- Punto 3 

afectarALosQueCumplen :: (a -> Bool) -> (a -> a) -> [a] -> [a]
afectarALosQueCumplen criterio efecto lista = (map efecto . filter criterio) lista ++ filter (not.criterio) lista

type PowerUp = Auto ->  Carrera -> Carrera

terremoto :: PowerUp
terremoto auto = afectarALosQueCumplen (estaCerca auto) (reducirVelocidad 50)

miguelitos :: Int -> PowerUp
miguelitos efectoMiguelito auto = afectarALosQueCumplen (gana auto) (reducirVelocidad efectoMiguelito)

jetPack :: Int -> PowerUp
jetPack tiempo auto = afectarALosQueCumplen (== auto) (modificarVelocidad (flip div 2) . correr tiempo . modificarVelocidad (*2))
--4a
type Evento = Carrera -> Carrera
type ListaDePosiciones = [(Int, Color)]

mostrarPosicionesCarrera :: Carrera -> ListaDePosiciones
mostrarPosicionesCarrera carrera = map (flip mostrarPosicionAuto carrera) carrera

mostrarPosicionAuto :: Auto -> Carrera -> (Int, Color)
mostrarPosicionAuto auto carrera = (puesto auto carrera, color auto)

simularCarrera :: Carrera -> [Evento] -> ListaDePosiciones
simularCarrera estadoInicial eventos = mostrarPosicionesCarrera $ foldl (flip ($)) estadoInicial eventos
--4b
correrTodos :: Int -> Evento
correrTodos tiempo = map (correr tiempo)

primerAutoConColor :: Color -> Carrera -> Auto
primerAutoConColor colorBuscado = head . filter ((==colorBuscado) . color) 

usaPowerUp :: Color -> PowerUp -> Evento
usaPowerUp colorDeAuto powerup carrera = powerup (primerAutoConColor colorDeAuto carrera) carrera

rojo :: Auto
rojo = Auto "Rojo" 120 0

negro :: Auto
negro = Auto "Negro" 120 0

blanco :: Auto
blanco = Auto "Blanco" 120 0

azul :: Auto
azul = Auto "Azul" 120 0

eventos :: [Evento]
eventos = [correrTodos 30, usaPowerUp "Azul" $ jetPack 3, usaPowerUp "Blanco" terremoto, correrTodos 40, usaPowerUp "Blanco" $ miguelitos 20, usaPowerUp "Negro" $ jetPack 6, correrTodos 10]

-- Seria posible, ya que se podía plantar el powerUp como "serImpactadoPorMisil", de modo que luego cuando se utilize la funcion de orden superior usaPowerUp, se la llame directamente al objetivo del misil
-- Tambien es posible, si se desea que el misil lo active algun auto en particular, que la funcion misilTeledirigido utilize la funcion afectarALosQueCumplen tomando de primer parametro ((== colorApuntado) . color)

-- La funcion vaTranquilo solo sería evaluable si dada una carrera de infinitos autos, algun auto va cerca, haciendo que la funcion devuelva False dado que deja de la funcion any deja de evaluar la lista infinita al encontrar un resultado falso, como comsecuencia de que haskell utiliza lazy evaluation
-- Si ningun auto de la lista infinita va cerca, la funcion seguirá evaluando autos hasta que la computadora se quede sin memoria

-- La funcion puesto nunca deja de evaluar, puesto que utiliza la funcion length sobre una lista filtrada y no es posible que la funcion length deje de evaluar los elementos de una lista antes de terminar.


