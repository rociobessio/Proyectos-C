#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Passenger.h"
#include  "utn.h"

//							STATIC LIBRARIES
static int esNombre(char* cadena,int longitud);


//							CONSTRUCTORS
Passenger* Passenger_new()
{
	Passenger* auxPass;

	auxPass = (Passenger*) malloc(sizeof(Passenger));

	if(auxPass!=NULL)//INICIALIZO LOS CAMPOS DE LA STRUCT
	{
		auxPass->id = 0;
		strcpy(auxPass->nombre,"NN"); //[NO NAME]
		strcpy(auxPass->apellido,"NLN"); //[NO LAST NAME]
		strcpy(auxPass->codigoVuelo,"AAA0000");
		auxPass->precio = 0.0;
		auxPass->statusFlight=1;
		auxPass->tipoPasajero=1;
	}
	return auxPass;
}

//AGREGUE APELLIDOSTR COMO PARA VALIDAR XQ NO ESTABA
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* statusFlight,char* precioStr,char* codigoVuelo)
{
	Passenger *this;

	this = Passenger_new();//GUARDO LO QUE DEVUELVE LA FUNCION

	int auxId;
	int auxTypePassenger;
	int auxStatusPassenger;
	float auxPrice;

	auxId = atoi(idStr);
	auxTypePassenger = atoi(tipoPasajeroStr);
	auxStatusPassenger = atoi(statusFlight);
	auxPrice = atof(precioStr);

	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && tipoPasajeroStr!=NULL && apellidoStr!=NULL && statusFlight!=NULL && precioStr!=NULL && codigoVuelo!=NULL)//VALIDO TODO
	{
		if(!(Passenger_setId(this, auxId) &&
			Passenger_setNombre(this, nombreStr) &&
			Passenger_setApellido(this, apellidoStr) &&
			Passenger_setPrecio(this, auxPrice) &&
			Passenger_setCodigoVuelo(this, codigoVuelo) &&
			Passenger_setTipoPasajero(this, auxTypePassenger) &&
			Passenger_setStatusFlight(this, auxStatusPassenger)))//[VALIDACION DE CADA CAMPO]
		{
			Passenger_delete(this);
			this=NULL;
		}
	}
	return this;
}

//   					DESTRUCTOR
void Passenger_delete(Passenger* this)//LE AGREGUE (Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

//						SEARCH/PRINT
int Passenger_searchForId(LinkedList* pArrayListPassengers, int id)
{
	int todoOk=-1;

	int auxId;

	Passenger* pAuxPassenger;

	for(int indice=0;indice<ll_len(pArrayListPassengers);indice++)
	{
		pAuxPassenger = ll_get(pArrayListPassengers, indice);//BUSCAMOS
		if(Passenger_getId(pAuxPassenger, &auxId)==1 && auxId==id)
		{
			todoOk=indice;//SI ENCUENTRA DEVUELE INDICE
		}
	}
	return todoOk;
}

int Passenger_ShowOnlyOne(Passenger *Passenger)
{
	int todoOk=0;

	int id;
	int typePassenger;
	char name[50];
	char lastName[50];
	float price;
	char codeFlight[85];
	int statusFlight;
	char descStatus[25];
	char descTypePassenger[20];

	if(Passenger!=NULL)
	{
		Passenger_getId(Passenger, &id);
		Passenger_getNombre(Passenger, name);
		Passenger_getApellido(Passenger, lastName);
		Passenger_getPrecio(Passenger, &price);
		Passenger_getCodigoVuelo(Passenger, codeFlight);
		Passenger_getTipoPasajero(Passenger, &typePassenger);
		Passenger_getStatusFlight(Passenger, &statusFlight);
		Passenger_getDescripcionStatusFlight(statusFlight, descStatus);
		Passenger_getDescripcionTipoPasajero(typePassenger, descTypePassenger);

		printf("|%4d | %-13s  |    %-13s	  |   $%11.2f  |       %11s	       | %15s     |   %10s    |\n",id,name,lastName,price,codeFlight,descTypePassenger,descStatus);

		printf("|-----|----------------|--------------------------|-----------------|--------------------------|---------------------|-----------------|\n");

		todoOk=1;
	}

	return todoOk;
}


//					SETTERS
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = -1;
	if(this!=NULL && nombre!=NULL && strlen(nombre)<48  && strlen(nombre)>=3)
	{
		if(esNombre(nombre, 49))
		{
			strlwr(nombre);
			nombre[0] = toupper(nombre[0]);
			strncpy(this->nombre,nombre,48);
			todoOk=1;
		}
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = -1;
	if(this!=NULL && apellido!=NULL && strlen(apellido)<=48 && strlen(apellido)>=3)
	{
		if(esNombre(apellido, 48))
		{
			strlwr(apellido);
			apellido[0] = toupper(apellido[0]);
			strncpy(this->apellido,apellido,48);
			todoOk=1;
		}
	}
	return todoOk;
}

