
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
///FUNCIONES DE MENUS Y SUBMENUS

float funcionMenuKm(float* punteroKms)
{
    float kmIngresadosPuntero;
    printf("\nSeleccionaste la opcion de ingresar los KM");
    printf("\n-------------------------------------------------------");
    printf("\nIngresa los KM del recorrido del vuelo: \n");
    scanf("%f",&kmIngresadosPuntero);
    while(kmIngresadosPuntero<=0)
    {
        printf("\nERROR reingresa los KM de recorrido: \n");
        scanf("%f",&kmIngresadosPuntero);
    }

    return *punteroKms = kmIngresadosPuntero;
}

float funcionMenuIngresoValores(float* punteroValorAero, float* punteroValorLatam)
{
    float ingresoPrecioAeroPuntero;
    float ingresoPrecioLatamPuntero;

    	printf("\nSeleccionaste la opcion de ingresar el valor total del vuelo:");
    	printf("\n-------------------------------------------------------");
    	printf("\nIngresa el valor del vuelo con LATAM: ");
    	scanf("%f",&ingresoPrecioLatamPuntero);
    	while(ingresoPrecioLatamPuntero<0)
    	{
    	    printf("\nERROR reingresa el valor del vuelo con LATAM: ");
    	    scanf("%f",&ingresoPrecioLatamPuntero);
    	}
    	printf("\nIngresa el valor del vuelo con Aerolineas: ");
    	scanf("%f",&ingresoPrecioAeroPuntero);
    	while(ingresoPrecioAeroPuntero<0)//VALIDAMOS QUE EL PRECIO NO SEA NEGATIVO
    	{
    	    printf("\nERROR reingresa el valor del vuelo con Aerolineas: ");
    	    scanf("%f",&ingresoPrecioAeroPuntero);
    	}

    *punteroValorAero = ingresoPrecioAeroPuntero;
    *punteroValorLatam = ingresoPrecioLatamPuntero;

    return *punteroValorAero;
    return *punteroValorLatam;
}

void funcionLimpiarPantallaEclipse()
{
	printf("\n\n\n\n\n");
}

void funcionInformarDatosActualizados(float kmIngresado, float precioLatam, float precioAero)
{
    ///ACA LE MOSTRAMOS AL USUARIOS EL VALOR DE LOS DATOS INGRESADOS CREAR FUNCION
     printf("\n-------------------------------------------------------");
     printf("\nACTUALIZACION DE VALORES INGRESADOS:");
     printf("\nLos km ingresados son %.2f\n", kmIngresado);
     printf("El valor ingresado LATAM es $%.2f\n",precioLatam);
     printf("El valor ingresado Aerolineas es $%.2f\n",precioAero);
     printf("\n-------------------------------------------------------");

}
