#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <iostream.h>
int mcd(int, int);

	 //    RECURSIVIDAD    //
void main()
{
 clrscr();

     do{
     gotoxy(5,10);
     printf(" \\");
     delay(100);
     gotoxy(4,10);
     printf("%c |");
     delay(100);
     gotoxy(5,10);
     printf("%c/ ");
     delay(100);
     gotoxy(5,10);
     printf("%c--");
     delay(100);
     gotoxy(5,10);
     printf(" \\");
     gotoxy(5,10);
     printf("%c |");
     delay(100);
     gotoxy(5,10);
     printf("%c/ ");
     delay(100);
     gotoxy(5,10);
     printf("%c--");
     delay(100);
     gotoxy(5,10);
     printf(" \\");
     delay(100);
    // printf("%c |");
     gotoxy(5,10);
     printf("%c/ ");
   }while(getch()!=EOF);

}