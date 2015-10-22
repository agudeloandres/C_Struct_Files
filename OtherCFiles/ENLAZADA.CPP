
  # include <stdlib.h>
  # include <stdio.h>
  # include <conio.h>
  # include <dos.h>
  # include <f:rutin.h>
  int menu(void);
void main ()
{
   nodo *ptr,*avail;
   int inf,n;
   unsigned int sw = 0;
   int opcion;

   // creacion del menu de pila lle
      while (( opcion= menu()) != 5){
	switch(opcion){
		 case 1:
			if(sw==0){
			sw=1;
			clrscr();
			ptr=NULL;
			avail=NULL;
			n=5;
			printf(" lista inicializada ");
			getch();
			}
			else{
			     printf(" la lista ya fue creada");
			     getch();
			    }

			    break;

		 case 2:
			if(sw==1){
			clrscr();
			printf("entre informacion : ");
			scanf("%d",&inf);
			insertar(&ptr,inf,&avail);
			}
			break;

		case 3:
			if(sw==1){
			printf ("informacion a eliminar : ");
			scanf("%d",&inf);
			if(ptr != NULL){
			cancelar(inf,&ptr,&avail);
			printf(" cancelado  ");
			getch();
			}

			}
			break;

		 case 4:
			 if(sw==1){
			 consultar(ptr);
			 getch();
			 }
			 else{
			 printf (" informacion no cosultada : ");
			 getch();
			 }

			 break;

			  }
	     }
}
int menu(void)
{
int opcion;
clrscr();
textbackground(1);
textcolor(15);
    int k,y,p;

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }



      gotoxy (35,2);
      printf ("M  E  N  U ");
      gotoxy (22,4);
      printf ("1_ INICIALIZAR");
      gotoxy (22,6);
      printf ("2_ INSERTAR");
      gotoxy (22,8);
      printf ("3_ CANCELAR");
      gotoxy (22,10);
      printf ("4_ CONSULTAR");
      gotoxy (22,12);
      printf ("5_ SALIR");
      gotoxy (22,14);
      printf ("DIGITE OPCION : ");
      scanf("%d",&opcion);
      return opcion;
      }
