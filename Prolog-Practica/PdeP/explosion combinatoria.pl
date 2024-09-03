color(botafogo, tordo).
color(oldMan, alazan).
color(energica, ratonero).
color(matBoy, palomino).
color(yatasto, pinto).

diccionario(tordo, negro).
diccionario(alazan, marron).
diccionario(ratonero, gris).
diccionario(ratonero, negro).
diccionario(palomino, marron).
diccionario(palomino, blanco).
diccionario(pinto, blanco).
diccionario(pinto, marron).

caballos(Caballos):-
    findall(Caballo, color(Caballo, _), Caballos).
compraria(Color, Seleccion):-
    caballos(Caballos),
    combinatoriaDeCaballos(Caballos, Color, Seleccion).

combinatoriaDeCaballos([], _ ,[]).
combinatoriaDeCaballos([CaballoValido|CaballosRestantes], Color, [CaballoValido|SeleccionadosRestantes]):-
    color(CaballoValido, ColorCaballo),
    diccionario(ColorCaballo, Color),
    combinatoriaDeCaballos(CaballosRestantes, Color, SeleccionadosRestantes).
combinatoriaDeCaballos([_|CaballosRestantes], Color, Seleccion):-
    combinatoriaDeCaballos(CaballosRestantes, Color, Seleccion).

