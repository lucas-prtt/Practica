#include <iostream>
#include <conio.h>

using namespace std;
void sort(int[], int longitud_del_array); //Ordena array

main(){
int q = 10, array[10]={15, 16, 66, 1, 98, 64, 107, 11, 32, 4};
sort(array, q);
cout<<"\n";
for(int i=0; i<q; i++)
    {
    cout<<array[i];
    if (i<q-1)
    cout<<" --- ";
    }
getch();
return 0;
}

void sort(int array[], int q){
int temp=0;
for(int i=0; i<q; i++)
{
    int pos_min=i;
    for(int k=i; k<q; k++)
    {  
        if (array[k]<array[pos_min])
        pos_min=k;
    }
    temp = array[i];
    array[i]=array[pos_min];
    array[pos_min]= temp;
}

}