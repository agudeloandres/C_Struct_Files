#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
//Estructura se define en forma global
typedef struct  profesor{
		float cedula;
		char nombre[30];
		int horas;
		float valor;
	       };
void main() {
profesor nomina[30];
float ced,sal,val,prom,promed,nomina_profesor;
char nom[30];
int i,lo,j,n,hor;
promed=0;
clrscr();
//lectura de los datos
printf("\nDIGITE EL NUMERO DE PROFESORES  :  ");
do{
scanf("%d",  &n);
}while(n<0||n>30);
for(j=0;j<=n-1;j++){
    clrscr();
    printf("\nDIGITE CEDULA PROFESOR %d :  ",j+1 );
    do{
    scanf("%f",&ced);
    }while(ced>99999999);
    nomina[j].cedula=ced;
    //asigna valor capturado ala cedula
printf("\nDIGITE SU NOMBRE  :  ");
cin.getline(nom,35);
lo=strlen(nom);
//asignacion del nombre de la variable caracter
for(i=0;i<=lo;i++){
    nomina[j].nombre[i]=nom[i];
}
printf("\nDIGITE LAS HORAS TRABAJADAS :");
do{
   scanf("%d",&hor);
   }while(hor<0);
   nomina[j].horas=hor;

printf("\nDIGITE EL VALOR DEVENGADO POR EL PROFESOR :");
do{
   scanf("%f",&val);
   }while(val<0);
   nomina[j].valor=val;
}
clrscr();
gotoxy(23,1);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(29,2);
printf("PROGRAMA  DE  SISTEMAS");
gotoxy(30,3);
printf("NOMINA DE PROFESORES ");

gotoxy(1,5);  printf("CEDULA          NOMBRE            HORAS              VALOR             SALARIO\n");
i=6;
for(j=0;j<=n-1;j++){
gotoxy(1,i);
printf("%7.0f",nomina[j].cedula);
gotoxy(14,i);
printf("%-35s",nomina[j].nombre);
gotoxy(35,i);
printf("%3.0d",nomina[j].horas);
gotoxy(55,i);
printf("%3.0f",nomina[j].valor);
    prom=((nomina[j].horas) * (nomina[j].valor));
    gotoxy(73,i);
    printf("%3.0f",prom);

    nomina_profesor+=prom;
       i++;

   }
      // nomina_profesor+=prom/n;
   gotoxy(20,20);
  printf("  LA NOMINA DE LOS PROFESORES ES : %0.0f\n",nomina_profesor );
 getch();
}
