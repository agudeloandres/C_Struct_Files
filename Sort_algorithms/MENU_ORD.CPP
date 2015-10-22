#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "string.h"
#include "ctype.h"
#include "process.h"
#define CPR(x) cprintf("%s",x)

char *op[]={
      "        INGRESO DE DATOS        ",
      "   ORDENAMIENTO POR INSERCION   ",
      "   ORDENAMIENTO POR SELECCION   ",
      "    ORDENAMIENTO POR BURBUJA    ",
      "       SALIR DEL PROGRAMA       "
      };


typedef struct estudiantes{
	float codigo;
	char nombre[30];
	};


void choice();
void Ingreso();
void Insercion();
void Seleccion();
void Burbuja();

void piso_color(int,int);
void marco (int,int,int,int);
void persiana(int);

estudiantes alumnos[30],temp,menor;
int lo,k,j,n,n1,i,tem,c;
float cod;
char nom[30],opcion;
unsigned int sw,aw;


void  main(){
 int i,j;

 ini:
 _setcursortype(_NOCURSOR);

 piso_color(BLACK,WHITE);
 clrscr();
 marco(2,2,75,23);
 textbackground(BLUE);textcolor(WHITE);
 gotoxy(25,2);cprintf(" MENU DE ORDENAMIENTO ");

 textbackground(BLACK);textcolor(WHITE);
 for (i=0;i<5;i++){
  gotoxy (20,2*i+7);
  CPR(op[i]);
  }


  piso_color(WHITE,BLACK);
  gotoxy(20,7);
  CPR(op[0]);
  gotoxy(20,7);

  c=getch();
  choice();
  while (c==0){
      c=getch();
	 persiana(c);
      c=getch();
     choice();
 } // FIN WHILE

     goto ini;

} //FIN MAIN

 //************************ FUNCIONES *******************************//
//********************************
void piso_color(int piso,int color){
   textbackground(piso);
   textcolor(color);
   }

//********************************
void marco (int a,int b,int c, int d){
#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205
#define PR(x) cprintf("%c",x)
 int i;
 window(1,1,80,25);       //Activa la ventana mayor para dibujar el marco
 gotoxy(a-1,b-1);
 PR(arrizq);
 for (i=a;i<=c;i++)
     PR(horiz);
 PR(arrder);
 for(i=b;i<=d;i++){
   gotoxy(c+1,i);
   PR(vert);
 }
 gotoxy(a-1,d+1);
 PR(abajizq);
 for(i=a;i<=c;i++)
   PR(horiz);
   PR(abajder);
   for(i=b;i<=d;i++){
    gotoxy(a-1,i);
    PR(vert);
    }
    window(a,b,c,d);             //Activa ventana dentro del marco
  }

//**********************
//************************
void Ingreso(void){
sw=0;
piso_color(BLACK,WHITE);
marco(2,2,75,23);
_setcursortype(_SOLIDCURSOR);
clrscr();
	 sw=1;
	  clrscr ();
	  gotoxy(20,10);
	  printf("DIGITE EL NUMERO DE ESTUDIANTES: \t");
	  do{

	     scanf("%d",&n);
	     }while(n<0);
	  for (j=1;j<=n;j++){
	      clrscr();
	      gotoxy(8,7);
	      printf("DIGITE EL CODIGO DEL ESTUDIANTE: \t");
	      scanf("%f",&cod);
	      alumnos[j].codigo=cod;
	      gotoxy(8,15);
	      printf("\DIGITE EL NOMBRE DEL ESTUDIANTE: \t");
	      cin.getline(nom,30);
	      lo=strlen(nom);
	      for(k=0;k<=lo;k++){
		 alumnos[j].nombre[k]=nom[k];

		 }
		strupr(alumnos[j].nombre);

	      }
	    _setcursortype(_NOCURSOR);
	   }
//***********************
void Insercion(void){

piso_color(BLACK,WHITE);
marco(2,2,75,23);
clrscr();

		   for(i=2;i<=n;i++){
		   j=i-1;
		   menor=alumnos[i];
		   while(strcmp(menor.nombre,alumnos[j].nombre)<0&&(j>0)){
		   alumnos[j+1]=alumnos[j];
		   j=j-1;
		   }
		   alumnos[j+1]=menor;
		   }
		   gotoxy(wherex()+2,wherey());
		   printf("CODIGO          NOMBRE \n");
		   for(i=1;i<=n;i++){
		   gotoxy(wherex()+2,wherey()+1);
		   printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
		   }
		   getch();
		   }

