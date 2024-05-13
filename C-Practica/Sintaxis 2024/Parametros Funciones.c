#include <stdio.h>
#include <string.h>
//Esto es nomas para ver si hay muchos cambios en el paso de parametros entre c y c++




char mayusculaDe(char letra){
    char letrasymayusculas[2][30];
    strcpy((letrasymayusculas[0]), "abcdefghijklmnopqrstuvwxyz");
    strcpy((letrasymayusculas[1]), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for(int i = 0; i<26; i=i+1){
        if(letra == letrasymayusculas[0][i]){
            return letrasymayusculas[1][i];
        }
    }
    return letra;
}

void TodoMayus(char palabra[]){

    for (int i = 0; palabra[i]!='\0'; i=i+1){
        char letra = palabra[i];
        printf("Operada letra %d:\t%c -> %c\n", i, letra, mayusculaDe(letra));
        letra = mayusculaDe(letra);
        palabra[i] = letra;
    }
    return;
}



void contardeXaY(int x, int y){
    for(int i = x; i<y; i=i+1){
        printf(" %d ", i);
    }
}

int main(){
    char palabra[50];
    strcpy(palabra, "Mundo");
    TodoMayus(palabra);
    printf("Hola %s! \n", palabra);
    contardeXaY(5, 24);
    return 0;
}
