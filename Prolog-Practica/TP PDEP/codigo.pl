%%---------------------------------------------%%
%%                  Parte 1                    %%
%%---------------------------------------------%%

%%---------%%
%% Punto 1 %%
%%---------%%

tieneCivilizacion(ana, romanos).
tieneCivilizacion(beto, incas).
tieneCivilizacion(carola, romanos).
tieneCivilizacion(dimitri, romanos).

desarrollo(ana ,herreria).
desarrollo(ana, forja).
desarrollo(ana, fundicion).
desarrollo(ana, laminas).
desarrollo(beto, herreria).
desarrollo(beto, forja).
desarrollo(beto, fundicion).
desarrollo(carola, herreria).
desarrollo(dimitri, herreria).
desarrollo(dimitri, emplumado).

tecnologia(herreria). 
tecnologia(emplumado).
tecnologia(forja).
tecnologia(laminas).
tecnologia(punzon).
tecnologia(fundicion).
tecnologia(malla).
tecnologia(horno).
tecnologia(placas).
tecnologia(molino).
tecnologia(collera).
tecnologia(arado). 

jugador(Jugador):-
    tieneCivilizacion(Jugador, _).


%%---------%%
%% Punto 2 %%
%%---------%%

expertoEnMetales(Jugador):-
    desarrollo(Jugador, herreria),
    desarrollo(Jugador, forja),
    fundicionORomano(Jugador).

fundicionORomano(Jugador):-
    desarrollo(Jugador, fundicion).

fundicionORomano(Jugador):-
    tieneCivilizacion(Jugador, romanos).


%%---------%%
%% Punto 3 %%
%%---------%%

civilizacionEsPopular(Civilizacion):-
    tieneCivilizacion(UnJugador, Civilizacion),
    tieneCivilizacion(OtroJugador, Civilizacion),
    UnJugador \= OtroJugador.

%%---------%%
%% Punto 4 %%
%%---------%%

tecnologiaGlobal(Tecnologia):-
    tecnologia(Tecnologia),
    forall(jugador(Jugador), desarrollo(Jugador, Tecnologia)).

%%---------%%
%% Punto 5 %%
%%---------%%

civilizaciones(Civilizacion):-
    tieneCivilizacion(_, Civilizacion).
    
tieneCadaTecnologia(Civilizacion, Tecnologia) :-
    tieneCivilizacion(Jugador, Civilizacion),
    desarrollo(Jugador, Tecnologia).

civilizacionLider(Civilizacion) :-
    civilizaciones(Civilizacion),
    forall(desarrollo(_, Tecnologia), tieneCadaTecnologia(Civilizacion, Tecnologia)).

%%---------------------------------------------%%
%%                  Parte 2                    %%
%%---------------------------------------------%%

%%---------%%
%% Punto 1 %%
%%---------%%
unidad(ana, jinete(caballo)).
unidad(ana, piquetero(conEscudo, 1)).
unidad(ana, piquetero(sinEscudo, 2)).
unidad(beto, campeon(100)).
unidad(beto, campeon(80)).
unidad(beto, piquetero(conEscudo, 1)).
unidad(beto, jinete(camello)).
unidad(carola, piquetero(sinEscudo, 3)).
unidad(carola, piquetero(conEscudo, 2)).

vidaPorUnidad(jinete(caballo), 90).
vidaPorUnidad(jinete(camello), 80).
vidaPorUnidad(campeon(Vida), Vida).
vidaPorUnidad(piquetero(sinEscudo, 1), 50).
vidaPorUnidad(piquetero(sinEscudo, 2), 65).
vidaPorUnidad(piquetero(sinEscudo, 3), 70).
vidaPorUnidad(piquetero(conEscudo, Nivel), Vida):- 
    vidaPorUnidad(piquetero(sinEscudo, Nivel), VidaSinEscudo),
    Vida is 1.10 * VidaSinEscudo.

%%---------%%
%% Punto 2 %%
%%---------%%
    
unidadConMasVida(Jugador, UnaUnidad):-
    unidad(Jugador, UnaUnidad),
    forall(unidad(Jugador, OtraUnidad), masVidaQue(UnaUnidad, OtraUnidad)).


masVidaQue(Fuerte, Debilucho):-
    vidaPorUnidad(Fuerte, MayorVida),
    vidaPorUnidad(Debilucho, MenorVida),
    MayorVida >= MenorVida.

%%---------%%
%% Punto 3 %%
%%---------%%

ventaja(campeon(_), piquero(_ , _)).
ventaja(piquero(_ , _), jinete(_)).
ventaja(jinete(_), campeon(_)).
ventaja(jinete(camello), jinete(caballo)).

gana(Ganador, Perdedor):-
    ventaja(Ganador, Perdedor).
    
gana(Ganador, Perdedor):-
    not(ventaja(Ganador, Perdedor)),
    masVidaQue(Ganador, Perdedor).


%%---------%%
%% Punto 4 %%
%%---------%%

cantidadUnidad(Jugador, Unidad, TotalDeUnidades):-
    findall(_, unidad(Jugador, Unidad), Unidades),
    length(Unidades, TotalDeUnidades).
    
seBancaUnaAsedio(Jugador):-
    jugador(Jugador),
    cantidadUnidad(Jugador, piquetero(sinEscudo, _), CantidadSinEscudo),
    cantidadUnidad(Jugador, piquetero(conEscudo, _), CantidadConEscudo),
    CantidadConEscudo > CantidadSinEscudo.

%%-----------%%
%% Punto 5.a %%
%%-----------%%

dependeDe(punzon, emplumado).
dependeDe(emplumado, herreria).
dependeDe(forja, herreria).
dependeDe(fundicion, forja).
dependeDe(horno, fundicion).
dependeDe(laminas, herreria).
dependeDe(malla, laminas).
dependeDe(placas, malla).
dependeDe(collera, molino).
dependeDe(arado, collera).
     
%%-----------%%
%% Punto 5.b %%
%%-----------%%

puedeDesarrollar(Jugador, Tecnologia):-
    jugador(Jugador),
    tecnologia(Tecnologia),
    not(desarrollo(Jugador, Tecnologia)),
    forall(requisito(Tecnologia, Requisito), desarrollo(Jugador, Requisito)).

requisito(Tecnologia, Requisito):-
    dependeDe(Tecnologia, Requisito).
requisito(Tecnologia, Requisito):-
    dependeDe(Tecnologia, Antecesor),
    requisito(Antecesor, Requisito).











