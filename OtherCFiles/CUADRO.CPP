//# include <c:librery.h>
#include<stdio.h>
#include <conio.h>

main()
{
clrscr();
textbackground(1);
    int k,y,p;

     gotoxy(20,1); printf("É\n");
     gotoxy(60,1);printf("»\n");
     gotoxy(20,3);printf("È\n");
     gotoxy(60,3);printf("¼\n");
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");

//CUADRITO DONDE ESTA EL TITULO

    for (k=21; k<= 59; k ++){
   gotoxy (k,y);
   gotoxy(21,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy (20,2);printf("º\n");
   gotoxy (60,2);printf("º\n");

    }


   for (p=6; p<=20; p++)
  {
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");
     gotoxy (15,p);printf("º\n");
     gotoxy (65,p);printf("º\n");
     }
      for (p=16; p<=64; p++)
  {
     gotoxy(p,6);printf("Í\n");
     gotoxy (p,21);printf("Í\n");

    }    
    getch();




}