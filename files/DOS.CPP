/* programa que puede insultarte si haces ejercicios bobos */
#include <stdio.h>
#include <stdlib.h>
   main()

{
 system ("cls");
 int a,b,prom,sum;

 printf("digite dos numeros enteros para analizarlos \n");
 scanf("%d %d",&a,&b);

 if (a>b)
	 { printf("%d es mayor que %d \n",a,b);
	  printf("su sumatoria es %d \n",(a+b));
						}
 if (a<b) {
	  printf("%d es mayor que %d \n",b,a);
	  printf("su producto es %d \n",(a*b));
       }

}

