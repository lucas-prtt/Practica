 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 using namespace std;


main(){
    FILE * archivo=fopen("texto2.bin","r");
    char n[50], q[50];
    fread(n, sizeof(n), 1, archivo);
    fread(q, sizeof(q), 1, archivo);
    cout<<n;
    cout<<q;
    getch();
    return 0;
}
