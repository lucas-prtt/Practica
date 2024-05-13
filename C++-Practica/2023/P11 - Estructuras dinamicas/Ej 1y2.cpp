#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

struct persona{
    char apellido[50];
    int dni;
};

struct nodopila{
    nodopila* siguiente;
    persona info;
};

void Ej1(nodopila*&pila, persona remplazo){
    //remplazar los dos elementos de arriba por uno nuevo
    if(pila->siguiente!=NULL and pila!=NULL){
    nodopila* temp;
    temp = pila->siguiente;
    delete pila;
    pila = temp;
    pila->info = remplazo;
    return;}
    cout<<"Error: longitud de pila insuficiente";
};
void Ej2(nodopila*&pila, persona remplazo){
    //Insertar persona en ubicacion de pila 3.
    nodopila* tercero=pila;
    while(tercero->siguiente->siguiente->siguiente!=NULL){
        tercero=tercero->siguiente;
    }
    tercero->info=remplazo;
};
void leerpila(nodopila*&pila)
{
    cout<<"\n";
    nodopila *actual;
    actual = pila;
    cout<<"\n "<<*actual->info.apellido<<" - "<<actual->info.dni;
    while(actual->siguiente!=NULL){
        actual = actual->siguiente;
        cout<<"\n "<<*actual->info.apellido<<" - "<<actual->info.dni;
    }
};

void apilar(nodopila*&pila, persona ingreso){
    nodopila *temp;
    temp = new nodopila;
    temp->info=ingreso;
    temp->siguiente = pila;
    pila=temp;
};
bool continuar(){
    cout<<"\nContinuar\nY/N?";
    char r;
    do{
        r=getch();
        r=toupper(r);
    }while(r!='Y' and r!='N');
    if(r=='Y')
    return true;
    return false;
}
persona ingresarpersona(){
    persona temp;
    cout<<"\nApellido:\n";
    fflush(stdin);
    cin.getline(temp.apellido, sizeof(temp.apellido));
    cout<<"\nDni:";
    cin>>temp.dni;
    return temp;
};
main(){
    nodopila*pila = NULL;
    do{
    apilar(pila, ingresarpersona());
    cout<<pila->info.apellido<<pila->info.dni;
    }while(continuar());
    cout<<"\nOk, ingreso finalizado \nLeyendo la lista...\n";
    getch();
    leerpila(pila);
    getch();
    Ej2(pila, ingresarpersona());
    leerpila(pila);
    getch();
    return 0;
}