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

struct DatoSLista
{
    int nroFact;
    float imp;
};
struct NodoS
{
   DatoSLista info;
   NodoS*sig;
};
struct Vendedor //DatoLista
{
    int codVend;
    NodoS*listaVtas;
};
struct Nodo
{
   Vendedor info;
   Nodo*sig;
};

void cargarLista(Nodo*&,FILE*avtas);
void listado(Nodo*);
void generarArchVend(Nodo*,FILE*av);
void insertar(NodoS*&lista,DatoSLista dato);
void listar(NodoS*lista);
float impTotal(NodoS*lista);
Nodo* buscarInsertar(Nodo*&lista,Vendedor al);

int main()
{
    FILE *archVtas,*archVend;
    Nodo* lista=NULL;
    archVtas=fopen("Ventas.dat","rb");
    if(archVtas!=NULL)
    {
        cargarLista(lista,archVtas);
        listado(lista); //punto a
        fclose(archVtas);
        archVend=fopen("VentasVendedor.dat","wb");
        if(archVend!=NULL)
        {
            generarArchVend(lista,archVend);  //punto b
            fclose(archVend);
        }
    }

    return 0;
}

void cargarLista(Nodo*&lista,FILE*avtas)
{
    RegArchVtas vta;
    DatoSLista d;
    Vendedor v;
    Nodo*p;
    fread(&vta,sizeof(RegArchVtas),1,avtas);
    while(!feof(avtas))
    {
        v.codVend=vta.codVendedor;
        v.listaVtas=NULL;
        p=buscarInsertar(lista,v);
        d.nroFact=vta.nroFact;
        d.imp=vta.importe;
        insertar(p->info.listaVtas,d);

        fread(&vta,sizeof(RegArchVtas),1,avtas);
    }
}

void listado(Nodo*lista)
{
    Nodo* p=lista;
    while(p!=NULL)
    {

            cout<<"El vendedor "<<p->info.codVend<<" realizo la siguientes ventas"<<endl;
            listar(p->info.listaVtas);
            p=p->sig;
    }
}

void generarArchVend(Nodo*lista,FILE*av)
{
    RegArchVtasVend vendedor;
    Nodo*p=lista;
    while(p!=NULL)
    {
        vendedor.codVendedor=p->info.codVend;
        vendedor.impTotal=impTotal(p->info.listaVtas);
        fwrite(&vendedor,sizeof(RegArchVtasVend),1,av);
        p=p->sig;
    }
}
//FUNCIONES DE LISTA
void insertar(NodoS*&lista,DatoSLista dato)
{
    NodoS *n,*p,*ant;
    n=new NodoS;
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

void listar(NodoS*lista)
{
    NodoS*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<"   Factura "<<p->info.nroFact<<" importe "<<p->info.imp<<endl;
        p=p->sig;
    }
}

float impTotal(NodoS*lista)
{
    float tot=0;
    NodoS*p;
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
        v[i]==NULL;
}

Nodo* buscarInsertar(Nodo*&lista,Vendedor al)
{
    Nodo*ant,*r=lista;
    while(r!=NULL && r->info.codVend<al.codVend)
    {
        ant=r;
        r=r->sig;
    }

    if(r==NULL || r->info.codVend!=al.codVend) //no está en la lista
    {
        Nodo*p=new Nodo;
        p->info=al;
        p->sig=r;
        if(r!=lista)
            ant->sig=p;
        else
            lista=p;
        return p;
    }
    else
        return r;
}


