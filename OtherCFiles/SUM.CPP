
# include "stdio.h"
# include "conio.h"
# include "stdlib.h"

void main()
{

int k,y,p;
clrscr();

   for (p=10; p<=15; p++)
  {
    gotoxy(40,10); printf("É\n");
    // gotoxy(40,16);printf("È");
    // gotoxy(55,10); printf("»\n");
    // gotoxy(55,16);printf("¼");
     gotoxy (40,p);printf("º\n");
    // gotoxy (55,p);printf("º\n");
     }
      for (p=41; p<=54; p++)
  {
     gotoxy(p,10);printf("Í\n");
     gotoxy (p,16);printf("Í\n");

    }
/*    gotoxy(42,11);
    printf("1.PREORDEN");
    gotoxy(42,13);
    printf("2.INORDEN");
    gotoxy(42,15);
    printf("3.POSTORDEN");
  */
    getch();
  
}