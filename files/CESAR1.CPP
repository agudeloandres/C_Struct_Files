#include <stdio.h>
#include <conio.h>
# include <dos.h>

main()
{
  int k,p,q,t,numero,otro;


 textcolor(9);

textbackground(0);
 clrscr();

     gotoxy(4,1); printf("�\n");
     gotoxy(4,3);printf("�\n");
      gotoxy(64,3);printf("�\n");
      gotoxy(64,1);printf("�\n");


   for (k= 5; k<= 63; k ++)
  {gotoxy (k,1);
   delay(50);
   printf("�\n");
   gotoxy (k,3);printf("�\n");
}

   for (p=2; p<=2; p++)
  {gotoxy (4,p);printf("�\n");
   gotoxy (7,p);printf("�\n");
  gotoxy (10,p);printf("�\n");
  gotoxy (13,p);printf("�\n");
  gotoxy (16,p);printf("�\n");
  gotoxy (19,p);printf("�\n");
  gotoxy (22,p);printf("�\n");
  gotoxy (25,p);printf("�\n");
  gotoxy (28,p);printf("�\n");
  gotoxy (31,p);printf("�\n");
  gotoxy (34,p);printf("�\n");
  gotoxy (37,p);printf("�\n");
  gotoxy (40,p);printf("�\n");
  gotoxy (43,p);printf("�\n");
  gotoxy (46,p);printf("�\n");
  gotoxy (49,p);printf("�\n");
  gotoxy (52,p);printf("�\n");
  gotoxy (55,p);printf("�\n");
  gotoxy (58,p);printf("�\n");
  gotoxy (61,p);printf("�\n");
  gotoxy (64,p);printf("�\n");
 }


     for (k= 7; k<= 61; k +=3)
  {gotoxy (k,1);

   printf("�\n");
   gotoxy (k,3);printf("�\n");
}


for (t=6;t<=63;t+=3){
  gotoxy(t,2);scanf("%d",&numero);
  gotoxy(t,4);scanf("%d",&otro);
  }





  getch();
 }