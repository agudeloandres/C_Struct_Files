
#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
clrscr();
int *base,*direcc;
int matriz[10][10],o,x,p,a,d,s;
int n,v,mat[10],sum,h,l,j;
gotoxy(9,3);
printf("INGRESAR EL NUMERO DE LAS FILAS Y LAS COLUMNAS DE LA MATRIZ : ");
do{
scanf("%d",&n);
	}while (n<=0);
		gotoxy(9,5);
		printf ("INGRESAR EL LIMITE INFERIOR DE LAS FILAS Y LAS COLUMNAS : ");
	do{
scanf ("%d",&o);
	}while (o<0);
		a=o;
		p=10-n;

//LIMITES

x=o+n-1;
h=x+p-a;

//MATRIZ
for (l=o;l<=x;l++){
	for (j=o;j<=x;j++){
		printf("matriz[%d][%d]=",l,j);
			scanf("%d",&matriz[l][j]);
		direcc=&matriz[l][j];
	}
}
//SE UTILIZA LA FUNCION DE ACCESO PARA EL DIRECCIONAMIENTO DE LA MATRIZ

sum=0;{
base=&matriz[o][o];
	for (l=o;l<=x;l++){
		direcc=base+(l-o)*h+(n-1);
			mat[l]=*direcc;
		sum+=*direcc;
       }
printf("\n SE MUESTRA LA SUMA DE LOS ELEMNTOS DE LA DIAGONAL SECUNDARIA %d\n", sum);

printf("DIRECCION" "%04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));


base=&mat[o];
printf("SE MUESTRAN LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA:\n");
	for (l=o;l<=x;l++){
		direcc=base+l-o;
			printf("mat[%d]=%d    ",l,*direcc);
		printf("DIRECCION=%04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));
	}

}
getch();
}
