#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

//PROTOTIPOS DE FUNCIONES
void marco (void);
void read_mtrz(int matrans[10][10],int);
void wri_mtrz(int matrans[10][10],int);
int adding_ppal(int matrans[10][10],int);
int adding_second(int matrans[10][10],int);
void inver_mtrz(int matrans[10][10],int,int matranst[10][10]);

main(){
int q,q2,q3,q4,o,o2,o3,o4,ev=0,ev1=0,ev2=0,ev3=0,evc=0;

char *opc=NULL,*opc2=NULL,*opc3=NULL,*opc4=NULL;
int i,j,m,n,da,db,da2,db2,mult,add;
int a[10][10],b[10][10],atrans[10][10],btrans[10][10];



i:
marco();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("ESTRUCTURA DE DATOS\n");
gotoxy(32,7);
printf("MENU PRINCIPAL");
gotoxy(18,11);
printf("1.  ENTRADA DE DATOS");
gotoxy(18,14);
printf("2.  OPERACIONES");
gotoxy(18,17);
printf("3.  CONSULTAR DATOS");
gotoxy(18,20);
printf("4.  TERMINAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);
gets(opc);
o=atoi(opc);
switch (o){

 case 1 :    //PRIMERA OPCION

   i2:
marco();
gotoxy(30,4);
printf("  ENTRADA DE DATOS\n");
  gotoxy(18,11);
 printf("1.  DIMENSION DE LAS DOS MATRICES CUADRADAS");
gotoxy(18,14);
printf("2.  CAPTURA DE LOS ELEMENTO DE LAS MATRICES");
gotoxy(18,17);
printf("3.  RETORNAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);
gets(opc2);
   o2=atoi(opc2);
   switch (o2){
      case 1:
	 clrscr();

	  marco();
	  gotoxy(10,6);
	  printf("DIGITE LA DIMENSION DE LA MATRIZ CUADRADA A:   ");
	  scanf("%d",&n);
	  gotoxy(10,11);
	  printf("DIGITE LA DIMENSION DE LA MATRIZ CUADRADA B:   ");
	  scanf("%d",&m);
	  ev=1;
	  goto i2;



     case 2:
	if (ev==0){
	clrscr();
	marco();
	gotoxy(10,10);
	printf("NO HAY DATOS PARA PROCESAR !! ");
	getch();
	goto i2;}


	marco();
	gotoxy(2,2);
	printf("\tDIGITE LOS ELEMENTOS DE LA MATRIZ A \n");
	read_mtrz(a,n);
	marco();
	printf("\tDIGITE LOS ELEMENTOS DE LA MATRIZ B \n");
	read_mtrz(b,m);
	evc=1;
	goto i2;

    case 3:
   goto i;
  default:
     goto i2;
    }



   case 2: //SEGUNDA OPCION
     if (ev==0 || evc==0 ){
	clrscr();
	marco();
	gotoxy(10,10);
	printf("NO HAY DATOS PARA PROCESAR !! ");
	getch();
	goto i;}

 i3:
 marco();
 gotoxy(30,4);
 printf("  OPERACIONES\n");
 gotoxy(18,11);
 printf("1.  SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL");
 gotoxy(18,14);
 printf("2.  SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA");
 gotoxy(18,17);
 printf("3.  HALLAR LA MATRIZ TRANSPUESTA");
 gotoxy(18,20);
 printf("4.  RETORNAR");
 gotoxy(30,23);
 printf("DIGITE OPCION [ ]");
 gotoxy(45,23);
 gets(opc3);
    o3=atoi(opc3);
    switch(o3){
     case 1:
	  clrscr();
	  //adda de la diagonal principal de  la matrans a
	  da=adding_ppal(a,n);
	  //adda de la diagonal principal de la matrans b
	  db=adding_ppal(b,m);
	  marco();
	  gotoxy( 10,10);
	  printf("OPERACION TERMINADA !! ");
	  getch();
	  ev1=1;
	  goto i3;


      case 2:
	 clrscr();
	 //adda de la diagonal secundaria de a
	 da2=adding_second(a,n);
	 //adda de la diagonal secundaria de b
	 db2=adding_second(b,m);
	 marco();
	 gotoxy(10,10);
	 printf("OPERACION TERMINADA !! ");
	 getch();
	 ev2=1;
	 goto i3;

       case 3:

	 clrscr();
	  //matrans transpuesta de a
	 inver_mtrz(a,n,atrans);
	 //matrans transpuesta de b
	 inver_mtrz(b,m,btrans);
	 marco();
	 gotoxy(10,10);
	 printf("OPERACION TERMINADA !! ");
	 getch();
	 ev3=1;
	 goto i3;

      case 4:
	goto i;
	default:
	  goto i3;

   }

    case 3: //TERCERA OPCION
      if (ev==0 || evc==0){
      clrscr();
      marco();
      gotoxy(10,10);
      printf("NO HAY DATOS PARA PROCESAR !! ");
      getch();
      goto i;}
      else
       if (ev1+ev2+ev3==0){
	 clrscr();
	 marco();
	 gotoxy(10,10);
	 printf("NO HA REALIZADO LAS OPERACIONES !! ");
	 getch();
	 goto i;}
      else
	if (ev1==0 || ev2==0 || ev3==0){
	  clrscr();
	  marco();
	  gotoxy(2,10);
	  printf("FALTAN OPERACIONES POR REALIZAR , TERMINE DE REALIZAR TODAS LAS OPERACIONES !!");
	  getch();
	  goto i;}
	else
      i4:
      marco();
      gotoxy(30,4);
      printf("  CONSULTA DE DATOS\n");
      gotoxy(15,11);
      printf("1.  MOSTRAR LA SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL");
      gotoxy(15,14);
      printf("2.  MOSTRAR LA SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA");
      gotoxy(15,17);
      printf("3.  MOSTRAR LA MATRIZ TRANSPUESTA");
      gotoxy(15,20);
      printf("4.  RETORNAR");
      gotoxy(30,23);
      printf("DIGITE OPCION [ ]");
      gotoxy(45,23);
      gets(opc4);
      o4=atoi(opc4);
      switch (o4){
	case 1:
	  clrscr();
	  marco();
	  printf("LA MATRIZ A ES:\n");
	  wri_mtrz(a,n);
	  printf("LA SUMATORIA DE LA DIAGONAL PRINCIPAL DE A ES: %d \n",da);
	  getch();
	  marco();
	  printf("LA MATRIZ B ES: \n");
	  wri_mtrz(b,m);
	  printf("LA SUMATORIA DE LA DIAGONAL PRINCIPAL DE B ES: %d \n",db);
	  getch();
	  goto i4;

	case 2:
	   clrscr();
	   marco();
	   printf("LA MATRIZ A ES:\n");
	   wri_mtrz(a,n);
	   printf("LA SUMATORIA DE LA DIAGONAL SECUNDARIA DE A ES: %d \n",da2);
	   getch();
	   marco();
	   printf("LA MATRIZ B ES:\n");
	   wri_mtrz(b,m);
	   printf("LA SUMATORIA DE LA DIAGONAL SECUNDARIA DE B ES: %d \n",db2);
	   getch();
	   goto i4;

	case 3:
	   clrscr();
	   marco();
	   //printf("LA MATRIZ A ES: \n");
	   //wri_mtrz(a,n);
	   printf("LA MATRIZ TRANSPUESTA DE A ES:\n");
	   wri_mtrz(atrans,n);
	   getch();
	   marco();
	   //printf("LA MATRIZ B ES: \n");
	   //wri_mtrz(b,m);
	   printf("LA MATRIZ TRANSPUESTA DE B ES:\n");
	   wri_mtrz(btrans,m);
	   getch();
	   goto i4;


	case 4:
	    goto i;
	    default:
	      goto i4;

       } //Cierra Switch



    getch();





  case 4:
    break;
    default:
	goto i;

     } //Cierra Switch

}  //FIN DEL PROGRAMA PRINCIPAL


//FUNCIONES

void read_mtrz(int matrans[10][10],int fl)  //LEER MATRIZ
{
int i,j,s=1;
for(i=1;i<=fl;i++){
    for(j=1;j<=fl;j++){
       gotoxy(3,3+s);
       printf("Matriz [%d,%d] = ",i,j);
       scanf("%d",&matrans[i][j]);
     s++;
     }
}
return;
}

int adding_ppal(int matrans[10][10],int fl) //SUMA DIAG-PPAL
{
int i,j,apd;
apd=0;
for(i=1;i<=fl;i++){
   apd+=matrans[i][i];
}
return apd;
}


int adding_second(int matrans[10][10],int fl) //SUMA DIAG-SEC
{
int i,j,cf,asd;
asd=0;
cf=fl-1;
for(i=1;i<=fl;i++){
   asd+=matrans[i][i+cf];
   cf-=2;
}
return asd;
}


void inver_mtrz(int matrans[10][10],int fl,int matranst[10][10]) //MATRIZ TRANSPUESTA
{
int i,j;
for(i=1;i<=fl;i++){
   for(j=1;j<=fl;j++){
      matranst[i][j]=matrans[j][i];
   }
}
return;
}

void wri_mtrz(int matrans[10][10],int fl) //ESCRIBIR MATRIZ
{
int i,j,s=1;
for(i=1;i<=fl;i++){
   for(j=1;j<=fl;j++){
      gotoxy(3,3+s);
      printf("Matriz [%d,%d] = %d\n",i,j,matrans[i][j]);
    s++;
   }
}
return;
}
///////////////////////////

void marco (void){
int q,q2,q3,q4;
clrscr();
gotoxy(0,0);
printf("�");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("�");
}
gotoxy(79,0);
printf("�");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("�");
}
gotoxy(80,24);
printf("�");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("�");}

gotoxy(1,24);
printf("�");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("�");}
return;
}


