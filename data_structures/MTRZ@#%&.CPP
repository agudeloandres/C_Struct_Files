/*hacer un programa c++ que dada una matriz a[i][j] i=lif y j=lic
con n*m elementos (verificarque n>0 y m>0). construir un vector suma[i]
imprimir a[i][j] y suma[i] usando la funcio de acceso cada elemento de
suma[i] contiene la suma de los elementos de la fila i de la matriz*/
#include <conio.h>
#include<stdio.h>
#include<dos.h>
void main()
{

float A[10][10],suma[20],sum;
int i,j,n,m,lif,lsf,lic,lsc,fil,col,s;
float *dir,*base;
clrscr();
printf("digite numero de filas y # de columnas\n");
do{
scanf("%d",&n);
scanf("%d",&m);
}while(n<0 && m<0);
//declaracion de los limites
lif=0;
lic=0;
lsf=lif+n-1;
lsc=lic+m-1;
s=lsc - lic+1;
//lectura de matriz

for(i=0;i<n;i++){
    for(j=0;j<m;j++){
	 printf("A[%d,%d]=",i,j);
	 scanf("%f",&A[i][j]);
	 }}
//calcula del vector[i]
for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<m;j++){
	   sum+=A[i][j];
	   }
    suma[i]=sum;
    printf("\n");
	   }
//imprimir A[i][j] con funcion de acceso
	base=&A[0][0];
	for(i=0;i<n;i++){
	       fil=(i-lif)*s;
	       for(j=0;j<m;j++){
		   col=j-lic;
		   dir=base+fil+col;
		   printf("\n");
printf(" A[%d,%d]=  %04.2f\n",i,j,*dir);
printf(" dirrecc =   %04x : %04x\n",FP_SEG(dir),FP_OFF(dir));
}}
//imprimir vector
base=&suma[0];
for(i=0;i<n;i++){
	fil=i-lif;
	dir=base+fil;
	printf("\n");
printf(" suma[%d]=  %4.2f\n",i,*dir);
printf("direccion: %04x : %04x\n",FP_SEG(dir),FP_OFF(dir));
getch();
} }