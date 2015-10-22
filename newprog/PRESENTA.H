#include<conio.h>
#include<dos.h>
#include<iostream.h>

void graphics(int v1,int v2,int v3,int v4)
{
 int i,j,k;
 for (i=v1;i<=v2;i++){
      gotoxy(i,v3);
      cout<<"Í";
    }


 for (j=v3;j<=v4;j++){
   gotoxy(v1,j);
   cout<<"º";
    gotoxy(v2,j);
   cout<<"º";
  }
    gotoxy(v1,v3);
  cout<<"É";

    gotoxy(v2,v3);
    cout<<"»";


 for (k=v1;k<=v2;k++){
   gotoxy(k,v4);
   cout<<"Í";
   delay(5);
  }
    gotoxy(v1,v4);
  cout<<"È";

  gotoxy(v2,v4);
  cout<<"¼";
return;
}


/*
void codigos()
#include<stdio.h>
{
 int x;
 char y,r;
 for ( ; ; ){
  clrscr();
  graphics(5,65,5,20);
  gotoxy(7,7);
  printf("PRESIONE UNA TECLA ");
  y=getch();
    gotoxy(7,8);
  printf("EL CODIGO ASCII PARA %c ES %d ",y,y);
  getch();
    gotoxy(7,10);
  printf("TECLEE UN CODIGO ASCII CUALQUIERA ");
  scanf("%d",&x);
    gotoxy(7,11);
  printf("EL CARACTER PARA EL CODIGO %d ES : %c ");
    gotoxy(7,15);
  printf("DESSEA CONTINUAR ? S ¢ N ");
  r=getch();
  if (r=='n' || r=='N')break;
  }
 return;
 }
 */