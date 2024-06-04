
--   1
data Pais = Pais{
    ingresoPerCapita    :: Integer,
    sectorPrivado       :: Integer,
    sectorPublico       :: Integer,
    deudaConFMI         :: Integer,
    recursosNaturales   :: [Recurso]
} deriving Show

type Recurso = String
type Receta = Pais -> Pais

nambia :: Pais
nambia = Pais 4140 650000 400000 50000000 ["Mineria", "Ecoturismo"] 
arabiaSaudita :: Pais
arabiaSaudita = Pais 900 80000 25000 1000000 ["Petroleo", "Arena"]


--   2

-- Modificadores
modificarDeuda :: (Integer -> Integer) -> Receta
modificarDeuda operacion pais = pais{deudaConFMI = operacion $ deudaConFMI pais}

modificarSectorPrivado :: (Integer -> Integer) -> Receta
modificarSectorPrivado operacion pais = pais{sectorPrivado = operacion $ sectorPrivado pais}

modificarSectorPublico :: (Integer -> Integer) -> Receta
modificarSectorPublico operacion pais = pais{sectorPublico = operacion $ sectorPublico pais}

modificarIngreso :: (Integer -> Integer) -> Receta
modificarIngreso operacion pais = pais{ingresoPerCapita = operacion $ ingresoPerCapita pais}

modificarRecursos :: ([Recurso] -> [Recurso]) -> Receta
modificarRecursos operacion pais = pais{recursosNaturales = operacion $ recursosNaturales pais}

prestar :: Integer -> Receta
prestar cuanto = modificarDeuda ((+) . (flip div 2) $ cuanto*3) 

prestarMillones :: Integer -> Receta
prestarMillones = prestar . (*1000000)

reducirSectorPublico :: Integer -> Receta
reducirSectorPublico cuantosPuestos pais
    |(>100) . sectorPublico $ pais = modificarSectorPublico (subtract cuantosPuestos) . modificarIngresoPorcentaje (-20) $ pais
    | otherwise = modificarSectorPublico (subtract cuantosPuestos) . modificarIngresoPorcentaje (-15) $ pais

modificarIngresoPorcentaje :: Integer -> Receta
modificarIngresoPorcentaje porcentaje pais = modificarIngreso ((+) . (flip div 100) . (*(100+porcentaje)) $ (ingresoPerCapita pais)) pais

sacarRecursos :: Recurso -> Receta
sacarRecursos recurso = modificarRecursos (filter (/=recurso)) . modificarDeuda (subtract 2000000)

pbi :: Pais -> Integer
pbi pais = (sectorPrivado pais + sectorPublico pais) * ingresoPerCapita pais

darBlindaje :: Receta
darBlindaje pais = modificarSectorPublico (subtract 500) . prestar (div (pbi pais) 2) $ pais

sacarMinerales :: Receta
sacarMinerales = sacarRecursos "Mineria" . prestarMillones 200

-- ghci> sacarMinerales nambia 
-- Pais {ingresoPerCapita = 4140, sectorPrivado = 650000, sectorPublico = 400000, deudaConFMI = 348000000, recursosNaturales = ["Ecoturismo"]}

-- Efecto colateral???

puedenSafar :: [Pais] -> [Pais]
puedenSafar = filter (elem "Petroleo" . recursosNaturales)

sumaDeDeudasACobrar :: [Pais] -> Integer
sumaDeDeudasACobrar = sum . map deudaConFMI

-- Orden superior:
-- La primera funcion utiliza orden superior al utilizar la funcion filter la cual toma como parametro otra función que es la que se encarga de filtrar cada elemento
-- Tuvo como ventaja el no tener que declarar una funcion recursiva que se encarge de filtrar segun solamente el criterio de este punto

-- Composicion: 
-- En la segunda funcion se compone la funcion sum con la funcion map, para que la lista de paises primero se convierta en una lista de enteros (Deudas) y luego de las sume.
-- Tiene como ventaja que me permite ahorrarme los parentesis y utilizar aplicacion parcial para responder el siguiente punto
-- Ademas me permite no escribir la lista de paises como argumento de ambos lados y es mas facil de entender

-- Aplicacion parcial:
-- La funcion map deudaConFmi está aplicada parcialmente, ya que normalmente map toma 2 parametros, sin embargo, solo se le da uno (la funcion a aplicar) para que luego al darse el otro se produzca el resultado
-- Tiene como ventaja que de este modo no tengo que declarar una nueva funcion tan solo para hacer un map con deudas y me permite no escribir la lista de paises como argumento de ambos lados

peorAMejorReceta :: [Receta] -> Pais -> Bool
peorAMejorReceta lista@(receta1:receta2:xs) pais = (pbi . receta1) pais < (pbi . receta2) pais && peorAMejorReceta (tail lista) (receta1 pais)
peorAMejorReceta _ _ = True


-- 6a: Si evaluamos la funcion de paises que pueden safar con una lista con un pais de recursos infinitos distintos al petroleo, como en el ejemplo dado, haskell permanecerá analizando indefinidamente, hasta que se acabe la memoria de la computadora y se mate el proceso

-- 6b: Si evaluamos la funcion de sumar deudas con una lista de paises finita, la cual tiene paises con infinitos recursos naturales, se obtendrá un resultado, puesto que no es necesario evaluar los recursos naturales de un pais para realizar la suma de deudas, y como haskell utiliza Lazy Evaluation, solo se evalua una expresion cuando se necesita, que en el caso de los recursos naturales en esta funcion es nunca.




