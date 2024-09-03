

%% Solo para generar mas facilmente los "atiende"
horario(dodain, [turno(lunes, 9, 15), turno(miercoles, 9, 15), turno(viernes, 9, 15)]).
horario(lucas, [turno(martes, 10, 20)]).
horario(juanC, [turno(sabado, 18, 22), turno(domingo, 18, 22)]).
horario(juanFdS, [turno(jueves, 10, 20), turno(viernes, 12, 20)]).
horario(leoC, [turno(lunes,14, 18), turno(miercoles, 14, 18)]).
horario(martu, [turno(miercoles, 23, 24)]).

atiende(Nombre, turno(Dia, HoraInicio, HoraFin)):-
    horario(Nombre, Horario),
    member(turno(Dia, HoraInicio, HoraFin), Horario).

atiende(vale, Turno):-
    atiende(dodain, Turno).
atiende(vale, Turno):-
    atiende(juanC, Turno).

% Por principio de universo cerrado, no agrego cuando nadie hace algo, ni cuando estan pensando en hacer algo pero aun no lo hace

estaAtendiendo(Persona, Dia, Hora):-
    atiende(Persona, turno(Dia, Inicio, Fin)),
    between(Inicio, Fin, Hora).

kiosquero(Persona):-
    horario(Persona, _).
kiosquero(vale). %% Para que solo ocurra una vez cada una lo hago con horarios

sola(Persona, Dia, Hora):-
    estaAtendiendo(Persona, Dia, Hora),
    kiosquero(OtraPersona),
    Persona\=OtraPersona,
    not(estaAtendiendo(OtraPersona, Dia, Hora)).

kiosqueros(Kiosqueros):-
    findall(Kiosquero, kiosquero(Kiosquero), Kiosqueros).

posiblesKiosqueros(Kiosqueros, Dia):-
    kiosqueros(Todos),
    auxiliarPosiblesKiosqueros(Kiosqueros, Dia, Todos).

auxiliarPosiblesKiosqueros([],_,[]).
auxiliarPosiblesKiosqueros([KiosqueroValido|Seleccion], Dia, [KiosqueroValido|Resto]):-
    estaAtendiendo(KiosqueroValido, Dia, _),
    auxiliarPosiblesKiosqueros(Seleccion, Dia, Resto).
auxiliarPosiblesKiosqueros(Seleccion, Dia ,[_|Resto]):-
    auxiliarPosiblesKiosqueros(Seleccion, Dia, Resto).







