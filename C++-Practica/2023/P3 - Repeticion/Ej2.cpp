#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main(){
    int alumnos = 0, nota1 = 0, nota2 = 0;
    string nombre;
    float promedio;
    cout<<"Ingrese la cantidad de alumnos: ";
    cin>>alumnos;
    for(int i=1; i<=alumnos; i++){
        cout<<"\n\nIngrese el nombre: ";
        cin>>nombre;
        cout<<"\nIngrese la primera nota: ";
        do{
        cin>>nota1;}while(nota1<1 or nota1>10);
        cout<<"\nIngrese la segunda nota: ";
        do{
        cin>>nota2;}
        while(nota2<1 or nota1>10);
        promedio = (float)(nota1 + nota2)/2;
        cout<<"\n\n"<<nombre<<" tuvo de promedio un "<<promedio<<"\n";
    }
    getch();
    return 0;
}