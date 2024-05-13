#include <stdio.h>
#include <iostream>
#include <conio.h>


struct final
{
    int numeroLegajo;
    int codigoMateria;
    char nombreApellido[100];
};

using namespace std;
void mostrar(final);
main()
{
    final insc;
    final hoy;
    FILE *inscripciones = fopen("MAESTROFINALES.DAT", "r");
    FILE *finalesHoy = fopen("DIAFINALES.DAT", "r");
    FILE *apareo = fopen("FINALESACT.DAT", "w");
    fread(&insc, sizeof(final), 1, inscripciones);
    fread(&hoy, sizeof(final), 1, finalesHoy);
    while (!feof(inscripciones) and !feof(finalesHoy))
    {
        if (insc.numeroLegajo == hoy.numeroLegajo)
        {
            if (insc.codigoMateria < hoy.codigoMateria)
            {
                mostrar(insc);
                fread(&insc, sizeof(final), 1, inscripciones);
            }
            else if(insc.codigoMateria>hoy.codigoMateria)
            {
                mostrar(hoy);
                fread(&hoy, sizeof(final), 1, finalesHoy);
            }else{
                mostrar(hoy);//o insc, es lo mismo.
                fread(&hoy, sizeof(final), 1, finalesHoy);
                fread(&insc, sizeof(final), 1, inscripciones);
            }
        }
        else if (insc.numeroLegajo < hoy.numeroLegajo)
        {
            mostrar(insc);
            fread(&insc, sizeof(final), 1, inscripciones);
        }
        else
        {
            mostrar(hoy);
            fread(&hoy, sizeof(final), 1, finalesHoy);
        }
    }
    while(!feof(finalesHoy)){
        mostrar(hoy);
        fread(&hoy, sizeof(final), 1, finalesHoy);
    }
    while(!feof(inscripciones)){
        mostrar(insc);
        fread(&insc, sizeof(final), 1, inscripciones);
    }
}
void mostrar(final a)
{
    cout << "\n"<< a.numeroLegajo << "--" << a.codigoMateria << "--" << a.nombreApellido;
    return;
}