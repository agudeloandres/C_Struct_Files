#include <conio.h>
#include <stdio.h>
#include <dos.h>
void main()
{
int *base,*dir;
int a[4][4][4],y,y1,m2,col1,s1,lit,lst,lif,lsf,m1,lic,lsc,col,n,k,m,s,i,j;
clrscr();
printf("DAR EL NUMERO DE FILAS DE LA MATRIZ = ");
do{
scanf("%d",&n);
}while (n<=0);
printf("DAR EL NUMERO DE COLUMNAS DE LA MATRIZ = ");
do{
scanf("%d",&m);
}while (m<=0);
printf("DAR EL NUMERO DE PAGINAS DE LA MATRIZ = ");
do{
scanf("%d",&y);
}while (y<=0);

printf ("DAR LOS LIMITES INFERIORES = ");
do{
scanf ("%d",&lif);
}while (lif<0);
lic=lif;
lit=lif;
m1=4-y;   //Dimensionar la altura de la matriz
m2=4-m;   //Dimensionar las columnas de la matriz
//Calculo de los limites
lsf=lif+n-1;  //Calculo del limite superior de filas
lsc=lic+m-1;  //Calculo del limite superior de columnas
lst=lit+y-1;  //Calculo del limite superior de paginas
s=(lsc-lic+1+m2); //Salto de Columna en Columna (Salto intermedio) = 8bytes
s1=(lst-lit+1+m1)*s; //Salto de Fila en Fila (Salto mayor) = 32 bytes
//k= 2 bytes Salto de pagina en pagina (Salto menor) = 2 bytes
//Captura de la matriz
for (i=lif;i<=lsf;i++){     //Fila
  for (j=lic;j<=lsc;j++){  //Columna
     for (k=lit;k<=lst;k++){ //Pagina
     printf("a[%d][%d][%d] = ",i,j,k); //Se llena por filas y por Columnas
     scanf("%d",&a[i][j][k]);         // y por ultimo por paginas
     //dir=&a[i][j][k];
   }
}
}
/*Aqui se usa la funcion de acceso a funcion de direccionamiento en
una matriz*/
base=&a[lif][lic][lit];
getch();
clrscr();
printf("\nVISUALIZACION DE LA MATRIZ USANDO FUNCIONES DE ACCESO :\n");
     for(i=lif;i<=lsf;i++){
       col=(i-lif)*s1;
       for (j=lic;j<=lsc;j++){
	  col1=(j-lic)*s;
	for (k=lit;k<=lst;k++){
	  dir=base+col+col1+(k-lit);// dir =base + (i-lif)*s1 + (j-lic)*s + (k-lit)*k
	  printf("a[%d][%d][%d] = %d  ",i,j,k,*dir);
	  printf("DIRECCION = %04x : %04x\n",FP_SEG(dir),FP_OFF(dir));
	}
     }
     }
	 getch();
    }


