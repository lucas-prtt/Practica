#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int factorial(int a);

main(){
    int n1;
    cin>>n1;
    n1=factorial(n1);
    cout<<"\n\n";
    cout<<"Factorial: "<<n1;
}

int factorial(int a)
{
if (a==0){return 1;}
else{return a*factorial(a-1);}
}