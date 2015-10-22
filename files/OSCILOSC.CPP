#include"conio.h"
#include"dos.h"
#include"string.h"
#include"stdio.h"
#include"ctype.h"
#include"graphics.h"
#include "process.h"
#include "stdlib.h"
		void Osciloscopio(int x);
		void Grafics(void);
		void voltimetro();
		void order_lef(void);
		void order_righ(void);
		void reglaX(void);
		void regla_X(void);
		void reglaY(void);
		void display(void);
		void regla_Y(void);
		void volts(void);
		void windowUp(int,int,int ancho,int alto,int c_fondo );
		void windowDw(int,int,int ancho,int alto,int c_fondo );
		void menssagebox(int ,int ,int ancho,int alto,int c_fondo,char *z );
		void menssage(int ,int ,int ancho,int alto,int c_fondo,char *x );
		void bottonUp(int,int,int,int,char *w);
		void bottonDw(int,int,int,int,char *w);

int data[1000],y1=120,x1=205;
int sw=1,X1=0,Y1=0,ancho=0,periodo=0;
float vpp,vmin,frecuencia,Hz;

main()
{
int grdriver,grmode;
char OP;
grdriver=DETECT;
initgraph(&grdriver,&grmode,"");


	  do{

			 /*M E N U*/
			  cleardevice();
		setviewport(0,0,639,478,BLUE);
		windowUp(5,20,639,478,CYAN);
		windowDw(50,70,590,450,LIGHTBLUE);
		bottonUp(240,150,BLACK,LIGHTGRAY,  " Osciloscopio ");
		bottonUp(240,150,RED,LIGHTGRAY,    " O            ");
		bottonUp(240,200,BLACK,LIGHTGRAY,  "   Graphics   ");
		bottonUp(240,200,RED,LIGHTGRAY,    "   G          ");
		bottonUp(240,250,BLACK,LIGHTGRAY,  "  Voltimetro  ");
		bottonUp(240,250,RED,LIGHTGRAY,    "  V           ");
		bottonUp(240,300,BLACK,LIGHTGRAY,  "  Options     ");
		bottonUp(240,300,RED,LIGHTGRAY,    "  O           ");
		bottonUp(240,350,BLACK,LIGHTGRAY,  "    Exit      ");
		bottonUp(240,350,RED,LIGHTGRAY,    "    E         ");

		   OP=toupper(getche());
		       switch(OP){
			case 'O':
		       sound(700);
	bottonDw(240,150,BLACK,LIGHTGRAY,          " Osciloscopio ");
		      delay(200);
		       nosound();
	bottonUp(240,150,RED,LIGHTGRAY,            " O            ");
		      delay(200);
		    Osciloscopio(0);
			break;

			case 'G':
			sound(700);
	bottonDw(240,200,BLACK,LIGHTGRAY,          "   Graphics   ");
			delay(200);
			nosound();
	bottonUp(240,200,RED,LIGHTGRAY,            "   G          ");
			delay(200);
			cleardevice();
			 Grafics();
			  break;

			  case 'V':
			 sound(700);
	bottonDw(240,250,BLACK,LIGHTGRAY,          "  Voltimetro  ");
			 delay(200);
			 nosound();
	bottonUp(240,250,RED,LIGHTGRAY,            "  V           ");
			 delay(200);
			voltimetro();
			   break;
			 case 'E':
			 sound(700);
	bottonDw(240,350,BLACK,LIGHTGRAY,          "    Exit      ");
			 delay(200);
			 nosound();
	bottonUp(240,350,RED,LIGHTGRAY,            "    E         ");
			delay(200);
		       closegraph();
			 exit(0);
			    }


  }while(!strchr("E",toupper(OP)));


       closegraph();

return 0;

  }


