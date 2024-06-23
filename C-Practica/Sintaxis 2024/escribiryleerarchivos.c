#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    FILE * arch = fopen("ejemplo.txt", "r+"); //Abre el archivo en modo lectura y escritura
    char palabra[100];
    char palabra2[55];
    fscanf(arch, "%s", palabra); //Lee primer palabra
    fscanf(arch, "%s", palabra); //Lee segunda palabra
    printf("\"%s\"",palabra); //Imprime primera palabra
    fgets(palabra2, 55, arch);
    printf("\nP2 -> %s\n", palabra2);
    fgets(palabra, 100, arch);
    printf("\nP1 -> %s\n", palabra);
    fseek(arch, 0, 2); //Mueve puntero a fin del archivo
    fprintf(arch, " %s", palabra); //Añade segunda palabra a fin del archivo
    fseek(arch, 0, 0);
    printf("\n");
    char caracter;
    fseek(arch, 0, 0);
    for (int i=0; i<100; i++)
    {
        fscanf(arch, "%c", &caracter);
        printf("%c\n", caracter);
    }        
    printf("%c FIN", caracter);
    return 0;
}



