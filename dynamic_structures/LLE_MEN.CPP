//PROGRAMA PARA EL MANEJO DE UNA LISTA LINEAL ENLAZADA LLE(Ptr)
// Ptr= Es Apuntador o cabeza del nodo y el unico elemento que se conoce de la lista.
// Avail= Es un apuntador, que es el espacio disponible.
//P,Q= son apuntadores, que contienen la direccion de memoria de un nodo.
 
#include<conio.h>
#include <stdio.h>
#include <C:\BORLANDC\BIN\DINAMICA\LLEMEN.H>

void main()
{
char Opc;
unsigned int sw;
LLE *Ptr,*Avail;
float Inf;

//CREACION DEL MENU
sw=0;

do{
  clrscr();
  gotoxy(25,2);
  printf ("**// M E N U  P R I N C I P A L **//");
  gotoxy(18,4);
  printf ("INICIALIZAR LISTA LINEAL ENLAZADA(LLE)************ (1)");
  gotoxy(18,6);
  printf ("INSERTAR INFORMACION EN UNA (LLE)***************** (2)");
  gotoxy(18,8);
  printf ("ELIMINAR LA INFORMACION DADA (LLE) *************** (3)");
  gotoxy(18,10);
  printf ("CONSULTAR INFORMACION EN UNA (LLE)**************** (4)");
  gotoxy(18,12);
  printf ("SALIR DEL PROGRAMA******************************** (5)");
  gotoxy (18,14);
  printf ("DIGITE OPCION: ");
  do{
    Opc=getchar();
  }while(Opc<'0' && Opc>'5');
   switch(Opc){


      case '1':if(sw==0){
		 sw=1;
		  clrscr();
		   Ptr=NULL;
		    Avail=NULL;
		     printf ("LISTA LINEAL ENLAZADA INICIALIZADA....<<0 y ENTER>> PARA CONTINUAR");
		      do{
		       Opc=getchar();
			}while (Opc!='0');
		}
		 else{
		   clrscr();
		    printf ("LISTA YA INICIALIZADA ------ [0 y E N T E R ] PARA C O N T I N U A R ");
		     do{
		      Opc=getchar();
		      }while (Opc!='0');
		 }
	       break;


      case '2':if(sw==1){
		  clrscr();
		   printf("DIGITE INFORMACION: ");
		    do{
		     scanf("%f",&Inf);
		     }while(Inf<0.0 || Inf>5.0);
		      Insertar_Lle(&Ptr,Inf,&Avail);
		       printf("DIGITE ----- (0 Y E N T E R) PARA CONTINUAR");
			do{
			 Opc=getchar();
			  }while (Opc!='0');
		}
		 else{
		  clrscr();
		   printf ("(LLE) NO DEFINIDA ----- (0 Y E N T E R) PARA CONTINUAR");
		    do{
		     Opc=getchar();
		     }while (Opc!='0');
		}
		break;

      case '3':if(sw==1){
		clrscr();
		 printf ("DIGITE INFORMACION DEL NODO A CANCELAR: ");
		  scanf ("%f", &Inf);
		   Cancelar_Lle(&Ptr,&Avail,Inf);
		    printf("DIGITE (0 y E N T E R) PARA CONTINUAR");
		     do{
		      Opc=getchar();
		       }while (Opc!='0');

		}
		 else{
		   clrscr();
		    printf ("(LLE) NO DEFINIDA ----- (0 y E N T E R) PARA CONTINUAR");
		     do{
		      Opc=getchar();
		      }while (Opc!='0');

		 }
	       break;



      case '4':if(sw==1){
		  clrscr();
		   Consultar_Lle(Ptr);
		    gotoxy(15,4);
		     printf ("\n DIGITE (0 y E N T E R) PARA CONTINUAR");
		      do{
		       Opc=getchar();
		       }while (Opc!='0');
		}
		 else{
		  clrscr();
		   printf ("(LLE) NO DEFINIDA----- (0 y E N T E R ) PARA CONTINUA");
		       do{
			 Opc=getchar();
		       }while (Opc!='0');

		break;
	   default: break;
	}
       }
   }while (Opc !='5');
   clrscr();
    gotoxy(20,8);
      printf (" [***///----F I N  D E L  P R O G R A M A----***///] ");
}



