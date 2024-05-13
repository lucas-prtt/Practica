#include <iostream>
#include <conio.h>
using namespace std;

struct empleado
{
    int legajo;
    float sueldo;
};

void ingresardatos(empleado[], int &q);
void mayor(empleado[], int q);



main(){
empleado empleado[100];
int q=100;
ingresardatos(empleado, q);
for (int i=0; i<q; i++){cout<<"\n "<<empleado[i].legajo<<"//"<<empleado[i].sueldo;}
mayor(empleado, q);
}




void ingresardatos(empleado vector[], int &q)
{
    int total=0;
    for(int i=0; i<q; i++)
    {   char r;
        cout<<"Ingrese el legajo de un empleado:\n";
        cin>>vector[i].legajo;
        cout<<"Ingrese el sueldo de ese empleado\n";
        cin>>vector[i].sueldo;
        total++;
        cout<<"Quiere ingresar un empleado mas?\nS/N\n";
        do{
            r=getch();
            if(r=='N' or r=='n'){q=total;}
        }while(r!='N' and r!='S' and r!='s' and r!='n');
    }
    q=total;
}
/*
void mayor(empleado array[], int q){
    int mayor=0;
    cout<<"\n\n";
    for(int i=0; i<q; i++){
        if(array[i].sueldo > array[mayor].sueldo)
        mayor=i;
        }
    for(int i=0; i<q; i++){
        if(array[i].sueldo == array[mayor].sueldo)
        {cout<<"Legajo "<<array[i].legajo<<" tuvo un sueldo de "<<array[i].sueldo<<"\n";}
    }
}*/
void mayor(empleado array[], int q){
    int quien[q];
    int cuantos=0; //al pasar por el primero el sueldo será igual al mayor por lo que se agrega uno
    quien[0]=0;
    cout<<"\n\n";
    for(int i=0; i<q; i++){
        if(array[i].sueldo > array[quien[0]].sueldo)
        {quien[cuantos-1]=i;
        cuantos=1;}
        else if(array[i].sueldo==array[quien[0]].sueldo){
        quien[cuantos]=i;
        cuantos++;
        }
        }

    for(int i=0; i<cuantos; i++){
        {cout<<"Legajo "<<array[quien[i]].legajo<<" tuvo un sueldo de "<<array[quien[i]].sueldo<<"\n";}
}}