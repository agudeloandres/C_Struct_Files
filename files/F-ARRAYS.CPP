#include <stdio.h>
#include <conio.h>

void swap (int,int);//Prototipo

main () {
 clrscr();
int a[]={8,7,8,8,2,1};
int f[10]={0};

void promedio (int []);//Prototipo
void mediana (int []);//Prototipo
void moda (int [],int []);//Prototipo

promedio (a);
mediana (a);
moda (f,a);

getch();
}

void promedio (int x []){
int i,t=0;
for (i=0;i<=5;i++)
t+=x[i];
printf("El promedio de la suma de los elementos del vector es : %.2f",(float) t/6);
}

void mediana (int y []){
int w,v;
for (w=0;w<=4;w++)
 for (v=w+1;v<=5;v++)
  if (y[w] > y[v])
   swap (y[w],y[v]);
   printf ("\nLa mediana es %d ",y[3]);

}


void swap (int a1,int b1){
int temp;

 temp=a1;
 a1=b1;
 b1=temp;
}

void moda (int fr[],int x[]){
 int ei,m=x[0],k=0;
  for (ei=0;ei<=5;ei++)
    ++fr[x[ei]];

    for (ei=0;ei<=5;ei++)
      if (m < x[ei]){
       m= x[ei];
	k=ei;
	 }
	 printf ("\nEl numero %d se repite %d veces ", m,k);
	 }
