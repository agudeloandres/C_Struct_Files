#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>

main (){
void Lea_Nombre(char [],int); 
char nom[40];
int lo,i;
printf("Digite Nombre :  ");
/*cin.getline(nom,40);
lo=strlen(nom);
for (i=0;i<=lo;i++){
printf("%c",nom[i]);*/
Lea_Nombre(nom,40);
getch();
}
//****************************
void Lea_Nombre(char Nomb [],int x){
 int i,lo;
 cin.getline(Nomb,x);lo=strlen(Nomb);
 for(i=0;i<=lo;i++){
  printf("%c",Nomb[i]);
  }
  return;
  }