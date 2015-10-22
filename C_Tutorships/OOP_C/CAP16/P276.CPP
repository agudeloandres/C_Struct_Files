	enum	{
		skipws	  = 0x0001,	// Salta espacios en blanco en la entrada
		left	  = 0x0002,	// Justifica los datos de salida a la izquierda
		right	  = 0x0004,	// Justifica los datos de salida a la derecha
		internal  = 0x0008, // Rellena despues del signo de indicador de base
		dec	  	  = 0x0010,	// Escribe los datos en base decimal
		oct	  	  = 0x0020,	// Escribe los datos en base octal
		hex	  	  = 0x0040,	// Escribe los datos en base hexadecimal
		showbase  = 0x0080,	// Escribe 0 o 0x si el dato es octal o hexa
		showpoint = 0x0100,	// Escribe el punto decimal y seis cifras
							// despues de punto decimal
		uppercase = 0x0200,	// Para los datos hexa, escribe las letras en
							// mayusculas
		showpos	  = 0x0400,	// add '+' to positive integers
		scientific= 0x0800,	// use 1.2345E2 floating notation
		fixed	  = 0x1000,	// use 123.45 floating notation
		unitbuf   = 0x2000,	// Libera todos los strings, despues de
							// ser escritos
		stdio     = 0x4000,	// Libera stdin, stdout y stderr
							// despues de utilizarsen
	};
