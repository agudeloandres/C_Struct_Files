#include <stdio.h>
#include <conio.h>
#include <dos.h>

main()
{
  int y=1, k,p,q,t;


 textcolor(9);
 textbackground(0);
 clrscr();

     gotoxy(4,1); printf("Щ");
     gotoxy(74,1);printf("Л");
     gotoxy(4,23);printf("Ш");
     gotoxy(74,23);printf("М");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   delay(20);
   printf("Э\n");
   gotoxy (k,23);printf("Э\n");
  }

   for (p=2; p<=22; p++)
  {gotoxy (4,p);printf("К\n");
   gotoxy (74,p);printf("К\n");
   delay(20);
  }


  textcolor(0);
  gotoxy(27,10);printf("C A R L O S  A N D R E S \n");
  delay(700);

   for (p=27;p>=10;p--)
  {gotoxy(p,10);printf("ллллллл ЈI N P U T? ллллллл    \n");
   delay(100);
   }

   for (p=10;p<=42;p++)
  {gotoxy(p,10);printf("   ллллллл <I N P U T> ллллллл  \n");
   delay(100);
   }

  for (p=42;p >=27;p--)
  {gotoxy(p,10);printf("ллллллл *I N P U T* ллллллл    \n");
   delay(100);
  }
   for (p=10;p<=15;p++)
  {gotoxy(27,p-1);printf("                             \n");
   gotoxy(27,p);printf("ллллллл ЈI N P U T? ллллллл    \n");
   delay(50);
   }

    char * pc = "C A R L O S  A N D R E S";
   textbackground (7);
   for (t=24;t>=0;t--)
   {gotoxy(29,7);printf ("%s\n",&pc[t]);    //Equivalente a pc+t
   delay(70);
   }

  getch();
  }
