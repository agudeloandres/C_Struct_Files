#include <stdio.h>
#include <conio.h>          //METODO DE ORDENAMIENTO *BURBUJA*

void main(){
int a [ ]={8,7,6,5,2,9,3,1,8,9};
int i=0,j=0,temp,k;
clrscr();
for (i=0;i<=8;i++){
 for (j=i+1;j<=9;j++){
  if (a[i]>a[j])
    {
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
     }


    }

  }
   for (k=0;k<10;k++){
    printf("\t%d",a[k]);
    }
   getch();
  }