
hacerSobre :: Integral x => x -> (x -> x) -> x
hacerSobre x f = f $ x

listaDeOperaciones = [(+7), (subtract 78), (flip div 2)]

-- Se puede hacer igual con 
--ghci> map ($ 2) listaDeOperaciones        
--[9,-76,1]
--ghci> map (flip ($) 2) listaDeOperaciones 
--[9,-76,1]
--ghci> map (hacerSobre 2) listaDeOperaciones 
--[9,-76,1]