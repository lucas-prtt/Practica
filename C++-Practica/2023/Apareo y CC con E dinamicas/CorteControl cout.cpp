#include <iostream>
#include <conio.h>

struct nodolista
{
    int dato;
    nodolista *sig;
};
struct resumenlistanodo{
    int dato;
    int cantidad;
    resumenlistanodo * sig;
};

void cortecontrol(nodolista *input);
void insertar(nodolista *&lista, int numero);
void mostrar(nodolista *lista);
void mostrar(resumenlistanodo *lista);
void agregar(nodolista *&lista, int a);

using namespace std;
main()
{
    int a;
    nodolista *lista1 = NULL;
    resumenlistanodo * resumen = NULL;
    cout << "Lista 1:\n";
    do
    {
        cin >> a;
        insertar(lista1, a);
    } while (a != 0);
    cout << "\nLista 1:\n";
    mostrar(lista1);
    /*
    cout << "\nLista 2:\n";
    mostrar(lista2);*/
    cout << "\nCortecontrol de listas:\n";
    cortecontrol(lista1);
    mostrar(resumen);
    getch();
    return 0;
}

void insertar(nodolista *&lista, int numero)
{
    nodolista *p, *ant, *n;
    n = new nodolista;
    n->dato = numero;
    p = lista;
    while (p != NULL and p->dato < n->dato)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p == lista)
    {
        lista = n;
    }
    else
    {
        ant->sig = n;
    }
}
void mostrar(nodolista *lista)
{
    nodolista *p = lista;
    while (p != NULL)
    {
        cout << p->dato;
        if (p->sig != NULL)
            cout << " - ";
        p = p->sig;
    }
}
void mostrar(resumenlistanodo *lista)
{
    resumenlistanodo *p = lista;
    while (p != NULL)
    {
        cout << p->dato<<": "<<p->cantidad;
        if (p->sig != NULL)
            cout << " - ";
        p = p->sig;
    }
}

void cortecontrol(nodolista *input)
{
    nodolista *a = input, *b;
    int cantidad;

    while (a != NULL)
    {   cantidad = 0;
        b = a;
        while (b!=NULL and b->dato == a->dato)
        {   
            cantidad++;
            b = b->sig;
        }
        cout<<a->dato<<": "<<cantidad<< " - ";
        a = b;
    }
}
