#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    float cat1, cat2, hip;
    cout<<endl<<endl<<endl<<endl<<"Cateto 1: ";
    cin>>cat1;
    cout<<"Cateto 2: ";
    cin>>cat2;
    hip = sqrt(pow(cat1, 2)+pow(cat2, 2));
    cout<<endl<<endl<<"La hipotenusa mide: "<<hip<<endl<<endl<<endl;
    getch();
    return 0;
}