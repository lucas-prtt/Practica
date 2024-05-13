#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;


struct Empleado
{
    int dni = 0;
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


void IngresarRepartidores(Empleado[], Empleado[], Empleado[], Empleado[], Zona[]); // Realiza todo el ingreso
bool Haylugar(int v, int z, Zona[]);                                               // Se fija si hay lugar para x medio de transporte en x zona y si hay suma 1 a dicha zona y devuelve true. Si no devuelve false.
void ValidaEnteros(int&);
string vehiculonumapal(int);                                                       // Devuelve el nombre del vehiculo en funcion de un numero del 1 al 4
void ordenarempleados(Empleado[]);                                                 // Ordena los empleados por dni
int cuantosempleados(Empleado[]);                                                  // Devuelve la cantidad de empleados en un vector de empleados fijandose el primer empleado con DNI 0
void escribirarchivo(char[], Empleado[]);
bool archivoexiste(char[]);
void cargararchivo(char[], Empleado[]);
void generarresumenzonas(Empleado[],Empleado[],Empleado[],Empleado[],Zona[]); //Genera el vector zonas mediante los vectores de empleados cargados de los archivos
void informeporzona(Zona zonas[]);
void zonamayorempleados(Zona zonas[]);
int disponible(Empleado v[]);
void nodisponibles(Empleado[],Empleado[],Empleado[],Empleado[]);
bool esnumero(char);
void verificarpatente(char[]);
void verificarnombre(char[]);

int main()
{ // Declaracion de variables
    Empleado motos[280];
    Empleado autos[280];
    Empleado camiones[280];
    Empleado camionetas[280];
    Zona zonas[14];
    int r=1;
    // Comienza el programa
    if (archivoexiste("RepMoto.dat") and archivoexiste("RepAuto.dat") and archivoexiste("RepCamion.dat") and archivoexiste("RepCamioneta.dat"))
    {
        cout << "Sea han detectado archivos generados previamente mediante este programa. Desea cargar los datos de los archivos o crear archivos nuevos?\n1. Ingresar datos y crear archivos nuevos\n2. Cargar archivos existentes\n\n>";
        do
        {
            cin >> r;
            cin.clear();
            cin.ignore(100, '\n');
            //Si r es palabra, va a contar como 0 por lo que automaticamente repite el ciclo
            //Limpiar el cin es suficiente
        } while (r != 1 and r != 2);
    }
    if (r == 1)
    {
        IngresarRepartidores(motos, autos, camiones, camionetas, zonas);
        ordenarempleados(motos);
        ordenarempleados(autos);
        ordenarempleados(camiones);
        ordenarempleados(camionetas);
        escribirarchivo("RepMoto.dat", motos);
        escribirarchivo("RepAuto.dat", autos);
        escribirarchivo("RepCamion.dat", camiones);
        escribirarchivo("RepCamioneta.dat", camionetas);
    }
    else
    {
        cargararchivo("RepMoto.dat", motos);
        cargararchivo("RepAuto.dat", autos);
        cargararchivo("RepCamion.dat", camiones);
        cargararchivo("RepCamioneta.dat", camionetas);
        generarresumenzonas(motos, autos, camiones, camionetas, zonas);
        cout<<"\n\n\tDatos Cargados.\n\n";
        getch();
    }
    //A partir de este punto estan ya todos los vectores cargados.

    informeporzona(zonas); //Punto 2 (funcion que muestra la cantidad de repartidores por medio de transporte por zona)
    zonamayorempleados(zonas); //Punto 4 (suma de repartidores total por zona, y muestra la zona con mayor cantidad de repartidores).

    //Punto 3 (Disponibilidad de vehiculos)
    nodisponibles(motos, autos, camiones, camionetas);
    return 0;
}

bool esnumero(char a){
    if(a>='0' and a<='9')
    return true;
    return false;
}


void verificarpatente(char a[]){
    bool patente=true;
    for(int i=0; i<3; i++){
        if(esnumero(a[i]))
        patente = false
    }
    for(int i=3; i<6; i++){
        if(!esnumero(a[i]))
        patente = false
    }
}


void IngresarRepartidores(Empleado motos[], Empleado autos[], Empleado camiones[], Empleado camionetas[], Zona zonas[])
{
    int qmotos = 0, qautos = 0, qcamiones = 0, qcamionetas = 0;
    int transporte;
    Empleado temp;
    cout << "Comenzando ingreso, digite un numero de documento igual a cero para finalizar. " << endl;
    cout << endl;
    cout << "Ingrese el numero de documento del repartidor: ";
    cin >> temp.dni;
    ValidaEnteros(temp.dni);
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
                ValidaEnteros(transporte);
            } while (transporte <= 0 or transporte >= 5);
            do
            {
                cout << "\n(1-14)\nDigite la zona en la que quiere trabajar: ";
                cin >> temp.zona;
                ValidaEnteros(temp.zona);
            } while (temp.zona <= 0 or temp.zona >= 15);
            if (Haylugar(transporte, temp.zona, zonas))
            {
                cout << "\nIngrese la patente del vehiculo sin espacios: ";
                fflush(stdin);
                cin.getline(temp.patente, sizeof(temp.patente));
                cin.clear();
                cin.ignore(100, '\n');
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
            ValidaEnteros(temp.dni);
        } while (temp.dni != 0);
        return;
    }
}


