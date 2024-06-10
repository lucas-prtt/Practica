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

carreraDeEjemplo = [Auto "Verde" 2 6, Auto "Azul" 205 3, Auto "Naranja" 1 1000, mario]



