#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void * printUpTo1000(void* _);
void * checkAndPrint(void* numero);
int main(){
    printf("Hola World!");
    printf("\nCon threads\n");
    
    pthread_t * thread1 ;
    pthread_t * thread2 ;
    thread1 = malloc(sizeof(thread1));
    thread2 = malloc(sizeof(thread2));
    pthread_create(thread1, NULL, printUpTo1000, NULL);
    pthread_create(thread2, NULL, printUpTo1000, NULL);
    pthread_join(*thread1, NULL); //Espera a que el thread termine
    pthread_join(*thread2, NULL);
    free(thread1);
    free(thread2);
    
    int numero = 1;
    pthread_t  * otroThread;
    otroThread = malloc(sizeof(otroThread));
    pthread_create(otroThread, NULL, checkAndPrint, (void*)&numero);
    getchar();
    numero = 0;
    pthread_join(*otroThread, NULL);

    free(otroThread);
    return 0;

}



void * printUpTo1000(void* _){
    for (int i = 0; i < 1000; i++){
        printf(" %d ", i);
    }
    pthread_exit(0);
}

void * checkAndPrint(void* numero){
        printf("\n\nPress enter to stop.\nWaiting for incoming conections");
    while(*(int*)numero){
        printf(".");
        fflush(stdout);
        usleep(500000);
        printf(".");
        fflush(stdout);
        usleep(500000);
        printf(".");
        fflush(stdout);
        usleep(500000);
        printf("\b\b\b");
        printf("   ");
        printf("\b\b\b");
        fflush(stdout);
        usleep(500000);
    }
}