#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

float porcentaje(float, float);

int main(){
    float a, b;
    cin>>(a);
    cin>>(b);
    if (b!=0) cout<<porcentaje(a, b)<<"%";
    else cout<<"ERROR";
    getch();
    return 0;
}

float porcentaje(float a, float b){
    if (b!=0)return ((a/b)*100);
    else cout<<"xd";
    return 0.0f; 
}