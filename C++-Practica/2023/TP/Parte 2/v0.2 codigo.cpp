#include <iostream>
#include <string.h>
using namespace std;

struct infopedido{
    char domicilio[50];
    int importe;
    int codigo;
};
struct nodopedido{
    infopedido pedido;
    nodopedido * sig;
};
struct colapedidos{
    nodopedido * pri;
    nodopedido * ult;
};

struct inforepartidor{
    int dni;
    char nombreyapellido[100];
    char patente[8];
    int zona;
    int mediodetransporte;
};
struct reparchivo{
    int dni;
    char nombreyapellido[100];
    char patente[8];
    int zona;
};
struct repartidor{
    inforepartidor datos;
    nodopedido * pedidos;
};
struct nodorepartidor{
    repartidor info;
    nodorepartidor * sig;
};
bool archivosexisten(); //true si el archivo existe, false si no existe
void asignarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores);
nodorepartidor * buscarrepartidor(nodorepartidor * listarepartidores, int dni);
infopedido desencolarpedido(colapedidos matrizpedidos[14][4], int zona, int mediodetransporte);
void registrarentrega(infopedido pedido, nodorepartidor * repartidor);
void cargarrepartidores(nodorepartidor *& listarepartidores, bool & estado);//Carga los repartidores de los archivos
void insertarrepartidor(nodorepartidor *& listarepartidores, reparchivo repartidor, int mediodetransporte);//Inserta un repartidor en la lista

int main(){
    bool archivosexisten;
    colapedidos matrizpedidos[14][4]; //Matriz de cola de pedidos a procesar.
                        //14 zonas, 4 medios de transporte -> 0:Moto, 1:Auto, 2:Camioneta, 3:Camion
    nodorepartidor * listarepartidores; //Lista de repartidores. Cada elemento de la lista tiene una lista de pedidos completados dentro.
    cargarrepartidores(listarepartidores, archivosexisten);
    if(!archivosexisten){
        cout<<"\nERROR: No se encontraron los archivos necesarios para la ejecucion del programa. Por favor ejecute el programa de registro de empleados en el mismo directorio en el que se encuentre este programa\n";
        return 0;
    }
    int opcion = 0;
    while(opcion!=4){
        cout<<"\n\n\n\n\n\n\n\nElija una opcion: \n1: Ingresar pedido\n2: Asignar pedido\n3: Mostrar Pedidos\n4: Salir\n";
        cin>>opcion;
        switch(opcion){
            case 1:
            break;
            case 2:
            asignarpedido(matrizpedidos, listarepartidores);
            break;
            case 3:
            break;
        }
    }
    cout<<"\n\n\nSaliendo...\n\n\n";
    //Salir
return 0;
}


void cargarrepartidores(nodorepartidor *& listarepartidores, bool & estado){
    //Esta funcion agrega a TODOS los repartidores que se encuentren en los archivos a la lista de repartidores.
    //Esto implica que al momento de mostrar cada repartidor con sus entregas, será necesario saltear los
    //repartidores que tengan una lista de entregas vacia
    //Esta funcion esta pensada para ser ejecutada al principio del programa, para evitar tener que buscar los
    //4 archivos cada vez que se quiere entregar un pedido con un repartidor nuevo.
    estado = false;
    if (archivosexisten()){       
        estado = true;
        reparchivo repartidor;
        FILE * motos = fopen("RepMoto.dat", "r");
        FILE * autos = fopen("RepAuto.dat", "r");
        FILE * camionetas = fopen("RepCamioneta.dat", "r");
        FILE * camiones = fopen("RepCamion.dat", "r");
        
        fread(&repartidor, sizeof(repartidor), 1, motos);
        while(!feof){
            insertarrepartidor(listarepartidores, repartidor, 0);
            fread(&repartidor, sizeof(repartidor), 1, motos);
        }

        fread(&repartidor, sizeof(repartidor), 1, autos);
        while(!feof){
            insertarrepartidor(listarepartidores, repartidor, 1);
            fread(&repartidor, sizeof(repartidor), 1, autos);
        }

        fread(&repartidor, sizeof(repartidor), 1, camionetas);
        while(!feof){
            insertarrepartidor(listarepartidores, repartidor, 2);
            fread(&repartidor, sizeof(repartidor), 1, camionetas);
        }

        fread(&repartidor, sizeof(repartidor), 1, camiones);
        while(!feof){
            insertarrepartidor(listarepartidores, repartidor, 3);
            fread(&repartidor, sizeof(repartidor), 1, camiones);
        }
    }
}

