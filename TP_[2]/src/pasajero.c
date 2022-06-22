
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "pasajero.h"
#include "menuPrincipal.h"
#include "typePassenger.h"

//2.1
int initPassanger(ePassenger list[], int len)
{
	int todoOk = 0;

	if(list!=NULL && len>0)
	{
		for(int i = 0;i<len;i++)//INDICAR QUE TODAS LAS POSICIONES ESTAN VACIAS, TOMANDO COMO REFERENCIA EL ID
		{
			list[i].isEmpty = 1;
		}
		todoOk =1;
	}
	return todoOk;
}

int searchFreeSpacePassenger(ePassenger list[], int len)
{

	int index = -1;

	if(list!=NULL && len >0 )
	{

		for(int i = 0;i<len;i++){
			if(list[i].isEmpty)
			{
				index = i;
				break; //ROMPO PORQUE ENCONTRE LUGAR
			}
		}
	}
	return index;
}

//2.3
int findPassengerById(ePassenger list[], int len,int pId,int* pIndex)
{
	int todoOk = 0;

	if(list!=NULL && len >0 && pIndex !=NULL && pId>0)
	{
		*pIndex= -1;
		for(int i = 0;i<len;i++){
			if(list[i].isEmpty == 0 && list[i].id == pId)
			{
				*pIndex = i;
				break; //ROMPO PORQUE ENCONTRE
			}
		}
		todoOk =1;
	}
	return todoOk;
}

int removePassenger(ePassenger list[],int len, int id,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger)//BAJA LOGICA
{
	int todoOk = 0;
	int idIngresada;
	int pIndex;
	char opcion;

	if(list!=NULL && len >0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n                BAJA PASSENGERS                             |\n");
		printf("____________________________________________________________|\n");
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
		showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
		printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
		printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");

		getValidInt("\nINGRESE EL ID: ", "\nERROR INGRESE ID VALIDA: ", "\nINGRESE SOLO NUMEROS: ", 1, 20001, &idIngresada);

		if(findPassengerById(list, len, idIngresada, &pIndex) == 1)//BUSCA EL EMPLEADO
		{
			if(pIndex == -1)
			{
				showMessage("\nPASAJERO NO ENCONTRADO DENTRO DEL SISTEMA!!\n");
			}
			else
			{
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				showOnePassenger(list[pIndex],status,tam_status,typePassenger,tamPassenger);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");

				getUserConfirmation(&opcion, "\nDESEA ELIMINAR AL EMPLEADO DEL SISTEMA?\n", "\nERROR REINGRESE (S/N): ");
				if(opcion !='s')
				{
					showMessage("\nBAJA CANCELADA POR EL USUARIO!!\n");
				}
				else
				{
					list[pIndex].isEmpty =1; //CAMBIO EL VALOR A VACIO
					showMessage("\nBAJA EXITOSA!!!\n");
					todoOk =1;
				}
			}
		}
		else
		{
			showMessage("\nOCURRIO UN ERROR INESPERADO CON EL SISTEMA AL BUSCAR AL PASAJERO!!\n");
		}
	}


	return todoOk;
}


