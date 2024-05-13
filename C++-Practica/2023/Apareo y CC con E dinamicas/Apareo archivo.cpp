#include <iostream>
#include <conio.h>

void ordenar(FILE *);
void apareo(FILE *, FILE *, FILE *);

using namespace std;
main()
{
    FILE *arch1 = fopen("arch1", "wb+");
    FILE *arch2 = fopen("arch2", "wb+");
    int a;
    cout << "Archivo 1:\n";
    do
    {
        cin >> a;
        fwrite(&a, sizeof(a), 1, arch1);
    } while (a != 0);
    cout << "Archivo 2:\n";
    do
    {
        cin >> a;
        fwrite(&a, sizeof(a), 1, arch2);
    } while (a != 0);
    ordenar(arch1);
    ordenar(arch2);
    getch();
    return 0;
}

void apareo(FILE *archivo1, FILE *archivo2){
    fseek(archivo1, 0, 2);
    int size1 = ftell(archivo1);
    fseek(archivo1, 0, 0);
    fseek(archivo2, 0, 2);
    int size2 = ftell(archivo2);
    fseek(archivo2, 0, 0);
    int a, b;
    while(ftell(archivo1)!=size1 and ftell(archivo2)!=size2){

    }
}



void ordenar(FILE *archivo)
{
    fseek(archivo, 0, 2);
    int size = ftell(archivo);
    fseek(archivo, 0, 0);
    int a, b;
    int j = 0;
    while (j<size)
    {
        fseek(archivo, 0, 0);
        while (ftell(archivo)<size-j)
        {
            if(ftell(archivo)!=0)
            fseek(archivo, -sizeof(int), 1);
            fread(&a, sizeof(a), 1, archivo);
            fread(&b, sizeof(a), 1, archivo);
            if (b < a)
            {
                fseek(archivo, -2 * sizeof(int), 1);
                fwrite(&b, sizeof(b), 1, archivo);
                fwrite(&a, sizeof(a), 1, archivo);
            }
            fseek(archivo, 0, 1);
        }
        j+=sizeof(a);
    }
}
