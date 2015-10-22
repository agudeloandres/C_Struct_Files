
# include <iostream.h>
# include <conio.h>
# include <dos.h>
# include <stdio.h>
# include  <string.h>
# include <a:\rulle.h>
# include <conio.h>

//programa para el manejo de pilas lle

void main ()
{

char opcion;
unsigned int sw;
nodo *Ptr, *Avail,*P,*Q,*x;
int inf;
clrscr();
int k,y,p;


//creacion del menu

sw=0;
do{
clrscr();
gotoxy(35,2);
printf(" MENU PRINCIPAL ");
gotoxy(20,8);
printf("1- INICIALIZAR LLE");
gotoxy(20,10);
printf("2- CREAR LLE ");
gotoxy(20,12);
printf("3- INSERTAR ANTES DE NODO DADO");
gotoxy(20,14);
printf("4- CANCELAR  ");
gotoxy(20,16);
printf( "5- MOSTRAR LISTA");
gotoxy(20,18);
printf("6- TERMINAR");
gotoxy(20,20);
printf("DIGITE OPCION:  ");
do{
  opcion=getchar();
  }while (opcion<'0'&&opcion<'6');
  switch (opcion){
     case'1': if(sw==0){
		sw=1;
		clrscr();

		//definicion de la lista lle

		Ptr=0;
		Avail=0;
		gotoxy(29,12);
		printf(" LISTA INICIALIZADA ");
		getch();
		}
		else {
		    clrscr();
		    printf("Lista ya Definida");
		    getch();
	      }
	      break;

     case'2': if (sw==1){
		  crear_nodo(&Ptr);
		}
		else{
		  clrscr();
		  printf("Lista Definida");
		  getch();
		}
		break;
     case'3': if (sw==1){
		  captura_nodo(&inf,&x,&Avail);
		  inserta(&Ptr,inf,x);
		}
		else{
		 clrscr();
		 printf("Lista No Definida");
		 getch();
		}
		break;
     case'4': if (sw==1){
		 clrscr();
		 gotoxy(10,2);
		 printf("INFORMACION DEL NODO A CANCELAR:  ");
		 gotoxy(15,4);
		 printf("informacion   : ");
		 scanf("%d",&inf);
		 Cancelar(&Ptr,&Avail,inf);
	       }
	       else{
		clrscr();
		printf("Lista No definida");
		getch();
		}
		break;
      case'5': if (sw==1){
	       clrscr();
	       mostrar_nodos(Ptr);
	       printf("\n\n<Enter> Continua:");
	       getch();
		}
		else{
		  clrscr();
		  printf("Lista No Definida");
		getch();
		 }
		 break;
      default:break;
   }
   } while (opcion != '6');
   clrscr();
   printf(" F I N  P R O C E S O ");
   }
