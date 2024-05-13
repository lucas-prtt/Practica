#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

long long int fibonacci(long long int a);

main(){
    int n;
    cin>>n;
    cout<<endl<<fibonacci(n);
    cout<<"\n\n";
}

long long int fibonacci(long long int a)
{
    if(a>2)
    return fibonacci(a-1)+fibonacci(a-2);
    else return 1;
}