#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;


struct infopedido{
    char domicilio[50];
    float importe;
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

struct InfoComer
{
    int codigo;
    int cantidad;
};

struct NodoArbol
{
    InfoComer dato;
    NodoArbol *izq;
    NodoArbol *der;
};

bool archivosexisten(); //true si el archivo existe, false si no existe
void asignarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores, NodoArbol*& arbol);
nodorepartidor * buscarrepartidor(nodorepartidor * listarepartidores, int dni);
infopedido desencolarpedido(colapedidos matrizpedidos[14][4], int zona, int mediodetransporte);
void registrarentrega(infopedido pedido, nodorepartidor * repartidor);
void cargarrepartidores(nodorepartidor *& listarepartidores);//Carga los repartidores de los archivos
void insertarrepartidor(nodorepartidor *& listarepartidores, reparchivo repartidor, int mediodetransporte);//Inserta un repartidor en la lista
void ingresarpedido(colapedidos matrizpedidos[14][4]);//Funcion que encola un pedido nuevo en la matriz
void iniciar(colapedidos matriz[14][4]); //Funcion que inicializa las colas de la matrizpedidos[14][4]
int transporte(float v); //Funcion que devuelve un entero de 0-3 (que corresponde al vehiculo), a partir del volumen del pedido
void arbol(NodoArbol *&raiz, infopedido pedidodesencolado);//Funcion que crea el arbol binario
NodoArbol *busqueda(NodoArbol *raiz, infopedido pedidodesencolado);//Funcion que busca un elemnto en el arbol binario
void arbolInsertar(NodoArbol *&raiz, infopedido pedidodesencolado);//Función que inserta un elemento en el arbol binario si no lo encuentra
void listarIn(NodoArbol *raiz);//Función que imprme una lista del arbol binario
void debug(colapedidos[14][4]);//Para revisar todas las colas
int main(){
    cout<<"Iniciando programa...\n";
   if(!archivosexisten()){
        cout<<"\nERROR: No se encontraron los archivos necesarios para la ejecucion del programa. Por favor ejecute el programa de registro de empleados en el mismo directorio en el que se encuentre este programa\n";
        return 0;
    }
    colapedidos matrizpedidos[14][4]; //Matriz de cola de pedidos a procesar.
                        //14 zonas, 4 medios de transporte -> 0:Moto, 1:Auto, 2:Camioneta, 3:Camion
    iniciar(matrizpedidos); //Inicializa matriz
    nodorepartidor * listarepartidores = NULL; //Lista de repartidores. Cada elemento de la lista tiene una lista de pedidos completados dentro.
    cargarrepartidores(listarepartidores);
    NodoArbol * arbol=NULL;
    int opcion = 0;
    while(opcion!=4){
        cout<<"\n\n\n\n\n\n\n\nElija una opcion: \n1: Ingresar pedido\n2: Asignar pedido\n3: Mostrar Pedidos\n4: Salir\n";
        cin>>opcion;
        switch(opcion){
            case 1:
            ingresarpedido(matrizpedidos);
            break;
            case 2:
            asignarpedido(matrizpedidos, listarepartidores, arbol);
            break;
            case 3:
            break;
            case 99:
            debug(matrizpedidos);
            break;
            case 4:
            break;
        }
    }
    cout<<"\n\n\nSaliendo...\n\n\n";
    //Salir
return 0;
}

void ingresarpedido(colapedidos matrizpedidos[14][4]){
    int zona=0,trans;
    float vol;

    nodopedido*p;
    p=new nodopedido;

    //Inicio de pedido
    cout<<"Ingrese la zona de entrega (1-14): ";
    cin>>zona;

    cout<<endl<<"Ingrese el volumen del paquete en metros cuadrados: ";
    cin>>vol;

    cout<<endl<<"Ingrese el domicilio: ";
    cin>>p->pedido.domicilio;

    cout<<endl<<"Ingrese el importe: ";
    cin>>p->pedido.importe;

    cout<<endl<<"Ingrese el código de comercio: ";
    cin>>p->pedido.codigo;
    trans=transporte(vol);
    p->sig=NULL;
    if(matrizpedidos[zona-1][trans].ult!=NULL)
        matrizpedidos[zona-1][trans].ult->sig=p;
    else
        matrizpedidos[zona-1][trans].pri=p;
    matrizpedidos[zona-1][trans].ult=p;
}

int transporte(float v){
    if(v>8)
        return 3;
    else if(v>0.02)
        return 2;
    else if(v>0.005)
        return 1;
    else
        return 0;
}

void iniciar(colapedidos matriz[14][4]){
    for(int i=0;i<=14;i++)
    {
        for(int j=0;j<=4;j++)
        {
            matriz[i][j].pri=NULL;
            matriz[i][j].ult=NULL;
        }
    }
}

