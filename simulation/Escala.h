// *******************************************************************
// **  FUNCION QUE GUARDA CUALQUIER PARTE DE LA PANTALLA EN ARCHIVO **
// *******************************************************************

void Guardar_Archivo(char *Nombre_Archivo,int x0,int y0,int x1,int y1)
{
 int filas, columnas;
 int i,j;
 filas=y1-y0;
 columnas=x1-x0;
 ofstream Archivo(Nombre_Archivo);
  if(Archivo)
   {  Archivo<<filas<<" ";
      Archivo<<columnas<<" ";
      for(i=0; i<=filas; i++)
         for(j=0; j<=columnas; j++)
           Archivo<<getpixel(j+x0,i+y0)<<" "; //* GUARDA EL COLOR
      Archivo.close();
    }
}


// ********************************************************************
// ** FUNCION QUE RECUPERA UNA PARTE DE LA PANTALLA DESDE UN ARCHIVO **
// ********************************************************************

void Leer_Archivo(char *Nombre_Archivo,int x0,int y0)
{
 int i,j,Color;
 int filas, columnas;
 ifstream Archivo(Nombre_Archivo);
 if(Archivo)
   {
       Archivo>>filas;
       Archivo>>columnas;
       for(i=0; i<=filas; i++)
         for(j=0; j<=columnas; j++)
           { Archivo>>Color;
             putpixel(j+x0,i+y0,Color); //* RECUPERA EL COLOR Y LO DIBUJA.
             }
      Archivo.close();
    }
}

// ********************************************************************
// **   FUNCION QUE RECUPERA ESCALA EL PUNTO SE¥ALADO POR EL MOUSE   **
// ********************************************************************

void Leer_Escalado(char *Nombre_Archivo,int x0,int y0)
{
 int i,j,Color,x,y,k,h;
 int filas, columnas;
 x=x0;
 y=y0;
 
 ifstream Archivo(Nombre_Archivo);
 if(Archivo)
   {
       Archivo>>filas;
       Archivo>>columnas;
       for(k=0; k<=filas; k++)
       { for(h=0; h<=columnas; h++)
         {  Archivo>>Color;
            for(i=y; i<y+20; i++)
            { for(j=x; j<x+20; j++)
              {
                putpixel(j,i,Color); // RECUPERA EL COLOR Y LO DIBUJA.
              }
            }
          x=x+20;
          }
        x=x0;
        y=y+20;
       }
     Archivo.close();
    }
}


// *******************************************************************
// **      FUNCION QUE ESCALA CUALQUIER PARTE DE LA PANTALLA        **
// *******************************************************************

void Escala(int Vert, int Horiz)
{  int x1,y1;
   int i,j,k,h,Color,x,y;
   
   x1 = Vert+16;
   y1 = Horiz+14;

   x=Vert;
   y=Horiz;

   Guardar_Archivo("ESCALA",x,y,x1,y1);
   Leer_Escalado("ESCALA",150,90);
   unlink("ESCALA");

}

