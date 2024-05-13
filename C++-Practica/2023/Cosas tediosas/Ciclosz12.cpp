#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
void ciclo(int num, int conj[], int t, int z);
main()
{
    int z = 12;
    int t = 12;
    int conjunto[t] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "\n\n";
    for (int i=0; i<t; i++){
        ciclo(conjunto[i], conjunto, t, z);
    }
    getch();
    return 0;
}
void ciclo(int num, int conj[], int t, int z){
    int ciclonumero[t],i=1;
    ciclonumero[0]=num;
    ciclonumero[i]=(num+num)%z;
    while(ciclonumero[i]!=ciclonumero[0]){
        i++;
        ciclonumero[i]=(ciclonumero[i-1]+ciclonumero[0])%z;

    }
    cout<<"\n<"<<num<<"> = {";
    for (int q=0; q<i; q++){
        cout<<ciclonumero[q]<<";";
    }
    cout<<"\b}\n";
}
