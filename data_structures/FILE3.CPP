#include<iostream.h>      //CREAR REGISTRO , ES UN ARCHIVO BINARIO
#include<stdio.h>         // NO SE PUEDE EDITAR ESTUD.DAT
#include<fstream.h>       // SOLO SE PUEDE CONSULTAR CON EL PROGRAMA FILE 2
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void inse_inde (float,int);
//programa para el manejo de archivos
typedef struct alumno{
	float codigo;
	char nombre[35];
	float telefono;
	};
void main()
{
clrscr();
fstream archivo;
alumno estudiante;
char op,c,nom[35];
float cod,tel;
int n,i,k;
unsigned int sw;
//abrir el archivo en forma output=salida=escribir
archivo.open("estud.dat",ios::in|ios::binary);
//proceso de validacion de la existencia archivo
if (archivo.good()){
   cout<<"archivo estud.dat ya existe-continua (S/N)";
   do{
     op=getchar();
   }while(op !='S' && op!='s' && op!='N' && op!='n');
   if (op=='N' || op=='n'){
	exit (1);
   }
}
archivo.close();
archivo.open("estud.dat",ios::out|ios::binary);
//captura de datos a grabar en el archivo
clrscr();
gotoxy(31,2);
printf("MANEJO DE ARCHIVOS");
gotoxy(10,4);
printf("CEDULA     :");
gotoxy(10,6);
printf("NOMBRE     :");
gotoxy(10,8);
printf("TELEFONO   :");
do{
  gotoxy(23,4);
  printf("             ");
  gotoxy(23,6);
  printf("                             ");
  gotoxy(23,8);
  printf("              ");
  gotoxy(23,4);
  scanf("%f",&cod);
  gotoxy(23,6);
  cin.getline(nom,35);
  gotoxy(23,8);
  scanf("%f",&tel);
  estudiante.codigo=cod;
  n=strlen(nom);
  for(i=0;i<=n;i++){
      estudiante.nombre[i]=nom[i];
  }
  estudiante.telefono=tel;
  //escritura del registro captura en el archivo
  archivo.write((char*) &estudiante,sizeof(estudiante));
  gotoxy(10,16);
  printf("Mas Datos (S/N) : ");
  do{
    op=getchar();
  }while(op!='S' && op!='s' && op!='N' && op!='n');
  gotoxy(10,16);
  printf("                          ");
}while (op=='S' || op=='s');
archivo.close();
getch();
}