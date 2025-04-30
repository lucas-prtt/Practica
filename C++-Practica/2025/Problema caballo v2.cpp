#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;


const int NIVEL = 64;
int tablero[NIVEL][8][8];
int static posibilidades[8][2] = {{1, 2},{-1, 2},{1, -2},{-1, -2},{2, 1},{-2, 1},{2, -1},{-2, -1}};

int esValido(int x, int y){
    return x<8 && x>=0 && y<8 && y>=0;
}

void mostrarTablero(int tableroAMostrar[8][8]){
    cout<<"=============\n";
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<tableroAMostrar[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void copiarNivel(int origen[8][8], int destino[8][8]){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            destino[i][j] = origen[i][j];
        }
    }
}
int hallarMovimientos(int x, int y, int profundidad){
    if (profundidad == NIVEL)
    return 1;
    if(profundidad > 0)
    {   
        copiarNivel(tablero[profundidad-1], tablero[profundidad]);
        if(esValido(x, y) && tablero[profundidad][x][y] == -1)
        tablero[profundidad][x][y] = profundidad;
        else
        return 0;
    }else{
        tablero[profundidad][x][y] = profundidad;
    }
    int v = 0;
    for(int i = 0; i<8 && !v ; i++){
        v = hallarMovimientos(x+posibilidades[i][0], y+posibilidades[i][1], profundidad+1);
    }
    return v;
}

int main(){
    int x_inicial , y_inicial;
    cout<<"Ingrese las posiciones de x y de y sucesivamente donde arracara el caballo:\n";
    cin>>x_inicial>>y_inicial;
    memset(tablero, -1, sizeof(tablero));
    hallarMovimientos(x_inicial, y_inicial, 0);
    mostrarTablero(tablero[63]);

}