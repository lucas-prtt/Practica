#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int columna(char);
void esFloat(char* );
int main(){
    char palabra[500];   

    scanf("%s", palabra);
    esFloat(palabra);

    return 0;
}

void esFloat(char palabra[]){
    int TT[6][3]={
        {2 ,1 ,5 },
        {2 ,5 ,5 },
        {2 ,5 ,3 },
        {4 ,5 ,5 },
        {4 ,5 ,5 },
        {5 ,5 ,5 }
        };

    int e = 0;
    int i;   
    int col = 0;
    for (i = 0; palabra[i]!='\0'; i++){
        col = columna(palabra[i]);
        if(col == -1){
            printf("\nERROR, caracter no aceptado");
            return;
        }
        e = TT[e][col];
    }
    if(e==2 || e==4)
        printf("Numero valido");
    else
        printf("No es numero");
    return;
}
int columna(char letra){
    if(letra<='9' && letra>='0'){
        return 0;
    }else if (letra == '+' || letra == '-'){
        return 1;
    }else if (letra == '.'){
        return 2;
    }else 
        return -1;    
}


