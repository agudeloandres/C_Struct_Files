#include<stdlib.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include <C:\BORLANDC\BIN\FILES\JOSE.H>

void main(){
int opc,i,opc2,i2,opc3,i3;
char *o=NULL,*o2=NULL,*o3=NULL;

 i:
 menu();
 //scanf("%d",&opc);
  gets(o);
  opc=atoi(o);
  switch (opc) {
     case 1:
	  i2:
	  submenu_vect();
	  //scanf("%d",&opc2);
	     gets(o2);
	     opc2=atoi(o2);
	     switch (opc2){
		 case 2:
		      suma_vect();
		      goto i2;
		 case 3:
		      mult_vect();
		      goto i2;
		 case 4:
		      goto i;
		 default:
		       gotoxy(36,25);
		       printf("нн ERROR !!");
		       delay(500);
		       goto i2;
	    }

      case 2:
	   i3:
	   submenu_mat();
	   gets(o3);
	   opc3=atoi(o3);
	   //scanf("%d",&opc3);
		switch (opc3){
		   case 1:
			suma_mat();
			goto i3;
		   case 2:
			 mult_mat();
			 goto i3;
		   case 3:

			 goto i3;
		   case 4:
			goto i;
		   default:
			 gotoxy(36,25);
			 printf("нн ERROR !!");
			 delay(500);
			 goto i3;
	       }


      case 3:
	   gotoxy(30,25);
	   printf("OPCION NO DESARROLLADA !!");
	   delay (500);
	   goto i;
      case 4:
	   break;

     default:
	   gotoxy(36,25);
	   printf("нн ERROR !!");
	   delay(500);
	   goto i;

  }  // FIN DEL SWITCH
}
/// FIN PROGRAMA PRINCIPAL
