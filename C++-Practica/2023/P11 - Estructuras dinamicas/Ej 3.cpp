#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

struct nodolista
{
    nodolista *siguiente;
    char letra;
};
int contarlista(nodolista *pri)
{
    if (pri == NULL)
        return 0;
    int contador = 1;
    while (pri->siguiente != NULL)
    {
        contador++;
        pri = pri->siguiente;
    }
    return contador;
}
void cargarlista(char v[], nodolista *pri)
{
    nodolista *actual;
    actual = pri;
    int i = 1;
    v[0] = actual->letra;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
        v[i] = actual->letra;
        i++;
    }
}
bool escapicua(nodolista *pri, nodolista *ult)
{
    int t;
    t = contarlista(pri);
    if (t == 0)
        return false;
    char listavector[t];
    cargarlista(listavector, pri);
    char izq = 0, der = t - 1;
    int i = 0;
    while (i != (t - 1) / 2)
    {
        i++;
        if (listavector[izq] != listavector[der])
        {
            return false;
        }
        izq++;
        der--;
    }
    return true;
}

void leerlista(nodolista *lista)
{
    if (lista == NULL)
        return;
    cout << "\n";
    nodolista *actual;
    actual = lista;
    cout << "\n " << actual->letra;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
        cout << actual->letra;
    }
};
nodolista *anteultimo(nodolista *&pri)
{
    nodolista *anterior = pri;
    while (anterior != NULL and anterior->siguiente != NULL and anterior->siguiente->siguiente != NULL)
    {
        anterior = anterior->siguiente;
    }
    return anterior;
};
void backspace(nodolista *&pri, nodolista *&ult)
{
    nodolista *temp;
    temp = anteultimo(pri);
    if (ult != NULL)
    {
        delete ult;
        ult = temp;
        ult->siguiente = NULL;
    }
}
void encolar(nodolista *&pri, nodolista *&ult, char a)
{
    nodolista *temp;
    temp = new nodolista;
    temp->letra = a;
    temp->siguiente = NULL;
    if (ult != NULL)
        ult->siguiente = temp;
    else
        pri = temp;
    ult = temp;
};
main()
{
    cout << "\n\n\n\n";
    nodolista *pri = NULL, *ult = NULL;
    char a;
    do
    {
        a = getch();
        if (a != 13)
        {
            if (a == 8)
            {
                if (ult != NULL)
                {
                    backspace(pri, ult);
                    cout << "\b \b";
                }
            }
            else
            {
                encolar(pri, ult, a);
                cout << a;
            }
        }
    } while (a != 13);
    cout << "\n\n...\n\n";

    if (escapicua(pri, ult))
    {
        cout << "Es capicua";
    }
    else
    {
        cout << "No es capicua";
    }
    // leerlista(pri);
    // cout<<"\n\n-> Son unos "<<contarlista(pri)<<" caracteres!";
    getch();
    return 0;
}