#include<iostream>
#include<string.h>
using namespace std;

struct Empleados{
    int dni;
    char nombreyapellido[100];
    char patente[8];
    int zona;
}registro[1120];

struct Zona{
    int motos=0;
    int autos=0;
    int camiones=0;
    int camionetas=0;
}zonas[14];

int IngresarRepartidores(Empleados registro[], Zona zonas[]);

int main(){
    IngresarRepartidores(registro, zonas);
return 0;}

int IngresarRepartidores(Empleados registro[], Zona zonas[])
    {
        int i=0;
        char transporte[10];
        char v1[5] = "Moto";
        char v2[5] = "Auto";
        char v3[7] = "Camion";
        char v4[10] = "Camioneta";
        cout<<"Digite un número de documento igual a cero para finalizar "<<endl;
        cout<<endl;
        cout<<"Ingrese el número de documento del repartidor: ";
        cin>>registro[i].dni;
            if (registro[i].dni==0){
                return 0;}
            else{
                do{
                    if (registro[i].dni!=0){

                    cout<<"Digite el nombre del repartidor: ";
                    fflush(stdin);
                    cin.getline(registro[i].nombreyapellido, sizeof(registro[i].nombreyapellido));
                    cout<<"Digite el medio de transporte: ";
                    cin>>transporte;
                    cout<<"Digite la patente del vehiculo: ";
                    cin>>registro[i].patente;
                    cout<<"Ingrese el codigo de la zona de actividad (del 1 al 14): ";
                    cin>>registro[i].zona;
                    if (strcmpi(transporte, v1)==0 && zonas[registro[i].zona].motos<20){
                        zonas[registro[i].zona].motos++;}
                    else {
                        if (strcmpi(transporte, v2)==0 && zonas[registro[i].zona].autos<20){
                            zonas[registro[i].zona].autos++;}
                        else {
                            if (strcmpi(transporte, v3)==0 && zonas[registro[i].zona].camiones<20){
                                zonas[registro[i].zona].camiones++;}
                            else {
                                if (strcmpi(transporte, v4)==0 && zonas[registro[i].zona].camionetas<20){
                                    zonas[registro[i].zona].camionetas++;}
                                    else {
                                        cout<<"          'No hay cupo disponible'          "<<endl;}
                                }
                            }
                        }
                    i++;
                    cout<<endl;
                    cout<<"Ingrese el número de documento del repartidor: ";
                    cin>>registro[i].dni;}
                    }while(registro[i].dni!=0);
                }
    }
