#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct Empleado
{
    int dni=0;
    char nombreyapellido[100];
    char patente[8];
    int zona;
};

struct Zona
{
    int motos = 0;
    int autos = 0;
    int camiones = 0;
    int camionetas = 0;
};

void IngresarRepartidores(Empleado[], Empleado[], Empleado[], Empleado[], Zona[]); //Realiza todo el ingreso
bool Haylugar(int v, int z, Zona[]); // Se fija si hay lugar para x medio de transporte en x zona y si hay suma 1 a dicha zona y devuelve true. Si no devuelve false.
string vehiculonumapal(int); //Devuelve el nombre del vehiculo en funcion de un numero del 1 al 4
void ordenarempleados(Empleado[]);//Ordena los empleados por dni
int cuantosempleados(Empleado[]);//Devuelve la cantidad de empleados en un vector de empleados fijandose el primer empleado con DNI 0
void escribirarchivo(char[],Empleado[]);
bool archivoexiste(char[]);
void cargararchivos(char[], Empleado[]);

int main()
{   //Declaracion de variables
    Empleado motos[280];
    Empleado autos[280];
    Empleado camiones[280];
    Empleado camionetas[280];
    Zona zonas[14];
    //Comienza el programa
    if (archivoexiste("RepMoto.dat") and archivoexiste("RepAuto.dat") and archivoexiste("RepCamion.dat") and archivoexiste("RepCamioneta.dat"))
    {cout<<"Desea cargar los datos de los archivos o crear archivos nuevos?\n1. Ingresar datos y crear archivos nuevos\n2. Cargar archivos existentes";
    int r;
    do{cin>>r;}while(r!=1 and r!=2); 
    if(r==1){
    IngresarRepartidores(motos, autos, camiones, camionetas, zonas);
    ordenarempleados(motos);
    ordenarempleados(autos);
    ordenarempleados(camiones);
    ordenarempleados(camionetas);
    escribirarchivo("RepMoto.dat", motos);
    escribirarchivo("RepAuto.dat", autos);
    escribirarchivo("RepCamion.dat", camiones);
    escribirarchivo("RepCamioneta.dat", camionetas);
    }else{

    }
    getch();
    return 0;
}

void IngresarRepartidores(Empleado motos[], Empleado autos[], Empleado camiones[], Empleado camionetas[], Zona zonas[])
{
    int qmotos = 0, qautos = 0, qcamiones = 0, qcamionetas = 0;
    int transporte;
    Empleado temp;
    cout << "Comenzando ingreso, digite un numero de documento igual a cero para finalizar " << endl;
    cout << endl;
    cout << "Ingrese el numero de documento del repartidor: ";
    cin >> temp.dni;
    if (temp.dni == 0)
    {
        return;
    }
    else
    {
        do
        {
            cout << "\nIngrese el nombre del repartidor: ";
            fflush(stdin);
            cin.getline(temp.nombreyapellido, sizeof(temp.nombreyapellido));

            do
            {

                cout << "\nIngrese el medio de transporte:\n1. Moto\n2. Auto\n3. Camion\n4. Camioneta\n\n>";
                cin >> transporte;
            } while (transporte <= 0 or transporte >= 5);

            do
            {
                cout << "\nDigite la zona en la que quiere trabajar: ";
                cin >> temp.zona;
            } while (temp.zona <= 0 or temp.zona >= 15);

            if (Haylugar(transporte, temp.zona, zonas))
            {
                cout << "\nIngrese la patente del vehiculo sin espacios: ";
                fflush(stdin);
                cin.getline(temp.patente, sizeof(temp.patente));
                if (transporte == 1)
                {
                    motos[qmotos] = temp;
                    qmotos++;
                }
                else if (transporte == 2)
                {
                    autos[qautos] = temp;
                    qautos++;
                }
                else if (transporte == 3)
                {
                    camiones[qcamiones] = temp;
                    qcamiones++;
                }
                else if (transporte == 4)
                {
                    camionetas[qcamionetas] = temp;
                    qcamionetas++;
                }
                cout << "\n\n\t\tIngreso realizado con exito!\n\n";
                getch();
            }
            else
            {
                cout << "\nNo hay mas lugar para " << vehiculonumapal(transporte) << " en la zona " << temp.zona << "\n\n";
                getch();
            }
            cout << endl;
            cout << "Ingrese el numero de documento del repartidor: ";
            cin >> temp.dni;
        } while (temp.dni != 0);
        return;
    }
}
bool Haylugar(int vehiculo, int zona, Zona zonas[])
{
    if (vehiculo == 1)
    {
        if (zonas[zona - 1].motos < 20)
        {
            zonas[zona - 1].motos++;
            return true;
        }
        else
            return false;
    }
    if (vehiculo == 2)
    {
        if (zonas[zona - 1].autos < 20)
        {
            zonas[zona - 1].autos++;
            return true;
        }
        else
            return false;
    }
    if (vehiculo == 3)
    {
        if (zonas[zona - 1].camiones < 20)
        {
            zonas[zona - 1].camiones++;
            return true;
        }
        else
            return false;
    }
    if (vehiculo == 4)
    {
        if (zonas[zona - 1].camionetas < 20)
        {
            zonas[zona - 1].camionetas++;
            return true;
        }
        else
            return false;
    }
    return false;
}
string vehiculonumapal(int n)
{
    switch (n)
    {
    case 1:
        return "motos";
    case 2:
        return "autos";
    case 3:
        return "camiones";
    case 4:
        return "camionetas";
    }
    return "";
}
int cuantosempleados(Empleado empleados[]){
    int i=0, t=0;
    while(empleados[i].dni!=0){ 
        //Calcula el tamaño del vector empleados utilizado mediante la restriccion de que el dni no puede ser 0
        t++;
        i++;
    }
    return t;
}
void ordenarempleados(Empleado emp[]){
    int t=cuantosempleados(emp);
    Empleado temp;
    for(int q=0; q<t; q++){
        for(int l=0; l<t-q-1; l++){
            if(emp[l].dni>emp[l+1].dni){
                temp = emp[l];
                emp[l] = emp[l+1];
                emp[l+1] = temp;
            }
        }
    }
}
void escribirarchivo(char nombre[], Empleado lista[]){
    int t=cuantosempleados(lista);
    FILE * archivo = fopen(nombre, "w");
        fwrite(&lista, sizeof(Empleado), t, archivo);
    fclose(archivo);
}
bool archivoexiste(char nombre[]){
    FILE * archivo; 
    archivo = fopen(nombre, "r");
    if (archivo!=NULL){
    fclose(archivo);
    return true;
    }
return false;
}
