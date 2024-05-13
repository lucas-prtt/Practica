#include <iostream>
#include <conio.h>

using namespace std;

/*
Input:
1.          --Proyectos--           (Menos de 100 Proyectos)   
    Codigo de Proyecto
    Nombre de Proyecto (Fin = Fin)
    Costo estimado de Proyecto
2.          --Empleados--
    Numero de legajo
    Nombre y apellido
    Responsabilidad (Ingeniero/Analista/Programador/Testeador/Operacion) (F = Fin)
    Sueldo a pagar
    Codigo de proyecto (Solo trabaja en uno)

Output:
1. Cantidad de empleados por proyecto, ordenado de menor a mayor por cantidad de empleados (Formato: Codigo de proyecto, cantidad de empleados)
2. Numero de legajo, nombre y apellido del programador que cobra mayor sueldo.
3. Listado de cada Proyecto, su codigo, nombre y el total abonado en sueldos para cada una de las responsabilidades del mismo
4. Informe de proyectos (Codigo y nombre) cuyo costo total (Suma de sueldos de empleados) es mayor al inicial estimado
5. Informar proyectos sin empleados asignados 
*/
struct proyecto{
    int codigo;
    string nombre;
    int costo;
    int qempleados;
    float costoreal;
    float costoA;
    float costoP;
    float costoI;
    float costoT;
    float costoO;
};
struct empleado{
    int legajo;
    string nombre;
    string apellido;
    char puesto;
    float sueldo;
    int proyecto;
};

void listadoprimero(proyecto vector[], int posUltProy);
void listado(proyecto vector[], int posUltProy, float[][5]);
void ordenar(string parametro, proyecto vector[], int posUltProy);
int buscarproyecto(int codigo ,proyecto[], int posUltProy);
void proyectosInput(proyecto proyectos[], int &posUltProy);
void empleados(proyecto proyectos[], int posUltProy, empleado &empleadocaro, float costos[][5]);
empleado caro(empleado esteempleado, empleado empleadocaro, char rol);
void listadocaro(proyecto vector[], int posUltProy);
void listadovacio(proyecto vector[], int posUltProy);
main(){
    proyecto proyectos[100];
    empleado programadorcaro;
    int qproy;
    float costos[100][5];
    proyectosInput(proyectos, qproy);
    empleados(proyectos, qproy, programadorcaro, costos);
    cout<<"\n\n---------------------------------------------------\n\n\n";
    ordenar("empleados",proyectos, qproy);
    
    listadoprimero(proyectos, qproy);
    cout<<"\n\nEl programador de mayor sueldo es "<<programadorcaro.nombre<<" "<<programadorcaro.apellido<< " de legajo "<<programadorcaro.legajo<<".\n";
    listado(proyectos, qproy, costos);

    listadocaro(proyectos, qproy);
    listadovacio(proyectos, qproy);
    getch();
    return 0;
}

void proyectosInput(proyecto proyectos[], int &ult){
    int i = 0;
    bool chau=false;
    cout<<"Ingrese el nombre del proyecto\n(O escriba FIN para salir)\n";
    cin>>proyectos[i].nombre;
    if (proyectos[i].nombre=="fin" or proyectos[i].nombre=="FIN")
    chau=true;
    while(!chau and i<100)
    {   
        cout<<"Ingrese el codigo del proyecto\n";
        cin>>proyectos[i].codigo;

        cout<<"Ingrese el costo esperado del proyecto)\n";
        cin>>proyectos[i].nombre;
        proyectos[i].qempleados=0;
        proyectos[i].costoreal=0;
        cout<<"Ingrese el nombre del proyecto\n(O escriba FIN para salir)\n";
        cin>>proyectos[i+1].nombre;
        
        if(proyectos[i+1].nombre!="FIN" and proyectos[i+1].nombre!="fin")
            i++;
        else chau=true;
    }
    ult = i;
}

void empleados(proyecto proyectos[], int posUltProy, empleado &programadorcaro, float costos[][5])
{
    empleado esteempleado;
    int i=0;
    programadorcaro.sueldo=0;

    cout<<"Responsabilidad del empleado a ingresar:\n(I=ingeniero, A=Analista, P=Programador, T=Tester, O=Operador, F=Dejar de ingresar empleados)\n";
    cin>>esteempleado.puesto;

    while(esteempleado.puesto!='f' and esteempleado.puesto!='F')
    {
        
        cout<<"\nNombre del empleado: \n";
        cin>>esteempleado.nombre;
        cout<<"\nApellido del empleado: \n";
        cin>>esteempleado.apellido;
        cout<<"\nNumero de legajo del empleado: \n";
        cin>>esteempleado.legajo;
        cout<<"\nSueldo del empleado: \n";
        cin>>esteempleado.sueldo;
        cout<<"\nCodigo del proyecto al que esta asignado:\n";
        cin>>esteempleado.proyecto;
        switch(esteempleado.puesto){
            case 'I':case 'i':
            costos[i][0] = esteempleado.sueldo;
            break;
            case 'A':case 'a':
            costos[i][1] = esteempleado.sueldo;
            break;
            case 'P':case 'p':
            costos[i][2] = esteempleado.sueldo;
            break;
            case 'T':case 't':
            costos[i][3] = esteempleado.sueldo;
            break;
            case 'O':case 'o':
            costos[i][4] = esteempleado.sueldo;
            break;
        }
        proyectos[buscarproyecto(esteempleado.proyecto, proyectos, posUltProy)].qempleados++;
        programadorcaro=caro(esteempleado, programadorcaro, 'P');
        proyectos[buscarproyecto(esteempleado.proyecto, proyectos, posUltProy)].costoreal+=esteempleado.sueldo;

        cout<<"Responsabilidad del empleado a ingresar:\n(I=ingeniero, A=Analista, P=Programador, T=Tester, O=Operador, F=Dejar de ingresar empleados)\n";
        cin>>esteempleado.puesto;
    }
}
int buscarproyecto(int codigo, proyecto proyecto[], int q){
    for(int i=0; i<q; i++)
    {

        if(proyecto[i].codigo==codigo)
        return i;
    }
    return -1;
}
empleado caro(empleado esteempleado, empleado empleadocaro, char rol){
    if (rol=='P' and esteempleado.sueldo>empleadocaro.sueldo)
    return esteempleado;
    return empleadocaro;
}

