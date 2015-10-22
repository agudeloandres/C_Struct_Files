#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include "A:/FUNLIS.h"

// PROGRAMA PARA MANEJO DE LISTAS LINEALES SECUENCIALES (LLS)

void main()
{
  char opcion;
  unsigned int sw;
  nodo *Avail,*Min,*Max,*Lo,*Lk,*Li;
  int Inf,Inf1,k,n,resp,R;

// CREACION DEL MENU

  sw=0;
  do{
  clrscr();
  gotoxy(10,2);
  printf("MENU DEL MANEJO DE UN ARBOL EN UNA LLS");
  gotoxy(15,6);
  printf("1. INICIALIZAR EL ARBOL EN UNA LLS ");
  gotoxy(15,8);
  printf("2. CREAR EL ARBOL EN UNA LLS");
  gotoxy(15,10);
/*  printf("3. INSERTAR NUEVO NODO DESPUES DE NODO CON INF DADA");
  gotoxy(15,12);
  printf("4. CANCELAR NODO CON INF DADA");
  gotoxy(15,14);  */
  printf("3. MOSTRAR EL ARBOL EN UNA LLS");
  gotoxy(15,12);
  printf("4. SALIR");
  gotoxy(15,14);
  printf(" DIGITE OPCION DESEADA: ");
  do{
      opcion=getchar();
     }while(opcion<'0' && opcion>'4');
  switch(opcion){
      case '1':if(sw==0){
		 sw=1;
		 clrscr();

		 // Definicion de la lista lls

		 printf("Digite M ximo N£mero de nodos de la lls: ");
		 do{
		    scanf("%d",&n);
		    R=n;
		    resp=((R-1)/2);
		    }while(n%2==0 );
		 if(resp%2 != 0){
		 Avail= new nodo[n];
		 Lo=Avail;
		 Min=Lo;
		 Lk=Lo;
		 k=0;
		 Max=Calculo_Maximo(Avail,n);
		 printf("DIRECCION DE Lo= %04x:%04x\n",FP_SEG(Lo),FP_OFF(Lo));
		 printf("DIRECCION DE Max= %04x:%04x\n",FP_SEG(Max),FP_OFF(Max));
		 printf("\n\n LISTA DEFINIDA Digite 0 y <Enter> continua..");
		 do{
		    opcion=getchar();
		    }while(opcion!='0');
		 }
		 else{
		      printf("\n\n  El n£mero %d no representa un arbol completo ",n);
		      printf("\n  debido a que no tiene sus hojas en el ultimo nivel ");
		      getch();
		      }
                      }
		 else{
		    clrscr();
		    printf("Lista ya definida..Digite 0 y <Enter> continua..");
		    do{
		       opcion=getchar();
		       }while(opcion!='0');
		    }
		    break;
      case '2':if(sw==1){
		  clrscr();
		  printf("Digite Informacion a Almacenar en nodo: ");
		  scanf("%d",&Inf);
		  crear_nodo_lls(&Lk,&k,Max,Inf);
		}
		else{
		   clrscr();
		   printf("Lista No Definida.. DIgite 0 y <Enter> Continua");
		   do{
		       opcion=getchar();
		       }while(opcion!='0');
		 }
		 break;   /*
      case '3':if(sw==1){
		  clrscr();
		  printf("Digite Informaci¢n a Almacenar en Nodo: ");
		  scanf("%d",&Inf1);
		  clrscr();
		  printf("Digite Informaci¢n Nodo a Buscar: ");
		  scanf("%d",&Inf);
		  insertar_nodo(&Lo,&Lk,&k,Max,Min,Inf,Inf1);
		}
		else{
		  clrscr();
		  printf("Lista No Definida.. DIgite 0 y <Enter> Continua");
		  do{
		       opcion=getchar();
		       }while(opcion!='0');
		    }
		    break;
      case '4':if(sw==1){
		  clrscr();
		  printf("INFORMACION DEL NODO A CANCELAR: ");
		  scanf("%d",&Inf);
		  Cancelacion_nodo(&Lo,&Lk,&k,Inf);
		}
		else{
		  clrscr();
		  printf("Lista No Definida.. DIgite 0 y <Enter> Continua");
		  do{
		       opcion=getchar();
		       }while(opcion!='0');
		 }
		 break;     */
      case '3':if(sw==1){
		  clrscr();
		  escribir_nodos_lls(Lo,Lk);
		  printf("\n\n DIgite 0 y <Enter> Continua");
		  do{
		       opcion=getchar();
		       }while(opcion!='0');
		 }
		 else{
		  clrscr();
		  printf("Lista No Definida.. DIgite 0 y <Enter> Continua");
		  do{
		       opcion=getchar();
		       }while(opcion!='0');
		 }
		 break;
      default: break;
     }
   }while(opcion!='4');
   clrscr();
   gotoxy(28,14);
   delete Avail;
   printf("FIN DEL PROCESO");
 }



