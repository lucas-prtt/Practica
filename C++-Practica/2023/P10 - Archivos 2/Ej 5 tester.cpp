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
main()
{
    srand(time(NULL));
    FILE *inscripciones = fopen("MAESTROFINALES.DAT", "w");
    FILE *finalesHoy = fopen("DIAFINALES.DAT", "w");
    final input;
    cout << "Cantidad:";
    int k;
    cin >> k;
    cout << "\n";
    for (int i = 0; i < k; i++)
    {
        int q=rand()%2;
        cout<<"\nHacia la lista "<<q+1;
        cout << "\n\nIngreso " << i + 1 << "\n\nCodigo: ";
            cin >> input.codigoMateria;
        while (!cin){            
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input.codigoMateria;};
        cout << "Legajo: ";
        do
        {
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input.numeroLegajo;
        } while (!cin);
        cout << "Nombre y Apellido: ";
        fflush(stdin);
        cin.getline(input.nombreApellido, 100, '\n');
        fflush(stdin);
        if (q)
        {
            fwrite(&input, sizeof(input), 1, inscripciones);
        }
        else
        {
            fwrite(&input, sizeof(input), 1, finalesHoy);
        }
    }
}