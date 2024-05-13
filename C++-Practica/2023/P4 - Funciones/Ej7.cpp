#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

unsigned int edadAGrupoEtario(unsigned int);

int main(){
    unsigned int edad;
    cin>>(edad);
    cout<<"Grupo etario:"<<edadAGrupoEtario(edad);
    getch();
    return 0;
    }

unsigned int edadAGrupoEtario(unsigned int age){
    if(age<=14)
    return 1;
    else if (age>=64)
    return 8;
    else if (age>=50 and age<=63)
    return 7;
    else return (age-1)/7;
}