#include <iostream>
#include <conio.h>

struct nodolista
{
    int dato;
    nodolista *sig;
};

void apareo(nodolista *input1, FILE *input2, nodolista *&output);
void insertar(nodolista *&lista, int numero);
void mostrar(nodolista *lista);
void mostrar(FILE *archivo);

using namespace std;
main()
{
    int a;
    nodolista *lista1 = NULL, *apareado = NULL;
    FILE *archivo = fopen("arch1", "rb");
    cout << "Lista:\n";
    do
    {
        cin >> a;
        insertar(lista1, a);
    } while (a != 0);
    cout << "\nLista:\n";
    mostrar(lista1);
    cout << "\nArchivo\n";
    mostrar(archivo);
    cout << "\nApareo de listas:\n";
    apareo(lista1, archivo, apareado);
    mostrar(apareado);
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
void mostrar(FILE *arch)
{
    fseek(arch, 0, 0);
    int a;
    fread(&a, sizeof(a), 1, arch);
    while (!feof(arch))
    {
        cout << a << " - ";
        fread(&a, sizeof(a), 1, arch);
    }
}

void apareo(nodolista *input1, FILE *arch, nodolista *&output)
{
    nodolista *p1 = input1;
    nodolista *p3 = output;
    nodolista *n;
    int a;
    fseek(arch, 0, 0);
    fread(&a, sizeof(a), 1, arch);
    while (p1 != NULL and !feof(arch))
    {
        n = new nodolista;
        n->sig = NULL;
        if (p1->dato == a)
        {
            n->dato = a;
            p1 = p1->sig;
            fread(&a, sizeof(a), 1, arch);
        }
        else if (p1->dato < a)
        {
            n->dato = p1->dato;
            p1 = p1->sig;
        }
        else
        {
            n->dato = a;
            fread(&a, sizeof(a), 1, arch);
        }
        if (output == NULL)
        {
            output = n;
            p3 = n;
        }
        else
        {
            p3->sig = n;
            p3 = p3->sig;
        }
    }
    while (!feof(arch))
    {
        n = new nodolista;
        n->sig = NULL;
        n->dato = a;
        if (output == NULL)
        {
            output = n;
            p3 = n;
        }
        else
        {
            p3->sig = n;
            p3 = p3->sig;
        }
        fread(&a, sizeof(a), 1, arch);
    }
    while (p1 != NULL)
    {
        n = new nodolista;
        n->sig = NULL;
        n->dato = p1->dato;
        if (output == NULL)
        {
            output = n;
            p3 = n;
        }
        else

        {
            p3->sig = n;
            p3 = p3->sig;
        }
        p1 = p1->sig;
    }
}

void agregar(nodolista *&lista, nodolista *&puntero, int a)
{
    nodolista *n = new nodolista;
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
