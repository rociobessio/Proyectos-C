#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "inputUsuario.h"

float calcularDebito(float precioRecibido)
{

	float precioConDesc;
	float precioFinal;

	if(precioRecibido>0)
	{
		precioConDesc =((precioRecibido*10)/100);
		precioFinal = precioRecibido-precioConDesc;
	}

	return precioFinal;
}

float calcularCredito(float precioRecibido)
{
    float precioConInteres;
    float precioFinalConInteres;

	if(precioRecibido>0)
	{
		precioConInteres =((precioRecibido*25)/100);
	    precioFinalConInteres = precioRecibido + precioConInteres;
	}

	return precioFinalConInteres;
}

float calcularBtc(float precioRecibido)
{
    int bitcoin = 1;
    float pesosArgentinosEquivalente = 3548415.10;
    float conversionFinal;

    if(precioRecibido>0)
    {
        conversionFinal = ((precioRecibido* bitcoin) / pesosArgentinosEquivalente);
    }

    return conversionFinal;
}

float calcularPrecioUnitario(float precioRecibido, float kmRecibido)
{
   float precioUnitarioFinal;

   if(precioRecibido>0 && kmRecibido>0)
   {
	   precioUnitarioFinal= precioRecibido / kmRecibido;
   }

   return precioUnitarioFinal;
}

float calcularDiferenciaPrecios(float precioAero, float precioLat)
{
    float diferenciaPrecios;

    if(precioAero>0 && precioLat>0)
    {
        diferenciaPrecios = precioAero - precioLat;
    }

    return diferenciaPrecios;
}

int calculosInformes(float resultDebAero,float resultDebLat,float resultCredAero,float resultCredLat,float resultBtcAero,float resultBtcLat,float resultUnitAero,float resultUnitLat,float resultDifPrecios)
{
	int todoOk = -1;

	if(resultDebAero>0 && resultDebLat>0 && resultCredAero>0 && resultCredLat>0 && resultBtcAero>0 && resultBtcLat>0 && resultUnitAero>0 && resultUnitLat>0 && resultDifPrecios)
	{
		printf("___________________________________________________________");
		printf("\n                                                           |");
		printf("\n            INFORME DE LOS CALCULOS                        |\n");
		printf("___________________________________________________________|\n");
		todoOk = 0;
		printf("_______________");
		printf("\n| AEROLINEAS  |\n");
		printf("|_____________|\n");
		printf("\nPRECIO DE DEBITO CON AEROLINEAS: %.2f",resultDebAero);
		printf("\nPRECIO DE CREDITO CON AEROLINEAS: %.2f",resultCredAero);
		printf("\nPRECIO DE BTC CON AEROLINEAS: %.12f",resultBtcAero);
		printf("\nPRECIO UNITARIO CON AEROLINEAS: %.7f",resultUnitAero);
		printf("\n_______________");
		printf("\n|    LATAM    |\n");
		printf("|_____________|\n");
		printf("\nPRECIO DE DEBITO CON LATAM: %.2f",resultDebLat);
		printf("\nPRECIO DE CREDITO CON LATAM: %.2f",resultCredLat);
		printf("\nPRECIO DE BTC CON LATAM: %.12f",resultBtcLat);
		printf("\nPRECIO UNITARIO CON LATAM: %.9f",resultUnitLat);
		printf("\n_______________");
		printf("\n|    DIF.     |\n");
		printf("|_____________|\n");
		printf("\nLA DIFERENCIA DE PRECIOS ENTRE LATAM Y AEROLINEAS ES: %.2f\n",resultDifPrecios);
	}

	return todoOk;
}

void cargaForzada(float kmsForzada,float precioLatForzada,float precioAeroForzada)
{
	float resultDebAero;
	float resultDebLat;
	float resultCredAero;
	float resultCredLat;
	float resulBtcAero;
	float resultBtcLat;
	float resultUnitAero;
	float resultUnitLat;
	float resultDif;

	if(kmsForzada>0 && precioLatForzada>0 && precioAeroForzada>0)
	{
		limpioPantalla();
		limpioPantalla();
		printf("\n___________________________________________________________");
		printf("\n                                                           |");
		printf("\n            CARGA FORZADA DE VALORES                       |\n");
		printf("___________________________________________________________|\n");
		resultDebLat = calcularDebito(precioLatForzada);
		resultDebAero = calcularDebito(precioAeroForzada);
		resultCredAero = calcularCredito(precioAeroForzada);
		resultCredLat = calcularCredito(precioLatForzada);
		resulBtcAero = calcularBtc(precioAeroForzada);
		resultBtcLat = calcularBtc(precioLatForzada);
		resultUnitAero = calcularPrecioUnitario(precioAeroForzada, kmsForzada);
		resultUnitLat = calcularPrecioUnitario(precioLatForzada, kmsForzada);
		resultDif = calcularDiferenciaPrecios(precioAeroForzada, precioLatForzada);

		calculosInformes(resultDebAero, resultDebLat, resultCredAero, resultCredLat, resulBtcAero, resultBtcLat, resultUnitAero, resultUnitLat, resultDif);
	}

}
