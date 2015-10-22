#include<conio.h>
#include <stdlib.h>
#include <stdio.h>           //Funciones getch,getche,getchar
void main (){

char c,ch,cha;
clrscr();
textcolor(WHITE);
printf("GETCHAR\n");
printf("Digita un Caracter : ");
c=getchar();
printf("El caracter fue :  ");
putchar(c);
printf("\n\nGETCHE\n");
printf("Digita otro caracter :  ");
ch=getche();
printf("\nEl caracter fue : ");
putchar(ch);
printf("\n\nGETCH\n");
printf("Digita otro caracter :  ");
cha=getch();
printf("\nEl caracter fue :  ");
putchar(cha);
getch();
}