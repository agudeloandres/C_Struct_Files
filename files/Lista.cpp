//***************************************************************
//			Raúl Salinas Maciel
//			*
//                            662195
//				*
//								*
//***************************************************************
//  El programa es de uso público, pero necesito dinero... 	*
//		PLEASE, SEND ME A DOLLAR!!!          		*
//								*
//		Manzana M-7, edif f4, depto. 4			*
//		Col. Villas de San Juan.			*
//		Guadalajara, Jalisco, México			*
//		CP. 44290					*
//								*
// e-mail: al662195@campus.gda.itesm.mx				*
// http://www.gda.itesm.mx/~al662195				*
//***********************************************************************
// Este programa realiza operaciones con una lista. Las operaciones se
//  *
// indican en la clase.
//						*
//			-. A LIST IMPLEMENTATION .-			*
//***********************************************************************

#include <iostream.h>
#include <conio.h>
#include <fstream.h>

typedef int element;   // Definición del un tipo de dato.

enum code {ERROR = 0, OK = 1}; // Tipo de dato enumerado.

struct node{           	       // Estructura de cada elemento de la lista.
	element info;  
	struct node *link;};

class list{                    // Lista es un objeto que contiene todas las
   private:		       // las operaciones que se realizan con la lista.
	struct node *cab,*list2;

   public:
	list(){ cab= NULL; list2= NULL;}
		    // Constructor. Inicializa la lista en NULL.
	code head(element& e);  // Regresa un código de error y el valor
			        //  del ele.
	void tail();	        // Elimina el último elemento de la lista.
	int length();	        // Regresa el tamaño de la lista.
	void insert(struct node *tmp,element e); // Inserta un elemento, or-
        				// denándolo.
	void remove(element e); // Elimina el elemento que se le asigne de
        			//  la lista. Si este existe.
	code member(element e); // Regresa un código de error si el elemen-
        			//   to existe dentro de la lista.
	void print(struct node *tmp);		// Imprime el contenido de la lista.
	void copy(struct node *tmp,struct node *ant);
	void concat(struct node *lista1,struct node *lista2);
	struct node *rpoint();
	void showlist(struct node *l1,struct node *l2,
		struct node *cop, struct node *con);
   };

// (Código) Modifica el valor del elemento asignado, regresando
//   el valor del 1er. elemento de la lista.

code list::head(element& e){
  if (cab->link == NULL) return ERROR;
  else { e= cab->link->info;
	 return OK;
	};
};

// (Código) Regresa un código de error si el elmento asignado no pertenece a
//   la lista.
code list::member(element e){
   struct node *temp=cab;
   code flag=ERROR;

   while (temp->link != NULL){
	if (temp->link->info == e){
	  flag= OK;
	  break;}
	else temp= temp->link;
   }
	return flag;
}

// (Código) Agrega un nuevo elemento a la lista, colocandolo en el lugar
//    que le corresponde, ordenadamente. El procedimiento se realiza en
//    forma recursiva.
void list::insert(struct node *tmp, element e){
 struct node *aux= new(struct node);

 if (tmp->link == NULL){
    aux->info= e;
    aux->link= NULL;
    tmp->link= aux;}
 else{
    if (tmp->link->info < e) insert(tmp->link,e);
    else {
	aux->info= e;
	aux->link= tmp->link;
	tmp->link= aux;}
    }
}

// (Código) Borra el elemento que se le asiogna de la lista. Eñ procedi-
//    miento, se ayuda de "member".
void list::remove(element e){
 struct node *temp=cab, *aux;

 if (member(e) == OK){
    while((temp->link != NULL) && (temp->link->info != e))
	temp= temp->link;
    if (temp->link != NULL){
	aux= temp->link;
    	temp->link= aux->link;
	delete(aux);}
 }
 else {
	cout<<"\nElemento no encontrado en lista...";
 }
}


// (Código). Calcula al dimensión de la lista. 
int list::length(){
   int cont=0;
   struct node *tmp=cab;

   while (tmp->link != NULL){
	tmp= tmp->link;
	cont++;}
   return cont;
}

// (Código). Borra el úlimo elemento de la lista. 
void list::tail(){
  struct node *tmp= cab, *aux;

  if (tmp->link != NULL){
    while(tmp->link->link != NULL) tmp= tmp->link;
    aux= tmp->link;
    tmp->link= aux->link;
    delete(aux);
  }
}         
    
// (Código). Imprime en pantalla el contenido de la lista.
void list::print(struct node *tmp){

  cout << "\n--";
  while (tmp->link != NULL){
	cout << tmp->link->info << "--";
	tmp= tmp->link;}
  cout << "NULL";
}

