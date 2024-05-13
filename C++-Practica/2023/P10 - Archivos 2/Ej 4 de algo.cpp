#include <iostream>
#include <stdio.h>
#include <conio.h>

struct Producto
{
    int codigo;
    int stock;
};
struct Pedido
{
    int numeroPedido;
    int numeroCliente;
    int numeroProducto;
    int cantidadPedida;
};
using namespace std;
void mostrar(Pedido);
main()
{
    Pedido tempPedido;
    Producto tempProducto;
    FILE *archivoProductos = fopen("archProd.dat", "r+");
    FILE *archivoPedidos = fopen("archPed.dat", "r");
    FILE *archivoFracasos = fopen("archFrac.dat", "w");
    fread(&tempPedido, sizeof(tempPedido), 1, archivoPedidos);
    while (!feof(archivoPedidos))
    {
        fseek(archivoProductos, (tempPedido.numeroPedido - 1) * sizeof(Producto), 0);
        fread(&tempProducto, sizeof(tempProducto), 1, archivoProductos);
        if (tempProducto.stock >= tempPedido.cantidadPedida)
        {
            mostrar(tempPedido);
            tempProducto.stock-=tempPedido.cantidadPedida;
            fseek(archivoProductos, sizeof(Producto), 1);
            fwrite(&tempProducto, sizeof(tempProducto), 1, archivoProductos);
        }
        else
        {
            fwrite(&tempPedido, sizeof(tempPedido), 1, archivoFracasos);
        }
        fread(&tempPedido, sizeof(tempPedido), 1, archivoPedidos);
    }
    getch;
    return 0;
}
void mostrar(Pedido a){
    cout<<"\n"<<a.numeroPedido<<"\t"<<a.numeroCliente<<"\t"<<a.numeroProducto<<"\t"<<a.cantidadPedida;
    return;
}