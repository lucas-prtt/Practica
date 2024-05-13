#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

bool lafuncion(int, int);

int main(){
    int a, b;
    cin>>a;
    cin>>b;
    cout<<"\n\n\n"<<lafuncion(a, b);
    getch();
    return 0;
}

bool lafuncion(int a,int b){
if(a%b==0 or b%a==0) 
return true;
else
return false;
}