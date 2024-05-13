#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

long long int sumarhoras(long long int, long long int);

int main(){
    long long int tiempo1;
    long long int tiempo2;
    cin>>tiempo1;
    cin>>tiempo2;
    cout<<sumarhoras(tiempo1, tiempo2);
    getch();
    return 0;
    }

long long int sumarhoras(long long int tiempo1, long long int tiempo2){
int sec1, sec2;
int min1, min2;
int hora1, hora2;
int rsec, rmin, rhora;
int dia = 0;

sec1 = tiempo1%100;
min1 = tiempo1%10000-sec1;
hora1 = tiempo1%1000000-sec1-min1;
sec2 = tiempo2%100;
min2 = tiempo2%10000-sec2;
hora2 = tiempo2%1000000-sec2-min2;
//cout<<" "<<sec1<<" "<<min1<<" "<<hora1<<" "<<sec2<<" "<<min2<<" "<<hora2;
rsec=sec1 + sec2;
if(rsec>=60) 
{rsec-=60;
min1+=100;}

rmin=min1 + min2;
if(rmin>=6000) 
{rmin-=6000;
hora1+=10000;}

rhora=hora1 + hora2;
if(rhora>=240000)
{rhora-=240000;
    dia+=1;}
return dia*1000000+rhora+rmin+rsec;
}