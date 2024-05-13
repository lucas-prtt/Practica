#include <iostream>
#include <conio.h>
#include <fstream>
/*Una empresa fabrica 6 productos diferentes y cada uno de ellos puede terminarse en 3 colores
distintos. Se Tienen dos archivos de texto. El primero tiene los nombres de los productos,
seguido inmediatamente por los nombres de los colores. El otro archivo contiene información
de los lotes de producción terminados en la semana. Por cada lote de producción se guarda una
línea con: el código del producto (entero con valores entre 0 y 5), el código del color (entero
entre 0 y 2) y la cantidad producida. Dentro de la línea, los valores se separan mediante un
tabulador.
Se pide armar un programa que a partir de la información en los archivos informe:
1. De cual combinación producto-color se produjo la mayor cantidad de unidades. Informar
usando los nombres, no los códigos, y la cantidad producida para esa combinación.
2. Nombre del producto del cual se produjo la menor cantidad de unidades, y cuantas fueron.
3. Que combinación producto-color tuvo el mayor promedio de unidades por lote. Informar
usando los nombres y el promedio correspondiente.
Nota: Usando los archivos datosG04E15nombres.txt y datosG04E15producc.txt los
resultados son:
1. cantimplora en color azul con 588 unidades producidas
2. mochila con 705 unidades
3. cantimplora en color verde con un promedio de 108 unidades por lote*/

using namespace std;




main(){
    int matriz[3][75];
    string vector[9];
    int resumen[3][6];
    string arch2 = "datosG04E15nombres.txt";
    string arch1 = "datosG04E15producc.txt";
    ifstream archivo1(arch1.c_str());
    ifstream archivo2(arch2.c_str());

    for(int j=0; j<75; j++){
        for(int i=0; i<3; i++){
            archivo1>>matriz[i][j];
            }
    }
    for(int i=0; i<9; i++){
        archivo2>>vector[i];
    }

    /*    ----------------------------Comprobar que ande todo bien-----------------------------*/
    /**/
    for(int j=0; j<75; j++){
        cout<<"INSERT INTO tabla VALUES (";
        for(int i=0; i<3; i++){
            cout<<matriz[i][j];
            if(i!=2)cout<<",";
            }
        cout<<");"<<endl;
    }/*
    for(int i=0; i<9; i++){cout<<vector[i]<<" - ";}
    */
    for(int i=0; i<3;i++){
        for(int j=0; j<6; j++){
            resumen[i][j]=0;
        }}
    /*for(int i=0; i<3;i++){
        for(int j=0; j<6; j++){
            cout<<resumen[i][j]<<"  ";}
        cout<<"\n";
    }*/
    
    for(int j=0; j<75; j++){
            resumen[matriz[1][j]][matriz[0][j]]+=matriz[2][j];
    }

    for(int i=0; i<3;i++){
        for(int j=0; j<6; j++){
            cout<<resumen[i][j]<<"  ";}
        cout<<"\n";
    }

    getch();
    return 0;
}




