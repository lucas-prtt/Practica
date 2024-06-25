energia(cajaPuerta).

energia(Aparato):-
    conectados(Fuente, Aparato),
    energia(Fuente).




conexion(cajaPuerta, lampara1).
conexion(lampara1, lampara2).
conexion(lampara2, dosTomacorrientesVacios).
conexion(lampara2, lucesDeAfuera).
conexion(lampara2, lavarropas).
conexion(tomaCorrientesBajoFreezer, tomaCorrientesHeladerita).
conexion(lampara1, tomaCorrientesBajoHeladerita).
conexion(freezer, lampara2).

%Asi tampoco anda
conectados(A, B):-
    conexion(B, A).
conectados(A, B):-
    conexion(A, B).
%No se como hacer que deje de ananlizar infinitamente

cortoCircuito(Aparato):-
    conectados(Aparato, Corto),
    cortoCircuito(Corto).

luz(Aparato):-
    energia(Aparato),
    not(cortoCircuito(Aparato)).





