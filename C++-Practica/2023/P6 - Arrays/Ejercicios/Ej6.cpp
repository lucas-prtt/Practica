#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

main(){
int tirada, resultados[11];
for(int i=0; i<11; i++){resultados[i]=0;}
cout<<"Este programa le dirá cuantas veces se dio cada resultado de 50 tiradas de dados\n";
for(int i=0; i<50; i++)
{
    cout<<"Tirada "<<i+1<<":";
    do{cin>>tirada;}while(tirada<2 or tirada>12);
    resultados[tirada-2]++;
}
for(int i=0; i<11; i++){
    cout<<"\n El numero "<<i+2<<" salio "<<resultados[i]<<" veces.";
}
getch();
return 0;
}