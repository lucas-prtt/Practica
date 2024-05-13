#include <iostream>
#include <conio.h>
using namespace std;

void juntarvectores(int[], int[], int[], int);
void intercalarvectores(int[], int[], int[], int);
void invertir(int[], int[], int);
void mayor(int[],int t, int &cual, int &pos);
void menores(int[], int t);
void menores2(int[], int t);
int ubicar(int[], int t, int b);
main(){
    int t=5;
    int may, pos;
    int v1[t]={7, 9, 12, 20, 7},v2[t]={9, 3, 4, 98, 6};
    int mod[2*t];
    //juntarvectores(v1, v2, mod, t);
    //intercalarvectores(v1, v2, mod, t);
    //invertir(v1, mod, t);
    //for(int i=0; i</*2**/t; i++){cout<<mod[i]<<" - ";}
    //mayor(v2, t, may,  pos);

    //cout<<"El mayor es "<<may<<" ubicado en la posicion "<<pos<<".\n";
    
    //menores(v1, t);
    //cout<<"\n\n\n\n----------------------------------------------------------------------\n\n\n\n";
    //menores2(v1, t);
    getch();
    return 0;
}
int ubicar(int v[], int t, int b){
    for(int i=0; i<t; i++){
        if(v[i]==b){return i;}
    }
    return -1;
}

void menores2(int v[], int t){
    int menor=v[0];
    for(int i=0; i<t; i++){
        if(menor>v[i])
        {menor=v[i];}
    }
    cout<<"El menor numero presente es "<<menor<<" y se encuentra en las posiciones: \n";
    for(int i=0; i<t; i++){
        if(v[i]==menor){
            cout<<"\t"<<i<<"\t";
        }
    }
}
void menores(int v[], int t){
    int menores[t], cuantos;
    cuantos=0;menores[0]=0; 
    for(int i=0; i<t; i++){
        if(v[menores[0]]>v[i]){
            cuantos=1;
            menores[cuantos-1]=i;            
        }else if(v[menores[0]]==v[i]){
            cuantos++;
            menores[cuantos-1]=i;
        }
    }
    cout<<"Hay en total "<<cuantos<<" numeros que son el minimo de todo el vector ("<<v[menores[0]]<<")\nEstos se encuentran en las siguientes posiciones:\n";
    for(int i=0; i<cuantos; i++){
        cout<<"\t"<<menores[i]<<"\t"; 
    }
    cout<<"\n";
}
void mayor(int v[], int t, int &may, int &pos)//Si el mayor es unico
{
    may=v[0]; pos=0;
    for (int i=0; i<t; i++){
        if (v[i]>may){
            may=v[i];
            pos=i;
        }
    }
}
void invertir(int vi[], int vf[], int t){
    for(int i=0; i<t; i++){
        vf[i]=vi[t-i-1];
    }
}
void intercalarvectores(int v1[], int v2[], int inter[], int t){
    for(int i=0; i<2*t; i++){
        if(i%2==0)
        {
            inter[i]=v1[i/2];
        }
        else
        {
            inter[i]=v2[i/2];
        }
    }


}

void juntarvectores(int v1[], int v2[], int junto[], int t){    
    for (int i=0; i<2*t; i++){
        if(i<t){
            junto[i]=v1[i];
        }
        else{
            junto[i]=v2[i-5];
        }
    }
}