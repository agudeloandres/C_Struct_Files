#include   <stdio.h>
#include   <dos.h>
#include   <conio.h>
#include   <stdlib.h>

 main(void)
{


   int c;
   while (!kbhit()){
   struct  time hora;

   gettime(&hora);
   //if(t.ti_hour > 12)
     //  c=t.ti_hour-12;
   //clrscr();
   textbackground(BLUE);
   textcolor(WHITE);
   gotoxy(20,12);
   //clreol();
   printf("La hora del sistema es : %2d:%02d:%02d.%02d",
	 hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);
  //delay(30);


 }
 getch();
}
