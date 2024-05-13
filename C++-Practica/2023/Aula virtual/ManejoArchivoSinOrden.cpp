#include <iostream>
#include <stdio.h>
#include <string.h>

//archivo de productos, búsqueda secuencial, modicación, mostrar
using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

void mostrar(FILE*a);
int busquedaSecuencial(FILE*a,int unCod,Producto&);
void esta(char nomA[],int unCod);
void sumaStock(char nomA[],int unCod,int cantASumar);
void consulta(char nomA[],int unCod);

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

        esta(nomArch,300);

        consulta(nomArch,521);

        //sumaStock(nomArch,124,20);

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

int busquedaSecuencial(FILE*a,int unCod,Producto &prod)
{
    int c=0;
    fread(&prod,sizeof(Producto),1,a);
    while(!feof(a) && prod.codigo!=unCod)
    {
        c++;
        fread(&prod,sizeof(Producto),1,a);
    }
    if(feof(a))
        return -1;
    else
        return c;
}

void esta(char nomA[],int unCod)
{
    Producto p;
    FILE*arch=fopen(nomA,"rb");
    if(busquedaSecuencial(arch,unCod,p)==-1)
        cout<<unCod<<" no esta"<<endl;
    else
        cout<<unCod<<" esta"<<endl;
    fclose(arch);
}

void sumaStock(char nomA[],int unCod,int cantASumar)
{
    Producto prod;
    FILE*arch=fopen(nomA,"rb+");
    int pos=busquedaSecuencial(arch,unCod,prod);
    if(pos!=-1)
    {
        /*
        fseek(arch,pos*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,arch);
        prod.stock+=cantASumar;
        fseek(arch,-sizeof(Producto),SEEK_CUR);
        fwrite(&prod,sizeof(Producto),1,arch);
        */
        prod.stock+=cantASumar;
        fseek(arch,pos*sizeof(Producto),SEEK_SET);
        fwrite(&prod,sizeof(Producto),1,arch);
    }
    fclose(arch);
}

void consulta(char nomA[],int unCod)
{
    Producto prod;
    FILE*arch=fopen(nomA,"rb");
    /*
    int pos=busquedaSecuencial(arch,unCod);
    if(pos!=-1)
    {
        fseek(arch,pos*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,arch);
        cout<<prod.codigo<<" "<<prod.stock<<endl;
    }
    */
    if(busquedaSecuencial(arch,unCod,prod)!=-1)
        cout<<prod.codigo<<" "<<prod.stock<<endl;

    fclose(arch);
}

