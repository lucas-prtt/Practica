#include <iostream>

using namespace std;

struct infocliente{
        int codigo;
        int cuota;
};
struct nodocliente{
    infocliente info;
    nodocliente * sig;
};

void enlistar(nodocliente *& lista,infocliente cliente);
void imprimirlista(nodocliente * lista);
main(){
    srand(time(NULL));
    infocliente cliente;
    nodocliente * lista;
    lista = NULL;
    int a;
    cin>>a;
    cliente.codigo=a;
    cliente.cuota=a*10+rand()%10+rand()%5*a;
    while(a!=0){
        enlistar(lista, cliente);
        cin>>a;
        cliente.codigo=a;
        cliente.cuota=a*10+rand()%10+rand()%5*a;
    }
    imprimirlista(lista);

   /* FILE * archivo = fopen("cobranzas.dat", "rb");

    fread(&cliente, sizeof(cliente), 1, archivo);
    while(!feof){
        enlistar(lista, cliente);
        fread(&cliente, sizeof(cliente), 1, archivo);
    }*/
    return 0;
}

void enlistar(nodocliente *& lista,infocliente cliente){
    nodocliente * nuevonodo;
    nuevonodo = new nodocliente;
    nuevonodo->info=cliente;
    nuevonodo->sig=NULL;
    nodocliente * p =lista;
    nodocliente * ant;
    while(p!=NULL and p->info.codigo<cliente.codigo){
        ant = p;
        p=p->sig;

    }
    while(p!=NULL and (p->info.cuota<cliente.cuota and p->info.codigo==cliente.codigo)){
        ant = p;
        p=p->sig;
    }
    nuevonodo->sig=p;
    if(p!=lista)
    ant->sig= nuevonodo;
    else 
    lista = nuevonodo;
    return;
}
void imprimirlista(nodocliente * lista){
    cout<<"\nOk...\n";
    nodocliente * p;
    p = lista;
    while(p!=NULL){
        cout<<"\n- Codigo: "<<p->info.codigo << " Cuota: " << p->info.cuota;
        p=p->sig;
    }
    return;
};