void insertarrepartidor(nodorepartidor *& listarepartidores, reparchivo repartidor, int transporte){
    //Inserta un repartidor del archivo en la lista de repartidores en orden de DNI.
    //Tambien inicializa la lista pedidos en NULL
    nodorepartidor * p;
    nodorepartidor * ant;
        nodorepartidor * n;
        n = new nodorepartidor;
        n->info.datos.dni=repartidor.dni;
        n->info.datos.mediodetransporte = transporte;
        strcpy(n->info.datos.nombreyapellido, repartidor.nombreyapellido);
        strcpy(n->info.datos.patente, repartidor.patente);
        n->info.datos.zona = repartidor.zona;
        n->info.pedidos=NULL;
    if (listarepartidores==NULL){
        listarepartidores=n;
    }
    p=listarepartidores;
    while(p!=NULL and p->info.datos.dni>repartidor.dni){
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    ant->sig=n;
    return;
}


void asignarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores){
    //Esta funcion busca en la lista de repartidores a quien corresponde el DNI y cual es su 
    //zona y su medio de transporte y con esa informacion saca un pedido de la cola y lo agrega a la 
    //lista de repartidores
    int dni, zona, mediodetransporte;
    cout<<"\nIngrese el dni del repartidor";
    cin>>dni;

    nodorepartidor * repartidor;
    repartidor = buscarrepartidor(listarepartidores, dni);
    //Esta funcion devuelve un pointer al repartidorcon x dni y NULL si no se encuentra el repartidor
    if(repartidor==NULL){
        cout<<"\nEl repartidor no pudo ser encontrado";
        return;
    }

    infopedido pedido;
    pedido = desencolarpedido(matrizpedidos, zona, mediodetransporte); 
    //Esta funcion debe devolver la informacion del pedido si lo encuentra, y si no, un pedido con importe -1 para señalar el error.
    if(pedido.importe==-1){
        cout<<"\nNo hay pedidos adecuados para el repartidor";
        return;
    }

    registrarentrega(pedido, repartidor);
    //Esta funcion usa un pointer al repartidor para agregar el pedido entregado.
    cout<<"\n\nPedido registrado\n\n";
    return;
}

bool archivosexisten()
{
    FILE *m, *a, *ct, *cn;
    m = fopen("RepMoto.dat", "r");
    a = fopen("RepAuto.dat", "r");
    ct = fopen("RepCamioneta.dat", "r");
    cn = fopen("RepCamion.dat", "r");
    if (a != NULL and m!=NULL and ct!= NULL and cn!=NULL)
    {
        fclose(a);fclose(m);fclose(ct);fclose(cn);
        return true;
    }
    return false;
}


void registrarentrega(infopedido pedidodesencolado, nodorepartidor * repartidor){
    // Esta funcion recibe el pedido desencolado y el repartidor que lo completo y lo agrega a la lista
    // de perdidos completados de dicho repoartidor
    nodopedido * p, * ant, * n;
    n = new nodopedido;
    n->pedido = pedidodesencolado; //Incluye codigo, domicilio e importe
    n->sig = NULL;
    if(repartidor->info.pedidos==NULL){
        repartidor->info.pedidos = n;
        return;
    }
    p=repartidor->info.pedidos;
    while(p!=NULL and p->pedido.importe<pedidodesencolado.importe){
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    ant->sig = n;

}

nodorepartidor * buscarrepartidor(nodorepartidor * listarepartidores, int dni){
return NULL;
}

infopedido desencolarpedido(colapedidos matrizpedidos[14][4], int zona, int mediodetransporte){
infopedido pedido;
//Poner codigo para que desencole el pedido
return pedido;
}

