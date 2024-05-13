#include <iostream>
#include <conio.h>

using namespace std;
main(){
    int n, m;
    int suma=0;
    do{
        cout<<"Ingrese la cantidad de columnas: ";
        cin>>n;
        cout<<"Ingrese la cantidad de filas: ";
        cin>>m;
    }while(n>30 or n<0 or m>30 or m<0);
    int matriz[m][n];
    int sumafila[n];
    int maxcolumna[m];
    int max=0;
    for(int i=0; i<m; i++)
    {  
        for(int q=0; q<n; q++)
        {
            
            cout<<"Ingrese el elemento ("<<i+1<<";"<<q+1<<"): ";
            cin>>matriz[i][q];
        }
    }
    cout<<"\n\n\nLa matriz quedó así:\n\n";
    for(int i=0; i<m; i++)
    {   sumafila[i]=0;
        for(int q=0; q<n; q++)

        {   sumafila[i]+=matriz[i][q];
            cout<<matriz[i][q]<<"\t";
            suma+=matriz[i][q];
        }
        cout<<"\n";
    }
    for(int q=0; q<n; q++){
        maxcolumna[q]=matriz[0][q];
        for(int i=0; i<m; i++){
            if(matriz[i][q]>maxcolumna[q]){
                maxcolumna[q]=matriz[i][q];
            }
        }
    }
    cout<<"\n\n\n";
    for(int i=0; i<m; i++){cout<<sumafila[i]<<"\t";}
    cout<<"\n\n\n";
    for(int i=0; i<n; i++){cout<<maxcolumna[i]<<"\t";}
    cout<<"\n\nPromedio = "<<suma/(n*m);
    getch();
    return 0;
}