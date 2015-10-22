/* Raúl Salinas Maciel.
Mat. 662195      Queue (Array Aplication) */
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
//***************************************************************

#include <iostream.h>
#include <conio.h>
#include <fstream.h>

#define MAX 5

enum code {TRUE= 1, FALSE= 0};

ofstream arch("c:\data.txt"); /* Initialice the output archive */

class Aqueue{
 private:
      int Q[MAX], *head, *tail;
      int *move(int *tmp);
 public:
      void init();
      code IsEmpty();
      code IsFull();
      code EnQueue(int x);
      code DeQueue();
      void Print();
};

// Initilize the queue.
void Aqueue::init(){
 int i;

 for (i=0; i<=MAX-2; i++)
  Q[i]= -32000;
 Q[MAX-1]= 32000;
 head=tail=Q;
}

// Move a pointer to the next position.
int *Aqueue::move(int *tmp){
  if(*tmp == Q[MAX-1]) return Q;
  else return tmp+1;
}

// Returns True if the queue is empty.
code Aqueue::IsEmpty(){
 if (head==tail) return TRUE;
 else return FALSE;
}

// Returns True if the queue is full.
code Aqueue::IsFull(){
 int *tmp=tail;
 if (move(tmp)==head) return TRUE;
 else return FALSE;
}

// Add a new element to the queue.
code Aqueue::EnQueue(int x){
 if (IsFull()){
  cout << "\n\t\tQueue Overflow!!!";
  arch << "\n\t\tQueue Overflow!!!";
  return FALSE;
 }
 else{
  *tail= x;
  tail= move(tail);
  return TRUE;
 }
}

// Delete one element form the queue.
code Aqueue::DeQueue(){
 if (IsEmpty()){
  cout << "\n\t\tQueue Underflow!!!";
  arch << "\n\t\tQueue Underflow!!!";
  return FALSE;
 }
 else{
  head= move(head);
  return TRUE;
 }
}

// Print the contain of the queue.
void Aqueue::Print(){
 int *aux=head;

 cout << "\n{ ";
 arch << "\n{ ";
 if (!IsEmpty()){
  while (aux != tail){
   cout << *aux << " ";
   arch << *aux << " ";
   aux= move(aux);
  }
 }
 cout << "}";
 arch << "}";
}

/* Principal */
void main(){
 Aqueue Queue;
 char cer;
 int ele;

 Queue.init();
 do{
  clrscr();
  cout << "\n\t\t\tQUEUE (Array implementation)";
  arch << "\n\t\t\tQUEUE (Array implementation)";
  cout << "\n\nQueue:\n";
  arch << "\n\nQueue:\n";
  Queue.Print();
  cout << "\n\t1. Insert new element...";
  arch << "\n\t1. Insert new element...";
  cout << "\n\t2. Delete element...";
  arch << "\n\t2. Delete element...";
  cout << "\n\t3. Salir...";
  arch << "\n\t3. Salir...";
  cout << "\n\t\tOption...";
  arch << "\n\t\tOption...";
  cin >> cer;
  arch << cer;
  switch (cer){
    case '1':{       // Case to call EnQueue.
     cout << "\n\nElement to insert (integer): ";
     arch << "\n\nElement to insert (integer): ";
     cin >> ele;
     arch << ele;
     if (Queue.EnQueue(ele) != FALSE)
       Queue.Print();
     getch();
     break;
    }
    case '2':{ 	       // Case to call DeQueue.
     if (Queue.DeQueue() != FALSE)
       Queue.Print();
     getch();
     break;
    }
  }
 } while (cer != '3');
}