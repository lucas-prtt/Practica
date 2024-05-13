#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct empleado
{
    int zona;
    int dni;
    char patente[7];
    char nombre[100];
};

void ingresarDatos();
void empleadosPorTransporte();
void transportesNoDisponibles();
void zonaMasEmpleados();

main()
{
    int a;
    while (true)
    {
    cout << "Seleccione que accion desea realizar:\n";
    cout << "1. Ingresar repartidores (sobreescribe repartidores anteriores)\n";
    cout << "2. Listar la cantidad de empleados por medio de transporte\n";
    cout << "3. Mostrar que medios de transporte no tienen ningun empleado asignado\n";
    cout << "4. Mostrar zona con mas empleados\n";
    cout << "5. Salir\n\n";
        cin>>a;
        cout<<"\n\n\n\n";
        switch (a)
        {
        case 1:
            ingresarDatos();
            break;
        case 2:
            empleadosPorTransporte();
            break;
        case 3:
            transportesNoDisponibles();
            break;
        case 4:
            zonaMasEmpleados();
            break;
        case 5:
            return 0;
        }
    }
}
void ingresarDatos(){}
void empleadosPorTransporte(){}
void transportesNoDisponibles(){}
void zonaMasEmpleados(){}