#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float total, ensamb, pint, elec;
    cout<<endl<<endl<<endl<<endl<<"Presupuesto: ";
    cin>>total;
    ensamb = total*0.37;
    pint = total*0.42;
    elec = total*0.21;
    cout<<endl<<"Presupuesto para el area ensambladora: "<<ensamb;
    cout<<endl<<"Presupuesto para el area de pintura: "<<pint;
    cout<<endl<<"Presupuesto para el area electrica: "<<elec;
    getch();
    return 0;
}