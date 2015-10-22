//Clase raton, para tratar el mismo 
     #include <dos.h> 
     #include <stdio.h> 
     #include <conio.h>

     class raton { 
	public:               //todos los elementos de la clase son publicos
	   int x;            //coordenada x del raton
	   int y;                     //coordenada y del raton
	   unsigned int NumBotones:3;    //numero de botones que tiene el raton instalado
	   unsigned int BotonI:1;       //contendra el estado del boton izquierdo
	   unsigned int BotonC:1;      //contendra el estado del boton central (si lo hay)
	   unsigned int BotonD:1;     //contendra el estado del boton derecho
	   int Inizializar(void);      //para inicializar el raton
	   void MostrarPuntero(void);  //para mostrar puntero de raton
	   void OcultarPuntero(void); //para ocultar puntero del raton
	   void ObtenEstado(void);   //para obtener coordenadas y estado de los botones
     }; 

     int raton::Inizializar(void){ 
        union REGS cpu; 
        cpu.x.ax=0; 
        int86(51,&cpu,&cpu); 
        NumBotones=cpu.x.bx; 
        if(NumBotones==0){ 
           return 0; 
        } else { 
           return 1; 
        } 
     } 

     void raton::MostrarPuntero(void){ 
        asm mov ax, 1; 
	asm int 51;
     }

     void raton::OcultarPuntero(void){ 
        asm mov ax, 2; 
        asm int 51; 
     } 

     void raton::ObtenEstado(void){ 
        union REGS cpu; 
        BotonI=0; 
        BotonC=0; 
        BotonD=0; 
        cpu.x.ax=3; 
        int86(51, &cpu, &cpu); 
        x=cpu.x.cx/8; 
        y=cpu.x.dx/8; 
        if((cpu.x.bx & 0x01)==0x01) BotonI=1; 
        if((cpu.x.bx & 0x02)==0x02) BotonD=1; 
	if((cpu.x.bx & 0x04)==0x04) BotonC=1;
     }

     void main(void){
	raton mouse;
	mouse.Inizializar();
	mouse.MostrarPuntero();
	mouse.ObtenEstado();
	printf("%d",mouse.NumBotones);
	for(;!kbhit();){
	   mouse.ObtenEstado();
	   gotoxy(10,10);
	   printf("                                                     ");
	   gotoxy(10,10);
	   printf(" %d - %d ", mouse.x,mouse.y);
	   if(mouse.BotonI==1) printf("Boton izquierdo");
	   if(mouse.BotonD==1) printf("Boton Derecho");
	}
	mouse.OcultarPuntero();
     }

