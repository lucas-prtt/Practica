#include <iostream>
#include <conio.h>
using namespace std;
main(){
    unsigned long long int n, i;
    cout<<"Ingrese hasta que numero decirle los primos y por cual numero empezar: \n\n";
    cin>>n>>i;
    bool primo;
    
    for (i; i<n; i++){
        primo=true;
        for(int q=2;primo and q<i/2; q++){
            if(i%q==0){primo=false;}
        }
        if (primo){
            cout<<i<<" - ";
        }
    }
    getch();
    return 0;
}