#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void output(int[], int);
void input(int[], int);
int max(int[], int);


main(){
    int q = 30;
    int array[q];

    input(array, q);
    cout<<endl<<endl<<"Numero maximo: "<< max(array, q);
    getch();
    return 0;
}




int max(int v[], int q){
    int max = v[0];
    for (int i = 0; i < q; i++)
    {
        if(v[i]>max)
        max=v[i];
    }
    return max;
}

void input(int v[], int q){
    for(int i=0; i<q; i++){
        cout<<"Ingrese el numero "<<i+1<<": ";
        cin>>v[i];
    }
}

void output(int v[], int q){
    for(int i=0; i<q; i++){
        cout<<v[i]<<endl;
    }
}