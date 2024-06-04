
--   1
data Pais = Pais{
    ingresoPerCapita    :: Integer,
    sectorPrivado       :: Integer,
    sectorPublico       :: Integer,
    deudaConFMI         :: Integer,
    recursosNaturales   :: [Recurso]
} deriving Show

type Recurso = String

nambia = Pais 4140 650000 400000 50000000 ["Mineria", "Ecoturismo"] 

--   2

-- Modificadores
modificarDeuda :: (Integer -> Integer) -> Pais -> Pais
modificarDeuda operacion pais = pais{deudaConFMI = operacion $ deudaConFMI pais}

modificarSectorPrivado :: (Integer -> Integer) -> Pais -> Pais
modificarSectorPrivado operacion pais = pais{sectorPrivado = operacion $ sectorPrivado pais}

modificarSectorPublico :: (Integer -> Integer) -> Pais -> Pais
modificarSectorPublico operacion pais = pais{sectorPublico = operacion $ sectorPublico pais}

modificarIngreso :: (Integer -> Integer) -> Pais -> Pais
modificarIngreso operacion pais = pais{ingresoPerCapita = operacion $ ingresoPerCapita pais}

modificarRecursos :: ([Recurso] -> [Recurso]) -> Pais -> Pais
modificarRecursos operacion pais = pais{recursosNaturales = operacion $ recursosNaturales pais}

prestar :: Integer -> Pais -> Pais
prestar cuanto = modificarDeuda ((+) . (flip div 2) $ cuanto*3) 

prestarMillones :: Integer -> Pais -> Pais
prestarMillones = prestar . (*1000000)

reducirSectorPublico :: Integer -> Pais -> Pais
reducirSectorPublico cuantosPuestos pais
    |(>100) . sectorPublico $ pais = modificarSectorPublico (subtract cuantosPuestos) . modificarIngresoPorcentaje (-20) $ pais
    | otherwise = modificarSectorPublico (subtract cuantosPuestos) . modificarIngresoPorcentaje (-15) $ pais

modificarIngresoPorcentaje :: Integer -> Pais -> Pais
modificarIngresoPorcentaje porcentaje pais = modificarIngreso ((+) . (flip div 100) . (*(100+porcentaje)) $ (ingresoPerCapita pais)) pais

sacarRecursos :: Recurso -> Pais -> Pais
sacarRecursos recurso = modificarRecursos (filter (/=recurso)) . modificarDeuda (subtract 2000000)

pbi :: Pais -> Integer
pbi pais = (sectorPrivado pais + sectorPublico pais) * ingresoPerCapita pais

darBlindaje :: Pais -> Pais
darBlindaje pais = modificarSectorPublico (subtract 500) . prestar (div (pbi pais) 2) $ pais