//2.2
int addPassenger(ePassenger* list,int len,char name[],char lastName[],float price,char flycode[],int typePassenger,int statusFlight,int id,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger)
{
	int todoOk =-1;

	int indice;

	char auxName[51];
	char auxLastName[51];
	float auxFloatPrice;
	char auxFlycode;

	char opcion;


	if(list!=NULL && len >0 && id && name!=NULL && lastName!=NULL && flycode!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n                ALTA PASSENGERS                             |\n");
		printf("____________________________________________________________|\n");

			indice = searchFreeSpacePassenger(list, len);

			if(indice == -1)
			{
				printf("\n¡NO HAY MAS ESPACIO EN EL SISTEMA!\n");

			}
			else
			{
				list[indice].id = id;

				getValidString("\nINGRESE EL NOMBRE: ",
								"\nRECUERDE, SOLO LETRAS: ",
								"\nEXCEDIO EL LIMITE: ",auxName, 3,51);
				strupr(auxName);
				strcpy(list[indice].name,auxName);

				getValidString("\nINGRESE EL APELLIDO:\n",
								"\nRECUERDE, SOLO LETRAS:\n",
								"\nEXCEDIO EL LIMITE:\n",auxLastName, 3,51);
				strupr(auxLastName);
				strcpy(list[indice].lastName,auxLastName);

				getFloatValidation( &auxFloatPrice,"\nINGRESE EL PRECIO DEL VUELO ($10000 - $700000000): \n",
									"\nVALORES ENTRE ($10000 - $700000000), REINGRESE: \n", 10000, 700000000);
				list[indice].price = auxFloatPrice;

				getValidStringAlpha("\nINGRESE EL CODIGO ALFANUMERICO DE VUELO DE 9 DIGITOS: ",
									"\nERROR INVALIDO, REINGRESE UN CODIGO ALFANUMERICO DE 9 DIGITOS: ", &auxFlycode, 9, 9);
				strcpy(list[indice].flycode,&auxFlycode);

				limpioPantalla();
				listarTypePassenger(typePassenger2, tamPassenger);
				utn_getNumero(&typePassenger, "INGRESE EL TIPO DE PASAJERO: ", "ERROR REINGRESE UN VALOR VALIDO. ", 1, 4, 100);
				list[indice].typePassenger = typePassenger;

				limpioPantalla();
				listarStatusFlight(status, tam_status);
				utn_getNumero(&statusFlight, "INGRESE EL ESTADO DEL VUELO: ", "ERROR REINGRESE UN VALOR VALIDO. ", 1, 3, 100);
				list[indice].statusFlight = statusFlight;

				list[indice].isEmpty = 0;//CON LA VUELTA Y CARGA PASA A ESTAR OCUPADO

				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				showOnePassenger(list[indice],status,tam_status,typePassenger2,tamPassenger);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");
				getUserConfirmation(&opcion, "\nDESEA DAR DE ALTA AL PASAJERO (S/N)?: ", "\nVALOR INVALIDO, REINGRESE (S/N): ");
				if(opcion!='s')
				{
					showMessage("\nALTA CANCELADA POR EL USUARIO!");
					id--;
					list[indice].isEmpty = 1;
				}
				else
				{
					showMessage("\n¡CARGA EXITOSA!\n");
				}

				todoOk = 1;
			}
	}

	return todoOk;
}

void showOnePassenger(ePassenger list,eStatusFlight status[],int tam,eTypeFlight typePassenger[],int tamPassenger)
{
	char descriptStatus[20];
	char descriptTypePassenger[25];
	cargarDescripcionStatus(status, tam, list.statusFlight, descriptStatus);
	cargarDescripcionStatusTypePassenger(typePassenger, tamPassenger, list.typePassenger, descriptTypePassenger);
	printf("|%4d | %-10s |    %-10s	|    $%-11.2f |       %-11s	     |	  %-13s    |       %-9s      |\n", list.id,
																					                       list.name,
																										   list.lastName,
																										   list.price,
																										   list.flycode,
																										   descriptTypePassenger,
																										   descriptStatus
																																);
}



