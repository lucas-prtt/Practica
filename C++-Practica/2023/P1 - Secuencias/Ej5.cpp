#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    int nota1, nota2, nota3, nota4;
    float promedio;
    cout<<"Ingrese la nota de la primera prueba"<<endl;
    cin>>nota1;
    cout<<"Ingrese la nota de la segunda prueba"<<endl;
    cin>>nota2;
    cout<<"Ingrese la nota de la tercera prueba"<<endl;
    cin>>nota3;
    cout<<"Ingrese la nota de la cuarta prueba"<<endl;
    cin>>nota4;
    promedio = (float(nota1) + nota2 + nota3 + nota4)/4;
    
    if(promedio<=10 and promedio >=0){
    cout<<endl<<"Tuviste un "<<promedio<<" de promedio";}
    else
    {cout<<endl<<endl<<endl<<"que?";}
    getch();
    return 0;
}