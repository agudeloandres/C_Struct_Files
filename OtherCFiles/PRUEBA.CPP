
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
// estruct de la pila
  struct stackNode{
	 float codigo;
	 char nombre[30];
	 float nota1;
	 float nota2;
	 float prom_student;
	 struct stackNode *Link;
	 };

  typedef struct stackNode STACK;
  typedef  STACK *pila;
  void push(pila *, float, char*, float, float,int,float);
  void buscar(pila );
  void Eliminar(pila);
  int pop(pila *);
  int pila_vacia(pila);
  void printstack(pila);
  int instructions(void);

main ()
{
int sw,lon;

pila stackptr = NULL;
int  choice,est,i,cdel,k,y,p;
char name[30];
float not1,not2,prom,cod;
clrscr();
while((choice = instructions()) != 6 ){
     switch(choice){

	  case 1:
		clrscr();
		gotoxy(10,10);
		printf("Entre cantidad de estudiantes...   ");
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
		    gotoxy(25,22);
		    printf("presione  <<enter>> ");
		    getch();
	      }
		else{
		    gotoxy(25,22);
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
	       buscar(stackptr);


	       }
		  else{
		      gotoxy(25,22);
		      printf("La pila esta vacia...\n\n");
		      getch();
	       }


		break;
		case 5:
		      if(! pila_vacia(stackptr)){
		      Eliminar(stackptr);
		      }
		      else{
		      gotoxy(25,22);
		      printf("La pila esta vacia...\n\n");
		      getch();
	       }    
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
textbackground(1);
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
printf(" 1  Nuevo  Nodo \n");
gotoxy(20,10);
printf(" 2  Borrar Nodo (Ultimo)\n");
gotoxy(20,12);
printf(" 3  Listar Pila \n");
gotoxy(20,14);
printf(" 4  Consultar (por codigo)\n");
gotoxy(20,16);
printf(" 5  Eliminar Nodo(por codigo)\n");
gotoxy(20,18);

printf(" 6  Fin proceso\n");
gotoxy(20,20);
printf("enter option [ ]");
gotoxy(34,20);
gets(c);
op = atoi(c);
return op;
}

void push(pila *base,float cod,char *name,float not1,float not2,int lon,float prom)
{
int j;
pila newptr;

newptr = new(STACK);


if(newptr != NULL){
   newptr -> codigo = cod;
   lon = strlen(name);
   for(j=0;j<=lon;j++){
      newptr->nombre[j]=name[j];
     }
   newptr -> nota1 = not1;
   newptr -> nota2 = not2;
   newptr -> prom_student = prom/2;
   newptr ->Link = *base;
   *base = newptr;
   }
   else
       printf("%f no insert¢. No hay espacio en memoria.\n",cod);
	}

int pop(pila *base)
{
if(*base != NULL){

    pila tempptr;
    float popvalue;

tempptr = *base;
popvalue = (*base)->codigo;
*base = (*base)->Link;
free(tempptr);
return popvalue;
}
 return 0 ;
 }
void printstack(pila currentptr)
{
if(currentptr == NULL){
    printf("La pila esta vacia...\n\n");
    }
    else{
    printf("La pila es:  \n");
	       printf("Codigo       Nombre Apellido                     nota 1   nota 2  definitiva\n\n");

	 while(currentptr != NULL){

	       printf("%-7.0f     %-20s                   %.2f      %.2f       %.2f  \n",currentptr ->codigo,currentptr ->nombre,currentptr ->nota1,currentptr ->nota2,currentptr ->prom_student);
	       currentptr = currentptr ->Link;
	       }
	      }
	 }

	  int pila_vacia(pila topptr)
	  {
	  return topptr == NULL;
	  }

void buscar(pila newptr )
{
pila newr;
int sw=0;
float eli;
float cod;
clrscr();
		gotoxy(15,10);
		printf(" entre codigo a buscar :  ");
		scanf("%f",&cod);
		printf(" \n\n\n");

newr = newptr;

	   while(sw==0 && newr != NULL){
	     if(newr ->codigo == cod ){
		eli = newr ->codigo;
	       printf("Codigo       Nombre Apellido                     nota 1   nota 2  definitiva\n\n");
	       printf("%-7.0f     %-25s            %.2f     %.2f     %.2f \n",eli,newr->nombre,newr->nota1,newr->nota2,newr->prom_student);
		sw=1;
		}
		 newr = newr->Link;



	      }
 getch();
}
void Eliminar(pila newptr )
{
pila newr;
int sw=0;
float eli;
float cod;
clrscr();
		gotoxy(15,10);
		printf(" entre codigo a eliminar :  ");
		scanf("%f",&cod);
		printf(" \n\n\n");

newr = newptr;

	   while(sw==0 && newr != NULL){
	     if(newr ->codigo == cod ){
		eli = newr ->codigo;
		newr->codigo = NULL;
//		newr->nombre =;
		newr->nota1 = NULL;
		newr->nota2 = NULL;
		newr->prom_student = NULL;
	       printf("Codigo       Nombre Apellido                     nota 1   nota 2  definitiva\n\n");
	       printf("%-7.0f     %-25s            %.2f     %.2f     %.2f \n",eli,newr->nombre,newr->nota1,newr->nota2,newr->prom_student);
		sw=1;
		}
		 newr = newr->Link;



	      }
 getch();
}