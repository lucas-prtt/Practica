#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int ingresoverificadoATOI(int);
float ingresoverificadoATOF(int);

main(){
    int a;
    a = ingresoverificadoATOI(100);
    float b;
    b = ingresoverificadoATOF(100);
    cout<<"\n\n"<<a<< " + 1 = "<<a+1;
    cout<<"\n\n"<<b<<" + 1 = "<<b+1;
    getch();
    return 0;
}
int ingresoverificadoATOI(int lmax){
    int num, i;
    char palabra[lmax];

    do{
        for(int q=0; q<lmax; q++) //Pone todo caracter en 0 (vacio)
            palabra[lmax]=0;
        
        cin.getline(palabra, sizeof(palabra)); //Ingresa valor
        fflush(stdin);

        i=0;
        while(i<lmax and isdigit(palabra[i])){ //Busca ultimo caracter que no es un numero
            i++;
        }

    }while(i==0 or palabra[i]!=0); //Si el ultimo caracter que no es un numero esta vacio, o es el primero, se vuelve a introducir
    //Solo continua si palabra es un array de numeros continuo y no vacio (No negativo)
    num = atoi(palabra);
    return num;
}
float ingresoverificadoATOF(int lmax){
    int i;
    float num;
    char palabra[lmax];
    bool yahubounpunto;
    do{
        for(int q=0; q<lmax; q++) //Pone todo caracter en 0 (vacio)
            palabra[lmax]=0;
        
        cin.getline(palabra, sizeof(palabra)); //Ingresa valor
        fflush(stdin);
        yahubounpunto=false;
        i=0;
        while(i<lmax and (isdigit(palabra[i]) or (!yahubounpunto and palabra[i]==('.')))){ //Busca ultimo caracter que no es un numero
            if(palabra[i]=='.')
            yahubounpunto=true;
            i++;
        }

    }while(i==0 or palabra[0] == '.' or palabra[i]!=0); //Si el ultimo caracter que no es un numero esta vacio, o es el primero, o es un punto, se vuelve a introducir
    //Solo continua si palabra es un array de numeros continuo con a lo sumo un punto y no es vacio (No negativo)
    num = atof(palabra);
    return num;
}