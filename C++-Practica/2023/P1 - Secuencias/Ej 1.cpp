#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;
main(){
    int a, b, c, suma, resta, producto;
    cout <<"INGRESA LOS 3 NUMEROS!"<<endl;
    cin>>a;

    cout<<"FALTAN 2 MAS!"<<endl;
    cin>>b;

    cout<<"UNO MAS!"<<endl;
    cin>>c;

    suma = a + b + c;
    resta = a - b - c;
    producto = a * b * c;
    cout<<endl<<"El valor de la suma de los 3 es "<<suma<<", el de la resta de los tres es "<<resta<<" y el de la multiplicacion de los 3 es "<<producto;
    getch();
return 0;
}
