#include <iostream>
#include <stdio.h>
#include <string.h>

//archivo de productos, b�squeda binaria, modicaci�n, mostrar
using namespace std;

struct estructura
{
    int codigo;
    int dato;
};

void mostrar(FILE*a);
int busquedaBinaria(FILE*a,int unCod,Producto &prod);
void esta(char nomA[],int unCod);
void sumaStock(char nomA[],int unCod,int cantASumar);
int cantReg(FILE*arch);
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
        cout<<"Cantidad de registros "<<cantReg(archivo)<<endl;
        fclose(archivo);

        esta(nomArch,300);

        consulta(nomArch,214);

        sumaStock(nomArch,748,50);

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

int busquedaBinaria(FILE*a,int codigobuscado)
{
    estructura lectura;
    int desde = 0,hasta,medio,pos = -1;   
    fseek(a,0,SEEK_END);
    hasta = (ftell(a)/sizeof(estructura))-1;
    fseek(a, 0, SEEK_SET);
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(a,medio*sizeof(estructura),SEEK_SET);
        fread(&lectura,sizeof(estructura),1,a);
        if(codigobuscado==lectura.codigo)
            pos=medio;
        else
        {
            if(codigobuscado<lectura.codigo)
               hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}


void esta(char nomA[],int unCod)
{
    Producto p;
    FILE*arch=fopen(nomA,"rb");
    if(busquedaBinaria(arch,unCod,p)==-1)
        cout<<unCod<<" no esta"<<endl;
    else
        cout<<unCod<<" esta"<<endl;
    fclose(arch);
}

void sumaStock(char nomA[],int unCod,int cantASumar)
{
    Producto prod;
    FILE*arch=fopen(nomA,"rb+");
    int pos=busquedaBinaria(arch,unCod,prod);
    if(pos!=-1)
    {
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
    if(busquedaBinaria(arch,unCod,prod)!=-1)
        cout<<prod.codigo<<" "<<prod.stock<<endl;

    fclose(arch);
}

int cantReg(FILE*arch)
{
    fseek(arch,0,SEEK_END);
    return ftell(arch)/sizeof(Producto);
}
