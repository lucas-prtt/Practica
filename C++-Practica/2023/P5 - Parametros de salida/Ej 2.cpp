#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

int multiplicar(int a, int b);

main(){
    int n1, n2;
    cin>>n1;
    cin>>n2;
    cout<<endl<<multiplicar(n1, n2);
    cout<<"\n\n";
}

int multiplicar(int a, int b)
{
    if(b>0)
    return a + multiplicar(a, b-1);
    else
    return 0;
}