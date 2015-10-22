#include<stdio.h>
#include<dos.h>
#include<conio.h>
#define N 3
void main()
{
 float A[N][N],V[3],sum;
 float *dir,*base;
 int i,j,n,s,lif,lsf,lic,lsc,fil,col;
 clrscr();
 printf("DIGITE NUMERO DE FILAS Y COLUMNAS DE LA MATRIZ: ");
 do{
    scanf("%d",&n);
   }
   while(n<=0 || n>3);
 lif=0;
 lic=0;
 lsf=lif+n-1;
 lsc=lic+n-1;
 s=lsc-lic+1;
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
	printf("A[%d][%d]=",i,j);
	scanf("%f",&A[i][j]);
    }
 }
 //CALCULO DEL VECTOR
 for(i=0;i<n;i++){
   sum+=A[i][j];
   // sum=0;
    for(j=0;j<n;j++){
       //sum+=A[i][j];
    }
   // V[i]=sum;
 }
 //IMPRIMIR A[i][j] CON FUNCION DE ACCESO
 printf("\n");
 base=&A[0][0];
 printf("DIRECCIONES DE LOS ELEMENTOS DE LA MATRIZ \n\n");
 for(i=0;i<n;i++){
    fil=(i-lif)*s;
    for(j=0;j<n;j++){
       col=j-lic;
       dir=base+fil+col;
       printf("A[%d][%d]=%4.2f",i,j,A[i][j],*dir);
       printf("  DIRECCION= %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
    }
 }
 printf("La suma de los elementos de las filas es:%d",sum);


 //IMPREMENTAR EL VECTOR
 /*printf("\n");
 printf("VECTOR DE LA SUMA DE LAS FILAS DE LA MATRIZ\n\n");
 base=&V[0];
 for(i=0;i<n;i++){
    fil=i-lif;
    dir=base+fil;
    printf("V[%d]=%4.2f",i,*dir);
    printf(" DIRECCION= %04x:%04x\n",FP_SEG(dir),FP_OFF(dir));
 }*/
 getch();
}