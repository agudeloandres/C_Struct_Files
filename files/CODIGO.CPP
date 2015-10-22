#include <string.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned long code;
	unsigned char buffer[0x1e];

	printf("CommandLine95 Keymaker by ED!SON '96\n");
	printf("Enter name:   ");
	gets(buffer);

	strupr(buffer);
	code = ( ((unsigned long)buffer[0] *
		(unsigned long)strlen(buffer))
		<< 0x0A) + 0x2f8cc;

	printf("Your code is: %lu", code);
	getch();
	return 0;
}

