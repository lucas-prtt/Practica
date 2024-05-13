#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
main()
{   char a[50], b[50], c[50];
    cin.getline(a, 49);
    fflush(stdin);
    cin.getline(b, 49);
    fflush(stdin);

    cout<<"\n1: "<<a;
    cout<<"\n2: "<<b;
    
    cout<<"\n\nstrcmp: "<<strcmp(a, b)<<"\n";
    strcpy(c, a);
    cout<<"\n\nstrcat: "<<strcat(c, b)<<"\n";
    getch();
    return 0;
}
