#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

struct medicamento{
    int codigo;
    char nombre[100];
    int stock;
    int preciounit;
};

void creararchivo();
void leerarchivo();
void stockbajo();
string nombreoriginal();
main(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    creararchivo();
    leerarchivo();
    cout<<"\n\n\n--------------------------------Productos con stock bajo---------------------------------\n\n\n";
    stockbajo();
    getch();
    return 0;
}
void creararchivo(){
    FILE * archivo;
    archivo = fopen("medicamentos.dat", "w");
    medicamento medit;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        medit.codigo=rand()%5000;
        medit.stock=abs(pow(5-i, rand()%3+2));
        strcpy(medit.nombre, nombreoriginal().c_str());
        medit.preciounit=rand()%100;
        fwrite(&medit, sizeof(medit), 1, archivo);
    }
    fclose(archivo);
}
void leerarchivo(){
    medicamento temp;
    FILE * archivo = fopen("medicamentos.dat", "r");
    fread(&temp, sizeof(temp), 1, archivo);
    while(!feof(archivo)){
        cout<<"\n"<<temp.codigo<<"   -   "<<temp.nombre<<"   -   "<<temp.preciounit<<"   -   "<<temp.stock<<"\n";
        fread(&temp, sizeof(temp), 1, archivo);
    }
    fclose(archivo);
}
void stockbajo(){
    medicamento temp;
    FILE * archivo = fopen("medicamentos.dat", "r");
    fread(&temp, sizeof(temp), 1, archivo);
    while(!feof(archivo)){
        if(temp.stock<=5){
        cout<< left <<setw(40)<<temp.nombre<<setw(10)<<"   -   "<<setw(5)<<temp.preciounit*temp.stock<<"\n";}
        fread(&temp, sizeof(temp), 1, archivo);
    }
    return;
}
string nombreoriginal(){
    string primero[16] = {"Medicamento", "Dolor", "Panacea", "Explosion", "Droga", "Hierba", "Aspirina", "Brebaje", "Panza", "Psicofarmaco", "Sueño", "Pocion", "Sopa", "Batido de proteinas", "Aceite esencial", "Tornado"};
    string segundo[16] = {"funcional", "fluorescente", "de espanto", "del diablo", "horrible", "verde", "increible", "inutil", "carmesí", "maloliente", "con psicosis", "que caducó", "medieval", "feliz", "kamikaze", "mortal"};
    string final = primero[rand()%16] + " " + segundo[rand()%16];
    return final;
}