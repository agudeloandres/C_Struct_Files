#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
clrscr();
int *base,*direcc;
int matriz[10][10],o,x,p,a;
int d,s,n,v,vec[10],sum,h,l,j;
gotoxy(9,3);
printf("INGRESE NUMERO DE LAS FILAS Y DE LAS COLUMNAS : " );

do{
	scanf("%d",&n);
	}while (n<=0);

printf ("INGRESE EL LIMITE INFERIOR DE LAS FILAS Y DE LAS COLUMNAS : ");
do{
	scanf ("%d",&o);
	}while (o<0);
	a=o;
	p=10-n+1;

//LIMITES

x=o+n-1;

h=x+p-a+1;

//MATRIZ

for (l=o;l<=x;l++){
	for (j=o;j<=x;j++){
		printf("matriz[%d][%d]=",l,j);
		scanf("%d",&matriz[l][j]);
		direcc=&matriz[l][j];
	}
}

//SE UTILIZA LA FUNCION DE ACCESO PARA DIRECCIONAMIENTO DE LA MATRIZ

sum=0;
base=&matriz[o][o];
	for (l=o;l<=x;l++){
		direcc=base+(l-o)*h;
		vec[l]=*direcc;
		sum+=*direcc;
}

printf("\n SE MUESTRA LA SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL %d\n",sum);

printf("DIRECCION %04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));


base=&vec[o];
printf("SE MUESTRAN LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL :\n");
	for (l=o;l<=x;l++){
	direcc=base+l-o;
	printf("MATRIZ[%d]=%d    ",l,*direcc);
	printf("DIRECCION =%04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));
	}
getch();
}
