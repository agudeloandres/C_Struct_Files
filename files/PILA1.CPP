#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

struct stacknode {
int data;
struct stacknode * nextptr;
};
typedef struct stacknode STACKNODE ;
typedef STACKNODE * STACKNODEPTR;
void push (STACKNODE *, int);
int pop (STACKNODEPTR *);
int isempty (STACKNODEPTR);
void printpila (STACKNODEPTR);
main () {
STACKNODEPTR stackptr= NULL;
int choice=0,value;
printf("%s\n%s\n%s\n","entre opcion :","1 para entrar valor pila","2 para sacar valor pila","3 salir");
 while (choice!=3){
 scanf ("%d",&choice);
 switch (choice){
 case 1:
	printf ("teclee un entero\n");
	scanf("%d",&value);
	push(&stackptr,value);
	printpila(stackptr);
	break;

case 2:
       if (!isempty (stackptr))
       printf("el valor es %d \n",pop (&stackptr));
       printpila(stackptr);
       break;
       }
      }
     }


