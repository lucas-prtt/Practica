 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 using namespace std;


main(){
    /*char str1[50];
    string str2;
    //getline(cin, str1);
    getline(cin, str2);
    cin.getline(str1, sizeof(str1));
    */FILE * archivo=fopen("texto.txt","w");
    /*cout<<str1<<"\t"<<str2;
    fputs(str1, archivo);*/
    //printf("%s", str2);
    char n[50];
    cin.getline(n, sizeof(n));
    fprintf(archivo, "el numero %s es un numero", n);
    getch();
    return 0;
}
