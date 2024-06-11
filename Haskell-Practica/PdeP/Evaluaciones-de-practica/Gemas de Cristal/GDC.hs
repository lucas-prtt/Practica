import Text.Show.Functions

data Aspecto = UnAspecto {
    tipoDeAspecto :: String,
    grado :: Float
} deriving (Show, Eq)

type Situacion = [Aspecto]



mejorAspecto :: Aspecto -> Aspecto -> Bool
mejorAspecto mejor peor = grado mejor < grado peor

mismoAspecto :: Aspecto -> Aspecto -> Bool
mismoAspecto aspecto1 aspecto2 = tipoDeAspecto aspecto1 == tipoDeAspecto aspecto2

buscarAspecto :: Aspecto -> Situacion -> Aspecto
buscarAspecto aspectoBuscado = head.filter (mismoAspecto aspectoBuscado)

buscarAspectoDeTipo :: String -> Situacion -> Aspecto
buscarAspectoDeTipo tipo = buscarAspecto (UnAspecto tipo 0)

reemplazarAspecto :: Aspecto -> Situacion -> Situacion
reemplazarAspecto aspectoBuscado situacion =aspectoBuscado : filter (not.mismoAspecto aspectoBuscado) situacion


--1a 

modificarAspecto :: (Float -> Float) -> Aspecto -> Aspecto
modificarAspecto funcion aspecto = aspecto{grado = funcion . grado $ aspecto}

--1b

mejorSituacion :: Situacion -> Situacion -> Bool
--mejorSituacion mejorSit peorSit = and $ zipWith mejorAspecto mejorSit peorSit
mejorSituacion s1 s2 = all (aspectoCorrespondienteMejor s2) s1

aspectoCorrespondienteMejor ::  Situacion -> Aspecto -> Bool
aspectoCorrespondienteMejor situacion aspecto  = mejorAspecto aspecto $ buscarAspecto aspecto situacion 

--1c

modificarSituacion :: String -> (Float -> Float)-> Situacion -> Situacion
modificarSituacion tipo alteracion sit = flip reemplazarAspecto sit . modificarAspecto alteracion . buscarAspectoDeTipo tipo $ sit

--2

data Gema = Gema {
    nombre :: String,
    fuerza :: Float,
    personalidad :: Personalidad
} deriving Show

type Personalidad = Situacion -> Situacion

vidente :: Personalidad
vidente = modificarSituacion "Incertidumbre" (/2) . modificarSituacion "Tension" (subtract 10)
relajada :: Float -> Personalidad
relajada nivel = modificarSituacion "Tension" (subtract 30) . modificarSituacion "Peligro" (+nivel)

gemaVidente :: Gema
gemaVidente = Gema "Esa De Color Azul" 3.14 vidente

gemaDescuidada :: Gema
gemaDescuidada = Gema "La de color Rojo" 20 (relajada 600)

--3 

gemaGana :: Situacion -> Gema -> Gema -> Bool
gemaGana sit ganador perdedor = masFuerte ganador perdedor && mejorEfectoSobreSituacion sit ganador perdedor

mejorEfectoSobreSituacion :: Situacion -> Gema -> Gema -> Bool
mejorEfectoSobreSituacion sit ganador perdedor = mejorSituacion (personalidad ganador sit) (personalidad perdedor sit)

masFuerte :: Gema -> Gema -> Bool
masFuerte ganador perdedor = fuerza ganador >= fuerza perdedor

--4

fusionar :: Situacion -> Gema -> Gema -> Gema
fusionar sit g1 g2 = Gema (nombreDeFusion g1 g2) (fuerzaDeFusion sit g1 g2) (personalidadDeFusion g1 g2)

nombreDeFusion :: Gema -> Gema -> String
nombreDeFusion g1 g2
    |nombre g1 == nombre g2 = nombre g1
    |otherwise = nombre g1 ++ nombre g2

fuerzaDeFusion :: Situacion ->  Gema -> Gema -> Float
fuerzaDeFusion sit g1 g2 
    |sonCompatibles sit g1 g2 = (*10) . (+ fuerza g1) $ fuerza g2
    |otherwise = (*7) . fuerza $ gemaDominante g1 g2 

sonCompatibles :: Situacion -> Gema -> Gema -> Bool
sonCompatibles situacion g1 g2 = mejorSituacion (sumarPersonalidades g1 g2 situacion) (personalidadDeFusion g1 g2 situacion)

gemaDominante :: Gema -> Gema -> Gema
gemaDominante g1 g2
    |fuerza g1 > fuerza g2 = g1
    |otherwise = g2

sumarPersonalidades :: Gema -> Gema -> Personalidad
sumarPersonalidades g1 g2 = personalidad g1 . personalidad g2

personalidadDeFusion :: Gema -> Gema -> Personalidad
personalidadDeFusion g1 g2 = sumarPersonalidades g1 g2 . map (modificarAspecto $ subtract 10)

--5

fusionGrupal :: Situacion -> [Gema] -> Gema
fusionGrupal situacion = foldl1 $ fusionar situacion

--6

--foo :: Int -> (Int -> Int) -> [Int] -> z
--foo :: Int -> (Int -> Bool) -> ([Int]->[Int]) -> z
--foo :: Int -> (Int -> Bool) -> [Int] -> z
--foo :: [Int] -> ([Int] -> Int) -> ([Int] -> [Int]) -> [Int] -> z


--Como puedo determinar cual tipo es el correcto si despues me dice que detecte los errores?
--Podrían estar todos incorrectos y ser de un tipo cualquiera