void CuadroDato(int Posy,char *Mensaje,int *Posicion,char *Mens )
{
 int Posx=300;
 setcolor(0);
 outtextxy(215,Posy+12,Mensaje);
 outtextxy(413,Posy+12,Mens);
 setcolor(0);
 line(Posx,Posy,Posx,Posy+26);
 line(Posx,Posy-1,Posx+100,Posy-1);
 setcolor(15);
 line(Posx,Posy+26,Posx+100,Posy+26);
 line(Posx+100,Posy-1,Posx+100,Posy+26);
 char Numero,Cadena[12];
 int Pos=0;
 do
 {
 Numero=getch();
 if(Numero==8)
  {
   setcolor(7);
   outtextxy(Posx+2,Posy+5,Cadena);
   Pos=Pos>0?Pos-1:0;
   Cadena[Pos]='\0';
  }
 if(strchr("0123456789.-",Numero))
  {
   Cadena[Pos]=Numero;
   Pos=Pos<11?Pos+1:11;
  }
 Cadena[Pos]='\0';
 setcolor(15);
 outtextxy(Posx+2,Posy+5,Cadena);
 }while(Numero!=13);
 strcpy(DatoEsfera[*Posicion],Cadena);
 *Posicion=*Posicion+1;
}

void CajaDialogo()
{
 int Posicion=0;
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar(129,125,512,355);
 setcolor(WHITE);
 line (130,126,511,126);
 line (130,126,130,354);
 line (142,138,142,341);
 line (142,138,498,138);
 line (500,137,500,343);
 line (141,343,500,343);

 setcolor(BLACK);
 line (129,355,512,355);
 line (512,125,512,355);
 setcolor(DARKGRAY);
 line (130,354,511,354);
 line (511,126,511,354);
 rectangle(141,137,499,342);
 setcolor(RED);
 outtextxy(146,171,"Esfera");
 outtextxy(150,180,"Roja");
 CuadroDato(140,"Valor de X",&Posicion,"X=3.051522");
 CuadroDato(175,"Valor de Y",&Posicion,"Y=1.592542");
 CuadroDato(210,"Valor de Z",&Posicion,"Z=15.62388");
 setcolor(BLUE);
 outtextxy(146,276,"Esfera");
 outtextxy(146,285,"Azul");
 CuadroDato(245,"Valor de X",&Posicion,"X=3.051522");
 CuadroDato(280,"Valor de Y",&Posicion,"Y=1.582542");
 CuadroDato(315,"Valor de Z",&Posicion,"Z=15.62388");

}
