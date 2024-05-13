#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

long long int combinatorio(long long int n, long long int m);

main(){
    int n;
    int m;
    cout<<"n\n";cin>>n;
    cout<<"m:\n";cin>>m;
    cout<<endl<<endl<<"Combinatoria: "<<endl<<combinatorio(n, m);
    cout<<"\n\n";
}

long long int combinatorio(long long int n, long long int m)
{
    if(n<=0)
    return 1;
    else 
    return combinatorio(n-1, m)*(m-n+1)/n;
    
}