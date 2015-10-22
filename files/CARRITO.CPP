
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(void)
{
   void *pnt=NULL;
   unsigned int size;
   int c,f,x1,x2,y1,y2;

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int maxx, maxy;

   /* our polygon array */
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   line(100,440,130,420); //line carro  aba
   line(96,430,126,410);

   line(100,440,96,430); //linea une
   line(130,420,126,410);

   line(92,420,100,414);
   line(92,420,100,440);
   line(100,414,105,425);

   circle(104,441,2);
   circle(127,426,2);

  /* setcolor(0);
   bar(0,0,640,480);*/
   size =  imagesize(90,410,150,445);
   pnt = malloc(size);

   getimage(90,410,150,445,pnt);
   getch();
//   putimage(400,10,pnt,XOR_PUT);
   f = 420;
   c= 80;

   while (c<= 200 && f >=150  )
   {
     setcolor(0);
     bar(0,0,640,480);
     putimage(c,f,pnt,XOR_PUT);
     line(119,435,220,347);
     line(218,345,326,443); //220 325
     line(327,444,640,444);
    // setbkcolor(0);
     c+=5; f-=5;
    delay(50);
   }

    setcolor(0);
   bar(0,0,640,480);

   line(232,315,260,332); //line carro  aba
   line(238,305,266,321);

   line(232,315,238,305); //linea une
   line(260,332,266,321);

   line(244,297,253,301); //linea arri  // 260,303
   line(238,305,244,297);//une aba
   line(253,301,247,310);

   circle(236,320,2);
   circle(252,330 ,2);
   setcolor(0);
   bar(90,415,135,442);

/*----------------------------------------------------------------*/
//    setcolor(0);
    size =  imagesize(230,290,265,335);  //
    pnt = malloc(size);

   getimage(230,290,265,335,pnt);
//   getch();
  /* f = 420;
   c= 80;*/


   while (c<=400 && f<= 400)
     {
     setcolor(0);
     bar(0,0,640,480);
     putimage(c,f,pnt,3); //XOR_PUT);
     line(111,435,220,345);
     line(215,345,326,443); // 220 325
     line(327,444,640,444);
    // setbkcolor(0);
     c+=5; f+=5;
     delay(50);
      }




   free(pnt);
   getch();
   closegraph();
   return 0;
}


