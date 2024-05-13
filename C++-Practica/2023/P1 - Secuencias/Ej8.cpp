#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float apr, desapr, aus, papr, pdesapr, paus, total;
    cout<<endl<<endl<<endl<<endl<<"Alumnos aprobados: ";
    cin>>apr;
    cout<<"Alumnos desaprobados: ";
    cin>>desapr;
    cout<<"Alumnos ausentes: ";
    cin>>aus;

    total=apr+desapr+aus;

    if(apr<0 or desapr<0 or aus<0){  
        cout<<endl<<endl<<"Algo anda mal...";
        getch();
        return 0;
    }else if(total==0){
        cout<<endl<<endl<<"No tenes alumnos!";
        getch();
        return 0;}


    papr = apr/total*100;
    pdesapr = desapr/total*100;
    paus = aus/total*100;

    /* Informe */cout<<endl<<endl<<"Aprobó un "<<papr<<"%, desaprobó un "<<pdesapr<<"% y se ausento un "<<paus<<"%.";
   
    /* Reaccion */if(pdesapr>90){cout<<endl<<"Que desastre!";}else if (paus>90 and paus != 100){cout<<endl<<"No vino casi nadie!";}else if(paus=100){cout<<endl<<"No vino nadie!";}
    
    cout<<endl;
    getch();
    return 0;
}