 //ORDENAMIENTO DE BURBUJA//
#include <stdio.h>
#include <conio.h>
main () {
 clrscr();

 void swap(int *, int *);//Prototipo
 int may (int []);//Prototipo

 int a []={8,7,6,5,2,9,3,1,8,9};
 int i=0,j=0,k,c;
 printf("\tANTES\n\n");
 for(c=0;c<=9;c++)
  printf("%4d",a[c]);
 for (i=0;i<=8;i++)
   for (j=i+1;j<=9;j++)
    if (a[i] > a[j])
     swap (&a[i],&a[j]);

  printf("\n\n\tDESPUES\n\n");
 for (k=0;k<=9;k++)
   printf("%4d",a[k]);
  printf ("\n\n\tEl mayor elemento del vector es : %d\n", may (a));
 getch();
}





void swap (int *el1,int *el2) //ORDENA ASCENDENTEMENTE DE MENOR A MAYOR EL
 {                            //ARREGLO.
 int temp;
 temp=* el1;
 * el1=* el2;
 * el2=temp;
 }


 int may (int b[] ){        //FUNCION QUE DETERMINA EL ELEMENTO MAYOR DEL
 int j1,c1, mayor=b[0];    //VECTOR
 for(j1=1;j1<=9;j1++)
  if (mayor< b[j1]){
   mayor=b[j1];
    }
    return mayor;
    }