void cargarrepartidores(nodorepartidor *& listarepartidores){
    //Esta funcion agrega a TODOS los repartidores que se encuentren en los archivos a la lista de repartidores.
    //Esto implica que al momento de mostrar cada repartidor con sus entregas, será necesario saltear los
    //repartidores que tengan una lista de entregas vacia
    //Esta funcion esta pensada para ser ejecutada al principio del programa, para evitar tener que buscar los
    //4 archivos cada vez que se quiere entregar un pedido con un repartidor nuevo.
        reparchivo repartidor;
        FILE * motos = fopen("RepMoto.dat", "r");
        FILE * autos = fopen("RepAuto.dat", "r");
        FILE * camionetas = fopen("RepCamioneta.dat", "r");
        FILE * camiones = fopen("RepCamion.dat", "r");

        fread(&repartidor, sizeof(repartidor), 1, motos);
        while(!feof(motos)){
            insertarrepartidor(listarepartidores, repartidor, 0);
            fread(&repartidor, sizeof(repartidor), 1, motos);
        }

        fread(&repartidor, sizeof(repartidor), 1, autos);
        while(!feof(autos)){
            insertarrepartidor(listarepartidores, repartidor, 1);
            fread(&repartidor, sizeof(repartidor), 1, autos);
        }

        fread(&repartidor, sizeof(repartidor), 1, camionetas);
        while(!feof(camionetas)){
            insertarrepartidor(listarepartidores, repartidor, 2);
            fread(&repartidor, sizeof(repartidor), 1, camionetas);
        }

        fread(&repartidor, sizeof(repartidor), 1, camiones);
        while(!feof(camiones)){
            insertarrepartidor(listarepartidores, repartidor, 3);
            fread(&repartidor, sizeof(repartidor), 1, camiones);
        }
}

void insertarrepartidor(nodorepartidor *& listarepartidores, reparchivo repartidor, int transporte){
    //Inserta un repartidor del archivo en la lista de repartidores en orden de DNI.
    //Tambien inicializa la lista pedidos en NULL
    cout<<" -> "<<repartidor.nombreyapellido<<" cargado\n";
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
        return;
    }
    p=listarepartidores;
    while(p!=NULL and p->info.datos.dni>repartidor.dni){
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=listarepartidores)
    ant->sig=n;
    else
    listarepartidores=n;
    return;
}

void asignarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores, NodoArbol *& arbolraiz){
    //Esta funcion busca en la lista de repartidores a quien corresponde el DNI y cual es su
    //zona y su medio de transporte y con esa informacion saca un pedido de la cola y lo agrega a la
    //lista de repartidores
    int dni, zona, mediodetransporte;
    cout<<"\nIngrese el dni del repartidor: ";
    cin>>dni;
    
    nodorepartidor * repartidor;
    repartidor = buscarrepartidor(listarepartidores, dni);
    //Esta funcion devuelve un pointer al repartidorcon x dni y NULL si no se encuentra el repartidor
    if(repartidor==NULL){
        cout<<"\nEl repartidor no pudo ser encontrado";
        return;
    }

    zona = repartidor->info.datos.zona;
    mediodetransporte=repartidor->info.datos.mediodetransporte;
    infopedido pedido;
    pedido = desencolarpedido(matrizpedidos, zona, mediodetransporte);
    //Esta funcion debe devolver la informacion del pedido si lo encuentra, y si no, un pedido con importe -1 para señalar el error.
    if(pedido.importe<0){
        cout<<"\nNo hay pedidos adecuados para el repartidor "<<repartidor->info.datos.nombreyapellido<<" que trabaja en la zona "<<zona<<" y viaja en "<<mediodetransporte;
        return;
    }

    registrarentrega(pedido, repartidor);
    arbol(arbolraiz, pedido);
    //Esta funcion usa un pointer al repartidor para agregar el pedido entregado.
    cout<<"\n\nPedido registrado\n\n";
    return;
}

bool archivosexisten(){
    //Comprueba que existan todos los archivos antes de realizar la carga de datos de los empleados
        FILE * motos = fopen("RepMoto.dat", "r");
        FILE * autos = fopen("RepAuto.dat", "r");
        FILE * camionetas = fopen("RepCamioneta.dat", "r");
        FILE * camiones = fopen("RepCamion.dat", "r");
    if (autos != NULL and motos!=NULL and camionetas!= NULL and camiones!=NULL)
    {
        fclose(autos);fclose(motos);fclose(camionetas);fclose(camiones);
        return true;
    }
    return false;
}

