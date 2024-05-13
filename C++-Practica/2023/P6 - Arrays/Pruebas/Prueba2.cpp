#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

void input(int[], int);
int prom(int[], int);
int mayores(int[], int, int);

main(){
    cout<<"Ok: "<<endl<<endl<<"ingrese la cantidad de numeros que va a ingresar: ";
    int q=0;
    cin>>q;
    int nros[q];
    input(nros, q);
    cout<<endl<<"Hay "<<mayores(nros, q, prom(nros, q))<<" numeros mayores al promedio de "<<prom(nros, q);
/*
Ingresar nros
Calcular promedio
Calcular numeros mayores al promedio
*/
getch();
}

void input(int v[], int t){
    for(int i=0; i<t; i++){
        cout<<endl<<"Ingrese el numero de orden "<<i+1<<endl;
        cin>>v[i];
    }
}
int prom(int v[], int t){
    int sum=0;
    for(int i=0; i<t; i++)
    {
        sum+=v[i];
    }
    return sum/t;
}
int mayores(int v[],int t, int p){
    int c=0;
    for(int i=0; i<t; i++){
        if(p<v[i]){
            c++;
        }
    }
    return c;
}
