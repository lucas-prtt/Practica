#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
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
bool presenciaderepartidoresconfirmada(nodorepartidor * listarepartidores, int zona, int transporte);
void mostrar(nodorepartidor * listarepartidores);
void ValidaEnteros(int &a);
void ValidaFloat(float &a);
bool archivosexisten(); //true si el archivo existe, false si no existe
void asignarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores, NodoArbol*& arbol);
nodorepartidor * buscarrepartidor(nodorepartidor * listarepartidores, int dni);
infopedido desencolarpedido(colapedidos matrizpedidos[14][4], int zona, int mediodetransporte);
void registrarentrega(infopedido pedido, nodorepartidor * repartidor);
void cargarrepartidores(nodorepartidor *& listarepartidores);//Carga los repartidores de los archivos
void insertarrepartidor(nodorepartidor *& listarepartidores, reparchivo repartidor, int mediodetransporte);//Inserta un repartidor en la lista
void ingresarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores);//Funcion que encola un pedido nuevo en la matriz
void iniciar(colapedidos matriz[14][4]); //Funcion que inicializa las colas de la matrizpedidos[14][4]
int transporte(float v); //Funcion que devuelve un entero de 0-3 (que corresponde al vehiculo), a partir del volumen del pedido
void arbol(NodoArbol *&raiz, infopedido pedidodesencolado);//Funcion que crea el arbol binario
void arbolInsertar(NodoArbol *&raiz, infopedido pedidodesencolado);//Función que inserta un elemento en el arbol binario si no lo encuentra
void listarIn(NodoArbol *raiz);//Función que imprme una lista del arbol binario
void debug(colapedidos[14][4]);//Para revisar todas las colas
void guardarPedidosNoEntregados(colapedidos[14][4]);
int ingresoverificadoATOI(int maxlongitud);
float ingresoverificadoATOF(int maxlongitud);

int main(){
    cout<<"Iniciando programa...\n";
   if(!archivosexisten()){
        cout<<"\nERROR: No se encontraron los archivos necesarios para la ejecucion del programa. Por favor ejecute el programa de registro de empleados en el mismo directorio en el que se encuentre este programa\n";
        getch();
        return 0;
    }
    colapedidos matrizpedidos[14][4]; //Matriz de cola de pedidos a procesar.
                        //14 zonas, 4 medios de transporte -> 0:Moto, 1:Auto, 2:Camioneta, 3:Camion
    iniciar(matrizpedidos); //Inicializa matriz
    nodorepartidor * listarepartidores = NULL; //Lista de repartidores. Cada elemento de la lista tiene una lista de pedidos completados dentro.
    cargarrepartidores(listarepartidores);
    NodoArbol *arbol=NULL;
    int opcion = 0;
    while(opcion!=4){
        cout<<"\n\n\n\n\nElija una opcion: \n1: Ingresar pedido\n2: Asignar pedido\n3: Mostrar Pedidos\n4: Salir\n\n>";
        opcion = ingresoverificadoATOI(100);
        switch(opcion){
            case 1:
            ingresarpedido(matrizpedidos, listarepartidores);
            break;
            case 2:
            asignarpedido(matrizpedidos, listarepartidores, arbol);
            break;
            case 3:
            mostrar(listarepartidores);
            break;
            /*case 99:
            debug(matrizpedidos);
            break;*/
            // Esa funcion mostraba una tabla con todas las direcciones de memoria primeras y ultimas
            // de matrizpedidos, la dejo comentada por si hubiese que arreglar algo
            case 4:
            break;
        }
    }

    guardarPedidosNoEntregados(matrizpedidos);
    cout<<"\nPedidos restantes agregados al archivo 'PedidosNoEntregados.dat'.\n\n\n";
    listarIn(arbol);
    getch();
    cout<<"\n\n\nCerrando el programa...\nPresione cualquier tecla para continuar\n\n\n";
    getch();
    //Salir
return 0;
}

void ingresarpedido(colapedidos matrizpedidos[14][4], nodorepartidor * listarepartidores){
    int zona=0,trans;
    float vol;

    nodopedido*p;
    p=new nodopedido;
    cout<<"\n\n";
    //Inicio de pedido
    do{
    cout<<"Ingrese la zona de entrega (1-14): ";
    zona = ingresoverificadoATOI(100);
    }while(zona<1 or zona>14);
    do{
    cout<<endl<<"Ingrese el volumen del paquete en metros cubicos: ";
    vol=ingresoverificadoATOF(100);
    }while(vol<=0);     //Tal vez redundante ya que la funcion ingresoverificadoATOF solo toma como validos numeros positivos, pero por las dudas
    trans=transporte(vol);
    if(!presenciaderepartidoresconfirmada(listarepartidores, zona, trans)){ //Si no hay repartidores
        cout<<"\n\nError: No se dispone de ningun repartidor que pueda entregar pedidos de ese volumen en esa zona \nPresione una tecla para continuar\n";
        getch();
        return;
    }

    cout<<endl<<"Ingrese el domicilio: ";
        cin.getline(p->pedido.domicilio, sizeof(p->pedido.domicilio)); //Ingresa valor
        fflush(stdin);
    do{
    cout<<endl<<"Ingrese el importe: ";
    p->pedido.importe = ingresoverificadoATOF(100);
    }while(p->pedido.importe<0); //Dejamos abierta la posibilidad a un pedido gratis, pero no a uno negativo
    cout<<endl<<"Ingrese el codigo de comercio: ";
    p->pedido.codigo = ingresoverificadoATOI(100); //No puede ser negativo, funcion validaenteros no acepta negativos. 
    //Suponemos que el codigo es un entero positivo
    p->sig=NULL;
    if(matrizpedidos[zona-1][trans].ult!=NULL)
        matrizpedidos[zona-1][trans].ult->sig=p;
    else
        matrizpedidos[zona-1][trans].pri=p;
    matrizpedidos[zona-1][trans].ult=p;
}

