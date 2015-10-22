#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>

typedef struct Registro{
	 char Nom[30];
	 int edad;
	 int tel;
       char Dir[30];
      char Cargo[20];
};


void main(){
Registro Amigos[10],*RegPtr;
char Name[30],Adress[30],Job[20];
int age,phone,n=0,i,l1,l2,l3,N,A,J,j,h,k,g;

clrscr();
printf("DIGITE LA CANTIDAD DE REGISTROS A INCLUIR :  ");
scanf("%d",&n);
clrscr();
RegPtr=&Amigos[0];
for(i=0;i<n;i++) {

  clrscr();
  printf("                        DATOS DE LAS PERSONAS");
  printf("\nDIGITE NOMBRE : ");
  cin.getline(Name,30);
  l1=strlen(Name);
   for(N=0;N<=l1;N++){
      Amigos[i].Nom[N] = Name[N];
      RegPtr->Nom[N] = Name [N];
   }

  printf("\nDIGITE DIRECCION : ");
  cin.getline(Adress,30);
  l2=strlen(Adress);
   for (A=0;A<=l2;A++){
     Amigos[i].Dir[A]=Adress[A];
     RegPtr->Dir[A] = Adress [A];
   }

  printf("\nDIGITE CARGO : ");
  cin.getline(Job,20);
  l3=strlen(Job);
    for (J=0;J<=l3;J++){
     Amigos[i].Cargo[J]=Job[J];
     RegPtr->Cargo[J] = Job[J];
    }
  printf("\nDIGITE EDAD : ");
  scanf("%d",&age);
   Amigos[i].edad=age;
   RegPtr->edad=age;
  printf("\nDIGITE TELEFONO : ");
  scanf("%d",&phone);
  Amigos[i].tel=phone;
  RegPtr->tel=phone;
  RegPtr++;
  }


 clrscr();
 gotoxy(2,2);printf("NOMBRE");gotoxy(30,2);printf("EDAD");gotoxy(37,2);printf("CARGO");
 gotoxy(53,2);printf("DIRECCION");gotoxy(69,2);printf("TELEFONO");
 gotoxy(2,3);printf("----------------------------------------------------------------------------");

 h=4;
 for (j=0;j<n;j++){


 gotoxy(2,h);printf("%s",Amigos[j].Nom);gotoxy(30,h);printf("%d",Amigos[j].edad);
 gotoxy(37,h);printf("%s",Amigos[j].Cargo);gotoxy(53,h);printf("%s",Amigos[j].Dir);
 gotoxy(70,h);printf("%d",Amigos[j].tel);

 h++;
 }
getch();


//Utilizando Apuntadores


clrscr();
 gotoxy(2,2);printf("NOMBRE");gotoxy(30,2);printf("EDAD");gotoxy(37,2);printf("CARGO");
 gotoxy(53,2);printf("DIRECCION");gotoxy(69,2);printf("TELEFONO");
 gotoxy(2,3);printf("----------------------------------------------------------------------------");

 RegPtr=&Amigos[0];
 g=4;
 for (k=0;k<n;k++){



 gotoxy(2,g);printf("%s",RegPtr->Nom);gotoxy(30,g);printf("%d",RegPtr->edad);
 gotoxy(37,g);printf("%s",RegPtr->Cargo);gotoxy(53,g);printf("%s",RegPtr->Dir);
 gotoxy(70,g);printf("%d",RegPtr->tel);

 RegPtr++;
 g++;
 }

getch();
}