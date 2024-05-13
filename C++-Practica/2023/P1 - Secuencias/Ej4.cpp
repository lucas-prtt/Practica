#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    int años, meses, totaldemeses;
    cout<<"Cuantos años tiene una persona?"<<endl;
    cin>>años;
    cout<<endl<<"Y meses?"<<endl;
    cin>>meses;
    totaldemeses=años*12+meses;
    cout<<endl<<"Entonces tiene "<<totaldemeses<<" meses";
    getch();
    return 0;
}