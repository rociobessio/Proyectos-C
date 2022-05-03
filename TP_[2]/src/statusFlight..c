
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "pasajero.h"
#include "menuPrincipal.h"
#include "statusFlight.h"




int listarStatusFlight(eStatusFlight status[], int tam)
{
	int todoOk = 0;
	if(status!=NULL && tam>0)
	{
		printf("\n---------------------------");
		printf("\n***LISTA DE STATUS***");
		printf("\n    ID	DESCRIPCION\n");
		for(int i=0;i<tam;i++)
		{
			printf("  %4d    %10s\n", status[i].id, status[i].descripcion);
		}
		printf("---------------------------\n");
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionStatus(eStatusFlight status[], int tam, int id,char descripcion[])
{
	int todoOk = 0;
	if(status!=NULL && tam>0 && id>=1 && id<=3 && descripcion!=NULL)
	{

		for(int i = 0;i<tam;i++)
		{
			if(status[i].id == id)
			{
				strcpy(descripcion, status[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
