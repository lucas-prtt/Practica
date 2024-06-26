madreDe(edwina, abbie).
madreDe(mona, homero).
madreDe(gaby, herbert).
madreDe(jacqueline, marge).
madreDe(jacqueline, patty).
madreDe(jacqueline, selma).
madreDe(marge, bart).
madreDe(marge, hugo).
madreDe(marge, lisa).
madreDe(marge, maggie).
madreDe(selma, ling).
padreDe(abe, abbie).
padreDe(abe, homero).
padreDe(abe, herbert).
padreDe(clancy, marge).
padreDe(clancy, patty).
padreDe(clancy, selma).
padreDe(homero, bart).
padreDe(homero, hugo).
padreDe(homero, lisa).
padreDe(homero, maggie).

tieneHijo(Persona):-
    padreDe(Persona, _).
tieneHijo(Persona):-
    madreDe(Persona, _).

compartenPadre(UnaPersona, OtraPersona):-
    padreDe(SuPadre, UnaPersona),
    padreDe(SuPadre, OtraPersona).

compartenMadre(UnaPersona, OtraPersona):-
    madreDe(SuMadre, UnaPersona),
    madreDe(SuMadre, OtraPersona).

hermanos(UnaPersona, SuHermano):-
    compartenPadre(UnaPersona, SuHermano),
    compartenMadre(UnaPersona, SuHermano).

medioHermanos(UnaPersona, SuMedioHermano):-
    compartenPadre(UnaPersona, SuMedioHermano),
    not(compartenMadre(UnaPersona, SuMedioHermano)).
medioHermanos(UnaPersona, SuMedioHermano):-
    compartenMadre(UnaPersona, SuMedioHermano),
    not(compartenPadre(UnaPersona, SuMedioHermano)).

padreOMadre(Persona, Hijo):-
    padreDe(Persona, Hijo).
padreOMadre(Persona, Hijo):-
    madreDe(Persona, Hijo).

%Para simplificar, son paraja si tuvieron un mismo hijo los dos
pareja(Persona, Conyuge):-
    padreOMadre(Persona, Hijo),
    padreOMadre(Conyuge, Hijo).
    

tioDe(Tio, Sobrino):-
    padreDe(PadreDeSobrino, Sobrino),
    hermanos(PadreDeSobrino, Tio).
tioDe(Tio, Sobrino):-
    pareja(Tio, Pareja),
    padreDe(PadreDeSobrino, Sobrino),
    hermanos(PadreDeSobrino, Pareja).
abueloMultiple(Abuelo):-
    abuelo(Abuelo, Nieto1),
    abuelo(Abuelo, Nieto2),
    Nieto1 \= Nieto2.
abuelo(Abuelo, Nieto):-
    padreOMadre(Abuelo, Hijo),
    padreOMadre(Hijo, Nieto).
cuniado(Cuniado, SuCuniado):-
    pareja(SuCuniado, ParejaDeCuniado),
    hermanos(ParejaDeCuniado, Cuniado).
suegro(Suegro, Persona):-
    pareja(Persona, Pareja),
    madreDe(Suegro, Pareja).
conSuegro(ConSuegro, Persona):-
    padreOMadre(Persona, Hijo),
    suegro(Hijo, ConSuegro).
yerno(Yerno, Persona):-
    pareja(Yerno, Pareja),
    padreOMadre(Persona, Pareja),
    padreDe(Yerno, _).
nuera(Nuera, Persona):-
    pareja(Nuera, Pareja),
    padreOMadre(Persona, Pareja),
    madreDe(Nuera, _).
primo(Primo, Persona):-
    tioDe(Tio, Persona),
    padreOMadre(Tio, Primo).


descendiente(Persona, Antepasado):-
    padreOMadre(Antepasado, Persona).
descendiente(Persona, Antepasado):-
    padreOMadre(Antepasado, SuHijo),
    descendiente(Persona, SuHijo).


