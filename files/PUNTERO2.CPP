#include<stdio.h>
#include<conio.h>      //Funcion para copiar una cadena en otra

void main(){
 char cadena1[81], cadena2[81], cadena3[81];
 void copstr(char *,char *);
 void copstr2(char * , char *);

 clrscr();
 printf("Introducir cadena : ");
 gets(cadena1);
 copstr(cadena2,cadena1);  //Copia la cadena1 en la cadena2
 copstr2(cadena3,cadena1);
 printf("la cadena copiada es : %s\n",cadena2);  //Array
 printf("la cadena copiada es : %s\n",cadena3);  //Apuntadores

 getch();
}


//Version Array
void copstr(char *p, char *q){      //copia q en p
int i=0;
 while ((p[i] = q[i]) != '\0')
 i++;
}


//Version Apuntadores
void copstr2(char *p , char *q){   //copia q en p
 while ((*p = *q) != '\0'){
  p++;
  q++;
 }
}