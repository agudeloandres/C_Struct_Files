#include<stdio.h>
#include<conio.h>

//prototipo de funciones//

void Lectura_mat (int matriz[20][20],int);
void Escritura_mat (int matriz[20][20],int);
int suma_diag_ppal (int matriz[20][20],int);
int suma_diag_sdria (int matriz[20][20],int);
void transpuesta (int matriz[20][20],int tm[20][20],int);

//programa de matrices//

void main()
{

int A[20][20],B[20][20],AT[20][20],BT[20][20],N1,M1,SDPA,SDSA,SDPB,SDSB;
char opcion,S,N,n,s,Var;
unsigned int SW=0;

//creacion de menu//



clrscr();
gotoxy(15,8);
printf("       UNIVERSIDAD COOPERATIVA DE COLOMBIA");

gotoxy(15,10);
printf("           PROGRAMA INGENIERIA DE SISTEMAS");

gotoxy(15,12);
printf("              ESTRUCTURA DE DATOS I");

gotoxy(15,14);
printf("            CLARA INES CAYON GUARDIOLA");


getch();
clrscr;



do{
clrscr();
gotoxy(15,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(15,4);
printf("PROGRAMA DE INGENIERIA DE SISTEMAS");
gotoxy(15,6);
printf("manejo de matrices cuadradas");
gotoxy(10,8);
printf("1- lectura de las matrices");
gotoxy(10,10);
printf("2- operaciones");
gotoxy(10,12);
printf("3- consulta");
gotoxy(10,14);
printf("4- salir");
gotoxy(10,16);
printf("digite opcion");

do{
opcion=getchar();
}while (opcion < '0' && opcion > '4');
switch (opcion){

case '1': if(SW==0){
	    SW=1;
	 //lectura de las matrices //
    clrscr();
    gotoxy(15,4);
printf("submenu de lectura de matriz");

    gotoxy(10,8);
printf("1- leer matriz A");

    gotoxy(10,10);
printf("2- leer matriz B");

    gotoxy(10,12);
printf("3- retornar");

    gotoxy(10,14);
printf("digite la opcion");

do{
opcion=getchar();
}while(opcion < '0' && opcion > '3');
switch(opcion){

	 case '1': clrscr();
	     //lectura de la matriz A //
	     printf("Dimension de A");
	     scanf("%d",&N1);
	     Lectura_mat(A,N1);
	     break;
	 case '2': clrscr();
	     printf("Dimension de B");
	     scanf("%d",&M1);
	     Lectura_mat(B,M1);
	     break;
	    default : break;

	  }while (opcion != '3');
	   }
	 else
	  {

      printf("la matriz ya esta creada desea cambiar los datos  si(s) no(n)");
      do{
      scanf("%c",&Var);
      }while(Var==s|| Var==s);{
      SW=0;
     }
    }
    break;
	  case'2': if (SW==1){
	   do{
	   clrscr();
	       gotoxy(10,2);
	       printf("submenu de operaciones ");

	       gotoxy(10,4);
	       printf("1- suma de los elementos de la diagonal pricipal");

	       gotoxy(10,6);
	       printf("2- suma de los elemento de la diagonal secundaria");

	       gotoxy(10,8);
	       printf("3- transpuesta de la matrices");

	       gotoxy(10,10);
	       printf("4- retornar");

	       gotoxy(10,14);
	       printf("digite la opcion");

	       do{
		opcion=getch();
	      }while (opcion < '0' && opcion > '4');

	      switch (opcion){

	     case '1': SDPA= suma_diag_ppal(A,N1);
		       SDPB= suma_diag_ppal(B,M1);
		   printf("la suma de los elementosde la diagonal principal de A y B son: %d y %d respectivamente",SDPA,SDPB);
		   break;

	     case '2': SDSA=Suma_diag_sdria(int matriz [20][20],int);
		       SDSB=Suma_diag_sdria(B,M1);
		  printf("la suma de los elemnetos de la diagonal secundaria de A y B son: %d respectivamente ",SDSA,SDSB);

		  break;

	     case '3':
		      Transpuesta(A,At,N1);
		      Transpuesta(B,Bt,M1);
		      escritura_mat(At,N1);
		      escritura-mat(Bt,M1);
		    break;

		  default: break;
		}
	       }while(opcion!=4);
	       }
	       else{
		printf("la matriz no ha sido leida");
		validar();
	      }
	      break;

	    case '3': if (SW==1){
		  do{
		    clrscr();

	       gotoxy(15,4);
	       printf("submenupara escribir las operaciones");
	       gotoxy(10,6);
	       printf("1.  Operaciones con la matriz A");
	       gotoxy(10,8);
	       printf("2.  Operaciones con la matriz B");
	       gotoxy(10,10);
	       printf("3.  Retornar");
	       gotoxy(10,16);
	       printf("Elija la opci¢n");
	       do{
		  opcion=getchar();
		  }while(opcion < '0' && opcion >'4');
		  switch (opcion){
		     case '1':
			   printf("La matriz A es:");
			   escritura_mat(A,N1);
			   printf("la suma de los elementos de la diagonal principal es: %d",SDPA);
			   prinf("la suma de los elementos de la diagonal secundaria es: %d",SDPA),
			   printf("La transpuesta de la matriz A es  ");
			   escritura mat(At,N1);
			   break;
		     case '2' :
			   printf("la matriz B es:   ");
			   escritura_mat(B,M1);
			   printf("la suma de los lementos de la diagonal principal es: %d", SDPB);
			   printf("La suma de los elementos de la diagonal secundaria es: %d",SDBA);
			   printf("la transpuesta de la matriz B es");
			   escritura_mat(BT,MT);
			   break;
			   default:break;
			   }while (opcion!='3');
			   }
			   else{
			   printf("La matirz no ha sido leida");
			   validar();
			   }

			   break;
			   }while (opcion!='4');
			   clrscr();
			   printf("fin de proceso");
			   }while(opcion <'0' && opcion>'4');

			   //funciones
			   void lectura_mat(int mat[20][20],int p);
			   {
			   int i,j;
			     for(i=1; i<=p; i++){
				for(j=1; j<=p; j++){
				printf("m[%d][%d]",i,j);
				scanf("%d",&mat[i][j]);
				}
				}
				int sum_diag_ppal(int mat[20][20],int p);
				{
				int suma_diag, i;
				suma_diag=0;
				for(i=1;i<=p,i++){
				  suma_diag+=mat[i][i];
				  }
				  return suma_diag;
				  }
	       //suma de la diagonal secundaria de la matriz
	       int suma_diag_sdria(int matriz[20][20],int p);
	       suma_diag_sdria=0;
	       for(i=1;i<=p;i++){
		  suma_diag_sdria += mat[i][j];
		  j-=1;
		  }
		  return suma_diag_sec;
		  }
		  void transpuesta(int mat[20][20],int tmat[20][20],int p);
		  {
		  int i,j;
		  for(i=1;i<=p;i++){
		     for(j=1;j<=p;j++){
		     tmat[i][j]= mat[j][i];
		     }
		     }

		     void validar();
		     {
		     char op;
		     printf("presione cualquier tecla para continuar");
		     op=getch;
		     }