int Passenger_setId(Passenger* this,int id)
{
	int todoOk=-1;

	if(this!=NULL && id>=0)
	{
		this->id = id;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk=-1;

	if(this!=NULL && tipoPasajero>0)
	{
		this->tipoPasajero = tipoPasajero;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setStatusFlight(Passenger* this,int statusFlight)
{
	int todoOk=-1;

	if(this!=NULL && statusFlight>0)
	{
		this->statusFlight = statusFlight;

		todoOk=1;
	}

	return todoOk;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;
	if(this!=NULL && codigoVuelo!=NULL && strlen(codigoVuelo)>=7 && strlen(codigoVuelo)<=7)
	{
		strupr(codigoVuelo);
		strncpy(this->codigoVuelo,codigoVuelo,8);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;

	if (this != NULL) {
		if(precio>=0){
			this->precio = precio;
			todoOk = 1;
		}
	}
	return todoOk;
}

////				GETTERS
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk=-1;
	if(this!=NULL && nombre!=NULL)
	{
		todoOk=1;
		strcpy(nombre,this->nombre);
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk=-1;
	if(this!=NULL && apellido!=NULL)
	{
		todoOk=1;
		strcpy(apellido,this->apellido);
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk=-1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getHigherId(Passenger* this,int* id)
{
    int todoOk = -1;

    if(this != NULL)
    {
        Passenger_getId(this,id);
        todoOk = 0;
    }
    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;

	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk=-1;

	if(this!=NULL && tipoPasajero>=0)
	{
		 *tipoPasajero = this->tipoPasajero;
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getDescripcionTipoPasajero(int typePassenger,char* desc)
{
	int todoOk=-1;

	if(desc!=NULL && typePassenger>0)
	{
		if(typePassenger==1)
		{
			strcpy(desc,"ECONOMIC");
		}
		else if(typePassenger==2)
		{
			strcpy(desc,"FIRST CLASS");
		}
		else if(typePassenger==3)
		{
			strcpy(desc,"CREW MEMBER");
		}
		else
		{
			strcpy(desc,"EXECUTIVE CLASS");
		}
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getStatusFlight(Passenger* this,int* statusFlight)
{
	int todoOk=-1;

	if(this!=NULL && statusFlight>=0)
	{
		 *statusFlight = this->statusFlight ;
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getDescripcionStatusFlight(int statusFlight,char* desc)
{
	int todoOk=-1;

	if(desc!=NULL && statusFlight>0)
	{
		if(statusFlight==1)
		{
			strcpy(desc,"LANDED");
		}
		else if(statusFlight==2)
		{
			strcpy(desc,"ON TIME");
		}
		else if(statusFlight==3)
		{
			strcpy(desc,"IN FLIGHT");
		}
		else
		{
			strcpy(desc,"DELAYED");
		}
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		todoOk=1;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return todoOk;
}

int Passenger_getAll(Passenger* this,char* name,char* lastname,float* price,char* flightCode,int* type,int* status,int* id)
{
	int todoOk = 1;

	if(this!=NULL)
	{
		Passenger_getId(this, id);
		Passenger_getNombre(this, name);
		Passenger_getApellido(this, lastname);
		Passenger_getPrecio(this, price);
		Passenger_getCodigoVuelo(this, flightCode);
		Passenger_getTipoPasajero(this, type);
		Passenger_getStatusFlight(this, status);
		todoOk=0;
	}
	return todoOk;
}

//STATIC LIBRARYS
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


//						SORT PASSENGERS
int Passenger_sortByName(void *name1,void *name2)
{
	int todoOk = 0;

	char auxName1[200];
	char auxName2[200];

	Passenger_getNombre(name1, auxName1);
	Passenger_getNombre(name2, auxName2);

	if(name1!=NULL && name2!=NULL)
	{
		if(strcmp(auxName1,auxName2)>0)
		{
			todoOk=1;
		}
		else if(strcmp(auxName1,auxName2)<0)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Passenger_sortByLastName(void *lastName1,void *lastName2)
{
	int todoOk = 0;

	char auxLastName1[200];
	char auxLastName2[200];

	Passenger_getApellido(lastName1, auxLastName1);
	Passenger_getApellido(lastName2, auxLastName2);

	if(lastName1!=NULL && lastName2!=NULL)
	{
		if(strcmp(auxLastName1,auxLastName2)>0)
		{
			todoOk=1;
		}
		else if(strcmp(auxLastName1,auxLastName2)<0)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Passenger_sortByCodeFlight(void *flightCode1,void *flightCode2)
{
	int todoOk = 0;

	char auxFligtCode1[200];
	char auxFlightCode2[200];

	Passenger_getCodigoVuelo(flightCode1, auxFligtCode1);
	Passenger_getCodigoVuelo(flightCode2, auxFlightCode2);

	if(flightCode1!=NULL && flightCode2!=NULL)
	{
		if(strcmp(auxFligtCode1,auxFlightCode2)>0)
		{
			todoOk=1;
		}
		else if(strcmp(auxFligtCode1,auxFlightCode2)<0)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Passenger_sortByPrice(void *price1,void *price2)
{
	int todoOk = 0;

	float auxPrice1;
	float auxPrice2;

	Passenger_getPrecio(price1, &auxPrice1);
	Passenger_getPrecio(price2, &auxPrice2);

	if(price1!=NULL && price2!=NULL)
	{
		if(auxPrice1>auxPrice2)
		{
			todoOk=1;
		}
		else if(auxPrice1<auxPrice2)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Passenger_sortByTypePassenger(void *type1,void *type2)
{
	int todoOk = 0;

	int auxType1;
	int auxType2;

	Passenger_getTipoPasajero(type1, &auxType1);
	Passenger_getTipoPasajero(type2, &auxType2);

	if(type1!=NULL && type2!=NULL)
	{
		if(auxType1>auxType2)
		{
			todoOk=1;
		}
		else if(auxType1<auxType2)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Passenger_sortByStatusFlight(void *status1,void *status2)
{
	int todoOk = 0;

	int auxStatus1;
	int auxStatus2;

	Passenger_getStatusFlight(status1, &auxStatus1);
	Passenger_getStatusFlight(status2, &auxStatus2);

	if(status1!=NULL && status2!=NULL)
	{
		if(auxStatus1>auxStatus2)
		{
			todoOk=1;
		}
		else if(auxStatus1<auxStatus2)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}
