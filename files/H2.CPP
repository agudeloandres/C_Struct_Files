#include<stdio.h>
#include<conio.h>
void main()
{
int n,a,temp,b,i,j;
void recurcion(int n,int a,int b,int temp);
clrscr();
  for(i=1;i<=10;i++){
      gotoxy(20,15-i);
      printf("±");
      }

     gotoxy(21,i+3);
     printf(" 1");
     for(i=1;i<=10;i++){
     gotoxy(40,15-i);
     printf("±");
     }
     gotoxy(41,i+3);
     printf(" 2");

     for(i=1;i<=10;i++){
     gotoxy(60,15-i);
     printf("±");
     }
     gotoxy(61,i+3);
     printf(" 3");
     gotoxy(1,1);
printf("digite # de discos");
scanf("%d",&n);
printf("digite poste donde estan los discos");
scanf("%d",&a);
printf("digite poste donde se colocaran los discos");
scanf("%d",&b);
printf("digite poste auxiliar ");
scanf("%d",&temp);
	if(a==1){
      for(i=0;i<n;i++){
       for(j=0;j<n-i;j++){
	 gotoxy(21+i*2,13-j);
	 putchar(22);
	 gotoxy(19-i*2,13-j);
	 putchar(22);
	  }
	 }
      }
      else
     if(a==2){
      for(i=0;i<n;i++){
       for(j=0;j<n-i;j++){
	 gotoxy(41+i*2,13-j);
	 putchar(22);
	 gotoxy(39-i*2,13-j);
	 putchar(22);
	  }
	 }
      }
      if(a==3){
      for(i=0;i<n;i++){
       for(j=0;j<n-i;j++){
	 gotoxy(61+i*2,13-j);
	 putchar(22);
	 gotoxy(59-i*2,13-j);
	 putchar(22);
	  }
	 }
	 }
      

       getch();
       clrscr();

recurcion(n,a,b,temp);
getch();

}
void recurcion(n,a,b,temp)
{

if(n==1){
 printf("mover el disco 1 del poste %d al poste %d \n",a,b);
 getch();
 return;
 }
 recurcion(n-1,a,temp,b);
 printf("mover el disco %d del poste %d  al poste %d \n",n,a,b);
 getch();
 recurcion(n-1,temp,b,a);
 }
