#include <iostream>
#include <conio.h>
using namespace std;
main(){
    FILE * arch = fopen("Creditos.dat","r");
    cout<<arch;
    int ab;
    cout<<"\nInput: ";
    cin>>ab;
    cout<<"\n\nHola mundo\n\n"<<ab<<ab<<ab;
    getch();
    return 0;
}
