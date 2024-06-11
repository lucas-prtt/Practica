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




