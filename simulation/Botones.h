void DibujeIcono(int x,int y, int *BitMap,int NumFila,int NumColumna)
 { for(int i=0;i<NumFila;i++)
     for(int j=0;j<NumColumna;j++)
      putpixel(x+j,y+i,*(BitMap++));
 }


int * Lapiz(void);
int * Icono(void);
int * Salir(void);
int * Restaurar(void);
int * Minimizar(void);
int * Mariposa(void);
int * Relleno(void);


int * Relleno(void)
 {
    static int Brochita[14][16]={
             15,15,15,15,15,15,15,15,0,0,15,15,15,15,15,15,
             15,15,15,15,15,15,15,0,15,0,15,15,15,15,15,15,
             15,15,0,0,0,15,0,15,15,15,0,0,15,15,15,15,
             15,0,0,0,15,0,15,15,15,0,15,15,0,15,15,15,
             0,0,0,15,0,3,3,3,3,3,3,0,0,0,15,15,
             0,0,15,0,3,3,3,3,3,3,0,0,0,0,0,15,
             0,0,15,0,0,3,0,3,3,0,0,0,0,0,3,0,
             0,0,0,15,15,0,3,3,0,0,0,0,0,3,3,0,
             0,0,0,15,15,0,3,0,0,0,0,0,3,3,0,15,
             0,0,0,15,15,15,0,0,0,0,0,3,3,0,15,15,
             0,0,0,15,15,15,15,0,0,0,3,3,0,15,15,15,
             15,0,0,15,15,15,15,15,0,3,3,0,15,15,15,15,
             15,0,0,15,15,15,15,15,15,0,0,15,15,15,15,15,
             15,15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,
            };
   return (int*) Brochita;
 }


