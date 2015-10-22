#include <iostream.h>
#include <conio.h>
//Programa para ordenar vectores Metodo Seleccion

void main (){
int a[50],i,j,temp,n,menor;

clrscr();
cout << "Nro de Elementos de A :" ;
cin >> n;

for (i=1;i<=n;i++){
 cout << "A[" << i<< "]= ";
 cin>> a[i];
 }

 for ( i=1;i<=n;i++){
  menor=a[i];
  temp=i;
  for(j=i+1;j<=n;j++){
   if (menor > a[j]){
     menor =a[j];
     temp=j;
     }
    }
   a[temp]=a[i];
   a[i]=menor;
   }
   cout<<"\n";
   cout<<"Vector A ordenado \n\n";
   for ( i=1;i<=n;i++){
    cout <<"A["<< i<<"]= "<<a[i]<<" " ;
    }
   getch();
   }



