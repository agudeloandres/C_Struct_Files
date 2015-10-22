#include<stdio.h>
#include<conio.h>      //cAMBIA LA ULTIMA VOCAL de una cadena POR UNA X
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>

void main(){
char Name[30],Nom[30],*q;
int l1,N;
clrscr();
printf("\nDIGITE NOMBRE : ");
  cin.getline(Name,30);
  l1=strlen(Name);
  q=Nom;

   for(N=0;N<=l1;N++){
     Nom[N] = Name[N];
   }

   //Busca desde la ultima posicion hacia la primera por la ultima vocal y la cambia por X
   for (N=l1;N>=0;N--){
       if (Name[N]== 'A' || Name[N]== 'a' || Name[N]== 'E' || Name[N]== 'e' || Name[N]== 'I' || Name[N]== 'i' || Name[N]== 'O' || Name[N]== 'o' || Name[N]== 'U' || Name[N]== 'u'){
	Name[N]='X';
	break;    //Sale del ciclo For
	}
  }

  while (*q !='\0'){
  printf("%c",*q);delay(100);
  *q++;
  }
  q=&Nom[l1]; //Situa el apuntador al final

  int t=l1;

  while(t+1){
  printf("%c",*q);delay(100);
  *q--;--t;
   }



   printf("\nNombre Original = %s \nNombre Cambiado= %s",Nom,Name);




getch();
}