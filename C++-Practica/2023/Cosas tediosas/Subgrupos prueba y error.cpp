#include <iostream>
#include <conio.h>
#define modulo 16
#define tamgrupo 8
// Solo para los subgrupos de tamaño 4
// ATENCION: Codigo muy mal optimizado

using namespace std;
int operar(int a, int b);
bool validarsubgrupo(int[4]);
bool pertenece(int[4], int);
bool norepite(int[4]);
void depurar(int todos[][4], int);
main()
{
    int todos[9999][4];
    int f = 0;
    int conjunto[tamgrupo] = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "\n\n";
    int subgrupo[4];
    for (int i = 0; i < tamgrupo; i++)
    {
        for (int q = 0; q < tamgrupo; q++)
        {
            for (int r = 0; r < tamgrupo; r++)
            {
                for (int j = 0; j < tamgrupo; j++)
                {
                    subgrupo[0] = conjunto[i];
                    subgrupo[1] = conjunto[q];
                    subgrupo[2] = conjunto[r];
                    subgrupo[3] = conjunto[j];
                    if (norepite(subgrupo) and validarsubgrupo(subgrupo))
                    {
                        todos[f][0] = subgrupo[0];
                        todos[f][1] = subgrupo[1];
                        todos[f][2] = subgrupo[2];
                        todos[f][3] = subgrupo[3];
                        f++;
                    }
                }
            }
        }
    }
    cout << "\n-----------------------------------------------------------------------------------------\n";
    depurar(todos, f);
    cout << "\nfin\n";
    getch();
    return 0;
}
void depurar(int todos[][4], int t)
{
    bool es;
    int suma;
    for (int i = 0; i < t; i++)
    {
        es = true;
        for (int q = 0; q < i; q++)
        {
            suma = 0;
            for (int l = 0; l < 4; l++)
            {
                for (int r = 0; r < 4; r++)
                {
                    if (todos[i][r] == todos[q][l])
                        suma++;
                }
            }
            if (suma >= 4)
            {
                es = false;
            }
        }
        if (es)
        {
            cout << "\n{" << todos[i][0] << "; " << todos[i][1] << "; " << todos[i][2] << "; " << todos[i][3] << "}";
        }
    }
}
int operar(int a, int b)
{
    return (a * b) % modulo;
}
bool validarsubgrupo(int subgrupo[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int q = 0; q < 4; q++)
        {
            if (!pertenece(subgrupo, operar(subgrupo[i], subgrupo[q])))
                return false;
        }
    }
    return true;
}
bool pertenece(int subgrupo[4], int x)
{
    for (int i = 0; i < 4; i++)
    {
        if (x == subgrupo[i])
        {
            return true;
        }
    }
    return false;
}
bool norepite(int subgrupo[4])
{
    int aux = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int q = 0; q < 4; q++)
        {
            aux += (subgrupo[q] == subgrupo[i]);
        }
    }
    if (aux == 4)
    {
        return true;
    }
    return false;
}