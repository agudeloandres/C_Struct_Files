#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "c:\borlandc\bin\files\mouse.cpp"
#define ESC  0x1b

void marco(void);
void boton(int,int,int,int,int,int,int,int);
void rectangulo(int,int,int,int);
void Fondo(void);
void conv_text(int,int,char[]);
char menup(void);
void menuIS(void);
void menuVP(void);
void menuN(void);
void menuIP(void);
void menuIC(void);
void menuPU(void);
void menuA(void);
void menuT(void);
void menu_efec_efec(void);
void calcula_vp(void);
void calcula_vp2(void);
void calcula_vf(void);
void calcula_n(void);
void calcula_n2(void);
void calcula_t(void);
void calcula_t2(void);
void calcula_vp_PU(void);
void calcula_vf_PU(void);
void calcula_n_PU(void);
void calcula_t_PU(void);
void calcula_vp_A(void);
void calcula_vf_A(void);
void calcula_A_vp(void);
void calcula_A_vf(void);
void conv_nom_efec(void);
void conv_efec_nom(void);
void conv_nom_nom(void);
void conv_efecA_efecP(void);
void conv_efecP_efecA(void);
void creditos();
void Pause(void);
void presentacion(void);
void TextResaltado(int,int,char []);
void TextSombra(int,int,char []);
void DrawTable(int,int,int,int,int);
void Erase(int,int,int,int,int);
void barra_estado(int,int,int,int);
void barra_titulo(int,int,int,char []);
void marco_grabado(int,int,int,int);
float CuadroDato(int,int ,char *, char * );
void Box(int,int,int,int,char []);
void CajaDialogo(char [],float * ,float *);
void DibujeIcono(int,int,int*,int,int);
int * Network(void);
int * Network2(void);
int * Cerrar(void);


