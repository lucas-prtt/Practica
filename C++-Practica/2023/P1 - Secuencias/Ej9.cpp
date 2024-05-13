#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    int numero, uni, dec, cen;
    cout<<endl<<endl<<endl<<endl<<"Decime un numero"<<endl;

    cin>>numero;
    cen = numero/100;
    dec = numero/10-cen*10;
    uni = numero-cen*100-dec*10;
    cout<<endl<<"   -Unidades: "<<uni<<""<<endl;
    cout<<"   -Decenas: "<<dec<<""<<endl;
    cout<<"   -Centenas: "<<cen<<""<<endl;
    getch();
    return 0;
}