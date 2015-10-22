#include <stdio.h>
#include <dos.h>
void main()
{
int *base,*dir;
int A[20][20],limtif,limtsf,W,limtic,limtsc,colm,n,d[10],sma,r,i,j;


  printf(" POR FAVOR DIGITE EL NUMERO DE FILAS Y COLUMNAS DE LA MATRIZ A :");
  do
 {
 scanf("%d",&n);
 }
 while (n<=0);
 printf (" POR FAVOR DAR EL LIMITE INFERIOR DE FILAS Y DE COLUMNAS : ");
 do
 {
 scanf ("%d",&limtif);
 }
 while (limtif<0);
 limtic=limtif;
 W=20-n+1;

//HALLAMOS LOS RESPECTIVOS LIMITES
 limtsf=limtif+n-1;

 r=limtsf+W-limtic+1;

 // LEEMOS LOS ELEMENTOS DE LA MATRIZ A

for (i=limtif;i<=limtsf;i++){
     for (j=limtif;j<=limtsf;j++){
     printf(" POR FAVOR DIGITE EL ELEMENTO A[%d][%d]:",i,j);
     scanf("%d",&A[i][j]);
     dir=&A[i][j];
   }
}
/* APLICACION DE LA FUNCION DE ACCESO PARA LOS ELEMENTOS DE LA 
   DIAGONAL PRINCIPAL DE LA MATRIZ A */

 sma=0;
 base= &A[limtif][limtif];
 for (i=limtif;i<=limtsf;i++){
      dir=base+(i-limtif)*r;
      d[i]=*dir;
      sma+=*dir;
     }

 printf(" \n LA SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL ES : %d \n",sma );
 printf(" LA DIRECCION DE LA SUMA ES : %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
 base=&d[limtif];
 printf("\n LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL :\n ");

 for (i=limtif;i<=limtsf;i++){
      
        dir=base+i-limtif;
        printf("\n EL ELEMENTO d[%d]=%d   ",i,*dir);
	printf(" LA DIRECCION DE ESTE  ELEMENTO  ES =%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
    }
  
  }





