lista = [5, 3, 4, 8]
sumar :: (Num a) => [a] -> a
sumar = foldr (+) 0

sumarcuadrados :: (Num a) => [a] -> a
sumarcuadrados = foldr (\x -> \y -> x^2+y) 0