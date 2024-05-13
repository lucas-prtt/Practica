#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void output(int[], int);
void input(int[], int);
int prom(int[], int);
void mostrargrandes(int[], int, int);
int mayor(int[], int);
int menor(int[], int);

main(){
    int q = 50;
    int array[q];

    input(array, q);
    output(array, q);
    cout<<"\n\nMayor valor: "<<mayor(array, q);
    cout<<"\n\nMenor valor: "<<menor(array, q);
    getch();
    return 0;
}

void mostrargrandes(int v[], int q, int min)
    {
        for (int i = 0; i < q; i++)
        {
            if (v[i]>min)
            cout<<endl<<v[i];
        }
    }

int prom(int v[], int q){
    int suma = 0; 
    for (int i = 0; i < q; i++)
    {
        suma+=v[i];
    }
    return suma/q;
}

void input(int v[], int q){
    for(int i=0; i<q; i++){
        cout<<"Numero "<<i+1<<" del vector: ";
        cin>>v[i];
    }
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
int mayor(int v[], int q){
    int max=v[0];
        for (int i = 0; i < q; i++)
        {
            if(max<v[i])
            max=v[i];
        }
    return max;
}

int menor(int v[], int q){
    int min = v[0];
        for (int i = 0; i < q; i++)
        {
            if(min>v[i])
            min=v[i];
        }
    return min;
}