#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"graphics.h"
#include<dos.h>
#include<string.h>
int f,p;
char V[4],S[4],N[4];

main()
{
 void PicasFijas(void);
 void Windows(int,int,int,int);
 void Boton(int,int,int,int,int,int,int,int);
 void Present(void);
 void Out(void);

 int control,modo,i,j,intento=0,M;
 char Aux[30],K;
 control=DETECT;
 initgraph(&control,&modo,"F:\BGI");
 Present();
 for(;;)
 {
  Windows(200,130,410,260);
  setcolor(11);
  settextstyle(1,0,3);
  outtextxy(240,160,"JUGAR.....[1]");
  outtextxy(240,190,"SALIR.......[2]");
  do{
  outtextxy(30,311,"DIGITE OPCION DESEADA [  ]");
  gotoxy(42,21);
  scanf("%c",&K);
  }while(K!='1' && K!='2');
  if(K=='1' || K=='2'){
  clearviewport();
  switch(K)
   {
    case '1':
    settextstyle(0,0,1);
    setfillstyle(1,7);
    bar(0,0,639,479);
    Windows(5,45,635,475);
    Boton(28,5,633,22,8,15,7,2);
    Boton(28,25,477,42,8,15,7,2);
    Boton(450,25,550,42,7,8,15,2);
    Boton(533,25,633,42,7,8,15,2);
    Boton(7,5,25,22,8,15,7,2);
    Boton(7,25,25,42,8,15,7,2);
    Windows(48,30,59,38);
    setcolor(8);
    outtextxy(270,13,"JEDSOFT");
    setcolor(15);
    outtextxy(268,11,"JEDSOFT");
    setcolor(1);
    outtextxy(269,12,"JEDSOFT");
    setcolor(0);
    settextstyle(2,0,4);
    setcolor(9);
    outtextxy(458,30,"Point:");
    outtextxy(540,30,"Level:");
    settextstyle(10,0,2);
    setcolor(15);
    outtextxy(34,55,"PICAS Y FIJAS ");
    setfillstyle(1,7);
    bar(280,100,380,120);
    settextstyle(0,0,1);
    setcolor(15);
    outtextxy(288,107,"PICAS FIJAS ");
    for(i=0;i<12;i++)
       line(280,100+i*20,380,100+i*20);
    for(i=0;i<3;i++)
       line(280+i*50,100,280+i*50,320);
    randomize();
    do{
       sprintf(N,"%s","");
       for(i=0;i<4;i++)
       {
	sprintf(S,"%d",random(9)+1);
	strcat(N,S);
       }
      }
      while((N[0] == N[1]) || (N[0] == N[2]) || (N[0] == N[3]) ||
	    (N[1] == N[2]) || (N[1] == N[3]) || (N[2] == N[3]));
       for(intento=1;intento<=10;intento++){
       sprintf(Aux,"%d",intento);
       outtextxy(30,107+intento*20,Aux);
       outtextxy(40,107+intento*20,". INTRODUZCA EL NUMERO:");
       do{
	  for(i=0;i<4;i++)
	   {
	    V[i]=getch();
	    sprintf(Aux,"%c",V[i]);
	    outtextxy(230+i*8,107+intento*20,Aux);
	   }
	  if((V[0] == V[1]) || (V[0] == V[2]) || (V[0] == V[3]) ||
	     (V[1] == V[2]) || (V[1] == V[3]) || (V[2] == V[3]))
	   {
	    setfillstyle(1,BLUE);
	    bar(230,107+intento*20,270,115+intento*20);
	    sound((2200*1)/2);
	    delay(300);
	    nosound();
	    outtextxy(395,107+intento*20,"NO DIGITE NUMEROS IGUALES");
	   }
	  delay(500);
	  setfillstyle(1,BLUE);
	  bar(395,107+intento*20,600,115+intento*20);
	 }
	  while((V[0] == V[1]) || (V[0] == V[2]) || (V[0] == V[3]) ||
		(V[1] == V[2]) || (V[1] == V[3]) || (V[2] == V[3]));

       PicasFijas();
       if(f==4)
	{
	 do{
	    settextstyle(1,0,4);
	    delay(500);
	    setcolor(15);
	    outtextxy(33,350,"±²  WIN  ²±");
	    delay(500);
	    setcolor(RED);
	    outtextxy(33,350,"±²  WIN  ²±");
	   }
	   while(!kbhit());
	   return 0;
	}
       sprintf(Aux,"%d",p);
       outtextxy(303,107+intento*20,Aux);
       sprintf(Aux,"%d",f);
       outtextxy(350,107+intento*20,Aux);
     }

      settextstyle(1,0,1);
      outtextxy(33,350,"PERDISTE...EL NUMERO ERA ");
      outtextxy(300,350,N);
      getch();
      clearviewport();
      break;

    case '2':
    Out();
    break;
    default:
	  outtextxy(185,230,"PRESIONE UNA TECLA");
   }
 }
}
 getch();
 closegraph();
 clearviewport();
}
/*************************************************************************/
void PicasFijas()
{
 int i,j;
 p=0;f=0;
 for(i=0;i<4;i++)
    for(j=0;j<4;j++)
       if(V[i]==N[j])
       if(i==j){
       	 f++;
	 break;}
       else{
	   p++;
	   break;}

}
/*************************************************************************/
void Windows(int x1,int y1,int x2,int y2)
{
 int i;
 setcolor(BLACK);
 rectangle(x1,y1,x2,y2);
 setfillstyle(1,1);
 bar(x1+1,y1+1,x2-1,y2-1);
 for(i=1;i<3;i++)
    {
     setcolor(WHITE);
     line(x1+i,y1+i,x2-i,y1+i);
     line(x1+i,y1+i,x1+i,y2-i);
     line(x1+i+3,y2-i-3,x2-i-3,y2-i-3);
     line(x2-i-3,y1+i+3,x2-i-3,y2-i-3);
     setcolor(11);
     line(x1+i+3,y1+i+3,x2-i-3,y1+i+3);
     line(x1+i+3,y1+i+3,x1+i+3,y2-i-3);
     line(x1+i,y2-i,x2-i,y2-i);
     line(x2-i,y1+i,x2-i,y2-i);
    }
 line(x1+i+4,y1+i+4,x1+i+4,y2-i-4);
 line(x1+i+4,y1+i+4,x2-i-4,y1+i+4);
 setcolor(WHITE);
 line(x1+i+4,y2-i-4,x2-i-4,y2-i-4);
 line(x2-i-4,y1+i+4,x2-i-4,y2-i-4);
}
/*************************************************************************/
void Boton(int x1,int y1,int x2,int y2,int c1,int c2,int c3,int N)
{
 int y;
 setlinestyle(0,0,0);
 setfillstyle(SOLID_FILL,c3);
 bar(x1,y1,x2,y2);
 for(y=0;y<N;y++)
    {
     setcolor(c1);
     line(x1-y,y2+y,x2+y,y2+y);
     line(x2+y,y1-y,x2+y,y2+y);
     setcolor(c2);
     line(x1-y,y1-y,x1-y,y2+y);
     line(x1-y,y1-y,x2+y,y1-y);
    }
 setcolor(0);
 line(x1-y,y2+y,x2+y,y2+y);
 line(x2+y,y1-y,x2+y,y2+y);
 line(x1-y,y1-y,x1-y,y2+y);
 line(x1-y,y1-y,x2+y,y1-y);
}
/************************************************************************/
void Present(void)
{
 Boton(180,50,470,400,8,15,7,2);
 setcolor(15);
 rectangle(190,60,460,390);
 Windows(210,80,438,97);
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(245,100,"JED");
 outtextxy(305,130,"SOFT");
 settextstyle(1,0,3);
 outtextxy(250,185,"Picas y Fijas");
 settextstyle(6,0,1);
 outtextxy(277,212,"Versi¢n 2.1");
 settextstyle(1,0,4);
 outtextxy(263,243,"U. C. C.");
 settextstyle(6,0,1);
 outtextxy(200,300,"Copyright JEDSOFT Corp.96-97");
 outtextxy(205,320,"Todos los Derechos Reservados");
 outtextxy(208,340,"JAVIER ECHEVERRIA DEL VALLE");
 settextstyle(0,0,0);
 delay(3500);
 clearviewport();
}
/***********************************************************************/
void Out(void)
{
  settextstyle(1,0,2);
  outtextxy(140,200,"PRESIONE UNA TECLA PARA SALIR");
  getch();
  clearviewport();
  exit(0);
}