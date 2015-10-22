#include <stdio.h>
#include <conio.h>



main (){


int producto (int,int);
int n,produ,a,b;


clrscr();

printf ("Digite dos  Numeros :  ");

scanf("%d %d",&a,&b);


produ=producto(a,b);

printf ("El producto de %d por %d  es : %d ",a,b,produ);


getch();
}




int producto(a,b){

 int prod;

 if (b==1)
      prod = a;

 else{

    prod=a+producto(a,b-1);

 }
 return prod;

}
