#include<stdio.h>
#include<conio.h>
#include "dos.h"
void main()
{
int n,a,temp,b,i,j;
void HANOI(int n,int a,int b,int temp);
textbackground(11);
textcolor(RED);
clrscr();
    a=1;
    b=3;
    temp=2;
    for(i=1;i<=10;i++){
      gotoxy(20,15-i);
      printf("±");
      }

     gotoxy(21,i+3);
     printf(" 1 (PRINCIPAL)");
     for(i=1;i<=10;i++){
     gotoxy(40,15-i);
     printf("±");
     }
     gotoxy(41,i+3);
     printf(" 2 (AUXILIAR)");

     for(i=1;i<=10;i++){
     gotoxy(60,15-i);
     printf("±");
     }
     gotoxy(61,i+3);
     printf(" 3 (DESTINO)");
     gotoxy(1,1);
printf("DIGITE NUMERO DE DISCOS A MOVER :  ");
scanf("%d",&n);
      for(i=0;i<n;i++){
       for(j=0;j<n-i;j++){
	 gotoxy(21+i*2,13-j);
	 putchar(22);
	 gotoxy(19-i*2,13-j);
	 putchar(22);

	 }
      }



       getch();
       clrscr();

HANOI(n,a,b,temp);
getch();

}
void HANOI(n,a,b,temp)
{

if(n==1){
 printf("mover el disco 1  del poste %d al poste %d \n",a,b);
 return;
 }
 HANOI(n-1,a,temp,b);
 printf("mover el disco %d del poste %d al poste %d \n",n,a,b);
 HANOI(n-1,temp,b,a);
 }
