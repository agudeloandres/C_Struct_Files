#include <stdio.h>
#include <dos.h>
void main()
{
int *base,*dir;
int a[10][10],lif,con,lsf,m1,lic,lsc,col,n,k,m[10],sum,s,i,j;
printf("Dar el n�mero de filas y columnas de la matriz=");
do{
scanf("%d",&n);
}while (n<=0);
printf ("Dar el l�mite inferior de las filas y columnas=");
do{
scanf ("%d",&lif);
}while (lif<0);
m1=10-n;
lic=lif;
//C�lculo de los l�mites
lsf=lif+n-1;

s=(lsf+m1-lic+1);

//Captura de la matriz
for (i=lif;i<=lsf;i++){
  for (j=lif;j<=lsf;j++){
     printf("a[%d][%d]=",i,j);
     scanf("%d",&a[i][j]);
     dir=&a[i][j];
   }
}
/*Aqu� se usa la funci�n de acceso a funci�n de direccionamiento en
una matriz*/
sum=0;
base=&a[lif][lif];
lic++;
 con=0;
 for (i=lif;i<=lsf-1;i++){
      col=(i-lif)*s;
      
    for (j=lic;j<=lsf;j++){
     dir=base+col+(j-lif);
      con++;
      m[con]=*dir;
      sum+=*dir;
     }
     lic++;
     }
printf("\n visualizaci�n de la suma de los elemtos de la triangular superior=%d\n",sum);

printf("direcci�n=%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
	
     
base=&m[lif];
printf("Visualizaci�n de los elementos de la trangular superior:\n");
   for (i=1;i<=con;i++){
	dir=base+i-lif;
        printf("m[%d]=%d    ",i,*dir);
	printf("direcci�n=%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
    }
    }




