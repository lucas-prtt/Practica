#include <iostream>
#include <conio.h>
using namespace std;

struct producto{
    int id;
    string desc;
    int stock;
    float precio;
    float comision;
    float facturacion;
};


void mostrarproductos(producto[], int q);
void mostrarcomisiones(float comisiones[]);
void ingresoproductos(producto[], int &q);
void ingresoventas(producto[], float comisiones[], int q);
bool noexiste(producto[], int q, int producto);
int ubicar(producto[], int q, int id);//Devuelve la posicion del producto en el array en base al id


main(){
    int q=400;
    producto productos[q];
    float comisiones[10];       //Cada posicion le corresponde a un visitador medico
    for (int i=0; i<10; i++){comisiones[i]=0;}
cout<<"\n\nIngreso de productos de la empresa. Para finalizar el ingreso ingrese 0 como ID de producto.\n\n\n";
ingresoproductos(productos, q);
cout<<"\n\nIngreso de ventas de visitadores medicos. Para finalizar el ingreso ingrese 0 como numero de visitador";
ingresoventas(productos, comisiones, q);
mostrarcomisiones(comisiones);
getch();
mostrarproductos(productos, q);
getch();
return 0;
}

void mostrarproductos(producto productos[], int q){
    cout<<"\n\n\n\nProductos restantes\n\n";
    cout<<"ID\t|Stock\t|Ingresos\n\t|\t|\n";

    for(int i=0; i<q; i++){
        cout<<productos[i].id<<"\t|"<<productos[i].stock<<"\t|$ "<<productos[i].facturacion<<"\n";
    }
    cout<<"\n";
}

void mostrarcomisiones(float comisiones[]){
    cout<<"\n\nComisiones de los vendedores:\nVendedor\t|\tComision\n\t\t|";
for (int i=0; i<10; i++)
{
    cout<<"\n"<<i<<"\t\t|\t$ "<<comisiones[i];
}
cout<<"\n";
}

void ingresoventas(producto productos[], float comisiones[], int q){
    int visitador;
    int producto;
    int cantidad;
    int posprod;
    //Solo para primer ciclo
    do{
        cout<<"\nNumero de visitador: ";
        cin>>visitador;
    }while(visitador<0 or visitador>10); 
    if (visitador==0)return;
    //Todos los demás
    do{

        do{
            cout<<"\nNumero de ID del producto vendido: ";
            cin>>producto;
            posprod=ubicar(productos, q, producto);
            if(posprod==-1)cout<<"El producto no existe";
            if(productos[posprod].stock==0) cout<<"De ese producto ya no queda stock";
        }while(producto<3000 or producto>15000 or posprod==-1 /*-1 = No existe*/ or productos[posprod].stock<=0);

        do{
            cout<<"\nCantidad del producto vendido: ";
            cin>>cantidad;
            if(cantidad>productos[posprod].stock)cout<<"No alcanza el stock.\n";
            if(cantidad==0)cout<<"La cantidad no puede ser 0.\n";
        }while(cantidad<=0 or cantidad>productos[posprod].stock);

        productos[posprod].stock-=cantidad;
        comisiones[visitador-1]+=productos[posprod].comision*productos[posprod].precio*cantidad;
        productos[posprod].facturacion+=productos[posprod].precio*cantidad*(1-productos[posprod].comision);
        cout<<"\nVenta registrada.\n\n";
        do{
            cout<<"\nNumero de visitador: ";
            cin>>visitador;
        }while(visitador<0 or visitador>10); 

    }while(visitador!=0);
}


int ubicar(producto productos[], int q, int id){//-1 si no existe
    for(int k=0; k<q; k++){
        if(productos[k].id==id){return k;}
    }
    return -1;
}

void ingresoproductos(producto productos[], int &q){
    int i=0;
    do 
    {
        do
        {
            cout<<"Ingrese el ID de producto: ";
            cin>>productos[i].id;
            for(int k=0; k<i; k++)
            {
                if (productos[k].id==productos[i].id)
                {
                    cout<<"\nID ingresada previamente, ingrese otra: \n";
                    productos[i].id=-1;
                }
            }
        }
        while(productos[i].id!=0 and (productos[i].id<3000 or productos[i].id>15000));
        if (productos[i].id==0){
        q=i;
        cout<<"\n\nIngreso de productos finalizado porque ingresó 0 como ID de producto.\n\tSe ingresaron "<<q<<" productos.\n\n";
        getch();
        return;
        }
        cout<<"Ingrese la descripcion del producto: ";
        cin>>productos[i].desc;

        do
        {   
            cout<<"Ingrese la cantidad de unidades en stock del producto: ";
            cin>>productos[i].stock;
        }
        while(productos[i].stock<0 or productos[i].stock>2000);
 
        do
        {   
            cout<<"Ingrese el precio del producto: ";
            cin>>productos[i].precio;
        }
        while(productos[i].precio<0);

        do
        {   
            cout<<"Ingrese la comision del producto: ";
            cin>>productos[i].comision;
            if (productos[i].comision>=5 and productos[i].comision<=20)
            {   
                productos[i].comision = productos[i].comision/100;
            }
        }
        while(productos[i].comision>0.2000001 or productos[i].comision<0.05);
        productos[i].facturacion=0;
        i++;
    }
    while(i<q);
    q=i;
    cout<<"\n\nIngreso de productos finalizado por llegar al maximo de productos permitidos.\n\tSe ingresaron "<<q<<" productos.\n\n";
    getch();
}