/**************************BOTON DW*****************************************/
void bottonDw(int X1,int Y1 , int color_txt,int c_fondo,char *w)
{

 int num,X2,Y2,i;
 float a,b;
 num=strlen(w);              /*El primer y segudo argumento de las funciones*/
 X2=X1+num*10;                /*bottonup, determinan la posicion del boton*/
 Y2=Y1+30;                      /*3er  argumento determinan el color del*/
				 /*texto de este,4to color de fondo*/
 setcolor(BLACK);                         /*"ColorF";  de este*/
 rectangle(X1,Y1,X2,Y2);  /*marco del boton*/
 for(i=1;i<3;i++){        /*profundidad de los botones*/
 moveto(X1+i,Y1+i);
 setcolor(BLACK);
 lineto(X2-i,Y1+i);
 setcolor(WHITE);
 lineto(X2-i,Y2-i);
 lineto(X1+i,Y2-i);
 setcolor(BLACK);
 lineto(X1+i,Y1+i);
       }
 setcolor(c_fondo);
 rectangle(X1+i,Y1+i,X2-i,Y2-i);
       a=((X2-X1)/2+X1);
       b=((Y2-Y1)/2+Y1);
 setcolor(color_txt);
 moveto(a,b);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((a),(b),c_fondo);
   settextstyle(5,HORIZ_DIR,4);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtext(w);

}
/***************************BOTON UP****************************************/
void bottonUp(int X1,int Y1,int color_txt,int c_fondo,char *w)
{
 int num,X2,Y2,i;
 float a,b;
 num=strlen(w);
 X2=X1+num*10;
 Y2=Y1+30;
 setcolor(BLACK);
 rectangle(X1,Y1,X2,Y2);  /*marco del boton*/
 setcolor(WHITE);
 for(i=1;i<3;i++){        /*altura del los botones*/
 moveto(X1+i+1,Y1+i);
 setcolor(WHITE);
 lineto(X2-i,Y1+i);
 setcolor(BLACK);
 lineto(X2-i,Y2-i);
 lineto(X1+i,Y2-i);
 setcolor(WHITE);
 lineto(X1+i,Y1+i);
      }
 setcolor(c_fondo);                          /*BOTTON DOWN*/
 rectangle(X1+i,Y1+i,X2-i,Y2-i);
       a=((X2-X1)/2+X1);
       b=((Y2-Y1)/2+Y1);
 setcolor(color_txt);
 moveto(a,b);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((a),(b),c_fondo);
   settextstyle(5,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtext(w);
}

/*******************************WINDOW UP***********************************/
void windowUp(int posx,int posy,int ancho,int alto,int c_fondo)
{
 int X2,Y2,i;
 float a,b;
 X2=ancho;
 Y2=alto;
 posx+=1;X2-=1;
 posy+=1;Y2-=1;
 for(i=1;i<=2;i++){
 moveto(posx+i,posy+i);
 setcolor(WHITE);
 lineto(X2-i,posy+i);
 setcolor(BLACK);       /**/
 lineto(X2-i,Y2-i);
 lineto(posx+i,Y2-i);
 setcolor(WHITE);
 lineto(posx+i,posy+i);
       }
 setcolor(c_fondo);
 rectangle(posx+i,posy+i,X2-i,Y2-i);
       a=((X2-posx)/2+posx);
       b=((Y2-posy)/2+posy);
 moveto(a,b);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((a),(b),c_fondo);

}
/*******************************WINDOW DW************************************/
void windowDw(int posx,int posy,int ancho,int alto,int c_fondo)
{
 int X2,Y2,i;
 float a,b;
 X2=ancho;
 Y2=alto;
 posx+=1;X2-=1;
 posy+=1;Y2-=1;
 for(i=1;i<=2;i++){
 moveto(posx+i,posy+i);
 setcolor(BLACK);
 lineto(X2-i,posy+i);
 setcolor(WHITE);
 lineto(X2-i,Y2-i);
 lineto(posx+i,Y2-i);
 setcolor(BLACK);
 lineto(posx+i,posy+i);
       }
 setcolor(c_fondo);
 rectangle(posx+i,posy+i,X2-i,Y2-i);
       a=((X2-posx)/2+posx);
       b=((Y2-posy)/2+posy);
 moveto(a,b);
 setfillstyle(SOLID_FILL,c_fondo);
   floodfill((a),(b),c_fondo);

}
/********************************MENSSAGE WIN*********************************/
void menssagebox(int posx,int posy,int ancho,int alto,int c_fondo,char *z)
{
 char op;
 void *buff;
 int X2,Y2,tamano;
 X2=ancho;
 Y2=alto;
 posx+=1;X2-=1;
 posy+=1;Y2-=1;
       tamano=imagesize(posx,posy,ancho+posx,alto+posy);
		  if(tamano != 0xff){
		     buff=malloc(tamano);
			if (buff){
	    getimage(posx,posy,ancho+posx,alto+posy,buff);
	   windowUp(posy,posx,ancho+posx,alto+posy,c_fondo);
	      bottonDw(posx+30,posy+20,BLACK,c_fondo,z);
	bottonUp(posx+30,posy+100,BLACK,c_fondo,  " UP ");
	bottonUp(posx+30,posy+100,RED,c_fondo,    " U  ");

	bottonUp(posx+120,posy+100,BLACK,c_fondo, " DW ");
	bottonUp(posx+120,posy+100,RED,c_fondo,   " D  ");
	bottonDw(posx+30,posy+60,BLACK,LIGHTBLUE, "      ");


	    do{
		      op=toupper(getche());
			  switch(op){
			   case  'U':
	bottonDw(posx+30,posy+100,BLACK,c_fondo,  " UP ");
			   delay(7000);
	bottonUp(posx+30,posy+100,RED,c_fondo,    " U  ");
			   printf("\a");
		putimage(posx,posy,buff,COPY_PUT);
			  free(buff);
			     break;
			   case  'D':
	bottonDw(posx+120,posy+100,BLACK,c_fondo,  " DW ");
	bottonDw(posx+120,posy+100,RED,c_fondo,    " D  ");
			   delay(7000);
	bottonUp(posx+120,posy+100,RED,c_fondo,    " D  ");
			   printf("\a");
		putimage(posx,posy,buff,COPY_PUT);
			    free(buff);
			       break;
			       }

	 }while(!strchr("AC",toupper(op)));
		      }

	      }

     }

/******************************MENSSAGE***************************************/

void menssage(int posx,int posy,int ancho,int alto,int c_fondo,char *x)
{
 char op;
 void *buff;
 int X2,Y2,tamano;
 X2=ancho;
 Y2=alto;
 posx+=1;X2-=1;
 posy+=1;Y2-=1;
       tamano=imagesize(posx,posy,ancho+posx,alto+posy);
		  if(tamano != 0xff){
		     buff=malloc(tamano);
			if (buff){
	  getimage(posx,posy,ancho+posx,alto+posy,buff);
	  windowUp(posy,posx,ancho+posx,alto+posy,c_fondo);
		 settextjustify(CENTER_TEXT,BOTTOM_TEXT);
			setcolor(RED);
			outtext(x);
	bottonUp(posx+70,posy+50,RED,c_fondo, " Aceptar");

	    do{
		      op=toupper(getche());
			  switch(op){
			   case  'A':
	bottonDw(posx+70,posy+50,RED,c_fondo, " Aceptar");
			   delay(7000);
	bottonUp(posx+70,posy+50,RED,c_fondo, " Aceptar");
			   printf("\a");
		putimage(posx,posy,buff,COPY_PUT);
			 free(buff);
			   break;
			  exit(0);
			     }

  }while(!strchr("A", toupper(op)));
		      }

	      }

     }

/****************************** COM_BIT***************************************/
void com_bit(unsigned num1)
  {
 unsigned c, mask = 1 << 15;
 printf("%d = ",num1);
 for(c = 1; c <= 16; c++){
 putchar(num1 & mask ? '1':'0');
 num1 <<= 1;
 if(c % 8 == 0)
 putchar(' ');
   }
 putchar('\t');
}

/*****************************************************************************/
void Osciloscopio(int r){
int i,byte,lsb,msb;

		      cleardevice();
		windowUp(5,5,630,478,CYAN);
		windowDw(50,50,590,317,CYAN);
	bottonUp(215,15,BLACK,LIGHTGRAY,  " <<  Osciloscopio >>  ");
	bottonUp(215,15,RED,LIGHTGRAY,    " <<  O            >>  ");

       do{

		setviewport(55,55,584,311,1);
		     clearviewport();
		      moveto(0,255);
		for(i=0;i<=999;i++){
			outport(0x378,0x00);
			outport(0x378,0x07);
			outport(0x378,0x16);
			   delay(1);
			msb=inport(0x379);
			outportb(0x378,0x06);
			lsb=inport(0x379);
			msb=msb<<1;
			msb=msb&0xf0;
			lsb=lsb>>3;
			lsb=lsb&0x0f;
			byte=msb|lsb;
			byte=byte;
			data[i]=byte;
			setcolor(RED);
		     putpixel(i,255-byte,RED);
		      lineto(i,255-data[i]);
				}
   }while(!strchr("SG",toupper(getche())));

			    volts();
}
/***************************  Grafics **************************************/


void Grafics(void)
{
int i=0,periodo;
char OR;
float frecuencia,Hz;
		      cleardevice();
	     windowUp(5,5,630,458,LIGHTBLUE);
	     windowDw(50,45,590,315,LIGHTBLUE);
	bottonUp(250,12,BLACK,LIGHTGRAY,    " << GRAFICS >> ");
	bottonUp(250,12,RED,LIGHTGRAY,      " << G       >> ");
	     windowUp(50,330,590,445,LIGHTBLUE);
	bottonUp(265,375,RED,LIGHTGRAY, " LF ");
	bottonUp(336,375,RED,LIGHTGRAY, " RG ");
	bottonUp(300,405,RED,LIGHTGRAY, " DW ");
	bottonUp(300,345,RED,LIGHTGRAY,    " UP ");
	bottonUp(265,375,BLACK,LIGHTGRAY,  "  F ");
	bottonUp(336,375,BLACK,LIGHTGRAY,  "  G ");
	bottonUp(300,405,BLACK,LIGHTGRAY,  "  W ");
	bottonUp(300,345,BLACK,LIGHTGRAY,  "  P ");
	bottonUp(305,375,RED,LIGHTGRAY,    " S ");
			 display();


       do{
		    OR=toupper(getche());
			  switch(OR){
			   case 'M':
		       for(i=0;i<=9;i++){
			   order_lef();
				 }
			   display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			    break;

			   case  'N':
		     for(i=0;i<=9;i++){
			   order_righ();
				 }
			  display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			   break;

			   case 'D':
			   reglaX();
		setviewport(55,335,584,448,1);
	bottonDw(245,70,BLACK,LIGHTGRAY,  "  W ");
			  sound(300);
			  delay(100);
	bottonUp(245,70,BLACK,LIGHTGRAY,  "  W ");
			  delay(100);
			  nosound();
			   break;

			   case 'R':
			  reglaY();
		setviewport(55,335,584,448,1);

	bottonDw(282,40,BLACK,LIGHTGRAY,  "  G ");
			  sound(300);
			  delay(100);
	bottonUp(282,40,BLACK,LIGHTGRAY,  "  G ");
			  delay(100);
			  nosound();
			   break;

			   case 'U':
			  regla_X();
		setviewport(55,335,584,448,1);
	bottonDw(245,10,BLACK,LIGHTGRAY,  "  P ");
			  sound(300);
			  delay(100);
	bottonUp(245,10,BLACK,LIGHTGRAY,  "  P ");
			  delay(100);
			  nosound();
			   break;
			   case 'L':
			   regla_Y();
		setviewport(55,335,584,448,1);
	bottonDw(210,40,BLACK,LIGHTGRAY,  "  F ");
			  sound(300);
			  delay(100);
	bottonUp(210,40,BLACK,LIGHTGRAY,  "  F ");
			  delay(100);
			  nosound();
			   break;

			   case 'P':
			   if(sw==1){
			      X1=x1;
			      Y1=y1;
			      sw=0;
				}
			   else{
			periodo=abs(x1-X1);
			  Hz=(10000/periodo);
			       sw=1;
		setviewport(55,335,584,448,1);
			gotoxy(10,23);
	      printf("periodo = %d ms  ",periodo);
			gotoxy(10,22);
	      printf("frec = %.2f Hz ",Hz);
				}
			   break;

			   case 'S':
		setviewport(55,335,584,448,1);
	bottonDw(250,40,RED,LIGHTGRAY,    " S ");
			  sound(500);
			  delay(900);
	bottonUp(250,40,RED,LIGHTGRAY,    " S ");
			 delay(1000);
			  nosound();
			   break;
			      }

  }while(OR!='S');

    return;
}
/**********************************DISPLAY****************************************/
void display(void)
{
int i=0,numy;
float vol;

	 setviewport(55,50,584,308,LIGHTBLUE);
		   clearviewport();
		      numy=255-y1;
		  vol=(numy*5.00)/255;
		     if(numy>=0){
		     gotoxy(59,24);
	   printf(" Yvol = %.2f  ",vol);
		     gotoxy(59,22);
	   printf(" Vpp  = %.2f  ",vpp);
			   }
		     if(x1>=0){
		     gotoxy(59,23);
	   printf(" Vmim = %.2f  ",vmin);
		     gotoxy(10,23);
	   printf("periodo = %d ms",periodo);
		     gotoxy(10,22);
	   printf("frec = %.2f Hz",Hz);
		     gotoxy(10,24);
	   printf("time  = %d   ",x1);
			   }
		  moveto(i,data[i]);

		 for(i=0;i<=528;i++){
		    setcolor(RED);
	  line(i,256-data[i],i+1,256-data[i+1]);
			    }

	return;

 }
/********************************ORDER_LEF*************************************/

void order_lef(void)
{
int i=0,temp;



		    temp=data[i];
		 for(i=0;i<=998;i++){
		    data[i]=data[i+1];
			    }
		    data[999]=temp;
}

/********************************ORDER_RIGH*************************************/

void order_righ(void)
{
int i=999,temp;



		    temp=data[i];
	       for(i=999;i>=1;i--){
		   data[i]=data[i-1];
			 }
		     data[0]=temp;

}
/********************************REGLA_X****************************************/


void reglaX(void)
{


	 setviewport(55,50,584,308,LIGHTBLUE);
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
		    if(y1>0 && y1<256){
			     y1++;
			 display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			      }
			else{
			     y1=0;
			  display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			    }


	 return;


 }
/***************************************REGLA_Y*******************************/

void reglaY(void)
{


	 setviewport(55,50,584,308,LIGHTBLUE);
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
		    if(x1>=0 && x1<=528){
			    x1++;
			 display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			      }
			else{
			     x1=0;
			  display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			    }

	 return;


 }

/********************************REGLA_X****************************************/


void regla_X(void)
{


	 setviewport(55,50,584,308,LIGHTBLUE);
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
		    if(y1>=0 && y1<=255){
			     y1--;
			 display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			      }
			else{
			     y1=255;
			  display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			    }


	 return;


 }

/***************************************REGLA_Y*******************************/

void regla_Y(void)
{


	 setviewport(55,50,584,308,LIGHTBLUE);
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
		    if(x1>=0 && x1<=528){
			    x1--;
			 display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			      }
			else{
			     x1=528;
			  display();
		       setcolor(CYAN);
		     line(2,y1,528,y1);
		     line(x1,0,x1,370);
		       circle(x1,y1,10);
			    }

	 return;


 }
/******************************************************************************/
 void volts(void)
 {
   int i;

		 vpp=data[i];
		 vmin=data[i];

	   for(i=0;i<=998;i++){
	      if(vpp<=data[i+1]){
		  vpp=data[i+1];
		      }
		if(vmin>=data[i+1]){
		   vmin=data[i+1];
		     }
		 }
	    vpp=(vpp*5.00)/255;
	   vmin=(vmin*5.00)/255;
 }

/***************************  Grafics **************************************/


void voltimetro(void)
{
int i=0,msb,lsb,byte;
char OR;
		      cleardevice();
	     windowUp(5,5,630,438,LIGHTBLUE);
	     windowDw(50,45,590,315,DARKGRAY);
	bottonUp(230,12,BLACK,LIGHTGRAY,    " << VOLTIMETRO >> ");
	bottonUp(230,12,RED,LIGHTGRAY,      " << V          >> ");
	bottonUp(250,322,BLACK,LIGHTGRAY,    " <<  TEST  >> ");
	bottonUp(250,322,RED,LIGHTGRAY,      " <<  T     >> ");
	bottonUp(265,360,BLACK,LIGHTGRAY,      "<< SALIR >>");
	bottonUp(265,360,RED,LIGHTGRAY,        "   S       ");

       do{

		    OR=toupper(getche());
			  switch(OR){
			   case 'T':
		setviewport(55,320,584,448,1);
	bottonDw(195,2,BLACK,LIGHTGRAY,        "<<   TEST  >> ");
			  sound(500);
			  delay(900);
	bottonUp(195,2,RED,LIGHTGRAY,          "     T        ");
			 delay(1000);
			  nosound();
		setviewport(55,55,584,311,1);
		     clearviewport();
		      moveto(0,255);

		for(i=0;i<=999;i++){
			outport(0x378,0x00);
			outport(0x378,0x07);
			outport(0x378,0x16);
			   delay(1);
			msb=inport(0x379);
			outportb(0x378,0x06);
			lsb=inport(0x379);
			msb=msb<<1;
			msb=msb&0xf0;
			lsb=lsb>>3;
			lsb=lsb&0x0f;
			byte=msb|lsb;
			byte=byte;
			data[i]=byte;
			setcolor(GREEN);
		     putpixel(i,255-byte,RED);
		      lineto(i,255-data[i]);
			      }
			   volts();
			gotoxy(35,18);
		  printf("voltage = %.2f",vpp);
			    break;

			   case 'S':
		setviewport(55,320,584,448,1);
	bottonDw(210,40,BLACK,LIGHTGRAY,      "<< SALIR >>");
			  sound(400);
			  delay(1000);
	bottonUp(210,40,RED,LIGHTGRAY,        "   S       ");
			  nosound();
			 delay(1000);
			   break;
			      }

  }while(!strchr("S",toupper(OR)));

    return;
}