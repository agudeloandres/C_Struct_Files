/* DADA UNA MATRIZ CUADRADA A DE NXN, DEDUCIR LA FUNCION DE ACCESO (DIRECCIONAMIENTO)
   PARA LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA.  HACER UN PROGRAMA C++ USANDO LA FUNCION
   DE ACCESO PARA QUE LEIDA LA MATRIZ A UNA MATRIZ DE NXN, IMPRIMIR LA DIAGONAL SECUNDARIA
   CALCULAR E IMPRIMIR SU SUMA */

#include <stdio.h>
#include <conio.h>
#include <dos.h>
void main()
{
int *base,*dir;
int A[10][10],lif,lsf,z1,lic,lsc,col,n1,k,B[10],suma,salto,i,j;
clrscr();
printf("DE EL # DE LAS FILAS Y LAS COLUMNAS DE LA MATRIZ QUE CREARA: ");
do{
scanf("%d",&n1);

}while (n1<=0);
printf ("DE EL LIMITE INFERIOR DE LAS FILAS Y LAS COLUMNAS  =");
do{
scanf ("%d",&lif);
}while (lif<0);
lic=lif;
z1=10-n1;


/* CALCULO DE LOS LIMITES */

		     lsf=lif+n1-1;
		     salto=lsf+z1-lic;

/* LECTURA DE LA MATRIZ */

	       for (i=lif;i<=lsf;i++){
		   for (j=lif;j<=lsf;j++){
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&A[i][j]);
			dir=&A[i][j];
		    }
		}
/* USO DE LA FUNCION DE ACCESO PARA UNA MATRIZ */
		suma=0;
		base=&A[lif][lif];
		for (i=lif;i<=lsf;i++){
		     dir=base+(i-lif)*salto+(n1-1);
		     B[i]=*dir;
		     suma+=*dir;
		 }


printf("\nLA SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA ES= %d\n\n",suma);
printf("Y SU CORRESPONDIENTE DIRECCION ES =  %04X : %04X \n\n\n" ,FP_SEG(dir),FP_OFF(dir));


    base=&B[lif];
    printf("LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA SON :\n");
    for (i=lif;i<=lsf;i++){
    dir=base+i-lif;
    printf("B[%d]=%d    " , i, *dir);
    printf(" CUYA DIRECCION ES =  %04X : %04X \n" ,FP_SEG(dir),FP_OFF(dir));
      }
   getch();
}



