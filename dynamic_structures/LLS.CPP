#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include <C:\BORLANDC\BIN\DINAMICA\LLS.H>


// PROGRAMA PARA MANEJO DE LISTAS LINEALES SECUENCIALES (LLS)


void main()
{

  textbackground(1);
  textcolor(14);
  char opcion, Opc,op;
  unsigned int sw;
  lls *Avail,*Min,*Max,*Lo,*Lk,*Li;
  float inf;
  int k,n;

// CREACION DEL MENU

  sw=0;
  do{


  marco();
  gotoxy(20,3);
  printf(" MENU LISTAS LINEALES SECUENCIALES ");
  gotoxy(15,8);
  printf("1.  INICIALIZAR LISTA LINEAL SECUENCIAL");
  gotoxy(15,10);
  printf("2.  CREAR LISTA LINEAL SECUENCIAL");
  gotoxy(15,12);
  printf("3.  CANCELAR NODO CON INFORMACION DADA");
  gotoxy(15,14);
  printf("4.  MOSTRAR NODOS DE LISTA SECUENCIAL");
  gotoxy(15,16);
  printf("5.  SALIR");
  gotoxy(30,20);
  printf("OPCION [ ]");gotoxy(38,20);

  do{
      opcion=getchar();
    } while(opcion<'0' && opcion>'5');
  switch(opcion){
      case '1':if(sw==0){
		 sw=1;
		 
		 marco();
		 // Definicion de la lista lls

		gotoxy(18,5);
		printf("DIGITE MAXIMO NUMERO DE NODOS DE LA LLS :    ");
		 do{
		    scanf("%d",&n);
		    }while(n<=0);
		 Avail= new lls[n];
		 Lo=Avail;
		 Min=Lo;
		 Lk=Lo;
		 k=0;
		 Max=Calculo_Maximo(Avail,n);
		 gotoxy(18,9);
		 printf("DIRECCION DE Lo= %04x:%04x ",FP_SEG(Lo),FP_OFF(Lo));
		 gotoxy(18,13);
		 printf("DIRECCION DE Max= %04x:%04x ",FP_SEG(Max),FP_OFF(Max));
		 getch();
	       }
		 else{
		    clrscr();
		    marco();
		    gotoxy(25,12);
		    printf("LISTA YA CREADA........!!! ");
		    getch();
		}
		 break;
      case '2':if(sw==1){
		  clrscr();
		  do{
		   crear_nodo_lls(&Lk,&k,Max,inf);
		   gotoxy(16,9);
		   printf("DESEA INSERTAR MAS NODOS (S/N):   ");
		  do{
		  op=getchar();
		  }while(op!='s' && op!='S' && op!='n' && op!='N');
		}while(op=='s' || op=='S');
		}
		else{
		   marco();
		   gotoxy(25,12);
		   printf("LISTA NO CREADA..........!!!");
		   getch();
		}
		break;


      case '3': if(sw==1){
		  clrscr();
		  Cancelacion_nodo(&Lo,&Lk,&k,inf);
		}
		else{
		   marco();
		   gotoxy(25,12);
		   printf("LISTA NO CREADA DIGITE.........!!!");
		  getch();
		}
		 break;

      case '4':if(sw==1){
		  clrscr();
		  escribir_nodos_nodo(Lo,Lk);
		  getch();
		}
		 else{
		   marco();
		   gotoxy(25,12);
		   printf("LISTA NO CREADA..........!!!");
		  getch();
		 }
		 break;
      default: break;
     }
   }while(opcion!='5');
   clrscr();
   gotoxy(28,14);
   delete Avail;
   printf("FIN DEL PROCESO");
 }






