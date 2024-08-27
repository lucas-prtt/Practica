
%%%%%%%%%%%%%
%% Punto 1 %%
%%%%%%%%%%%%%

viaja(dodain, pehuenia).
viaja(dodain, sanMartin).
viaja(dodain, esquel).
viaja(dodain, sarmiento).
viaja(dodain, camarones).
viaja(dodain, playasDoradas).
viaja(alf, bariloche).
viaja(alf, sanMartin).
viaja(alf, elBolson).
viaja(nico, marDelPlata).
viaja(vale, calafate).
viaja(vale, elBolson).

viaja(martu, Lugar):-
    viaja(nico, Lugar).
viaja(martu, Lugar):-
    viaja(alf, Lugar).

persona(Turista):-
    viaja(Turista, _).

% Como Juan no sabe a donde ir no se lo puede incluir

% Como Carlos no viaja, por principio de universo cerrado se lo excluye y se tomara como falso cualquier consulta de viaja que se le haga



%%%%%%%%%%%%%
%% Punto 2 %%
%%%%%%%%%%%%%



% FORMATO: atraccion(Ubicacion, tipoDeAtraccion(Cualidades))


atraccion(pehuenia, parqueNacional(elBosqueVerde)).
atraccion(bariloche, cerro(otto, 2001)).
atraccion(camarones, cuerpoAgua(rio, conPesca, 13)).
atraccion(playasDoradas, playa(12)).
atraccion(elBolson, excursion(explorandoUnaFabricaDeBolsas)).

atraccion(esquel, parqueNacional(losAlerces)).
atraccion(esquel, excursion(trevellin)).
atraccion(esquel, excursion(trochita)).
atraccion(pehuenia, cerro(bateaMahuida, 2000)).
atraccion(pehuenia, cuerpoAgua(moquehue, conPesca, 14)).
atraccion(pehuenia, cuerpoAgua(alumine, conPesca, 19)).


esCopado(cerro(_, Altura)):-
    Altura>2000.
esCopado(cuerpoAgua(_, conPesca, _)).
esCopado(cuerpoAgua(_, _, Temperatura)):-
    Temperatura>20.
esCopado(plalla(DeltaMarea)):-
    DeltaMarea<5.
esCopado(excursion(Nombre)):-
    string_length(Nombre, Letras),
    Letras>7.
esCopado(parqueNacional(_)).

vacacionesCopadas(Turista):-
    persona(Turista),
    forall(viaja(Turista, Ubicacion), algunaAtraccionCopada(Ubicacion)).

algunaAtraccionCopada(Ubicacion):-
    atraccion(Ubicacion, Atraccion),
    esCopado(Atraccion).

%%%%%%%%%%%%%
%% Punto 3 %%
%%%%%%%%%%%%%

noSeCruzaron(UnaPersona, OtraPersona):-
    persona(UnaPersona), 
    persona(OtraPersona),
    %UnaPersona\=OtraPersona,
    not(seCruzaron(UnaPersona, OtraPersona)).

%Si se quiere que seCruzaron funcione de manera correcta individualmente, agregar la parte comentada

seCruzaron(UnaPersona, OtraPersona):-
    viaja(UnaPersona, MismoDestino),
    viaja(OtraPersona, MismoDestino).
    %UnaPersona \= OtraPersona.

%%%%%%%%%%%%%
%% Punto 4 %%
%%%%%%%%%%%%%

costo(sarmiento, 100).
costo(esquel, 150).
costo(pehuenia, 180).
costo(sanMartin, 150).
costo(camarones, 135).
costo(playasDoradas, 170).
costo(bariloche, 140).
costo(calafate, 240).
costo(elBolson, 145).
costo(marDelPlata, 140).

gasolero(Turista):-
    persona(Turista),
    forall(viaja(Turista, Ubicacion), destinoGasolero(Ubicacion)).

destinoGasolero(Destino):-
    costo(Destino, Costo),
    Costo<160.

%%%%%%%%%%%%%
%% Punto 5 %%
%%%%%%%%%%%%%


% itinerario(Persona, Itinerario)
% Esto es lo de explosion combinatoria???

