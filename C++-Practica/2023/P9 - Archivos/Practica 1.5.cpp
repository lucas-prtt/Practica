 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 using namespace std;


main(){
    FILE * archivo=fopen("texto.txt","r");
    char n[50];
    fread(n, sizeof(n), 1, archivo);
    cout<<"\nInicio-"<<n<<"-Fin\n";
    getch();
    return 0;
}
