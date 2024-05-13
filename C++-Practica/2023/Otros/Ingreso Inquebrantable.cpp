#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;
void v1(int&);
void v2(int&);
void v3(int&);
main(){
    int a;
    v3(a);
    cout<<"\nFin\n";
    getch();
    return 0;
}

void v1(int &a){
    //Detecta si es una palabra pero un input de cero es un falso positivo
    cin>>a;
    cout<<a<<endl;
    if(a==0)
    cout<<"No fue numero\n";
}

void v2(int &a){
    //Detecta palabras, el cero no es falso positivo
    //Si es invalido se niega a aceptar otro dato por cin durante todo el programa
    cin>>a;
    cout<<a<<endl;
    if(!cin){
        cout<<"\nNo fue numero\n";
    }
    int b;
    cin>>b;
    cout<<"\n\n"<<b;
}

void v3(int &a){
    cin>>a;
    if(!cin){
        cout<<"\nNo fue numero\n";
    } else{
        cout<<"\nFue numero\n";
    }
    cin.clear();
    cin.ignore(200, '\n');
}