# include "stdio.h"
# include "conio.h"
# include "a:\factoria.h"

void main()
{
int vect[100],a,b,i,n;
float suma=0;
clrscr();
printf(" digite tama¤o del vector\n ");
scanf("%d",&n);
printf(" digite elementos del vector\n\n");
for(i=0;i<n;i++){
//   do{
   scanf("%d",&vect[i]);
 //  }while(i>0 && i<5);
     suma+=vect[i];
     }
  for(i=0;i<=n;i++){
  a=vect[i];
 printf("el factorial %d ",factorial(a));


 }

  for(i=0;i<=n;i++){
  a=vect[i];
  b=vect[i+1]
 printf("el producto %d ",factorial(a));

  printf("La sumatoria es  %f ",suma);
 getch();

}
