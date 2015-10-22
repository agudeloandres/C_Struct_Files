
#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
int *base,*dir;
int a[4][4][4],m3,y,y1,m2,col1,s1;
int lit,lst,lif,lsf,m1,lic,lsc,col,n,k,m,sum[10],s,i,j;
gotoxy(14,3);
printf("ingrese el número de filas de la matriz : ");
do{
scanf("%d",&n);
}while (n<=0);
gotoxy(14,5);
printf("ingrese el número de columnas de la matriz : ");
do{
scanf("%d",&m);
}while (m<=0);
gotoxy(14,7);
printf("ingrese el número de altura de la matriz : ");
do{
scanf("%d",&y);
}while (y<=0);
gotoxy(14,9);
printf ("ingrese los límites inferiores : ");
do{
scanf ("%d",&lif);
}while (lif<0);
lic=lif;
lit=lif;
m1=4-y;
m2=4-m;
//m3=m2+m;
// límites
lsf=lif+n-1;
lsc=lic+m-1;
lst=lit+y-1;
s=(lsc-lic+1+m2);
s1=(lst-lit+1+m1)*s;
//matriz
for (i=lif;i<=lsf;i++){
  for (j=lic;j<=lsc;j++){
     for (k=lit;k<=lst;k++){
     printf("a[%d][%d][%d]=",i,j,k);
     scanf("%d",&a[i][j][k]);
     dir=&a[i][j][k];
   }
}
}
// función de direccionamiento 

base=&a[lif][lic][lit];
printf("\n visualización de la matriz usando funciones de acceso\n");
     for(i=lif;i<=lsf;i++){
       col=(i-lif)*s1;
       for (j=lic;j<=lsc;j++){
          col1=(j-lic)*s;
	for (k=lit;k<=lst;k++){
	  dir=base+col+col1+(k-lit);
          printf("a[%d][%d][%d]=%d   ",i,j,k,*dir);
	  printf("dirección=%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
	}              
     }
     }

    }





