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


dipper :: Persona
dipper = Persona 12 ["Diario", "Gorra", "Disfraz de oveja"] 5

mabel :: Persona
mabel = Persona 13 ["Soplahojas"] 4

gasparin :: Criatura
gasparin = Fantasma 7 (flip tieneObjeto "Soplahojas")

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
gana persona (Gnomos _) = tieneObjeto persona "Soplahojas" 
gana persona SiempreDetras = False
gana persona fantasma@Fantasma{} = asuntoPendiente fantasma persona

tieneObjeto :: Persona -> Item -> Bool
tieneObjeto = flip elem . inventario

modificarExperiencia :: (Integer->Integer)->Persona->Persona
modificarExperiencia operacion persona = persona{experiencia = operacion . experiencia $ persona}

enfrentarCriaturas :: Persona -> [Criatura] -> Persona
enfrentarCriaturas = foldl enfrentar  

ejercitoDeGnomos :: Criatura
ejercitoDeGnomos = Gnomos 10

elSiempreDetras :: Criatura
elSiempreDetras = SiempreDetras

fantasmaPegi13 :: Criatura
fantasmaPegi13 = Fantasma 3 ovejaInimputable
ovejaInimputable :: Persona -> Bool
ovejaInimputable persona = ((<13) . edadPersona) persona && tieneObjeto persona "Disfraz de oveja"

fantasmaPrincipiante :: Criatura
fantasmaPrincipiante = Fantasma 1 ((>10) . experiencia)

grupoDeCriaturas :: [Criatura]
grupoDeCriaturas = [elSiempreDetras, ejercitoDeGnomos, fantasmaPegi13, fantasmaPrincipiante]

--Para enfrentar a estas criaturas se puede escribir en consola
--enfrentarCriaturas dipper grupoDeCriaturas

zipWithIf :: (a -> b -> b) -> (b -> Bool) -> [a] -> [b] -> [b]
zipWithIf funcion condicion (xA:xAs) (xB:xBs) 
    | condicion xB = funcion xA xB : zipWithIf funcion condicion xAs xBs
    | otherwise = xB : zipWithIf funcion condicion (xA:xAs) xBs
zipWithIf _ _ _ _ = []



