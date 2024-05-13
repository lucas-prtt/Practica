#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void reverse(int[], int);
void output(int[], int);
void input(int[], int);


main(){
    int q = 40;
    int array[q];

    input(array, q);
    reverse(array, q);
    getch();
    return 0;
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

void reverse(int v[], int q){
    for(int i=q-1; i>=0; i--){
        cout<<v[i]<<"\t";
    }
}