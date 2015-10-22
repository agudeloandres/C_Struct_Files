#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include <C:\BORLANDC\BIN\DINAMI~1\LLSMEN.H>


// PROGRAMA PARA MANEJO DE LISTAS LINEALES SECUENCIALES (LLS)

void main()
{
  char opcion, Opc;
  unsigned int sw;
  lls *Avail,*Min,*Max,*Lo,*Lk,*Li;
  float inf;
  int k,n;

// CREACION DEL MENU

  sw=0;
  do{
  clrscr();
  gotoxy(10,2);
  printf("MENU PRINCIPAL MANEJO DE LISTAS LINEALES SECUENCIALES");
  gotoxy(15,6);
  printf("1. INICIALIZAR LISTA LINEAL SECUENCIAL");
  gotoxy(15,8);
  printf("2. CREAR LISTA SECUENCIAL");
  gotoxy(15,10);
  printf("3. CANCELAR NODO CON INF DADA");
  gotoxy(15,12);
  printf("4. MOSTRAR NODO DE LISTA SECUENCIAL");
  gotoxy(15,14);
  printf("5. SALIR");
  gotoxy(15,16);
  printf(" DIGITE OPCION DESEADA: ");
  do{
      opcion=getchar();
     }while(opcion<'0' && opcion>'5');
  switch(opcion){
      case '1':if(sw==0){
		 sw=1;
		 clrscr();

		 // Definicion de la lista lls

		printf("Digite Maximo Numero de nodos de la (lls) :  ");
		 do{
		    scanf("%d",&n);
		    }while(n<=0);
		 Avail= new lls[n];
		 Lo=Avail;
		 Min=Lo;
		 Lk=Lo;
		 k=0;
		 Max=Calculo_Maximo(Avail,n);
		 printf("DIRECCION DE Lo= %04x:%04x\n",FP_SEG(Lo),FP_OFF(Lo));
		 printf("DIRECCION DE Max= %04x:%04x\n",FP_SEG(Max),FP_OFF(Max));
		 printf("\n\n LISTA DEFINIDA...<<ENTER>> PARA CONTINUAR: ");
		 do{
		   Opc=getchar();
		 }while(Opc!='0');
	       }
		 else{
		    clrscr();
		    printf("LISTA YA DEFINIDA...<<ENTER>> PARA CONTINUAR");
		    do{
		      Opc=getchar();
		    }while(Opc!='0');
		 }
		 break;
      case '2':if(sw==1){
		  clrscr();
		  crear_nodo_lls(&Lk,&k,Max,inf);
		}
		else{
		   clrscr();
		   printf("LISTA NO DEFINIDA...<<ENTER>> PARA CONTINUAR");
		   do{
		     Opc=getchar();
		   }while(Opc!='0');
		}
		break;


      case '3': if(sw==1){
		  clrscr();
		  Cancelacion_nodo(&Lo,&Lk,&k,inf);
		}
		else{
		  clrscr();
		   printf("LISTA NO DEFINIDA...<<ENTER>> PARA CONTINUAR");
		  do{
		   Opc=getchar();
		  }while(Opc!='0');
		}
		 break;

      case '4':if(sw==1){
		  clrscr();
		  escribir_nodos_nodo(Lo,Lk);
		  printf("\n\nPresione <<ENTER>> Para Continuar");
		  do{
		    Opc=getchar();
		  }while(Opc!='0');
		}
		 else{
		  clrscr();
		   printf("LISTA NO DEFINIDA...<<ENTER>> PARA CONTINUAR");
		  do{
		    Opc=getchar();
		  }while(Opc!='0');
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




