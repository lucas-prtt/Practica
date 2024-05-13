#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int lafuncion(int,int);

int main(){
    int a, b;
    cin>>a;
    cin>>b;
    cout<<"\n\n\n"<<lafuncion(a, b);
    getch();
    return 0;
}

int lafuncion(int na, int nb){
int div, res;
do{
div = na/nb;
res = na%nb;
if(res!=0){
    na = nb;
    nb = res;
}
} while (res!=0);

return nb;
}