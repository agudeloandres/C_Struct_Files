// EXPENSE1.CPP VERSION ESTRUCTURADA DEL PROGRAMA DE GASTOS DE VIAJES

#include <stdio.h>
#include <string.h>
#include <conio.h>

struct ExpenseRec {  //Estructura de gastos de viaje
 char TripName[80],Date[80];
 int Mileage,Cost,Fringe;
};

void CheckWithBoss(struct ExpenseRec ExRec){
 //El jefe es muy estricto no aprueba todos los viajes
 if (!stricmp(ExRec.TripName,"Ixtapa") || !stricmp(ExRec.TripName,"Cancun"))
   printf("%s : Esta despedido por pasarse de listo \n",ExRec.TripName);
 else if (ExRec.Cost/4 < ExRec.Fringe)
  printf("Los gastos de Entretenimiento %s estan muy altos\n",ExRec.TripName);
 else printf("Viaje %s aprobado\n",ExRec.TripName);
}

int I,ExCount;
struct ExpenseRec ExRec [20];  //Registros de los empleados

  main (){

  clrscr();

  printf("Cuantos Viajes hizo ?:  ");
  scanf("%d",&ExCount);
  for (I=0;I<ExCount;I++){
   printf ("Introduzca nombre de su viaje : ");
   scanf("%s",ExRec[I].TripName);
   printf("Digite fecha de partida (mm/dd/aa) ? : ");
   scanf("%s",ExRec[I].Date);
   printf("Introduzca  cantidad de millas del viaje : ");
   scanf("%d",&ExRec[I].Mileage);
   printf("Introduzca costo del viaje : ");
   scanf("%d",&ExRec[I].Cost);
   printf("Introduzca costo de comidas y entretenimiento : ");
   scanf("%d",&ExRec[I].Fringe);
  }
  for (I=0;I<ExCount;I++) CheckWithBoss(ExRec[I]);
  getch();
  return 0;
  }




