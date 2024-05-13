#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main(){
    double sueldo;
    int i=0, a = 0, b = 0, c = 0, d = 0;
    while(sueldo!=0){
        i++;
        cout<<"\n(Ingrese sueldo 0 para finalizar el ingreso de datos)\n"<<"Ingrese el sueldo del empleado "<<i<<": ";
        cin>>sueldo;
        cout<<"\n";
        if(sueldo<900 and sueldo!=0){a++;}
        if(sueldo>=900 and sueldo<1200){b++;}
        if(sueldo>=1200 and sueldo<2000){c++;}
        if(sueldo>=2000){d++;}
    }
    cout<<"\n\n\n\n\n\n";
    cout<<"\n\t--> "<<a<<" empleados ganan menos de 900";
    cout<<"\n\t--> "<<b<<" empleados ganan entre 900 y 1200";
    cout<<"\n\t--> "<<c<<" empleados ganan entre 1200 y 2000";
    cout<<"\n\t--> "<<d<<" empleados ganan mas de 2000\n";
    getch();
    return 0;
}