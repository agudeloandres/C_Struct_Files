     /* CONVERTING LOWERCASE LETTERS TO UPPERCASE LETTERS
	USING A NON-CONSTANT POINTER TO NON-CONSTANT DATA */

#include <stdio.h>
#include <conio.h>

 void ConvertToUppercase(char *); //Prototype
void main () {
  char string [30] = "carlos andres";
  clrscr();
  highvideo();
  printf("the string before conversion is : %s\n",string);
  ConvertToUppercase(string);
  printf("the string after conversion is : %s\n",string);
  getch();
  return;

}

/**** Funtion*****/

void ConvertToUppercase(char * s) {
  while (*s != '\0') {
   if (*s >= 'a' && *s <= 'z')
     *s -= 32;   /*  Convert to ASCII uppercase letter */

      ++s;   /* increment s to point to the next character */
    }
}