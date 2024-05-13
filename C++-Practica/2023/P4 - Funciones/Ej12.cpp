#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

unsigned int edadAGrupoEtario(unsigned int);
bool puntob(int); //Punto b
bool puntoc(int, int, int); //Punto c
bool puntod(int, int, int, char); //Punto d
int edad(int, int, int, int, int, int);
int main(){
    int dh, mh, ah, d, m, a; char s; //Variables de la encuesta
    int q=0, g1=0, g2=0, g3=0, g4=0, g5=0, g6=0, g7=0, g8=0, pb=0, pc=0, pd=0, pee=0;char pes='x'; 
    //variables de resumen
    //Grupo 1, 2, 3, 4...
    //Punto d sexo y Punto d edad
    cout<<"Que fecha es hoy?\n";
    do{cout<<"Dia: ";
    cin>>dh;}while(dh<=0 or dh>31);
    do{cout<<"Mes: ";
    cin>>mh;}while(mh<=0 or mh>12);
    do{cout<<"Año: ";
    cin>>ah;}while(ah<0);
    cout<<"De acuerdo, a censar!";
    getch();
    cout<<"\n\n\n\n\n\n";
    do{
        //                                                              PREGUNTAS
        cout<<"Fecha de nacimiento\n";
        do{cout<<"\nDia: ";
        cin>>d;}while (d<0 or d>31);
        if(d!=0){
        q++;
        do{cout<<"Mes: ";
        cin>>m;} while(m<=0 or m>12);
        do{cout<<"Año: ";
        cin>>a;} while(edad(dh, mh, ah, d, m, a)<0);
        do{cout<<"\nSexo: ";
        cin>>s;} while(s!='M' and s!='F' and s!='M' and s!='f');
        //                                                              ANALISIS
        switch (edadAGrupoEtario(edad(dh, mh, ah, d, m, a)))
        {
        case 1:g1++;break;
        case 2:g2++;break;
        case 3:g3++;break;
        case 4:g4++;break;
        case 5:g5++;break;
        case 6:g6++;break;
        case 7:g7++;break;
        case 8:g8++;break;
        }
        if(puntob(m)){pb++;}
        if(puntoc(d, m, a)){pc++;}
        if(puntod(d, m, a, s)){pd++;}
        if(edad(dh, mh, ah, d, m, a)>pee)
        {
            pee = edad(dh, mh, ah, d, m, a);
            pes = s;
        }
    }}while(d!=0);
    //                                                                  MOSTRAR DATOS
    cout<<"\n\n\n\n\nGente encuestada: "<<q;
    cout<<"\n\n\nPoblacion ordenada por grupo etario:\n";
    cout<<"\nGrupo etario 1: "<<g1;
    cout<<"\nGrupo etario 2: "<<g2;
    cout<<"\nGrupo etario 3: "<<g3;
    cout<<"\nGrupo etario 4: "<<g4;
    cout<<"\nGrupo etario 5: "<<g5;
    cout<<"\nGrupo etario 6: "<<g6;
    cout<<"\nGrupo etario 7: "<<g7;
    cout<<"\nGrupo etario 8: "<<g8;
    cout<<"\n\n\nNacimientos en el mes de octubre: "<<pb;
    cout<<"\n\nNacimientos antes del 9 de julio de 1990: "<<pc;
    cout<<"\n\nNacimientos de mujeres en la primavera de 1982: "<<pd;
    cout<<"\n\nLa persona mas vieja con "<<pee<<" años es un";
    if(pes=='F' or pes=='f')
    cout<<"a mujer";
    else
    cout<<" hombre";
    cout<<"\n\n";

    getch();
    return 0;
    }



int edad(int hoydia, int hoymes, int hoyyear, int dia, int mes, int year){
    //No distingue meses de una cantidad de dias distinta de 30.
    int edad = 0;
    edad = (hoyyear*365 - year*365 + hoymes * 30 - mes*30 + hoydia - dia)/365;
   if((hoyyear*365 - year*365 + hoymes * 30 - mes*30 + hoydia - dia)<0){return -1;}
    return edad;
}

unsigned int edadAGrupoEtario(unsigned int age){
    if(age<=14)
    return 1;
    else if (age>=64)
    return 8;
    else if (age>=50 and age<=63)
    return 7;
    else return (age-1)/7;
}
bool puntob(int mes){
    if(mes==10)
    return true;
    else return false;
}
bool puntoc(int dia, int mes, int year){
    if((((dia<9 and mes==7) or mes<7) and year==1990) or year<1990)
    return true;
    else return false;
}
bool puntod(int dia, int mes, int year, char sexo){
    if(((dia>=23 and mes==9) or mes==10 or mes==11 or (mes==12 and dia<=22))and year==1982 and (sexo=='f' or sexo=='F'))
    return true;
    else return false;
}