void printPassengers(ePassenger list[], int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger)
{
	int bandera=0;

		for(int i =0; i<len;i++)
		{
			if(!list[i].isEmpty)//SI ESTA OCUPADO LO MUESTRO
			{
				showOnePassenger(list[i],status,tam_status,typePassenger,tamPassenger);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\n				**NO SE ENCONTRARON PASAJEROS DENTRO DEL SISTEMA**\n");
		}
}


int modifyPassenger(ePassenger list[], int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger)
{
	//ePassenger pasajeroModificacion;
	int todoOk = 0;

	int idIngresada;
	int pIndex;
	char opcion;
	int opcionNum;

	char auxCadena [51];
	float auxFloat;
	int auxTypePassenger;

	if(list!=NULL && len >0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n                MODIFICACION PASSENGERS                     |\n");
		printf("____________________________________________________________|\n");
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
		showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
		printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
		printPassengers(list, len,status,tam_status,typePassenger2,tamPassenger);
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");
		getValidInt("\nINGRESE EL ID: ", "\nERROR, INGRESE UN VALOR VALIDO: ", "\nERROR, UNICAMENTE NUMEROS: ", 1, 2000, &idIngresada);

		if(findPassengerById(list, len, idIngresada, &pIndex) == 1)//BUSCA EL EMPLEADO
		{
			if(pIndex == -1)
			{
				showMessage("\nPASAJERO NO ENCONTRADO DENTRO DEL SISTEMA!!\n");
			}
			else
			{
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				showOnePassenger(list[pIndex],status,tam_status,typePassenger2,tamPassenger);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");

				getUserConfirmation(&opcion, "\nDESEA MODIFICAR A UN PASAJERO (S/N)?  ", "\nERROR REINGRESE (S/N): ");
				if(opcion =='s')
				{
					printf("____________________________");
					printf("\n|1)NOMBRE                  |\n|"
							"2)APELLIDO                |\n|"
							"3)PRECIO DE VUELO         |\n|"
							"4)CODIGO DE VUELO         |\n|"
							"5)TIPO DE PASAJERO        |\n");
					printf("|__________________________|");
					utn_getNumero(&opcionNum, "\nINGRESE QUE DESEA MODIFICAR: ", "\nVALOR INVALIDO, REINGRESE: ", 1, 6, 10);
					switch(opcionNum)
					{
						case 1:
							getValidString("\nINGRESE EL NOMBRE:\n",
											"\nRECUERDE, SOLO LETRAS:\n",
											"\nEXCEDIO EL LIMITE:\n",auxCadena, 3,51);
							strupr(auxCadena);
							getUserConfirmation(&opcion, "\nDESEA MODIFICAR EL NOMBRE DEL PASAJERO? S/N\n","\nERROR REINGRESE");
							if(opcion=='s')
							{
								strcpy(list[pIndex].name,auxCadena);
								showMessage("\n**MODIFICACION EXITOSA**\n");
							}
							else
							{
								showMessage("\n**MODIFICACION CANCELADA**\n");
							}
						break;
						case 2:
							getValidString("\nINGRESE EL APELLIDO:\n",
											"\nRECUERDE, SOLO LETRAS:\n",
											"\nEXCEDIO EL LIMITE:\n",auxCadena, 3,51);
							strupr(auxCadena);
							getUserConfirmation(&opcion, "\nDESEA MODIFICAR EL APELLIDO DEL PASAJERO? S/N\n","\nERROR REINGRESE");
							if(opcion=='s')
							{
								strcpy(list[pIndex].lastName,auxCadena);
								showMessage("\n**MODIFICACION EXITOSA**\n");
							}
							else
							{
								showMessage("\n**MODIFICACION CANCELADA**\n");
							}
						break;
						case 3:
							getFloatValidation( &auxFloat,
												"\nINGRESE EL PRECIO DEL VUELO ($10000 - $700000000): \n",
												"\nLIMITE DE ($10000 - $700000000), REINGRESE : \n", 10000, 700000000);
							getUserConfirmation(&opcion, "\nDESEA MODIFICAR EL PRECIO DEL VUELO DEL PASAJERO? S/N\n","\nERROR REINGRESE");
							if(opcion=='s')
							{
								list[pIndex].price = auxFloat;
								showMessage("\n			**MODIFICACION EXITOSA**\n");
							}
							else
							{
								showMessage("\n			**MODIFICACION CANCELADA**\n");
							}
						break;
						case 4:
							getValidStringAlpha("\nINGRESE EL CODIGO ALFANUMERICO DE VUELO DE 9 DIGITOS: ",
												"\n**ERROR INVALIDO, REINGRESE UN CODIGO ALFANUMERICO DE 9 DIGITOS: ", auxCadena, 9, 9);
							strcpy(list[pIndex].flycode,auxCadena);
							if(opcion=='s')
							{
								strcpy(list[pIndex].flycode, auxCadena);
								showMessage("\n	**MODIFICACION EXITOSA**\n");
							}
							else
							{
								showMessage("\n**MODIFICACION CANCELADA**\n");
							}
						break;
						case 5:
							listarTypePassenger(typePassenger2, tamPassenger);
							utn_getNumero(&auxTypePassenger, "INGRESE EL TIPO DE PASAJERO: ", "ERROR, REINGRESE UN VALOR VALIDO. ", 1, 4, 100);
							list[pIndex].typePassenger = auxTypePassenger;
							if(opcion=='s')
							{
								list[pIndex].typePassenger = auxTypePassenger;
								showMessage("\n	**MODIFICACION EXITOSA**\n");
							}
							else
							{
								showMessage("\n**MODIFICACION CANCELADA**\n");
							}
						break;
					}
				}
				else
				{
					showMessage("\nMODIFICACION CANCELADA!");
				}
			todoOk =1;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN ERROR INESPERADO CON EL SISTEMA AL BUSCAR AL PASAJERO!!\n");
		}
	}
return todoOk;
}

/*
int sortPassengers(ePassenger* list, int len, int order)
{
	int todoOk = 1;

	ePassenger auxiPasajero;

	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len;i++)
		{
			for(int j = i;j<len;j++)
			{
				if(!list[i].isEmpty && !list[j].isEmpty)
				{
					if(((list[i].typePassenger == list[j].typePassenger) && strcmp(list[i].lastName,list[j].lastName)>0 && order ==1)
						|| (list[i].typePassenger != list[j].typePassenger && list[i].typePassenger > list[j].typePassenger&& order ==1)
						||(list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName)<0 && order ==0)
						||(list[i].typePassenger != list[j].typePassenger && list[i].typePassenger < list[j].typePassenger&& order ==0))
					{
						auxiPasajero = list[i];
						list[i] = list[j];
						list[j] = auxiPasajero;
					}
				}
			}
		}
	}
	return todoOk;
}
*/

int sortPassengers(ePassenger* list, int len, int order)//SI APELLIDO COINCIDE ORDENAR POR TIPO PASAJERO
{
	int todoOk = 1;

	ePassenger auxiPasajero;

	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len-1;i++)
		{
			for(int j = i+1;j<len;j++)
			{
				if(!list[i].isEmpty && !list[j].isEmpty)
				{
					if((strcmp(list[i].lastName,list[j].lastName)==0 && (list[i].typePassenger > list[j].typePassenger) && order ==1)
						|| (strcmp(list[i].lastName,list[j].lastName)>0 &&  order == 1)
						|| (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].typePassenger < list[j].typePassenger && order ==0)
						|| (strcmp(list[i].lastName,list[j].lastName)<0  && order ==0))
					{
						auxiPasajero = list[i];
						list[i] = list[j];
						list[j] = auxiPasajero;
					}
				}
			}
		}
	}
	return todoOk;
}



