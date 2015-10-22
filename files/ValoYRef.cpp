/*Ejemplo de funciones por valor y por referencia*/ 
  /*Calcula dos veces el procentaje de gastos, la primera vez 
  utilizando una funci�n por valor y la segunda por  referencia*/
  
  #include<stdio.h> 
  
  porcentaje_xvalor(float ingreso, float egreso) 
  { 
      egreso=((egreso/ingreso)*100) 
     printf("Usted gasta el %.2f por ciento de lo  quegana",egreso); 
  } 
  
  porcentaje_xref(float *ingreso,float *egreso) 
  { 
     *egreso=(((*egreso)/(*ingreso))*100); 
     printf("Usted gasta el %.2f por ciento de lo  quegana",egreso); 
  } 
  
  main() 
  { 
      float entrada,salida; 
     clrscr(); 
      printf("Entradas: "); 
     scanf("%f",&entrada); 
      printf("Salidad: "); 
     scanf("%f",&salida); 
      porcentaje_xvalor(entrada,salida); /*Llamada a la  funci�nporcentaje utilizando paso de     par�metros  por valor*/
     printf("\n\n"); 
      porcentaje_xref(&entrada,&salida); /*Utilizaci�nde  la funci�n porcentaje con paso de    par�metrospor  referencia*/ 
      getch(); 
  } 