#include <iostream>
#include <conio.h>
using namespace std;

int busquedabinaria(int[], int, int);
main(){
    int vector[23]={7, 3, 8, 9, 12, 89, 6, 8, 22, 75, 21, 64, 7, 98, 3, 1, -4, 300, 75, -40, 53223, 654, 77};
    int temp;
    bool cambio=true;
    cout<<"|      cargando     |\n ";
    for(int i=0; i<22 and cambio; i++){
        cambio=false;
        for(int q=0; q<23-i; q++){
            if(vector[q]>vector[q+1]){
            temp=vector[q];
            vector[q]=vector[q+1];
            vector[q+1]=temp;
            cambio=true;
            }
            }
        cout<<"►";
    }
    cout<<"\n\n";
    for(int i=0; i<23; i++){cout<<vector[i]<<" ";}
    cout<<"\n\nIngrese un numero y le diremos la posicion\n";
    int elegido;
    cin>>elegido;
    int posicion=busquedabinaria(vector, 23, elegido);
    if(posicion!=-1)
    cout<<posicion+1;
    else 
    cout<<"no esta";
    getch();
    return 0;
}
int busquedabinaria(int vector[], int longitud, int buscado){
//   int pos=-1,desde=0,hasta=longitud-1,medio;
//   while(desde<=hasta && pos==-1)
//   {
//       medio=(desde+hasta)/2;
//       if(vector[medio]==buscado)
//           pos=medio;
//       else
//       {
//           if(buscado<vector[medio])
//               hasta=medio-1;
//           else
//               desde=medio+1;
//       }
//   }
//   return pos;
 
    int mayor=longitud, menor=0, promedio;
    while(mayor>=menor){
        promedio=(mayor+menor)/2;
        if(buscado==vector[promedio])
        return promedio;
        else if(buscado<vector[promedio])
        mayor=promedio-1;
        else if(buscado>vector[promedio])
        menor=promedio+1;
    }
    return -1;
}