void ValidaEnteros(int &a)
{
    bool i = false;
    do{
        if(!cin)
        {
            cout << "\n   ERROR. Ingrese un numero entero: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> a;
        }
        if (!cin)
        {
            i = false;
        }
        else
        {
            i = true;
        }
    }while (i == false);
    return;
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


int cuantosempleados(Empleado empleados[])
{
    int i = 0, t = 0;
    while (empleados[i].dni != 0)
    {
        // Calcula el tamaño del vector de empleados utilizado mediante la restriccion de que el dni no puede ser 0 (Sin haber sido un dni no modificado)
        t++;
        i++;
    }
    return t;
}


void ordenarempleados(Empleado emp[])
{
    int t = cuantosempleados(emp);
    Empleado temp;
    for (int q = 0; q < t; q++)
    {
        for (int l = 0; l < t - q - 1; l++)
        {
            if (emp[l].dni > emp[l + 1].dni)
            {
                temp = emp[l];
                emp[l] = emp[l + 1];
                emp[l + 1] = temp;
            }
        }
    }
}


void escribirarchivo(char nombre[], Empleado lista[]){
    int t = cuantosempleados(lista);
    FILE *archivo = fopen(nombre, "w");
    for(int i=0; i<t; i++)
    fwrite(&lista[i], sizeof(Empleado), 1, archivo);
    fclose(archivo);
}


bool archivoexiste(char nombre[])
{
    FILE *archivo;
    archivo = fopen(nombre, "r");
    if (archivo != NULL)
    {
        fclose(archivo);
        return true;
    }
    return false;
}


void cargararchivo(char nombre[], Empleado vector[])
{
    FILE *archivo;
    int i=0;
    archivo = fopen(nombre, "r");
    fread(&vector[i], sizeof(Empleado), 1, archivo);
    while (!feof(archivo)){
    i++;
    fread(&vector[i], sizeof(Empleado), 1, archivo);
    }
    fclose(archivo);
}


void generarresumenzonas(Empleado motos[], Empleado autos[], Empleado camiones[], Empleado camionetas[], Zona zonas[]){
    int t;
    //Resumen motos
    t=cuantosempleados(motos);
    for(int i=0; i<t; i++){
        zonas[motos[i].zona-1].motos++;//el -1 en las zonas es para que se ponga en la posicion correcta del vector
    }
    //Resumen autos
    t=cuantosempleados(autos);
    for(int i=0; i<t; i++){
        zonas[autos[i].zona-1].autos++;
    }
    //Resumen camiones
    t=cuantosempleados(camiones);
    for(int i=0; i<t; i++){
        zonas[camiones[i].zona-1].camiones++;
    }
    //Resumen camionetas
    t=cuantosempleados(camionetas);
    for(int i=0; i<t; i++){
        zonas[camionetas[i].zona-1].camionetas++;
    }
}


void informeporzona(Zona zonas[])
{
    cout << "\n\nInforme de cantidad de repartidores por cada zona:" << endl;
    for (int i = 0; i < 14; i++)
        {
        cout << "Zona " << i + 1 << ":" << endl;
        cout << "  Motos: " << zonas[i].motos << " repartidor/es" << endl;
        cout << "  Autos: " << zonas[i].autos << " repartidor/es" << endl;
        cout << "  Camiones: " << zonas[i].camiones << " repartidor/es" << endl;
        cout << "  Camionetas: " << zonas[i].camionetas << " repartidor/es" << endl<<endl;
    getch();
    }
    cout<<"\n";
}


void zonamayorempleados(Zona zonas[])
{

    int cuantos=0, cuales[14], s, v[14];
    cuales[0]=0;
    //primero saco la suma del total de repartidores por zona, y los paso a un vector.
    for (int i = 0; i < 14; i++)
        {
        s = zonas[i].motos + zonas[i].autos + zonas[i].camiones + zonas[i].camionetas;
        v[i] = s;
        }
        //con cada uno de los valores de las sumas en el vector, empiezo a comparar, para sacar el mayor y ponerlo en el cout.
        for (int i = 0; i < 14; i++)
        {
            if( v[i] > v[cuales[0]] )
            {
                cuantos = 1;
                cuales[0] = i;
            }else if(v[i]==v[cuales[0]])
            {
                cuales[cuantos]=i;
                cuantos++;
            }
        }
        if(cuantos==1){
        cout << "La zona con mas repartidores es " << cuales[0] + 1 <<" con "<<v[cuales[0]]<<" repartidores."<< endl;
        }else{
            cout<<"Las zonas con mas repartidores son las zonas ";
            for(int i=0; i<cuantos; i++){
                cout<<cuales[i]+1;
                if(i+1<cuantos-1)
                cout<<", ";
                else if(i+1==cuantos-1)
                cout<<" y ";
            }
            cout<<" con "<<v[cuales[0]]<<" repartidores cada una.";
        }
    getch();
    cout<<"\n";
}


int disponible(Empleado v[])
{
    int aux;
    aux=v[0].dni;
    if(aux!=0)
        return 1;
    else
        return -1;
}


void nodisponibles(Empleado motos[],Empleado autos[],Empleado camiones[],Empleado camionetas[])
{
    bool pri=false;
    if(disponible(motos)<0)
    {
        pri=true;
        cout<<endl<<"Medios de Transporte no disponibles: "<<endl;
        cout<<"Moto"<<endl;
    }
    if(disponible(autos)<0)
    {
        if(!pri)
        {
            cout<<endl<<"Medios de Transporte no disponibles: "<<endl;
            pri=true;
        }
        cout<<"Auto"<<endl;
    }
    if(disponible(camiones)<0)
    {
        if(!pri)
        {
            cout<<endl<<"Medios de Transporte no disponibles: "<<endl;
            pri=true;
        }
        cout<<"Camion"<<endl;
    }
    if(disponible(camionetas)<0)
    {
        if(!pri)
        {
            cout<<endl<<"Medios de Transporte no disponibles: "<<endl;
            pri=true;
        }
        cout<<"Camioneta"<<endl;
    }
    getch();
}
