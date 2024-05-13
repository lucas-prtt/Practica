#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
main(){
    bool INV;
    int complemento;
    int i=13;
    int matriz[i][i];
    for(int cont1 = 0; cont1 < i; cont1++){
        for(int cont2 = 0; cont2<i; cont2++){
            matriz[cont1][cont2] = (cont1*cont2)%i;
        }
    }
    cout<<"\n";
    for(int cont1 = 0; cont1 < i; cont1++){
        INV = false;
        for(int cont2 = 0; cont2<i; cont2++){
            cout<<setw(3)<<matriz[cont1][cont2];
            if(matriz[cont1][cont2]==1){
            INV = true;
            complemento = cont2;}
        }
        if(INV){
            cout<<"      <---- "<<cont1<< "//" << complemento;
        }
        cout<<"\n";
    }
getch();
return 0;
}