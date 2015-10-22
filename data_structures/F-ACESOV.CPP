# include <stdio.h>
# include <dos.h>
# include <conio.h>
  // programa para mostrar uso de la funcion de acceso vector

void main ()
{
clrscr();
int *base, *dir;
int a[30], li, ls, n, sum, i, j;
printf (" DAR EL NUMERO DE ELEMENTOS DEL VECTOR ");
  do{
  scanf("%d", &n);
   }  while (n<=0);
   printf(" DAR EL LIMITE INFERIOR DEL VECTOR ");
   do{
   scanf("%d",&li);
   } while (li<0);
   ls = li+n-1;
  for (i=li; i<=ls; i++){
  printf (" a[%d]=",i);
  scanf("%d", &a[i]);
  }
  base = &a[li];
  sum = 0;
  // NIVEL DE IMPLEMENTACION
      for ( i=li; i<=ls; i++){
	dir=i-li+base;
	sum+=*dir;
	}
	printf (" VISUALIZACION DEL VECTOR a USANDO FUNCION DE ACCESO \n\n");
     for (i=li; i<=ls; i++){
	dir =base +i-li;
	printf("a[%d]=%d     ",i,*dir);
	printf (" direccion = %04x : %04x\n", FP_SEG(dir), FP_OFF(dir));
	}
  printf (" \n suma=%d   %04x : %04x", sum, FP_SEG(&sum), FP_OFF(&sum));
  getch();
  }