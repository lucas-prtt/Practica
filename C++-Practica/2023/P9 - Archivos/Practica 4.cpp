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
    abc str[5];
    for(int i=0; i<5; i++){
    cin>>str[i].a>>str[i].b>>str[i].c;
}
    fwrite(&str, sizeof(abc), 5, archivo);

    getch();
    return 0;
}
