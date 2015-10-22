// *******************************************************************
// ******           FUNCION RETORNA OPCION A EJECUTAR           ******
// *******************************************************************

int Retorna_Opcion(int Vert, int Horiz) 
{ 
int Opcion=0;

// ******           FUNCION DEVUELVE SALIR            ******
  if (Vert >= 620 && Vert <= 634 && Horiz >= 2 && Horiz <= 16)
        Opcion = 1; 

// ******           FUNCION DEVUELVE INTRODUCCION           ******
  else if (Vert >= 4 && Vert <= 110 && Horiz >= 22 && Horiz <= 33)
        Opcion = 2; 

// ******           FUNCION DEVUELVE DEMOSTRACION           ******
  else if (Vert >= 116 && Vert <= 224 && Horiz >= 22 && Horiz <= 33)
        Opcion = 3; 

// ******           FUNCION DEVUELVE FUNCIONAMIENTO           ******
  else if (Vert >= 228 && Vert <= 350 && Horiz >= 22 && Horiz <= 33)
        Opcion = 4; 

// ******           FUNCION DEVUELVE TEMAS DE AYUDA           ******
  else if (Vert >= 354 && Vert <= 406 && Horiz >= 22 && Horiz <= 33)
        Opcion = 5; 

// ******           FUNCION DEVUELVE ACERCA DE SHOW           ******
  else if (Vert >= 410 && Vert <= 518 && Horiz >= 22 && Horiz <= 33)
        Opcion = 6; 

  return (Opcion);
}
