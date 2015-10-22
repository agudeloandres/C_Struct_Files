#include<stdio.h>
#include<dos.h>
#include<conio.h>

void main()
   {
   clrscr();
int *base;
int *dir;
int M[10][10],cont,s,lif,lsf,ma,lic,lsc,c,n,k,m[10],sm,i,j;

gotoxy(22,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(23,3);
printf("PROGRAMA DE INGENIERIA DE SISTEMAS");
gotoxy(29,4);
printf("ESTRUCTURA DE DATOS I");
gotoxy(25,5);
printf("MATRIZ TRIANGULAR SUPERIOR (NXN)\n\n");
printf("DIGITE EL NUMERO DE FILAS: ");
 scanf("%d",&n);
printf("DIGITE EL NUMERO DE COLUMNAS: ");
 scanf("%d",&s);
printf("DIGITE EL LIMITE INFERIOR DE LAS FILAS : ");
do{
  scanf("%d",&lif);
} while(lif<0);

ma=10-n;
lic = lif;

//CALCULANDO LOS LIMITES DE LA MATRIZ

lsf = lif+n-1;
s=(lsf+ma-lic+1);

//GENERAR LA MATRIZ M[I][J]
int sil=40-(s+4),b=10;

for(i=lif;i<=lsf;i++){
    sil=40-(s+4);
  for(j=lif;j<=lsf;j++){
      gotoxy (sil,b);
      scanf("%d",&M[i][j]);
      dir=&M[i][j];
      sil+=4;
   }
   b+=2;
}
printf("\n");

    //UTILIZANDO FUNCION DE ACCESO


base=&M[lif][lif];
lic++;
cont=0;

for(i=lif;i<=lsf-1;i++){
    c=(i-lif)*s;
    for(j=lic;j<=lsf;j++){
       dir=base+c+(j-lif);
       cont++;
       m[cont]=*dir;
    }
    lic++;
}
base=&m[lif];
printf("               LOS ELEMENTOS DE LA TRIANGULAR SUPERIOR SON: \n\n");
for(i=1;i<=cont;i++){
   dir=base+i-lif;
   printf("\tm[%d]=%d      ",i,*dir);
}

getch();
getch();
}