bool presenciaderepartidoresconfirmada(nodorepartidor * listarepartidores, int zona, int transporte){
    nodorepartidor * p=listarepartidores;
    while(p!=NULL and (p->info.datos.zona != zona or p->info.datos.mediodetransporte!=transporte)){
        p=p->sig;
    }
    if(p==NULL){
        return false;
    }
    return true;
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
        cout<<"Repartidores registrados: \n\n";
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
    cout<<" -> DNI: "<<repartidor.dni<<"\tNombre: "<<repartidor.nombreyapellido<<"\n";
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
        n->sig=NULL;
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
    do{
    dni = ingresoverificadoATOI(100);
    }while(dni<=0);

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
        cout<<"\nNo hay pedidos adecuados para el repartidor "<<repartidor->info.datos.nombreyapellido;
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
    while(p!=NULL and p->pedido.importe>pedidodesencolado.importe){
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
    if(p->info.datos.dni==dni){
    return p;
    }
    else{
        return NULL;
    }
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

void arbol(NodoArbol *&raiz, infopedido pedidodesencolado){ //Quedo medio inutil esta funcion aca
    arbolInsertar(raiz, pedidodesencolado);//Lo agrega al arbol binario
}

void arbolInsertar(NodoArbol *&raiz, infopedido pedidodesencolado){
    int nro;
    NodoArbol *n = new NodoArbol();
    n->dato.codigo = pedidodesencolado.codigo;
    n->dato.cantidad = 1;
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
                if(n->dato.codigo < ant->dato.codigo)
                {
                    r = r->der;
                }
                else
                {
                    r->dato.cantidad++;
                    return;
                }

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
        // Di vuelta izquierda y derecha porque alguien puso mal los signos en la funcion de crear el arbol
        // y coregir aca me parece mas facil que corregir en el otro
        listarIn(raiz -> der);
        cout << "   El comercio '" << raiz->dato.codigo << "' tuvo '" << raiz->dato.cantidad << "' entregas realizadas." << endl;
        listarIn(raiz -> izq);
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

void mostrar(nodorepartidor * listarepartidores){
    nodorepartidor * repartidoractual=listarepartidores;
    nodopedido * pedidoactual;
    int i=0;
    cout<<"\n\n\n";
    while(repartidoractual!=NULL){
        if(repartidoractual->info.pedidos!=NULL){ //Si tiene pedidos
        cout<<"\n\n\n\nRepartidor: "<<repartidoractual->info.datos.nombreyapellido;
        cout<<"\nDNI: "<<repartidoractual->info.datos.dni<<"\n\n";
        pedidoactual=repartidoractual->info.pedidos;
        i=0;
        while(pedidoactual!=NULL){
            i++;
            cout<<"\n\tPedido "<<i<<":\n"<<"Destino: "<<pedidoactual->pedido.domicilio;
            cout<<"\nCodigo de comercio: "<<pedidoactual->pedido.codigo;
            cout<<"\nImporte: ";
            printf("$%.2f\n\n", pedidoactual->pedido.importe);
            pedidoactual=pedidoactual->sig;
        }
        getch();
        }
        repartidoractual=repartidoractual->sig;
    }

    cout<<"\n\nFin de los repartidores\n";
}

void guardarPedidosNoEntregados(colapedidos matrizpedidos[14][4]){
    FILE* archivo = fopen("PedidosNoEntregados.dat", "ab");


    if (archivo == NULL){
        cout << "No se pudo abrir el archivo de salida" << endl;
        return;
    }
    // i = zona, j = transporte
    for (int i = 0; i < 14; i++){
        for (int j = 0; j < 4; j++){
            nodopedido* actual = matrizpedidos[i][j].pri;
            while(actual != NULL){
                fwrite(&actual->pedido, sizeof(infopedido), 1, archivo);
                actual = actual->sig;
            }
        }
    }
    fclose(archivo);
}

int ingresoverificadoATOI(int lmax){
    int num, i;
    char palabra[lmax];

    do{
        for(int q=0; q<lmax; q++) //Pone todo caracter en 0 (vacio)
            palabra[lmax]=0;
        
        cin.getline(palabra, sizeof(palabra)); //Ingresa valor
        fflush(stdin);

        i=0;
        while(i<lmax and isdigit(palabra[i])){ //Busca ultimo caracter que no es un numero
            i++;
        }

    }while(i==0 or palabra[i]!=0); //Si el ultimo caracter que no es un numero esta vacio, o es el primero, se vuelve a introducir
    //Solo continua si palabra es un array de numeros continuo y no vacio (No negativo)
    num = atoi(palabra);
    return num;
}
float ingresoverificadoATOF(int lmax){
    int i;
    float num;
    char palabra[lmax];
    bool yahubounpunto;
    do{
        for(int q=0; q<lmax; q++) //Pone todo caracter en 0 (vacio)
            palabra[lmax]=0;
        
        cin.getline(palabra, sizeof(palabra)); //Ingresa valor
        fflush(stdin);
        yahubounpunto=false;
        i=0;
        while(i<lmax and (isdigit(palabra[i]) or (!yahubounpunto and palabra[i]==('.')))){ //Busca ultimo caracter que no es un numero
            if(palabra[i]=='.')
            yahubounpunto=true;
            i++;
        }

    }while(i==0 or palabra[0] == '.' or palabra[i]!=0); //Si el ultimo caracter que no es un numero esta vacio, o es el primero, o es un punto, se vuelve a introducir
    //Solo continua si palabra es un array de numeros continuo con a lo sumo un punto y no es vacio (No negativo)
    num = atof(palabra);
    return num;
}