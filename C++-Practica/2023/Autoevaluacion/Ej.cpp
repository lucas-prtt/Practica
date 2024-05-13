#include <iostream>
#include <conio.h>

using namespace std;

struct nodoinscripto
{
    int dni;
    char nombreyapellido[100];
    float ingreso;
    nodoinscripto *sig;
};

struct nodocredito
{
    nodoinscripto *inscriptos;
    int codigo;
    int restantes = 0;
    int otorgados;
    nodocredito *sig;
};
struct inscripto
{
    int dni;
    char nombreyapellido[100];
    int codigo;
    float ingreso;
};
struct credito
{
    int codigo;
    char desc[100];
    int otorgados;
};
void mostrarcreditos(nodocredito *lista);
void leerlista();
void todoscodigos();
void insertarcodigo();
void ingresarcreditos(nodocredito *&lista);
void organizarinscriptos(nodocredito *lista);
void otorgarcreditos(nodocredito *lista);
void insertar(nodocredito *lista, credito nuevo);
main()
{
    cout << " Inicio\n\n\n";
    nodocredito *lista = NULL;
    todoscodigos();
    ingresarcreditos(lista);
    mostrarcreditos(lista);
    getch();
    return 0;
}
void ingresarcreditos(nodocredito *&lista)
{
    FILE *archcod = fopen("Creditos.dat", "rb");

    if (archcod == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }

    credito creditoleido, nuevocredito;
    nodocredito *p, *ant, *n;
    int codigo;
    int cantidad;

    cout << "\n\nIngrese codigo 0 para finalizar\nCodigo del credito: ";
    cin >> codigo;
    while (codigo != 0)
    {
        fseek(archcod, 0, 0);
        cout << "Ingrese la cantidad de creditos a ofrecer";
        cin >> cantidad;
        fread(&creditoleido, sizeof(creditoleido), 1, archcod);
        while (!feof(archcod) and creditoleido.codigo != codigo)
        {
            fread(&creditoleido, sizeof(creditoleido), 1, archcod);
        }
        cout << creditoleido.codigo << creditoleido.desc << creditoleido.otorgados;

        p = lista;
        while (p != NULL and p->codigo < codigo)
        {
            ant = p;
            p = p->sig;
        }
        if (p != NULL and codigo == p->codigo)
        {
            cout << "Ese codigo ya estaba";
        }
        else
        {
            n = new nodocredito;
            n->codigo = codigo;
            n->otorgados = creditoleido.otorgados;
            n->restantes = cantidad;
            n->inscriptos = NULL;
            n->sig = p;
            if (p == lista)
            {
                lista = n;
            }
            else
            {
                ant->sig = n;
            }
        }

        cout << "\nCodigo del credito: ";
        cin >> codigo;
    }
}

void todoscodigos()
{
    credito temp;
    FILE *arch = fopen("Creditos.dat", "rb");
    fread(&temp, sizeof(temp), 1, arch);
    while (!feof(arch))
    {
        cout << temp.codigo << " - "
             << "\n";
        fread(&temp, sizeof(temp), 1, arch);
    }
    return;
}


void mostrarcreditos(nodocredito *lista)
{
    nodocredito *p = lista;
    while (p != NULL)
    {
        cout << p->codigo << " - " << p->restantes;
        p = p->sig;
    }
}