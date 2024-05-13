#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float base, altura, area, perimetro;
    cout<<endl<<endl<<endl<<endl<<"Cual es la longitud de la base?"<<endl;

    cin>>base;
    cout<<endl<<"Cual es la longitud de la altura?"<<endl;
    cin>>altura;
    area = base*altura;
    perimetro = base*2+altura*2;
    cout<<endl<<"   -Area: "<<area<<" cm²"<<endl;
    cout<<"   -Perimetro: "<<perimetro<<" cm"<<endl;
    getch();
    return 0;
}