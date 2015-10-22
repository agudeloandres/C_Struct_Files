// EXPENSE2.CPP VERSION ORIENTADA A OBJETOS DEL PROGRAMA DE GASTOS DE VIAJES
//EXPENSE1.CPP

#include <stdio.h>
#include <string.h>
#include <conio.h>

class Expense {    //El tipo de objeto de gastos de viaje
 public:
 char TripName[80],Date[80];
 int Mileage,Cost,Fringe;
 void AskQuestions(void);
 void CheckWithBoss(void);

};



void Expense::AskQuestions(void){
//Esta funcion recopila datos para el objeto Expense
   printf ("Introduzca nombre de su viaje : ");
   scanf("%s",TripName);
   printf("Digite fecha de partida (mm/dd/aa) ? : ");
   scanf("%s",Date);
   printf("Introduzca  cantidad de millas del viaje : ");
   scanf("%d",&Mileage);
   printf("Introduzca costo del viaje : ");
   scanf("%d",&Cost);
   printf("Introduzca costo de comidas y entretenimiento : ");
   scanf("%d",&Fringe);
}

void Expense::CheckWithBoss(void){
//El jefe es muy estricto. No aprueba todos los viajes
if (!stricmp(TripName,"Ixtapa") || !stricmp(TripName,"Cancun"))
   printf("%s : Esta despedido por pasarse de listo \n",TripName);
 else if (Cost/4 < Fringe)
  printf("Los gastos de Entretenimiento %s estan muy altos\n",TripName);
 else printf("Viaje %s aprobado\n",TripName);
}

Expense ExRec[20];
int ExCount,I;

int main (int, char *){
 clrscr();
 printf ("Cuantos viajes hizo ud ? : ");
 scanf ("%d",&ExCount);
  for (I=0;I<ExCount;I++)  //datos de gasto para cada empleado
   ExRec[I].AskQuestions();
   for (I=0;I<ExCount;I++)  //Escriba la respuesta del jefe
   ExRec[I].CheckWithBoss();
   getch();
   return 0;
   }

