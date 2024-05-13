#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

string returnstring();
void returnchar(char a[]);
main(){
    char a[20];
    cout<<returnstring();
    returnchar(a);
    cout<<a;
    getch();
    return 0;
}
string returnstring(){
    string s = "Palabras a devolver\n";
    return s;
}
void returnchar(char a[]){
    strcpy(a, "Palabras a devolver 2\n");
    return;
}