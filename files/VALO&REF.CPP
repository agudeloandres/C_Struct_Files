/*Ejemplo de funciones por valor y por referencia*/
  /*Calcula dos veces el procentaje de gastos, la primera vez 
  utilizando una función por valor y la segunda por  referencia*/
  
  #include<stdio.h>
  #include <conio.h>
  
  porcentaje_xvalor(float ingreso, float egreso) 
  { 
      egreso=((egreso/ingreso)*100); 
     printf("Usted gasta el %.2f por ciento de lo  que gana",egreso);
  }

  porcentaje_xref(float *ingreso,float *egreso)
  {
     *egreso=(((*egreso)/(*ingreso))*100);
     printf("Usted gasta el %.2f por ciento de lo  que gana",*egreso);
  }
  
  main() 
  { 
      float entrada,salida; 
     clrscr(); 
      printf("Entradas: "); 
     scanf("%f",&entrada); 
      printf("Salidad: "); 
     scanf("%f",&salida); 
      porcentaje_xvalor(entrada,salida); /*Llamada a la  funciónporcentaje utilizando paso de     parámetros  por valor*/
     printf("\n\n"); 
      porcentaje_xref(&entrada,&salida); /*Utilizaciónde  la función porcentaje con paso de    parámetrospor  referencia*/ 
      getch(); 
  } 