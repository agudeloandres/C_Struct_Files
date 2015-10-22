// EXPENSE3.CPP VERSION ORIENTADA A OBJETOS DEL PROGRAMA DE GASTOS DE VIAJES
//EXPENSE2.CPP QUE UTILIZA LA HERENCIA PARA MANIPULAR A LOS EJECUTIVOS DE
// MANERA DIFERENTE.


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


class Expense {    //El tipo de objeto de gastos de viaje
 public:
 char TripName[80],Date[80];
 int Mileage,Cost,Fringe;
 virtual void AskQuestions(void);    //Utilice virtual porque las
 virtual void CheckWithBoss(void);   //omitiremos en ExecutiveExp
};

class ExecutiveExp : public Expense{
 public:
  int Rating;
  virtual void AskQuestions(void);   //La palabra clave virtual
  virtual void CheckWithBoss(void);  //opcional aqui
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

void ExecutiveExp::AskQuestions(void){
 //esta funcion recopila datos del objeto gastos de ejecutivos

 Expense::AskQuestions();  //llame a la version heredada
 printf("Como califica el viaje ? (0-10) : ");
 scanf("%d",&Rating);
}

void ExecutiveExp::CheckWithBoss(void){
 //el jefe acepta mas de los ejecutivos

 if (Cost/2 < Fringe)printf("Cuidado. No se esta divirtiendo mucho !");
 }

 Expense *ExRec[20];   //arreglo de punteros al tipo clase base
 int ExCount,I;
 unsigned char Executive;  //verdadero si es un ejecutivo

 int main (int, char *){

  //Determine si el usuario es un ejecutivo o no. Si es use la clase
 //ExecutiveExp.
 clrscr();
 printf("Es ud ejecutivo (y/n) : ");
 if (toupper(getche())=='Y') Executive=1; else Executive=0;
 printf("\nCuantos viajes hizo ud.? : ");
 scanf("%d",&ExCount);

  //Asigne suficientes objetos del tipo apropiado para el numero de
 // viajes hechos. Que objetos se incluyen en el arreglo depende de si
//el usuario es un ejecutivo o no.

for(I=0;I<ExCount;I++)
 if (Executive)
   ExRec[I]=new ExecutiveExp;
 else
   ExRec[I]=new Expense;

 //Las siguientes son llamadas polimorficas. Utilice la misma llamada
 //para hacer referencia a los objetos

 for (I=0;I<ExCount;I++)  //Datos de gasto para cada objeto
  ExRec[I]->AskQuestions();

  for (I=0;I<ExCount;I++)  //Escriba la respuesta del jefe
    ExRec[I]->CheckWithBoss();

  getch();
  return 0;

 }