void registrarentrega(infopedido pedidodesencolado, nodorepartidor * repartidor){
    // Esta función recibe el pedido desencolado y el repartidor que lo completo y lo agrega a la lista
    // de perdidos completados de dicho repoartidor
    nodopedido * p, * ant, * n;
    NodoArbol *raiz;
    n = new nodopedido;
    n->pedido = pedidodesencolado; //Incluye codigo, domicilio e importe
    n->sig = NULL;
    p=repartidor->info.pedidos;
    while(p!=NULL and p->pedido.importe<pedidodesencolado.importe){
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if(p!=repartidor->info.pedidos)
    ant->sig = n;
    else
    repartidor->info.pedidos=n;
}

nodorepartidor * buscarrepartidor(nodorepartidor * listarepartidores, int dni){
//Si se encuentra el repartidor se devuelve un puntero al repartidor dentro de la lista.
//De lo contrario devuelve NULL
    nodorepartidor * p;
    p=listarepartidores;
    while(p!=NULL and p->info.datos.dni>dni){
        p=p->sig;
    }
return p;
}

infopedido desencolarpedido(colapedidos matrizpedidos[14][4], int zona, int mediodetransporte){
    infopedido pedido;
    // se verifica que la zona y medio sean validos, si no es asi, devuelve un -1
    if (zona < 1 || zona > 14 || mediodetransporte < 0 || mediodetransporte > 3){
        cout<<zona<<mediodetransporte; //Tecnicamente, nunca deberia finalizar aca ya que el medio de transporte y la zona vienen de los archivos del tp anterior, pero por las dudas dejemolos
        pedido.importe = -1;
        return pedido;
    }
    if (matrizpedidos[zona-1][mediodetransporte].pri == NULL){
        // si la cola está vacia, devuelve tmb -1
        pedido.importe = -1;
     }
     else{
        // si no está vacia, desencola el primer pedido y actualiza el puntero pri
        nodopedido* primerPedido = matrizpedidos[zona-1][mediodetransporte].pri;
        pedido = primerPedido->pedido;
        matrizpedidos[zona-1][mediodetransporte].pri = primerPedido->sig;
        delete primerPedido;

        // si la cola queda vacía, actualiza el puntero ult
        if (matrizpedidos[zona-1][mediodetransporte].pri == NULL){
            matrizpedidos[zona-1][mediodetransporte].ult = NULL;
        }
    }
    return pedido;
}

void arbol(NodoArbol *&raiz, infopedido pedidodesencolado){
    NodoArbol *r = raiz;
    cout<<"Se comenzo a ejecutar subrutina ARBOL";
    getch();
    busqueda(r, pedidodesencolado);
    if(r->dato.codigo == pedidodesencolado.codigo)
    {
        r->dato.cantidad++;//Le suma 1 a la cantidad de pedidos entregados en el negocio
    }
    else

        arbolInsertar(raiz, pedidodesencolado);//Lo agrega al arbol binario
}

NodoArbol *busqueda(NodoArbol *raiz, infopedido pedidodesencolado){
    NodoArbol *r = raiz;
    while(r != NULL && r->dato.codigo != pedidodesencolado.codigo)
    {
        if(pedidodesencolado.codigo < r->dato.codigo)
            r = r->izq;
        else
            r = r->der;
    }
    return r;
}

void arbolInsertar(NodoArbol *&raiz, infopedido pedidodesencolado){
    int nro;
    NodoArbol *n = new NodoArbol();
    n->dato.codigo = pedidodesencolado.codigo;
    n->izq = NULL;
    n->der = NULL;
    if(raiz == NULL)
    {
        raiz=n;
    }
    else
    {
        NodoArbol *r, *ant;
        r = raiz;
        while(r != NULL)
        {
            ant = r;
            if(n->dato.codigo > ant->dato.codigo)
            {
                r = r->izq;
            }
            else
            {
                r = r->der;
            }
        }
        if(n->dato.codigo > ant->dato.codigo)
        {
            ant->izq = n;
        }
        else
        {
            ant->der = n;
        }
    }
}

void listarIn(NodoArbol *raiz){
    if(raiz != NULL)
    {
        listarIn(raiz -> izq);
        cout << "   El comercio '" << raiz->dato.codigo << "' tuvo '" << raiz->dato.cantidad << "' entregas realizadas." << endl;
        listarIn(raiz -> der);
    }
}


void debug(colapedidos matrizpedidos[14][4]){
    cout<<"direcciones primeras de la matriz de pedidos:\n\n";
    for(int i=0; i<14; i++){    
    cout<<matrizpedidos[i][0].pri<<" . "<<matrizpedidos[i][1].pri<<" . "<<matrizpedidos[i][2].pri<<" . "<<matrizpedidos[i][3].pri<<"\n";
    }


    cout<<"direcciones ultimas de la matriz de pedidos:\n\n";
    for(int i=0; i<14; i++){    
    cout<<matrizpedidos[i][0].ult<<" . "<<matrizpedidos[i][1].ult<<" . "<<matrizpedidos[i][2].ult<<" . "<<matrizpedidos[i][3].ult<<"\n";
    }


    return;
}