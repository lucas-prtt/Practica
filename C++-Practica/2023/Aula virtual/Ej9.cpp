#include <iostream>
#include <stdio.h>

using namespace std;

struct DatoArchPlato
{
    int codPlato; //(1 a 200) ordenado por codPlato
	char descripcion[41];
	float precio;
};
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
struct DatoArchFac
{
    Fecha fecha;
    int nroFactura;
    int mesa;
    int mozo;
    float importe;
};
struct DatoLista
{
    int codPlato;
    int cant;
};
struct Nodo
{
    DatoLista info;
    Nodo*sig;
};
/*
struct DatoVecPlato
{
    char descripcion[41];
	float precio;
};
*/
int main()
{
    float comMozos[10];
    inicVecF(comMozos); //inicializa en vector en cero
    Nodo*mesas[48];
    inicializar(mesas); //pone todos los elementos en NULL
    //DatoVecPlato platos[200];
    Fecha f;
    int nroFac;
    ingresarFecha(f); //ingresa y devuelve la fecha del día
    cout<<"nro fac inicial ";
    cin>>nroFac;
    FILE*ap=fopen("Platos.dat","rb");
    if(ap!=NULL)
    {
      //guardarPlatos(ap,platos); //llena el vector de platos con los datos del archivo "Platos.dat"
      //recepcionar(platos,mesas,comMozos,f,nroFac);

      recepcionar(mesas,comMozos,f,nroFac,ap);
      mostrarComMozos(comMozos); //muestra la comisión que cobrarán los mozos que está almacenada en el vector

        //El enunciado pedía que si quedaban adiciones pendiente informar
        if(hayAdicPendientes(mesas))
            cout<<"hay adiciones pendientes"<<endl;

        fclose(ap);
    }
    cout<<"nro fac inicial para maniana "<<nroFac<<endl; //no pedido

    return 0;
}

//void recepcionar(DatoVecPlato platos[],Nodo*mesas[],float comMozos[],Fecha f,int &nf)
void recepcionar(Nodo*mesas[],float comMozos[],Fecha f,int &nf,FILE*ap)
{
    int nroM,cod,canti;
    char codOp;
    DatoLista datoL;
    Nodo*p,*aux;
    cin>>nroM; //faltaría validar entre 0 y 48
    while(nroM!=0)
    {
        cin>>codOp;
        switch(codOp)
        {
            case 'A':
                cout<<"Ingrese el cod de plato a entregar ";
                cin>>cod;
                cin>>canti;
                datoL.codPlato=cod;
                datoL.cant=0;
                p=buscarInsertar(mesas[nroM-1],datoL);
                p->info.cant+=canti;
                break;
            case 'B':
                cout<<"Ingrese el cod de plato a devolver ";
                cin>>cod;
                cin>>canti;
                p=buscar(mesas[nroM-1],cod);
                if(p!=NULL && p->info.cant>=canti)
                    p->info.cant-=canti;
                break;
            case 'F':
                FILE*a=fopen("Facturacion.dat","ab");
                DatoArchFac fac;
                cout<<"Ingrese el cod de mozo que atendio la mesa ";
                cin>>cod;
                cout<<"Fecha "<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<"    Nro Fac "<<nf<<endl;
                cout<<"Cant               Descripción                Precio Unitario              Importe"<<endl;
                p=mesas[nroM-1];
                float importe,total=0;
                while(p!=NULL)
                {
                    if(p->info.cant>0)
                    {
                        DatoArchPlato plato;
                        fseek(ap,(p->info.codPlato-1)*sizeof(DatoArchPlato),SEEK_SET);
                        fread(&plato,sizeof(DatoArchPlato),1,ap);
                        importe=p->info.cant*plato.precio;
                        //importe=p->info.cant*platos[p->info.codPlato-1].precio;
                        cout<<p->info.cant;
                        //cout<<platos[p->info.codPlato-1].descripcion;
                        cout<<plato.descripcion;
                        //cout<<platos[p->info.codPlato-1].precio;
                        cout<<plato.precio;
                        cout<<importe;
                        total+=importe;
                    }
                    aux=p;
                    p=p->sig;
                    delete aux;
                }

                mesas[nroM-1]=NULL;
                cout<<"mozo "<<cod<<" total "<<total<<endl;
                comMozos[cod-1]+=total*0.01;
                fac.fecha=f;
                fac.nroFactura=nf;
                fac.mesa=nroM;
                fac.importe=total;
                fac.mozo=cod;
                fwrite(&fac,sizeof(fac),1,a);
                nf++;
                fclose(a);
                break;
        }
        cin>>nroM; //faltaría validar entre 0 y 48

    }
}
Nodo* buscarInsertar(Nodo*&lista,DatoLista dato)
{
    Nodo*ant,*p=lista;
   while(p!=NULL && p->info.codPlato<dato.codPlato)
   {
       ant=p;
       p=p->sig;
   }
   if(p!=NULL && dato.codPlato==p->info.codPlato)
        return p;
   else
   {
        Nodo*n=new Nodo;
        n->info=dato;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
        return n;
   }
}
bool hayAdicPendientes(Nodo*v[])
{
    int i=0;
    while(i<48 && v[i]==NULL)
        i++;
    /*
    if(i<48)
        return true;
    else
        return false;
    */
    return i<48;
}

