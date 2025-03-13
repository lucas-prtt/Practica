% Acá va el código



%%%%%%%%%%%%%%
%% REGISTRO %%
%%%%%%%%%%%%%%

%  usuario(Nombre, Edad, Genero).
%  rangoEtario(Nombre, rango(Minimo, Maximo)).
%  preferenciaDeGenero(Nombre, [Genero]).
%  gustos(Nombre, [Gustos], [Disgustos]).




%Ejemplos
usuario(jose, 21, masculino).
usuario(ana, 20, femenino).
usuario(pedro, 18, noBinario).
usuario(sofia, 23, femenino).
usuario(leandro, 30, masculino).
usuario(miguel, 17, masculino).
usuario(manuel, 43, masculino).
rangoEtario(jose, rango(19, 23)).
rangoEtario(ana, rango(18, 25)).
rangoEtario(pedro, rango(18, 21)).
rangoEtario(sofia, rango(28, 72)).
rangoEtario(leandro, rango(90, 110)).
rangoEtario(miguel, rango(16, 17)).
rangoEtario(manuel, rango(20, 40)).
preferenciaDeGenero(jose, [femenino]).
preferenciaDeGenero(ana, [masculino, femenino, noBinario]).
preferenciaDeGenero(miguel, [femenino, noBinario]).
preferenciaDeGenero(sofia, [masculino, noBinario]).
preferenciaDeGenero(manuel, [masculino]).
gustos(jose, [futbol, basquet, hockey, cocina, videojuegos], [dormir, estudiar, leer, caminar, irAlMedico]).
gustos(ana, [leer, escribir, futbol, dormir, correr], [estudiar, basquet, caminar, videojuegos, irAlMedico]).
gustos(miguel, [leer, escribir, futbol, dormir, bailar], [estudiar, cocinar, caminar, videojuegos, irAlMedico]).
gustos(sofia, [futbol, surf, hockey, cocina, videojuegos], [dormir, estudiar, leer, caminar, irAlMedico]).
gustos(manuel, [futbol, tenis, hockey, cocina, videojuegos], [dormir, estudiar, leer, caminar, irAlMedico]).



%%  Modelo la ausencia de datos como la ausencia de una de las clausulas para determinada persona.
%%  En el caso de los gustos, si faltara, por ejemplo, los gustos pero no los disgustos (o viceversa), se pondría una lista vacia para el campo faltante.
%%  El rango etario esta puesto con un functor para forzar la existencia de los dos valores (Minimo y Maximo) de manera simultanea


perfilIncompleto(Persona):-
    usuario(Persona, Edad, _),
    Edad < 18.
perfilIncompleto(Persona):-
    nombreDeUsuario(Persona),
    not(perfilCompleto(Persona)).


nombreDeUsuario(Nombre):-
    usuario(Nombre, _, _).

perfilCompleto(Persona):-
    rangoEtario(Persona, _),
    preferenciaDeGenero(Persona, _),
    gustos(Persona, Gustos, Disgustos),
    alMenosCinco(Gustos),
    alMenosCinco(Disgustos).

alMenosCinco(Lista):-
    length(Lista, Longitud),
    Longitud>=5.




%%%%%%%%%%%%%%
%% Analisis %%
%%%%%%%%%%%%%%



almaLibre(Persona):-
    nombreDeUsuario(Persona),
    forall(usuario(_, _, Genero), leGustaEseGenero(Persona, Genero)).

almaLibre(Persona):-
    rangoEtario(Persona, rango(Minimo, Maximo)),
    Rango is Maximo - Minimo,
    Rango>30.

leGustaEseGenero(Persona, GeneroAEvaluar):-
    preferenciaDeGenero(Persona, GenerosPreferidos),
    member(GeneroAEvaluar, GenerosPreferidos).

%%

quiereLaHerencia(Persona):-
    usuario(Persona, Edad, _),
    rangoEtario(Persona, rango(Minimo, _)),
    Diferencia = Minimo-Edad,
    Diferencia >=30.

%%

indeseable(Persona):-
    nombreDeUsuario(Persona),
    not(pretendienteDe(_, Persona)).



%%%%%%%%%%%%%
%% MATCHES %%
%%%%%%%%%%%%%


pretendienteDe(Pretendiente, Pretendido):-
    edadCompatible(Pretendiente, Pretendido),    %%Personas generadas por edadCompatible
    generoCompatible(Pretendiente, Pretendido),
    gustoEnComun(Pretendiente, Pretendido), 
    Pretendiente \= Pretendido.

