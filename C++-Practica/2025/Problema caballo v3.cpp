#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


const int filas = 8;
const int columnas = 8;
const int NIVEL = filas*columnas;
int tablero[columnas][filas];
int prioridades[columnas][filas];
int static posibilidades[8][2] = {{1, 2},{-1, 2},{1, -2},{-1, -2},{2, 1},{-2, 1},{2, -1},{-2, -1}};

int esValido(int x, int y){
    return x<columnas && x>=0 && y<filas && y>=0;
}
int valorPrioridad(int x, int y){ //Asigna un valor de prioridad en funcion de la distancia al centro: mas en la esquina = mas prioridad
    double centroX = (columnas - 1) / 2.0;
    double centroY = (filas - 1) / 2.0;
    return sqrt(pow(x-centroX,6)+pow(y-centroY, 6)); 
}
void rellenarPrioridad(int matriz[columnas][filas]){ //Rellena una matriz temporal para no tener que calcular las prioridades cientos de veces
    for(int i=0; i<columnas; i++){
        for(int j=0; j<filas; j++){
            matriz[i][j] = valorPrioridad(i, j);
        }
    }
}
int compararPrioridad(const void * elem1, const void * elem2){ //Compara la prioridad de la posicion elem1 (x, y) y elem2 (x, y)
    int *f = (int*)elem1;
    int *s = (int*)elem2;
    int prioridadF = prioridades[f[0]][f[1]];
    int prioridadS = prioridades[s[0]][s[1]];
    if (prioridadF > prioridadS) return -1;
    if (prioridadS > prioridadF) return 1;
    return 0;
}

void mostrarTablero(int tableroAMostrar[columnas][filas]){
    cout<<"=============\n";
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            cout<<tableroAMostrar[j][i]<<" ";
        }
        cout<<"\n";
    }
}
int hallarMovimientos(int x, int y, int profundidad){
    if (profundidad == NIVEL) // Si se llega a 64, terminar
        return 1;

    if(esValido(x, y) && tablero[x][y] == -1) //Si el colocamiento es valido
        tablero[x][y] = profundidad; //Rellenar tablero
    else
        return 0; //Sino volver
    
        //Siendo valido...
    int v = 0; // V = VALIDEZ
    int opcionesOrdenadas[8][2];
    for(int i=0; i<8; i++){
        opcionesOrdenadas[i][0] = x + posibilidades[i][0];
        opcionesOrdenadas[i][1] = y + posibilidades[i][1];
    } // Mete los valores de posibilidades de movimientos en terminos absolutos (sumando x e y)
    qsort(opcionesOrdenadas, 8, sizeof(opcionesOrdenadas[0]), compararPrioridad); //ordena las posibilidades que conviene explorar primero en funcion de su distancia al centro
    for(int i = 0; i<8 && !v ; i++){ //Por cada posibilidad hasta que se encuentre una valida
        v = hallarMovimientos(opcionesOrdenadas[i][0], opcionesOrdenadas[i][1], profundidad+1);
        //Fijarse si es valido y actualizar V
    }
    if (v == 0) // Si es invalido
    tablero[x][y] = -1; // Revertir cambios

    return v; // Devolver 1 si es valido, 0 si es invalido
}

int main(){
    int x_inicial , y_inicial;
    cout<<"Ingrese las posiciones de x y de y sucesivamente donde arracara el caballo:\n";
    cin>>x_inicial>>y_inicial;
    memset(tablero, -1, sizeof(tablero));
    rellenarPrioridad(prioridades);
    hallarMovimientos(x_inicial, y_inicial, 0);
    mostrarTablero(tablero);

}