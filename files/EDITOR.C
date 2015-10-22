/* Programa para Modo Texto */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include <dos.h> 
unsigned modo; 
char bksp=8; 

void main(void) 
{ 
   Inicia(); 
   clrscr(); 
   color(0,3); 
   caja(1,1,80,24,'Æ'); 
   ventana(1,1,80,3,"Programa Procesador de Texto",0,0,14,4);
   color(1,3); 
   caja(1,21,80,24,' '); 
   marco(1,21,80,24,1); 
   Procesa_Pagina(); 
} 
void copia_pagina(int p1,int p2) 
{ 
  movedata(0xB800,(unsigned)p1*4000,0xB800,(unsigned)p2*4000,80*25*2);
} 
int inkey(char *car) 
{ int a; 
   a=0; 
   *car=getch(); 
   if (kbhit()) 
   { *car=getch(); 
       a=1;}; 
   return(a); 
} 
char caracter(int x,int y) 
{ unsigned segm,despl; 
   char car; 
   segm=0xB800; 
   despl=((y1)*160)+((x1)*2); 
   car=peekb(segm,despl); 
   return(car); 
} 

char atributo(int x,int y) 
{ unsigned segm,despl; 
   char car; 
   segm=0xB800; 
   despl=((y1)*160)+((x1)*2)+1; 
   car=peekb(segm,despl); 
   return(car); 
} 

void pcaracter(int x,int y,char car) 
{ unsigned segm,despl; 
   segm=0xB800; 
   despl=((y1)*160)+((x1)*2); 
   pokeb(segm,despl,car); 
} 

void patributo(int x,int y,char car) 
{ unsigned segm,despl; 
   segm=0xB800; 
   despl=((y1)*160)+((x1)*2)+1; 
   pokeb(segm,despl,car); 
} 
void escribe(int x,int y,const char cad[]) 
{ int cont; 
   for (cont=0;cont<strlen(cad); cont++)pcaracter(x+cont,y,cad[cont]); 
} 
void str(char c,int n,char cad[]) 
{ int i; 
   for (i=0;i<n;i++) 
   cad[i]=c; 
   cad[i]=0; 
} 

void centra(int fila,const char cad[]) 
{ int i,x; 
   x=(80strlen(cad))/2; 
   for (i=0;i<strlen(cad);i++) pcaracter(i+x,fila,cad[i]);
} 

void color(int plano,int fondo) 
{ textcolor(plano); 
   textbackground(fondo); 
} 

void caja(int x1,int y1,int x2,int y2,char c) 
{ char cad[90]; 
   int i; 
   str(c,x2x1+1,cad); 
   for (i=y1;i<=y2;i++) 
   { 
     gotoxy(x1,i); 
     cprintf("%s",cad); 
   } 
} 

void marco( int x1,int y1,int x2,int y2,char tipo) 
{ char tipe[6]; 
   int i,j; 
   switch (tipo) 
   { 
     case 1: 
     { tipe[0]='Ú'; 
        tipe[1]='Ä'; 
        tipe[2]='¿'; 
        tipe[3]='Æ'; 
        tipe[4]='Ù'; 
        tipe[5]='À'; 
        break;} 
      case 2: 
     {   tipe[0]='É'; 
        tipe[1]='Í'; 
        tipe[2]='»'; 
        tipe[3]='º'; 
        tipe[4]='º'; 
        tipe[5]='È'; 
        break;} 
     default: 
          for (i=0;i<6;i++) tipe[i]=tipo;
   } 
   gotoxy(x1,y1); 
   cprintf("%c",tipe[0]); 
   for (i=x1+1;i<x2;i++) cprintf("%c",tipe[1]); 
   cprintf("%c",tipe[2]); 
   for (j=y1+1;j<y2;j++) 
   { 
      gotoxy(x2,j); 
      cprintf("%c",tipe[3]); 
   } 
   gotoxy(x2,y2); 
   cprintf("%c",tipe[4]); 
   gotoxy(x1,y2); 
   cprintf("%c",tipe[5]); 
   for (i=x1+1;i<x2;i++) cprintf("%c",tipe[1]); 
   for (j=y1+1;j<y2;j++) 
   { 
      cprintf("%c",tipe[3]); 
   } 
} 

