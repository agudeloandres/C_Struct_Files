#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
int *base,*direcc;
int matriz[10][10],o,x,p,a;
int d,s,n,v,z,sum[10],h,l,j;
clrscr();
gotoxy(9,3);
printf("INGRESE EL NUMERO DE FLIAS DE LA MATRIZ : ");
	do{
	scanf("%d",&n);
	}while (n<=0);
gotoxy(9,5);
printf("INGRESE EL NUMERO DE COLUMNAS DE LA MATRIZ : ");
	do{
	scanf ("%d",&z);
	}while (z<=0);
gotoxy(5,7);
printf ("INGRESE EL LIMITE INFERIOR DE LAS FILAS Y DE LAS COLUMNAS : ");
	do{
	scanf ("%d",&o);
	}while (o<0);

a=o;
p=10-z;

//LIMITES

x=o+n-1;
d=a+z-1;
h=d+p-a+1;

//MATRIZ

for (l=o;l<=x;l++){
	  for (j=a;j<=d;j++){
     		printf("MATRIZ[%d][%d]=",l,j);
     		scanf("%d",&matriz[l][j]);
     	  direcc=&matriz[l][j];
   	}
}
//SE UTILIZA LA FUNCION DE ACCESO PARA EL DIRECCIONAMIENTO DE LA MATRIZ

base=&matriz[o][a];
for (l=o;l<=x;l++){
        s=(l-o)*h;
    	sum[l]=0;
   	 for(j=a;j<=d;j++){
      		direcc=base+s+(j-a);
	 	sum[l]+=*direcc;
 	    }
}

printf("\nSE MUESTRA LA MATRIZ USANDO FUNCIONES DE ACCESO\n");
for(l=o;l<=x;l++){
       s=(l-o)*h;
	       for (j=a;j<=d;j++){
	       		direcc=base+s+(j-a);
               		printf("MATRIZ[%d][%d]=%d   ",l,j,*direcc);
	  		printf("DIRECCION =%04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));
		}
}

base=&sum[o];
	printf("\nSE MUESTRA EL VECTOR CON LA FUNCION DE ACCESO\n");
		for (l=o;l<=x;l++){
			direcc=base+l-o;
			printf("SUM[%d]=%d    ",l,*direcc);
			printf("DIRECCION= %04x:%04x\n",FP_SEG(direcc),FP_OFF(direcc));
    		}
}




