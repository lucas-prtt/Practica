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
    strcat(nombre, ".bin");                          
    FILE * archivo=fopen(nombre,"r");
    if(archivo==NULL){
        cout<<"Error, "<<nombre<<" no existe.";
        getch();
        return 0;
    }
    abc nnn;
    for(int i=0; i<5; i++){
    fread(&nnn, sizeof(nnn), 1, archivo);
    cout<<nnn.a<<"---"<<nnn.b<<"---"<<nnn.c<<"\n";
    }
    getch();
    return 0;
}
