# include <iostream.h>
# include <conio.h>
# include <dos.h>
# include <stdio.h>
# include  <string.h>
# include <F:\rulle.h>
# include <conio.h>
# include <F:cuadro.h>
# include <F:cuadr.h>
//programa para el manejo de pilas lle
void main ()
{

char opcion;
unsigned int sw;
estudiante *Ptr, *Avail,*P,*Q,*T;
float Inf;
clrscr();
textbackground(1);
textcolor(15);
    int k,y,p;


//creacion del menu
sw=0;
do{
clrscr();
cuadro();
gotoxy(35,2);
printf(" MENU PRINCIPAL ");
gotoxy(27,5);
printf(" LISTA LINEAL ENLAZADA ");

gotoxy(20,8);

printf("1- INICIALIZAR LISTA ");

gotoxy(20,10);
printf("2- CREAR LISTA ");
gotoxy(20,12);
printf("3- INSERTAR ANTES ");
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
		cuadr();
		gotoxy(29,12);
		printf(" LISTA INICIALIZADA ");
		getch();
		}
		else {
		    clrscr();
		    cuadr();
		    gotoxy(30,12);
		    printf("Lista ya Definida\a");
		    getch();
	      }
	      break;

     case'2': if (sw==1){
		  crear_nodo_lle(&Ptr);
		}
		else{

		  clrscr();
		  cuadr();
		  gotoxy(30,12);
		  printf("Lista No Definida\a");
		  getch();
		}
		break;
     case'3': if (sw==1){
		  captura_nodo(&Inf,&T,&Avail);
		  inserta(&Ptr,Inf,T);
		}
		else{
		 clrscr();
		 cuadr();
		 gotoxy(30,12);
		 printf("Lista No Definida\a");
		 getch();
		}
		break;
     case'4': if (sw==1){
		 clrscr();
		 gotoxy(10,2);
		 printf("INFORMACION DEL NODO A CANCELAR:  ");
		 gotoxy(15,4);
		 printf("INFORMACION : ");
		 scanf("%f",&Inf);
		 Cancelar(&Ptr,&Avail,Inf);
	       }
	       else{
		clrscr();
		cuadr();
		gotoxy(30,12);
		printf("Lista No definida\a");
		getch();
		}
		break;
      case'5': if (sw==1){
	       clrscr();
	       escribir_nodos_lle(Ptr);
	       cuadr();
	       gotoxy(30,12);
	       printf(" PULSE <Enter>..!\a");
	       getch();
               printf("\a");
		}
		else{
		  clrscr();
		  cuadr();
		  gotoxy(30,12);
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
