#include <iostream>
#include <stdio.h>


using namespace std;

struct RegArchVtas
{
    int nroFact;
    int codVendedor;
    float importe;
};

struct RegArchVtasVend
{
    int codVendedor;
    float impTotal;
};

struct DatoLista
{
    int nroFact;
    float imp;
};
struct Nodo
{
   DatoLista info;
   Nodo*sig;
};

void cargarVector(Nodo*v[],FILE*avtas);
void listado(Nodo*vec[],int n);
void generarArchVend(Nodo*v[],int n,FILE*av);
void inicializaVec(Nodo*v[],int t);
void insertar(Nodo*&lista,DatoLista dato);
void listar(Nodo*lista);
float impTotal(Nodo*lista);
void inicializaVec(Nodo*v[],int t);

int main()
{
    FILE *archVtas,*archVend;
    Nodo* vecVend[10];
    archVtas=fopen("Ventas.dat","rb");
    if(archVtas!=NULL)
    {
        inicializarVec(vecVend,10);
        cargarVector(vecVend,archVtas);
        listado(vecVend,10); //punto a
        fclose(archVtas);
        archVend=fopen("VentasVendedor.dat","wb");
        if(archVend!=NULL)
        {
            generarArchVend(vecVend,10,archVend);  //punto b
            fclose(archVend);
        }
    }

    return 0;
}

void cargarVector(Nodo*v[],FILE*avtas)
{
    RegArchVtas vta;
    DatoLista d;
    fread(&vta,sizeof(RegArchVtas),1,avtas);
    while(!feof(avtas))
    {
        d.nroFact=vta.nroFact;
        d.imp=vta.importe;
        insertar(v[vta.codVendedor-1],d);

        fread(&vta,sizeof(RegArchVtas),1,avtas);
    }
}

void listado(Nodo*vec[],int n)//muestra solo los vendedores que hicieron ventas
{
    for(int i=0;i<n;i++)
    {
        if(vec[i]!=NULL)
        {
            cout<<"El vendedor "<<i+1<<" realizo la siguientes ventas"<<endl;
            listar(vec[i]);
        }
    }
}

void generarArchVend(Nodo*v[],int n,FILE*av) //si un vendedor no hizo hizo ventas lo guarda con importe 0
{
    RegArchVtasVend vendedor;
    for(int i=0;i<n;i++)
    {
        vendedor.codVendedor=i+1;
        vendedor.impTotal=impTotal(v[i]);
        fwrite(&vendedor,sizeof(RegArchVtasVend),1,av);
    }
}
//FUNCIONES DE LISTA
void insertar(Nodo*&lista,DatoLista dato)
{
    Nodo *n,*p,*ant;
    n=new Nodo;
    n->info=dato;
    p=lista;
    while(p!=NULL && p->info.imp > dato.imp)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=lista)
        ant->sig=n;
    else
        lista=n;
}

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<"   Factura "<<p->info.nroFact<<" importe "<<p->info.imp<<endl;
        p=p->sig;
    }
}

float impTotal(Nodo*lista)
{
    float tot=0;
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        tot+=p->info.imp;
        p=p->sig;
    }
    return tot;
}
//

void inicializaVec(Nodo*v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=NULL;
}
