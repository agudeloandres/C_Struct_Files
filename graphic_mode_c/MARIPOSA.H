//************************************************************************
//************************************************************************
//******                BIBLIOTECA DEL EFECTO MARIPOSA             *******
//************************************************************************
//************************************************************************


void Esfera (long double x, long double y, int cl);
void Capturar (long double *af);

//****************************************************************
//***********************   MAIN   *******************************
//****************************************************************
void Lorenz()
{

    int Rojo[16] = {0,5,15,25,35,45,55,63,0,0,0,0,0,0,0,63};
    int Azul[16] = {0,5,15,25,35,45,55,63,0,0,0,0,0,10,10,63};
    int Verde[16] = {0,4,8,12,16,21,27,32,5,15,25,35,45,55,63,63};
    int c, b, a, l,k;
    long double c1, cl, dt, xa[2], ya[2], za[2], x, y, z, x1, y1, z1, xd, yd;
    struct palettetype pal;

    xa[0] = 3.051522;
    ya[0] = 1.592542;
    za[0] = 15.62388;
    xa[1] = 3.051522;
    ya[1] = 1.582542;
    za[1] = 15.62388;
    clrscr();
/*    
    gotoxy(20,3); printf("Ingrese los valores iniciales");
    gotoxy(5,7); printf("Valores para la Esfera Azul");

    gotoxy(5,9); printf("Valor de X (Por defecto:[%2.5Lf]): ",xa[0]);
    Capturar(&xa[0]);
    gotoxy(5,10); printf("Valor de Y (Por defecto:[%2.5Lf]): ",ya[0]);
    Capturar(&ya[0]);
    gotoxy(5,11); printf("Valor de Z (Por defecto:[%2.5Lf]): ",za[0]);
    Capturar(&za[0]);

    gotoxy(5,13); printf("Valores para la Esfera Roja");
    gotoxy(5,15); printf("Valor de X (Por defecto:[%2.5Lf]): ",xa[1]);
    Capturar(&xa[1]);
    gotoxy(5,16); printf("Valor de Y (Por defecto:[%2.5Lf]): ",ya[1]);
    Capturar(&ya[1]);
    gotoxy(5,17); printf("Valor de Z (Por defecto:[%2.5Lf]): ",za[1]);
    Capturar(&za[1]);
  */
    getpalette(&pal);
    for (k=0;k<=15;k++)
      setrgbpalette(pal.colors[k], Rojo[k], Verde[k], Azul[k]);

    c1 = 0.292893;
    dt = 0.02;
    a  = 5;
    b  = 15;
    c  = 1;
    do {
      for (l=0;l<=1;l++) {
	x = xa[l];
	y = ya[l];
	z = za[l];
	x1 = x - a*x*dt + a*y*dt;
	y1 = y + b*x*dt - y*dt - z*x*dt;
	z1 = z - c*z*dt + x*y*dt;
	x = x1;
	y = y1;
	z = z1;
	xd = y - x*c1;
	yd = z + x*c1;
	if (l==1) {
	  cl = 0;
          Esfera(xd,yd,cl);
	}
	else {
	  cl = 7;
          Esfera(xd,yd,cl);
	}
        delay(4);  //Determina la rapidez de las esferas;
	xa[l] = x;
	ya[l] = y;
	za[l] = z;
      }
    } while (!kbhit());
    getch();
}

void Esfera (long double x, long double y, int cl)
{
    long double c;
    int i, k, colour,i1,j1;
    i1 =(int) (19.0*x + 320.0);
    j1 =(int) ( -14.0*y + 440.0);
    k = 7;
    for (i=1;i<=7;i++) {
      c = 0.09*i;
      colour = (i + cl);
      setcolor(colour);
      setfillstyle(SOLID_FILL,colour);
      fillellipse ((int)(i1+c),(int)(j1+c),k,k);
      k--;
    }
    putpixel(i1+c,j1+c,15);
    return;
}
void Capturar (long double *af){
char st[25];
st[0]='\0';
gets(st);
if (st[0]!='\0') *af=_atold(st);
}
