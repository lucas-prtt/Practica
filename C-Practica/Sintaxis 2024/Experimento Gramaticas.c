#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Gramatica{
    char axioma;
    // un caracter no terminal
    char terminales[60];
    // lista de terminales: {'a', 'b', '\0'}
    char noterminales[60];
    // lista de no terminales: {'S', 'T', '\0'}
    char producciones[60][3];
    // lista de producciones:
        // primer elemento es un no terminal,
        // segundo y tercer elemento son:
            // terminal y \0
            // terminal y no terminal
    // Se entiende que el primer elemento produce el segundo y el tercero
    // 1->23
}Gramatica;

bool letraPerteneceAPalabra (char letra, char palabra[]){
    int i = 0;
    while(palabra[i]!='\0' && palabra[i]!=letra)
        i = i + 1;
    if (palabra[i] == letra)
        return true;
    else
        return false;
}

void crearGramatica(Gramatica *G){
    char input;
    int cuantosTerminales=0;
    int cuantosNoTerminales=0;

    printf("\nIngrese los terminales presionando enter tras ingresar cada uno\nIngrese @ como terminal para finalizar:\n");
    do{
        scanf("%c", &input);
        fflush(stdin); //Para que no tome el \n del enter

        if(input!='@'){
            G->terminales[cuantosTerminales] = input;
            cuantosTerminales = cuantosTerminales+ 1;
        }
        else{
            G->terminales[cuantosTerminales] = '\0';
        }

    }while(input!='@');
    //printf("%s", G->terminales);

    printf("\n\nIngrese los no terminales presionando enter tras ingresar cada uno\nIngrese @ como terminal para finalizar:\n");
    do{
        scanf("%c", &input);
        fflush(stdin); //Para que no tome el \n del enter

        if(input!='@'){
            G->noterminales[cuantosNoTerminales] = input;
            cuantosNoTerminales = cuantosNoTerminales+ 1;
        }
        else{
            G->noterminales[cuantosNoTerminales] = '\0';
        }

    }while(input!='@');
    //printf("%s", G->noterminales);

    bool axiomavalido;

    do {
        printf("\nIngrese el axioma: ");
        scanf("%c", &G->axioma);
        fflush(stdin);
        axiomavalido = letraPerteneceAPalabra(G->axioma, G->noterminales);
        if(!axiomavalido){
            printf("\nEse caracter no puede ser axioma pues no pertenece al grupo de no terminales\n");
        }
    }
    while(!axiomavalido);

    int cantidadDeProducciones = 0;
    bool esProduccionValida;
    char palabraInput[5];
    printf("\nIngrese las producciones\nFormato: \"S->aS\"\nPara finalizar ingrese solamente @:\n\n");
    do{
        do{
            printf("Produccion %d: ", cantidadDeProducciones+1);
            strcpy(palabraInput, "     ");
            scanf("%s", palabraInput);
            fflush(stdin);
            esProduccionValida =
                letraPerteneceAPalabra(palabraInput[0], G->noterminales) && //Izq es NT
                (
                    (letraPerteneceAPalabra(palabraInput[3], G->terminales) && palabraInput[4]=='\0') //Der es T
                        ||
                    (letraPerteneceAPalabra(palabraInput[3], G->terminales) && letraPerteneceAPalabra(palabraInput[4], G->noterminales)) //Der es T . NT
                );
            if(!esProduccionValida && palabraInput[0] != '@'){
                printf("\tIngreso incorrecto, intente de nuevo:\n");
            }

        }while(!esProduccionValida && palabraInput[0] != '@');

        if (esProduccionValida){
            G->producciones[cantidadDeProducciones][0] = palabraInput[0];
            G->producciones[cantidadDeProducciones][1] = palabraInput[3];
            G->producciones[cantidadDeProducciones][2] = palabraInput[4];
            cantidadDeProducciones = cantidadDeProducciones + 1;
        }
    }while(palabraInput[0]!='@');
return;
}


int main(){
    printf("Programa Iniciado:\n\n");
    Gramatica G;
    crearGramatica(&G);

    printf("Fin: Axioma: %c", G.axioma);

return 0;
}
