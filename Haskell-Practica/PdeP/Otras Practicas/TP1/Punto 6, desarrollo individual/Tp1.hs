--import Lib 
------- Por ahora el import Lib no anda

import Text.Show.Functions
import Data.List(genericLength)

--Yo extraño mi ciudad, las luces de mi ciudad...” decía la canción. Es el momento
--de modelar las ciudades del pintoresco país de Haskellandia, de las que nos interesa
--conocer su nombre, el año de fundación, las atracciones principales (como “Obelisco”,
--Pan de Azúcar”, “El Gorosito”, etc.) y su costo de vida.
   

-- Estructura Ciudad
data Ciudad = Ciudad {
    nombre :: String,
    anio :: Integer,
    atracciones :: [String],
    costoDeVida :: Float
}deriving (Show)

-- Estructura Anio
data LosAniosPasan = LosAniosPasan {
     numAnio :: Integer,
     eventos :: [Ciudad -> Ciudad]
}deriving (Show)


--Ciudades ejemplo
barcelona = Ciudad "Barcelona" 1700 ["Sagrada Familia", "Parc Guell"] 1000
buenosAires = Ciudad "Buenos Aires" 1536 ["Obelisco", "Casa Rosada"] 800
paris = Ciudad "Paris" 300 ["Torre Eiffel", "Louvre"] 1500
tokio = Ciudad "Tokio" 1603 [] 2000






-- Punto 1 -- Valor de una ciudad

valorDeUnaCiudad ::  Ciudad -> Float
valorDeUnaCiudad ciudad
    | anio ciudad < 1800 = fromIntegral(5 * (1800 - anio ciudad))
    | null (atracciones ciudad) = 2 * costoDeVida ciudad
    | otherwise =  3 * costoDeVida ciudad 
    





-- Punto 2 -- Atracciones Copadas

esVocal :: Char -> Bool
esVocal letra =  letra `elem` "aeiouAEIOU"
 
algunaAtraccionCopada :: Ciudad -> Bool
algunaAtraccionCopada ciudad = any atraccionCopada (atracciones ciudad)

atraccionCopada :: String -> Bool
atraccionCopada (x:_) = esVocal x
atraccionCopada _ = False

--Punto 2.1
--Ciudad Sobria

ciudadSobria :: Int -> Ciudad -> Bool
ciudadSobria cantidadDeLetras ciudad = all (mayorACantidadDeLetras cantidadDeLetras) (atracciones ciudad)
    where
        mayorACantidadDeLetras :: Int -> String -> Bool
        mayorACantidadDeLetras cantidadDeLetras atraccion = genericLength atraccion > cantidadDeLetras

--Punto 2.2
-- Ciudad con nombre raro

ciudadNombreRaro :: Ciudad -> Bool
ciudadNombreRaro ciudad = any ((<5) . genericLength) (atracciones ciudad)


 




-- Punto 3: Eventos

sumarUnaNuevaAtraccion ::  String -> Ciudad -> Ciudad
sumarUnaNuevaAtraccion nuevaAtraccion (Ciudad nombre anio atracciones costoDeVida) = Ciudad nombre anio (nuevaAtraccion : atracciones) (costoDeVida * 1.20)

-- Punto 3.1
-- Crisis
atravesarCrisis :: Ciudad -> Ciudad
atravesarCrisis (Ciudad nombre anio atracciones costoDeVida) = Ciudad nombre anio (init atracciones) (costoDeVida * 0.9)

-- Punto 3.2
--Remodelación
remodelacion :: Float -> Ciudad -> Ciudad
remodelacion porcetanje (Ciudad nombre anio atracciones costoDeVida) = Ciudad ("New" ++ nombre) anio atracciones (costoDeVida * (1 + porcetanje/100))

--Punto 3.3
-- Reevaluación
reevaluacion :: Int -> Ciudad -> Ciudad
reevaluacion cantidadLetras (Ciudad nombre anio atracciones costoDeVida) 
    | ciudadSobria cantidadLetras (Ciudad nombre anio atracciones costoDeVida) = Ciudad nombre anio atracciones (costoDeVida * 1.10)
    | otherwise = Ciudad nombre anio atracciones (costoDeVida - 3)





-- Punto 4 --

detonarCiudad :: Ciudad -> Ciudad
detonarCiudad = reevaluacion 5 . remodelacion 10 . atravesarCrisis . sumarUnaNuevaAtraccion "Atraccionnro1" 




-- Punto 5 --
-- Anios Ejemplo
año2022 :: LosAniosPasan
año2022 = LosAniosPasan 2022 [remodelacion 5, atravesarCrisis, reevaluacion 7]
año2015 :: LosAniosPasan
año2015 = LosAniosPasan 2015 []

--type Evento = Ciudad -> Ciudad
--Se podria implementar esto para que quede mas comodo

--Funciones
pasarPorAnio :: LosAniosPasan -> Ciudad -> Ciudad
pasarPorAnio anio = pasarPorListaDeEventos (eventos anio)

--Esta  es auxiliar

