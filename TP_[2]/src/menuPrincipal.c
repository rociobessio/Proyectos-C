
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


	int banderaAltas =0;

	initPassanger(list, TAM); //LOS INICIALIZO




	do
	{
		utn_getNumero(&opcion, "\n---------------------------------------------------------------\n"
								"		BIENVENID@ A NUESTRA AGENCIA\n"
								"---------------------------------------------------------------\n"
								"A CONTINUACION PRESIONE: "
								"\n\n1)ALTA\n\n2)MODIFICAR\n\n3)BAJA\n\n4)INFORMAR\n\n5)ALTA FORZADA\n\n6)SALIR\n\n",
								"\n\n\n\nERROR: "
								"\n\n1)ALTA\n\n2)MODIFICAR\n\n3)BAJA\n\n4)INFORMAR\n\n5)ALTA FORZADA\n\n6)SALIR\n\n", 1, 6, 10000);
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
					banderaAltas=1;//CAMBIAMOS EL VALOR
				}
				else
				{
					showMessage("\n	**WARNING**\n");
					showMessage("\n	**ERROR AL CARGAR EL PASAJERO DENTRO DEL SISTEMA**\n");
				}

				system("pause");
			break;
			case 2:
				limpioPantalla();
				limpioPantalla();
				limpioPantalla();
					if(banderaAltas==0)
					{
						showMessage("\n	**¡AUN NO SE DIO EL ALTA, NO SE PUEDE MODIFICAR!**\n");
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
				limpioPantalla();
				if(banderaAltas==0)
				{
					showMessage("\n**¡AUN NO SE DIO EL ALTA, NO SE PUEDE DAR DE BAJA!**\n");
				}
				else
				{
					if(removePassenger(list, TAM,pasajeroIngresado.id,status,TAM_STATFGHT,typePassenger,TAM_TYPEP) == 0)
					{
						showMessage("\n**¡OCURRIO UN ERROR INESPERADO AL DAR DE BAJA!**\n");
					}
				}
				system("pause");
			break;
			case 4:
				limpioPantalla();
				limpioPantalla();
				submenueInform(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				system("pause");
			break;
			case 5:
				limpioPantalla();
				limpioPantalla();
				altaForzadaPassengers(list,TAM,5,&siguienteId);
				showMessage("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				showMessage("						  ***LISTADO DE PASAJEROS***    \n");
				showMessage("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				showMessage("  ID	 NOMBRE		  APELLIDO	   PRECIO VUELO	      CODIGO DE VUELO         TIPO DE PASAJERO	      ESTADO DE VUELO      \n");
				printPassengers(list, TAM,status,TAM_STATFGHT,typePassenger,TAM_TYPEP);
				showMessage("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				system("pause");
			break;
			default:
				limpioPantalla();
				limpioPantalla();
				showMessage("\n	 ***MUCHAS GRACIAS POR FINALIZAR LA OPERACION***.\n");
				system("pause");
			break;
		}

	}while(opcion!=6);
}


