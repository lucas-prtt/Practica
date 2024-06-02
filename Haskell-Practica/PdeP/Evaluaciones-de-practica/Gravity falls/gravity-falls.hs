{-# LANGUAGE DataKinds #-}
import Text.Show.Functions

data Persona = Persona{
    edadPersona :: Integer,
    inventario :: [Item],
    experiencia :: Integer
} deriving (Eq, Show)

data Criatura = Fantasma{
    categoria :: Integer,
    asuntoPendiente :: Requisito
} | Gnomos{
    cantidad :: Integer
} | SiempreDetras deriving Show

tenerSoplaHojas :: Requisito
tenerSoplaHojas = elem "Soplahojas" . inventario

dipper :: Persona
dipper = Persona 16 ["Diario", "Gorra"] 5

mabel :: Persona
mabel = Persona 15 ["Soplahojas"] 4

gasparin :: Criatura
gasparin = Fantasma 7 tenerSoplaHojas

detrasDeTiImbecil :: Criatura
detrasDeTiImbecil = SiempreDetras

reunionDeGnomos :: Criatura
reunionDeGnomos = Gnomos 5

peligrosidad :: Criatura -> Integer
peligrosidad (Gnomos cantidad) = 2 ^ cantidad
peligrosidad SiempreDetras = 0
peligrosidad (Fantasma categoria _) = categoria * 20

type Requisito = Persona -> Bool
type Item = String

enfrentar :: Persona -> Criatura -> Persona
enfrentar humano criatura
    | gana humano criatura = modificarExperiencia (+ peligrosidad criatura) humano
    | otherwise = modificarExperiencia (+1) humano

gana :: Persona->Criatura->Bool
gana persona (Gnomos _) = elem "Soplahojas" $ inventario persona
gana persona SiempreDetras = False
gana persona fantasma@Fantasma{} = asuntoPendiente fantasma persona

modificarExperiencia :: (Integer->Integer)->Persona->Persona
modificarExperiencia operacion persona = persona{experiencia = operacion . experiencia $ persona}


