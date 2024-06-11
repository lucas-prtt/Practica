import Data.List (genericLength)

--Durante el trabajo hicimos esto:
type Ciudad = String -- Esto para simplificar

type Criterio a = Ord a => Ciudad -> a

caba = "Ciudad Autonoma de Buenos Aires"
madrid = "Madrid"
laDeLosBaguettes = "Paris"

funcion :: (Num a, Ord a) => Criterio a
funcion ciudad = genericLength ciudad

type Comida = String
baguete :: Comida
baguete = "Baguete"

funcion2 :: Criterio String
funcion2 ciudad = take (genericLength ciudad * genericLength baguete) $ cycle baguete

type FuncionDeTresParametros h o l a = h->o->l->a

funcion3 :: FuncionDeTresParametros Int Int Int [Int]
funcion3 x y z = take (x*3) . cycle $ [x,2*y,3*z] 

f5 :: FuncionDeTresParametros Char Char String [String]
f5 e1 e2 lista = iterate ((e1:) . (e2:)) lista

