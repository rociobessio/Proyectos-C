/*
 ============================================================================
 Alumna      : Bessio Rocio Soledad
 Division    : 1A
 Arreglando  : TP_[1]
 Tema        : Funciones y reutilizacion de estas
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"

/****************************************************
    Menu:
     1. Ingresar Kilometros: ( km=x)
     2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)
			- Precio vuelo Aerolineas:
			- Precio vuelo Latam:
     3. Calcular todos los costos:
		a) Tarjeta de d�bito (descuento 10%)
		b) Tarjeta de cr�dito (inter�s 25%)
		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
		d) Mostrar precio por km (precio unitario)
		e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
     4. Informar Resultados
			�Latam:
			a) Precio con tarjeta de d�bito: r
			b) Precio con tarjeta de cr�dito: r
			c) Precio pagando con bitcoin : r
			d) Precio unitario: r
			Aerol�neas:
			a) Precio con tarjeta de d�bito: r
			b) Precio con tarjeta de cr�dito: r
			c) Precio pagando con bitcoin : r
			d) Precio unitario: r
			La diferencia de precio es : r �
     5. Carga forzada de datos
     6. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

	goingToMainMenu();

    return 0;
}

