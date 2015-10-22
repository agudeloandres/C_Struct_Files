#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void mount (void);
int triangle[]={190,400,370,200,540,400};
main()
{
   unsigned int size1,c=0,x1=244,y1=148;
   void *car2;
   int pol[]={244,148,304,148,304,173,344,173,344,203,244,203};


   void *car;
   unsigned int size;
   int controlador_grafico = 0, modo_grafico;
   int i,x=40,y=400,poly[]={40,400,140,400,140,370,100,370,100,345,40,345,40,400};

   /* initialize graphics mode */
   initgraph(&controlador_grafico, &modo_grafico, "");


   setbkcolor(WHITE);
   setfillstyle(1,BLUE);
   setcolor(BLUE);
   //drawpoly(8,poly);
   fillpoly(7,poly);
   setcolor(BLUE);
   setfillstyle(1,GREEN);
   fillellipse(48,400,15,15);
   fillellipse(132,400,15,15);
   size = imagesize(39,344,141,401);
   car=malloc(size);
   getimage(33,344,147,415,car);
   for (;c<=50;c++){
   cleardevice();
   mount();
   putimage(x,y,car,1);   //SUBIDA
   x+=4;
   y-=5;
   delay(50);
   }
   getch();
   //******************

   cleardevice();
   mount();
   setbkcolor(WHITE);
   setfillstyle(1,BLUE);
   setcolor(BLUE);
   fillpoly(6,pol);
   setcolor(BLUE);
   setfillstyle(1,GREEN);
   fillellipse(253,200,15,15);
   fillellipse(337,200,15,15);
   size1=imagesize(235,144,355,215);
   car2=malloc(size1);
   getimage(235,144,355,215,car2);
   for (;c<=50;c++){
   cleardevice();
   mount();
   x1+=3;
   y1+=4;
   putimage(x1,y1,car2,1);
   delay(50);
   }
   free(car2);






   getch();
   //closegraph();
}

void mount (void){
   setfillstyle(1,BROWN);
   setcolor(RED);
   fillpoly(3,triangle);
   }