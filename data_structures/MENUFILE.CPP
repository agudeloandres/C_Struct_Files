#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct clientData {
  int acctNum;
  char lastName[15];
  char firstName[10];
  float balance;
  };

 //******* Prototipos de Funciones ********//

 void enterChoice (void);
 void textFile (FILE *);
 void updateRecord(FILE *);
 void newRecord(FILE *);
 void deleteRecord(FILE *);

main (){
 FILE *cfPtr;
 int choice;

 clrscr();
 if ((cfPtr=fopen("credit.dat","r+")) == NULL)
    printf("file could not be opened \n");
 else{
    enterChoice();
    scanf("%d",&choice);

   while (choice != 5){

       switch (choice) {
	  case 1:
		textFile(cfPtr);
		break;
	  case 2:
		updateRecord (cfPtr);
		break;
	  case 3:
		newRecord(cfPtr);
		break;
	  case 4:
		deleteRecord(cfPtr);
		break;

       }
   }

 }
 fclose(cfPtr);
 return 0;
getch();
}

//********** FUNTIONS ************//

void textFile (FILE *readPtr) {
 FILE *writePtr;
 struct clientData client;

  if ((writePtr = fopen ("accounts.txt","w"))==NULL)
     printf("file could not be opened\n");
  else {
     rewind (readPtr);
     fprintf(writePtr,"%-6s%-16s%-11s%10s\n",
	     "Acct",  "last Name",  "first Name",  "balance");

     while (!feof(readPtr)) {
       fread(&client,sizeof (struct clientData),1,readPtr);

	if (client.acctNum !=0)
	  fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",client.acctNum,
		   client.lastName,client.firstName,client.balance);
     }
  }
  fclose(writePtr);
}
//-------------------------------------------------------------------

void updateRecord(FILE *fPtr) {
 int account;
 float transaction;
 struct clientData client;

 printf("enter account to update (1-100) : ");
 scanf("%d",&account);
 fseek(fPtr,(account-1) * sizeof(struct clientData),SEEK_SET);
 fread(&client,sizeof(struct clientData),1,fPtr);

 if (client.acctNum ==0)
    printf("account #%d has no information \n",account);
 else {
    printf("%-6d%-16s%-11s%10.2f\n\n",client.acctNum,client.lastName,
	    client.firstName,client.balance);
    printf("enter charge (+) or payment (-) : ");
    scanf("%f",&transaction);
    client.balance += transaction;
    printf("%-6d%-16s%-11s%10.2f\n\n",client.acctNum,client.lastName,
	    client.firstName,client.balance);
    fseek(fPtr,(account-1) * sizeof (struct clientData),SEEK_SET);
    fwrite(&client,sizeof (struct clientData),1,fPtr);
 }
}
//--------------------------------------------------------------------

void deleteRecord(FILE *fPtr) {
  struct clientData client, blankClient = {0,  "",  "",  0};
  int accountNum;

  printf("enter account number to delete (1-100): ");
  scanf("%d",&accountNum);
  fseek(fPtr,(accountNum-1) * sizeof (struct clientData),SEEK_SET);
  fread(&client,sizeof(struct clientData),1,fPtr);

  if (client.acctNum ==0)
    printf("account %d does not exist \n",accountNum);
  else {
    fseek(fPtr,(accountNum-1) * sizeof (struct clientData),SEEK_SET);
    fwrite(&blankClient,sizeof (struct clientData),1,fPtr);
  }
}
//-----------------------------------------------------------------------

void newRecord(FILE *fPtr){
 struct clientData client;
 int accountNum;
 printf("enter new account number (1-100) : ");
 scanf("%d",&accountNum);
 fseek(fPtr,(accountNum-1) * sizeof (struct clientData),SEEK_SET);
 fread(&client,sizeof(struct clientData),1,fPtr);

 if(client.acctNum != 0)
   printf("account #%d already contains information \n",client.acctNum);
 else {
   printf("enter last name, first name, balance \n ?");
   scanf("%s%s%f",&client.lastName,&client.firstName,&client.balance);
   client.acctNum = accountNum;
   fseek(fPtr,(client.acctNum -1) * sizeof (struct clientData),SEEK_SET);
   fwrite(&client,sizeof(struct clientData),1,fPtr);
 }
}
//-----------------------------------------------------------
void enterChoice(void) {

  printf("enter choice :\n"
	 "   1. to see text file\n"
	 "   2. to update Record \n"
	 "   3. to create a new Record \n"
	 "   4. to delete a Record \n");

    return ;
}