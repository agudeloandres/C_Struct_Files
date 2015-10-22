#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>


int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
int    ErrorCode;		/* Reports any graphics errors		*/

void inimodograf();
void segundero(void);
void minutero(void);

void main()
{
   clrscr();
   inimodograf();
   minutero();

}

 void minutero(void)
 {
    int x;

    for(x=87;x>=84;x-=3)
   {
   segundero();
   setcolor(5);
   pieslice(320,240,90,x,30);
   getch();
   }
}


 void segundero(void)
 {
   int x;

   setcolor(2);
   circle(320,240,60);
   line(370,240,380,240);
   line(320,290,320,300);
   line(260,240,270,240);
   setfillstyle(7,0);

   for(x=90;x>=0;x-=3)
   {
   setcolor(2);
   pieslice(320,240,90,x,60);
   setcolor(0);
   line(320,240,320,190);
   delay(100);
   }

   setfillstyle(7,0);
   for(x=360;x>=90;x-=3)
   {
   setcolor(2);
   pieslice(320,240,359,x,60);
   line(320,290,320,300);
   line(260,240,270,240);
   setcolor(0);
   line(320,240,380,242);
   line(320,240,370,240);
   line(320,240,320,190);
   delay(100);
   }
   setcolor(2);
   line(320,240,320,190);
 }







void inimodograf(void)
{

  GraphDriver = DETECT; 		/* Request auto-detection	*/
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();		/* Read result of initialization*/
  if( ErrorCode != grOk ){		/* Error occured during init	*/
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}