#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
# include <dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int t,i,k,numeros;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }



   outtextxy(116,60,"[1] *.bak");
   outtextxy(116,80,"[2] *.obj");
   outtextxy(116,100,"[3] *.exe [No recomendable]");
   outtextxy(116,120,"[4]  Todo [denegado ]");
   outtextxy(116,140,"Sin una opcion definida se hara el Default.");
   outtextxy(116,165,"Opcion ? [   ]");
   gotoxy(26,11);scanf("%d",&numeros);

   delay(700);
  cleardevice();

   for (t=1;t<=13;t++) {
   setcolor(t);
    outtextxy(150,20,"Escaneando la Unidad, tenga paciencia!");
    delay(60);
    }

    /* draw the 3-d bar */
      bar3d(100, 100, 400,140, 10, 1);

   /* loop through the fill patterns */
   k=0;
   for (i=100; i<=401; i++)
   {

      /* set the fill style */
      setfillstyle(1, BLUE);
      /* draw the bar */
    bar(100, 100, i,140);
    gotoxy (35,10);printf("%d%",k);
    k=(400-i);
    delay(10);
      }


   switch (numeros)  {

   case 1:
	system("dir *.bak");
	system("del *.bak");
	delay(700);
	break;

    case 2:
	system("dir *.obj");
	system("del *.obj");
	delay(700);
	break;

     case 3:
	system("dir *.exe");
	system("rename elimina.exe elimina.ira");
	system("del *.bak");
	system("rename elimina.ira elimina.exe");
	delay(700);
	break;

    case 4:
	system("dir *.*");
       gotoxy(25,25);printf("Esta funcion no esta activada, te jodes!");
	delay(900);
     //	system("del *.bak");
	break;

     default:
	gotoxy(25,25);printf("No es una opcion valida!");
	 delay(900);
    }



    cleardevice();
    settextstyle(5,0,4);
    for (t=1;t<=13;t++) {
    setcolor(t);
    outtextxy(150,20,"Unidad limpiada con exito!");
    delay(60);
    }
    settextstyle(8,0,3);
    for (t=1;t<=13;t++) {
    setcolor(t);
    outtextxy(150,300,"Presione una tecla para finalizar!");
    delay(60);
    }

    getch();
   /* clean up */
   closegraph();
   return 0;
}

