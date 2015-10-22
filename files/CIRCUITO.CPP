#include "string.h"
#include "stdio.h"
#include "ctype.h"
#include "graphics.h"
#include "stdlib.h"
#include "conio.h"
void windowUp(int,int,int ancho,int alto,int c_fondo,char *w );
void drawIcono(int,int,int ancho,int alto,int C_fondo,char *w[7] );
void message(int,int,int ancho,int alto,int c_fondo,char *w );
void drawIconoDW(int,int,int ancho,int alto,int C_fondo,char *w );
void icono();
void process();
int i=0,k=0,r,R1,R2,R3,R4,R5,R6,R7,R8,R9,
	      R10,R11,R12,R13,l=1,V1,V2,V3;
float R1E,R2E,R3E,R4E,R5E,VAB,VCD,VAC,VR4E,VR5E,I1,I2,I3,I4,I5;
float cr1,cr2,cr3,cr4,cr5,cr6,cr7,cr8,cr9,cr10,cr11,cr12,cr13;
void main(void)
{
int j=13,k,i,h;
int controlador,modo;
controlador=DETECT;
modo=0;
initgraph(&controlador,&modo,"");
	 while((toupper(j)!='S')){
	 windowUp(10,10,595,500,LIGHTGRAY," F I S I C A III ");
	 outtextxy(400,24,"Digite ( S ) para salir");
	 line(210,190,210,265);
	 line(200,265,220,265);
	 line(210,280,210,355);
	 line(200,280,220,280);
	 line(210,355,300,355);

	 line(210,190,250,190);
	 line(260,190,300,190);
	 line(260,190,260,200);
	 line(250,180,250,190);
	 line(250,180,260,200);

	 line(450,190,500,190);
	 line(510,190,550,190);
	 line(510,190,510,200);
	 line(500,180,500,190);
	 line(500,180,510,200);

	 line(475,150,475,225);
	 line(525,150,525,225);
	 line(475,150,525,150);
	 line(475,225,525,225);
	 line(510,150,510,160);
	 line(500,150,500,140);
	 line(500,140,510,160);
	 line(510,235,510,225);
	 line(500,225,500,215);
	 line(500,215,510,235);

	 line(450,355,500,355);
	 line(510,355,550,355);
	 line(510,355,510,365);
	 line(500,345,500,355);
	 line(500,345,510,365);

	 line(300,355,370,355);
	 line(380,355,450,355);
	 line(380,355,380,365);
	 line(370,345,370,355);
	 line(370,345,380,365);

	 line(300,190,370,190);
	 line(380,190,450,190);
	 line(380,190,380,200);
	 line(370,180,370,190);
	 line(370,180,380,200);

	 line(300,190,300,265);
	 line(290,265,300,265);
	 line(290,265,310,280);
	 line(300,280,300,355);
	 line(300,280,310,280);

	 line(270,150,270,225);
	 line(340,150,340,225);
	 line(270,150,340,150);
	 line(270,225,340,225);

	 line(450,190,450,265);
	 line(440,265,460,265);
	 line(450,280,450,355);
	 line(440,280,460,280);

	 line(550,190,550,265);
	 line(540,265,560,265);
	 line(550,280,550,355);
	 line(540,280,560,280);
	 outtextxy(263,170,"R1");
	 outtextxy(385,378,"R3");
	 outtextxy(500,378,"R5");
	 outtextxy(385,170,"R2");
	 outtextxy(500,170,"R10");
	 outtextxy(333,278,"R1");
	 outtextxy(530,278,"V3");
	 outtextxy(430,278,"V2");
	 outtextxy(230,278,"V1");

	   icono();
	    j=getche();
	if(j==13 || j==72 || j==80){
	  i=71;
	  h=95;
	 while(j!=13){
	  setcolor(WHITE);
  rectangle(30,i,92,h);
	  j=getche();
	 if(j==72 && i>80){
	 setcolor(BLUE);
  rectangle(30,i,92,h);
	  i=i-24;
	  h=h-24;
	  l--;
	      }
   if(j==80 && i<409){
       setcolor(BLUE);
  rectangle(30,i,92,h);
	   i=i+24;
	   h=h+24;
	   l++;
	   }
	  }
	  if(j==13 && l==1){
		drawIconoDW(30,71,60,20,7," V1");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE V1..?");
		l=1;
		}
	if(j==13 && l==2){
		drawIconoDW(30,95,60,20,7," V2");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE V2..?");
		l=1;
		}
	if(j==13 && l==3){
		drawIconoDW(30,120,60,20,7," V3");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE V3..?");
		l=1;
		}
	if(j==13 && l==4){
		drawIconoDW(30,145,60,20,7," R1");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R1..?");
		l=1;
		}
	if(j==13 && l==5){
		drawIconoDW(30,169,60,20,7," R2");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R2..?");
		l=1;
		}
	if(j==13 && l==6){
		drawIconoDW(30,194,60,20,7," R3");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R3..?");l=1;
		l=1;
		}
	if(j==13 && l==7){
		drawIconoDW(30,217,60,20,7," R4");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R4..?");
		l=1;
		}
	if(j==13 && l==8){
		drawIconoDW(30,242,60,20,7," R5");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R5..?");
		l=1;
		}
	if(j==13 && l==9){
		drawIconoDW(30,267,60,20,7," R6");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R6..?");
		l=1;
		}
	if(j==13 && l==10){
		drawIconoDW(30,290,60,20,7," R7");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R7..?");
		l=1;
		}
	if(j==13 && l==11){
		drawIconoDW(30,313,60,20,7," R8");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R8..?");
		l=1;
		}
	if(j==13 && l==12){
		drawIconoDW(30,338,60,20,7," R9");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R9..?");
		l=1;
		}
	if(j==13 && l==13){
		drawIconoDW(30,368,60,20,7,"  R10");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R10..?");
		l=1;
		}
	if(j==13 && l==14){
		drawIconoDW(30,387,60,20,7,"  R11");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R11..?");
		l=1;
		}
	if(j==13 && l==15){
		drawIconoDW(30,410,60,20,7,"  R12");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R12..?");
		l=1;
		}
	if(j==13 && l==16){
		drawIconoDW(30,435,60,20,7,"  R13");
		icono();
		message(200,150,400,280,DARKGRAY,"AJUSTE VALOR DE R13..?");
		l=1;
		}
	       cleardevice();
     }
     }
     cleardevice();
     while((toupper(j)=='S')){
	 windowUp(10,10,595,450,BLUE," F I S I C A III ");
	 outtextxy(400,24,"Digite ( ENTER ) para salir");
	 outtextxy(50,70,"R1equ = ");
	 outtextxy(50,87,"R2equ = ");
	 outtextxy(50,103,"R3equ = ");
	 outtextxy(50,120,"R4equ = ");
	 outtextxy(50,136,"R5equ = ");
	 outtextxy(220,70,"Corriente 1 =  ");
	 outtextxy(220,87,"Corriente 2 =  ");
	 outtextxy(220,103,"Corriente 3 =  ");
	 outtextxy(220,120,"Corriente 4 =  ");
	 outtextxy(220,136,"Corriente 5 =  ");
	 outtextxy(390,70,"Vol_AB = ");
	 outtextxy(390,87,"Vol_CD = ");
	 outtextxy(390,103,"Vol_AC = ");
	 outtextxy(402,120,"Vol_R4equ = ");
	 outtextxy(402,136,"Vol_R5equ = ");
	 outtextxy(60,182,"Corr_R1 = ");
	 outtextxy(60,199,"Corr_R2 = ");
	 outtextxy(60,216,"Corr_R3 = ");
	 outtextxy(60,233,"Corr_R4 = ");
	 outtextxy(60,249,"Corr_R5 = ");
	 outtextxy(60,263,"Corr_R6 = ");
	 outtextxy(60,280,"Corr_R7 = ");
	 outtextxy(60,295,"Corr_R8 = ");
	 outtextxy(60,310,"Corr_R9 = ");
	 outtextxy(65,325,"Corr_R10 = ");
	 outtextxy(65,342,"Corr_R11 = ");
	 outtextxy(65,360,"Corr_R12 = ");
	 outtextxy(65,378,"Corr_R13 = ");
	 line(210,190,210,265);
	 line(200,265,220,265);
	 line(210,280,210,355);
	 line(200,280,220,280);
	 line(210,355,300,355);

	 line(210,190,250,190);
	 line(260,190,300,190);
	 line(260,190,260,200);
	 line(250,180,250,190);
	 line(250,180,260,200);

	 line(450,190,500,190);
	 line(510,190,550,190);
	 line(510,190,510,200);
	 line(500,180,500,190);
	 line(500,180,510,200);

	 line(450,355,500,355);
	 line(510,355,550,355);
	 line(510,355,510,365);
	 line(500,345,500,355);
	 line(500,345,510,365);

	 line(300,355,370,355);
	 line(380,355,450,355);
	 line(380,355,380,365);
	 line(370,345,370,355);
	 line(370,345,380,365);

	 line(300,190,370,190);
	 line(380,190,450,190);
	 line(380,190,380,200);
	 line(370,180,370,190);
	 line(370,180,380,200);

	 line(300,190,300,265);
	 line(290,265,300,265);
	 line(290,265,310,280);
	 line(300,280,300,355);
	 line(300,280,310,280);

	 line(450,190,450,265);
	 line(440,265,460,265);
	 line(450,280,450,355);
	 line(440,280,460,280);

	 line(550,190,550,265);
	 line(540,265,560,265);
	 line(550,280,550,355);
	 line(540,280,560,280);
	 outtextxy(263,165,"R1");
	 outtextxy(385,378,"R3equ");
	 outtextxy(500,378,"R5equ");
	 outtextxy(385,165,"R2equ");
	 outtextxy(500,165,"R4equ");
	 outtextxy(333,278,"R1equ");
	 outtextxy(530,278,"V3");
	 outtextxy(430,278,"V2");
	 outtextxy(230,278,"V1");
	 process();
	 j=getche();

    }
}
void windowUp(int posx,int posy,int ancho,int alto,int c_fondo,char*w)
{
 setcolor(WHITE);
 rectangle(posx,posy,ancho,alto);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((posx+1),(posy+1),WHITE);
   settextstyle(7,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(posx+100,posy+15,w);
 rectangle(posx+1,posy+1,ancho-1,alto-1);
 setcolor(DARKGRAY);
 line(posx,alto,ancho,alto);
 line(ancho,alto,ancho,posy);
 line(posx+1,alto-1,ancho-1,alto-1);
 line(ancho-1,alto-1,ancho-1,posy+1);
 setcolor(WHITE);
 rectangle(posx+10,posy+5,ancho-10,posy+30);
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((posx+11),(posy+6),WHITE);
   setcolor(BLACK);
 line(posx+10,posy+5,ancho-10,posy+5);
 line(posx+10,posy+5,posx+10,posy+30);

}

void drawIcono(int posx,int posy,int ancho,int alto,int C_fondo,char*w)
{

    setcolor(WHITE);
    rectangle(posx,posy,posx+ancho,posy+alto);
 setfillstyle(SOLID_FILL,C_fondo);
   floodfill((posx+1),(posy+1),WHITE);
   setcolor(BLACK);
    rectangle(posx+1,posy+1,posx+ancho,posy+alto);
    rectangle(posx+1,posy+1,posx+ancho+1,posy+alto+1);
   settextstyle(0,HORIZ_DIR,2);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(posx+11,posy+12,w);
 return;
}
void icono(){
  drawIcono(30,71,60,20,7," V1");
  drawIcono(30,95,60,20,7," V2");
  drawIcono(30,120,60,20,7," V3");
  drawIcono(30,145,60,20,7," R1");
  drawIcono(30,169,60,20,7," R2");
  drawIcono(30,194,60,20,7," R3");
  drawIcono(30,217,60,20,7," R4");
  drawIcono(30,242,60,20,7," R5");
  drawIcono(30,267,60,20,7," R6");
  drawIcono(30,290,60,20,7," R7");
  drawIcono(30,313,60,20,7," R8");
  drawIcono(30,338,60,20,7," R9");
  drawIcono(30,362,60,20,7,"  R10");
  drawIcono(30,387,60,20,7,"  R11");
  drawIcono(30,410,60,20,7,"  R12");
  drawIcono(30,435,60,20,7,"  R13");
return;
}
void message(int posx,int posy,int ancho,int alto,int c_fondo,char*w)
{
 char rango;
 setcolor(WHITE);
 rectangle(posx,posy,ancho,alto);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((posx+1),(posy+1),WHITE);
   settextstyle(7,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(posx+100,posy+15,w);
 rectangle(posx+1,posy+1,ancho-1,alto-1);
 setcolor(BLACK);
 line(posx,alto,ancho,alto);
 line(ancho,alto,ancho,posy);
 line(posx+1,alto-1,ancho-1,alto-1);
 line(ancho-1,alto-1,ancho-1,posy+1);
 setcolor(WHITE);
 rectangle(posx+10,posy+5,ancho-10,posy+30);
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((posx+11),(posy+6),WHITE);
   setcolor(BLACK);
 line(posx+10,posy+5,ancho-10,posy+5);
 line(posx+10,posy+5,posx+10,posy+30);
     drawIcono(posx+30,posy+55,20,20,LIGHTGRAY,"UP");
     drawIcono(posx+150,posy+55,20,20,LIGHTGRAY,"DW");
     drawIconoDW(posx+60,posy+55,80,24,LIGHTGRAY,"   R = ");

	do{
		       rango=getche();
		   if(rango==72 && r<=16){
			r=r+1;
     drawIconoDW(posx+30,posy+55,20,20,LIGHTGRAY,"UP");
			//Delay(100);
     drawIcono(posx+30,posy+55,20,20,LIGHTGRAY,"UP");
			    }
		if(rango==80 && r>=1){
			 r=r-1;
     drawIconoDW(posx+150,posy+55,20,20,LIGHTGRAY,"DW");
		      /* Delay(100);*/
     drawIcono(posx+150,posy+55,20,20,LIGHTGRAY,"DW");
			    }
		    if(l==1){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      V1=r;
		      printf("%d",V1);
			 }
		    if(l==2){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      V2=r;
		      printf("%d",V2);
			 }
		   if(l==3){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      V3=r;
		      printf("%d",V3);
			 }
		    if(l==4){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R1=r;
		      printf("%d",R1);
			 }
		    if(l==5){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R2=r;
		      printf("%d",R2);
			 }
		   if(l==6){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R3=r;
		      printf("%d",R3);
			 }
		  if(l==7){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R4=r;
		      printf("%d",R4);
			 }
		  if(l==8){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R5=r;
		      printf("%d",R5);
			 }
		 if(l==9){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R6=r;
		      printf("%d",R6);
			 }
		if(l==10){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R7=r;
		      printf("%d",R7);
			 }
		if(l==11){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R8=r;
		      printf("%d",R8);
			 }
		if(l==12){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R9=r;
		      printf("%d",R9);
			 }
		if(l==13){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R10=r;
		      printf("%d",R10);
			 }
		if(l==14){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R11=r;
		      printf("%d",R11);
			 }
		if(l==15){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R12=r;
		      printf("%d",R12);
			 }
		if(l==16){
		      gotoxy(40,14);
		      printf("%s","  ");
		      gotoxy(40,14);
		      R13=r;
		      printf("%d",R13);
		    }
       }while(rango!=13);
		       return;

}
void process()
{
R1E= (float)1/R2+(float)1/R3+(float)1/R4;
R1E= 1/R1E;
R2E= (float)1/R5+(float)1/R6;
R2E= 1/R2E;
R3E= (float)1/R7+(float)1/R8;
R3E= 1/R3E;
R4E= (float)1/R9+(float)1/R10+(float)1/R11;
R4E= 1/R4E;
R5E= (float)1/R12+(float)1/R13;
R5E= 1/R5E;
I5=(V2-V3)/(R4E+R5E);
I2=(((float)(V1/R1)*(R2E+R3E))-(I5*R3E))/((((float)(R1+R1E)/R1)*(R2E+R3E))+R1E);
I3=(float)(V1-((R1+R1E)*I2))/R1;
I4=I3-I5;
I1=I2+I3;
VAB=I3*R2E;
VCD=I4*R3E;
VAC=I2*R1E;
VR4E=I5*R4E;
VR5E=I5*R5E;
cr1=(float)V1/R1;
cr2=(float)VAC/R2;
cr3=(float)VAC/R3;
cr4=(float)VAC/R4;
cr5=(float)VAB/R5;
cr6=(float)VAB/R6;
cr7=(float)VCD/R7;
cr8=(float)VCD/R8;
cr9=(float)VR4E/R9;
cr10=(float)VR4E/R10;
cr11=(float)VR4E/R11;
cr12=(float)VR5E/R12;
cr13=(float)VR5E/R13;
gotoxy(11,5);
printf("%f",R1E);
gotoxy(11,6);
printf("%f",R2E);
gotoxy(11,7);
printf("%f",R3E);
gotoxy(11,8);
printf("%f",R4E);
gotoxy(11,9);
printf("%f",R5E);
gotoxy(35,5);
printf("%f",I1);
gotoxy(35,6);
printf("%f",I2);
gotoxy(35,7);
printf("%f",I3);
gotoxy(35,8);
printf("%f",I4);
gotoxy(35,9);
printf("%f",I5);
gotoxy(57,5);
printf("%f",VAB);
gotoxy(57,6);
printf("%f",VCD);
gotoxy(57,7);
printf("%f",VAC);
gotoxy(57,8);
printf("%f",VR4E);
gotoxy(57,9);
printf("%f",VR5E);
gotoxy(15,12);
printf("%f",cr1);
gotoxy(15,13);
printf("%f",cr2);
gotoxy(15,14);
printf("%f",cr3);
gotoxy(15,15);
printf("%f",cr4);
gotoxy(15,16);
printf("%f",cr5);
gotoxy(15,17);
printf("%f",cr6);
gotoxy(15,18);
printf("%f",cr7);
gotoxy(15,19);
printf("%f",cr8);
gotoxy(15,20);
printf("%f",cr9);
gotoxy(15,21);
printf("%f",cr10);
gotoxy(15,22);
printf("%f",cr11);
gotoxy(15,23);
printf("%f",cr12);
gotoxy(15,24);
printf("%f",cr13);
getche();
return;
}
void drawIconoDW(int posx,int posy,int ancho,int alto,int C_fondo,char*w)
{
    setcolor(BLACK);
    rectangle(posx,posy,posx+ancho,posy+alto);
 setfillstyle(SOLID_FILL,C_fondo);
   floodfill((posx+1),(posy+1),BLACK);
   setcolor(BLACK);
    rectangle(posx+1,posy+1,posx+ancho,posy+alto);
    rectangle(posx+2,posy+2,posx+ancho-2,posy+alto-2);
    setcolor(WHITE);
    line(posx+1,posy+alto-1,posx+ancho,posy+alto-1);
    line(posx+ancho,posy+alto-1,posx+ancho,posy+1);
    line(posx+2,posy+alto-2,posx+ancho,posy+alto-2);
    line(posx+ancho-1,posy+alto-1,posx+ancho-1,posy+2);
   settextstyle(7,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
      setcolor(BLACK);
   outtextxy(posx+11,posy+12,w);
 return;
}