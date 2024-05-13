#include <iostream>
#include <conio.h>

struct nodolista
{
    int dato1;
    int dato2;
    nodolista *sig;
};

void insertar(nodolista *&lista, int numero, int b);
void mostrar(nodolista *lista);

using namespace std;
main()
{
    int a, b;
    nodolista *lista1 = NULL;
    cout << "Lista 1:\n";
    do
    {   
        cout<<"a:";
        cin >> a;
        cout<<"b: ";
        cin >> b;
        insertar(lista1, a, b);
    } while (a != 0);

    cout << "\nLista 1:\n";
    mostrar(lista1);
    getch();
    return 0;
}

void insertar(nodolista *&lista, int numero1, int numero2)
{
    nodolista *p, *ant, *n;
    n = new nodolista;
    n->dato1 = numero1;
    n->dato2 = numero2;
    p = lista;
    while (p != NULL and p->dato1 < n->dato1)
    {
        ant = p;
        p = p->sig;
    }
    while (p != NULL and p->dato1 == n->dato1 and p->dato2<n->dato2)
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
        cout <<"("<< p->dato1 << "; " << p->dato2 <<")";
        if (p->sig != NULL)
            cout << "  -  ";
        p = p->sig;
    }
}
