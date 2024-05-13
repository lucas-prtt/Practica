#include <iostream>
#include <conio.h>
using namespace std;
struct resumen{
    int item;
    unsigned int cantidad;
};
void ordenar(int[], int);
void cortecontrol(int[], int, resumen[]);
main(){
    int t=25;
    resumen resumidito[t];
    for(int i=0; i<t; i++){resumidito[i].cantidad=0;}
    int vector[t]={19, 98, 56, 21, 774, 98, 45, 98, 15, 16, 17, 15 ,19, 14, 16, 16, 18, 19, 11, 18, 18, 23, 98, 45, 200};
    ordenar(vector, t);
    for(int i=0; i<t; i++){cout<<vector[i]<<" - ";}
    cortecontrol(vector, t, resumidito);
    cout<<"\n\n\n";
    for(int i=0; i<t; i++){if(resumidito[i].cantidad!=0){cout<<resumidito[i].item<<"\t - \t"<<resumidito[i].cantidad<<".\n";}}
    getch();
    return 0;
}
void ordenar(int v[], int t){
    int temp;
    int posmin;
    int min;
    for(int i=0; i<t-1; i++){
        min = v[i];
        for(int q=i; q<t; q++){
            if (min>v[q]){
            posmin=q; 
            min=v[q];
            }
        }
        temp=v[posmin];
        v[posmin]=v[i];
        v[i]=temp;
    }
}

void cortecontrol(int v[], int t, resumen zf[]){
    int i=0, j, q=0, r=0;
    do{
        j=i;
        do{
            j++;
            q++;
        }while(j<t and v[i]==v[j]);
        zf[r].item = v[i];
        zf[r].cantidad = q;
        r++;
        q=0;
        i=j;
    }while(i<t);
}
