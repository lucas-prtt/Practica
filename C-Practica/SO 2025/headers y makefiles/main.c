#include "headerDelMain.h"

int main(){
    imprimirEntero(9);
    int x = 4;
    for(int i = 1; i<(x*x); i*=7){
        x++;
    }
    imprimirEntero(x);
    return 0;
}

// Se compila con:

// gcc -c main.c ->  Crea main.o (ya incluye el header)
// gcc -c funciones.c -> Crea funciones.o
// gcc main.o, funciones.o -o "ejecutable" -> linkea los .o para hacer un .exe

// Alternativamente:
// gcc main.c funciones.c -o "ejecutable" -> Crea el .exe sin guardar los .o en el medio
// Tiene como desventaja que si se cambia algo en uno de los dos archivos, hay que recompilar los dos, ya que el .o del que no se cambio no se lo tiene de antes
