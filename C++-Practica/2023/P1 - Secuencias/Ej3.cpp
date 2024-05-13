#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main(){
    int n, w, x, y, z, suma;
    //se entiende como n = wxyz
    cout<<"Ingrese un numero positivo de 4 cifras:"<<endl;
    cin>>n;
    w=n/1000;
    z=n%10;
    y=(n%100-z)/10;
    x=n/100-w*10;
    //cout<< "   Es " <<w<<x<<y<<z<< "???";
    suma = w + x + y + z;
    cout<<endl<<endl<<"La suma de los digitos da como resultado "<<suma;
    getch();
    return 0;
}