#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
void producto(int num, int conj[], int t, int z);
main()
{
    int z = 16;
    int t = 8;
    int conjunto[t] = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "\t│";
    for (int i = 0; i < t; i++)
    {
        cout << left << setw(5) << conjunto[i] << " ";
    }
    cout << "\n────────┼────────────────────────────────────────────────────────────────────────────────\n";
    for (int i = 0; i < t; i++)
    {
        cout << conjunto[i] << "\t│";
        producto(conjunto[i], conjunto, t, z);
        cout << "\n";
    }
    getch();
    return 0;
}

void producto(int num, int conj[], int t, int z)
{
    int a;
    for (int i = 0; i < t; i++)
    {

        a = num * conj[i];
        cout << left << setw(5) << a % z << " ";
    }
}