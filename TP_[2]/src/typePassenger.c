
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "pasajero.h"
#include "menuPrincipal.h"
#include "statusFlight.h"
#include "typePassenger.h"







int listarTypePassenger(eTypeFlight type[], int tam)
{
	int todoOk = 0;
	if(type!=NULL && tam>0)
	{
		printf("\n---------------------------");
		printf("\n***LISTA DE STATUS***");
		printf("\n   ID	  DESCRIPCION\n");
		for(int i=0;i<tam;i++)
		{
			printf(" %4d     %10s\n", type[i].id, type[i].descripcion);
		}
		printf("---------------------------\n");


		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionStatusTypePassenger(eTypeFlight type[], int tam, int id,char descripcion[])
{
	int todoOk = 0;
	if(type!=NULL && tam>0 && id>=1 && id<=4 && descripcion!=NULL)
	{

		for(int i = 0;i<tam;i++)
		{
			if(type[i].id == id)
			{
				strcpy(descripcion, type[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
