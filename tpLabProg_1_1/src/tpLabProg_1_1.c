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
		a) Tarjeta de débito (descuento 10%)
		b) Tarjeta de crédito (interés 25%)
		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
		d) Mostrar precio por km (precio unitario)
		e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
     4. Informar Resultados
			“Latam:
			a) Precio con tarjeta de débito: r
			b) Precio con tarjeta de crédito: r
			c) Precio pagando con bitcoin : r
			d) Precio unitario: r
			Aerolíneas:
			a) Precio con tarjeta de débito: r
			b) Precio con tarjeta de crédito: r
			c) Precio pagando con bitcoin : r
			d) Precio unitario: r
			La diferencia de precio es : r “
     5. Carga forzada de datos
     6. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

	goingToMainMenu();

    return 0;
}

