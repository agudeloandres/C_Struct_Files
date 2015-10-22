#include <stdio.h>
#include <conio.h>
struct card {
char * face ;
char * suit;
};
main ()
{
clrscr();
struct card a;
struct card * aptr;
a.face= "hola";
a.suit="mundo";
aptr=&a;
printf("%s %s\n%s %s\n",a.face,a.suit,aptr->face,aptr->suit);
printf("%s %s\n",(*aptr).face,(*aptr).suit);
getch();
}