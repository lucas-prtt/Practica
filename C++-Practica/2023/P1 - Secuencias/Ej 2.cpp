#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main(){
    float a, b, suma, promedio;
    cout<<"Ingrese un numero:"<<endl;
    cin>>a;
    cout<<"Ingreses otro mas:"<<endl;
    cin>>b;
    suma = 2*a + pow(b, 2);
    promedio = (pow(a, 3) + pow(b, 3))/2;
    cout<<endl<<"La suma del doble del primero de aquellos numeros junto con el cuadrado del segundo es igual a "<<suma;
    cout<<endl<<"El promedio del cubo de ambos numeros es "<<promedio;
    getch();
    return 0;
}