
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<C:\BORLANDC\BIN\DINAMI~1\PILAMEN.H>

//programa para manejo de pila lls

void main()
{
char opc;
unsigned int sw;
pila *Tope,*Base,*Max,*Li;
int n;
float Inf;

//creacion del menu
sw=0;
textcolor(15);
do{
  clrscr();
    gotoxy(20,2);
    printf (" UNIVERSIDAD COOPERATIVA DE COLOMBIA");
    gotoxy(26,3);
    printf (" ESTRUCTURA DE DATOS I");
    gotoxy(33,4);
    printf (" PILAS");

  gotoxy(25,7);
  printf("M E N U  P R I N C I P A L");
  gotoxy(18,9);
  printf("1---- Crear Pila");
  gotoxy(18,11);
  printf("2---- Insertar Nodo(Push)en la pila");
  gotoxy(18,13);
  printf("3---- Cancelar Nodo (Pop)en la pila");
  gotoxy(18,15);
  printf("4---- Mostrar Pila");
  gotoxy(18,17);
  printf("5---- Salir");
  gotoxy(28,20);
  printf("Digite Opcion: ");
  do{
    opc=getchar();
  }while(opc<'0' && opc<'5');
  switch(opc){

     case '1':if(sw==0){
		sw=1;
		clrscr();
		//definicion de espacio disponible
		printf("Digite el maximo numero de nodos de la Pila: ");
		do{
		  scanf("%d",&n);
		}while(n<=0);
		crear_pila(&Base,&Tope,n);
		Max=Maximo(Base,n);
		printf("\n    Base  = %04x : %04x",FP_SEG(Base),FP_OFF(Base));
		printf("\n    Tope  = %04x : %04x",FP_SEG(Tope),FP_OFF(Tope));
		printf("\n    Maximo= %04x : %04x",FP_SEG(Max),FP_OFF(Max));
		printf("\n (0 y ENTER ) Para Continua: ");
		do{
		  opc=getchar();
		}while(opc!='0');
	       }
	       else{
		 clrscr();
		 printf("Pila ya creada..[ 0 y ENTER ] Para Continuar: ");
		 do{
		   opc=getchar();
		 }while(opc!='0');
	       }
	       break;

     case '2':if(sw==1){
		clrscr();
		printf("\n Digite informacion del Nodo a Incluir: ");
		scanf("%f",&Inf);
		push(&Tope,Max,Inf);
	      }
	      else{
		clrscr();
		printf("Pila No Creada .. ( ENTER )  Continua : ");
		do{
		  opc=getchar();
		}while(opc!='0');
	      }
	      break;

     case'3':if(sw==1){
	       clrscr();
	       Pop(&Tope,Base,&Inf);
	       printf("\n Nodo Cancelado= %3.1f",Inf);

	       printf("\n\n[0 y ENTER ] para Continuar : ");
	       do{
		 opc=getchar();
	       }while(opc!='0');
	     }
	     else{
	       clrscr();
	       printf("Pila No Creada ... (0 y ENTER) para Continua : ");
	       do{
		 opc=getch();
	       }while(opc!='0');
	     }
	     break;

     case '4':if(sw==1){
		clrscr();
		Escribir_Pila(Base,&Tope,Max,n);
		printf("\n\n[0 y ENTER ] para Continua : ");
		do{
		  opc=getchar();
		}while(opc!='0');
	      }
	      else{
		clrscr();
		printf("pila no creada (0 y ENTER ) para Continua: ");
		do{
		  opc=getchar();
		}while(opc!='0');
	      }
	      break;

     default: break;
   }
 }while (opc!='5');

clrscr();
gotoxy(30,13);
printf(" Fin Del Programa ");
getch();
}
