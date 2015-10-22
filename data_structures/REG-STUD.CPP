#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<ctype.h>


typedef struct Registro{
	 char Nom[30];
	 float cod;

};

void marco();
void menu();
void burbuja (char *[],int );
void escribir (char *[],int );


void main(){
Registro Amigos[10],*RegPtr;
char *nombres [50];
char Name[30];
int n=0,i,l1,N,A,J,j,h,k,g,num[50];
float codigo;

//menu();
//getch();
marco();
printf("DIGITE LA CANTIDAD DE REGISTROS A INCLUIR :  ");
scanf("%d",&n);
clrscr();
RegPtr=&Amigos[0];
for(i=0;i<n;i++) {

  marco();
  printf("                        DATOS DE LAS PERSONAS");
  printf("\nDIGITE NOMBRE : ");
  cin.getline(Name,30);
  l1=strlen(Name);
   for(N=0;N<=l1;N++){
      Amigos[i].Nom[N] = Name[N];
      RegPtr->Nom[N] = Name [N];
   }
   strupr(Amigos[i].Nom);
   strupr(RegPtr->Nom);
   nombres[i]=Amigos[i].Nom;


  printf("\nDIGITE CODIGO : ");
  scanf("%f",&codigo);
  Amigos[i].cod=codigo;
  RegPtr->cod=codigo;
  RegPtr++;

  }


 burbuja(nombres,n);
 escribir(nombres,n);
 getch();
 clrscr();
 gotoxy(2,2);printf("NOMBRE");gotoxy(60,2);printf("CODIGO");
 gotoxy(2,3);printf("----------------------------------------------------------------------------");
 gotoxy(2,4);printf("----------------------------------------------------------------------------");

 h=5;
 for (j=0;j<n;j++){


 gotoxy(2,h);printf("%s",Amigos[j].Nom);gotoxy(60,h);printf("%.0f",Amigos[j].cod);

 h++;
 }
getch();


//Utilizando Apuntadores


clrscr();
 gotoxy(2,2);printf("NOMBRE");gotoxy(60,2);printf("CODIGO");
 gotoxy(2,3);printf("----------------------------------------------------------------------------");
 gotoxy(2,4);printf("----------------------------------------------------------------------------");
 RegPtr=&Amigos[0];
 g=5;
 for (k=0;k<n;k++){



 gotoxy(2,g);printf("%s",RegPtr->Nom); gotoxy(60,g);printf("%.0f",RegPtr->cod);

 RegPtr++;
 g++;
 }

getch();
}

//************************************
void marco (void){      //MARCO
int q,q2,q3,q4;
clrscr();
gotoxy(0,0);
printf("É");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("Í");
}
gotoxy(79,0);
printf("»");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("º");
}
gotoxy(80,24);
printf("¼");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("Í");}

gotoxy(1,24);
printf("È");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("º");}
return;
}
//******************************
void menu(){

  marco();
  gotoxy(35,4);
  printf (" M E N U  ");
  gotoxy(18,8);
  printf ("1  INGRESO DE DATOS ");
  gotoxy(18,10);
  printf ("2  ORDENAMIENTO DE BURBUJA");
  gotoxy(18,12);
  printf ("3  ORDENAMIENTO POR SELECCION");
  gotoxy(18,14);
  printf ("4  ORDENAMIENTO POR INSERCION");
  gotoxy(18,16);
  printf ("5  SALIR ");
  gotoxy (33,18);
  printf ("OPCION [ ]");
  gotoxy(41,18);
}


//******************************
void burbuja (char *pcadena[],int nc){
char *aux;   //Puntero auxiliar
int i,s=1;

while ((s = 1) && (--nc > 0)){
 s = 0;  //No haga cambio
 for (i = 1;i <= nc; i++)
  if(strcmp(pcadena[i-1],pcadena[i]) > 0){
    aux=pcadena[i-1];
    pcadena[i-1]=pcadena[i];
    pcadena[i]=aux;
    s = 1;   // Realice cambio
  }
 }
}
//*********************************
//FUNCION ESCRIBIR
void escribir (char *pcadena[],int nc){
// nc = numero de cadenas a escribir


while (--nc >= 0)
 printf ("%s  \n",*pcadena++);

}