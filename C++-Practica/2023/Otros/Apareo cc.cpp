#include <iostream>
#include <conio.h>

using namespace std;
void apareo(int[], int[], int, int);
main(){
    int vector1[13]={8, 23, 41, 55, 56, 59, 70, 89, 99, 102, 542, 554, 987};
    int vector2[10]={1, 8, 35, 85, 85, 89, 99, 100, 101, 102};
    apareo(vector1, vector2, 13, 10);

    getch();
    return 0;
}



void apareo(int v1[], int v2[], int t1, int t2){
    int pos1=0, pos2=0;

    while(pos1<t1 and pos2<t2){
        if(v1[pos1]==v2[pos2])
        {
            cout<<v1[pos1]<<" - ";
            pos1++;
            pos2++;
        }else if(v1[pos1]<v2[pos2])
        {
            cout<<v1[pos1]<<" - ";
            pos1++;
        }
        else
        {
            cout<<v2[pos2]<<" - ";
            pos2++;
        }
        }
    
    for (int i=pos1; i<t1; i++){
        cout<<v1[i]<<" - ";
    }
    for (int i=pos2; i<t2; i++){
        cout<<v2[i]<<" - ";
    }
}