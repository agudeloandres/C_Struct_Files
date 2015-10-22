#include<conio.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{

   int n,n2;
   char *str = "hello man is a good day to go fishing",*str2;
   clrscr();
   n = atoi(str);
   printf("digita una frase\n");
   gets(str2);
   n2=atoi(str2);
   printf("string =%s ; integer %d\n",str2,n2);
   printf("string = %s ; integer = %d\n", str, n);
   puts(str);
   puts(str2);
   getch();
   return 0;
}
