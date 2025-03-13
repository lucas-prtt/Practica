import System.Win32.DebugApi (rip)

--Arranco 9:42

-- Punto 1

data Auto=Auto{
    marcaDeAuto :: String,
    modeloDeAuto :: String,
    desgasteDeChasis :: Integer,
    desgasteDeRuedas :: Integer,
    velocidadMaxima :: Integer,
    tiempoDeCarrera :: Integer
} deriving Show

autoFerrari :: Auto
autoFerrari = Auto "Ferrari" "F50" 0 0 65 0
autoLamborghini :: Auto
autoLamborghini = Auto "Lamborghini" "Diablo" 7 4 73 0
autoFiat :: Auto
autoFiat = Auto "Fiat" "Modelo 600" 33 27 44 0

--Punto 2

autoEnBuenEstado :: Auto->Bool
autoEnBuenEstado auto = ((<40) . desgasteDeChasis) auto && ((<60) . desgasteDeRuedas) auto

autoNoDaMas :: Auto->Bool
autoNoDaMas auto = ((>80) . desgasteDeChasis) auto || ((>80) . desgasteDeRuedas) auto

--Punto 3

porcentajeDeEntero :: Integer -> Integer -> Integer
porcentajeDeEntero porcentaje numero = div (numero * porcentaje) 100  

modificarDesgasteChasis :: (Integer->Integer) -> Auto -> Auto
modificarDesgasteChasis funcion auto = auto{desgasteDeChasis = funcion . desgasteDeChasis $ auto}

modificarDesgasteRuedas :: (Integer->Integer) -> Auto -> Auto
modificarDesgasteRuedas funcion auto = auto{desgasteDeRuedas = funcion . desgasteDeRuedas $ auto}

repararAuto :: Auto -> Auto
repararAuto auto = modificarDesgasteChasis (subtract $ porcentajeDeEntero 85 (desgasteDeChasis auto)) . modificarDesgasteRuedas (const 0) $ auto

-- Punto 4


data Estado = Bien | Mojada | Ripio | Obstruida deriving (Show, Eq)


data Tramo = Curva{
    angulo :: Integer,
    longitud :: Integer,
    estado :: Estado,
    sectorObstruido :: Integer
} | Recto{
    longitud :: Integer,
    boxes :: Bool,
    estado :: Estado,
    sectorObstruido :: Integer
}

curvaPeligrosa :: Tramo
curvaPeligrosa = Curva 60 300 Bien 0

curvaTranca :: Tramo
curvaTranca = Curva 110 550 Bien 0

tramoRectoClassic :: Tramo
tramoRectoClassic = Recto 750 False Bien 0

tramito :: Tramo
tramito = Recto 280 False Bien 0


sumarTiempo :: Integer -> Auto -> Auto
sumarTiempo tiempo auto = auto{tiempoDeCarrera = (+tiempo) . tiempoDeCarrera $ auto}

tiempoCurva :: Tramo -> Auto -> Integer
tiempoCurva tramo auto = div (tiempoRecta tramo auto) 2
tiempoRecta :: Tramo -> Auto -> Integer
tiempoRecta tramo auto = div (longitud tramo) $ velocidadMaxima auto

tiempoTramo :: Tramo -> Auto -> Integer
tiempoTramo curva@Curva{} = tiempoCurva curva
tiempoTramo recta@Recto{} = tiempoRecta recta

recorrerTramo :: Tramo -> Auto -> Auto
recorrerTramo curva@(Curva ang lon _ _) auto = modificarDesgasteRuedas (+div (3*lon) ang) . sumarTiempo (tiempoCurva curva auto) $ auto
recorrerTramo recta@(Recto lon False _ _) auto = modificarDesgasteChasis (+div lon 100) . sumarTiempo (tiempoRecta recta auto) $ auto
recorrerTramo recta@(Recto lon True _ _) auto 
    |autoEnBuenEstado auto = modificarDesgasteChasis (+div lon 100) . sumarTiempo (tiempoRecta recta auto) $ auto
    |otherwise = repararAuto . recorrerTramo recta{boxes = False} . sumarTiempo 10 $ auto

recorrerMojada :: Tramo -> Auto -> Auto
recorrerMojada tramo auto = recorrerTramo tramo . sumarTiempo (flip div 2 $ tiempoTramo tramo auto) $ auto

doble :: (a->a)->(a->a)
doble a = a . a

recorrerRipia :: Tramo -> Auto -> Auto
recorrerRipia tramo = doble (recorrerTramo tramo)

recorrerObstruida :: Tramo -> Auto -> Auto
recorrerObstruida tramo = modificarDesgasteRuedas ((+) . (*2) . sectorObstruido $ tramo) . recorrerTramo tramo

pasarPor :: Tramo -> Auto -> Auto
pasarPor tramo 
    | estado tramo == Bien = recorrerTramo tramo
    | estado tramo == Ripio = recorrerRipia tramo
    | estado tramo == Mojada = recorrerMojada tramo
    | estado tramo == Obstruida = recorrerObstruida tramo


-- Punto 5

pasarPorTramo :: Tramo -> Auto -> Auto
pasarPorTramo tramo auto 
    |not . autoNoDaMas $ auto = pasarPor tramo auto
    |otherwise = auto

--Punto 6

mojar :: Tramo -> Tramo
mojar tramo = tramo{estado = Mojada}

ripiar :: Tramo -> Tramo
ripiar tramo = tramo{estado = Ripio}

obstruir :: Integer -> Tramo -> Tramo
obstruir obstruccion tramo = tramo{estado = Obstruida, sectorObstruido = obstruccion}

curvaA :: Tramo
curvaA = Curva 80 400 Bien 0
curvaB :: Tramo
curvaB = Curva 115 650 Bien 0
rectaA :: Tramo
rectaA = Recto 970 False Bien 0
boxesA :: Tramo
boxesA = Recto 800 True Bien 0

--a
type Pista = [Tramo]
superPista :: Pista
superPista = [tramoRectoClassic, curvaTranca, mojar tramito, tramito, obstruir 2 curvaA, curvaB, rectaA, curvaPeligrosa, ripiar tramito, boxesA]

--b

sacarLosQueNoDanMas :: [Auto] -> [Auto] 
sacarLosQueNoDanMas = filter (not . autoNoDaMas) 

pasarAutosYFiltrar :: [Auto] -> Tramo -> [Auto]
pasarAutosYFiltrar losautos tramo = sacarLosQueNoDanMas $ map (pasarPorTramo tramo) losautos

pegarLaVuelta :: Pista -> [Auto] -> [Auto]
pegarLaVuelta pista autos = foldl pasarAutosYFiltrar autos pista
--pegarLaVuelta pista autos = foldl (\losautos tramo -> sacarLosQueNoDanMas $ map (pasarPorTramo tramo) losautos) autos pista

--7
type Carrera = (Pista, Int)
tourBuenosAires :: Carrera
tourBuenosAires = (superPista, 20)


modelarCarrera :: Carrera -> [Auto] -> [[Auto]]
modelarCarrera (pista, vueltas) autos = take vueltas (iterate (pegarLaVuelta pista) autos)








