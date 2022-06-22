#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "inputUsuario.h"
#include "calculos.h"

int menu()
{
	int opcion;

	printf("\n__________________________________________________________________________");
	printf("\n                                                                          |");
	printf("\n                       WELCOME TO TRAVEL AGENCY                           |\n");
	printf("__________________________________________________________________________|\n");
	printf("_________________________________________");
	printf("\n|1)INGRESAR KILOMETROS                  |\n|"
			"2)INGRESAR PRECIO DE VUELOS            |\n|"
			"3)CALCULAR TODOS LOS COSTOS            |\n|"
			"4)INFORMAR RESULTADOS                  |\n|"
			"5)CARGA FORZADA                        |\n|"
			"6)SALIR                                |\n");
	printf("|_______________________________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 6, 10);
	return opcion;
}



void goingToMainMenu()
{

	char confirmation = 'n';

	float kms;
	float precioAero = 0;
	float precioLatam = 0;

	int flag = 0;

	//resultados
	float resultDebAero;
	float resultDebLat;
	float resultCredAero;
	float resultCredLat;
	float resulBtcAero;
	float resultBtcLat;
	float resultUnitAero;
	float resultUnitLat;
	float resultDif;

	//carga forzada
	float kmsForzada = 7090;
	float precioLatForzada = 159339;
	float precioAeroForzada = 162965;

    do
    {
    	switch(menu())
    	{
			case 1:
				limpioPantalla();
				pedirKms(&kms);
				flag = 1;
				system("Pause");
			break;
			case 2:
				limpioPantalla();
				if(flag==1)
				{
					pedirPreciosLatamYAero(&precioLatam, &precioAero);
					flag = 2;
				}
				else
				{
					printf("\nPRIMERO DEBES DE INGRESAR LOS KILOMETROS!\n");
				}
				system("Pause");
			break;
			case 3:
				if(flag==2)
				{
					printf("\nCALCULANDO VALORES....\n");
						resultDebLat = calcularDebito(precioLatam);
						resultDebAero = calcularDebito(precioAero);
						resultCredAero = calcularCredito(precioAero);
						resultCredLat = calcularCredito(precioLatam);
						resulBtcAero = calcularBtc(precioAero);
						resultBtcLat = calcularBtc(precioLatam);
						resultUnitAero = calcularPrecioUnitario(precioAero, kms);
						resultUnitLat = calcularPrecioUnitario(precioLatam, kms);
						resultDif = calcularDiferenciaPrecios(precioAero, precioLatam);
						flag=3;
				}
				else
				{
					printf("\nPRIMERO DEBES DE INGRESAR LOS VALORES DE LOS VUELOS!\n");
				}
				system("Pause");
			break;
			case 4:
				if(flag==3)
				{
					calculosInformes(resultDebAero, resultDebLat, resultCredAero, resultCredLat, resulBtcAero, resultBtcLat, resultUnitAero, resultUnitLat, resultDif);
				}
				else
				{
					printf("\nPRIMERO DEBES DE REALIZAR LOS CALCULOS!\n");
				}
				system("Pause");
			break;
			case 5:
				cargaForzada(kmsForzada, precioLatForzada, precioAeroForzada);
				system("Pause");
			break;
			case 6:
				getUserConfirmation(&confirmation, "\nDESEAS SALIR DE LA APP (S/N)?: ", "\nVALOR INVALIDO, REINTENTA (S/N)!: ");
				if(confirmation=='s')
				{
					printf("DECIDISTE FINALIZAR LA APP!\nNOS VEMOS.....\n");
				}
				else
				{
					printf("DECIDISTE CONTINUAR USANDO LA APP!\n");
				}
			system("Pause");
			break;
    	}

		funcionInformarDatosActualizados(kms,precioLatam,precioAero);


    }while(confirmation!='s');

}
