
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

viaja(martu, Lugar):-
    viaja(nico, Lugar),
    viaja(alf, Lugar).
% Independientemente de que no se haya definido a donde viaja nico, este predicado permite definir a donde viajara martu

% Como Juan no sabe a donde ir no se lo puede incluir

% Como Carlos no viaja, por principio de universo cerrado se lo excluye y se tomara como falso cualquier consulta de viaja que se le haga



%%%%%%%%%%%%%
%% Punto 2 %%
%%%%%%%%%%%%%