//*******************
void Seleccion (void){

piso_color(BLACK,WHITE);
marco(2,2,75,23);
clrscr();

		      for(i=1;i<=n-1;i++){
		      menor=alumnos[i];
		      tem=i;
		      for(j=i+1;j<=n;j++){
		     if(strcmp(menor.nombre,alumnos[j].nombre)>0){
			menor=alumnos[j];
			tem=j;
			}
			}
			alumnos[tem]=alumnos[i];
			alumnos[i]=menor;
			}
			printf("CODIGO         NOMBRE \n");
			for(i=1;i<=n;i++){
			gotoxy(wherex()+2,wherey()+1);
			printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
			}
		   getch();
		}
//***********************
void Burbuja(void){

piso_color(BLACK,WHITE);
marco(2,2,75,23);
clrscr();

		   n1=n-1;
		   aw=0;
		   while(aw==0){
		   j=2;
		   aw=1;
		   for(i=1;i<=n1;i++){
		   if(strcmp(alumnos[i].nombre,alumnos[j].nombre)>0){
		   temp=alumnos[i];
		   alumnos[i]=alumnos[j];
		   alumnos[j]=temp;
		   aw=0;
		  } // Fin if
		  j++;
		  } // Fin for
		  n1=n1-1;
		  }// fin While
		   printf("CODIGO         NOMBRE \n");
		   for(i=1;i<=n;i++){
		   gotoxy(wherex()+2,wherey()+1);
		   printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
		   }
		getch();
	   }

//***********************
void choice(void){
if(c==13 && wherey()==7)
    Ingreso();                  //LA TECLA ENTER VALE 13
    else
     if (c==13 && wherey()==9)
	Insercion();
     else
       if (c==13 && wherey()==11)
	 Seleccion();
     else
       if(c==13 && wherey()==13)
	Burbuja();
     else
      if (c==13 && wherey()==15){
	piso_color(0,15);clrscr();exit(0);}
 }
 //********************************
 void persiana(int c){
 switch(c){
	     case 80:switch(wherey()){
			 case 7:
				piso_color(BLACK,WHITE);
				CPR(op[0]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[1]);
				gotoxy(20,wherey());
				break;

			case 9:
				piso_color(BLACK,WHITE);
				CPR(op[1]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[2]);
				gotoxy(20,wherey());
				break;

			case 11:
				piso_color(BLACK,WHITE);
				CPR(op[2]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[3]);
				gotoxy(20,wherey());
				break;

			case 13:
				piso_color(BLACK,WHITE);
				CPR(op[3]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[4]);
				gotoxy(20,wherey());
				break;
			case 15:

				piso_color(BLACK,WHITE);
				CPR(op[4]);
				piso_color(WHITE,BLACK);
				gotoxy(20,7);
				CPR(op[0]);
				gotoxy(20,wherey());
				break;

			} //FIN SWITCH WHEREY()

		     break;


	     case 72:switch(wherey()){
			case 7:
			      piso_color(BLACK,WHITE);
			      CPR(op[0]);
			      piso_color(WHITE,BLACK);
			      gotoxy(20,15);
			      CPR(op[4]);
			      gotoxy(20,wherey());
			      break;
		       case 9:
			      piso_color(BLACK,WHITE);
			      CPR(op[1]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[0]);
			      gotoxy(20,wherey());
			      break;
		      case 11:
			      piso_color(BLACK,WHITE);
			      CPR(op[2]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[1]);
			      gotoxy(20,wherey());
			      break;
		      case 13:
			      piso_color(BLACK,WHITE);
			      CPR(op[3]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[2]);
			      gotoxy(20,wherey());
			      break;
		      case 15 :
			      piso_color(BLACK,WHITE);
			      CPR(op[4]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[3]);
			      gotoxy(20,wherey());
			      break;

			}//FIN SWITCH WHEREY()
		      break;

	      default:break;


     } //FIN SWITCH PRINCIPAL
 }