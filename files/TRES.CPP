# include <stdio.h>;
# include <dos.h>;
# include <conio.h>;



    main()

{   textcolor(3);
    textbackground(0);
    int y=1, k,p,q,t;
    clrscr();

    gotoxy(4,1); printf("�\n");
    gotoxy(74,1);printf("�\n");
    gotoxy(4,23);printf("�\n");
    gotoxy(74,23);printf("�\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   delay(50);
   printf("�\n");
   gotoxy (k,23);printf("�\n");
  }

   for (p=2; p<=22; p++)
  {gotoxy (4,p);printf("�\n");
   gotoxy (74,p);printf("�\n");
   delay(50);
  }

{ /* recuadro interior en movimiento */
    gotoxy(14,3); printf("�\n");
    gotoxy(64,3);printf("�\n");
    gotoxy(14,13);printf("�\n");
    gotoxy(64,13);printf("�\n");

    for (k= 15; k<= 63; k ++)
  {gotoxy (k,3);
   printf("�\n");
   gotoxy (k,13);printf("�\n");
  }

   for (p=4; p<=12; p++)
  {gotoxy (14,p);printf("�\n");
   gotoxy (64,p);printf("�\n");
   }

}




 {
  textcolor (17);
  textbackground(3);
  gotoxy(25,20);printf("Press any key to continue..\n"); }
  getch();
}