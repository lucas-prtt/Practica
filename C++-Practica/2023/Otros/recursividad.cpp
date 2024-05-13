#include <iostream>
#include <conio.h>

using namespace std;
int reves(int);
int mcd(int, int);
int modulo(int);
int potencia(int, int);
int producto(int, int);
main(){
    int numero;
    cout<<"\nIngrese un numero: ";
    cin>>numero;
    reves(numero);
    cout<<"\n\n\n OTRO NUMERO: ";
    int numero2;
    cin>>numero2;
    cout<<potencia(numero, numero2)<<"\n";
    cout<<producto(numero, numero2)<<"\n";
    if (numero>numero2)
    cout<<mcd(numero, numero2);
    else
    cout<<mcd(numero2, numero);
    getch();
    return 0;
}
int producto(int n1, int n2){
    if(n2==0){return 0;}
    return n1 + producto(n1, n2-1);
}

int mcd(int dividendo, int divisor){
if(divisor==0) return dividendo;
return mcd(divisor, dividendo%divisor);
}

int reves(int n){
if(n>-10 and n<10){
cout<<n;
return n;}
else{
cout<<n%10;
return reves(modulo(n/10));
}
};
int modulo(int n){
    if(n<0) return -n;
    else return n;
}
int potencia(int a, int n){
    if(n==0)return 1;
    return a*potencia(a, n-1);
}