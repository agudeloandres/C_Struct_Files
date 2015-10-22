#include <stdio.h>
#include <dos.h>
#include <conio.h>

//programa para mostrar uso de funcion de acceso vector


void main (){
int *base,*dir;
int a [3][3], lif, lsf, lic, lsc,s, col, n,k, m,sum[3],i,j;
clrscr();
printf("DAR EL NUMERO DE FILAS DE LA MATRIZ = ");
do {
scanf("%d",&n);
} while (n<=0);

printf("DAR EL NUMERO DE COLUMNAS DE LA MATRIZ =");
do{
scanf("%d",&m);
}while (m<=0);

printf("DAR EL LIMITE INFERIOR DE LAS FILAS = ");
do {
scanf ("%d",&lif);
}while (lif<0);

printf("DAR EL LIMITE INFERIOR DE LAS COLUMNAS = ");
do{
scanf("%d",&lic);
} while (lic<0);

// CALCULO DE LIMITES

lsf=lif+n-1;
lsc=lic+m-1;
s=lsc-lic+1; //LONGITUD DE CADA BLOQUE (FILAS) POR COLUMNAS

// CAPTURA DE LA MATRIZ

for (i=lif;i<=lsf;i++){
  for (j=lic;j<=lsc;j++){
       printf("a[%d][%d] = " ,i,j);
       scanf("%d",&a[i][j]); // SE LLENA POR FILAS SI FUERA a[j][i] FUERA
       dir=&a[i][j];         // POR COLUMNAS
   }
}

//AQUI SE USA FUNCION DE ACCESO O FUNCION DE DIRECCIONAMIENTO EN UNA MATRIZ

base=&a[lif][lic];
 for (i=lif;i<=lsf;i++){
    col=(i-lif)*s;
    sum[i]=0;
    for (j=lic;j<=lsc;j++){
       dir = base+col+(j-lic);
       sum[i]+=*dir;
    }
 }

 printf("\nVISUALIZACION DE LA MATRIZ a USANDO FUNCIONES DE ACCESO\n\n");
  for(i=lif;i<=lsf;i++){
      col=(i-lif)*s;
      for (j=lic;j<=lsc;j++){
	  dir = base+col+(j-lic);
	  printf("a[%d][%d] = %d      ",i,j,*dir);
	  printf("DIRECCION = %04x : %04x\n", FP_SEG(dir),FP_OFF(dir));
      }
  }


 printf("\nVISUALIZACION DEL VECTOR a USANDO FUNCIONES DE ACCESO\n\n");
   for (i=lif;i<=lsf;i++){
       dir =base+i-lif;
       printf("SUM[%d] = %d           ",i,*dir);
       printf("DIRECCION = %04x : %04x \n",FP_SEG(dir),FP_OFF(dir));
   }

getch();
}