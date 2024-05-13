mismaFuncion :: (x->y) -> (x->y)
mismaFuncion x = x

flipTrucho :: (x->y->z)->y->x->z
flipTrucho funcion b c = funcion c b

siguiente :: Int->Int
siguiente x = (+1) x

mitad :: (Fractional x) => x->x
mitad x = (*0.5)x

inversa :: (Fractional x) => x->x
inversa x = (1/)x

triple :: Fractional x => x->x
triple x = (*3) x

esNumeroPositivo :: (Num x, Ord x) => x->Bool
esNumeroPositivo x = 
    if x >= 0 then True
    else False

esMultiploDe :: Integral x => x->x->Bool
esMultiploDe x y = ((==0) . rem y) x

esBiciesto :: Integral x => x -> Bool
esBiciesto x = (not . esMultiploDe 100 $ x ) && esMultiploDe 4 x || esMultiploDe 400 x

inversaRaizCuadrada :: (Floating x) => x -> x
inversaRaizCuadrada x = inversa . sqrt $ x

incrementMCuadradoN :: (Fractional x) => x -> x -> x
incrementMCuadradoN x y = (+y) . (^2) $ x

esResultadoPar :: Integral x => x->x->Bool
esResultadoPar n m = (==0) . (flip mod 2) . (^m) $ n

