#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

int static posibilidades[8][2] = {{1, 2},{-1, 2},{1, -2},{-1, -2},{2, 1},{-2, 1},{2, -1},{-2, -1}};

struct nodo_tablero{
    int tablero[8][8] = {0};
    nodo_tablero *movimientos[8] = {NULL};
};

void copiarMatriz(int origen[8][8], int destino[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            destino[i][j] = origen[i][j];
        }
    }
}

void mostrarTablero(int tablero[8][8]){
    cout<<"=============";
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<"\n";
    }
}


bool buscar(int paso, int x , int y , nodo_tablero * raiz, int tableroPadre[8][8]){
    copiarMatriz(tableroPadre, raiz->tablero);
    if(paso == 65){
        
        return true;
    }
    if(x<0 or x>=8 or y<0 or y>=8 or raiz->tablero[x][y] != 0){
        delete raiz;
        return false;
    }
    raiz->tablero[x][y]=paso;
    bool valido = false;
    //cout <<"<a<"<<x<<y<<">a>";
    mostrarTablero(raiz->tablero);
    for(int i=0; i<8 and !valido; i++){
        //cout<<i;
        raiz->movimientos[i] = new nodo_tablero;
        bool analizadoValido = buscar(paso+1, x+posibilidades[i][0], y+posibilidades[i][1], raiz->movimientos[i], raiz->tablero);
        valido = valido or analizadoValido;
        if(!analizadoValido){
            delete raiz->movimientos[i];
            raiz->movimientos[i] = NULL;
        }
    }
    //cout<<"b";
    return valido;
}
nodo_tablero * hallarEncontrado(int paso, nodo_tablero * raiz){
    if(paso == 64){
        return raiz;
    }
    for(int i = 0; i<8; i++){
        if(raiz->movimientos[i]!= NULL)
        {return hallarEncontrado(paso + 1, raiz->movimientos[i]);}
    }
    return NULL;
}
void hallarMovimientos(int x_inicial, int y_inicial, int tablero_encontrado[8][8]){
    nodo_tablero * arbol = new nodo_tablero;
    nodo_tablero * encontrado;
    bool encuentra = buscar(1, x_inicial, y_inicial, arbol, arbol->tablero);
    if (!encuentra){
        cout<<"Imposible";
    }
    else{
        cout<<"Encontrado!\n";
        encontrado = hallarEncontrado(1, arbol);
    }
    copiarMatriz(encontrado->tablero, tablero_encontrado);

    delete arbol;
    return;
}


int main(){
    int x_inicial , y_inicial;
    cout<<"Ingrese las posiciones de x y de y sucesivamente donde arracara el caballo:\n";
    cin>>x_inicial>>y_inicial;
    int tablero_encontrado[8][8];
    hallarMovimientos(x_inicial, y_inicial, tablero_encontrado);
    mostrarTablero(tablero_encontrado);

}