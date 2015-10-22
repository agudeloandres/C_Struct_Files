#include <iostream.h>
#include <conio.h>
//Programa para ordenar vectores Metodo burbuja Mejorada

void main(){


int a[50],i,j,temp,n1,n;
unsigned int sw;
clrscr();
cout <<"Nro de Elementos de A :";
cin>> n;
for (i=1;i<=n;i++){
 cout<< "A ["<<i<<"]= ";
 cin >> a[i];
 }
 sw=0;
 n1=n-1;
 while (sw==0){
 j=2;
 sw=1;
 for (i=1;i<=n1;i++){
  if (a[i]>a[j]){
   temp = a[i];
   a[i]=a[j];
   a[j]=temp;
 sw=0;
 }
j++;
}
n1=n1-1;
}
cout<<"\n";
cout<<"Vector A ordenado\n\n";
for (i=1;i<=n;i++){
 cout << "A [" <<i<<"] = "<<a[i]<< " " ;
 }
 getch();
 }



