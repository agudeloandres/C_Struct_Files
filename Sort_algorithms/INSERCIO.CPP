#include <iostream.h>
#include <conio.h>
//Programa para ordenar vectores Metodo Insercion
void main (){
int a[50],i,j,temp,n,menor;

clrscr();
cout <<"Nro de Elementos de A : " ;
cin >> n;
for (i=1;i<=n;i++){
 cout << " A [" << i<< "]=";
 cin >> a[i];
 }

 for ( i=2;i<=n;i++){
  j=i-1;
  menor=a[i];
  while (menor < a[j] && j>0){
   a[j+1] = a[j];
   j=j-1;
   }
   a[j+1]=menor;
   }
   cout << "\n";
   cout << " Vector A ordenado \n\n";
   for ( i=1;i<=n;i++){
    cout << "A["<<i<<"]= "<<a[i]<<" ";
    }
    getch();
    }


