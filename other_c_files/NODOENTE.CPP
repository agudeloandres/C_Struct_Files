 //programa principal que maneja listas lineales cada nodo tiene informaci�n un entero
 #include<iostream.h>
 #include<stdio.h>
 #include<conio.h>
 #include<dos.h>
 
 void main()
 {
  unsigned int sw;
  int *ln,*l1,*li,*lk,*lo,*Avail;
  int k,n;

  //localizar espacio disponible
  
  printf("digite el m�ximo n�mero de nodos de la lista");
   scanf("%d",&n);

    do{
    scanf("%d",&n);

       }while  (n<=0);
	
      //Asignaci�n del espacio disponible

       Avail=new int[n];

     //asignaci�n de condiciones iniciales

     lo=Avail;
     Avail++;
     k=0;
       do{
       printf("m�s Datos...Digite 0 (si),1(no)");
	do{
	  scanf("%d", &sw);
	  }
	while (sw>0 &&sw>1);
	if (sw==0) {
	k++;
	lk= Avail;
	Avail++;
	crea_nodo_lls(lk,n,k,&sw,1);
	}
        
      }
      while (sw==0 &&k<=n);

    //imprimir listas lls

    ln=lk;
    escritura_nodos_lls(ln,lo,1);

    //liberar memoria

    delete lo;

 }