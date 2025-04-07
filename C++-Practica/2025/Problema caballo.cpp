#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct nodo_tablero{
    int tablero[8][8] = {0};
    nodo_tablero *movimientos[8];
};

void hallarMovimientos(int x_inicial, int y_inicial, int tablero_encontrado[8][8]){
    nodo_tablero * arbol = new nodo_tablero;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            tablero_encontrado[i][j] = arbol->tablero[i][j];
        }
    }
    delete arbol;
    return;
}

void mostrarTablero(int tablero[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int x_inicial , y_inicial;
    cout<<"Ingrese las posiciones de x y de y sucesivamente donde arracara el caballo:\n";
    cin>>x_inicial>>y_inicial;
    int tablero_encontrado[8][8];
    hallarMovimientos(x_inicial, y_inicial, tablero_encontrado);
    mostrarTablero(tablero_encontrado);

}