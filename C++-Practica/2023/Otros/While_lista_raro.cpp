#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct nodolista{
    int num;
    nodolista * sig;
};

void insertar(int num, nodolista*& lista){
nodolista * p = lista , * ant;
nodolista * nuevo;
nuevo = new nodolista;
nuevo->num = num;
while(p and p->num<num){
    ant = p;
    p = p->sig;
}
if(p!=lista){
    ant->sig = nuevo;
}
else{
    lista = nuevo;
}
    nuevo->sig = p;
}

main(){
    cout<<"Start\n";
    int a;
    nodolista * lista = NULL;
    do{
        cin>>a;
        insertar(a, lista);
    }
    while(a != 0);
    nodolista * lec = lista; 
    while(lec != NULL)
    {
        cout<<lec->num;
        lec = lec->sig;
    }
    getch();
    return 0;
}