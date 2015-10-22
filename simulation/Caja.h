void MostrarDatos(void)
{
float Total,Valor;
int Pozos;
Total=Proyecto->ValorTotal();
Pozos=Proyecto->MostrarNumeroPozos();
Valor=Proyecto->MostrarValorPozos();
setcolor(BLUE);
if(Total>Pozos*Valor)
  outtextxy(240,160,"Es rentable perforar");
else
 outtextxy(240,160,"!Perforar es riesgoso­");
setcolor(WHITE);
line(230,170,430,170);
setcolor(8);
line(230,169,430,169);
setcolor(BLACK);
outtextxy(162,210,"Total de la venta");
outtextxy(162,260,"P(Z>10000)");
outtextxy(162,310,"Probabilidad");
outtextxy(340,210,"Numero de pozos");
outtextxy(340,260,"Valor de la Media");
outtextxy(340,310,"Valor por Pozo");
setcolor(RED);
char cadena[10];
sprintf(cadena,"%.2f",Total);
outtextxy(162,220,cadena);
sprintf(cadena,"%.2f",Valor);
outtextxy(340,320,cadena);
sprintf(cadena,"%d",Pozos);
outtextxy(340,220,cadena);
sprintf(cadena,"%.2f",Proyecto->MostrarMedia());
outtextxy(340,270,cadena);
sprintf(cadena,"%.2f",Proyecto->MostrarProbabilidad());
outtextxy(162,320,cadena);
sprintf(cadena,"%.2f",Proyecto->ValorTotalProbabilidadZ());
outtextxy(162,270,cadena);
}
 void Convertir(void)
{
    int Posicion=0;
    float a1,a2,a3,a4;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
     a1=0.2;
    else
         {
           a1=(float)atof(DatoEsfera[Posicion]);
           if(a1>1.0)
             a1=0.2;
         }
    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      a2 = 10.0;
    else
      a2=(float)atof(DatoEsfera[Posicion]);
    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      a3 = 50000.0;
    else
      a3=(float)atof(DatoEsfera[Posicion]);

    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
       a4= 10000.0;
    else
     a4=(float)atof(DatoEsfera[Posicion]);
     Proyecto->CambiarValores(a1,a3,a4,a2);
    }

void CuadroDato(int Posy,char *Mensaje,int *Posicion,char *Mens )
{
 int Posx=280;
 setcolor(BLUE);
 outtextxy(155,Posy+12,Mensaje);
 setcolor(0);
 outtextxy(390,Posy+12,Mens);
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
 if(strchr("0123456789.",Numero))
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
void Cuadro(void)
{
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

}

void CajaDialogo()
{
 int Posicion=0;
 Cuadro();
 CuadroDato(150,"Probabilidad",&Posicion,"Pro=0.2");
 CuadroDato(200,"Numero de Pozos",&Posicion,"Pozos=10");
 CuadroDato(250,"Media",&Posicion,"Media=$50000");
 CuadroDato(300,"Valor por Pozo",&Posicion,"$10000");
 Convertir();
 Cuadro();
 MostrarDatos();
 getch();

}
