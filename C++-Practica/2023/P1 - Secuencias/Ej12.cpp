#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float coteu, cotdol, eu, dol, pesos;
    cout<<endl<<endl<<endl<<endl<<"Cotizacion del dolar: ";
    cin>>cotdol;
    cout<<endl<<"Cotizacion del euro: ";
    cin>>coteu;
    cout<<endl<<"Cantidad de dinero: ";
    cin>>pesos;
    dol = pesos/cotdol;
    eu = pesos/coteu;
    cout<<endl<<"Dolares: "<<dol;
    cout<<endl<<"Euros: "<<eu;
    getch();
    return 0;
}