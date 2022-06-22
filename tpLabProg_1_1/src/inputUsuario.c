#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "calculos.h"


int pedirKms(float* km)
{
	int todoOk=-1;
	float kmAux;

	if(km!=NULL)
	{
		printf("\n___________________________________________________________");
		printf("\n                                                           |");
		printf("\n            INGRESO DE KILOMETROS                          |\n");
		printf("___________________________________________________________|\n");

		utn_getNumeroFlotante(&kmAux, "\nINGRESA LOS KILOMETROS (max 100000 kms): ", "\n[VALOR INVALIDO, REINTENTA]\n", 1, 100000, 10);

		*km = kmAux;
		todoOk = 0;

	}
	return todoOk;
}

int funcionInformarDatosActualizados(float kmIngresado, float precioLatam, float precioAero)
{
	int todoOk =-1;

	if(kmIngresado>=0 && precioLatam>=0 && precioAero>=0)
	{
    	limpioPantalla();
		printf("\n___________________________________________________________");
		printf("\n                                                           |");
		printf("\n            VALORES ACTUALIZADOS                           |\n");
		printf("___________________________________________________________|\n");
	    printf("LOS KILOMETROS INGRESADOS SON: %.2f                 \n", kmIngresado);
	    printf("EL VALOR INGRESADO DE LATAM ES: $%.2f               \n",precioLatam);
	    printf("EL VALOR INGRESADO DE AEROLINEAS ES: $%.2f          \n",precioAero);
	     todoOk=0;
	}
     return todoOk;
}

int pedirPreciosLatamYAero(float* precioLatam,float* precioAero)
{
	int todoOk=-1;
	float auxLatam;
	float auxAero;

	if(precioAero!=NULL && precioLatam!=NULL)
	{
    	limpioPantalla();
    	limpioPantalla();
		printf("\n___________________________________________________________");
		printf("\n                                                           |");
		printf("\n            INGRESO DE PRECIOS                             |\n");
		printf("___________________________________________________________|\n");
		todoOk = 0;

		utn_getNumeroFlotante(&auxAero, "\nINGRESA EL PRECIO DEL VUELO CON AEROLINEAS (max $200000): ", "\n[VALOR INVALIDO, REINGRESA]\n", 1, 200000, 10);

		utn_getNumeroFlotante(&auxLatam, "\nINGRESA EL PRECIO DEL VUELO CON LATAM (max $200000): ", "\n[VALOR INVALIDO, REINGRESA]\n", 1, 200000, 10);

		*precioLatam = auxLatam;
		*precioAero = auxAero;
	}

	return todoOk;
}



