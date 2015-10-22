#include<stdio.h>
#include<conio.h>
#include<dos.h>

//GENERA  UN VECTOR LLAMADO SUMA CON LA SUMA DE CADA FILA

void main()
{
clrscr();
int *base,*dir;
int lif,dimx,dimy,lic,lsf,lsc,s,i,j,n,m,col;
int a[3][3],suma[3];

printf("\nDAR EL NUMERO DE FILAS: ");
do{
  scanf("%d",&n);
}while(n<=0);
printf("DAR EL NUMERO DE COLUMNAS: ");
do{
  scanf("%d",&m);
}while(m<=0);
printf("\nDAR EL LIMITE INFERIOR DE LA FILA: ");
do{
  scanf("%d",&lif);
}while(lif<0);
printf("DAR EL LIMITE INFERIOR DE LAS COLUMNAS: ");
do{
  scanf("%d",&lic);
}while(lic<0);
//c lculo de limites
lsf=lif+n-1;
lsc=lic+m-1;
s=lsc-lic+1;
//captura de la matriz
for(i=lif;i<=lsf;i++){
   for(j=lic;j<=lsc;j++){
     printf(" a[%d][%d]=  ",i,j);
     scanf("%d",&a[i][j]);
     dir=&a[i][j];
   }
}
base=&a[lif][lic];
for(i=lif;i<=lsf;i++){
   suma[i]=0;
   col=(i-lif)*s;
   for(j=lic;j<=lsc;j++){
      dir=base+col+(j-lic);
      suma[i]+=*dir;
      printf("\ta[%d][%d]= %d", i,j,*dir);
    }
   printf("      suma[%d]= %d\n",i,suma[i]);
}
getch();
}