int informPrice(ePassenger list[],int len,float* acumPrecio,int* cantPassengers, int* contPassengerSuperior,float* promedioPrecios)
{
	int todoOk =-1;

	float acumPasaje = 0.00;
	int cantPasajeros = 0;
	float promedio;

	int cantidadPassengerPromedio=0;

	if(list!=NULL && len>0 && acumPrecio!=NULL && cantPassengers!=NULL && promedioPrecios!=NULL)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].price>0 && list[i].isEmpty==0)
			{
				cantPasajeros++;
				acumPasaje=list[i].price  + acumPasaje;
			}
		}

		promedio=(float)(acumPasaje/cantPasajeros);
		for(int i=0; i<len;i++)
		{
			if(list[i].price>promedio && list[i].isEmpty==0)
			{
				cantidadPassengerPromedio++;
			}
		}
		*cantPassengers = cantPasajeros;
		*acumPrecio= acumPasaje;
		*promedioPrecios = promedio;
		*contPassengerSuperior = cantidadPassengerPromedio;

		todoOk =0;
	}

	return todoOk;
}

int sortPassengersByCode(ePassenger* list,int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger,int order)
{
	int todoOk = -1;
	ePassenger auxPassanger;

	if(list!=NULL && len>0)
	{
		for(int i = 0;i<len;i++)
		{
			for(int j = i;j<len;j++)
			{
				if(!list[i].isEmpty && !list[j].isEmpty )
				{
					if(order==1)
					{
						if(strcmp(list[i].flycode,list[j].flycode)>0 )
						{
							auxPassanger = list[i];
							list[i]= list[j];
							list[j]= auxPassanger;
						}
					}
					else if(order==0)
					{
						if(strcmp(list[i].flycode,list[j].flycode)<0)
						{
							auxPassanger = list[i];
							list[i]= list[j];
							list[j]= auxPassanger;
						}
					}
				}
			}
		}

		showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
		showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
		printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
		for(int i =0; i<len;i++)
		{
			if(!list[i].isEmpty && list[i].statusFlight == 1)
			{
				 showOnePassenger(list[i],status,tam_status,typePassenger,tamPassenger);
			}
		}
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");

		todoOk=0;
	}
	return todoOk;
}



