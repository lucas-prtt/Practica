

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






