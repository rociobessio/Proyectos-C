#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "principalMenu.h"
#include "utn.h"


#define STATE_FILE_OPEN 1
#define STATE_FILE_CLOSED 0


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu()
{
	int opcion;

	printf("\n__________________________________________________________________________");
	printf("\n                                                                          |");
	printf("\n                       WELCOME TO THE AGENCY                              |\n");
	printf("__________________________________________________________________________|\n");
	printf("_________________________________________________________________________________");
	printf("\n|1)LOAD THE PASSENGERS DATA FROM THE FILE data.csv (IN TEXT MODE)               |\n|"
			"2)LOAD THE PASSENGERS DATA FROM THE FILE data.bin (IN BINARY MODE)             |\n|"
			"3)ADD PASSENGER                                                                |\n|"
			"4)MODIFY PASSENGER                                                             |\n|"
			"5)REMOVE PASSENGER                                                             |\n|"
			"6)LIST PASSENGERS                                                              |\n|"
			"7)SORT PASSENGERS                                                              |\n|"
			"8)SAVE THE PASSENGERS DATA FROM THE FILE data.csv (IN TEXT MODE)               |\n|"
			"9)SAVE THE PASSENGERS DATA FROM THE FILE data.bin (IN BINARY MODE)             |\n|"
			"10)EXIT APP                                                                    |\n");
	printf("|_______________________________________________________________________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 10, 10);
	return opcion;
}

void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*)){
	int flagForCompare = *flag;

	if(flagForCompare==flagValue)
	{
		printf("\n%s\n",messageError1);
	}else
	{
		if (!pFunction(array))
		{
			printf("\n%s\n",messageError2);
		} else
		{
			printf("\n%s\n",messageSucess);
		}
	}
}

//PRINCIPAL MENU
void goingToMainMenu()
{
	char confirmation = 'n';
	int fileState = 0;
	int binaryState=0;

    LinkedList *listaPasajeros = ll_newLinkedList(); //INIT

    do
    {
    	limpioPantalla();
    	switch(menu())
    	{
			case 1:
				limpioPantalla();
				if(controller_loadFromText("data.csv", listaPasajeros) == 1)
				{
					printf("\nTHE FILE HAS BEEN OPENNED SUCCESSFULLY IN TEXT MODE!\n");
					fileState = 1;
				}
				else
				{
					printf("\nEXISTING ERROR WHILE OPENING FILE IN TEXT MODE!\n");
				}
				system("Pause");
			break;
			case 2:
				limpioPantalla();
				if(binaryState==0)
				{
					printf("\nBEFORE LOADING THE FILE IN BINARY MODE YOU NEED TO OPEN IT IN TEXT MODE AND SAVE IT IN BINARY TO BE ABLE TO USE IT!\n");
				}
				else
				{
					if(controller_loadFromBinary("data.bin", listaPasajeros) == 1)
					{
						printf("\nTHE FILE HAS BEEN OPENNED SUCCESSFULLY IN BINARY MODE!\n");
						fileState = 1;
					}
					else
					{
						printf("\nEXISTING ERROR WHILE OPENING FILE IN BINARY MODE!\n");
					}

				}
				system("Pause");
			break;
			case 3:
				limpioPantalla();
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO ADD THE PASSENGER! ",
						"\nYOU HAVE EXITED THE ADD!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_addPassenger);
				system("Pause");
			break;
			case 4:
				limpioPantalla();
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO MODIFY THE PASSENGER! ",
						"\nYOU HAVE EXITED THE MODIFICATIONS MENU!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_editPassenger);
				system("Pause");
			break;
			case 5:
				limpioPantalla();
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR WHILE TRYING TO REMOVE THE PASSENGER! ",
						"\nYOU HAVE EXITED THE REMOVAL MENU!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_removePassenger);
				system("Pause");
			break;
			case 6:
				limpioPantalla();
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR TRYING TO LIST THE PASSENGERS, TRY AGAIN! ",
						"\nTHE LIST OF PASSENGERS HAS BEEN SHOWED SUCCESFULLY!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_ListPassenger);
				system("Pause");
			break;
			case 7:
				pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
						"\nTHERE WAS AN ERROR TRYING TO SORT THE PASSENGERS, TRY AGAIN! ",
						"\nTHE PASSENGERS HAVE BEEN SORTED SUCCESFULLY!",
						&fileState, STATE_FILE_CLOSED, listaPasajeros, controller_sortPassenger);
			break;
			case 8:
				limpioPantalla();
				if(fileState==1)
				{
					controller_saveAsText("data.csv", listaPasajeros);
					fileState = 0;
					printf("\nTHE FILE HAS BEEN CLOSED AND SAVED SUCCESSFULLY IN TEXT MODE!\n");
				}
				else
				{
					printf("\nYOU NEED TO LOAD THE FILE FIRST!\n");
				}
				system("Pause");
			break;
			case 9:
				limpioPantalla();
				if(fileState==1)
				{
					controller_saveAsBinary("data.bin", listaPasajeros);
					fileState = 0;
					printf("\nTHE FILE HAS BEEN CLOSED AND SAVED SUCCESSFULLY IN BINARY MODE!\n");
					binaryState=1;
				}
				else
				{
					printf("\nYOU NEED TO LOAD THE FILE FIRST!\n");
				}
				system("Pause");
			break;
			case 10:
				limpioPantalla();
				if(fileState!=0)
				{
					printf("\nBEFORE EXITING THE APP YOU NEED TO SAVE THE FILE!\n");
				}
				else
				{
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CLOSE THE APP (S/N)?: ", "\nINVALID VALUE, TRY AGAIN (S/N)!: ");
					if(confirmation=='s')
					{
						printf("YOU HAVE CHOOSEN TO CLOSE THE APP!\nSEE YOU SOON.....\n");
					}
					else
					{
						printf("YOU HAVE CHOOSEN TO CONTINUE USING THE APP!\n");
					}
				}
				system("Pause");
				break;
    	}
    }while(confirmation!='s');
}

