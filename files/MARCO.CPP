#include<stdio.h>
#include<conio.h>
#include<dos.h>

main (){
int q,q2,q3,q4;

clrscr();
gotoxy(0,0);
printf("�");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("�");
}
gotoxy(79,0);
printf("�");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("�");
}
gotoxy(80,24);
printf("�");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("�");}

gotoxy(1,24);
printf("�");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("�");}
getch();
}