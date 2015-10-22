#include <iostream.h>
#include <conio.h>
//Programa para ordenar vectores Metodo Burbuja

void main (){
int a[50],i,j,n1,temp,n;

clrscr();
cout << " Nro de Elementos de A : ";
cin >>n;

for (i=1;i<=n;i++){
 cout<<"A["<<i<<"]= ";
 cin>>a[i];
 }
 n1=n-1;
 for(i=1;i<=n1;i++){
  for (j=i+1;j<=n;j++){
   if (a[i]>a[j]){
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }
  }
}
cout << "\n";
cout << "Vector A ordenado \n\n";
 for(i=1;i<=n;i++){
   cout<< "A["<<i<<"]="<<a[i]<<" " ;
   }
 getch();
 }







