#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float radio, dia, per, sup;
    const float PI=3.1415926;
    cout<<endl<<endl<<endl<<endl<<"Radio del circulo en centimetros: ";
    cin>>radio;
    dia=2*radio;
    per=dia*PI;
    sup=pow(radio, 2)*PI;
    cout<<endl<<"   -Diametro: "<<dia<<" cm"<<endl;
    cout<<"   -Perimetro: "<<per<<" cm"<<endl;
    cout<<"   -Superficie: "<<sup<<" cm"<<endl<<endl<<endl<<endl;
    getch();
    return 0;
}