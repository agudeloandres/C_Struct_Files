#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct clientData {      //COMO ESCRIBIR DATOS DIRECTA/ A UN ARCHIVO DE
 int acctNum;            // ACCESO DIRECTO
 char lastName[15];
 char firstName[10];
 float balance;
};

main () {
  FILE * cfPtr;
  struct clientData client;
   clrscr();
   if ((cfPtr = fopen("credit.dat","r+")) == NULL)
       printf("file could not be opened\n");
   else {
       printf("enter account number"
	      "(1 to 100 , 0 to end input)\n?");
       scanf("%d",&client.acctNum);

       while (client.acctNum != 0) {
	  printf("enter last name , first name , balance\n?");
	  scanf("%s%s%f",&client.lastName,&client.firstName,&client.balance);
	  fseek (cfPtr,(client.acctNum-1) * sizeof(struct clientData),SEEK_SET);
	  fwrite (&client,sizeof(struct clientData),1,cfPtr);
	  printf("enter account number\?");
	  scanf("%d",&client.acctNum);
       }
   }
   fclose(cfPtr);
   return 0;
}
