
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
// definicion del registro base dotos

typedef struct notas {
	       float codigo ;
	       char  nombre[30];
	       float calf1;
	       float calf2;
	       float calf3;
	       float defini;
	       float deftotal;
	    };
main()
{
ini:
notas estudent[60],*ptr;
int n,i,j,r,lon,ini,pro,ice;
float co,defini=0,deftotal=0,PromEst=0,PromCur=0;
float nota1,nota2,nota3,prom=0;
float sutal=0,sum1=0,sum2=0,sum3=0;
char nom[30],c;

do{
clrscr();
gotoxy(20,2);printf("             MENU PRINCIPAL\n\n\n");
	printf("                   1. < CAPTURA DE REGISTROS\n\n");
	printf("                   2. < PROMEDIOS (A y C)\n\n");
	printf("                   3. < ORDENAMIENTOS\n\n");
	printf("                   4. < TERMINAR\n\n\n\n");
	printf(" DIGITE OPCION [  ]");

gotoxy(18,15);
scanf("%d",&ice);
}while( ice<0 || ice >4);
switch(ice){
case 1:
  clrscr();
  printf(" \n\n\n\nNUMERO DE ESTUDIANTES A CAPTURAR....[");
   do{
   scanf("%d",&n);
	 } while(n<0 && n>60);

		  // lectura  y asignacion de datos a cada registro
	ptr=&estudent[0];
	for(i=1; i<=n;i++){
	clrscr();
	sutal=0,deftotal=0;
		 printf("\n\nCODIGO DEL ESTUDIANTES    ");
			scanf("%f",&co);
		 printf("\n\nNOMBRE DEL ESTUDIANTES : ");
			cin.getline(nom,30);
		 printf("\n\nPrimera Nota ...... " );
			scanf("%f",&nota1);
			sum1= nota1*0.35;
		 printf("\n\nSegunda Nota ...... ");
			scanf("%f",&nota2);
		 sum2= nota2*0.35;
		 printf("\n\nTercera Nota: .....");
			scanf("%f",&nota3);

  sum3=nota3*0.30;
  sutal+=sum1+sum2+sum3;
  PromEst=(nota1+nota2+nota3)/3;
  PromCur+=PromEst;

ptr->codigo=c;
lon = strlen(nom);
for(j=0;j<=lon;j++){
ptr->nombre[j]=nom[j];
ptr->defini=sutal;

}
ptr->calf1=nota1;
ptr->calf2=nota2;
ptr->calf3=nota3;
ptr->defini=sutal;
ptr->deftotal=PromCur/n;
ptr++;
}
goto ini;

case 2:
do{
pro:
clrscr();
gotoxy(30,2);
printf("MOSTRARIO DE LOS PROMEDIOS\n\n\n");
  printf("                 1 <PROMEDIO DE ESTUDIANTES\n\n");
  printf("                 2 <PROMEDIO DEL CURSO\n\n");
  printf("                 3 <TERMINAR\n\n\n\n");
  printf("        DIGITE OPCION  [  ]");
  gotoxy(26,13);
 scanf("%d",&ice);
if(ice== 1){
clrscr();
gotoxy(20,4);printf("           PROMEDIO DEL ESTUDIANTE");
gotoxy(5,8);printf("CODIGO       NOMBRE                    NOTA.1  NOTA.2  NOTA.3   DEFI\n ");
ptr=&estudent[0];
j=10;

for(i=0;i<n;i++){
defini=sutal;
gotoxy(5,j);printf("%7.0f       %s  %1.2f   %1.2f   %1.2f    %1.2f ",ptr->codigo,ptr->nombre,ptr->calf1,ptr->calf2,ptr->calf3,ptr->defini);
ptr++;
j++;
}
getch();

}
if(ice== 2){
clrscr();
gotoxy(20,4);
printf("             PROMEDIO DEL ESTUDIANTE");
gotoxy(5,8);
printf("CODIGO       NOMBRE                   NOTA.1  NOTA.2  NOTA.3   DEFI\n ");
ptr=&estudent[0];
j=10;
for(i=0;i<n;i++){
defini=sutal;
gotoxy(5,j);
printf("%7.0f       %-25s  %1.2f   %1.2f   %1.2f    %1.2f ",ptr->codigo,ptr->nombre,ptr->calf1,ptr->calf2,ptr->calf3,ptr->defini);
printf("\n\n");
gotoxy(18,15);printf("Promedio del Curso_________%1.2f",ptr->deftotal);
ptr++;
j++;
}getch();
}}while(ice!=3);
goto ini;
}
}


