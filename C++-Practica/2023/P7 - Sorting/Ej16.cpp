#include <iostream>
#include <conio.h>
using namespace std;

struct producto
{
    int rubro;
    int producto;
    string desc;
};

void ingresardatos(producto[], int &q);
void ordenar(producto[], int q);

main(){
producto productos[100];
int q=100;
ingresardatos(productos, q);
ordenar(productos, q);
for (int i=0; i<q; i++){cout<<"\n "<<productos[i].producto<<"//"<<productos[i].desc<<"//"<<productos[i].rubro;}
}




void ingresardatos(producto vector[], int &q)
{
    int total=0;
    for(int i=0; i<q; i++)
    {   char r;
        cout<<"Ingrese el id de producto:\n";
        cin>>vector[i].producto;
        cout<<"Ingrese el id de rubro:\n";
        cin>>vector[i].rubro;
        cout<<"Ingrese la descripción sin utilizar espacios:\n";
        cin>>vector[i].desc;
        total++;
        cout<<"Quiere ingresar otro producto mas?\nS/N\n";
        do{
            r=getch();
            if(r=='N' or r=='n'){q=total;}
        }while(r!='N' and r!='S' and r!='s' and r!='n');
    }
    q=total;
}

void ordenar(producto vector[], int q)
{
    for (int i=0; i<q-1; i++)
    {
        for(int k=0; k<q-1-i; k++)
        {
            if(vector[k].rubro>vector[k+1].rubro)
            {
                producto temp = vector[k];
                vector[k]=vector[k+1];
                vector[k+1]=temp;
            }

        }
    }
}