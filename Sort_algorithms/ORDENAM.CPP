#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include "ctype.h"

typedef struct estudiantes{
	float codigo;
	char nombre[30];
	};

void menup();
void Ingreso();
void Insercion();
void Seleccion();
void Burbuja();

estudiantes alumnos[30],temp,menor;
int lo,k,j,n,n1,i,tem;
float cod;
char nom[30],opcion;
unsigned int sw,aw;


void main()
{
clrscr();

do{
menup();
do{
opcion=getchar();
}while (opcion<'0'  &&  opcion<'5');
switch(opcion){


case '1':if(sw==0){
	    Ingreso();
	    break;
	    }

case '2': if(sw==1){
		   Insercion();
		   break;
		   }
case '3': if(sw==1){
		 Seleccion();
		 break;
		 }
case '4': if(sw==1){
		 Burbuja();
		 break;
		 }
	     }

   }while(opcion!='5');
}


//*************************
void menup(void){
clrscr ();
gotoxy (20,2);
printf (" UNIVERSIDAD  COOPERATIVA  DE  COLOMBIA");
gotoxy (20.5,3);
printf ("         INGENIERIA DE SISTEMAS");
gotoxy (20,4);
printf ("            IV SEMESTRE");
gotoxy (30,8);
printf ("    M E N U  ");
gotoxy (4,10);
printf ("    1. LECTURA DE DATOS");
gotoxy (4,12);
printf ("    2. ORDENAMIENTO DE DATOS POR INSERCION");
gotoxy (4,14);
printf ("    3. ORDENAMIENTO DE DATOS POR SELECCION");
gotoxy (4,16);
printf ("    4. ORDENAMIENTO DE DATOS POR BURBUJA");
gotoxy (5,18);
printf ("    5. SALIR");
gotoxy (4,22);
printf ("                     DIGITE OPCION [ ]");
gotoxy (40,22);
}
//************************
void Ingreso(void){
sw=0;
clrscr();
	 sw=1;
	  clrscr ();
	  printf("DIGITE EL NUMERO DE ESTUDIANTES: \t");
	  do{
	     scanf("%d",&n);
	     }while(n<0 || n>30);
	  for (j=1;j<=n;j++){
	      clrscr();
	      printf("DIGITE EL CODIGO DEL ESTUDIANTE: \t");
	      scanf("%f",&cod);
	      alumnos[j].codigo=cod;
	      printf("DIGITE EL NOMBRE DEL ESTUDIANTE: \t");
	      cin.getline(nom,30);
	      lo=strlen(nom);
	      for(k=0;k<=lo;k++){
		 alumnos[j].nombre[k]=nom[k];

		 }
		strupr(alumnos[j].nombre);

	      }

	   }
//***********************
void Insercion(void){

clrscr();

		   for(i=2;i<=n;i++){
		   j=i-1;
		   menor=alumnos[i];
		   while(strcmp(menor.nombre,alumnos[j].nombre)<0&&(j>0)){
		   alumnos[j+1]=alumnos[j];
		   j=j-1;
		   }
		   alumnos[j+1]=menor;
		   }
		   printf("CODIGO         NOMBRE \n");
		   for(i=1;i<=n;i++){
		   printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
		   }
		   getch();
		   }

//*******************
void Seleccion (void){

clrscr();

		      for(i=1;i<=n-1;i++){
		      menor=alumnos[i];
		      tem=i;
		      for(j=i+1;j<=n;j++){
		     if(strcmp(menor.nombre,alumnos[j].nombre)>0){
			menor=alumnos[j];
			tem=j;
			}
			}
			alumnos[tem]=alumnos[i];
			alumnos[i]=menor;
			}
			printf("CODIGO         NOMBRE \n");
			for(i=1;i<=n;i++){
			printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
			}
		   getch();
		}
//***********************
void Burbuja(void){

clrscr();

		   n1=n-1;
		   aw=0;
		   while(aw==0){
		   j=2;
		   aw=1;
		   for(i=1;i<=n1;i++){
		   if(strcmp(alumnos[i].nombre,alumnos[j].nombre)>0){
		   temp=alumnos[i];
		   alumnos[i]=alumnos[j];
		   alumnos[j]=temp;
		   aw=0;
		  }
		  j++;
		  }
		  n1=n1-1;
		  }
		   printf("CODIGO         NOMBRE \n");
		   for(i=1;i<=n;i++){
		   printf("%6.0f         %-35s\n",alumnos[i].codigo,alumnos[i].nombre);
		   }
		getch();
	   }

//***********************