energia(cajaPuerta).

energia(Aparato):-
    conexion(Fuente, Aparato),
    energia(Fuente).


%conexion(A, B):-
%   conexion(B, A).
% Esto por algun motivo no anda bien.
conexion(cajaPuerta, lampara1).
conexion(lampara1, lampara2).
conexion(lampara2, dosTomacorrientesVacios).
conexion(lampara2, lucesDeAfuera).
conexion(lampara2, lavarropas).
conexion(tomaCorrientesBajoFreezer, tomaCorrientesHeladerita).
conexion(lampara1, tomaCorrientesBajoHeladerita).
conexion(freezer, lampara2).

cortoCircuito(Aparato):-
    conexion(Aparato, Corto),
    cortoCircuito(Corto).

luz(Aparato):-
    energia(Aparato),
    not(cortoCircuito(Aparato)).





