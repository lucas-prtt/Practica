#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

bool divisible(int,int);
int factorial(int);


int main(){
    int num, div3 = 0, div5 = 0, div3y5 = 0;
    do
    {
    cin>>num;
    if (divisible(num, 3) and divisible(num, 5))
        div3y5++;
    else if (divisible(num, 3))
        div3++;
    else if (divisible(num, 5))
        div5++;
    cout<<"Su factorial es:\n"<<factorial(num)<<endl;
    }
    while
    (num!=0);
    cout<<"Hubo "<<div3<<" numeros divisibles por 3, "<<div5<<" numeros divisibles por 5 y "<<div3y5<<" que fueron divisibles por los dos a la vez";
    getch();
    return 0;
}

bool divisible(int a,int b)
{
if(a%b==0 or b%a==0) 
return true;
else
return false;
}

int factorial(int n){
    if (n>=1){
        long f = 1;
        for(int i=1; i<=n; i++){f*=i;}
        return f;}
        else {cout<<"Solo se admiten numeros mayores o iguales a ";return 1;}}
