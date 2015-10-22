#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main () {

int *base , *dir ,*dir2,*dir3;
int a[30], b[30],li ,ls , n , i, j;
clrscr();
printf ("DAR EL NUMERO DE ELEMENTOS DEL VECTOR ");
do {
scanf ("%d",&n);
}while (n<=0);
printf ("DAR EL LIMITE INFERIOR DEL VECTOR ");
do {
scanf ("%d",&li);
} while (li<0);
ls = li+n-1;
for (i=li;i<=ls;i++){
printf ("a[%d] = ",i);
scanf ("%d",&a[i]);
}
base = & a[li];

printf("ELEMENTOS QUE SON  MULTIPLOS DE 2 :\n");
for (i=li;i<=ls;i++){
dir = base+(i-li);
 if (*dir % 2 == 0){
  printf (" %d   ",*dir);
  printf (" a[%d]= %d  DIRECCION  %04x : %04x \n",  i, *dir,FP_SEG (dir), FP_OFF (dir));
  }
  }
printf ( " ELEMENTOS QUE OCUPAN POSICION PAR : \n");
for (i=li;i<=ls;i++){
dir2 = base + (i-li) ;
 if (((dir2)-base + li) % 2 ==0){
      printf (" %d  ",*dir2);
      printf ("\nDIRECCION :  %04x : %04x \n", FP_SEG(dir2), FP_OFF (dir2));
}
}

  for (i=li;i<=ls;i++){
   dir3 = base + (i-li);
    if (( dir3 -base + li ) % 3 ==0 ){
       if(*dir3 % 2!=0){
	 for (j=0;j<=ls;j++)
	 b[j]=a[i];


       }
       }
 }
	 printf("VECTOR b[j] : \n");
	 for (i=li;i<=ls;i++)
	   printf("%d ",b[j]);

  getch();
  }



