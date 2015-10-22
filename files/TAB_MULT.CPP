#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
main (){
int i=1,a=1,r;
clrscr();
  while (i<=10){
   r=a*i,
   printf("\n%d x %d = %d",a,i,r);
   i++;
   if (i>10 && a<10){
   a++;i=1;
   printf("\n\n");
   getch();
   }
  }
getch();
}