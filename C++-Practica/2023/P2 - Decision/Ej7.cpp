#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
main(){
    float l1, l2, l3;
    int sino, ran, n;
    n=0;
    cout<<"\n\n\n\nIngrese la longitud de un segmento\n";
    cin>>l1;
    cout<<"Ingrese la longitud de un segundo segmento\n";
    cin>>l2;
    cout<<"Ingrese la longitud de un tercer segmento\n";
    cin>>l3;
    if ((l1+l2)>l3 && (l2+l3)>l1 && (l1+l3)>l2)
    {
        cout<<"Me alegro de informarle que sus segmentos pueden conformar un triangulo";
        b:
        cout<<"\nQuiere que conformen un triangulo?\n\n\t1. Si!\n\t2. No!\n\n\n";
        c:
        cin>>sino;
        if(sino==1)
        {   
            cout<<"\n\n\n";
            srand(time(NULL));
            ran = rand() % 5;
            switch(ran){
                case 0:
                if(l1==l2 && l1==l3){
                    cout<<"\nLos segmentos forman un triangulo perfecto\n";
                    }
                else{
                    cout<<"\nLos segmentos forman un triangulo deforme\n";
                }
                break;
                case 1:
                cout<<"\n\nUn segmento no quiere conformar un triangulo los 3 segmentos se empiezan a pelear ";
                getch();
                cout<<"\nUn segmento se parte a la mitad";
                getch();
                cout<<"\nEl segmento rebelde se rinde y acepta ser parte de un triangulo";
                getch();
                cout<<"\nLos segmentos se dan cuenta que ahora son 4";
                getch();
                cout<<"\nLos segmentos forman un cuadrilatero";
                break;
                case 2:
                cout<<"Los segmentos intentan formar un triangulo pero no lo logran";
                break;
                case 3:
                cout<<"Los segmentos forman un triangulo";
                break;
                case 4:
                cout<<"Los segmentos se ponen a discutir\n\n";
                getch();
                cout<<"\n\n";
                getch();
                cout<<"\n\n";
                getch();
                cout<<"\n\n";
                getch();
                cout<<"\nLos segmentos se enojan y cada uno se va para su lado, nunca volviendose a encontrar.\n";
                break;
                default:
                cout<<"Los segmentos se ponen a jugar al basquet";
            }
        }
        else if(sino==2)
        {
            cout<<"*Los segmentos se ponen tristes*";
        }
        else {system("CLS");n+=1;if(n==1){cout<<"\n\n\nDale loco, elegi una de las opciones\n\n\n";goto b;}
        if(n==2){cout<<"\n\n\nPorfavor, UNO o DOS\n\n\n";goto c;}
        if(n==3){cout<<"\n\n\nDale, no es tan dificil\n\n\n";goto b;}
        if(n==4){cout<<"\n\n\nUNO o DOS\n\n\n";goto c;}
        if(n==5){cout<<"\n\n\n1 o 2\n\n\n";goto c;}
        if(n==6){cout<<"\n\n\nOne or two\n\n\n";goto c;}
        if(n==7){cout<<"\n\n\nEins oder zwei\n\n\n";goto c;}
        if(n==8){cout<<"\n\n\nYa me cansaste, a partir de ahora voy a repetir el mismo mensaje hasta que te canses\n\n\n";goto b;}
        if(n>8){cout<<"\n\n\n-ERROR-\n    -Codigo de error: U5U4R10 In515T3nt3-\n\n\n";goto b;}}
    }
    else
    {
        cout<<"Lamentablemente, sus segmentos no podrán conformar un triangulo. ";
        if(l1+l2<l3){cout<<"El tercer lado es demasiado largo";}
        else if(l1+l3<l2){cout<<"El segundo lado es demasiado largo";}
        else if(l2+l3<l1){cout<<"El primer lado es demasiado largo";}
        else {cout<<"\nForman una especie de linea o algo parecido pero creo que no cuenta como triangulo.";}
        cout<<"\n\n";
    }
    
    getch();
    return 0;
}