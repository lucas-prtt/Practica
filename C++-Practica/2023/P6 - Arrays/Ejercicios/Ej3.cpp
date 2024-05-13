#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void output(int[], int);
void input(int[], int);
int prom(int[], int);
void mostrargrandes(int[], int, int);

main(){
    int q = 40;
    int array[q];

    input(array, q);
    cout<<"Edades mayores al promedio: \n\n";
    mostrargrandes(array, q, prom(array, q));
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
        cout<<"Edad del alumno "<<i+1<<": ";
        cin>>v[i];
    }
}

void output(int v[], int q){
    for(int i=0; i<q; i++){
        cout<<v[i]<<endl;
    }
}
