#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv){
    printf("Se introdujo %s", argv[1]);
    FILE * arch = fopen("texto.txt", "w");
    for (int i=0; i<(*(argv[2]));i++)
        fprintf(arch, "%s", argv[1]);
    return 0;
}

