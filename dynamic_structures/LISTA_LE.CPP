/* OPERATING AND MAINTAINING A LIST */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct listNode {    //self-referential structure
     char data;
     struct listNode *nextPtr;
};

 typedef struct listNode LISTNODE;
 typedef LISTNODE *LISTNODEPTR;   //LISTNODEPTR es un Apuntador a LISTNODE

  //********** PROTOTIPOS DE FUNCIONES ********

  void insert(LISTNODEPTR *, char);
  char del(LISTNODEPTR *, char);
  int isEmpty(LISTNODEPTR);
  void printList(LISTNODEPTR);
  void instructions (void);

  main () {

      LISTNODEPTR startptr = NULL;
      int choice;
      char item;

      clrscr();
      instructions ();   //Display the menu
      printf (" ? ");
      scanf ("%d",&choice);

      while (choice != 3) {

	 switch (choice) {
	   case 1 :
	    printf ("Enter a Character : ");
	    scanf ("\n%c",&item);
	    insert (&startptr,item);
	    printList(startptr);
	    break;

	   case 2:
	     if (!isEmpty(startptr)) {
	      printf ("Enter character to be deleted : ");
	      scanf ("\n%c",&item);

	      if (del (&startptr,item)) {
	       printf("%c deleted \n",item);
	       printList(startptr);
	      }
	      else
		 printf("%c not found \n\n",item);

	     }
	     else
		printf("List is empty \n\n");

	     break;

	   default :
	      printf("Invalid Choice \n\n");
              clrscr();
	      instructions ();
	      break;
	 }
	 printf ("?");
	 scanf ("%d",&choice);
       }
       printf("End of run \n");
       getch();
       return 0;
   }

//********* Funtions ***********


void instructions (void) {		//Print the instructions
  printf ("Enter your choice : \n"
	  "      1 to insert an element into the list \n"
	  "      2 to delete an element from the list \n"
	  "      3 to end \n");
}
// -------------------------------

void insert (LISTNODEPTR *sptr, char value) {  //Insert a new value ordered
  LISTNODEPTR newptr,previousptr,currentptr;
   newptr = (LISTNODEPTR) malloc(sizeof(LISTNODE));
     //CONVERSION CAST (LISTNODEPTR)
    //para que el apuntador que retorne malloc
   //sea del tipo apuntador a LISTNODE

    if (newptr != NULL ) {   // Is space available
      newptr -> data = value;
      newptr -> nextPtr = NULL;

      previousptr= NULL;
      currentptr= *sptr;

      while (currentptr != NULL && value > currentptr-> data){
	previousptr= currentptr;         //walk to .....
	currentptr=currentptr->nextPtr;  //......next node
      }

      if (previousptr==NULL){
       newptr->nextPtr=*sptr;
       *sptr=newptr;
      }
       else {
	 previousptr->nextPtr=newptr;
	 newptr->nextPtr=currentptr;
       }
    }
    else
      printf("%c not inserted. No memory available\n",value);
  }
//-------------------------------------------------------------

char del (LISTNODEPTR *sptr,char value) {   // delete a list element
 LISTNODEPTR previousptr,currentptr,tempptr;
  if (value == (*sptr)->data) {
    tempptr = *sptr;
    *sptr = (*sptr) ->nextPtr;    // de-thread the node
    free (tempptr);               // free the de-thread node
    return value;
  }
   else {
     previousptr = *sptr;
     currentptr = (*sptr)->nextPtr;
     while (currentptr != NULL && currentptr->data != value){
       previousptr= currentptr;         //walk to.......
       currentptr= currentptr->nextPtr;  //.....next node
     }
     if (currentptr != NULL){
       tempptr= currentptr;
       previousptr->nextPtr= currentptr->nextPtr;
       free(tempptr);
       return value;
     }
  }
  return '\0';
}
//-----------------------------------------------------

int isEmpty(LISTNODEPTR sptr) {     //return 1 if itïs empty , 0 otherwise

  return sptr== NULL;
}
//------------------------------------------------------

void printList(LISTNODEPTR currentptr){
  if(currentptr==NULL)
    printf("List is empty \n\n");
  else {
    printf("the list is : \n");
     while (currentptr != NULL ){
       printf("%c  --> ",currentptr->data);
       currentptr = currentptr->nextPtr;
     }
    printf("NULL \n\n");
  }
}


