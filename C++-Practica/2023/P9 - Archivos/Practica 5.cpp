#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct empleado
{
    int dni;
    char nombreyapellido[100];
};
main()
{
    empleado motos[280];
    cin >> motos[0].dni;
    char a[100];
    fflush(stdin);
    cin.getline(a, sizeof(a));
    strcpy(motos[0].nombreyapellido, a);
    cout << motos[0].dni << "----" << motos[0].nombreyapellido;
    getch();
    return 0;
}