void ventana(int x1,int y1,int x2,int y2,const char titulo[],int marc,intsmb,int cp,int cf) 
{ 
   int a; 
   char cad[90]; 
   color(0,0); 
   if (smb) caja(x1+1,y1+1,x2+1,y2+1,'±'); 
   color(cp,cf); 
   str(' ',x2x1+1,cad); 
   gotoxy(x1,y1); 
   cprintf("%s",cad); 
   a=x1+((x2x1+1)strlen(titulo))/2; 
   gotoxy(a,y1); 
   cprintf("%s",titulo); 
   color(0,7); 
   for (a=y1+1;a<=y2;a++) 
   { 
     gotoxy(x1,a); 
     cprintf("%s",cad); 
   } 
   str('ß',x2x1+1,cad); 
   gotoxy(x1,y1+1); 
   cprintf("%s",cad); 
   if (marc) marco(x1,y1+2,x2,y2,2); 
} 

void Cadena(int x1,int x2,int fila,char cad[]) 
{ int xx1,xx2,i; 
   char car; 
   xx1=x1; 
   car=caracter(xx1,fila); 
   while ((xx1>(x11)) && (car<33) ) 
   { xx1++; 
      car=caracter(xx1,fila);} 
   xx2=x2; 
   car=caracter(xx2,fila); 
   while ((xx2<(x2+1)) && (car<33) ) 
   { xx2; 
      car=caracter(xx2,fila);} 
   for (i=0;i<(xx2xx1+1);i++) cad[i]=caracter(xx1+i,fila);
   cad[i]=0; 
} 


void Inicia(void) 
{ 
   modo=LASTMODE; 
   textmode (modo); 
   gotoxy(1,1); 
   color(WHITE,BLACK); 
} 

void Procesa_Pagina(void) 
{ unsigned char Ch,car,Colum[4],Reng[4],Mensaje[15],Aux[70];
   int sec,si,otr1,otr2; 
   color(7,0); 
   window (4,5,77,19); 
   clrscr(); 
   si=1; 
   escribe(11,22,"Columna:1"); 
   escribe(11,23,"Renglón:1"); 
   escribe(30,22,"Alt C  Centrar Alt Del o Ctrl Y Borrar Linea"); 
   escribe(30,23,"Alt Ins  Insertar Linea Home  Inicio deLinea") ; 
   do{ 
    sec=inkey(&Ch); 
     if (sec) 
     { 
      switch (Ch) 
      { 
         case 45: si=0;break; 
         case 72:gotoxy(wherex(),wherey()1); break; 
         case 75:gotoxy(wherex()1,wherey()); break; 
         case 77: gotoxy(wherex()+1,wherey());break; 
         case 80: gotoxy(wherex(),wherey()+1);break; 
         case 71: gotoxy(1,wherey());break; 
         case79:{otr2=77;car=caracter(otr2,wherey()+4); 
                    while ((car>3) && (car < 33)) 
                    { otr2; 
                   car=caracter(otr2,wherey()+4); 
                    } 
                    gotoxy(otr2+13,wherey());break; 
                  } 
          case 46:{Cadena(4,77,wherey()+4,Aux); 
                   gotoxy(1,wherey()); 
                   clreol(); 
                   centra(wherey()+4,Aux); 
                   break;} 
           case 162: insline();break;
           case 163: delline();break;
        } 
    } 
    else 
       switch(Ch) 
       { 
           case 3: si=0; break; 
           case 13: cprintf("\n\r");break;
           case 8: cprintf("%c%c",bksp,bksp);break; 
           case 27: si=0;break; 
           case 25: delline();break;
           default: cprintf("%c",Ch);
       } 

       Colum[0]=(wherex() / 10) +48; 
       if (Colum[0]=='0') { Colum[0]=(wherex() %10)+48;Colum[1]=' ';} 
       else { Colum[1]=(wherex() % 10)+48;} 
       Colum[2]=0; 

       Reng[0]=(wherey() / 10) +48; 
       if (Reng[0]=='0') { Reng[0]=(wherey() %10)+48;Reng[1]=' ';} 
       else { Reng[1]=(wherey() % 10)+48;} 
       Reng[2]=0; 

       strcpy(Mensaje,"Columna:"); 
       strcat(Mensaje,Colum); 
       escribe(11,22,Mensaje);    
       strcpy(Mensaje,"Renglón:"); 
       strcat(Mensaje,Reng); 
       escribe(11,23,Mensaje); 

   }while (si); 

} 