void ordenar(string parametro, proyecto vector[], int posUltProy){
    int i=0;
    proyecto temp;
    bool cambio=true;
    if(parametro=="empleados"){i=1;}
    else if(parametro=="codigo"){i=2;}
    else if(parametro=="costo"){i=3;}

    switch(i){
        case 1: 
        for(int k=0;k<=posUltProy-1; k++){
            for(int q=0;!cambio and q<=posUltProy-1; q++){
                cambio=false;
                if(vector[q].qempleados>vector[q+1].qempleados)
                {
                    temp = vector[q];
                    vector[q] = vector[q+1];
                    vector[q+1] = temp;
                    cambio=true;
                }
            }
        }
        break;
        case 2:
        for(int k=0;k<=posUltProy-1; k++){
            for(int q=0;!cambio and q<=posUltProy-1; q++){
                cambio=false;
                if(vector[q].codigo>vector[q+1].codigo)
                {
                    temp = vector[q];
                    vector[q] = vector[q+1];
                    vector[q+1] = temp;
                    cambio=true;
                }
            }
        }
        break;
        case 3:
        for(int k=0;k<=posUltProy-1; k++){
            for(int q=0;!cambio and q<=posUltProy-1; q++){
                cambio=false;
                if(vector[q].costo>vector[q+1].costo)
                {
                    temp = vector[q];
                    vector[q] = vector[q+1];
                    vector[q+1] = temp;
                    cambio=true;
                }
            }
        }
        break;
        default:
        cout<<"\n\n►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄\n\t\tError: parametro en funcion ordenar mal declarado\n\t\tUtilice *empleados*, *codigo* o *costo* como parametro\n►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄►◄\n\n";
        break;
    }
}

void listado(proyecto vector[], int posUltProy, float costos[][5]){
    cout<<"Codigo"<<"\t\t||\t"<<"Nombre"<<"\t\t||\t"<<"Costo por empleado:\tIngeniero\tAnalist\tProgramador\tTester\tOperador"<<endl;
    for(int i=0; i<=posUltProy; i++){
        cout<<vector[i].codigo<<"\t\t||\t"<<vector[i].nombre<<"\t\t||\t"<<endl;
        cout<<costos[i][0]<<"\t";
        cout<<costos[i][1]<<"\t";
        cout<<costos[i][2]<<"\t";
        cout<<costos[i][3]<<"\t";
        cout<<costos[i][4]<<"\n";
    }
}

void listadocaro(proyecto vector[], int posUltProy){
    int q=0;
    for(int i=0; i<=posUltProy; i++){
        if(vector[i].costoreal>vector[i].costo){
            if(q==0)
            {
                cout<<"\nProyectos con gastos mayores a los esperados\n\nCodigo"<<"\t\t||\t"<<"Nombre"<<endl;
            }
            q++;
            cout<<vector[i].codigo<<"\t\t||\t"<<vector[i].nombre<<"\n";
        
        }
    }
    if(q==0){cout<<"\n\n Ninguno!\n";}
}

void listadovacio(proyecto vector[], int posUltProy){
    int q=0;
    cout<<"\nProyectos sin empleados asignados:\n\nCodigo"<<"\t\t||\t"<<"Nombre"<<endl;
    for(int i=0; i<=posUltProy; i++){
        if(vector[i].qempleados==0){
            if(q==0)
            {
                cout<<"\nProyectos con gastos mayores a los esperados\n\nCodigo"<<"\t\t||\t"<<"Nombre"<<endl;
            }
            q++;
            cout<<vector[i].codigo<<"\t\t||\t"<<vector[i].nombre<<"\n";
        
        }
    }
    if(q==0){cout<<"\n\n Ninguno!\n";}
}
void listadoprimero(proyecto vector[], int posUltProy){
    cout<<"Codigo de proyecto ------ Cantidad de empleados\n\n\n";
    for(int i=0; i<=posUltProy; i++){
        cout<<vector[i].codigo<<"\t||\t"<<vector[i].qempleados<<"\n";
    }
}