edadCompatible(Pretendiente, Pretendido):-
    rangoEtario(Pretendiente, rango(Min, Max)),
    usuario(Pretendido, Edad, _),
    between(Min, Max, Edad).

generoCompatible(Pretendiente, Pretendido):-
    usuario(Pretendido, _, Genero),
    leGustaEseGenero(Pretendiente, Genero). %% Reutilizada de alma libre

gustoEnComun(UnaPersona, OtraPersona):-
    cosasQueLeGustan(UnaPersona, GustosDeUnaPersona),
    cosasQueLeGustan(OtraPersona, GustosDeOtraPersona),
    listasCompartenUnElemento(GustosDeOtraPersona, GustosDeUnaPersona).

cosasQueLeGustan(Persona, Gustos):-
    gustos(Persona,  Gustos, _).

listasCompartenUnElemento(Lista1, Lista2):-
    member(ElementoComun, Lista1),
    member(ElementoComun, Lista2).

%%

hayMatch(UnaPersona, OtraPersona):-
    pretendienteDe(UnaPersona, OtraPersona),
    pretendienteDe(OtraPersona, UnaPersona).

%%

trianguloAmoroso(Vertice1, Vertice2, Vertice3):-  
    pretendienteUnidireccional(Vertice1, Vertice2),
    pretendienteUnidireccional(Vertice2, Vertice3),
    pretendienteUnidireccional(Vertice3, Vertice1).

pretendienteUnidireccional(Pretendiente, Pretendido):-
    pretendienteDe(Pretendiente, Pretendido),
    not(pretendienteDe(Pretendido, Pretendiente)).

% Los vertices son nombres de personas, pero se me hace mas expresivo
% referirme a las personas del triangulo como sus vertices

%%

unoParaElOtro(UnaPersona, OtraPersona):-
    hayMatch(UnaPersona, OtraPersona),
    not(odiaUnGustoDe(UnaPersona, OtraPersona)),
    not(odiaUnGustoDe(OtraPersona, UnaPersona)).

odiaUnGustoDe(AquelQueLeGustaAlgo, AquelQueLeDisgustaAlgo):-
    cosasQueLeGustan(AquelQueLeGustaAlgo, Gustos),
    cosasQueLeDisgustan(AquelQueLeDisgustaAlgo, Disgustos),
    listasCompartenUnElemento(Gustos, Disgustos).

cosasQueLeDisgustan(Persona, Disgustos):-
    gustos(Persona, _, Disgustos).


%%%%%%%%%%%%%%
%% MENSAJES %%
%%%%%%%%%%%%%%

%% indiceDeAmor(Emisor, Receptor, Indice).
indiceDeAmor(ana, jose, 4).
indiceDeAmor(jose, ana, 10).
indiceDeAmor(jose, ana, 8).
indiceDeAmor(ana, pedro, 2).
indiceDeAmor(jose, sofia, 3).
indiceDeAmor(manuel, jose, 7).

desbalance(UnaPersona, OtraPersona):-           %% Es inversible pues esMasAmorosoQue genera las personas
    esMasAmorosoQue(UnaPersona, OtraPersona).
desbalance(UnaPersona, OtraPersona):-
    esMasAmorosoQue(OtraPersona, UnaPersona).

esMasAmorosoQue(Amoroso, Serio):-
    nombreDeUsuario(Amoroso),
    nombreDeUsuario(Serio),
    promedioIndiceDeAmor(Amoroso, Serio, PromedioAmoroso),
    promedioIndiceDeAmor(Serio, Amoroso, PromedioSerio),
    DobleDePromedioSerio is PromedioSerio * 2,
    DobleDePromedioSerio < PromedioAmoroso.

promedioIndiceDeAmor(Emisor, Receptor, Promedio):-
    findall(Indice, indiceDeAmor(Emisor, Receptor, Indice), ListaDeIndices),
    length(ListaDeIndices, CantidadDeMensajes),
    CantidadDeMensajes\=0, %% Para que no tire error al dividir por cero si no hay mensajes
    sumlist(ListaDeIndices, SumatoriaDeIndices),
    Promedio is SumatoriaDeIndices / CantidadDeMensajes.

%%

ghostea(Fantasma, Ignorado):-
    nombreDeUsuario(Fantasma),
    nombreDeUsuario(Ignorado),
    indiceDeAmor(Ignorado, Fantasma, _),
    not(indiceDeAmor(Fantasma, Ignorado, _)).



