#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esprefijo(char prefijo[], char cadena[]);
void concatenar(char destino[], char palabra1[], char palabra2[]);
bool vacia(char cadena[]);
int longitudcadena(char cadena[]);
int main(){
    char palabra1[200];
    char palabra2[200];
    char concatenada[400];
    printf("Hola\nEscriba una palabra: ");
    scanf("%s", &palabra1);
    printf("\nLongitud: %d\nEscriba algo mas: ", longitudcadena(palabra1));
    scanf("%s", &palabra2);
    concatenar(concatenada, palabra1, palabra2);
    printf("\nSi junto las dos palabras me queda %s.\n", concatenada);
    if (esprefijo(palabra1, palabra2))
    printf("\n%s es prefijo de %s!", palabra1, palabra2);
    else
    printf("\n%s NO es prefijo de %s", palabra1, palabra2);

    return 0;

}

bool esprefijo(char prefijo[], char cadena[]){
    int i = -1;
    if (longitudcadena(cadena) < longitudcadena(prefijo))
    return false;
    do{
        i++;
        if (prefijo[i]==0){
        //printf("\n-----------------\n i = %d \nTrue in prefijo = %c and cadena = %c\n----------------\n", i, prefijo[i], cadena[i]);
        return true;
        }
        //printf(" %c == %c ? ", prefijo[i], cadena[i]);
        
    }while(cadena[i]==prefijo[i]);
    return false;
}

int longitudcadena(char cadena[]){
    int i=0;
    while(cadena[i]!='\0'){
        i++;
    }
    return i;
}

bool vacia(char cadena[]){
    return cadena[0]=='\0';
}

void concatenar(char destino[], char palabra1[], char palabra2[]){
    int i = 0;
    int j = 0;
    while(palabra1[i]!='\0'){
        destino[i] = palabra1[i];
        i++;
    }
    while(palabra2[j]!='\0'){
        destino[i] = palabra2[j];
        i++;
        j++;
    }
    destino[i]='\0';
    return;
}
    

