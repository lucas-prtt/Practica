#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
struct parcial
{
    int dni;
    int nota;
};
void crearArchivo1(int j);
void corteControl(FILE*);
main()
{
    int r;
    cout << "Cuantos?\n";
    cin >> r;
    crearArchivo1(r);
    FILE * arch = fopen("Parcial 1.dat", "r");
    corteControl(arch);
    getch();
    return 0;
}
void corteControl(FILE * arch){
    parcial a;
    parcial b;
    int suma, cant, promedio;
    fread(&a, sizeof(a), 1, arch);
    while(!feof(arch)){
        cout<<"Notas de "<<a.dni<<":\n";
        suma=a.nota;
        cout<<"-"<<a.nota<<"\n";
        cant=1;
        fread(&b, sizeof(b), 1, arch);
        while(a.dni==b.dni and !feof(arch)){
            cout<<"-"<<b.nota<<"\n";
            suma+=b.nota;
            cant++;
            fread(&b, sizeof(b), 1, arch);
            
        }
        promedio=suma/cant;
        cout<<"--Promedio: "<<promedio<<"\n\n";
        a=b;
    }
}

void crearArchivo1(int j)
{
    parcial temp;
    if (j > 0)
    {
        FILE *arch;
        arch = fopen("Parcial 1.dat", "w");
        for (int i = 0; i < j; i++)
        {
            cout << "DNI: ";
            cin >> temp.dni;
            cout << "NOTA: ";
            cin >> temp.nota;
            fwrite(&temp, sizeof(temp), 1, arch);
        }
        fclose(arch);
    }

    return;
}