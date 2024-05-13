#include <iostream>
#include <conio.h>

struct nodolista
{
    int dato;
    nodolista *sig;
};

void insertar(nodolista *&lista, int numero);
void mostrar(nodolista *lista);
void eliminarelemento(nodolista * & lista, int numero);

using namespace std;
main()
{
    int a;
    nodolista *lista1 = NULL;
    cout << "Lista 1:\n";
    do
    {
        cin >> a;
        insertar(lista1, a);
    } while (a != 0);
    cout << "\nLista 1:\n";
    mostrar(lista1);
    cout << "\n";
    do
    {
        cin >> a;
        eliminarelemento(lista1, a);
    } while (a != 0);
    mostrar(lista1);
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
void eliminarelemento(nodolista * & lista, int numero){
    nodolista * p, *ant;
    p = lista;
    while(p!=NULL and p->dato<numero){
        ant = p;
        p=p->sig;
    }
    if(p==NULL or p->dato!=numero){
        return;
    }
    if(p==lista){
        lista = lista->sig;
        delete p;
    }else{
        ant->sig = p->sig;
        delete p;
    }

}