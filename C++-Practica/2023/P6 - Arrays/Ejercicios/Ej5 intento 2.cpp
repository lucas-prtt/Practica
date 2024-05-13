#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

void output(int[], int); //Muestra todos los valores de un array
void inputHasta0(int[],int&); //Pide numeros para poner en un array hasta que se escriba cero
void ordenar(int[], int); //Ordena de menor a mayor los valores de un array
int menor(int[], int); //Devuelve el menor valor de un array, mientras que este no sea cero
void copiarArray(int[] , int , int[]); //Copia el primer array al segundo
void eliminarMenor(int[], int); //Establece el menor valor de un array en cero
int valorNoCero(int[], int); //Agarra el primer valor de un array el cual no sea cero
void entre500Y1(int[], int); //Elimina los valores del array que no estan entre 500 y 1
void fueraDe500Y1(int[], int); //Elimina los valores del array que estan entre 500 y 1
void outputMenosCero(int[], int); //Muestra todos los valores de un array menos los que valen 0
main(){
    int q = 9999;    //Maxima cantidad de numeros posibles
    int array[q];
    inputHasta0(array, q);
    int arraydentro[q];
    int arrayfuera[q];
    copiarArray(array, q, arraydentro);
    copiarArray(array, q, arrayfuera);
    entre500Y1(arraydentro, q);
    fueraDe500Y1(arrayfuera, q);
    ordenar(arraydentro, q);
    ordenar(arrayfuera, q);
    cout<<"\nValores entre 500 y 1 ordenados de menor a mayor: \n\n";
    outputMenosCero(arraydentro, q);
    cout<<"\nValores no entre 500 y 1 ordenados de menor a mayor: \n\n";
    outputMenosCero(arrayfuera, q);
    getch();
    return 0;
}

void outputMenosCero(int v[], int q){
    cout<<"\n\n\n(";
    bool primero=true;
    for (int i = 0; i < q; i++)
    {   if(v[i]!=0)
        {
            if(primero){
            cout<<v[i];
            primero = false;
            }
            else
            cout<<"; "<<v[i];
        }
    }
    cout<<")";
}

void entre500Y1(int v[], int q){
    int en[q];
    for (int i = 0; i < q; i++)
    {
        en[i]=0;
    }
    
    int k=0;
    for (int i = 0; i < q; i++)
    {
        if(v[i]<=500 && v[i]>=1){
            en[k]=v[i];
            k++;
        }
    }

    copiarArray(en, q, v);
    

}

void fueraDe500Y1(int v[], int q){
    int fuera[q];
    for (int i = 0; i < q; i++)
    {
        fuera[i]=0;
    }
    int k=0;
    for (int i = 0; i < q; i++)
    {
        if(v[i]>500 || v[i]<1){
            fuera[k]=v[i];
            k++;
        }
    }

    copiarArray(fuera, q, v);

}

void ordenar(int v[], int q)
{
    int ord[q];
    for (int i = 0; i < q; i++)
    {
        ord[i]=menor(v, q);
        eliminarMenor(v, q);
    }
    copiarArray(ord, q, v);
    
}

void inputHasta0(int v[], int &q){
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
    int min = valorNoCero(v, q);
        for (int i = 0; i < q; i++)
        {
            if(v[i]!=0 && min>v[i])
            min=v[i];
        }
    return min;
}

void copiarArray(int v1[], int q, int v2[]){
    for (int i = 0; i < q; i++)
    {
        v2[i] = v1[i];
    }
}

void eliminarMenor(int v[], int q){
    int m = menor(v, q);
    for (int i = 0; i < q; i++)
    {
        if (v[i]==m)
        v[i]=0;
    }
}

int valorNoCero(int v[], int q){
    for (int i = 0; i < q; i++)
    {
        if(v[i]!=0)
        return v[i];
    }
    return 0;
}