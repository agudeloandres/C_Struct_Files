#include<stdio.h>
#include<conio.h>
#include<dos.h>

main(){
int o,q,q2,q3,q4;


clrscr();
gotoxy(0,0);
printf("ษ");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("อ");
delay(15);
}
gotoxy(79,0);
printf("ป");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("บ");
delay(15);
}
gotoxy(80,24);
printf("ผ");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("อ");
delay(15);
}

gotoxy(1,24);
printf("ศ");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("บ");
delay(15);
}
i:
clrscr();
gotoxy(0,0);
printf("ษ");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("อ");
}
gotoxy(79,0);
printf("ป");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("บ");
}
gotoxy(80,24);
printf("ผ");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("อ");}

gotoxy(1,24);
printf("ศ");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("บ");}

gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("ESTRUCTURA DE DATOS\n");
gotoxy(32,7);
printf("MENU PRINCIPAL");
gotoxy(18,11);
printf("1. ENTRADA DE DATOS");
gotoxy(18,14);
printf("2. OPERACIONES");
gotoxy(18,17);
printf("3. CONSULTAR DATOS");
gotoxy(18,20);
printf("4. TERMINAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);
scanf("%d",&o);
switch (o){
 case 1 : case 2 : case 3 :

  gotoxy(34,25);
  printf("No Validada");
  delay(800);
  goto i;

  case 4:
   break;
  default:
    gotoxy(36,25);
    printf("ญญ ERROR !!");
   delay(500);
   goto i;

   } //Cierra Switch

}  //FIN