#include <iostream>
#include <conio.h>
using namespace std;

struct nodo{
    int num;
    nodo * izq;
    nodo * der;
};

void agregar(nodo *& lista, int a);
void IRD(nodo * lista);
main(){
    nodo * lista;
    lista = NULL;
    int a;
    cin>>a;
    while(a!=0){
        agregar(lista, a);
        cin>>a;
    }
    IRD(lista);

    return 0;
}

void agregar(nodo *& lista, int x){
    nodo * n=new nodo;
    n->num=x;
    n->izq=NULL;
    n->der=NULL;
    nodo * p=lista, * ant;
    if(p==NULL){
        lista=n;
    }else{
        while(p!=NULL){
            ant = p;
            if(x<p->num){
                p=p->izq;
            }
            else if(x>p->num){
                p=p->der;
            }
        }
        if(ant->num<x){
            ant->der=n;
        }else if(ant->num>x){
            ant->izq=n;
        }
    }
}

void IRD(nodo * lista){
    if(lista==NULL)
    return;
    IRD(lista->izq);
    cout<<" - "<<lista->num;
    IRD(lista->der);
};