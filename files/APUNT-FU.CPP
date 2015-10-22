# include <stdio.h>
#include <conio.h>
# define SIZE 10
void swap(int *, int *);
main () {
clrscr();
int a [SIZE]={8,2,4,7,3,9,1,4,9,5};
int counter,order;
void bubble (int *, int,int (*)(int,int));
int ascending (int,int);
int descending(int,int);

printf("teclee 1 para ordenar ascendentemente \n");
printf ("teclee 2 para ordenar descendentemente \n");
scanf("%d",&order);

printf("antes del ordenamiento.....\n");
for (counter=0;counter<=SIZE-1;counter++)
printf ("%4d",a[counter]);
if (order==1){
bubble(a,SIZE,ascending);
printf("\ndespues de ordenar ascendentemente \n");
}
else {
      bubble (a,SIZE,descending);
      printf("\ndespues de ordenar descendentemente \n");
      }

for (counter=0;counter<=SIZE-1;counter++)
  printf("%4d",a[counter]);
  getch();
  }
//******************************FUNCIONES*************************************


void bubble (int *work,int tam,int (* compare)(int,int)){ //es un apuntador a
int pass, count;					  // a una funcion
for (pass=0;pass<=SIZE-2;pass++)
     for (count=0;count<=SIZE-2;count++)
      if ((*compare)(work[count],work[count+1]))
       swap(&work[count],&work[count+1]);

}
void swap (int *EL1,int *EL2)
{
int temp;
temp=*EL1;
*EL1=*EL2;
*EL2=temp;
}

 int descending (int a,int b) {
 return a<b;   //retorna 1 o 0 si es verdadero o falso (verdadero si a<b o
 }            //falso si no lo es)

 int ascending (int a , int b){
 return a>b; //retorna 1 o 0 si es verdadero o falso (verdadero si a>b o
 }           //falso si es a<b)
