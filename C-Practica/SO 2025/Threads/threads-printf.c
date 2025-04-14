#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void printUpToANumber(int* numero);


int main(){
    printf("Hola World!");
    int * num;
    num = malloc(sizeof(num));
    *num = 40;
    printUpToANumber(num);

    print("\nAhora con threads\n");
    *num = 10;
    pthread_t thread ;
    pthread_create(&thread, NULL, printUpToANumber, num);
    printUpToANumber(num);


    
    
    free(num);




    return 0;

}


void printUpToANumber(int* number){
    for (int i = 0; i < *number; i++){
        printf(" %d ", i);
    }
    return;
}