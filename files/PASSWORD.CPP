#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

void password (void);
main (){
password();
}

void password (void){
int i;
char c,pas2[9],pas[]= "macintosh";

clrscr();
for (i=0;i<=9;i++){
 c=getch();
 pas2[i]=c;
 printf("*");
 /*if (c != pas[i]){
   printf("\nPassword Incorrecto.....Oprima una tecla \n");
   getch();
   exit(1);
 } */
}

if (strcmp(pas2,pas)==0)
printf("\nPassword Correct.....\n");
else{
 printf("\nPassword Incorrecto.....Oprima una tecla \n");
   getch();
   exit(1);
 }

}