int * Mariposa(void)
 {
     static int menu[74][74]={
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,14,14,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,0,14,14,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,14,14,0,0,14,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,14,14,0,0,0,14,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,4,0,14,14,0,0,0,14,14,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,14,14,0,0,0,14,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,0,14,14,0,0,4,0,0,0,0,14,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,14,14,0,5,0,0,0,0,0,14,14,14,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,5,0,14,14,0,0,4,0,4,14,14,14,14,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,5,4,0,14,14,0,0,0,0,0,0,0,14,14,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,0,0,14,14,0,0,0,5,0,0,2,0,0,0,0,14,14,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,14,14,0,0,4,0,0,0,2,2,0,4,0,14,14,14,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,5,0,0,14,0,0,0,5,0,0,0,2,2,2,0,0,14,14,14,14,0,15,15,15,15,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,4,0,0,0,2,2,2,2,0,0,0,14,14,0,0,15,15,15,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,4,0,0,0,5,0,0,0,2,2,2,2,2,0,0,0,0,0,14,0,0,15,15,15,15,15,15,15,6,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,5,0,0,4,0,0,0,2,2,2,2,2,2,0,0,4,0,0,14,14,14,0,15,15,15,15,15,15,6,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,2,2,2,2,2,2,0,4,0,0,0,14,14,14,14,0,15,15,15,15,15,6,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,4,0,0,0,2,2,2,2,2,2,2,0,0,0,5,0,0,0,0,0,0,15,15,15,15,15,6,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,2,2,2,0,15,15,15,15,6,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,2,2,2,2,2,2,2,2,0,0,4,0,0,2,2,2,2,2,0,15,15,15,6,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,5,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,0,15,15,15,6,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,9,9,0,0,5,0,0,0,0,2,2,2,2,2,2,0,0,4,0,0,2,2,2,2,2,2,2,0,15,15,6,15,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,9,9,0,4,0,0,4,0,0,2,2,2,2,2,2,0,5,0,0,2,2,2,2,2,2,0,0,0,15,15,6,15,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,9,0,0,2,9,0,0,2,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,0,15,15,6,6,15,15,15,15,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,9,9,0,9,0,2,2,2,0,0,2,2,2,2,2,0,0,4,0,0,2,2,2,2,0,0,0,0,0,15,6,6,6,6,15,6,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,9,9,9,0,0,2,2,2,4,0,2,2,2,2,2,0,5,0,0,2,2,2,2,0,0,0,5,0,0,6,6,8,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,9,9,0,4,0,2,0,0,2,2,2,2,0,0,0,0,0,2,2,2,2,0,5,0,0,0,0,6,8,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,9,9,0,0,9,0,0,0,5,0,0,2,2,2,2,0,0,4,0,0,2,2,2,2,2,0,0,0,0,6,8,14,8,6,15,15,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,0,0,9,9,0,0,0,4,0,0,0,5,2,2,2,0,5,0,0,2,2,2,2,2,2,0,0,0,6,6,8,14,8,6,0,0,0,0,2,2,2,2,0,14,14,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,9,9,0,0,9,0,0,5,0,2,2,0,0,2,0,0,0,0,0,2,2,2,2,2,0,0,0,0,6,14,8,14,8,6,0,0,0,0,0,2,2,2,2,0,14,14,14,0,14,14,14,0,0,0,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,0,9,9,9,0,9,0,0,0,2,2,2,2,0,0,5,0,4,0,2,2,2,2,2,0,0,0,0,6,14,8,14,8,6,0,0,5,0,0,2,2,2,2,2,0,14,14,0,14,14,14,14,0,0,14,0,0,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,0,0,9,9,0,0,5,0,2,2,2,2,0,0,4,0,0,0,2,2,2,2,0,0,0,0,0,6,14,8,14,8,14,6,0,0,0,0,0,2,2,2,2,0,0,14,0,0,14,14,14,0,0,14,14,14,0,0,0,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,0,0,9,0,0,0,0,2,2,2,4,0,0,0,0,2,2,2,2,2,0,0,0,0,0,6,14,8,14,8,14,6,0,0,5,0,0,2,2,2,2,2,0,0,0,0,0,0,14,0,0,14,14,14,0,0,0,0,0,0,15,15,15,
        15,15,15,15,15,15,15,15,15,15,0,5,0,0,0,0,4,0,5,2,0,0,4,0,5,2,2,2,2,0,0,0,0,15,15,6,14,8,14,8,14,6,0,0,0,0,0,2,2,2,2,2,0,0,5,0,4,0,0,0,4,0,14,14,0,0,0,14,14,14,0,0,15,15,
        15,15,15,15,15,15,15,15,15,0,0,0,4,0,5,0,2,0,0,4,0,5,0,0,0,0,2,0,0,0,0,0,15,15,6,14,8,14,8,14,6,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,14,14,0,0,0,0,0,15,
        15,15,15,15,15,15,15,0,0,4,5,0,0,0,2,2,2,2,5,0,0,0,2,4,0,5,0,0,0,0,0,15,15,6,14,8,14,8,14,6,0,0,0,2,2,2,2,2,2,2,0,0,4,0,0,4,0,2,2,2,2,2,0,4,0,0,0,0,0,0,0,14,0,15,
        15,15,15,15,15,0,0,0,0,0,0,0,5,4,2,2,2,2,0,0,0,2,2,2,0,0,4,0,0,15,15,15,6,14,8,14,8,14,6,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,4,0,0,0,14,14,14,0,0,
        15,15,15,0,4,0,0,4,0,15,15,0,0,0,0,2,2,0,0,2,0,0,15,5,0,0,0,15,15,15,15,15,6,8,14,8,14,6,15,0,0,0,2,2,2,2,2,0,0,0,4,0,0,2,2,2,2,2,2,2,0,0,0,4,0,0,0,0,14,14,14,0,0,0,
        15,0,0,0,0,0,0,15,15,15,15,15,0,5,0,4,5,0,15,15,15,0,0,0,0,15,15,15,15,15,15,6,8,14,8,14,6,15,15,0,0,2,2,2,2,0,0,0,0,5,0,0,2,2,2,2,2,2,2,0,0,5,0,0,5,0,14,14,14,0,0,0,4,0,
        15,0,4,0,0,15,15,15,15,15,15,15,15,0,0,0,0,0,15,15,15,15,0,15,15,15,15,15,15,15,15,6,14,8,6,6,15,15,0,0,0,2,2,2,0,0,0,4,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,14,14,14,0,0,0,0,0,15,
        15,0,0,15,15,15,15,15,15,15,15,15,15,15,0,0,5,0,15,15,15,15,15,15,15,15,15,15,15,15,15,6,6,6,15,15,15,0,0,0,2,2,2,2,0,0,5,0,0,0,2,2,2,2,2,2,2,0,0,0,4,0,0,14,14,14,0,0,0,0,4,0,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,2,2,2,2,0,4,0,0,0,2,2,2,2,2,2,2,2,2,0,0,5,0,0,14,14,14,0,0,4,0,0,0,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,2,2,2,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,4,0,0,14,14,0,0,0,0,0,0,0,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,2,2,2,0,0,5,0,2,2,2,2,2,2,2,2,2,2,0,0,5,0,0,14,14,0,5,0,4,0,0,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,2,2,0,4,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,14,0,4,0,0,0,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,2,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,4,0,0,4,0,0,4,0,0,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,5,0,2,0,0,5,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,5,0,4,0,2,2,2,0,0,0,0,0,0,5,15,0,4,0,0,4,0,0,0,4,0,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,15,2,4,0,0,0,5,0,0,5,0,0,4,0,0,4,0,0,15,0,0,0,5,0,0,5,0,0,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,2,2,2,0,4,0,0,2,0,0,0,9,2,2,9,0,0,0,15,15,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,2,0,0,5,0,4,2,2,2,0,5,2,2,2,2,0,5,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,2,2,2,2,0,0,0,2,2,0,4,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,4,2,2,2,2,0,4,0,4,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,5,0,5,2,2,0,5,0,0,0,0,9,9,9,9,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,2,2,0,0,0,0,0,0,0,9,9,9,0,0,9,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,5,0,5,2,2,2,2,4,0,5,0,0,0,9,9,9,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,4,2,2,2,0,0,0,0,9,9,9,0,0,9,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,2,2,5,0,0,0,0,0,9,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,5,0,4,0,0,0,9,9,9,0,0,9,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,5,0,4,0,0,0,9,9,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,5,0,0,9,9,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,5,0,0,15,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,4,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,4,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
        15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15        };
   return (int*) menu;
 }


