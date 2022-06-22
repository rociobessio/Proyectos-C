
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include  "pasajero.h"
#include "statusFlight.h"
#include "typePassenger.h"


#define TAM 2000

#define TAM_STATFGHT 3

#define TAM_TYPEP 4

void menuPrincipal()
{
	int opcion;

	int siguienteId=1;	//ID GENERADA

	int banderaHarcode = 1;
	char confirma;

	ePassenger list[TAM];
	ePassenger pasajeroIngresado;

	eStatusFlight status[TAM_STATFGHT] = {
		{1,"ACTIVO"}, //SE DEBE DE PONER EN EL HARDCODEO
		{2,"DEMORADO"},
		{3,"CANCELADO"}
};

	eTypeFlight typePassenger[TAM_TYPEP] = {
		{1,"ECONOMICO"}, //SE DEBE DE PONER EN EL HARDCODEO
		{2,"PRIMERA CLASE"},
		{3,"TURISTA"},
		{4,"TRIPULANTE"}
};



	initPassanger(list, TAM); //LOS INICIALIZO

	do
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n                AGENCIA DE VIAJES                           |\n");
		printf("____________________________________________________________|\n");
		printf("____________________________");
		printf("\n|1)ALTA PASSENGER          |\n|"
				"2)MODIFICAR PASSENGER     |\n|"
				"3)BAJA DE PASSENGER       |\n|"
				"4)INFORME PASSENGER       |\n|"
				"5)ALTA FORZADA            |\n|"
				"6)SALIR                   |\n");
		printf("|__________________________|");
		getValidInt("\nINGRESE OPCION: ", "\nERROR, REINGRESE: ","\nINGRESE NUMEROS UNICAMENTE: " ,1, 6, &opcion);

		limpioPantalla();
		switch(opcion)
		{
			case 1:
				limpioPantalla();
				limpioPantalla();
				limpioPantalla();
				if(addPassenger(list, TAM, pasajeroIngresado.name,pasajeroIngresado.lastName,pasajeroIngresado.price,pasajeroIngresado.flycode,pasajeroIngresado.typePassenger,pasajeroIngresado.statusFlight,siguienteId,status,TAM_STATFGHT,typePassenger,TAM_TYPEP)) //si devuelve 1 todo salio bien
				{
					siguienteId++;
					banderaHarcode = 0;
				}
				else
				{
					showMessage("\nWARNING!!!\n");
					showMessage("\nERROR AL CARGAR EL PASAJERO DENTRO DEL SISTEMA\n");
				}

				system("pause");
			break;
			case 2:
				limpioPantalla();
				limpioPantalla();
					if(banderaHarcode == 1)
					{
						showMessage("\n¡AUN NO SE DIO EL ALTA, NO SE PUEDE MODIFICAR!\n");
					}
					else
					{
						modifyPassenger(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
					}
				system("pause");
			break;
			case 3:
				limpioPantalla();
				limpioPantalla();
				if(banderaHarcode==1)
				{
					showMessage("\n¡AUN NO SE DIO EL ALTA, NO SE PUEDE DAR DE BAJA!\n");
				}
				else
				{
					if(removePassenger(list, TAM,pasajeroIngresado.id,status,TAM_STATFGHT,typePassenger,TAM_TYPEP) == 0)
					{
						showMessage("\n¡OCURRIO UN ERROR INESPERADO AL DAR DE BAJA!\n");
					}
				}
				system("pause");
			break;
			case 4:
				limpioPantalla();
				limpioPantalla();
				if(banderaHarcode==1)
				{
					showMessage("\n¡AUN NO HAY NADIE EN EL SISTEMA, NO SE PUEDE INFORMAR!\n");
				}
				else
				{
					submenueInform(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				}
				system("pause");
			break;
			case 5:
				banderaHarcode = 0;
				limpioPantalla();
				limpioPantalla();
				altaForzadaPassengers(list,TAM,5,&siguienteId);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("						  ***LISTADO DE PASAJEROS***                                                      | ");
				showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
				showMessage("|  ID |	 NOMBRE    |	APELLIDO        |   PRECIO VUELO  |      CODIGO DE VUELO     |   TIPO DE PASAJERO  |   ESTADO DE VUELO    |   ");
				printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
				printPassengers(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				showMessage("----------------------------------------------------------------------------------------------------------------------------------|\n");
				system("pause");
			break;
			default:
				limpioPantalla();
				limpioPantalla();
				getUserConfirmation(&confirma, "\nDESEA TERMINAR LA APP (S/N)?: ", "\nVALOR INVALIDO, REINTENTE (S/N): ");
				if(confirma=='s')
				{
					showMessage("\nMUCHAS GRACIAS POR FINALIZAR LA APLICACION!\n");
				}
				else
				{
					showMessage("\nDECIDIO SEGUIR USANDO LA APP\n");
				}
				system("pause");
			break;
		}

	}while(opcion!=6);
}


