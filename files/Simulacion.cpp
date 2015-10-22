/*
  SIMULACIÓN DEL MOVIMIENTO PLANETARIO
  Nov-1996  Versión 5.0  Freeware
  Compilar en modelo Small
*/

#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <conio.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <dos.h>
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define minim(a,b) ( (a) < (b) ? (a) : (b) )
#define maxim(a,b) ( (a) > (b) ? (a) : (b) )

void nosound(void);
void strlwr(char *argv[]);
/*char strchr( char *argv[], int c);*/

#define BLUE 0
#define MAGENTA 1
#define CYAN 2

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct {
  int xcen, ycen;
  double a, b, c, e, p;
  double w, dw, dww, drot;
  int flag;
} tunneldata;

void inittunnel (tunneldata *d, int xcen, int ycen, int xradius, int yradius)
/* Bronshtein p.245 */
{
  d->xcen = xcen;  d->ycen = ycen; /* centro */
  d->a = (double) maxim (xradius, yradius); /* Semieje mayor */
  d->b = (double) minim (xradius, yradius); /* Semieje menor */
  d->c = sqrt ((double)d->a * d->a - (double)d->b * d->b); /* Distancia focal */
  d->e = d->c / d->a; /* Excentricidad */
  d->p = ((double)d->b * d->b) / d->a; /* Parámetro focal */
  d->flag = 0; /* Alterna entre uno sí y otro no */

  d->dw = M_PI/180; /* Incrementos */
  d->drot = 2*M_PI/24;
  d->dww = M_PI/30;

  d->w = 0; /*M_PI/2;*/
}
void runtunnel (tunneldata *d)
{
  double r, or, oor;
  int x, y, ox, oy, oox, ooy;
  double ww, www, rot=0;

  /*setlinestyle(SOLID_LINE,0,NORM_WIDTH);*/

  if (d->w > M_PI) d->w = 0; /*M_PI/2;*/
  else d->w+= d->dw; /* ángulo para aceleración */

  ww = 0;
  for (ww = 0; ww <M_PI; ww+=d->dww) /* Varios aros */
  {
    rot = 0;
    for (rot = 0; rot< 2*M_PI; rot+= d->drot) /* ángulo de rotación */
    {
      www = d->w + ww;
      if (www > M_PI) www -= M_PI;

      /* aceleración actual y anteriores */
      r = d->p / (1 + d->e * cos(www));
      or = d->p / (1 + d->e * cos(www - d->dw));
      /*oor = d->p / (1 + d->e * cos(www - d->dw - d->dw));*/

      /* coordenadas actuales y anteriores */
      x = d->xcen + r*cos(rot);
      y = d->ycen - r*sin(rot);
      ox = d->xcen + or*cos(rot);
      oy = d->ycen - or*sin(rot);
      /*oox = d->xcen + oor*cos(rot);
      ooy = d->ycen - oor*sin(rot);*/

      /* Borrar línea anterior y pintar nueva (estrella) */
      #if 0
      setcolor(getbkcolor()); line(oox, ooy, ox, oy);
      setcolor(WHITE); line(ox, oy, x, y);
      #else
      d->flag = ! d->flag;
      if (d->flag) line(ox, oy, x, y);
      #endif
    }
  }

}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int geticolor(int icolor)
/* Los colores de la espiral */
{
  switch (icolor)
  {
    case 0: return BLUE;
    case 1: return MAGENTA;
    case 2: return CYAN;
  }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void centerstars (int xmid, int ymid, int radius)
/* Puntos aleatorios pero que tienden a un punto central */
{
  const unsigned long numstars = 50*radius;
  long i;
  int x, y, color;
  double r, a;

  for (i=0; i<numstars/2; ++i) /* R² = y² + x² */
  {
    r = random(radius*2) - radius;
    a = random(360)*M_PI/180;
    x = xmid + cos(a)*r;
    y = ymid - sin(a)*r;
    putpixel(x, y, LIGHTGRAY) ; /*getmaxcolor() / (i%10?2:1));*/ /* GRIS o BLANCO */
  }
  for (i=0; i<numstars/6; ++i)
  {
    r = random(radius*2) - radius;
    a = random(360)*M_PI/180;
    x = xmid + cos(a)*r;
    y = ymid - sin(a)*r;
    putpixel(x, y, WHITE);
  }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void drawdoublespiral (void)
/* Red de dos espirales en sentidos opuestos */
{
  const int vueltas = 360*2;
  const int xmid = getmaxx()/2;
  const int ymid = getmaxy()/2;
  const int maxcolors = 3;
  double rad;
  int x1,y1, x2,y2, ox1=0,oy1=0, ox2=0,oy2=0;
  int a, a0=0, color=0;
  int radius = 1;

  /*setlinestyle(DASHED_LINE, 0, THICK_WIDTH);*/
  /*setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);*/
  setlinestyle(SOLID_LINE, 0, NORM_WIDTH);

  for(a0=0; a0<360; a0+=maxcolors) /* Espirales en todos los ángulos */
  {
    if (!(a0 % maxcolors))
      setcolor(geticolor(color = (color+1) % maxcolors));
    radius = 0;
    for (a=0; a< vueltas; ++a) /* Las espirales */
    {
      /* Espiral positiva */
      rad = (a+a0) * M_PI / 180;
      x1 = xmid + cos(rad) * radius;
      y1 = ymid - sin(rad) * radius;

      /* Espiral negativa */
      rad = (vueltas-(a+a0)) * M_PI / 180;
      x2= xmid + cos(rad) * radius;
      y2= ymid - sin(rad) * radius;

      if (a!=0) {
        line(ox1,oy1,x1,y1);
	line(ox2,oy2,x2,y2);
      }
      ox1 = x1; oy1 = y1;
      ox2 = x2; oy2 = y2;

      /* Número de grados que tarda en aumentar el radio */
      if (!(a % 1)) ++radius;
    }
  }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void opengraphics (void)
/* Inicialización del modo gráfico */
{
  int gdriver = DETECT, gmode, errorcode;

  /* initialize graphics mode */
  initgraph(&gdriver, &gmode, "");

  /* read result of initialization */
  errorcode = graphresult();

  if (errorcode != grOk) /* an error occurred */
  {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1); /* return with error code */
  }
}
#pragma startup opengraphics 99

void closegraphics (void)
/* Clausura del modo gráfico */
{
  closegraph();
}
#pragma exit closegraphics 101

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void far *createcircleimage (int radius, int color, int num)
/* Obtiene la imagen en bits de un mundo. */
/* Si color es -1 entonces crea una máscara de fondo blanco y
   círculo negro */
{
   void far *bitmap;
   void far *rest;
   char str[5];
   #define BACKCOLOR (color<0? WHITE: BLACK)
   #define FORECOLOR (color<0? BLACK: color)

   if (radius < 1) radius = 1; /* Filtro de radio mínimo */

   /* Copia de lo que había para posterior restauración */
   rest = farmalloc(imagesize(0, 0, radius*2, radius*2));
   assert(rest != NULL);
   getimage(0, 0, radius*2, radius*2, rest);

   /* Fondo negro */
   setfillstyle(SOLID_FILL, BACKCOLOR);
   bar(0, 0, radius*2, radius*2);

   /* Pintar mapa del mundo */
   setfillstyle(SOLID_FILL, FORECOLOR);
   setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
   setcolor(FORECOLOR);
   pieslice(radius, radius, 0, 360, radius);
   if (color>=0) {
     setcolor(color-8);
     circle(radius, radius, radius);
     if (num >= 0) {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
       setcolor(BLACK); outtextxy(radius, radius, itoa(num, str, 10));
     }
   }
   /* Obtenar copia del mapa */
   bitmap = farmalloc(imagesize(0, 0, radius*2, radius*2));
   assert(bitmap != NULL);
   getimage(0, 0, radius*2, radius*2, bitmap);

   /* Restaurar imagen anterior */
   putimage(0, 0, rest, COPY_PUT);
   farfree(rest);

   return bitmap;

} /* createcircleimage */

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*
  DYNAMIC es una clase para la animación mediante
  el dibujo de un mapa de bits.
*/

typedef struct {
  int oldx, oldy;    /* Anteriores coordenadas */
  void far *bitmap;  /* Imagen a pintar */
  void far *copy;    /* Imagen a restaurar */
  void far *mask;    /* Máscara */
  int radius;        /* Radio de la imagen (ancho y alto) */
  int color;         /* Color de la imagen */
  int start;         /* ¿Está recien inicializado? */
  int num;           /* Número de orden */
} dynamicdata;

void copydynamic (dynamicdata *d, dynamicdata *e)
{
  d->oldx = e->oldx;
  d->oldy = e->oldy;
  d->bitmap = e->bitmap;
  d->copy = e->copy;
  d->mask = e->mask;
  d->radius = e->radius;
  d->color = e->color;
  d->start = e->start;
  d->num = e->num;
}
void opendynamic (dynamicdata *d, int radius, int color, int num)
/* Inicialización de la estructura */
{
  d->radius = radius;
  d->bitmap = NULL;
  d->copy = NULL;
  d->mask = NULL;
  d->start = 1;
  d->color = color;
  d->num = num;
}

void savedynamic (dynamicdata *d, int x, int y)
/* Guardar imagen anterior */
{
  const int maxx = getmaxx();
  const int maxy = getmaxy();
  #define XBOUND(x)  ( (x)<0 ? 0 : ((x)>maxx ? maxx : (x)) )
  #define YBOUND(y)  ( (y)<0 ? 0 : ((y)>maxy ? maxy : (y)) )

  if (d->copy == NULL) {
     d->copy = farmalloc(imagesize(0,0,d->radius*2,d->radius*2));
     assert(d->copy != NULL);
     d->mask = createcircleimage(d->radius, -1, -1);
     assert(d->mask != NULL);
  }
  getimage(XBOUND(x - d->radius), YBOUND(y - d->radius),
           XBOUND(x + d->radius), YBOUND(y + d->radius), d->copy);
}
void paintdynamic (dynamicdata *d, int x, int y)
/* Pinta la imagen deseada */
{
  if (d->bitmap == NULL)
    d->bitmap = createcircleimage(d->radius, d->color, d->num);

  /* Si se utilizó 'savedynamic' entonces trabajar con máscaras */
  if (d->copy != NULL) {
    assert(d->mask != NULL && d->bitmap != NULL);
    putimage(x-d->radius, y-d->radius, d->mask, AND_PUT);
    putimage(x-d->radius, y-d->radius, d->bitmap, OR_PUT);
  }
  else {
    assert(d->bitmap != NULL);
    putimage(x-d->radius, y-d->radius, d->bitmap, XOR_PUT);
  }
  d->oldx = x;  d->oldy = y;
}
void erasedynamic (dynamicdata *d)
/* Restaurar imagen anterior */
{
  #define XBOUND(x)  ( (x)<0 ? 0 : ((x)>getmaxx() ? getmaxx() : (x)) )
  #define YBOUND(y)  ( (y)<0 ? 0 : ((y)>getmaxy() ? getmaxy() : (y)) )

  if (d->start) /* La primera vez no se hace nada */
    d->start = 0;
  else {
    if (d->copy != NULL) {
      assert(d->copy != NULL);
      putimage(XBOUND(d->oldx - d->radius),
               YBOUND(d->oldy - d->radius), d->copy, COPY_PUT);
    }
    else {
      assert(d->bitmap != NULL);
      putimage(d->oldx - d->radius, d->oldy - d->radius, d->bitmap, XOR_PUT);
    }
  }
}
void closedynamic (dynamicdata *d)
/* Borrado de la estructura */
{
  if (d->bitmap != NULL) farfree(d->bitmap);
  if (d->copy != NULL) farfree(d->copy);
  if (d->mask != NULL) farfree(d->mask);
  d->bitmap = NULL;
  d->copy = NULL;
  d->mask = NULL;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*
   ELLIPSE POLAR es una clase para dibujar elipses
   mediante función polar. Se proporciona el centro de masas
   de la elipse. Los puntos de la elipse que se obtienen
   cumplen con la segunda ley de Kepler.
*/

/* Angulo sobre la vertical, 0=de canto, 90=desde arriba */
double ANGV=90; /* Angulo vertical [0..90] */
int VELOC=10; /* Velocidad de rotación [1..100] */

typedef struct {
    double a;  /* Semieje mayor */
    double b;  /* Semieje menor */
    double c;  /* Distancia focal */
    double e;  /* Excentricidad */
    double p;  /* Parámetro focal */
    double r;  /* Rotación de la elipse [0..2·PI] */
    int xc1, yc1; /* Primer foco */
    int xc2, yc2; /* Segundo foco */
    int dx, dy; /* Distancia entre los focos */
    int way; /* Sentido de giro: positivo (+1) o negativo (-1) */
    double w, dw; /* Angulo e incremento del ángulo (velocidad) */
    int color; /* El color */
    int x, y, xx, yy, xxx, yyy; /* Punto actual y anteriores */
    double mass; /* Masa del objeto */
    int start;
} ellipsepolardata;

void copyellipsepolar(ellipsepolardata *d, ellipsepolardata *e)
{
  d->a = e->a; d->b = e->b;
  d->c = e->c; d->e = e->e;
  d->p = e->p; d->r = e->r;
  d->xc1 = e->xc1; d->yc1 = e->yc1;
  d->xc2 = e->xc2; d->yc2 = e->yc2;
  d->dx = e->dx; d->dy = e->dy;
  d->way = e->way;
  d->color = e->color;
  d->w = e->w; d->dw = e->dw;
  d->x = e->x; d->y = e->y;
  d->xx = e->xx; d->yy = e->yy;
  d->xxx = e->xxx; d->yyy = e->yyy;
  d->mass = e->mass;
  d->start = e->start;
}
void getpoint (ellipsepolardata *d, double angle)
/* Devuelve el punto de la elipse del ángulo expresado en radianes */
{
    double r;

    /* Recordar puntos anteriores */
    d->xxx = d->xx; d->yyy = d->yy;
    d->xx = d->x; d->yy = d->y;

    /* Calcular nuevo punto */
    d->w = angle * d->way;
    r = d->p / (1 + d->e * cos(d->w + d->r));
    d->x = d->xc2 + r*cos(d->w);
    d->y = d->yc2 + r*sin(d->w) * ANGV/90;
}
void initellipsepolar(ellipsepolardata *d,
  int xCen, int yCen, int xRadius, int yRadius,
  double rot, int retrogado, int color, double mass)
/* Inicializa la estructura de la elipse polar */
{
   d->a = (double) maxim (xRadius, yRadius); /* Semieje mayor */
   d->b = (double) minim (xRadius, yRadius); /* Semieje menor */
   d->c = sqrt ((double)d->a * d->a - (double)d->b * d->b);
   d->e = d->c / d->a; /* Excentricidad */
   d->p = ((double)d->b * d->b) / d->a; /* Parámetro focal */
   d->r = rot * (M_PI/180.); /* Angulo en radianes */
   d->xc1 = xCen;
   d->yc1 = yCen;
   d->dx = (-2 * d->c)*cos(d->r);
   d->dy = (-2 * d->c)*sin(d->r);
   d->xc2 = d->xc1 - d->dx;
   d->yc2 = d->yc1 + d->dy * ANGV/90;
   d->way = retrogado ? -1 : +1;
   d->color = color;
   d->w = 0;
   d->dw = 2*M_PI/(sqrt(d->a*d->a*d->a)) * VELOC; /* 3ra ley de Kepler */
   getpoint(d, 0);
   d->xxx = d->xx = d->x;
   d->yyy = d->yy = d->y;
   d->mass = mass;
}
void incrotation (ellipsepolardata *d, double dx)
/* Incrementa la rotación de la elipse que define la órbita */
{
   d->r += dx * M_PI/180;
   if (d->r > 2*M_PI) d->r -= 2*M_PI;
   else if (d->r < 0) d->r += 2*M_PI;

   d->dx = (-2 * d->c)*cos(d->r);
   d->dy = (-2 * d->c)*sin(d->r);
   d->xc2 = d->xc1 - d->dx;
   d->yc2 = d->yc1 + d->dy * ANGV/90;
}
void estela (ellipsepolardata *d, int flag)
/* Línea entre dos puntos consecutivos de la trayectoria */
{
  setwritemode(1); setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
  setcolor(d->color);
  if (! flag)
    line(d->xxx, d->yyy, d->xx, d->yy);
  else
    line(d->xx, d->yy, d->x, d->y);
}

void ellipsepolar (ellipsepolardata *d)
/* Dibuja las áreas de barrido de la elipse polar (2ª Ley de Kepler) */
{
    double r, angle;
    int x, y;

    setcolor((d->color-8)%16);
    for (angle =0; angle < M_PI*2; angle += M_PI/30)
    {
      r = d->p / (1 + d->e * cos(angle + d->r));
      x = d->xc2 + r*cos(angle);
      y = d->yc2 + r*sin(angle) * ANGV/90;
      line(d->xc1, d->yc1, x, y);
    }
}
void draworbit (ellipsepolardata *d)
/* Dibuja la órbita, es decir, una elipse */
{
  double angle, cosrot, sinrot, cos90rot, sin90rot, xp, yp;
  int xCen, yCen, x, y;

  /* Constantes para el cambio de coordenadas */
  cosrot = cos(d->r);
  sinrot = sin(d->r);
  cos90rot = cos(M_PI_2 + d->r);
  sin90rot = sin(M_PI_2 + d->r);

  /* El centro de la elipse es equidistante a sus focos */
  xCen = (d->xc1 + d->xc2)/2;
  yCen = (d->yc1 + d->yc2)/2;

  /* Pintar los centros */
  setcolor(d->color);
  circle(d->xc1, d->yc1, 2);
  circle(d->xc2, d->yc2, 2);

  setlinestyle(SOLID_LINE, 0, NORM_WIDTH);

  for (angle=0; angle <= M_PI*2 ; angle+=M_PI/180)
  {
     xp = d->a * cos(angle);
     yp = d->b * sin(angle);
     x = xCen + (xp*cosrot + yp*cos90rot);
     y = yCen - (xp*sinrot + yp*sin90rot) * ANGV/90;
     if (angle == 0)
       moveto(x, y);
     else
       lineto(x, y);
  }
} /* draworbit */

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

double distance (double x1, double y1, double x2, double y2)
/* Devuelve la distancia que hay entre dos puntos. */
{
    return sqrt( (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2) );
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void printhelp(void)
{
    puts("SIMULACION DEL MOVIMIENTO PLANETARIO. Nov-1998 V1.0");

    puts("Parametros: dcsaovertmplgxnbwi <c> <a> <v> <i> (*=omision)");
    puts("   d   fondo con doble espiral.");
    puts("   c   mostrar las colisiones entre cuerpos (v).");
    puts("   s   fondo estrellado con centro de gravedad.");
    puts("   a   mostrar las Areas de barrido.");
    puts("   o   mostrar orbitas planetarias elipticas.");
    puts("   v   numero de orbitas realizada (si colisiones (c) mostrar masa).");
    puts("   e   etiquetar todos los cuerpos con números (v).");
    puts("   r   radiacion solar (en la doble espiral).");
    puts("   t   mostrar tiempo de sincronizacion (si (i) nº de iteraciones).");
    puts("   m   se utiliza mascaras AND y OR (y sino XOR).");
    puts("   p   sentido de giro positivo (y sino aleatorio).");
    puts("   l   lineas uniendo todos los cuerpos.");
    puts("   g   lineas de gravedad al sol.");
    puts("   x   no mostrar el sol en el centro.");
    puts("   n   mostrar el camino que hace cada cuerpo (a,o).");
    puts("   w   mostrar estelas que deja tras si la particula.");
    puts("   i   calculo de posicion por nº de iteraciones en vez de tiempo.");
    puts("  <c>  numero de cuerpos orbitando [1..100] <5>.");
    puts("  <a>  Angulo sobre la vertical [0..90] <90>.");
    puts("  <v>  velocidad de giro [1..100] <10>.");
    puts("  <i>  rotacion de las orbitas [float<1] <0.0>.");
    printf("Ejemplos: xpngw 3 60 * -0.3 , vpcw 24");
    getch();
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void swap (int *a, int *b)
{
  int c = *a; *a = *b; *b = c;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct
{
  int step, part, xcen, ycen, color;
  tunneldata t;

} collisiondata;

void initcollision (collisiondata *d)
{
  d->step = 0;
  d->part = 2;
}
void opencollision (collisiondata *d, int xmid, int ymid, int color)
{
  const int r=getmaxy()/16;

  d->part = d->step = 0;
  d->color = color;
  inittunnel(&d->t, d->xcen = xmid, d->ycen = ymid, r, r/6);
  /*setpalette(0,getmaxcolor()); setpalette(0,0);*/
  setbkcolor(DARKGRAY);
  setbkcolor(LIGHTGRAY);
  setbkcolor(WHITE);
  setbkcolor(DARKGRAY);
  setbkcolor(LIGHTGRAY);
  setbkcolor(BLACK);
}
void runcollision (collisiondata *d)
{
  const int STEPS=10;
  const int r=getmaxy()/16;

  if (d->step > STEPS)
  {
    d->step = 0; d->part++;
    inittunnel(&d->t, d->xcen, d->ycen, r, r/6);
  }
  if (d->part > 1)
  {
    d->step = 0;
    nosound();
    return;
  }
  setwritemode(1); setlinestyle(DOTTED_LINE, 0, THICK_WIDTH);
  setcolor(d->color);
  runtunnel(&d->t);
  /*sound(1000-(d->part*STEPS + d->step)*50);*/
  d->step++;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*
  Volumen de la esfera: V=4/3·PI·R^3 (Bronshtein 203)
  Pongamos que la masa es igual en todo el volumen.
*/
double RadiusToMass (double radius)
{
  double mass;
  mass = 4./3.*M_PI*pow(radius,3.);
  return mass;
}
double MassToRadius (double mass)
{
  double radius;
  radius = pow((3.*mass)/(4*M_PI),1./3.);
  return radius;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* Una partícula (o planeta) */
typedef struct {
  dynamicdata d;       /* Datos para animación */
  ellipsepolardata e;  /* Datos para la elipse */
  int count;           /* Cuenta de vueltas */
  int colisiones;      /* Número de colisiones que ha recibido */
  int color;
} planetdata;

#define MAXSIZE 100 /* Número máximo de particulas */
#define ARG(c) (strchr(argv[1],(c)))

/* Número de collisiones máximo estimado que se pueden producir a la vez */
#define NUMCOLLS 50

void main(int argc, char *argv[])
{
  int SIZE=5, size; /* Número de partículas mostradas */
  double INCROT=0; /* Incremento de la rotación en las órbitas */
  planetdata p[MAXSIZE]; /* Reservar espacio para las partículas */
  static int start = 1; /* Indica que estamos en inicialización */
  int xCen, yCen, ii, jj, i, j, k, icolor=0, r;
  double a, d;
  dynamicdata d0; /* el sol */
  ellipsepolardata e0;
  collisiondata cd[NUMCOLLS]; int ci=0; /* Registro de colisiones */
  clock_t ticks1, ticks2; /* Cuenta del tiempo */
  unsigned long step=0; /* Número de iteraciones */

/* ARGUMENTOS EN LÍNEA DE COMANDOS */
  if (argc < 2) {
    printhelp();
    return;
  }
  strlwr(argv[1]);
  if (argc >= 6 && *argv[5] != '*') {
    INCROT = atof(argv[5]);
  }
  if (argc >= 5 && *argv[4] != '*') {
    VELOC = atoi(argv[4]);
    if (VELOC < 1 || VELOC > 100) VELOC = 10;
  }
  if (argc >= 4 && *argv[3] != '*') {
    ANGV = atof(argv[3]);
    if (ANGV < 0 || ANGV > 90) ANGV = 90;
  }
  if (argc >= 3 && *argv[2] != '*') {
    SIZE = atoi(argv[2]);
    if (SIZE < 1 || SIZE > MAXSIZE) SIZE = 1;
  }

/* INICIALIZAR */
  randomize();
  opengraphics();

  xCen = getmaxx() / 2;
  yCen = getmaxy() / 2;

  if (ARG('d')) drawdoublespiral();
  if (ARG('s')) centerstars(xCen, yCen, xCen*2);
  /*if (ARG('s')) stars();*/

  /* Inicializar la estructura para cada partícula */
  for (i=0; i<SIZE; ++i) {
    p[i].color = 10+(i%5);
    r = ARG('e') ? 8 : (2+random(3));
    opendynamic(&p[i].d, r, p[i].color, ARG('e') ? i+1 : -1);
    initellipsepolar(&p[i].e, xCen,yCen, 50+random(150), 30+random(150),
      random(360), ARG('p') ? 1 : random(2), p[i].color, RadiusToMass(r));

    if (ARG('a')) ellipsepolar(&p[i].e);
    if (ARG('o')) draworbit(&p[i].e);
    p[i].count = 0;
    p[i].colisiones = 0;
  }

  /* El centro de gravedad, es decir, el sol */
  if (! ARG('x'))
    if (ARG('c')) {
      setfillstyle(SOLID_FILL, getmaxcolor()); setcolor(getmaxcolor());
      pieslice(xCen, yCen, 0, 360, 10);
      setcolor(LIGHTGRAY); circle(xCen, yCen, 10);
    } else {
      opendynamic(&d0, 10, 15, -1);
      paintdynamic(&d0, xCen, yCen);
      closedynamic(&d0);
    }

  if (ARG('l') || ARG('g')) {
    setcolor(CYAN);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    setwritemode(1); /* XOR */
  }

  for(i=0; i<NUMCOLLS; ++i) initcollision(&cd[i]);

/******* BUCLE PRINCIPAL *******/
  size = SIZE;
  ticks1 = ticks2 = clock();
  for(step=0;;step++)
  {
    /* Si se pulsa una tecla, hacer una pausa */
    if (kbhit()) {
      if (getch()==27) { /* ESC */
	break;
      } else {
	getch();
	ticks1 = clock() - (ticks2 - ticks1);
      }
    }

    /* Mostrar siguiente secuencia de las colisiones que queden pendientes */
    if (ARG('c')) for(i=0; i<NUMCOLLS; ++i) runcollision(&cd[i]);

    /* Borrar partículas de las anteriores coordenadas */
    for (i=0; i<SIZE; ++i) erasedynamic(&p[i].d);

    /* Calcular nuevas coordenadas */
    for (i=0; i<SIZE; ++i) {
      if (INCROT) incrotation(&p[i].e, INCROT);
      getpoint(&p[i].e, p[i].e.w);
    }

    /* Guardar imagen y pintar partícula */
    if (ARG('m')) for (i=0; i<SIZE; ++i) savedynamic(&p[i].d, p[i].e.x, p[i].e.y);
    for (i=0; i<SIZE; ++i) paintdynamic(&p[i].d, p[i].e.x, p[i].e.y);

    if (start)
      start = 0;
    else {
      /* Dejar rastro al moverse la partícula */
      if (ARG('n')) {
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	for (i=0; i<SIZE; ++i) {
	  setcolor(p[i].e.color-8);
	  line(p[i].e.xx, p[i].e.yy, p[i].e.x, p[i].e.y);
	}
      }

      /* Borrar líneas anteriores */
      setcolor(CYAN); setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
      if (ARG('g')) for (i=0; i<SIZE; ++i) line(p[i].e.xx, p[i].e.yy, xCen, yCen);
      if (ARG('l')) for (i=0; i<SIZE; ++i) for (j=i+1; j<SIZE; ++j)
	line(p[i].e.xx, p[i].e.yy, p[j].e.xx, p[j].e.yy);
      if (ARG('w')) for (i=0; i<SIZE; ++i) estela (&p[i].e, 0);
    }

    /* Hallar ángulos */
    for (i=0; i<SIZE; ++i)
      if (ARG('i')) /* Depende del número de iteraciones */
	p[i].e.w = p[i].e.dw + step * p[i].e.dw;
      else /* Depende del tiempo que ha pasado */
	p[i].e.w = p[i].e.dw * (ticks2-ticks1);

    /* Líneas uniendo las partículas */
    setcolor(CYAN); setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    if (ARG('g')) for (i=0; i<SIZE; ++i) line(p[i].e.x, p[i].e.y, xCen, yCen);
    if (ARG('l')) for (i=0; i<SIZE; ++i) for (j=i+1; j<SIZE; ++j)
      line(p[i].e.x, p[i].e.y, p[j].e.x, p[j].e.y);
    if (ARG('w')) for (i=0; i<SIZE; ++i) estela (&p[i].e, 1);

    /* Buscar posibles colisiones entre partículas */
    if (ARG('c')) for (i=0; i<SIZE; ++i) for (j=i+1; j<SIZE; ++j) {
      d = distance(p[i].e.x, p[i].e.y, p[j].e.x, p[j].e.y);
      if ( d < (p[i].d.radius + p[j].d.radius)) /* Si hay colisión... */
      {
	/* La partícula con más masa absorbe a la de menos masa */
	if (p[i].e.mass > p[j].e.mass)
	  { ii = i; jj = j; } else { ii = j; jj = i; }

	/* Inicializar estructura para mostrar la colisión */
	ci = (ci+1) % NUMCOLLS;
	opencollision(&cd[ci], (p[ii].e.x + p[jj].e.x)/2, (p[ii].e.y + p[jj].e.y)/2, p[jj].e.color);

	/* Borrar rastro (líneas) de la partícula que se va a destruir */
	setcolor(CYAN); setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	if (ARG('g')) line(p[jj].e.x, p[jj].e.y, xCen, yCen);
	if (ARG('l')) for (k=0; k<SIZE; ++k) line(p[jj].e.x, p[jj].e.y, p[k].e.x, p[k].e.y);
	if (ARG('w')) estela (&p[jj].e, 1);

	/* Aumentar tamaño de la partícula con la masa de la otra */
	erasedynamic(&p[ii].d); closedynamic(&p[ii].d);
	p[ii].e.mass += p[jj].e.mass; /* Sumar la masa de otra partícula */
	opendynamic(&p[ii].d, MassToRadius(p[ii].e.mass),
	  p[ii].e.color, ARG('e') ? p[ii].d.num : -1);
	erasedynamic(&p[ii].d);
	paintdynamic(&p[ii].d, p[ii].e.x, p[ii].e.y);
	p[ii].colisiones ++;

	/* Aprovechar el hueco que ha quedado para reducir el array */
	SIZE--;
	erasedynamic(&p[jj].d); closedynamic(&p[jj].d);
	copyellipsepolar(&p[jj].e, &p[SIZE].e);
	copydynamic(&p[jj].d, &p[SIZE].d);
	p[jj].colisiones = p[SIZE].colisiones;

	/**/
	p[SIZE].e.mass = 0.0;
      }
    }

    /* Cuenta las vueltas que ha dado cada partícula */
    if (ARG('v')) {
      if (ARG('c')) for (i=0; i<size; ++i) {
	gotoxy(1+(i/24)*8,2+(i%24));
	if (p[i].e.mass == 0.)
	  printf("               ");
	else
	  printf("%d: %8.2f   ", ARG('e') ? p[i].d.num: i+1, p[i].e.mass);
      }
      else for (i=0; i<SIZE; ++i) {
	gotoxy(1+(i/24)*8,2+(i%24));
	printf("%2d: %d", i+1, (int)(p[i].e.w / (M_PI*2)));
      }
    }

    /* Efecto especial de radiación solar */
    if (ARG('r')) {
      icolor = (icolor+1) % 3;
      setpalette(geticolor(0),geticolor(icolor % 3));
      setpalette(geticolor(1),geticolor((icolor+1) % 3));
      setpalette(geticolor(2),geticolor((icolor+2) % 3));
    }

    /* Mostrar el tiempo que ha pasado */
    ticks2 = clock();
    if (ARG('t')) {
      gotoxy(1,1);
      if (ARG('i'))
	printf("loops: %ld", step);
      else
	printf("time: %ld", (ticks2-ticks1));
    }
  }

/* FINALIZACIÓN */
  nosound();
  for (i=0; i<SIZE; ++i) closedynamic(&p[i].d);
  closegraphics();
  return;

} /* main */

/* FIN DEL FICHERO FUENTE */













