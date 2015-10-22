

//                   LISTAS LINEALES ENLASADAS CIRCULARES                //


//   RUTINA DE INCIALIZAR LLEC.

//COMIENZO
//********************************************//
inicializar
      ptr <- NULL
      avail <- NULL
//***************************************//

//   RUTINA DE INCLUIR LLEC.

		Leer informacion
		localizar el nodo
		asignar informacion


// condicion de vacio

VACIA:

    ptr <- p
    link(ptr) <- p

// ******************************************//

otro caso:

LEER
LOCALIZAR
ASIGNAR

	Q <- LINK(PTR)
	LINK(PTR) <- P
	LINK(P) <- Q
	PTR <- P
//*********************************************//
OTRO CASO:

Cuando hay un solo nodo:

	LINK(P) <- PTR
	LINK(PTR) <- P
// ************************************************//

/// RUTINA PARA CANCELAR CON UN NODO CONOCIDO LLEC.

LEER
BUSCAR

VACIA:
      escriba "no hay nada que cancelar"

//*******************************************//
UN SOLO NODO:

     IF LINK(P) <- P
	PTR <- NULL

      ELSE
	 IF P = PTR
	 LINK(Q) <- PTR
	 PTR <- Q
	 LIBERAR(P)



OTRO CASO:
	  LINK(Q) <- LINK(P)
	  LIBERAR(P)

OTRO CASO:
	  Q <- LINK(PTR)
	  LINK(PTR) <- LINK(Q)


//// RUTINA PARA CONSULTAR

	 P <- PTR
      HH
	 P != PTR
	 INF <- INFO(P)
	 ESCRIBA ( INF )
	 P <- LINK(P)
      FHH


//////  RUTINA PARA CACELAR POR EL LINK(PTR)=POP

	  INF <- INFO(TOPE)
	// CONSULTA PARA INCONTAR ANTESESOR DE TOPE

	    P <- TOPE
	    LINK(Q) <- LINK(TOPE)
	    TOPE <- Q
	    LIBERE(P)

///////// RUTINA PARA INCLUIR POR EL LINK(PTR)=PUSH


	  LOCALIZAR(P)
	  INFO(P) <- INF
	  LINK(P) <- LINK(TOPE)
	  LINK(TOPE) <- P
	  TOPE <- P

// FIN









