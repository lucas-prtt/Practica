
% Acá va el código



%    juego(nombreDelJuego, genero(caracteristicas), precio).  <--- precio expresado en dolares :(
%    descuento(nombreDelJuego, descuento). <--- descuento expresado en porcentaje 
%    posee(nombreDeUsuario, nombreDelJuego).
%    vaAComprar(nombreDeUsuario, nombreDelJuego, esRegalo(aQuien)/noEsRegalo).


juego(callOfDutyWW2, accion, 60).
juego(falloutNewVegas, rol(247), 15).
juego(acertijosMisteriosos, puzzle(dificil, 25), 5.99).
juego(elMisterioDeLaCasaEmbrujada, puzzle(facil, 5), 14).
juego(rompecabezasDeBobRoss, puzzle(imposible, 12000), 3.25).
juego(dota2, rol(42900000), 0).
juego(csgo, accion, 0).
juego(minecraft, rol(999999), 21).

descuento(falloutNewVegas, 90).
descuento(acertijosMisteriosos, 2.5).




cuantoSale(Juego, PrecioFinal):-
    precio(Juego, Precio),
    descuento(Juego, Descuento),
    PrecioFinal is Precio - Precio * Descuento * 0.01.

cuantoSale(Juego, PrecioFinal):-
    precio(Juego, PrecioFinal),
    not(descuento(Juego, _)).   %Precio genera Juego, no hay problema de inversibilidad

precio(Juego, Precio):-
    juego(Juego, _, Precio).




buenDescuento(Juego):-
    descuento(Juego, Descuento),
    Descuento>=50.




esPopular(JuegoDeAccion):-
    generoYDatos(JuegoDeAccion, accion).
esPopular(JuegoDeRol):-
    generoYDatos(JuegoDeRol, rol(Jugadores)),
    Jugadores>1000000.
esPopular(JuegoDePuzzles):-
    generoYDatos(JuegoDePuzzles, puzzle(facil, _)).
esPopular(JuegoDePuzzles):-
    generoYDatos(JuegoDePuzzles, puzzle(_, 25)).
esPopular(minecraft).
esPopular(csgo).

generoYDatos(Juego, Genero):-
    juego(Juego, Genero, _).








usuario(xxManuelito85xx, [csgo, dota2], [propio(minecraft), regalo(elMisterioDeLaCasaEmbrujada, soyhackerxd)]).
usuario(soyhackerxd, [csgo, callOfDutyWW2, minecraft], [regalo(acertijosMisteriosos, xxManuelito85xx), regalo(acertijosMisteriosos, regalenmeAlgoPorfisQueNoTengoPlata), regalo(elMisterioDeLaCasaEmbrujada, xxManuelito85xx), propio(falloutNewVegas)]).
usuario(revendoJuegosPorMercadoLibre, [], [regalo(callOfDutyWW2, xxManuelito85xx), regalo(minecraft, xxManuelito85xxalt), regalo(acertijosMisteriosos, soyhackerxd), regalo(luisAlbertoGonzalez, minecraft)]).

posee(Usuario, Juego):-
    usuario(Usuario, Juegos, _),
    member(Juego, Juegos).

vaAComprar(Usuario, Compra, Regalo):-
    usuario(Usuario, _, Adquisiciones),
    member(Adquisicion, Adquisiciones),
    loRegala(Adquisicion, Compra, Regalo).

loRegala(propio(Juego), Juego, noEsRegalo).
loRegala(regalo(Juego, Destinatario), Juego, esRegalo(Destinatario)).

/* posee(xxManuelito85xx, csgo).
posee(xxManuelito85xx, dota2).
posee(soyhackerxd, csgo).
posee(soyhackerxd, callOfDutyWW2).
posee(soyhackerxd, minecraft).
posee(luisAlbertoGonzalez, acertijosMisteriosos).
posee(pablito777, minecraft).
posee(xxManuelito85xxalt, dota2).

vaAComprar(xxManuelito85xx, minecraft, noEsRegalo).
vaAComprar(xxManuelito85xx, elMisterioDeLaCasaEmbrujada, esRegalo(soyhackerxd)).
vaAComprar(revendoJuegosPorMercadoLibre, callOfDutyWW2, esRegalo(xxManuelito85xx)).
vaAComprar(revendoJuegosPorMercadoLibre, minecraft, esRegalo(xxManuelito85xxalt)).
vaAComprar(revendoJuegosPorMercadoLibre, acertijosMisteriosos, esRegalo(soyhackerxd)).
vaAComprar(revendoJuegosPorMercadoLibre, minecraft, esRegalo(luisAlbertoGonzalez)).
vaAComprar(soyhackerxd, acertijosMisteriosos, esRegalo(xxManuelito85xx)).
vaAComprar(soyhackerxd, acertijosMisteriosos, esRegalo(regalenmeAlgoPorfisQueNoTengoPlata)).
vaAComprar(soyhackerxd, falloutNewVegas, noEsRegalo).
vaAComprar(soyhackerxd, elMisterioDeLaCasaEmbrujada, esRegalo(xxManuelito85xx)).
vaAComprar(luisAlbertoGonzalez, falloutNewVegas, noEsRegalo). */




jugador(Jugador):-
    posee(Jugador,_).
comprador(Usuario):-
    vaAComprar(Usuario, _, _).




adictoADescuentos(Comprador):-
    comprador(Comprador),
    forall(vaAComprar(Comprador, Juego, _), buenDescuento(Juego)).




fanaticoDeGenero(Jugador, Genero):-
    posee(Jugador, UnJuego),
    posee(Jugador, OtroJuego),
    UnJuego\=OtroJuego,
    genero(UnJuego, Genero),
    genero(OtroJuego, Genero).

monotematico(Jugador, Genero):-
    jugador(Jugador),
    posee(Jugador, UnJuego),
    genero(UnJuego, Genero),
    forall(posee(Jugador, OtroJuego), genero(OtroJuego, Genero)).

genero(Juego, Genero):-
    generoYDatos(Juego, GeneroFunctor),
    tipoDeJuego(Genero, GeneroFunctor).

tipoDeJuego(accion, accion).
tipoDeJuego(rol, rol(_)).
tipoDeJuego(puzzle, puzzle(_,_)).




buenosAmigos(UnAmigo, OtroAmigo):-
    vaAComprar(UnAmigo, UnRegalo, esRegalo(OtroAmigo)),
    vaAComprar(OtroAmigo, OtroRegalo, esRegalo(UnAmigo)),
    esPopular(UnRegalo),
    esPopular(OtroRegalo).




gastoTotal(Usuario, GastoTotal, TipoDeCompra):-
    tipoDeCompra(TipoDeCompra, _),
    comprador(Usuario),
    findall(PrecioFinal , gastaEnUnJuego(Usuario, TipoDeCompra, PrecioFinal), Gastos),
    sumlist(Gastos, GastoTotal).

gastaEnUnJuego(Usuario, TipoDeCompra, Gasto):-
    vaAComprar(Usuario, Juego, Destinatario),
    tipoDeCompra(TipoDeCompra, Destinatario),
    cuantoSale(Juego, Gasto).

tipoDeCompra(esRegalo, esRegalo(_)).
tipoDeCompra(noEsRegalo, noEsRegalo).
tipoDeCompra(ambas, esRegalo(_)).
tipoDeCompra(ambas, noEsRegalo).         %%  Se puede remplazar por (ambas, _) y anda igual
