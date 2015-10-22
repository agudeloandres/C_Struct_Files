void Inicio_Programa()
{
 int x,y;

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

/********         DIBUJA LAS LETRAS DE CAOS DE IZQUIERDA A DERECHA         *********/

 DibujeLetra(265,148,Candy_Font(),BLACK,24,32);
 DibujeIcono(278,153,La_S(),10,7);

 DibujeLetra(232,155,Candy_Font(),LIGHTBLUE,24,32);
 DibujeIcono(246,160,La_O(),9,9);

 DibujeLetra(202,148,Candy_Font(),LIGHTRED,24,32);
 DibujeIcono(215,153,La_A(),9,11);

 DibujeLetra(169,155,Candy_Font(),GREEN,24,32);
 DibujeIcono(180,160,La_C(),9,10);



/********         DIBUJA LOS RECUADROS DEL MOUSE            *********/
 x = 404;
 y = 215;

 DibujeIcono(x,y,Raton1_Microsoft(),20,21);
 DibujeIcono(x+21,y,Raton2_Microsoft(),20,21);
 DibujeIcono(x+42,y,Raton3_Microsoft(),20,21);

 DibujeIcono(x,y+20,Raton4_Microsoft(),20,21);
 DibujeIcono(x+21,y+20,Raton5_Microsoft(),20,21);
 DibujeIcono(x+42,y+20,Raton6_Microsoft(),20,21);
 DibujeIcono(x+63,y+20,Raton7_Microsoft(),20,21);

 DibujeIcono(x,y+40,Raton8_Microsoft(),20,21);
 DibujeIcono(x+21,y+40,Raton9_Microsoft(),20,21);
 DibujeIcono(x+42,y+40,Raton10_Microsoft(),20,21);
 DibujeIcono(x+63,y+40,Raton11_Microsoft(),20,21);

 DibujeIcono(x+21,y+60,Raton12_Microsoft(),20,21);
 DibujeIcono(x+42,y+60,Raton13_Microsoft(),20,21);
 DibujeIcono(x+63,y+60,Raton14_Microsoft(),20,21);

 setcolor(BLUE);
 settextstyle(4,0,1);
 outtextxy(160,260,"Efecto Mariposa");
 DibujeIcono(445,192,Lapiz(),15,9);

//****************************************************************
//**********       ESCRIBE EL TEXTO DE LA IMAGEN      ************
//****************************************************************
  settextstyle(0,0,1);
  setcolor(BLUE);
  outtextxy(275,185,"Ver. 1.5");
  outtextxy(360,200,"Para D.O.S.");

  setcolor(BLACK);
  outtextxy(160,220,"Fabrizio Bola¤o Lopez");
  outtextxy(160,230,"Jorge Danilo Rueda Sanabria");
  outtextxy(160,240,"Balmiro Pallares");

  setcolor(6);
  outtextxy(220,305,"UNIVERSIDAD DEL MAGDALENA");
  outtextxy(232,315,"Ingenieria de Sistemas");
  outtextxy(276,325,"VII Semestre");
  setcolor(RED);
  settextstyle(4,0,1);
  outtextxy(375,150,"Simulacion");
  delay(4000);
}