int * Salir(void)
 {
    static int Salida[9][8]={
             7,7,7,7,7,7,7,7,
             0,0,7,7,7,7,0,0,
             7,0,0,7,7,0,0,7,
             7,7,0,0,0,0,7,7,
             7,7,7,0,0,7,7,7,
             7,7,0,0,0,0,7,7,
             7,0,0,7,7,0,0,7,
             0,0,7,7,7,7,0,0,
             7,7,7,7,7,7,7,7
           };
   return (int*) Salida;
 }

int * Restaurar(void)
 {
    static int Restaura[9][8]={
             7,7,0,0,0,0,0,0,
             7,7,0,0,0,0,0,0,
             7,7,0,7,7,7,7,0,
             0,0,0,0,0,0,7,0,
             0,0,0,0,0,0,7,0,
             0,7,7,7,7,0,0,0,
             0,7,7,7,7,0,7,7,
             0,7,7,7,7,0,7,7,
             0,0,0,0,0,0,7,7
           };
   return (int*) Restaura;
 }

int * Minimizar(void)
 {
    static int Minimiza[9][8]={
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,7,7,7,7,7,7,7,
             7,0,0,0,0,0,0,7,
             7,0,0,0,0,0,0,7,
           };
   return (int*) Minimiza;
 }


int * Icono(void)
 {
    static int Esquina[16][16]={
             8,8,8,8,8,8,8,8,8,8,8,1,1,1,1,1,
             8,15,15,15,15,15,15,15,15,15,7,8,1,1,1,1,
             8,15,15,15,15,15,15,15,15,15,7,15,8,1,1,1,
             8,15,15,15,15,15,4,4,4,4,0,0,0,0,1,9,
             8,15,15,15,15,8,8,8,8,4,15,15,7,1,9,9,
             8,15,15,15,15,12,12,12,12,4,15,15,7,9,9,1,
             8,15,15,2,2,0,12,12,12,4,15,15,9,9,1,1,
             8,15,2,14,10,2,0,12,12,4,15,9,9,1,1,1,
             8,15,2,10,10,2,0,12,12,1,9,9,1,0,1,1,
             8,15,2,10,10,2,0,15,15,11,9,1,7,0,1,1,
             8,15,15,0,0,0,15,15,8,0,1,15,7,0,1,1,
             8,15,15,15,15,12,12,8,7,0,15,15,7,0,1,1,
             8,15,15,12,12,4,4,4,0,15,15,15,7,0,1,1,
             8,15,4,4,4,15,15,15,15,15,15,15,7,0,1,1,
             8,7,7,7,7,7,7,7,7,7,7,7,7,0,1,1,
             0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
            };
   return (int*) Esquina;
 }

int * Lapiz(void)
 {
  static int Escribe[15][9]={
           7,7,7,7,7,0,0,0,7,
           7,7,7,7,0,4,4,4,0,
           7,7,7,7,0,4,15,15,0,
           7,7,7,0,0,4,15,0,7,
           7,7,7,0,14,0,0,0,7,
           7,7,0,14,15,7,0,7,7,
           7,7,0,15,14,0,0,7,7,
           7,0,15,14,7,0,7,7,7,
           7,0,14,15,0,0,7,7,7,
           0,14,15,7,0,7,7,7,7,
           0,0,14,0,0,7,7,7,7,
           0,0,0,0,7,7,7,7,7,
           0,0,0,7,7,7,7,7,7,
           0,0,7,7,7,7,7,7,7,
           0,7,7,7,7,7,7,7,7,
          };
  return (int*) Escribe;
 }
