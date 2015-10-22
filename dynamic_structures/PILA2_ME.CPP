/////////////////////////////////////////////////////////////////////////////
//		       UNIVERSIDAD COOPERATIVA DE COLOMBIA                 //
//		       FACULTAD  DE INGENIERIA DE SISTEMAS                 //
//		       	     ESTRUCTURA DE DATOS  I                        //
//			        PRESENTADO POR:                            //
//		      ALEJANDRA MARIA MONERY GAMEZ. 5971037                //
//		      ANA MARIA VAN LEENDEN CARPIO. 5971058                //
//			       PRESENTADO  A:                              //
//		         ING. RICARDO CONTRERAS G.                         //
//                                 PILAS                                   //
/////////////////////////////////////////////////////////////////////////////

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include"C:\BORLANDC\BIN\DINAMI~1\PILA2M.H"

//PROGRAMA PARA EL MANEJO DE PILAS LLS

void main()
{
char opcion;
unsigned int sw;
stack *tope, *base,  *max, *li;
int n, k, p,y;
float inf;


//CREACION DEL MENU

sw=0;
do{
clrscr();
textcolor(11);
textbackground(9);
gotoxy(1,1);  printf("É\n");
gotoxy(80,1); printf("»\n");
gotoxy(1,23); printf("È\n");
gotoxy(80,23);printf("¼\n");

for(k=2; k<=79; k++){

gotoxy(k,y);
gotoxy(k,1);  printf("Í\n");
gotoxy(k,6);  printf("Í\n");
gotoxy(k,23); printf("Í\n");
}

for(p=2; p<=22;p++){

gotoxy(1,p);  printf("º\n");
gotoxy(80,p); printf("º\n");
}

gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(31,3);
printf("SECCIONAL SANTA MARTA");
gotoxy(25,4);
printf("FACULTAD DE INGENIERIA DE SISTEMAS");
gotoxy(31,5);
printf("ESTRUCTURA DE DATOS I");
gotoxy(35,8);
printf("M E N U");
gotoxy(20,10);
printf("1.-CREAR PILA");
gotoxy(20,12);
printf("2.-INSERTAR NODO (PUSH) EN LA PILA");
gotoxy(20,14);
printf("3.-CANCELAR NODO (POP) EN LA PILA");
gotoxy(20,16);
printf("4.-MOSTRAR PILA");
gotoxy(20,18);
printf("5.-SALIR");
gotoxy(30,20);
printf("DIGITE OPCION [ ] ");
gotoxy(45,20);
do{
  opcion=getchar();
} while(opcion<'0' && opcion <'5');
switch(opcion){
    case '1': if (sw==0){
	      sw=1;
	      clrscr();

//DEFINICION ESPACIO DISPONIBLE

printf("DIGITE EL MAXIMO NUMERO DE NODOS DE LA LISTA:   ");
do{
 scanf("%d",&n);
} while(n<=0);
      crear_pila(&base, &tope, n);
      max=maximo(base,n);
      printf("   base=%04x:%04x",FP_SEG(base), FP_OFF(base));
      printf("   tope+%04x:%04x",FP_SEG(tope), FP_OFF(tope));
      printf("\n maximo=%04x:%04x", FP_SEG(max), FP_OFF(max));
      printf("\n\n DIGITE 0 Y <ENTER> CONTINUA\n");
      do{
	 opcion=getchar();
      } while (opcion!='0');
}
  else{
      clrscr();
      printf("PILA YA CREADA... DIGITE 0 Y <ENTER> CONTINUA\n");
      do{
	 opcion=getchar();
      } while(opcion!='0');
}
  break;


    case'2': if(sw==1){
	     clrscr();
	     printf("\n DIGITE INFORMACION DEL NODO A INCLUIR\n");
	     scanf("%f", &inf);
	     push(&tope, max, inf);
}
  else{
      clrscr();
      printf("PILA NO CREADA... DIGITE 0 Y <ENTER> CONTINUA\n");
      do{
	 opcion=getchar();
      } while(opcion!='0');
}
  break;


    case'3': if(sw==1){
	     clrscr();
	     pop(&tope, base, &inf);
	     printf("\n NODO CANCELADO =%3.0f", inf);
	     printf("\n\n DIGITE 0 Y <ENTER> CONTINUA\n");
	     do{
		opcion=getchar();
	     } while(opcion!='0');
}
  else{
      clrscr();
      printf("PILA NO CREADA... DIGITE 0 Y <ENTER> CONTINUA\n");
      do{
	 opcion=getchar();
      } while(opcion!='0');
}
   break;


    case'4': if(sw==1){
	     clrscr();
	     escribir_pila(base, &tope, max, n);
	     printf("\n\n DIGITE 0 Y <ENTER> CONTINUA\n");
	     do{
		opcion=getchar();
	     } while(opcion!='0');
}
  else{
       clrscr();
       printf("PILA NO CREADA...  DIGITE 0 Y <ENTER> CONTINUA\n");
       do{
	  opcion=getchar();
       } while(opcion !='0');
}
   break;
 default: break;
 }
} while (opcion!='5');
clrscr();
printf("FIN DEL PROCESO");
}




