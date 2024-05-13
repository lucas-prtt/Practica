#include <iostream>
#include <conio.h>
using namespace std;

struct nodo{
    int num;
    nodo * sig;
    nodo * ant;
};

void agregar(nodo *& lista, int a);
void imprimirlista(nodo * lista);
void explorar(nodo * lista);
main(){
    nodo * lista;
    lista = NULL;
    int a;
    cin>>a;
    while(a!=0){
        agregar(lista, a);
        cin>>a;
    }
    explorar(lista);

    return 0;
}

void agregar(nodo *& lista, int x){
    nodo * n, * p, * ant;
    n = new nodo;
    n->num=x; 
    p=lista;
    ant=NULL;
    while(p!=NULL and p->num<x){
        ant = p;
        p = p->sig;
    }
    n->sig=p;
    n->ant=ant;
    if(p!=lista){
        ant->sig=n;
        if(p!=NULL)
        p->ant=n;
        }
    else
        lista=n;
}

void explorar(nodo * lista){
nodo * p=lista;
if(p==NULL){
return;
}
char a = 'l';
while(a!='s'){
a=getch();
if(a=='a'){
    //izq
    if(p->ant!=NULL){
        p=p->ant;
        cout<<"<->\n";
    }
    cout<<p->num<<"\n";
}
else if (a=='d'){
    //der
        if(p->sig!=NULL){
        p=p->sig;
        cout<<"<->\n";
    }
    cout<<p->num<<"\n";
}
}
}

void imprimirlista(nodo * lista){
    nodo * p;
    p=lista;
    while (p!=NULL)
    {
        cout<<"\n"<<p->num<<" <- ";
        p=p->sig;
    }
    return;
};