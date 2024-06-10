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

type Evento = Carrera -> Carrera
type ListaDePosiciones = [(Int, Color)]

mostrarPosicionesCarrera :: Carrera -> ListaDePosiciones
mostrarPosicionesCarrera carrera = map (flip mostrarPosicionAuto carrera) carrera

mostrarPosicionAuto :: Auto -> Carrera -> (Int, Color)
mostrarPosicionAuto auto carrera = (puesto auto carrera, color auto)

simularCarrera :: Carrera -> [Evento] -> ListaDePosiciones
simularCarrera estadoInicial eventos = mostrarPosicionesCarrera $ foldl (flip ($)) estadoInicial eventos


