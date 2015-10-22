/*digite tamano de los vectores y imprimalos en un tercer vector
ordenadamente por pisicion de valores entre los dos vectores*/

#include<conio.h>
#include "stdio.h"
main()
{
clrscr();
int a[12],b[12],c[24];
int i,x,y,w,j,k;
printf("digite tama¤o de los vectores(max10)\n");
scanf("%d",&w);
	printf("VECTOR DE A:\n");
for(i=0;i<w;i++){

	printf(" elemento %d: ",i+1);
	scanf("%d",&x);
	a[i]=x;
	  }
	  printf("VECTOR DE B:\n");
for(j=0;j<w;j++){

	printf(" elemento %d: ",j+1);
	scanf("%d",&y);
	b[j]=y;
	  }
	  i=0;
	  j=0;
for(k=0;k<w*2;k++)
	if (a[i]<=b[j]){
		c[k]=a[i];
		 i++;
		 if(i>=10) a[i]=999;
		 }
	else{
		c[k]=b[j];
		j++;
		 if(j>=10) b[j]=999;
		}
getch();
for(k=0;k<w*2;k++)
printf("el nuevo es %d\n ",c[k]);
		
getch();
}