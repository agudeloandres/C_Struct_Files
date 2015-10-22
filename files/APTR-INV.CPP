#include <stdio.h>    //PROGRAMA QUE INVIERTE UN VECTOR UTILIZANDO
#include <conio.h>    //APUNTADORES
void main (){
clrscr();
int a[5]={1,2,3,4,5},k,c,t,*aptr1,*aptr2;

printf("El vector es :\n");
for(t=0;t<=4;t++)
 printf("\t%d",a[t]);

aptr1=&a[0];      //Un apuntador que apunte al inicio del vector
aptr2=&a[4];     //Un apuntador que apunte al final del vector

for (k=0;k<=4;k++)
 aptr2[4-k]=aptr1[k];

printf("\n\nEl vector invertido queda : \n");

for (c=0;c<=4;c++)
 printf("\t%d",aptr2[c]); //Es equivalente a : *(aptr2+c)

 getch();
 }