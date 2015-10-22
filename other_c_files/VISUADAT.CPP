#include<iostream.h>
#include"stdio.h"
#include<conio.h>
void main()
{
clrscr();
struct alumno{
    float telefono,codigo;
    char *nombre;
    }sistemas;
    float cod,tel;
    char nom[35];
    gotoxy(14,3);
    printf("DIGITE AQUI SU IMFORMACION");
    gotoxy(14,5);
    printf("Por favor ingrese el codigo   ");
    scanf("%f",&cod);
    gotoxy(14,7);
    printf("Por favor ingrese el nombre   ");
    cin.getline(nom,35);
    gotoxy(14,9);
    printf("Por favor ingrese el número de telefono   ");
    scanf("%f",&tel);
    sistemas.codigo=cod;
    sistemas.nombre=nom;
    sistemas.telefono=tel;
    gotoxy(14,12);
    printf("ESTOS SON SUS DATOS");
    gotoxy(14,14);
    printf("su codigo es =%6.0f",sistemas.codigo);
    gotoxy(14,16);
    printf("su nombre es =%s",sistemas.nombre);
    gotoxy(14,18);
    printf("su telefono es =%6.0f",sistemas.telefono);
 getch();
    }