#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
			     //CREACION DE UN ARCHIVO SECUENCIAL
main () {
 int account;
 char name[30];
 float balance;
 FILE *cfPtr;   //   cfPtr=clients.dat file pointer

 clrscr();
 if ((cfPtr = fopen ("clients.dat","w")) == NULL)
    printf("File could not be opened \n");
 else {
    printf("enter the account , name , and balance\n");
    printf("enter EOF to end input \n");
    printf("?");
    scanf("%d%s%f",&account,name,&balance);

    while (!feof(stdin)) {
      fprintf(cfPtr,"%d %s %.2f\n", account,name,balance);
      printf("?");
      scanf("%d%s%f",&account,name,&balance);
    }
    fclose(cfPtr);
 }
 return 0;
}