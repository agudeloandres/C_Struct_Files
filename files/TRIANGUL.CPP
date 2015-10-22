/* programa que hace triangulos*/

# include <stdio.h>
# include <conio.h>


main()
{

clrscr();
int silak,ismel,alexa,nico;

gotoxy(5,1);printf("Digite la Base y la Altura  B[  ], A[  ]");
gotoxy(35,1);scanf("%d",&alexa);
gotoxy(42,1);scanf("%d",&nico);
clrscr();
//-------------------------------------------------------------------------
//Primer triangulo
// altura
for (silak=1;silak<=nico;silak++){
gotoxy(1,silak);
printf("*");
}
//base
for (ismel=1;ismel<=alexa;ismel++){
gotoxy(ismel,nico);
printf("*");
}
// Hipotenusa
for (ismel=alexa;ismel>=1;ismel--){
gotoxy(ismel,ismel);
printf("*");
gotoxy(25,25);
printf("Primer Triangulo");
}
getch();

//--------------------------------------------------------------------------
// Segundo triangulo
 clrscr();
//altura
for (ismel=alexa;ismel>=1;ismel--){
gotoxy(nico,ismel);
printf("*");
}
 //base
for (silak=1;silak<=nico;silak++){
gotoxy(silak,1);
printf("*");
}
//hipotenusa
for (nico=1;nico<=alexa;nico++){
gotoxy(nico,nico);
printf("*");
gotoxy(25,25);
printf("Segundo triangulo");
}
getch();

//--------------------------------------------------------------------------
//Tercer triangulo

 clrscr();
//altura
for (silak=1;silak<=nico-1;silak++){
gotoxy(alexa,silak);
printf("*");
}
//base
for (ismel=1;ismel<=alexa;ismel++){
gotoxy(ismel,nico-1);
printf("*");
}
//hipotenusa
for (silak=1;silak<=nico;silak++){
for (ismel=nico-1;ismel>=1;ismel--){
gotoxy(ismel,nico-ismel);
printf("*");
gotoxy(25,25);
printf("Tercer triangulo");
}
}
getch();

//--------------------------------------------------------------------------
// Cuarto triangulo
 clrscr();
//altura
for (silak=1;silak<=nico-1;silak++){
gotoxy(1,silak);
printf("*");
}
//base
for (ismel=alexa;ismel>=1;ismel--){
gotoxy(ismel-1,1);
printf("*");
}
//hipotenusa
for (silak=1;silak<=nico;silak++){
for (ismel=nico-1;ismel>=1;ismel--){
gotoxy(ismel,nico-ismel);
printf("*");
gotoxy(25,25);
printf("Cuarto Triangulo");
}
}
getch();
clrscr();
}

