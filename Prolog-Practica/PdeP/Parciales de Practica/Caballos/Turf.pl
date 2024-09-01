


%%%%%%%%%%%%%
%% Punto 1 %%
%%%%%%%%%%%%%

jinete(valdivieso, 155, 52).
jinete(leguisamo, 161, 49).
jinete(lezcano, 149, 50).
jinete(baratucci, 153, 55).
jinete(falero, 157, 52).

unJinete(Jinete):-
    jinete(Jinete, _ , _).

caballo(botafogo).
caballo(oldMan).
caballo(energica).
caballo(matBoy).
caballo(yatasto).

leGusta(botafogo, Jinete):-
    jinete(Jinete, _, Peso),
    Peso < 52.

leGusta(botafogo, baratucci).

leGusta(oldMan, Jinete):-
    unJinete(Jinete),
    atom_length(Jinete, Longitud),
    Longitud>7.



leGusta(energica, Jinete):-
    unJinete(Jinete),
    not(leGusta(botafogo, Jinete)).

leGusta(matBoy, Jinete):-
    jinete(Jinete, Altura, _),
    Altura>170. 

%% A yatasto no le gusta nadie, por lo que por principio de universo cerrado, no es necesario aclararlo.

stud(valdivieso, elTute).
stud(falero, elTute).
stud(lezcano, lasHormigas).
stud(baratucci, elCharabon).
stud(leguisamo, elCharabon).

gano(botafogo, granPremioNacional).
gano(botafogo, granPremioRepublica).
gano(oldMan, granPremioRepublica).
gano(oldMan, campeonatoPalermoDeOro).
gano(matBoy, granPremioCriadores).

%% Los que no ganan premio no se los incluye (Ppio de universo cerrado)

%%%%%%%%%%%%%
%% Punto 2 %%
%%%%%%%%%%%%%

leGustanMultiplesJinetes(Caballo):-
    leGusta(Caballo, UnJinete),
    leGusta(Caballo, OtroJinete),
    UnJinete\=OtroJinete.


%%%%%%%%%%%%%
%% Punto 3 %%
%%%%%%%%%%%%%

aborrece(Caballo, Stud):-
    caballo(Caballo),
    unStud(Stud),
    forall(leGusta(Caballo, Jinete), not(stud(Jinete, Stud))).

unStud(Stud):-
    stud(_, Stud).

%%%%%%%%%%%%%
%% Punto 4 %%
%%%%%%%%%%%%%


piolin(Jinete):-
    unJinete(Jinete),
    forall(caballoCapo(Caballo), leGusta(Caballo, Jinete)).

caballoCapo(Caballo):-
    gano(Caballo, Premio), 
    premioImportante(Premio).

premioImportante(granPremioNacional).
premioImportante(granPremioRepublica).

%%%%%%%%%%%%%
%% Punto 5 %%
%%%%%%%%%%%%%


%Los resultados expresados como una lista de primer lugar a ultimo lugar
% Para lograr inversibilidad se podria expresar las carreras de la siguiente manera
% carrera([caballo1, caballo2, caballo3...]).
% A pesar de eso, esta forma no distingue entre distintas carreras.


%apuesta(ganador(Caballo))
%apuesta(segundo(Caballo))
%apuesta(exacta(Caballo, Caballo))
%apuesta(imperfecta(Caballo, Caballo))

apuestaGanadora(Apuesta, Carrera):-
    apuesta(Apuesta),
    % Si se tiene las carreras:    carrera(Carrera),
    cumplida(Apuesta, Carrera).

cumplida(ganador(Caballo), Carrera):-
    nth1(1, Carrera, Caballo).
cumplida(segundo(Caballo), Carrera):-
    nth1(Posicion, Carrera, Caballo),
    Posicion=<2.
cumplida(exacta(Primero, Segundo)):-
    nth1(1, Carrera, Primero),
    nth1(2, Carrera, Segundo).
cumplida(imperfecta(UnCaballo, OtroCaballo)):-
    cumplida(segundo(UnCaballo)),
    cumplida(segundo(OtroCaballo)).


%%%%%%%%%%%%%
%% Punto 6 %%
%%%%%%%%%%%%%

%% Esto va??



