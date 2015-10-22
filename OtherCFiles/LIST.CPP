#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// definicion del registro base dotos

 struct listnode {
	       float codigo ;
	       char  data;
	       struct listnode *nextptr;
	    };
typedef struct listnode LISTNODE;
typedef LISTNODE *LISTNODEPTR;


void insert(LISTNODEPTR *,char);
char delette(LISTNODEPTR *,char);
void condic(LISTNODEPTR);
void printlist(LISTNODEPTR);
void intruccion(void);


main()
{
LISTNODEPTR startptr = NULL;
int op;
char item;
clrscr();
intruccion();
printf("?");
scanf("%d",&op);
 while(op != 3){
       switch(op){

	    case 1:
		  printf("enter cantidad de estudiantes");
		  scanf("\n%c",&item);
		  insert(&startptr,item);
		  printlist(startptr);
		  break;
	    case 2:
		 if(!condic(startptr))
		 {
		    printf("enter codigo a borrar:");
		    scanf("\n%c",&item);

		 if(delette(&startptr,item));
		    printf("%c borrado.\n",item);
		    printlist(startptr);
		   }
		   else
			printf("%c codigo no existe:",item);

		   else
			printf("%c lista llena:",item);

			break;

		     default:
			   printf("invalidada opcion");
			   intruccion();
			   break;
			   }
		  printf("?");
		  scanf("%d",&op);
		}
		  printf("end of run\n");
		  }


// intrucciones de entrada

     void intruccion(void)
     {
     printf("enter your option ? \n"
     "  1 to insert node \n"
     "  2 to delete node \n"
     "  3 to end\n");
     }

int insert(LISTNODEPTR *sptr,int value)
{
LISTNODEPTR newptr, previousptr,currentptr;
newptr =malloc(sizeof(LISTNODEPTR));
if(newptr != NULL){
newptr->codigo = value;
newptr->nextptr = NULL;

previousptr = NULL;
currentptr = *sptr;

while(currentptr != NULL && value > currentptr->codigo){
previousptr = currentptr ;
currentptr = currentptr->nextptr;
}
if(previousptr == NULL){
   newptr->nextptr = *sptr;
   *sptr = newptr;
   }
   else{
      previousptr->nextptr = newptr;
      newptr->nextptr = currentptr;
      }
   }
   else{
   printf(" %d not inserted.no memory available.\n",value);
   }
return 0;
}

// fun borrar

/*int delette(BASE_DATOPTR *sptr,int value)
{
BASE_DATOPTR newptr, previousptr,tempptr;
*/
