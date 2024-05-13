#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

void repetir(string texto, int cantidad);

main(){
    int n;
    string texto;
    cin>>n;
    cin>>texto;
    cout<<"Tu texto repetido "<<n<<" veces se vería así"<<endl;
    repetir(texto, n);
    cout<<"\n\n";
}

void repetir(string texto, int cantidad)
{
    if (cantidad>0)
    {
        repetir(texto, cantidad-1);
        cout<<texto<<endl;
    }

}