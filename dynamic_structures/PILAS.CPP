#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<C:\BORLANDC\BIN\DINAMI~1\rupila.h>
//programa para manejo de pila lls

void main()
{
textbackground(1);
textcolor(14);
char opcion,op;
unsigned int sw;
stack *Tope,*Base,*Max,*Li;
int n;
float Inf;
//creacion del menu
sw=0;
do{
 //clrscr();
 menu();
 gotoxy(35,2);
 printf("M E N U");
 gotoxy(18,8);
 printf("1.  CREAR PILA");
 gotoxy(18,10);
 printf("2.  INSERTAR NODO(PUSH) EN LA PILA");
 gotoxy(18,12);
 printf("3.  CANCELAR NODO(POP) EN LA PILA");
 gotoxy(18,14);
 printf("4.  MOSTRAR PILA");
 gotoxy(18,16);
 printf("5.  SALIR");
 gotoxy(25,20);
 printf("DIGITE OPCION [ ]");
 gotoxy(40,20);
 do{
   opcion=getchar();
 }while(opcion<'0' && opcion<'5');
 switch(opcion){
      case'1':if(sw==0){
	       sw=1;
	       marco();
	       //Definicion espacio disponible
	       gotoxy(5,3);
	       printf("DIGITE EL NUMERO MAXIMO DE NODOS DE LA PILA : [  ]");
	       gotoxy(52,3);
	       do{
		scanf("%d",&n);
	      }while(n<=0);
	       crear_pila(&Base,&Tope,n);
	       Max=Maximo(Base,n);
	       gotoxy(5,5);printf("Base=%04x:%04x",FP_SEG(Base),FP_OFF(Base));
	       gotoxy(5,7);printf("Tope=%04x:%04x",FP_SEG(Tope),FP_OFF(Tope));
	       gotoxy(5,9);printf("Maximo=%04x:%04x",FP_SEG(Max),FP_OFF(Max));
	       getch();
	      }
	      else{
		marco();
		gotoxy(25,12);
		printf("PILA YA CREADA.......!!!");
		getch();
	      }
	       break;
	    case'2':if(sw==1){
		     do{
		     marco();
		     gotoxy(5,3);
		     printf("DIGITE INFORMACION DEL NODO A INCLUIR : ");
		     scanf("%f",&Inf);
		     Push(&Tope,Max,Inf);
		     gotoxy(7,5);
		     printf("DESEA INSERTAR MAS NODOS (S/N):   ");
		     do{
		      op=getchar();
		      }while(op!='s' && op!='S' && op!='n' && op!='N');
		     }while(op=='s' || op=='S');

		   }
		    else{
		      marco();
		      gotoxy(25,12);
		      printf("PILA NO CREADA.....!!!");
			getch();

		    }
		      break;
		  case'3':if(sw==1){
			marco();
			//printf("Digite informacion del nodo a cancelar: ");
			//scanf("%f",&Inf);
			Pop(&Tope,Base,&Inf);
			gotoxy(25,12);
			printf("NODO CANCELADO = %3.0f   ",Inf);
			printf("Dir = %04x:%04x \n",FP_SEG(Tope+1),FP_OFF(Tope+1));
			getch();
			}
			else{
			 marco();
			 gotoxy(25,12);
			 printf("PILA NO CREADA.....!!!");
			 getch();
			}
			   break;
			case'4':if(sw==1){
				 marco();
                                 gotoxy (25,2);printf("LA PILA ES :");
				 escribir_pila(Base,&Tope,Max,n);
				 getch();
			       }
			       break;
			     default:break;
			     }
			    }while(opcion!='5');
			  clrscr();
			  gotoxy(30,12);printf("FIN PROCESO");
			  }





