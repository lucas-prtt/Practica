 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 #include <string.h>
 using namespace std;

struct abc{
    int a;
    int b;
    int c;
};
main(){
    char nombre[50];
    cin.getline(nombre, sizeof(nombre));
    FILE * archivo=fopen(strcat(nombre, ".bin"),"w");
    abc str;
    cin>>str.a>>str.b>>str.c;

    fwrite(&str, sizeof(str), 1, archivo);

    getch();
    return 0;
}
