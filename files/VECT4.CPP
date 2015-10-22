#include <stdio.h>
#include <conio.h>

main(){
int a [50];int b[50];int c[50]={0},x,k,j,t;
clrscr();
printf("TAMA¥O DEL VECTOR A Y B\n");
scanf("%d",&t);

printf("DIGITE LOS ELEMENTOS DE A \n");
for (x=0;x<=(t-1);x++)
scanf("%d",&a[x]);
printf("DIGITE LOS ELEMENTOS DE B \n");
for (k=0;k<=(t-1);k++)
scanf("%d",&b[k]);

printf("\n EL VECTOR SUMA ES : \n");
for (j=0;j<=(t-1);j++){
c[j]=a[j]+b[j];
printf("  %d",c[j]);
}







getch();
}