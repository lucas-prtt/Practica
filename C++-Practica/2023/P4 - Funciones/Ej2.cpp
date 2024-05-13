#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int lafuncion(int);

int main(){
    int a;
    cin>>a;
    cout<<"\n\n\n"<<lafuncion(a);
    getch();
    return 0;
}

int lafuncion(int n){
    if (n>=1){
        long f = 1;
        for(int i=1; i<=n; i++){f*=i;}
        return f;}
    else {cout<<"Solo se admiten numeros mayores o iguales a ";return 1;}
}