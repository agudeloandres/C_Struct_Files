#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main ()
{
int *dir, *base;
int A[3][3][3],b,br,c,cr,d,dr,f,fr,limtip, limtsp,limtif;
int limtsf, limtsc, limtic, s, n, i, j;


printf (" POR FAVOR DIGITE EL NUMERO DE PLANOS DEL ARREGLO DE A : ");
do
{
scanf ("%d", &n);
}
while (n <= 0);

printf ("POR FAVOR DIGITE EL NUMERO DE FILAS DEL ARREGLO A : ");
do
{
scanf ("%d", &b);

}
while (n<=0);
printf  ("POR FAVOR DIGITE EL NUMERO DE COLUMNAS DEL ARREGLO A:");
do
{
scanf ("%d", &br);
}

while (n <= 0);
printf ("POR FAVOR DIGITE  EL LIMITE INFERIOR DE LOS PLANOS DEL ARREGLO A : ");
do
{
scanf ("%d", &limtip);
}
while (limtip < 0);

printf ("POR FAVOR DIGITE  EL LIMITE INFERIOR DE LAS FILAS DEL ARREGLO A : ");

do
{
scanf ("%d", &limtif);
}
while (limtif < 0);
printf ("POR FAVOR DIGITE  EL LIMITE INFERIOR DE LAS COLUMNAS DEL ARREGLO A : ");

do
{
scanf ("%d", &limtic);
}
while (limtic < 0);

//HALLAMOS LOS LIMITES CORRESPONDIENTES


d=4-b;
dr=4-br;
limtsp= limtip+n-1;
limtsf= limtif+b-1;
limtsc= limtic+br-1;
f= (limtsf-limtif+1+dr);    
fr=(limtsc-limtic+d+1)*f;




for (s=limtip; s<=limtsp; s++){
     for (i=limtif; i<=limtsf; i++){
	  for (j=limtic; j<=limtsc; j++){
	     printf("POR FAVOR DIGITE EL ELEMENTO A[%d][%d][%d] :  ", s,i,j);
             scanf("%d",&A[s][i][j]);
             dir = &A[s][i][j];
             
	 }

      }
    
  }


// APLICAMOS LA FUNCION DE ACCESO A LA MATRIZ TRIDIMENSIONAL


printf ("\n ELEMENTOS DE LA MATRIZ TRIDIMENSIONAL APLICANDO LA FUNCION SE ACCESO \n\n");

base = &A[limtip][limtif][limtic];     

for(s=limtip; s<=limtsp;s++){
    cr=(s-limtip)*fr;
    for(i=limtif; i<=limtsf;i++){
        c=(i-limtif)*f;
      for(j=limtic; j<=limtsc;j++){
          dir= base+cr+c+(j-limtic);
       
    printf ("EL ELEMENTO A[%d][%d][%d] = %d",s ,i,j,*dir);
    printf (" LA DIRECCION DE ESTE ELEMENTO ES: % 04X:%04X \n", FP_SEG(dir), FP_OFF(dir));

      }
    }
 }

}





