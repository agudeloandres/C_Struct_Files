#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

  struct stackNode{
	 float codigo;
	 char nombre[30];
	 float nota1;
	 float nota2;
	 float prom_student;
	 struct stackNode *nextptr;
	 };

  typedef struct stackNode STACKNODE;
  typedef  STACKNODE *STACKNODEPTR;
  void push(STACKNODEPTR *, float, char*, float, float,int,float);
  int pop(STACKNODEPTR *);
  int pila_vacia(STACKNODEPTR);
  void printstack(STACKNODEPTR);
  int instructions(void);

main ()
{
int sw,lon;

STACKNODEPTR stackptr = NULL;
int  choice,est,i,cdel,k,y,p;
char name[30];
float not1,not2,prom,cod;
clrscr();
while((choice = instructions()) != 5 ){
     switch(choice){

	  case 1:
		clrscr();
		gotoxy(10,10);
		printf("Entre cantidad de estudiantes...[   ] ");
		gotoxy(43,10);
		scanf("%d",&est);

     for(i=1;i<=est;i++){
		clrscr();
		gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {
    gotoxy (k,y);
    gotoxy(k,1);printf("Í\n");
    gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }
		// CAPTURA DE LA INFORMACION DE LOS NODOS

		gotoxy(25,8);
		printf(" PROCESAMIENTO DE ESTUDIANTES ");
		gotoxy(25,10);
		printf("code: ");
		scanf("%f",&cod);
		gotoxy(25,12);
		printf("Name: \n");
		gotoxy(31,12);
		cin.getline(name,30);
		gotoxy(25,14);
		printf("Note1: ");
		gotoxy(32,14);
		do{
		gotoxy(32,14);
		clreol();
		scanf("%f",&not1);
		}while(not1<0 || not1>5);
		gotoxy(25,16);
		printf("note2: ");
		do{
		gotoxy(32,16);
		clreol();
		scanf("%f",&not2);
		}while(not2<0 || not2>5);
		prom = (not1+not2);
		// ENVIA INFO Y GUARDA

		push(&stackptr,cod,name,not1,not2,lon,prom);
		clrscr();
		}
		break;

	 case 2:
		if(! pila_vacia(stackptr)){//VERIFICA ESTADO DE LA PILA
		    printf("\n",pop(&stackptr));//SACA INFO DE LA PILA
		    gotoxy(25,20);
		    printf("presione  <<enter>> ");
		    getch();
	      }
		else{
		    gotoxy(25,20);
		    printf("La pila esta vacia...! ");
		    getch();
		    }

		break;
	 case 3:
		clrscr();
		printstack(stackptr); // MUESTRA PILA
		getch();
		break;
	 case 4:
	       if(! pila_vacia(stackptr)){//VERIFICA ESTADO DE LA PILA

	       clrscr();
	       void eliminar();

	       }
		  else{
		      gotoxy(25,20);
		      printf("La pila esta vacia...\n\n");
	       }


	       getch();
		break;
	   default:
		printf(" Invalid choice.\n\n");
		break;
	     }

	     }
     return 0;
     }

int instructions(void)
{
clrscr();
    int k,y,p;

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }

int op;
char c[80];
gotoxy(25,4);
printf("  M E N U   P R I N C I P A L ");
printf("\n\n");
gotoxy(20,8);
printf(" 1  Insertar informacion en pila\n");
gotoxy(20,10);
printf(" 2  Borrar informacion de la pila(Ultimo)\n");
gotoxy(20,12);
printf(" 3  Consultar informacion de la pila\n");
gotoxy(20,14);
printf(" 4  Eliminar por (codigo)\n");
gotoxy(20,16);
printf(" 5  Fin proceso\n");
gotoxy(20,18);
printf("enter option [ ]");
gotoxy(34,18);
gets(c);
op = atoi(c);
return op;
}

void push(STACKNODEPTR *topptr,float cod,char *name,float not1,float not2,int lon,float prom)
{
int j;
STACKNODEPTR newptr;

newptr = new(STACKNODE);


if(newptr != NULL){
   newptr -> codigo = cod;
   lon = strlen(name);
   for(j=0;j<=lon;j++){
      newptr->nombre[j]=name[j];
     }
   newptr -> nota1 = not1;
   newptr -> nota2 = not2;
   newptr -> prom_student = prom/2;
   newptr ->nextptr = *topptr;
   *topptr = newptr;
   }
   else
       printf("%f no insert¢. No hay espacio en memoria.\n",cod);
	}

int pop(STACKNODEPTR *topptr)
{
if(*topptr != NULL){

    STACKNODEPTR tempptr;
    float popvalue;

tempptr = * topptr;
popvalue = (*topptr)->codigo;
*topptr = (*topptr)->nextptr;
free(tempptr);
return popvalue;
}
 return 0 ;
 }
void printstack(STACKNODEPTR currentptr)
{
if(currentptr == NULL){
    printf("La pila esta vacia...\n\n");
    }
    else{
    printf("La pila es:  \n");
	       printf("Codigo       Nombre Apellido                     nota 1   nota 2  definitiva\n\n");

	 while(currentptr != NULL){

	       printf("%-7.0f     %-20s                   %.2f      %.2f       %.2f  \n",currentptr ->codigo,currentptr ->nombre,currentptr ->nota1,currentptr ->nota2,currentptr ->prom_student);
	       currentptr = currentptr ->nextptr;
	       }
	      }
	 }

	  int pila_vacia(STACKNODEPTR topptr)
	  {
	  return topptr == NULL;
	  }