void list::copy(struct node *tmp,struct node *ant){
 struct node *aux= new(struct node);

  if (tmp->link != NULL){
    aux->info= tmp->link->info;
    aux->link= NULL;
    ant->link= aux;
    copy(tmp->link,ant->link);
 }
}

void list::concat(struct node *lista1, struct node *lista2){
  element e;

  while (lista2->link != NULL){
    e= lista2->link->info;
    insert(lista1,e);
    lista2= lista2->link;
  }
}

struct node *list::rpoint(){
 return cab; }

void list::showlist(struct node *l1, struct node *l2, struct node *cop, struct node *con){
struct node *tmp;

 cout << "\n\tContenido de las listas...";
 tmp= l1;
 cout << "\nLista 1:";
 while (tmp->link != NULL){
  cout << tmp->link->info << "--";
  tmp= tmp->link;
 }
 cout << "NULL";
 tmp= l2;
 cout << "\nLista 2:";
 while (tmp->link != NULL){
  cout << tmp->link->info << "--";
  tmp= tmp->link;
 }
 cout << "NULL";
 tmp= cop;
 cout << "\nCopia:";
 while (tmp->link != NULL){
  cout << tmp->link->info << "--";
  tmp= tmp->link;
 }
 cout << "NULL";
 tmp= con;
 cout << "\nConCat:";
 while (tmp->link != NULL){
  cout << tmp->link->info << "--";
  tmp= tmp->link;
 }
 cout << "NULL";
}

// ***PRINCIPAL***
void main()
{
 char cer;
 element ele;	      // Variable donde se asignarán los valores.
 list list1,list2;          // Objeto del tipo list.
 struct node *copia,*lista1= NULL, *lista2, *concat=NULL,*aux;

 copia= new(struct node);
 copia->link= NULL;
 concat= new(struct node);
 concat->link= NULL;
 lista2= new(struct node);
 lista2->link= NULL;
 do{              // Ciclo de repetición de opciones.
    clrscr();
    cout << "\t\t\tManejo de listas";
    cout << "\n\n\t[I]nsertar elemento...";
    cout << "\n\t[B]orrar elemento...";
    cout << "\n\t[L]ongitud de la lista...";
    cout << "\n\t[T]ail...";
    cout << "\n\t[H]ead...";
    cout << "\n\t[D]etectar...";
    cout << "\n\tAne[X]ar a otra lista...";
    cout << "\n\tC[O]piar lista...";
    cout << "\n\tConC[A]tenar listas...";
    cout << "\n\t[S]alir...";
    cout << "\n\t\tOpcion: ";
    cin >> cer;
    switch (cer) {
	case 'I','i': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		cout << "\nElemento a insertar: ";
		cin >> ele;
		list1.insert(lista1,ele);
		list1.print(lista1);
		getch();
		break;
		}
	case 'B','b': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		cout << "\nElemento a borrar: ";
		cin >> ele;
		list1.remove(ele);
		list1.print(lista1);
		getch();
		break;
		}
	case 'L','l': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		cout << "\nLongitud de la lista: " << list1.length()
			<< " elementos.";
		getch();
		break;
		}
	case 'T','t': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		list1.tail();
		cout << "\n";
		list1.print(lista1);
		getch();
		break;
		}
	case 'H','h': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		if (list1.head(ele) == OK){
			cout << "\nHead: " << ele;
		getch();
		break;
		}
		}
	case 'D','d': {
		clrscr();
		cout << "Elemento a detectar: ";
		cin >> ele;
		if (list1.member(ele) == OK){
			cout <<"\nEl elemento existe...";
			cout << "\nlista1:";
			list1.print(lista1);
			}
		else{ cout << "\nEl elemento NO existe...";
		getch();
		break;
		}
                }
	case 'X','x': {
        	clrscr();
		cout << "\nlista2:";
		list1.print(lista2);
		cout << "\nElemento a insertar: ";
		cin >> ele;
		list1.insert(lista2,ele);
		cout << "\nlista2:";
                list1.print(lista2);
		getch();
                break;
		}
	case 'O','o': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
 		list1.copy(lista1,copia);
		cout << "\nLista copiada...";
		list1.showlist(lista1,lista2,copia,concat);
		getch();
		break;
		}
	case 'A','a': {
		clrscr();
		cout << "\nlista1:";
		list1.print(lista1);
		cout << "\nlista2:";
		list1.print(lista2);
		list1.copy(lista1,concat);
		list1.concat(concat,lista2);
                list1.showlist(lista1,lista2,copia,concat);
		getch();
		break;
                }
	case 'S','s': {
		clrscr();
		break;
		}
 }
 }while((cer != 's') && (cer != 'S'));
}



