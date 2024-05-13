#include <iostream>
#include <conio.h>
using namespace std;

struct nodo{
    int info;
    nodo * sig;
};
struct nodoarbol{
    int info;
    nodo * izq;
    nodo * der;
};

void apilar(nodo*&, int);
int desapilar(nodo*&);
void encolar(nodo *& pri, nodo*& ult, int n);
int desencolar(nodo *& pri, nodo*& ult);
void insertar(nodo *& lista, int);
void mostrar(nodo * lista);
void buscaryeliminar(nodo *& lista, int n);
void buscaryeliminarenorden(nodo *& lista, int n);
main(){
    int a;
    nodo * pila=NULL;
    nodo * pri = NULL, *ult = NULL;
    nodo * lista = NULL;
    do{
        cin>>a;
        apilar(pila, a);
        encolar(pri, ult, a);
        insertar(lista, a);
    }
    while(a!=0);
    while(pila!=NULL){
        cout<<" "<<desapilar(pila);
    }
    cout<<endl;
    while(pri!=NULL){
        cout<<" "<<desencolar(pri, ult);
    }
    cout<<endl;
    do{
        cin>>a;
        buscaryeliminarenorden(lista, a);
    }
    while(a!=0);
    mostrar(lista);
    getch();
    return 0;
}

void apilar(nodo *& pila, int nuevonumero){
    nodo *temp = new nodo;
    temp->info=nuevonumero;
    temp->sig = pila;
    pila=temp;
}
int desapilar(nodo *& pila){
    nodo *temp=pila;
    int n;
    n=pila->info;
    pila = pila->sig;
    delete temp;
    return n;
}
void encolar(nodo *& pri, nodo*& ult, int n){
    nodo *temp = new nodo;
    temp->info=n;
    temp->sig=NULL;
    if(ult!=NULL)
        ult->sig=temp;
    else
        pri=temp;
    ult=temp;
}
int desencolar(nodo *& pri, nodo *& ult){
    nodo * temp;
    int n;
    n=pri->info;
    temp=pri;
    pri=pri->sig;
    delete temp;
    if(pri==NULL)
        ult=NULL;
    return n;
}
void insertar(nodo *& lista, int n){
    nodo * nuevo = new nodo;
    nuevo->info = n;
    nuevo->sig = NULL;
    nodo * temp = lista, * ant;
    while(temp!=NULL and temp->info<n){
        ant=temp;
        temp=temp->sig;
    }
    if(temp!=lista)
    ant->sig=nuevo;
    else
    lista=nuevo;
    nuevo->sig = temp;
}
void mostrar(nodo * lista){
    nodo * p = lista;
    while(p!=NULL)
    {
        cout<<" "<<p->info;
        p=p->sig;
    }
}
void buscaryeliminar(nodo *& lista, int n){
    nodo * temp=lista, *ant;
    while(temp!=NULL and temp->info!=n){
        ant=temp;
        temp = temp->sig;
    }
    if(temp==NULL)
        return;
    else if(temp==lista)
        lista=temp->sig;
    else
        ant->sig=temp->sig;
    delete temp;
}
void buscaryeliminarenorden(nodo *& lista, int n){
    nodo * temp=lista, *ant;
    while(temp!=NULL and temp->info<n){
        ant=temp;
        temp = temp->sig;
    }
    if(temp==NULL or temp->info!=n)
        return;
    else if(temp==lista)
        lista=temp->sig;
    else{
        ant->sig=temp->sig;
    }
    delete temp;
}