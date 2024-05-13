#include <iostream>
#include <conio.h>

struct nodolista
{
    int dato;
    nodolista *sig;
};

void apareo(nodolista *input1, nodolista *input2);
void insertar(nodolista *&lista, int numero);
void mostrar(nodolista *lista);
void agregar(nodolista *& lista, nodolista *&puntero, int a);

using namespace std;
main()
{
    int a;
    nodolista *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;
    cout << "Lista 1:\n";
    do
    {
        cin >> a;
        insertar(lista1, a);
    } while (a != 0);
    cout << "Lista 2:\n";
    do
    {
        cin >> a;
        insertar(lista2, a);
    } while (a != 0);
    cout << "\nLista 1:\n";
    mostrar(lista1);
    cout << "\nLista 2:\n";
    mostrar(lista2);
    cout << "\nApareo de listas:\n";
    apareo(lista1, lista2);
    mostrar(lista3);
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

void apareo(nodolista *input1, nodolista *input2)
{
    nodolista *p1 = input1;
    nodolista *p2 = input2;

    while (p1 != NULL and p2 != NULL)
    {
        if (p1->dato == p2->dato)
        {
            cout<<p1->dato<<" ";
            p1 = p1->sig;
            p2 = p2->sig;
        }
        else if (p1->dato < p2->dato)
        {   
            cout<<p1->dato<<" ";
            p1 = p1->sig;
        }
        else if (p1->dato > p2->dato)
        {
            cout<<p2->dato<<" ";
            p2 = p2->sig;
        }
    }
    while (p1 != NULL)
    {
        cout<<p1->dato<<" ";
        p1 = p1->sig;
    }
    while (p2 != NULL)
    {
        cout<<p2->dato<<" ";
        p2 = p2->sig;
    }
}

void agregar(nodolista *& lista, nodolista *&puntero, int a)
{   
    nodolista * n = new nodolista;
    n->dato = a;
    n->sig = NULL;
    if (puntero == NULL)
    {
        lista = n;
    }
    else
    {
        puntero->sig = n;
        puntero = n;
    }
}
