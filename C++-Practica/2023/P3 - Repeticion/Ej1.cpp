#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main(){
    int numero[9] = {};
    cout<<"Ingrese 10 numeros\n";

    for(int i=0; i<=9; i++)
        cin>>numero[i];

    cout<<"\n\n\nPositivos:\n";
    for(int i=0; i<=9; i++)
        if(numero[i]>0)cout<<"\t-> "<<numero[i]<<endl;

    getch();
    return 0;
}