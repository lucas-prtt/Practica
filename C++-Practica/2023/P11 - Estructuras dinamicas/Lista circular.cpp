#include <iostream>

using namespace std;

struct nodo{
    int num;
    nodo * sig;
};

void agregar(nodo *& lista, int a);
void imprimirlista(nodo * lista);
main(){
    nodo * lista;
    lista = NULL;
    int a;
    cin>>a;
    while(a!=0){
        agregar(lista, a);
        cin>>a;
    }
    imprimirlista(lista);

    return 0;
}

void agregar(nodo *& lista, int x){
    nodo * n;
    n = new nodo;
    n->num=x;
    if(lista==NULL){
        lista = n;
        lista->sig=lista;
        return;
    }
    n->sig=lista->sig;
    lista->sig=n;
}

void imprimirlista(nodo * lista){
    nodo * p;
    p=lista;
    cout<<"\n"<<p->num;
    p=p->sig;
    while (p!=lista)
    {
        cout<<"\n"<<p->num<<" "<<p<<lista;;
        p=p->sig;
    }
    return;
};