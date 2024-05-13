 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 using namespace std;


main(){
    FILE * archivo=fopen("texto2.bin","w");
    char n[50], q[50];
    cin.getline(n, sizeof(n));
    cin.getline(q, sizeof(q));
    fwrite(n, sizeof(n), 1, archivo);
    fwrite(q, sizeof(q), 1, archivo);
    getch();
    return 0;
}
