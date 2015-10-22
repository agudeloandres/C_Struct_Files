#include <stdio.h>
#include <conio.h>
#include <dos.h>
main ()
{
int max,min,x,cm,cn,cnn,cnm,g,t;

textcolor(4);
textbackground(11);
clrscr();
for (t=1;t<=30;t++){
gotoxy(t,1);printf(" PROGRAMA DE MIN Y MAX");
delay(100);
}
gotoxy(1,3);   printf("DIGITE LA CANTIDAD MAXIMA (MAX.) (POSITIVA) \n");
scanf("%d",&max);
printf("DIGITE LA CANTIDAD MINIMA (MIN.) (POSITIVA) \n");
scanf("%d",&min);
printf("DIGITE CUALQUIER CANTIDAD DE NUMEROS O PRESIONE -1 PARA SALIR \n");
cm=0;cn=0;cnn=0;cnm=0;
//for (x=
while (x!=-1) {
scanf("%d",&x);
if (x>max)
cm++;
if (x<min)
cn++;

if (x>=min && x<=max)
cnn++;


}            

//g=cnn+cnm;

printf ("NUMEROS MAYORES QUE MAX. HAY : %d\n",cm);
printf("NUMEROS MENORES QUE MIN. HAY : %d\n",cn);
printf("NUMEROS ENTRE MIN. Y MAX. HAY : %d\n",cnn);
getch();
}