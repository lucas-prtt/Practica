#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void sumar(int a, int b, int & c);

main(){
    int n1, n2, suma;
    cin>>n1;
    cout<<"\n\n";
    cin>>n2;
    cout<<"\n\n";
    sumar(n1, n2, suma);
    cout<<suma;
}

void sumar(int a, int b, int & c)
{
    c= a + b;
}