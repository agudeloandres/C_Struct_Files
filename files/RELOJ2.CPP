#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<time.h>


int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
int    ErrorCode;		/* Reports any graphics errors		*/

int longitud_h,longitud_m,longitud_s,radio=60;
int x,y;

int t1=310,t2=240,t3=310,t4=240,t5=310,t6=240;
void inimodograf(void);
void dibuja_manecilla(int h,int m,int s);


void main()
{
  inimodograf();

 while(!kbhit())
 {
  setcolor(15);
  outtextxy(310,195,"MAC");
  struct  time t;
     gettime(&t);
 /*  printf("The current time is: %2d:%02d:%02d.%02d\n",
	  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);  */
  int horas=t.ti_hour;
  int minutos=t.ti_min;
  int segundos=t.ti_sec;

  time_t Date;
  time(&Date);gotoxy(3,4);
  printf("LA FECHA DE HOY ES: %s\n", ctime(&Date));

  gotoxy(3,3);
  printf("la hora es %2d:%02d:%02d",horas,minutos,segundos);

  //clrscr();

  setcolor(2);
  circle(320,240,60);
  setcolor(9);
  line(320,300,320,290);
  line(260,240,270,240);
  line(320,180,320,190);
  line(380,240,370,240);
  dibuja_manecilla(horas,minutos,segundos);
 }
closegraph();restorecrtmode();
}

  void dibuja_manecilla(int h,int m,int s)
  {

      longitud_h=(radio*5)/10;
      longitud_m=(radio*7)/10;
      longitud_s=(radio*6)/10;

      double vhora=h+m/60.0+s/3600.0;
      setcolor(0);
      line(320,240,t5,t6);
      vhora*=(2*M_PI)/12.0;
      x=320+longitud_h*sin(vhora);
      y=240-longitud_h*cos(vhora);
      setcolor(2);
      line(320,240,x,y);
      t5=x;t6=y;


      double vminuto=m+s/60.0;
      setcolor(0);
      line(320,240,t3,t4);
      vminuto*=(2*M_PI)/60.0;
      x=320+longitud_m*sin(vminuto);
      y=240-longitud_m*cos(vminuto);
      setcolor(2);
      line(320,240,x,y);
      t3=x;t4=y;

      double vsegundo=(s*(2*M_PI))/60.0;
      setcolor(0);
      line(320,240,t1,t2);
      x=320+longitud_s*sin(vsegundo);
      y=240-longitud_s*cos(vsegundo);
      setcolor(2);
      circle(320,240,60);
      line(320,240,x,y);
      t1=x;t2=y;
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