lista = [5, 3, 4, 8]
sumar :: (Num a) => [a] -> a
sumar = foldr (+) 0

sumarcuadrados :: (Num a) => [a] -> a
sumarcuadrados = foldr (\x -> \y -> x^2+y) 0

fibo1 :: Integer -> Integer
fibo1 x 
    |x==1 = 1
    |x==2 = 1
    |x>2 = foldl (+) 0 (map fibo1 [x-2..x-1])

