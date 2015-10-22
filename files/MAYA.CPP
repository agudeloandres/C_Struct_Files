# include <stdio.h>
# include <conio.h>

main()

{
int x,y;
clrscr();
textcolor(10);
for (x=1;x<=79;x++){
 for (y=1;y<=25;y++){
 gotoxy(x,y);printf("Å");
}
}
getch();
for (x=1;x<=79;x++){
 for (y=1;y<=25;y++){
 gotoxy(y,x);printf(" ");
}
}
getch();

}


