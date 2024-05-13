#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main(){
    int numero, i, uni, dec, cen, mil;
    float promedio;
    cout<<"Ingrese un numero a convertir en numeros romanos: ";
    cin>>numero;
    //Separar el numero en partes
    uni = numero%10;
    dec = numero%100-uni;
    dec = dec/10;
    cen = numero%1000-dec-uni;
    cen = cen/100;
    mil = numero%10000-cen-dec-uni;
    mil = mil/1000;
    //Crear romano
        if(numero<=3999){
        
            cout<<"Su numero en romano es: ";
            switch(mil){
                case 0:cout<<"";break;
                case 1:cout<<"M";break;
                case 2:cout<<"MM";break;
                case 3:cout<<"MMM";break;
            }
            switch(cen){
                case 0:cout<<"";break;
                case 1:cout<<"C";break;
                case 2:cout<<"CC";break;
                case 3:cout<<"CCC";break;
                case 4:cout<<"CD";break;
                case 5:cout<<"D";break;
                case 6:cout<<"DC";break;
                case 7:cout<<"DCC";break;
                case 8:cout<<"DCCC";break;
                case 9:cout<<"CM";break;
            }
            switch(dec){
                case 0:cout<<"";break;
                case 1:cout<<"X";break;
                case 2:cout<<"XX";break;
                case 3:cout<<"XXX";break;
                case 4:cout<<"XL";break;
                case 5:cout<<"L";break;
                case 6:cout<<"LX";break;
                case 7:cout<<"LXX";break;
                case 8:cout<<"LXXX";break;
                case 9:cout<<"XC";break;
            }
            switch(uni){
                case 0:cout<<"";break;
                case 1:cout<<"I";break;
                case 2:cout<<"II";break;
                case 3:cout<<"III";break;
                case 4:cout<<"IV";break;
                case 5:cout<<"V";break;
                case 6:cout<<"VI";break;
                case 7:cout<<"VII";break;
                case 8:cout<<"VIII";break;
                case 9:cout<<"IX";break;
            }
        }else{cout<<"Demasiado grande";}
    getch();
    return 0;
}