#include<stdio.h>
#include<conio.h>

int longstr(char *);       //FUNCION LONGSTR QUE DEVUELVE LA LONGITUD DE UNA
			   //CADENA DE CARACTERES

void main(){
clrscr();
static char *cadena = NULL;  //el caracter '/0' es a¤adido automaticamente
printf("Digite una cadena de caracteres : \n");
scanf("%s",cadena);
printf ("\n\tsu longitud es : %d\n",longstr(cadena));
getch();
}


//Funcion
int longstr(char *str){
 char *p;
 p=str;                //p apunta al primer caracter

 while(*p != '\0')
 p++;                    //p apunta al siguiente caracter
 return ((int)(p-str));
}