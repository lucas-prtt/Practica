#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void output(int[], int);
void inputhasta0(int[],int&);
void ordenar(int[], int);
int menor(int[], int);
void encontrarycero(int[], int, int);
int encontrarunodistintoa0(int[], int);
void copiararray(int[], int, int[]);
main(){
    int q = 9999;
    int array[q];
    inputhasta0(array, q);
    ordenar(array, q);
    int arrayordenadodentro[q];
    int arrayordenadofuera[q];


    output(array, q);
    
    getch();
    return 0;
}

void ordenar(int v[], int q)
{
    int ord[q];
    for (int i = 0; i < q; i++)
    {
        ord[i]=menor(v, q);
        encontrarycero(v, q, menor(v,q));

    }
    copiararray(ord, q, v);
}
void inputhasta0(int v[], int &q){
    int a=0;
    for(int i=0; i<q; i++){
        
        cout<<"Numero "<<i+1<<": ";
        cin>>a;
        if(a!=0) v[i]=a;
        else q=i;
    }
    //A partir de aca se trata a q como el ultimo valor del array
}

void output(int v[], int q){
    cout<<"\n\n\n(";
    for(int i=0; i<q; i++){
        if(i!=q-1)
        cout<<v[i]<<"; ";
        else
        cout<<v[i];
    }
    cout<<")";
}
int menor(int v[], int q){
    int min = v[encontrarunodistintoa0(v, q)];
        for (int i = 0; i < q; i++)
        {
            if(v[i]!=0 && min>v[i])
            min=v[i];
        }
    return min;
}
void encontrarycero(int v[], int q, int n){
    for (int i = 0; i < q; i++)
    {
        if(v[i]==n){v[i]=0;}
    }
}
int encontrarunodistintoa0(int v[], int q){
    for (int i = 0; i < q; i++)
    {
        if(v[i]!=0)
        return v[i];
    }
    return 0;
}
void copiararray(int v1[], int q, int v2[]){
    for (int i = 0; i < q; i++)
    {
        v2[i] = v1[i];
    }
    
}