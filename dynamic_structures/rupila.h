//Archivo rupila.h que contiene las rutinas para el manejo de pila

void marco (void){      //MARCO
int q,q2,q3,q4;
clrscr();
gotoxy(0,0);
printf("É");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("Í");
}
gotoxy(79,0);
printf("»");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("º");
}
gotoxy(80,24);
printf("¼");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("Í");}

gotoxy(1,24);
printf("È");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("º");}
return;
}
//******************************

//Definicion de los nodos de la pila;
typedef struct stack{
	float S;
    };

//funcion que halla la direccion maxima que se puede acceder en memoria
stack *Maximo(stack *Base, int n)
{
  stack *Max;
  int i;
  Max=Base;
  for(i=1;i<=n;i++){
      Max++;
 }
 return Max;

 }
 //funcion para definir una pila
 void crear_pila(stack **Base, stack **Tope, int n)
 {
  stack *Avail;
  //asignacion del espacio disponible
  Avail=new stack[n];
  //asignacion de condiciones iniciales
  *Base=Avail;
  *Tope=Avail;
  }
  //Funcion Push para insertar un nodo en una pila

  void Push(stack **Tope, stack *Max, float Inf)
  {
   char op;
   (*Tope)++;
   if (*Tope>Max){
      clrscr();
      (*Tope)--;
      marco();
      gotoxy(25,12);printf("PILA LLENA....!!! OVERFLOW..!!");
      getch();
      }
      else{
       (*Tope)->S=Inf;
       }
       return;
       }
       //Funcion Pop para cancelar o remover un nodo de una pila
       void Pop(stack **Tope, stack *Base, float *Inf)
       {
	char op;
	//(*Tope)--;
	if(*Tope<Base){
	  marco();
	  //(*Tope)++;
	  gotoxy(25,12);printf("PILA VACIA...!! UNDERFLOW..!!");
	  getch();

	  }
	  else{
	      (*Inf)=(*Tope)->S;
	      (*Tope)--;
	     }
	     return;
	     }
	     //Funcion que escribe los elementos de la pila
	     void escribir_pila(stack *Base,stack **Tope,stack *Max,int n)
	     {
	      char op;
	      int y=3;
	      stack *Base1,*Tope1,*Max1,*Top=NULL;
	      float Inf;
	      Top=*Tope;
	      //crear nueva pila para sacar elementos y guardar
	      crear_pila(&Base1,&Tope1,n);
	      Max1=Maximo(Base1,n);
	      //impresion de la pila usando Pop y Push (stack Top)

	      while(Base!=Top){
		Pop(&Top,Base,&Inf);
	       *Tope=Top;
		gotoxy(5,y);
		printf(" %1.1f   ",Inf);
		printf("Dir = %04x:%04x",FP_SEG(Top+1),FP_OFF(Top+1));
		Push(&Tope1,Max1,Inf);
	      y++;

	      }
	      //Recuperacion de la Pila
	      while(Base1!=Tope1){
		Pop(&Tope1,Base1,&Inf);
		Push(&Top,Max,Inf);
		*Tope=Top;
		}
		}

//*******************************

void menu()     //CUADRO DEL MENU
{
 clrscr();
     int k,y,p;

     gotoxy(20,1); printf("É\n");
     gotoxy(60,1);printf("»\n");
     gotoxy(20,3);printf("È\n");
     gotoxy(60,3);printf("¼\n");
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");

//CUADRITO DONDE ESTA EL TITULO

    for (k=21; k<= 59; k ++){
   gotoxy (k,y);
   gotoxy(21,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy (20,2);printf("º\n");
   gotoxy (60,2);printf("º\n");

    }


   for (p=6; p<=20; p++)
  {
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");
     gotoxy (15,p);printf("º\n");
     gotoxy (65,p);printf("º\n");
     }
      for (p=16; p<=64; p++)
  {
     gotoxy(p,6);printf("Í\n");
     gotoxy (p,21);printf("Í\n");

    }
return;
}
