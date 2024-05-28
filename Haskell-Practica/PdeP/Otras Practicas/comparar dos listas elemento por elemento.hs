
lista1 :: [Integer]
lista1 = [15, 60, 32]
lista2 :: [Integer]
lista2 = [15, 60, 33]


--Compara dos listas elemento por elemento

--compararListas (<=) lista1 lista2
compararListas :: Eq x =>(x->x->Bool) -> [x] -> [x] -> Bool
compararListas condicion (x1:xs1) (x2:xs2) = condicion x1 x2 && compararListas condicion xs1 xs2
compararListas _ [] [] = True
compararListas _ _ _ = False



--Mas Complicado, pero usando all
--compararLista2 tuplaConPrimerElementoMenorOIgual lista1 lista2
compararListas2 :: (Eq x, Ord x) =>((x, x)->Bool) -> [x] -> [x] -> Bool
compararListas2 condicion l1 l2 = all condicion (listasEmparejadas l1 l2)

listasEmparejadas :: (Eq a, Ord a) => [a] -> [a] -> [(a, a)]
listasEmparejadas [] [] = []
listasEmparejadas (x1:xs1) (x2:xs2) = (x1, x2) : listasEmparejadas xs1 xs2 

tuplaConPrimerElementoMenorOIgual :: Ord x => (x, x) -> Bool
tuplaConPrimerElementoMenorOIgual x = fst x <= snd x
--Aca dice que se puede usar uncurry     ^     Pero no se como funciona del todo

--Al parecer uncurry f (x, y) = f x y
--Descompone una dupla en sus elementos para darselos a una funcion

--Se podria hacer:
--tuplaConPrimerElementoMenorOIgual x = uncurry (<=) x
--tuplaConPrimerElementoMenorOIgual = uncurry (<=)
