#include <iostream>
#include <stdio.h>


using namespace std;

struct DatoArchEmple
{
    int nroLeg;
    char nomApe[31];
    int dni;
    int dpto;
};

struct DatoArchVacantes
{
    int dpto;
    int cant;
};
struct DatoArchPost
{
    int legajo;
    int dpto;
};
struct NodoC
{
    int leg;
    NodoC *sig;
};
struct DatoVec
{
    int cantVac;
    NodoC*pri;
    NodoC*ult;
};

int main()
{
    DatoVec vec[50];
    inic(vec);
    FILE*aEmple=fopen("Empleados.dat","rb+");
    FILE*aVac=fopen("Vacantes.dat","rb");
    FILE*aPost=fopen("Postulantes.dat","rb");
    llenarVec(aVac,vec);
    procesarPost(aPost,vec);
    puntoAB(aEmple,vec);
    fclose(aEmple);
    fclose(aVac);
    fclose(aPost);
    return 0;
}
void inic(DatoVec v[])
{
    for(int i=0;i<50;i++)
    {
        v[i].cantVac=0;
        v[i].pri=NULL;
        v[i].ult=NULL;
    }
}
void llenarVec(FILE*a,DatoVec v[])
{
    DatoArchVacantes reg;
    fread(&reg,sizeof(DatoArchVac),1,a);
    while(!feof(a))
    {
        v[reg.dpto-1].cantVac=reg.cant;
        fread(&reg,sizeof(DatoArchVac),1,a);
    }
}
void procesarPost(FILE*ap,DatoVec v[])
{
    DatoArchPost reg;
    fread(&reg,sizeof(DatoArchPost),1,ap);
    while(!feof(ap))
    {
        encolar(v[reg.dpto-1].pri,v[reg.dpto-1].ult,reg.legajo);
        fread(&reg,sizeof(DatoArchPost),1,ap);
    }
}
void puntoAB(FILE*ae,DatoVec v[])
{
    int unLeg,pos;
    DatoArchEmple emple;
    for(int i=0;i<50;i++)
    {
        if(v[i].pri!=NULL)
        {
            cout<<"Departamento "<<i+1<<endl;
            while(v[i].pri!=NULL)//la cola no esté vacía
            {
                unLeg=desencolar(v[i].pri,v[i].ult);
                pos=busquedaBinariaArch(ae,unLeg,emple);
                if(pos!=-1)
                {
                    cout<<emple.nroLeg<<emple.nomApe<<emple.dni<<endl;
                    if(v[i].cantVac>0)
                    {
                        emple.dpto=i+1;
                        fseek(ae,pos*sizeof(DatoArchEmple),SEEK_SET);
                        fwrite(&emple,sizeof(DatoArchEmple),1,ae);
                        v[i].cantVac--;
                    }
                }


            }
        }
    }
}

int busquedaBinariaArch(FILE* arch,unsigned bus,DatoArchEmple &par)
{
    int desde,hasta,medio,cantRegistros,pos=-1;
    desde=0;
    fseek(arch,0,SEEK_END);
    cantRegistros=ftell(arch)/sizeof(DatoArchEmple);
    hasta=cantRegistros-1;
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(arch,medio*sizeof(DatoArchEmple),SEEK_SET);
        fread(&par,sizeof(DatoArchEmple),1,arch);
        if(par.nroLeg==bus)
            pos=medio;
        else
        {
            if(bus<par.nroLeg)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}


void encolar(NodoC*&pri,NodoC*&ult,int nro)
{
    NodoC*p;
    p=new NodoC;
    p->info=nro;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
   ult=p;
}

int desencolar(NodoC*&pri,NodoC*&ult)
{
    int dato;
    NodoC *p;
    p=pri;
    dato=p->info;
    pri=p->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;
    return dato;
}


