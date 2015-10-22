#include <conio.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int c,x;
  char *Nom;
  clrscr();
  textcolor(15);cprintf("Digite Nombre de Usuario : ");
  //c=getche();
  x=0;                        // Escribe solo en Mayusculas
  while (c!=13){
  c=getch();
  if (islower(c)){
  int i;
  i=toupper(c);cprintf("%c",i);Nom[x]=i;}
  else{
  cprintf("%c",c);
  Nom[x]=c;
  }
  x++;
  }

  cprintf("\n\rProcesando...");
  cprintf(" %s",Nom);

  int p;
  gotoxy(1,4);cprintf("Digite Contrase¤a: ");
  while (p!=13){
  p=getch();
  if (p==13) break;
  cprintf("*");
  }
  gotoxy(1,6);cprintf("Okey...Dokey");
  getch();
  return 0;
}
