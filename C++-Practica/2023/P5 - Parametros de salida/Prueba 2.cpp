#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void intercambio(int & a, int & b);

main(){
    int n1, n2;
    cin>>n1;
    cout<<"\n\n";
    cin>>n2;
    cout<<"\n\n";
    intercambio(n1, n2);
    cout<<"1: "<<n1<<"\n2:"<<n2;
}

void intercambio(int & a, int & b)
{
int x=a;
a=b;
b=x;
}