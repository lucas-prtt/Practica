#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;


const int filas = 5;
const int columnas = 5;
const int NIVEL = filas*columnas;
int tablero[columnas][filas];
int static posibilidades[8][2] = {{1, 2},{-1, 2},{1, -2},{-1, -2},{2, 1},{-2, 1},{2, -1},{-2, -1}};

int esValido(int x, int y){
    return x<columnas && x>=0 && y<filas && y>=0;
}

void mostrarTablero(int tableroAMostrar[columnas][filas]){
    cout<<"=============\n";
    for(int i=0; i<columnas; i++){
        for(int j=0; j<filas; j++){
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

    for(int i = 0; i<8 && !v ; i++){ //Por cada posibilidad hasta que se encuentre una valida
        v = hallarMovimientos(x+posibilidades[i][0], y+posibilidades[i][1], profundidad+1);
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
    hallarMovimientos(x_inicial, y_inicial, 0);
    mostrarTablero(tablero);

}