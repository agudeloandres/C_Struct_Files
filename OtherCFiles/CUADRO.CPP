//# include <c:librery.h>
#include<stdio.h>
#include <conio.h>

main()
{
clrscr();
textbackground(1);
    int k,y,p;

     gotoxy(20,1); printf("�\n");
     gotoxy(60,1);printf("�\n");
     gotoxy(20,3);printf("�\n");
     gotoxy(60,3);printf("�\n");
     gotoxy(15,6); printf("�\n");
     gotoxy(65,6);printf("�\n");
     gotoxy(15,21);printf("�\n");
     gotoxy(65,21);printf("�\n");

//CUADRITO DONDE ESTA EL TITULO

    for (k=21; k<= 59; k ++){
   gotoxy (k,y);
   gotoxy(21,1);printf("�\n");
   gotoxy (k,3);printf("�\n");
   gotoxy(k,1);printf("�\n");
   gotoxy (k,3);printf("�\n");
   gotoxy (20,2);printf("�\n");
   gotoxy (60,2);printf("�\n");

    }


   for (p=6; p<=20; p++)
  {
     gotoxy(15,6); printf("�\n");
     gotoxy(65,6);printf("�\n");
     gotoxy(15,21);printf("�\n");
     gotoxy(65,21);printf("�\n");
     gotoxy (15,p);printf("�\n");
     gotoxy (65,p);printf("�\n");
     }
      for (p=16; p<=64; p++)
  {
     gotoxy(p,6);printf("�\n");
     gotoxy (p,21);printf("�\n");

    }    
    getch();




}