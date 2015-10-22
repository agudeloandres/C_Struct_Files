#include <stdio.h>
#include <conio.h>
#include <dos.h>

 void main()
 {

 int *dir,*base;
 int A[20][20],limtif,limtif1,ct,q,q1,x,clm,n,k,lic,W[30],sma,r,i,j;
 printf(" POR FAVOR DIGITE EL NUMERO DE FILAS Y DE COLUMNAS DE LA MATRIZ A :");
 do
 {
 scanf("%d",&n);
 }
 while (n<=0);
 printf ("POR FAVOR DIGIE EL LIMITE INFERIOR DE LAS FILAS Y COLUMNAS DE LA MATRIZ A :");
 do
 {
 scanf ("%d",&limtif);
 }
 while (limtif<0);
 x =20-n;

 //CALCULO DE LOS LIMITES CORRESPONDIENTES
 
 q= limtif+n-1;
 q1= limtif;

 r=(q+x-limtif+1);
  

 //LECTURA DE LA MATRIZ

  for (i=limtif;i<= q;i++){

       for (j=limtif;j<= q;j++){

	    printf ("POR FAVOR DIGITE EL ELEMENTO A[%d][%d] : " , i,j);
            scanf("%d",&A[i][j]);
            dir= &A[i][j];
            }
  }
 /* APLICAMOS FUNCION DE ACCESO PARA HALLAR LA DIRECCION DE LOS ELEMENTOS
   DE LA TRIANGULAR INFERIOR */ 


  sma=0;
  base= &A[limtif][limtif];
  limtif1=limtif;
  ct=0;


  for (i=limtif+1;i<= q;i++){
       clm=(i-limtif1)*r;     
       for (j=limtif1;j<=q1;j++){
            dir= base+clm+(j-limtif1);
            ct++;
            W[ct]=*dir;
            sma+=*dir;
       }
       q1++;
  }


 //IMPRIMO LOS ELEMENTOS DE LA TRIANGULAR INFERIOR Y LUEGO SU SUMA

  base=&W[limtif];

  printf(" \nLA TRIANGULAR INFERIOR DE LA MATRIZ A ES :\n");

  for (i=1;i<=ct;i++){
       dir=base+i-limtif;
       printf("EL ELEMENTO W[%d]=%d    ",i,*dir);
       printf("LA DIRECCION DE ESTE ELEMENTO  ES :  %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));

       }


  printf("\nLA SUMA RESULTANTE DE LOS ELEMENTOS DE LA TRIANGULAR INFERIOR ES : %d\n",sma);

  printf("LA  DIRECCION DE ESTA SUMA ES : %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));

}




