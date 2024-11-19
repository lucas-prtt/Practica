#include <stdio.h>

typedef struct estructura{
    int entero;
}estructura;

int main(){
    estructura unaEstructura;
    int estructura;
    unaEstructura.entero = 5;
    estructura = 3;
    printf("\n ----> %d\n", estructura);
    printf("\n ----> %d\n\n", unaEstructura.entero);
    return 0;
}


