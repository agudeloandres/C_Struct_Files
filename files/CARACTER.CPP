#include <stdio.h>
#include <conio.h>
#include <dos.h>

main()
{
  int y=1, k,p,q,t;


 textcolor(9);
 textbackground(0);
 clrscr();

     gotoxy(4,1); printf("�");
     gotoxy(74,1);printf("�");
     gotoxy(4,23);printf("�");
     gotoxy(74,23);printf("�");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   delay(20);
   printf("�\n");
   gotoxy (k,23);printf("�\n");
  }

   for (p=2; p<=22; p++)
  {gotoxy (4,p);printf("�\n");
   gotoxy (74,p);printf("�\n");
   delay(20);
  }


  textcolor(0);
  gotoxy(27,10);printf("C A R L O S  A N D R E S \n");
  delay(700);

   for (p=27;p>=10;p--)
  {gotoxy(p,10);printf("������� �I N P U T? �������    \n");
   delay(100);
   }

   for (p=10;p<=42;p++)
  {gotoxy(p,10);printf("   ������� <I N P U T> �������  \n");
   delay(100);
   }

  for (p=42;p >=27;p--)
  {gotoxy(p,10);printf("������� *I N P U T* �������    \n");
   delay(100);
  }
   for (p=10;p<=15;p++)
  {gotoxy(27,p-1);printf("                             \n");
   gotoxy(27,p);printf("������� �I N P U T? �������    \n");
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