--                       Version explicitamente recursiva
--pasarPorListaDeEventos :: [Ciudad -> Ciudad] -> Ciudad -> Ciudad
--pasarPorListaDeEventos (x:xs) ciudad = pasarPorListaDeEventos xs (x ciudad)
--pasarPorListaDeEventos _ ciudad      = ciudad 
--                          Version con fold
pasarPorListaDeEventos :: [Ciudad -> Ciudad] -> Ciudad -> Ciudad
pasarPorListaDeEventos = flip $ foldr (\evento -> \ciudad -> evento ciudad) 




-- 5.2  Algo mejor
-- Implementar una función que reciba una ciudad, un criterio de comparación y un evento, 
-- de manera que nos diga si la ciudad tras el evento subió respecto a ese criterio. 

data Criterio = CostoDeVida | Atracciones 

algoMejor :: Criterio -> Ciudad -> (Ciudad -> Ciudad) -> Bool
algoMejor CostoDeVida ciudad evento = costoDeVida ciudad < (costoDeVida . evento) ciudad
algoMejor Atracciones ciudad  evento = (genericLength . atracciones) ciudad < (genericLength . atracciones . evento) ciudad


--  NO FUNCIONA TODAVIA  -> Intento de generalizar 5.2, 5.3, 5.4
-- filter :: (a -> Bool) -> [a] -> [a]
-- (Ciudad -> Bool)
-- filtrarEventos :: [Ciudad -> Ciudad] -> (Ciudad -> Ciudad) ->Ciudad -> [Ciudad -> Ciudad]
-- --                  Lista de eventos ->  Criterio de los eventos que se quedan -> Lista de eventos Filtrada
-- filtrarEventos eventos condicion ciudad = filter condicion eventos 

-- costoDeVidaQueSuba :: LosAniosPasan -> Ciudad -> Ciudad
-- costoDeVidaQueSuba unAnio ciudad =  pasarPorListaDeEventos (filtrarEventos (eventos unAnio) (algoMejor costoDeVida ciudad) ) ciudad


-- Punto 5.3
costoDeVidaQueSuba :: LosAniosPasan -> Ciudad -> Ciudad
costoDeVidaQueSuba unAnio ciudad =  pasarPorListaDeEventos eventosbuenos ciudad
    where 
        -- filter :: (Ciudad -> Ciudad -> Bool) -> [Ciudad -> Ciudad] -> [Ciudad -> Ciudad]
        eventosbuenos = filter (algoMejor CostoDeVida ciudad) (eventos unAnio)


-- Punto 5.4
costoDeVidaQueBaje :: LosAniosPasan -> Ciudad -> Ciudad
costoDeVidaQueBaje unAnio ciudad = pasarPorListaDeEventos eventosmalos ciudad
    where 
        -- filter :: (not . (Ciudad -> Ciudad -> Bool)) -> [Ciudad -> Ciudad] -> [Ciudad -> Ciudad]
        eventosmalos = filter (not . algoMejor CostoDeVida ciudad) (eventos unAnio)

-- Punto 5.5                
valorQueSuba:: LosAniosPasan -> Ciudad -> Ciudad
valorQueSuba unAnio ciudad = pasarPorListaDeEventos eventosCapitalistas ciudad
    where                                       -- Ciudad antes          <       Ciudad Despues
        eventosCapitalistas = filter (\evento -> valorDeUnaCiudad (evento ciudad) > valorDeUnaCiudad ciudad) (eventos unAnio)

--Punto 6.1
--Listas para probar
listaOrdenada = [remodelacion 10, remodelacion 20, remodelacion 30, remodelacion 40]
listaDesordenada = [remodelacion 50, remodelacion 60, remodelacion 10]
type Evento = (Ciudad -> Ciudad)

{-  -- Primera version

listaDeEventosOrdenada :: [Evento]->Ciudad->Bool
listaDeEventosOrdenada (x1:x2:xs) ciudad = (costoDeVida . x1 $ ciudad) < (costoDeVida . x2 $ ciudad) && listaDeEventosOrdenada (x2:xs) ciudad 
listaDeEventosOrdenada (x:xs) ciudad = True
listaDeEventosOrdenada _ _ = True
 -}

 -- Voy a intentar generalizar
foldDobleR :: (b->b->a->a)->a->[b]->a
foldDobleR funcion casoBase (x1:x2:xs) = funcion x1 x2 (foldDobleR funcion casoBase (x2:xs))
foldDobleR _ casoBase (x2:xs) = casoBase
foldDobleR _ casoBase [] = casoBase 

-- Funciona bien esta!!!
listaDeEventosOrdenada :: [Evento] -> Ciudad -> Bool
listaDeEventosOrdenada lista ciudad = foldDobleR (\e1 -> \e2 -> \resto -> (costoDeVida . e1 $ ciudad) < (costoDeVida . e2 $ ciudad) && resto) True lista

-- Ahora a aplicarla al ejercicio con lo de los anios
anioConCostoDeVidaAscendente :: LosAniosPasan -> Ciudad -> Bool
anioConCostoDeVidaAscendente = listaDeEventosOrdenada . eventos  

--Punto 6.2
listaDeCiudadesOrdenadas :: [Ciudad] -> Evento -> Bool
listaDeCiudadesOrdenadas ciudades evento = foldDobleR (\c1 -> \c2 -> \resto -> (costoDeVida . evento $ c1) < (costoDeVida . evento $ c2) && resto) True ciudades

