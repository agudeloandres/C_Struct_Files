#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
# include <dos.h>

char r;
 int t;
 int w,l,base,base2;
int main(void)
{
void HANOI(int n,int a,int b,int auxi);
int gdriver = DETECT, gmode, n,i,j,a,b,auxi,t,v, q, y, h,color, maxx, maxy,maxcolor, seed;
initgraph(&gdriver, &gmode, "F:\BGI");
   maxx = getmaxx() + 1;
   maxy = getmaxy() + 1;
   maxcolor = getmaxcolor() + 1;
settextstyle(7,0,6);
   while (!kbhit())
   {
      settextstyle(7,0,6);
      seed = random(32767);
      srand(seed);
      for (v=0; v<10000; v++)
      {
	 q = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 putpixel(q, y, color);

      }
	    for(h=1;h<=13;h++){
	    setcolor(q+h);
	    outtextxy(70,50,"TORRES DE HANOI");

}
	    settextstyle(1,0,5);
	    for(h=0;h<=14;h++){
	    setcolor(q+h+1);
	    outtextxy(53,200," CARLOS ANDRES AGUDELO");
	    outtextxy(100,350," ISAAC ABELLO ARIZA");
	    }



      delay(100);
      srand(seed);

      for (v=0; v<10000; v++)
      {
	 q = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 if (color == getpixel(q, y))
	    putpixel(q, y, 3+14);



      }
   }
getch();
//***************************************************************************


do{
inicio:
setcolor(WHITE);
cleardevice();
setbkcolor(BLUE);
settextstyle(0,0,1);
setfillstyle(1,5);
outtextxy(190,3,"T O R R E S  D E  H A N O I");
setcolor(WHITE);
setlinestyle(0, 0, 3);
line(0,2,180,2);
line(420,2,637,2);
line(0,2,0,470);
line(0,470,637,470);
line(637,2,637,470);
setlinestyle(0, 0, 1);
// POLIMORFISMO
bar3d(80,25,100,320,8,1);
bar3d(275,25,295,320,8,1);
bar3d(500,25,520,320,8,1);
setcolor(WHITE);
settextstyle(0,0,1);
outtextxy(80,340,"1 PRINCIPAL");
outtextxy(275,340,"2 AUXILIAR");
outtextxy(500,340,"3 DESTINO");
setcolor(YELLOW);
outtextxy(200,386,"DIGITE NUMERO DE DISCOS A MOVER :[     ]");
outtextxy(200,406,"     **  MAXIMO 17 DISCOS  **");
gotoxy(62,25);
scanf("%d",&n);
if (n<=0){
cleardevice();
settextstyle(1,0,3);
outtextxy(160,250,"NO HAY DISCOS PARA MOVER ! ");
getch();
goto inicio;
}
if (n>17){
cleardevice();
settextstyle(1,0,3);
outtextxy(90,250,"DATO INVALIDO, NO SE PUEDE PROCESAR !");
getch();
goto inicio;
}
w=0;l=170;base=310;base2=325;

       for(i=1;i<=n;i++){
       setfillstyle(6,GREEN);
       bar3d(w+=5,base-=15,l-=5,base2-=15,6,1);
       }

getch();

w=430;l=600;base=310;base2=325;
for(i=1;i<=n;i++){
       setfillstyle(6,GREEN);
       bar3d(w+=5,base-=15,l-=5,base2-=15,6,1);
      }

getch();

cleardevice();
setbkcolor(BLUE);
setcolor(YELLOW);
textcolor(YELLOW);
//*************************************************************************//
a=1;
b=3;
auxi=2;

gotoxy(15,25);printf("PRESENTACION DE LOS PASOS\n\n");
HANOI(n,a,b,auxi);
printf("\t ³                                           ³ \n");
printf("\t ³            FIN DE LOS PASOS      	     ³ \n");
printf("\t ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ \n");

  getch();
cleardevice();
  setcolor(RED);
   settextstyle(1, HORIZ_DIR, 1);
   outtextxy(30,267 ,"Deseas salir  [S/N] ? [   ]");
   gotoxy(30,18);getchar();
    r=getchar();
 }while (r !='s'&& r!='S');
 salida:
  // Salida Del Programa
   for (t= 0 ; t<=13; t++) {
  setcolor(t);
  delay(20);
  outtextxy(30,267 ,"Deseas salir  [S/N] ? [   ]");
  }
   delay(50);
   cleardevice();
   settextstyle(0, HORIZ_DIR, 1);
    for (t= 0 ; t<=13; t++) {
   setcolor(t);
   delay(20);
   outtextxy(30,180 ,"ESTE PROGRAMA HA FINALIZADO, GRACIAS POR UTILIZAR EL PROGRAMA !");
   }
  delay(50);
 getch();
closegraph();
return 0;
}
//**************************FIN DEL PROGRAMA PRINCIPAL***********************
void HANOI(n,a,b,auxi)
{
if(n==1){
 printf("\t ³ Mover el disco 1  del poste %d  al poste %d ³ \n",a,b);
 return;
 }
 HANOI(n-1,a,auxi,b);
 printf("\t ³ Mover el disco %d  del poste %d  al poste %d ³ \n",n,a,b);
 HANOI(n-1,auxi,b,a);
 }





