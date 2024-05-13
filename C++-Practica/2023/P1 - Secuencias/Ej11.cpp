#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float p = 75;
    float q, t;
    cout<<endl<<endl<<endl<<endl<<"     +Cuantos metros de alambre?"<<endl<<endl;
    cout<<"        -";
    cin>>q;
    t=p*q;
    if(t>0.0){
    cout<<endl<<"     +Eso serian $"<<t;
    cout<<endl<<endl<<"        -Dale, ahora te pago."<<endl<<endl;}
    else if(t==0.0){cout<<endl<<"     +Eso no es nada"<<endl<<endl<<endl;}
    else if(t<0.0){cout<<endl<<"     +Yo vendo, no compro"<<endl<<endl<<endl;}
    getch();
    return 0;
}