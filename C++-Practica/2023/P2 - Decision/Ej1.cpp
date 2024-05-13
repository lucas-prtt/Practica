#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
main(){
    float n1, n2, may;
    cout<<"\n\n\n\nIngrese un numero\n\n";
    cin>>n1;
    cout<<"\nIngrese otro numero\n\n";
    cin>>n2;
    if(n1>n2)
    {
        may = n1;
    }
    else if(n2>n1)
    {
        may = n2;
    }
    else
    {
        cout<<"\n\n\tSon iguales\n\n\n";
        goto fin;
    }
    cout<<"\n\n\tEl mayor es "<<may<<".\n\n\n";

    fin:
    getch();
    return 0;
}