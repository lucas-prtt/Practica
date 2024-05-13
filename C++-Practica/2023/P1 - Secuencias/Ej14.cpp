#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float largo, alto, arena;
    cout<<endl<<endl<<endl<<endl<<"Alto de la pared en metros: ";
    cin>>alto;
    cout<<endl<<endl<<"Largo de la pared en metros: ";
    cin>>largo;
    arena = alto*largo*0.5;
    cout<<endl<<"Se requieren "<<arena<<" metros cubicos de arena ("<<arena*1000<<" centimetros cubicos)";
    getch();
    return 0;
}