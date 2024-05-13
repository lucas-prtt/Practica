#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;

struct inscripto
{
    int dni;
    char nombreyapellido[100];
    int codigo;
    float ingreso;
};
struct credito
{
    int codigo;
    char desc[100];
    int otorgados;
};

main()
{
    srand(time(NULL));
    cout << " Inicio\n\n\n";
    int cantinsc = 100;
    int cantcreds = 10;
    int codigospresentes[cantcreds];
    inscripto tempinsc;
    credito tempcred[cantcreds];
    FILE *cods = fopen("Creditos.dat", "w");
    FILE *insc = fopen("Inscriptos.dat", "w");
    for (int i = 0; i < cantcreds; i++)
    {
        tempcred[i].codigo = rand() % 45;
        codigospresentes[i] = tempcred[i].codigo;
        tempcred[i].otorgados = rand() % 370;
        strcpy(tempcred[i].desc, "Codigo");

    }

    for(int i = 0; i<cantcreds; i++){
        for(int q = 0; q<(cantcreds-i-1); q++){
            if(tempcred[q].codigo<tempcred[q+1].codigo){
                credito aux = tempcred[q];
                tempcred[q] = tempcred[q+1];
                tempcred[q+1] = aux;
            }
        }
    }

    for (int i = 0; i < cantinsc; i++)
    {
        tempinsc.codigo = codigospresentes[rand() % 20];
        tempinsc.dni = rand() % 60000000;
        tempinsc.ingreso = pow(rand() % 90, 3) + 95000;
        strcpy(tempinsc.nombreyapellido, "Juan");
        fwrite(&tempinsc, sizeof(tempinsc), 1, insc);
    }
    fseek(cods, 0, 0);
    for (int i=0; i<cantcreds; i++){
    fwrite(&tempcred[i], sizeof(credito), 1, cods);
    }

    getch();
    return 0;
}