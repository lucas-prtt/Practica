#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

void input(int[], int);
int prom(int[], int);
int mayores(int[], int, int);

main(){
    cout<<"Ok: "<<endl<<endl;
    int nros[5];

    input(nros, 5);
    cout<<"Hay "<<mayores(nros, 5, prom(nros, 5))<<" numeros mayores al promedio de "<<prom(nros, 5);
/*
Ingresar nros
Calcular promedio
Calcular numeros mayores al promedio
*/
getch();
}

void input(int v[], int t){
    for(int i=0; i<t; i++){
        cout<<"Ingrese el numero de orden "<<i<<endl;
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
