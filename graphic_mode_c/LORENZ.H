//************************************************************************
//************************************************************************
//******                BIBLIOTECA DEL EFECTO MARIPOSA             *******
//************************************************************************
//************************************************************************


//************************************************************************
//******               DECLARACION DE FUNCIONES LOCALES            *******
//************************************************************************

void Draw (double x, double y, int cl);


//************************************************************************
//******      FUNCION QUE EJECUTA LAS ECUACIONES DE LORENZ         *******
//************************************************************************

void Lorenz()
{
    int ipalr[16] = {0,5,15,25,35,45,55,63,0,0,0,0,0,0,0,63};
    int ipalb[16] = {0,0,0,0,0,0,0,0,5,15,25,35,45,55,63,63};
    int ipalg[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,63};
    int c, b, a, l,k;
    double c1, cl, dt, xa[2], ya[2], za[2], x, y, z, x1, y1, z1, xd, yd;
    struct palettetype pal;
    int Posicion=0;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
     { xa[0] = 3.051522;}
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
          if(a1>=25)
            xa[0] = 3.051522;
          else
            xa[0]=a1;
         }
    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      {ya[0] = 1.592542;}
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
          if(a1>=25)
            ya[0] = 1.592542;
          else
            ya[0]=a1;
         }

    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      za[0] = 15.62388;
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
          if(a1>=25)
            za[0] = 15.62388;
          else
            za[0]=a1;
         }

    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
       xa[1] = 3.051522;
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
           if(a1>=25)
            xa[1] = 3.051522;
          else
            xa[1]=a1;
         }

    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      ya[1] = 1.582542;
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
           if(a1>=25)
            ya[1] = 1.582542;
          else
            ya[1]=a1;
         }

    Posicion++;
    if(!strcmp(DatoEsfera[Posicion],"\0"))
      za[1] = 15.62388;
    else
         {
          double a1=(double)atof(DatoEsfera[Posicion]);
           if(a1>=25)
            za[1] = 15.62388;
          else
            za[1]=a1;
         }
    c1 = 0.292893;
    dt = 0.02;
    a  = 5;
    b  = 15;
    c  = 1;

    getpalette(&pal);
    for (k=0;k<=15;k++)
       setrgbpalette(pal.colors[k], ipalr[k], ipalg[k], ipalb[k]);
    do
    {
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
	  Draw(xd,yd,cl);
	}
	else {
	  cl = 7;
	  Draw(xd,yd,cl);
	}
        delay(4);  //Cambia el delay (rapido / despacio);
	xa[l] = x;
	ya[l] = y;
	za[l] = z;
      }
    }while (!kbhit());
    getch(); /* ojo*/
    cleardevice();
}

void Draw (double x, double y, int cl)
{
    double c;
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
