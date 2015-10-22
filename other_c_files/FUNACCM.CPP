#include <stdio.h>
#include <dos.h>

void main()
{

int *dir,*base;
int A[20][20],limtif,limtsf,W,limtic,limtsc,clm,n,k,s,sma[20],r,i,j;

 printf("POR FAVOR ADIGITE EL NUMERO DE FILAS DE LA MATRIZ A : ");
 do
 {
 scanf("%d",&n);
 }
 while (n<=0);
 printf("POR FAVOR DIGITE EL NUMERO DE COLUMNAS DE LA MATRIZ A : " );
 do
 {
 scanf ("%d",&s);
 }
 while (s<=0);
 printf ("POR FAVOR DIGITE EL LIMITE INFERIOR DE LAS FILAS Y COLUMNAS DE LA MATRIZ A :");
 do
 {
 scanf ("%d",&limtif);
 }
 while (limtif<0);
 limtic=limtif;
 W=20-s;

//HALLAMOS LOS LIMITES CORRESPONDIENTES

 limtsf=limtif+n-1;
 limtsc=limtic+s-1;
 r=limtsc+W-limtic+1;

//LEEMOS LA MATRIZ A

 for (i=limtif;i<=limtsf;i++){
     for (j=limtic;j<=limtsc;j++){
          printf("POR FAVOR DIGITE EL ELEMETO A[%d][%d]=",i,j);
          scanf("%d",&A[i][j]);
          dir= &A[i][j];
     }
 }
//APLICAMOS FUNCION DE ACCESO A LOS ELEMENTOS DE LA MATRIZ A

 base=&A[limtif][limtic];
 for (i=limtif;i<=limtsf;i++){
      clm=(i-limtif)*r;
      sma[i]=0;
      for (j=limtic;j<=limtsc;j++){
           dir=base+clm+(j-limtic);
	   sma[i]+=*dir;
      }
 }


 printf("\n LOS ELEMENTOS DE LA MATRIZ A UTILIZANDO FUNCION DE ACCESO \n");

 for(i=limtif;i<=limtsf;i++){
     clm=(i-limtif)*r;
     for (j=limtic;j<=limtsc;j++){
	  dir=base+clm+(j-limtic);
          printf("EL ELEMENTO A[%d][%d]=%d   ",i,j,*dir);

	  printf(" LA DIRECCION DE ESTE ELEMENTO ES : %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
     }
 }

 base=&sma[limtif];


 printf("\nEL VECTOR SUMA UTILIZANDO LA FUNCION DE ACCESO ES : \n");

 for (i=limtif;i<=limtsf;i++){
      dir=base+i-limtif;
      printf("\n LA SUMA RESULTANTE DE LA FILA[%d] ES sma: %d    ",i,*dir);
      printf("\n Y SU DIRECCION ES : %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
 }


 }