MOUSE mouse;
void main (){

int gdriver=0,gmode,opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,opc8,opc9;
char op,*op1=NULL,*op2=NULL,*op3=NULL,*op4=NULL,*op5=NULL,*op6=NULL,*op7=NULL,*op8=NULL,*op9=NULL,opcion;



initgraph(&gdriver,&gmode," ");
mouse.Inicializar(); //Inicializa Mouse
presentacion();
settextstyle(1,0,3);
setlinestyle(0,0,0);
menp:
Fondo();
mouse.Mostrar(); //Muestra Puntero del Mouse
mouse.AreaProtegida(199,170,400,350);
mouse.LimVert(15,getmaxx()-15); //Delimita los limites verticales en donde se mueve el mouse
mouse.LimHoriz(15,getmaxy()-18); //Delimita los limites Horizontales en donde se mueve el mouse

 op=menup();
    switch (op){
   case '1' : ini:
	      Fondo();
	      menuIS();
	      gets(op1);opc1=atoi(op1);
	       switch(opc1){

		  case 1 : vp:
			   Fondo();
			   menuVP();
			   gets(op7);opc7=atoi(op7);
			    switch(opc7){

			       case 1:
				       Fondo();
				       calcula_vp();
				       Pause();
				       goto vp;

			       case 2:
				       Fondo();
				       calcula_vp2();
				       Pause();
				       goto vp;

			       case 3:goto ini;
			       default:goto vp;
			      }//Fin switch opc7
		  case 2 :
			   Fondo();
			   calcula_vf();
			   Pause();
			   goto ini;

		   case 3 : N:
			    Fondo();
			    menuN();
			    gets(op8);opc8=atoi(op8);
			      switch(opc8){
				 case 1:
					 Fondo();
					 calcula_n();
					 Pause();
					 goto N;

				case 2:
					 Fondo();
					 calcula_n2();
					 Pause();
					 goto N;

				case 3:  goto ini;
				default :goto N;
			      }//Fin Switch opc8

		   case 4 : IP:
			    Fondo();
			    menuIP();
			    gets(op9);opc9=atoi(op9);
			      switch(opc9){

				 case 1:
					Fondo();
					calcula_t();
					Pause();
					goto IP;

				case 2 :
					 Fondo();
					 calcula_t2();
					 Pause();
					 goto IP;
				case 3: goto ini;
				default:goto IP;
			      } //Fin switch opc9


		  case 5 : goto menp;
		default:goto ini;
		}// Fin Switch interno

   case '2' : menIC:
	     Fondo();
	     menuIC();
	     gets(op2);opc2=atoi(op2);
	     switch (opc2){
	      case 1:PU:
		     Fondo();
		     menuPU();
		     gets(op3);opc3=atoi(op3);
		       switch (opc3){
			 case 1:
				 Fondo();
				 calcula_vp_PU();
				 Pause();
				 goto PU;

			 case 2:
				 Fondo();
				 calcula_vf_PU();
				 Pause();
				 goto PU;


			 case 3:
				Fondo();
				calcula_n_PU();
				Pause();
				goto PU;

			 case 4:
				Fondo();
				calcula_t_PU();
				Pause();
				goto PU;

			 case 5: goto menIC;
			 default:goto PU;
		      }//Fin switch interno



	      case 2:A:
		     Fondo();
		     menuA();
		     gets(op4);opc4=atoi(op4);
		     switch(opc4){
		      case 1:
			     Fondo();
			     calcula_vp_A();
			     Pause();
			     goto A;

		      case 2:
			      Fondo();
			      calcula_vf_A();
			      Pause();
			      goto A;

		       case 3:
			      Fondo();
			      calcula_A_vp();
			      Pause();
			      goto A;

		       case 4:
			      Fondo();
			      calcula_A_vf();
			      Pause();
			      goto A;


		       case 5:goto menIC;
		      default:goto A;
		     }//Fin del Switch interno

	      case 3:T:
		     Fondo();
		     menuT();
		     gets(op5);opc5=atoi(op5);
		       switch (opc5){
			case 1:
			       Fondo();
			       conv_nom_efec();
			       Pause();
			       goto T;

			case 2:
			       Fondo();
			       conv_efec_nom();
			       Pause();
			       goto T;


			case 3:
			       Fondo();
			       conv_nom_nom();
			       Pause();
			       goto T;



			case 4:efec:
			       Fondo();
			       menu_efec_efec();
			       gets(op6);opc6=atoi(op6);
				 switch(opc6){
				   case 1:
					   Fondo();
					   conv_efecA_efecP();
					   Pause();
					   goto efec;
				   case 2:
					   Fondo();
					   conv_efecP_efecA();
					   Pause();
					   goto efec;
				    case 3:goto T;
				    default:goto efec;

				  }//Fin switch opc6



			case 5:goto menIC;
			default:goto T;

		     }//Fin switch interno

	    case 4:goto menp;
	    default :goto menIC;

	    }//Fin switch Externo

    case '3':
    //************* VPN *******************//
	 float Tas,Period;
	 double Ing[15],Gast[15];
      //************CUADRO DE ENTRADA DE DATOS *****************//
       marco();
       Box(120,120,530,350,"Ingreso De Datos - Mac Software");
       Period=CuadroDato(370,175,"Digite Numero de Periodos","");
	Tas=CuadroDato(370,225,"Digite Tasa de Interes (%)","");
	conv_text(150,295,"NOTA: ");
	conv_text(150,310,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL");
	getch();cleardevice();
	//************************************************************//
	Fondo();settextstyle(1,0,3);conv_text(188,82,"GASTOS - INGRESOS");
	DrawTable(32,140,602,450,15);
	TextResaltado(12,140, "   PERIODOS");TextResaltado(240,140,"GASTOS");
	TextResaltado(435,140,"INGRESOS");


	float Ip,Ip1,SumaIngresos=0,SumaEgresos=0,VPN;
	Ip=(float)(Tas/100);
	Ip1 =(float)(1+Ip);


	for(int I=0;I<=Period;I++){
	gotoxy(12,12+I); printf("%d",I);
	gotoxy(31,12+I);scanf("%lf",&Gast[I]);
	gotoxy(59,12+I);scanf("%lf",&Ing[I]);
	}

	for(I=0;I<=Period;I++){
	SumaIngresos+=(float)(Ing[I]/pow(Ip1,I));
	SumaEgresos+=(float)(Gast[I]/pow(Ip1,I));
	}

	VPN=(float)(SumaIngresos-SumaEgresos);

	getch();Erase(32,140,610,460,1);

	TextSombra(150,230,"Valor Presente Neto = $");
	gotoxy(56,16);printf("%.4f",VPN);
	if (VPN==0)
	 TextSombra(210,270,"Es Indiferente");
	 else{
	VPN<0?TextSombra(190,270,"No es Rentable"):TextSombra(210,270,"Es Rentable");}
	getch();cleardevice();clearviewport();
	 //FIN
       goto menp;
    //************************************//

   case '4':closegraph();exit(0);restorecrtmode();system("cls");
   default:goto menp;

 } //Fin Switch principal

} //FIN


//**********************************FUNCIONES******************************//
//*************
void rectangulo(int x1,int y1,int x2,int y2)
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
void marco(){
  cleardevice();
  setbkcolor(BLUE);
  rectangulo(3,3,getmaxx()-3,getmaxy()-3);
  }
//***********
void boton(int x1,int y1,int x2,int y2,int c1,int c2,int c3,int N)
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
//*************
void conv_text(int x,int y , char N[]){
setcolor(8);
outtextxy(x,y,N);
setcolor(15);
outtextxy(x-2,y-2,N);
setcolor(1);
outtextxy(x-1,y-1,N);
setcolor(WHITE);
}
//*************
void Fondo(void){
//setbkcolor(BLACK);//Darle el Borde del Boton Negro
marco();
boton(90,70,500,120,8,15,7,5);}
//*************
void menuIS(void){
	      conv_text(220,82,"INTERES SIMPLE");
	      TextSombra(170,155, "1. Calcular Valor Presente");
	      TextSombra(170,195, "2. Calcular Valor Futuro");
	      TextSombra(170,235, "3. Calcular Numero de Periodos");
	      TextSombra(170,275, "4. Calcular Tasa de Interes");
	      TextSombra(170,315, "5. Retornar");
	      TextSombra(243,359, "Opcion [ ]");
	      gotoxy(43,24);
	      }
//***************
//*************
void menuVP(void){
conv_text(210,82,"VALOR PRESENTE");
TextSombra(160,180, "1. Valor Presente dado Interes");
TextSombra(160,230, "2. Valor Presente dado Valor Futuro");
TextSombra(160,280, "3. Retornar");
TextSombra(250,358, "Opcion [ ]");
gotoxy(44,24);
}
//***********************
void menuN(void){
conv_text(170,82,"NUMERO DE PERIODOS");
TextSombra(120,180, "1. Numero de Periodos dado Interes");
TextSombra(120,230, "2. Numero de Periodos dado Valor Futuro");
TextSombra(120,280, "3. Retornar");
TextSombra(250,358, "Opcion [ ]");
gotoxy(44,24);
}
//*************
void menuIP(void){
conv_text(200,82,"TASA DE INTERES");
TextSombra(150,180, "1. Tasa de Interes dado Interes");
TextSombra(150,230, "2. Tasa de Interes dado Valor Futuro");
TextSombra(150,280, "3. Retornar");
TextSombra(250,358, "Opcion [ ]");
gotoxy(44,24);
}
//*************
void calcula_vp(void){
			  float vp,i,t,n;
			  char *a;
			  int d;
			  conv_text(180,82,"Calculo Valor Presente");
			  TextSombra(175,162,"Digite El Interes : ");
			  gotoxy(50,12);printf("$ ");scanf("%f",&i);
			  TextSombra(175,225,"Digite La Tasa : ");
			  gotoxy(50,16);scanf("%f",&t);gotoxy(55,16);printf("%");
			  TextSombra(175,290,"Digite El Numero de Periodos : ");
			  gotoxy(69,20);scanf("%f",&n);
			  TextSombra(175,357,"El Valor Presente es : ");
			  vp=i/((t/100)*n);

			  gotoxy(58,24); printf("$ %.2f",vp);
			  //gcvt(vp,d,a);
			  //setcolor(YELLOW);
			  //TextSombra(429,357,"$");
			  //TextSombra(454,357,a);
			  setcolor(WHITE);
			  }
//********************
void calcula_vp2(void){
			  float vp,i,t,n,vf;
			  conv_text(180,82,"Calculo Valor Presente");
			  TextSombra(175,162,"Digite El Valor Futuro : ");
			  gotoxy(58,12);printf("$ ");scanf("%f",&vf);
			  TextSombra(175,225,"Digite La Tasa : ");
			  gotoxy(50,16);scanf("%f",&t);gotoxy(55,16);printf("%");
			  TextSombra(175,290,"Digite El Numero de Periodos : ");
			  gotoxy(69,20);scanf("%f",&n);
			  TextSombra(175,357,"El Valor Presente es : ");
			  vp=vf/(1+((t/100)*n));
			  gotoxy(58,24);printf("$ %.2f",vp);
			  }
//********************
void calcula_vf(void){
			   float vp,vf,t,n;
			   conv_text(180,82,"Calculo Valor Futuro");
			   TextSombra(170,162,"Digite Valor Presente : ");
			   gotoxy(56,12);printf("$ ");scanf("%f",&vp);
			   TextSombra(170,225,"Digite Tasa de Interes : ");
			   gotoxy(57,16);scanf("%f",&t);gotoxy(62,16);printf("%");
			   TextSombra(170,290,"Digite Numero de Periodos : ");
			   gotoxy(64,20);scanf("%f",&n);
			   TextSombra(170,355,"El valor Futuro es : ");
			   vf=vp*(1+((t/100)*n));
			   gotoxy(56,24);printf("$ %.2f",vf);
			   }
//***********************
void calcula_n (void){
			    float n,i,vp,t;
			    conv_text(138,82,"Calculo Numero de Periodos");
			    TextSombra(170,162,"Digite El Interes : ");
			    gotoxy(50,12);printf("$ ");scanf("%f",&i);
			    TextSombra(170,225,"Digite Tasa de Interes : ");
			    gotoxy(57,16);scanf("%f",&t);gotoxy(62,16);printf("%");
			    TextSombra(170,290,"Digite El Valor Presente : ");
			    gotoxy(62,20);printf("$ ");scanf("%f",&vp);
			    TextSombra(170,357,"El Numero de Periodos es : ");
			    n=i/(vp*(t/100));
			    gotoxy(64,24);printf("%.2f",n);
			    }
//********************
void calcula_n2 (void){
			    float n,i,vp,t,vf;
			    conv_text(138,82,"Calculo Numero de Periodos");
			    TextSombra(170,162,"Digite El Valor Futuro : ");
			    gotoxy(57,12);printf("$ ");scanf("%f",&vf);
			    TextSombra(170,225,"Digite Tasa de Interes : ");
			    gotoxy(57,16);scanf("%f",&t);gotoxy(62,16);printf("%");
			    TextSombra(170,290,"Digite El Valor Presente : ");
			    gotoxy(62,20);printf("$ ");scanf("%f",&vp);
			    TextSombra(170,357,"El Numero de Periodos es : ");
			    i=(vf/vp)-1;
			    n=i/(t/100);
			    gotoxy(64,24);printf("%.2f",n);
			    }
//********************
void calcula_t(void){
			    float i,vp,n,t;
			    conv_text(138,82,"Calculo Tasa de Interes");
			    TextSombra(170,162,"Digite El Interes : ");
			    gotoxy(50,12);printf("$ ");scanf("%f",&i);
			    TextSombra(170,225,"Digite El Valor Presente : ");
			    gotoxy(60,16);printf("$ ");scanf("%f",&vp);
			    TextSombra(170,290,"Digite El Numero de Periodos : ");
			    gotoxy(68,20);scanf("%f",&n);
			    TextSombra(170,357,"La tasa de Interes es : ");
			    t=(i/(vp*n))*100;
			    gotoxy(63,24);printf("%.2f %",t);
			    }
//************************
void calcula_t2(void){
			    float i,vp,n,t,vf;
			    conv_text(138,82,"Calculo Tasa de Interes");
			    TextSombra(170,162,"Digite El Valor Futuro :");
			    gotoxy(57,12);printf("$ ");scanf("%f",&vf);
			    TextSombra(170,225,"Digite El Valor Presente : ");
			    gotoxy(60,16);printf("$ ");scanf("%f",&vp);
			    TextSombra(170,290,"Digite El Numero de Periodos : ");
			    gotoxy(68,20);scanf("%f",&n);
			    TextSombra(170,357,"La tasa de Interes es : ");
			    i=(vf/vp)-1;
			    t=(i/n)*100;
			    gotoxy(63,24);printf("%.2f %",t);
			    }
//************************
void menuIC(void){
	      conv_text(190,82,"INTERES COMPUESTO");
	      TextSombra(170,155, "1. Pago Unico");
	      TextSombra(170,205, "2. Anualidades");
	      TextSombra(170,255, "3. Tasas");
	      TextSombra(170,305, "4. Retornar");
	      TextSombra(267,372, "Opcion [ ]");
	      gotoxy(46,25);
	      }
//*****************
void menuPU(void){
		     conv_text(220,82,"PAGO UNICO");
		     TextSombra(170,155, "1. Calcular Valor Presente");
		     TextSombra(170,195, "2. Calcular Valor Futuro");
		     TextSombra(170,235, "3. Calcular Numero de Periodos");
		     TextSombra(170,275, "4. Calcular Tasa de Interes");
		     TextSombra(170,315, "5. Retornar");
		     TextSombra(243,359, "Opcion [ ]");
		     gotoxy(43,24);
		     }
//*****************
void calcula_vp_PU(void){
				 float vp,i,t,n,vf;
				 double pot;
				 conv_text(180,82,"Calculo Valor Presente");
				 TextSombra(175,162,"Digite El Valor Futuro : ");
				 gotoxy(58,12);printf("$ ");scanf("%f",&vf);
				 TextSombra(175,225,"Digite La Tasa : ");
				 gotoxy(48,16);scanf("%f",&t);gotoxy(53,16);printf("%");
				 TextSombra(175,290,"Digite El Numero de Periodos : ");
				 gotoxy(69,20);scanf("%f",&n);
				 TextSombra(175,354,"El Valor Presente es : ");
				 pot=pow(1+(t/100),n);
				 vp=vf/pot;
				 gotoxy(58,24);printf("$ %.2f",vp);
				 }
//***********************
void calcula_vf_PU(void){
				 double pot;
				 float vf,vp,t,n;
				 conv_text(180,82,"Calculo Valor Futuro");
				 TextSombra(170,162,"Digite Valor Presente : ");
				 gotoxy(56,12);printf("$ ");scanf("%f",&vp);
				 TextSombra(170,225,"Digite Tasa de Interes : ");
				 gotoxy(57,16);scanf("%f",&t);gotoxy(62,16);printf("%");
				 TextSombra(170,290,"Digite Numero de Periodos : ");
				 gotoxy(64,20);scanf("%f",&n);
				 TextSombra(170,352,"El valor Futuro es : ");
				 pot=pow(1+(t/100),n);
				 vf=vp*pot;
				 gotoxy(56,24);printf("$ %.2f",vf);
				 }
//**********************
void calcula_n_PU(void){
				double n,vf,vp,t;
				conv_text(138,82,"Calculo Numero de Periodos");
				TextSombra(170,162,"Digite El Valor Futuro : ");
				gotoxy(58,12);printf("$ ");scanf("%lf",&vf);
				TextSombra(170,225,"Digite Tasa de Interes : ");
				gotoxy(57,16);scanf("%lf",&t);gotoxy(62,16);printf("%");
				TextSombra(170,290,"Digite El Valor Presente : ");
				gotoxy(61,20);printf("$ ");scanf("%lf",&vp);
				TextSombra(170,354,"El Numero de Periodos es : ");
				n=log(vf/vp)/log(1+(t/100));
				gotoxy(63,24);printf("%.2lf",n);
				}
//***********************
void calcula_t_PU(void){
				double vp,vf,n,pot,t;
				conv_text(155,82,"Calculo Tasa de Interes");
				TextSombra(170,162,"Digite El Valor Futuro : ");
				gotoxy(57,12);printf("$ ");scanf("%lf",&vf);
				TextSombra(170,225,"Digite El Valor Presente : ");
				gotoxy(60,16);printf("$ ");scanf("%lf",&vp);
				TextSombra(170,290,"Digite El Numero de Periodos : ");
				gotoxy(68,20);scanf("%lf",&n);
				TextSombra(170,354,"La tasa de Interes es : ");
				pot=pow(vf/vp,1/n);
				t=(pot-1)*100;
				gotoxy(57,24);printf("%.2lf %",t);
				}
//************************
void menuA(void){
		     conv_text(220,82,"ANUALIDADES");
		     TextSombra(170,155, "1. Calcular Valor Presente");
		     TextSombra(170,195, "2. Calcular Valor Futuro");
		     TextSombra(170,235, "3. Calcular Anualidad dado V.P.");
		     TextSombra(170,275, "4. Calcular Anualidad dado V.F.");
		     TextSombra(170,315, "5. Retornar");
		     TextSombra(243,359, "Opcion [ ]");
		     gotoxy(43,24);
		     }
//*******************
void calcula_vp_A(void){
			     double a,t,n,vp,pot,pot2;
			     conv_text(170,82,"Calculo Valor Presente");
			     TextSombra(175,162,"Digite La Anualidad : ");
			     gotoxy(55,12);printf("$ ");scanf("%lf",&a);
			     TextSombra(175,227,"Digite La Tasa : ");
			     gotoxy(48,16);scanf("%lf",&t);gotoxy(53,16);printf("%");
			     TextSombra(175,290,"Digite El Numero de Periodos : ");
			     gotoxy(69,20);scanf("%lf",&n);
			     TextSombra(175,355,"El Valor Presente es : ");
			     pot=(pow(1+(t/100),n))-1;
			     pot2=(pow(1+(t/100),n))*(t/100);
			     vp=a*(pot/pot2);
			     gotoxy(56,24);printf("$ %.2lf",vp);
			     }
//**********************
void calcula_vf_A(void){
			      double a,t,n,pot,vf;
			      conv_text(180,82,"Calculo Valor Futuro");
			      TextSombra(170,162,"Digite La Anualidad : ");
			      gotoxy(54,12);printf("$ ");scanf("%lf",&a);
			      TextSombra(170,227,"Digite Tasa de Interes : ");
			      gotoxy(57,16);scanf("%lf",&t);gotoxy(62,16);printf("%");
			      TextSombra(170,290,"Digite Numero de Periodos : ");
			      gotoxy(64,20);scanf("%lf",&n);
			      TextSombra(170,356,"El valor Futuro es : ");
			      pot=(pow(1+(t/100),n))-1;
			      vf=a*(pot/(t/100));
			      gotoxy(53,24);printf("$ %.2lf",vf);
			      }
//************************
void calcula_A_vp(void){
			      double vp,t,n,pot,pot2,a;
			      conv_text(142,82,"Calculo Anualidad dado V.P.");
			      TextSombra(175,162,"Digite El Valor Presente : ");
			      gotoxy(62,12);printf("$ ");scanf("%lf",&vp);
			      TextSombra(175,227,"Digite La Tasa : ");
			      gotoxy(48,16);scanf("%lf",&t);gotoxy(53,16);printf("%");
			      TextSombra(175,290,"Digite El Numero de Periodos : ");
			      gotoxy(69,20);scanf("%lf",&n);
			      TextSombra(175,354,"La Anualidad es : ");
			      pot=(pow(1+(t/100),n))-1;
			      pot2=(pow(1+(t/100),n))*(t/100);
			      a=vp*(pot2/pot);
			      gotoxy(50,24);printf("$ %.2lf",a);
			      }
//*******************
void calcula_A_vf(void){
			      double vf,t,n,a,pot;
			      conv_text(142,82,"Calculo Anualidad dado V.F.");
			      TextSombra(175,162,"Digite Valor Futuro : ");
			      gotoxy(55,12);printf("$ ");scanf("%lf",&vf);
			      TextSombra(175,227,"Digite La Tasa : ");
			      gotoxy(48,16);scanf("%lf",&t);gotoxy(53,16);printf("%");
			      TextSombra(175,290,"Digite El Numero de Periodos : ");
			      gotoxy(69,20);scanf("%lf",&n);
			      TextSombra(175,355,"La Anualidad es : ");
			      pot=(pow(1+(t/100),n))-1;
			      a=vf*((t/100)/pot);
			      gotoxy(50,24);printf("$ %.2lf",a);
			      }
//*****************
void menuT(void){
		     conv_text(270,82,"TASAS");
		     TextSombra(155,160, "1. Convertir Nominal a Efectiva");
		     TextSombra(155,200, "2. Convertir Efectiva a Nominal");
		     TextSombra(155,240, "3. Convertir Nominal a Nominal");
		     TextSombra(155,280, "4. Convertir Efectiva a Efectiva");
		     TextSombra(155,320, "5. Retornar");
		     TextSombra(250,375, "Opcion [ ]");
		     gotoxy(44,25);
		     }
//*******************
void conv_nom_efec (void){
			       double j,m,ip,pot,ia;
			       conv_text(145,82,"Conv. Nominal-Efectiva");
			       TextSombra(135,163,"Digite La Tasa Nominal : ");
			       gotoxy(55,12);scanf("%lf",&j);gotoxy(60,12);printf("%");
			       TextSombra(135,227,"Digite Numero de Periodos : ");
			       gotoxy(59,16);scanf("%lf",&m);
			       TextSombra(135,292,"La Tasa Efectiva Periodica es : ");
			       ip=((j/100)/m)*100;gotoxy(63,20);printf("%.2lf %",ip);
			       TextSombra(135,355,"La Tasa Efectiva Anual es : ");
			       pot=pow(1+((j/100)/m),m);
			       ia=(pot-1)*100;
			       gotoxy(60,24);printf("%.2lf %",ia);
			       }
//***********************
void conv_efec_nom (void){
			       double ip,m,j,pot;
			       conv_text(145,82,"Conv. Efectiva-Nominal");
			       TextSombra(25,163,"Digite La Tasa Efectiva : ");
			       gotoxy(41,12);scanf("%lf",&ip);gotoxy(46,12);printf("%");
			       TextSombra(25,227,"Digite Numero de Periodos : ");
			       gotoxy(47,16);scanf("%lf",&m);
			       TextSombra(25,292,"La Tasa Nominal Anual (Efectiva Periodica) : ");
			       j=((ip/100)*m)*100;gotoxy(69,20);printf("%.2lf %",j);
			       TextSombra(25,355,"La Tasa Nominal Anual (Efectiva Anual) : ");
			       pot=(pow(1+(ip/100),1/m))-1;
			       j=(m*pot)*100;
			       gotoxy(65,24);printf("%.2lf %",j);
			       }
//***********************
void conv_nom_nom (void){
			       double j,m,pot,ia,m2;
			       conv_text(145,82,"Conv. Nominal-Nominal");
			       TextSombra(135,163,"Digite La Tasa Nominal : ");
			       gotoxy(55,12);scanf("%lf",&j);gotoxy(60,12);printf("%");
			       TextSombra(135,227,"Digite Numero de Periodos : ");
			       gotoxy(61,16);scanf("%lf",&m);
			       pot=pow(1+((j/100)/m),m);
			       ia=(pot-1)*100;
			       TextSombra(135,292,"Digite Numero de Periodos : ");
			       gotoxy(61,20);scanf("%lf",&m2);
			       TextSombra(135,355,"La Tasa Nominal Anual : ");
			       pot=(pow(1+(ia/100),1/m2))-1;
			       j=(m2*pot)*100;
			       gotoxy(58,24);printf("%.2lf %",j);
			       }

//**********************
void menu_efec_efec(void){
			       conv_text(145,82,"Conv. Efectiva-Efectiva");
			       TextSombra(100,180, "1. Efectiva Anual a Efectiva Periodica");
			       TextSombra(100,230, "2. Efectiva Periodica a Efectiva Anual");
			       TextSombra(100,280, "3. Retornar");
			       TextSombra(250,358, "Opcion [ ]");
			       gotoxy(44,24);
			       }
//**********************
void conv_efecA_efecP(void){
					   double i,m,j,pot,ip;
					   conv_text(110,82,"Efectiva Anual-Efectiva Periodica");
					   TextSombra(135,163,"Digite La Tasa Efectiva : ");
					   gotoxy(54,12);scanf("%lf",&i);gotoxy(59,12);printf("%");
					   TextSombra(135,227,"Digite Numero de Periodos : ");
					   gotoxy(60,16);scanf("%lf",&m);
					   TextSombra(135,292,"La Tasa Efectiva Periodica es : ");
					   pot=(pow(1+(i/100),1/m))-1;
					   j=(m*pot)*100;
					   ip=((j/100)/m)*100;
					   gotoxy(63,20);printf("%.2lf %",ip);
					   }
//**********************
void conv_efecP_efecA(void){
					   double i,m,j2,pot2,ia;
					   conv_text(110,82,"Efectiva Periodica-Efectiva Anual");
					   TextSombra(135,163,"Digite La Tasa Efectiva : ");
					   gotoxy(54,12);scanf("%lf",&i);gotoxy(59,12);printf("%");
					   TextSombra(135,227,"Digite Numero de Periodos : ");
					   gotoxy(60,16);scanf("%lf",&m);
					   TextSombra(135,292,"La Tasa Efectiva Anual es : ");
					   j2=((i/100)*m)*100;
					   pot2=pow(1+((j2/100)/m),m);
					   ia=(pot2-1)*100;
					   gotoxy(60,20);printf("%.2lf %",ia);
					   }

//**********************
void marco_grabado(int x1,int y1,int x2,int y2){
  setcolor(8);
  rectangle(x1,y1,x2,y2);
  setcolor(15);
  line(x1+1,y1+1,x2-1,y1+1);line(x1+1,y1+1,x1+1,y2-1);
  line(x1,y2+1,x2+1,y2+1);line(x2+1,y2+1,x2+1,y1+1);
  }
//***************
void marco_Barra(int x1,int y1,int x2,int y2){
  setlinestyle(0,0,2);setcolor(15);rectangle(x1,y1,x2,y2);
  setlinestyle(0,0,2);setcolor(8);
  line(x1+2,y1+2,x1+2,y2-1);line(x1,y2+2,x2+2,y2+2);
  line(x2+2,y2+1,x2+2,y1);line(x1+2,y1+2,x2-2,y1+2);
  /*line(x1+2,y1+2,x2-2,y1+2);line(x1+2,y1+2,x1+2,y2-2);
  line(x1,y2+2,x2+2,y2+2);line(x2+2,y2+2,x2+2,y1+2);*/
  }
//***************
void Line3D(int x1,int y1, int x2, int y2){
  setlinestyle(0,0,1);setcolor(8);
  line(x1,y1,x2,y2);
  setlinestyle(0,0,1);setcolor(15);
  line(x1,y1+1,x2,y1+1);
}
//*************
void LineBar(int x1, int y1, int x2, int y2){
setlinestyle(0,0,2);setcolor(15);line(x1,y1,x2,y2);
setlinestyle(0,0,2);setcolor(8);line(x1,y1+2,x2,y2+2);
}
//*************
void TextResaltado(int X ,int Y,char Texto [] ){
setcolor(1);
outtextxy(X+1,Y+1,Texto);
setcolor(3);
outtextxy(X,Y,Texto);
setcolor(1);
outtextxy(X-1,Y-1,Texto);
setcolor(15);
}
//*******************
void TextSombra(int x,int y, char text []){
setcolor(7);
outtextxy(x+1,y+1,text);
setcolor(0);
outtextxy(x,y,text);
setcolor(15);
outtextxy(x-1,y-1,text);
}

//*******************
void DrawTable( int left, int top,int right, int bottom, int Color){
setfillstyle(1,Color);setcolor(Color);
bar(left,top,right+1,bottom-281);setlinestyle(0,1,3);
rectangle(left+1,top+30,right,bottom);
//Columns
line(left+148,top+30,left+148,bottom);
line(right-212,top+30,right-212,bottom);
}
//*******************
void Erase( int left, int top,int right, int bottom, int Color){
setfillstyle(1,Color);bar(left,top,right,bottom);}
//*************************
void barra_estado(int x1,int y1,int x2,int y2){
setcolor(BLACK);line(x1,y1,x2,y1);line(x1,y2,x1,y1);setcolor(8);line(x1-1,y1-1,x2-1,y1-1);line(x1-1,y2,x1-1,y1);
setcolor(WHITE);line(x2,y1,x2,y2);line(x2,y2,x1,y2);
//line(x2+1,y1,x2+1,y2);line(x2,y2+1,x1,y2+1);
}
//***********************
 void barra_titulo(int x1,int y1, int x2,char N []){
 setfillstyle(1,1);bar(x1,y1,x2,y1+18);
 setcolor(15);settextstyle(0,0,0);outtextxy(x1+26,y1+5,N);
 }
//***********************

//**********************
float CuadroDato(int posX,int Posy,char *Mensaje, char *Mens )
{
 int Posx=posX;
 setcolor(0);

 conv_text(Posx-220,Posy+12,Mensaje);
 conv_text(413,Posy+12,Mens);
 setbkcolor(0);
 setcolor(0);
 line(Posx,Posy,Posx,Posy+26);
 line(Posx,Posy-1,Posx+100,Posy-1);
 setcolor(15);
 line(Posx,Posy+26,Posx+100,Posy+26);
 line(Posx+100,Posy-1,Posx+100,Posy+26);
 char Numero,Cadena[12];
 int Pos=0;
 do
 {
 Numero=getch();
 if(Numero==8) // Si Presiona BackSpace para borrar
  {
   setcolor(7);
   outtextxy(Posx+2,Posy+5,Cadena);  //Escribe el numero del mismo color Gris
   Pos=Pos>0?Pos-1:0;               //Borra el Ultimo Digito del Vector
   Cadena[Pos]='\0';               //Le asigna Un espacio en Blanco
  }
 if(strchr("0123456789.-",Numero)) //Verifica que se inserto un Numero y
  {                                // No un Caracter Alfabetico
   Cadena[Pos]=Numero;             //Inserta en la posicion actual el Numero
   Pos=Pos<11?Pos+1:11;            //Aumenta en uno el tama¤o del vector
  }                                // Maximo 11 digitos
 Cadena[Pos]='\0';                 //Le asigna un espacio en blanco al ultimo
 setcolor(15);                     //Nodo aumentado que no vale nada
 outtextxy(Posx+2,Posy+5,Cadena);   //Escribe el numero en color blanco
 }while(Numero!=13);  //Realiza el ciclo mientras no se presione ENTER
// *Posicion=*Posicion+1; //Incrementa Posicion
return atof(Cadena);
}
//**************************
void Box(int x,int y,int x1,int y1,char Titulo []){
boton(x,y,x1,y1,8,15,7,5);marco_grabado(x+10,y+28,x1-10,y1-10);
barra_titulo(x+2,y+2,x1-1,Titulo);DibujeIcono(x+7,y+3,Network2(),16,16);
boton(x1-17,y+5,x1-5,y+17,8,15,7,1);DibujeIcono(x1-15,y+7,Cerrar(),9,9);
}
//**************************


//**********************
void autores(void){
marco();
setbkcolor(0);
boton(30,20,610,460,8,15,7,3);
boton(45,35,595,445,8,15,7,3);
boton(204,52,444,69,8,15,7,3);
setlinestyle(0,0,2);

marco_grabado(52,42,588,438);
//marco_Barra(52,42,588,438);

settextstyle(0,0,1);
conv_text(267,59," HACKERZ.COM ");
settextstyle(7,0,2);
conv_text(80,90,"  Software realizado por los estudiantes :");
conv_text(110,140,"    * CARLOS ANDRES AGUDELO SERNA ");
conv_text(110,180,"    * KAROLE  CIFUENTES JIMENEZ ");
//settextstyle(7,0,2);
conv_text(34,225,"    Presentado al Profesor: LIC. ALVARO NAVARRO");
settextstyle(1,0,9);
 setbkcolor(0);
 boton(165,279,460,410,8,15,7,3);
 DibujeIcono(410,356,Network(),16,16);
 conv_text(190,260,"H");
 conv_text(218,305,"S");
 settextstyle(1,0,4);
 conv_text(253,301,"ACKERZ");
 conv_text(263,345,"OFTWARE");
  settextstyle(0,0,1);
 conv_text(265,394,"HACKERZ Corporation 2000");

  getch();

settextstyle(1,0,3);
}
//**********************
void creditos(void){
    setbkcolor(0); //Para darle el borde de color negro
    boton(450,430,550,450,8,15,7,3);
    settextstyle(7,0,1);
    conv_text(465,429,"Creditos ");
    setcolor(RED);
    outtextxy(465,428,"C");
    //outtextxy(464,427,"_");

    settextstyle(1,0,3);
 }
//*************
void press_credits(void){
printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
       boton(450,430,550,450,15,8,7,3);
       settextstyle(7,0,1);
       setcolor(BLUE);
       conv_text(465,429,"Creditos ");
       setcolor(RED);
       outtextxy(465,429,"C");
       //outtextxy(465,429,"_");
       delay(330);
       autores();

  }
//*************
char menup(void){
char opcion;
int Boton_Creditos,Vert,Horiz,x,y;
//Boton_Creditos=0;
Fondo();
conv_text(210,82,"MENU PRINCIPAL");
TextSombra(200,170, "1. Interes Simple");
TextSombra(200,220, "2. Interes Compuesto");
TextSombra(200,270, "3. Valor Presente Neto (VPN)");
TextSombra(200,320, "4. Salir");
TextSombra(250,398, "Opcion [ ]");
gotoxy(44,24);
creditos();

/*while ( (Boton_Creditos=mouse.Estado(&Vert,&Horiz) ) ==0){
  Boton_Creditos = mouse.Estado(&Vert,&Horiz);
   /*x = Vert;
   y = Horiz;*/

   /*if(kbhit()){
      getch();*/

     /*if ( (Boton_Creditos) == IZQUIERDO)
     {
      if (Vert >= 450 && Vert <= 550 && Horiz >=430 && Horiz <=450){
      mouse.Esconder();
      press_credits();
      mouse.Mostrar();
      //mouse.LibBotones();
     }
      //mouse.LibBotones();
     }
      //mouse.LibBotones();
     } */

opcion=getche();
if (toupper(opcion) =='C'){
mouse.Esconder();
press_credits();
return 0;
}
else return opcion;
} // Fin Funcion
//**********************
void Pause(void)
{
  int c;
  c = getch();
  if( ESC == c ){
    closegraph();
    exit( 1 );
  }

  if( 0 == c ){
    c = getch();
  }
  cleardevice();
}
//*******************
void presentacion(void)
{
 int i,x;
 setbkcolor(0);
 rectangulo(160,30,490,420);
 rectangulo(170,40,480,410);
  boton(180,50,470,400,8,15,7,2);
  boton(204,70,444,87,8,15,7,3);

  marco_grabado(190,60,460,390);
  setcolor(15);
  rectangle(190,60,460,390);
  setcolor(BLUE);
  rectangle(191,61,459,389);
  setcolor(DARKGRAY);
  rectangle(189,59,461,391);

 settextstyle(0,0,1);
 conv_text(267,77," HACKERZ.COM ");

 boton(204,107,444,377,8,15,7,3);
 settextstyle(1,0,9);
 conv_text(225,90,"H");
 conv_text(253,135,"S");
 settextstyle(1,0,4);
 conv_text(285,131,"ACKERZ");
 conv_text(298,180,"OFTWARE");
 settextstyle(3,0,1);
 Line3D(215,245,435,245);
 //LineBar(215,260,435,260);
 conv_text(214,262,"CALCULADORA FINANCIERA");
 conv_text(275,293,"Version 2.1");
 settextstyle(0,0,1);
 conv_text(215,337,"Copyright HACKERZ Corp.98-99");
 conv_text(249,356,"All Rights Reserved");
 getch();
 //delay(3500);

}
//*********************************************
int * Network(void){
 #define w 15  //White
 #define g 10  //LightGreen
 #define c 11  //LightCyan
 #define a 14  //Yellow
 #define R 12  //LightRed
 #define M 13  //LightMagenta

 static int Net[16][16]={
 7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,
 8,w,w,w,w,w,w,w,0,7,7,7,7,7,7,7,
 8,w,0,0,0,0,1,w,0,7,7,7,7,7,7,7,
 8,w,0,c,9,9,1,w,0,7,7,7,7,7,7,7,
 8,w,0,9,9,9,1,w,0,7,7,7,7,7,7,7,
 8,w,1,1,1,1,1,8,8,8,8,8,8,8,8,7,
 8,7,7,7,7,7,8,w,w,w,w,w,w,w,0,7,
 8,0,0,0,0,0,8,w,0,0,0,0,0,7,0,7,
 8,w,w,w,w,w,8,w,0,c,2,2,8,7,0,7,
 8,7,g,8,8,8,8,w,0,2,2,2,8,7,0,7,
 7,0,0,0,0,0,8,w,0,8,8,8,8,7,0,7,
 7,7,8,0,7,7,8,7,7,7,7,7,7,7,0,7,
 7,7,8,0,7,7,8,0,0,0,0,0,0,0,8,0,
 8,8,a,6,0,8,8,w,w,w,w,w,w,w,8,0,
 0,0,a,6,0,0,8,7,g,8,8,8,8,8,8,0,
 7,7,0,0,7,7,7,0,0,0,0,0,0,0,0,7,
 };
 return (int *) Net;
 }
//*****************************
//*********************
int * Cerrar(void){
 static int Cer [9][9]={
  0,0,7,7,7,7,7,0,0,
  7,0,0,7,7,7,0,0,7,
  7,7,0,0,7,0,0,7,7,
  7,7,7,0,0,0,7,7,7,
  7,7,7,0,0,0,7,7,7,
  7,7,0,0,7,0,0,7,7,
  7,0,0,7,7,7,0,0,7,
  0,0,7,7,7,7,7,0,0,
  7,7,7,7,7,7,7,7,7,
  };
  return (int *) Cer;
  }
//*********************
//**************************

int * Network2(void){
 #define w 15
 #define g 10
 #define a 14
 #define c 11
  static int Net[16][16]={
 1,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1,
 8,w,w,w,w,w,w,w,0,1,1,1,1,1,1,1,
 8,w,0,0,0,0,1,w,0,1,1,1,1,1,1,1,
 8,w,0,c,9,9,1,w,0,1,1,1,1,1,1,1,
 8,w,0,9,9,9,1,w,0,1,1,1,1,1,1,1,
 8,w,1,1,1,1,1,8,8,8,8,8,8,8,8,1,
 8,7,7,7,7,7,8,w,w,w,w,w,w,w,0,1,
 8,0,0,0,0,0,8,w,0,0,0,0,0,7,0,1,
 8,w,w,w,w,w,8,w,0,c,2,2,8,7,0,1,
 8,7,g,8,8,8,8,w,0,2,2,2,8,7,0,1,
 1,0,0,0,0,0,8,w,0,8,8,8,8,7,0,1,
 1,1,8,0,1,1,8,7,7,7,7,7,7,7,0,1,
 1,1,8,0,1,1,8,0,0,0,0,0,0,0,8,0,
 8,8,a,6,0,8,8,w,w,w,w,w,w,w,8,0,
 0,0,a,6,0,0,8,7,g,8,8,8,8,8,8,0,
 1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,
 };
 return (int *) Net;
 }
//*********************
void DibujeIcono(int x,int y, int *BitMap,int NumFila,int NumColumna)
 { for(int i=0;i<NumFila;i++)
     for(int j=0;j<NumColumna;j++)
      putpixel(x+j,y+i,*(BitMap++));
 }