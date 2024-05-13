#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int factorial(int);

int main(){
    int m, n;

    cout<<"---M---\n";
    do
        cin>>m;
    while(m<=0);

    cout<<"---N---\n";
    do
        cin>>n;
    while(n<=0);

    cout<<"---Combinatoria---\n";
    if(m>=n){
    cout<<"\n\n\n"<<factorial(m)/(factorial(n)*factorial(m-n));
    } else 
    cout<<"M debe ser mayor o igual a N, si no no te digo la combinatoria\n\n\n";

    getch();
    return 0;
}

int factorial(int n){
    if (n>=1){
        long f = 1;
        for(int i=1; i<=n; i++){f*=i;}
        return f;}
    else if(n==0)
    {return 1;}
    else
    {cout<<"M debe ser mayor a N y ninguno de los dos puede ser negativo o 0";return 1;}
}