int submenueInform(ePassenger list[],int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger[],int tamPassenger)
{
	int todoOk =1;

	int opcion;
	int order;

	//----
	float acumuladorPrecio = 0.0;
	int cantPassengers=0;
	int cantPassengersPromedioPrecioMayor = 0;
	float promedioFinal = 0.0;


	if(list!=NULL && len>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n                INFORMES                                    |\n");
		printf("____________________________________________________________|\n");

		printf("_____________________________________________________________");
		printf("\n|1)ORDEN ALFABETICO POR APELLIDO Y TIPO DE PASAJERO         |\n|"
				"2)TOTAL Y PROMEDIO DE PRECIOS                              |\n|"
				"3)CODIGO DE VUELO Y ESTADO DE VUELO ACTIVO                 |\n");
		printf("|___________________________________________________________|");
		utn_getNumero(&opcion, "\nINGRESE: ", "\nERROR, REINTENTE UN VALOR VALIDO ", 1 , 3, 5000);
		switch (opcion)
		{
			case 1:
				printf("\n\n");
				printf("_______________________");
				printf("\n|1)ASCENDENTE         |\n|"
						"0)DESCENDENTE        |\n");
				printf("|_____________________|");
				utn_getNumero(&order, "\nINGRESE COMO DESEA VER LA LISTA:", "\nERROR, REINGRESE VALOR VALIDO ", 0, 1, 10000);
				sortPassengers(list, len, order);
				limpioPantalla();
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");
			break;
			case 2:
				limpioPantalla();

				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				informPrice(list, len, &acumuladorPrecio, &cantPassengers,&cantPassengersPromedioPrecioMayor, &promedioFinal);
				printPassengers(list, len,status,tam_status,typePassenger,tamPassenger);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");

				printf("\n___________________________________________________________________________________\n");
				printf("\nEL TOTAL DE PRECIO DE TODOS LOS VUELOS INGRESADOS ES DE: $%.2f						",acumuladorPrecio);
				printf("\n___________________________________________________________________________________\n");
				printf("\nEL PROMEDIO ENTRE LOS PRECIOS DE LOS VUELOS ES DE: $%.2f								",promedioFinal);
				printf("\n___________________________________________________________________________________\n");
				printf("\nLA CANTIDAD DE PASAJEROS EN SUPERAR ESE PROMEDIO SON: %d							",cantPassengersPromedioPrecioMayor);
				printf("\n___________________________________________________________________________________\n");
			break;
			case 3:
				printf("\n\n");
				printf("_______________________");
				printf("\n|1)ASCENDENTE         |\n|"
						"0)DESCENDENTE        |\n");
				printf("|_____________________|");
				utn_getNumero(&order, "\nCOMO DESEA VER LA LISTA: ", "\nERROR, REINGRESE VALOR VALIDO ", 0, 1, 10000);
				sortPassengersByCode(list, len,status,tam_status,typePassenger,tamPassenger,order);

			break;
		}

	}
	return todoOk;
}


int altaForzadaPassengers(ePassenger* list, int len, int cant,int* id)
{
	ePassenger impostores[] =
	   {
		       {0, "ESTEBAN", "QUITO",100000,"AhJil14567",1,1,0},
		        {0, "CARLA", "ALONSO",120000,"Skml89Plm",2,2,0},
		        {0, "MARIA","ALONSO", 140000,"pL23581da",3,3,0},
		        {0, "JOSE", "ACUNIA",120000,"69AmneIsa",2,1,0},
		        {0, "LUCAS", "DANIEL", 110000,"89Sfew122",4,2,0},
		        {0, "PAULA", "TRAVOLTA", 130000,"hjrwSa219",1,1,0},
		        {0, "CLAUDIA", "MUSSIO", 120000,"5afew21fp",2,3,0},
		        {0, "CRISTINA", "ESCALANTE", 150000,"riedon213",3,2,0},
		        {0, "RENATA", "MANDI", 120000,"sjfF25pa5",1,2,0},
		        {0, "BENICIO", "POLKA", 110000,"2pol12a5",4,1,0}
	    };

	int todoOk = 0;
	if(list!=NULL && len >0 && id!=NULL && cant>0 && cant<=len)
	{
		for(int i = 0;i<cant;i++)
		{
			list[i] = impostores[i];
			list[i].id = *id;
			*id = *id+1; //INCREMENTO LAS IDs
		}
		todoOk = 1;
	}

	return todoOk;
}

