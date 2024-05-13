#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

/*
1. Se dispone de un conjunto de inscripciones de alumnos a examen en el mes de mayo. Cada inscripci�n tiene los siguientes datos: nombre y apellido, n�mero
de legajo, c�digo de materia, d�a, mes y a�o del examen. Los datos finalizan con un n�mero de legajo igual a cero. Desarrollar un programa que a partir del
ingreso de las inscripciones por teclado, genere un archivo binario de inscripci�n de alumnos a ex�menes finales DIAFINALES.DAT, seg�n el siguiente dise�o:
    A.1 Nro. de legajo        A.2 C�digo de materia
    A.3 D�a del examen        A.4 Mes del examen
    A.5 A�o del examen        A.6 Nombre-Apellido
*/

struct Inscripcion
{
    int legajo;
    int codigo;
    int dia;
    int mes;
    int anio;
    char nombreyapellido[100];
};

void IngresoDatos(Inscripcion[], int );
void CrearArchivo(Inscripcion [], int );
void MostrarArchivo(Inscripcion [], int );

int main()
{
    int contador = 0;
    Inscripcion Alumno[100];
   // IngresoDatos(Alumno, contador);
  //  CrearArchivo(Alumno, contador);
    MostrarArchivo(Alumno, contador);
    getch();
    return 0;
}

void IngresoDatos(Inscripcion Alumno[], int c)
{
    int i = 0;
    cout << "Digite un numero de legajo igual a cero (0) para finalizar." << endl;
    cout << "Ingrese el numero de legajo: ";
    cin >> Alumno[i].legajo;
    if (Alumno[i].legajo == 0)
    {
        return;
    }
    else
    {
        do
        {
            cout << "\nDigite el codigo de materia: ";
            cin >> Alumno[i].codigo;
            cout << "\nIngrese el dia del examen: ";
            cin >> Alumno[i].dia;
            cout << "\nIngrese el mes del examen (1 - 12): ";
            cin >> Alumno[i].mes;
            cout << "\nIngrese el anio del examen: ";
            cin >> Alumno[i].anio;
            cout << "\nIngrese nombre y apellido del estudiante: ";
            fflush(stdin);
            cin.getline(Alumno[i].nombreyapellido, sizeof(Alumno[i].nombreyapellido));
            cout << "\n         'Registro a Examen Final realizado con exito'          ";
            cout << endl;
            i++;
            c++;
            cout << "\nDigite el numero de legajo: ";
            cin >> Alumno[i].legajo;
        } while(Alumno[i].legajo != 0);
    }
}

void CrearArchivo(Inscripcion Alumno[], int c)
{
    FILE *Archivo;
    int i = 0;
    Archivo = fopen("DIAFINALES.dat", "wb");
    fwrite(&Alumno[i], sizeof(Inscripcion), 1, Archivo);
    for(int i=1; i < c; i++)
    {
        fwrite(&Alumno[i], sizeof(Inscripcion), 1, Archivo);
    }
    fclose (Archivo);
}


void MostrarArchivo(Inscripcion Alumno[], int c)
{
    FILE *Archivo;
    int i = 0;
    Archivo = fopen("DIAFINALES.dat", "rb");
    fread(&Alumno[i], sizeof(Inscripcion), 1, Archivo);
    cout<<Alumno[i].nombreyapellido;
    while (!feof(Archivo))
    {
        i++;
        fread(&Alumno[i], sizeof(Inscripcion), 1, Archivo);
        cout<<Alumno[i].nombreyapellido<<Alumno[i].codigo;
    }
    fclose(Archivo);
}
