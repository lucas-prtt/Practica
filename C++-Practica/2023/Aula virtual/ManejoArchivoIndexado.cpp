#include <iostream>
#include <stdio.h>
#include <string.h>

//archivo de productos, consulta, modicación, con acceso directo
using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

void mostrar(FILE*a);
int busquedaSecuencial(FILE*a,int unCod,Producto &prod);
void esta(char nomA[],int unCod);
void sumaStock(char nomA[],int unCod,int cantASumar);

int main()
{
    char nomArch[21];
    cout<<"Ingrese el nombre del archivo: ";
    cin>>nomArch;
    strcat(nomArch,".dat");

    FILE *archivo=fopen(nomArch,"rb");
    if(archivo==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        mostrar(archivo);
        fclose(archivo);

        esta(nomArch,8);

        consulta(nomArch,9);

        sumaStock(nomArch,3,50);

        archivo=fopen(nomArch,"rb");
        mostrar(archivo);
        fclose(archivo);
    }


    return 0;
}

void mostrar(FILE*a)
{
    Producto prod;
    fread(&prod,sizeof(Producto),1,a);
    while(!feof(a))
    {
        cout<<prod.codigo<<"    "<<prod.stock<<endl;
        fread(&prod,sizeof(Producto),1,a);
    }
}


void esta(char nomA[],int unCod)
{
    Producto p;
    FILE*arch=fopen(nomA,"rb");
    fseek(arch,(unCod-1)*sizeof(Producto),SEEK_SET);
    fread(&p,sizeof(Producto),1,arch);
    if(p.codigo!=unCod)
         cout<<unCod<<" no esta"<<endl;
    else
        cout<<unCod<<" esta"<<endl;
    fclose(arch);
}

void sumaStock(char nomA[],int unCod,int cantASumar)
{
    Producto p;
    FILE*arch=fopen(nomA,"rb+");
    fseek(arch,(unCod-1)*sizeof(Producto),SEEK_SET);
    fread(&p,sizeof(Producto),1,arch);
    if(p.codigo==unCod)
    {
        p.stock+=cantASumar;
        //fseek(arch,(unCod-1)*sizeof(Producto),SEEK_SET);
        fseek(arch,-sizeof(Producto),SEEK_CUR);
        fwrite(&p,sizeof(Producto),1,arch);
    }
    fclose(arch);
}

void cosulta(char nomA[],int unCod)
{
   Producto p;
    FILE*arch=fopen(nomA,"rb");
    fseek(arch,(unCod-1)*sizeof(Producto),SEEK_SET);
    fread(&p,sizeof(Producto),1,arch);
    if(p.codigo==unCod)
        cout<<p.codigo<<" "<<p.stock<<endl;
    fclose(arch);
}

