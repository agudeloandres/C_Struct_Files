#include <dos.h>
#include <conio.h>
#include<stdio.h>
#include <string.h>

void main (){
char * num,*a,*b;
textbackground(1);textcolor(15);
clrscr();
gotoxy(10,5);
highvideo();
cprintf("Digite una cadena de caracteres maximo de 4 digitos : ");
num[0]=5;   //Recibe maximo 4 digitos y el caracter de fin '\0'
cgets(num);
gotoxy(10,7);
lowvideo();
cprintf("Numero = %s",num+2);
gotoxy(10,9);
strcpy(a,"Numero Digitado= ");strcat(a,num+2);cprintf(a);
gotoxy(10,11);cputs(num+2);
getch();
}