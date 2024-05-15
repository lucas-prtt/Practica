esMultiploDeTres:: Integral x => x -> Bool
esMultiploDeTres x = mod x 3 == 0

esMultiploDe:: Integral x => x -> x -> Bool
esMultiploDe x y = mod y x == 0

cubo :: Num x => x -> x
cubo x = x^3

area :: Num x => x->x->x
area b h = b * h

esBiciesto :: Integral x => x -> Bool
esBiciesto x = esMultiploDe 400 x || ( esMultiploDe 4 x && not (esMultiploDe 100 x ) )

pruebaRara :: Integral x => Fractional y => x -> y -> Int
pruebaRara x y = 5

celsiusAFarenheit :: Fractional x => x -> x
celsiusAFarenheit x = x * ( 9 / 5 ) + 32 

farenheitACelsius :: Fractional x => x -> x
farenheitACelsius x = ( x - 32 ) * 5 / 9 

esFrio :: (Fractional x, Ord x) => x -> Bool
esFrio x = farenheitACelsius x < 80

mcm :: Integral x => x -> x -> x
mcm a b = (a * b) `div` gcd a b

mayor :: (Ord x) => x->x->x
mayor x y = 
    if x > y then x
    else y

menor :: (Ord x) => x->x->x
menor x y = 
    if x > y then y
    else x

maxdetres :: (Ord x)=> x -> x -> x -> x
maxdetres a b c = max a (max b c)

dispersion :: (Num x, Ord x) => x -> x -> x -> x
dispersion x y z = mayor  (mayor x y) z - menor (menor x y) z

diasParejos :: (Fractional x, Ord x) => x->x->x->Bool
diasParejos x y z = dispersion x y z < 0.30

diasLocos :: (Fractional x, Ord x) => x->x->x->Bool
diasLocos x y z = dispersion x y z > 1

diasNormales :: (Fractional x, Ord x) => x->x->x->Bool
diasNormales x y z = not (diasLocos x y z) && not (diasParejos x y z)


--Cafe con leche-- 
auxCuadrado :: Int->Int->Int
auxCuadrado x y = 
    if x <= 0 then x
    else auxCuadrado (x-y) (y+2)

esCuadradoPerfecto :: Int -> Bool
esCuadradoPerfecto x = (auxCuadrado x 1) == 0
--Fin cafe con leche--