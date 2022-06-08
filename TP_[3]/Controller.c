 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include"parser.h"


/*
int saveAsText_maxID(FILE* pFile, LinkedList* pArrayListPassenger,int* maxID)
{
    Passenger* passenger;

    int id;
    int len_LL;
    int todoOk = 0;
    int maxId;
    int flag = 0;

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        len_LL = ll_len(pArrayListPassenger);

        for(int i=0; i<len_LL; i++)
        {
        	passenger = ll_get(pArrayListPassenger,i);
            Passenger_getHigherId(passenger,&id);
            if(flag==0 || id>maxId)
            {
            	maxId = id;
            	flag=1;
            }
            todoOk = 1;
        }
    }
    *maxID = maxId;
    return todoOk;
}

int controller_saveAsTextMaxID(FILE* pFile,char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int maxID;

    if(pFile !=NULL && saveAsText_maxID(pFile,pArrayListPassenger,&maxID))
    {
        todoOk = 1;
        fprintf(pFile,"%d\n",maxID+1);//LA GUARDO
    }
    return todoOk;
}*/

int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListPassenger,int* maxID)
{
    Passenger* passenger;

    int id;
    int len_LL;
    int todoOk = 0;
    int maxId;
    int flag = 0;

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        len_LL = ll_len(pArrayListPassenger);

        for(int i=0; i<len_LL; i++)
        {
        	passenger = ll_get(pArrayListPassenger,i);
            Passenger_getHigherId(passenger,&id);
            if(flag==0 || id>maxId)
            {
            	maxId = id;
            	flag=1;
            }
            todoOk = 1;
        }
    }
    *maxID = maxId;
    return todoOk;
}

int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int maxID;

    if(pFile !=NULL && saveAsBinary_LastID(pFile,pArrayListPassenger,&maxID))
    {
        todoOk = 1;
        fprintf(pFile,"%d\n",maxID+1);
    }
    return todoOk;
}
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;//SAVE PASSENGERS
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "r");
	pFile2=fopen("ultimaID.bin","wb");

	if(pFile != NULL)
	{
		parser_PassengerFromText(pFile, pArrayListPassenger);
		fclose(pFile);
		todoOk=1;
	}
	if(controller_saveBinaryLastId(pFile2,"ultimaID.bin", pArrayListPassenger))
	{
		fclose(pFile2);
	}

    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList *pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;//SAVE PASSENGERS
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "rb");//OPEN IN BINARY
	pFile2=fopen("ultimaID.bin","wb");

	if(pFile != NULL)
	{
		parser_PassengerFromBinary(pFile, pArrayListPassenger);
		fclose(pFile);//CLOSE THE FILE
		todoOk=1;
	}

	if(controller_saveBinaryLastId(pFile2,"ultimaID.bin", pArrayListPassenger))
	{
		fclose(pFile2);//CLOSE ID BIN
	}

    return todoOk;
}

//				CONTROLLERS DE ID
int obtainID(int* id)
{
	int todoOk = 0;
	int newID;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","rb"); //OPEN FILE
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newID);//LEO LA ID
		*id = newID;
		fclose(pFile); //IF CAN BE OPENED THEN CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}

int upgradeID(int id)
{
	int nextID = ++id; //UPGRADE'S ID
	int todoOk = 0;
	FILE* pFile;
	pFile = fopen("ultimaID.bin","wb"); //OPEN TXT
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",nextID);//LA ESCRIBO EN EL ARCHIVO
		fclose(pFile); //IF CAN BE OPENED THE CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}


int controller_addPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk=0;

	Passenger *pAuxPassenger;
	pAuxPassenger = Passenger_new();
	char confirmation;

	//AUXILIARIES
	int auxId;
	char auxName[50];
	char auxLastName[50];
	char auxCodeFlight[8];
	int auxTypePassenger;
	float auxPrice;
	int auxStatusFlight;

	if(pArrayListPassenger!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                           PASSENGER ADD                                  |\n");
		printf("__________________________________________________________________________|");
		obtainID(&auxId);
		utn_getNombre(auxName, 48, "\nENTER PASSENGER NAME'S: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.] ", 50);
		convertFirstLetterStringUpper(auxName);

		utn_getNombre(auxLastName, 48, "\nENTER PASSENGER'S LAST NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]. ", 50);
		convertFirstLetterStringUpper(auxLastName);

		utn_getNumero(&auxTypePassenger, "\nENTER TYPE PASSENGER (1-ECONOMIC,2-FIRST CLASS,3-CREW MEMBER,4-EXECUTIVE CLASS): ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 4, 50);

		getValidStringAlpha("\nENTER PASSENGER'S FLIGHT CODE (7 VALUES): ", "\n[INVALID VALUE, TRY AGAIN.] ", auxCodeFlight, 7, 7);
		strupr(auxCodeFlight);
		utn_getNumeroFlotante(&auxPrice, "\nENTER THE PRICE OF THE FLIGHT (10000-500000): ", "\n[INVALID VALUE, TRY AGAIN.]", 10000, 500000, 50);

		utn_getNumero(&auxStatusFlight, "\nENTER STATUS FLIGHT (1-LANDED,2-ON TIME,3-IN FLIGHT,4-DELAYED): ", "\n[INVALID VALUE, TRY AGAIN.]", 1, 4, 50);

		getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO ADD THE PASSENGER (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
		if(confirmation=='s')
		{
			if(pAuxPassenger!=NULL)//UPDATE VALUES
			{
				Passenger_setId(pAuxPassenger, auxId);
				Passenger_setNombre(pAuxPassenger, auxName);
				Passenger_setApellido(pAuxPassenger, auxLastName);
				Passenger_setPrecio(pAuxPassenger, auxPrice);
				Passenger_setCodigoVuelo(pAuxPassenger, auxCodeFlight);
				Passenger_setTipoPasajero(pAuxPassenger, auxTypePassenger);
				Passenger_setStatusFlight(pAuxPassenger, auxStatusFlight);
				ll_add(pArrayListPassenger, pAuxPassenger);//ADDS THEM TO THE LIST
				upgradeID(auxId);//UPGRADE PASSENGER'S ID
				todoOk=1;
			}
		}
		else
		{
			printf("\nTHE ADDITION HAS BEEN CANCELLED!\n");
			todoOk=1;
		}

	}
    return todoOk;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	Passenger *pAuxPassenger;

	if(pArrayListPassenger==NULL)
	{
		printf("\nNO PASSENGERS REGISTERED!");
	}
	else
	{
		printf("\n\n");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|						       PASSENGERS LIST                                                                                        ");
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|  ID |	    NAME       |	  LAST NAME       |     PRICE       |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
		printf("|-----|----------------|--------------------------|-----------------|--------------------------|---------------------|-----------------|\n");
		todoOk=1;
		for(int i=0;i<ll_len(pArrayListPassenger);i++)
		{
			pAuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_ShowOnlyOne(pAuxPassenger);
		}

	}
    return todoOk;
}

int controller_selectMenuOption()//USER CAN MODIFY EVERYTHING BESIDES STATUS FLIGHT!
{
	int opcion;

	printf("____________________________");
	printf("\n|1)NAME                    |\n|"
			"2)LAST NAME               |\n|"
			"3)FLIGHT CODE             |\n|"
			"4)FLIGHT PRICE            |\n|"
			"5)TYPE PASSENGER          |\n|"
			"6)EXIT                    |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nENTER OPTION: ", "\n[INVALID VALUE, PLEASE TRY AGAIN.]", 1, 6, 50);
	return opcion;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	//AUXILIARIES
	Passenger *pAuxPassenger;
	int auxTypePassenger;
	char auxName[50];
	char auxLastName[50];
	char auxFlightCode[8];
	float auxPrice;

	int index;
	int maxId;
	int idSearch;
	char confirmation;

	if(pArrayListPassenger!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                      PASSENGER MODIFICATION                              |\n");
		printf("__________________________________________________________________________|");
		obtainID(&maxId);
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&idSearch, "\nENTER PASSENGER IDs TO MODIFY: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 0, (maxId-1), 50);

		index = Passenger_searchForId(pArrayListPassenger, idSearch);

		if(index==1)
		{
			printf("\n THERE IS NO PASSENGER WITH ID Nº%d",idSearch);
		}
		else
		{
			pAuxPassenger = ll_get(pArrayListPassenger, index);

			printf("\n\n");
			printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|						         PASSENGERS LIST                                                                                        ");
			printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|  ID |	    NAME       |	  LAST NAME       |     PRICE       |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
			printf("|-----|----------------|--------------------------|-----------------|--------------------------|---------------------|-----------------|\n");
			Passenger_ShowOnlyOne(pAuxPassenger);//SHOW THE PASSENGER

			switch(controller_selectMenuOption())
			{
				case 1:
					utn_getNombre(auxName, 48, "\nENTER THE PASSENGER'S NEW NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]  ", 50);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PASSENGER'S NAME (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
					if(confirmation=='s')
					{
						convertFirstLetterStringUpper(auxName);
						printf("\nPASSENGER NAME HAS BEEN UPDATED TO %s\n",auxName);
						Passenger_setNombre(pAuxPassenger, auxName);
					}
					else
					{
						printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
					}
					todoOk=1;
					system("Pause");
				break;
				case 2:
					utn_getNombre(auxLastName, 48, "\nENTER THE PASSENGER'S NEW LAST NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]  ", 50);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PASSENGER'S LAST NAME (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
					if(confirmation=='s')
					{
						convertFirstLetterStringUpper(auxLastName);
						printf("\nPASSENGER LAST NAME HAS BEEN UPDATED TO %s\n",auxLastName);
						Passenger_setApellido(pAuxPassenger, auxLastName);
					}
					else
					{
						printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
					}
					todoOk=1;
					system("Pause");
				break;
				case 3://FLIGHT CODE
					getValidStringAlpha("\nENTER THE PASSENGER'S NEW FLIGHT CODE: ", "\n[INVALID VALUES, PLEASE TRY AGAIN] ", auxFlightCode, 7, 7);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PASSENGER'S FLIGHT CODE (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
					strupr(auxFlightCode);
					if(confirmation=='s')
					{
						printf("\nPASSENGER FLIGHT CODE HAS BEEN CHANGED FROM %s TO ",auxFlightCode);
						Passenger_setCodigoVuelo(pAuxPassenger, auxFlightCode);
						strupr(auxFlightCode);
						printf("%s\n",auxFlightCode);
					}
					else
					{
						printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
					}
					todoOk=1;
					system("Pause");
				break;
				case 4://FLIGHT PRICE
					utn_getNumeroFlotante(&auxPrice, "\nENTER THE PASSENGER'S NEW FLIGHT PRICE: ", "\n[INVALID VALUES, PLEASE TRY AGAIN]", 10000, 500000, 50);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PASSENGER'S FLIGHT PRICE (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
					if(confirmation=='s')
					{
						Passenger_setPrecio(pAuxPassenger, auxPrice);
						printf("\nPASSENGER FLIGHT PRICE HAS BEEN UPDATED TO $%.2f\n",auxPrice);
					}
					else
					{
						printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
					}
					todoOk=1;
					system("Pause");
				break;
				case 5://TYPE PASSENGER
					utn_getNumero(&auxTypePassenger,"\nENTER THE PASSENGER'S NEW TYPE PASSENGER (1-ECONOMIC,2-FIRST CLASS,3-CREW MEMBER,4-EXECUTIVE CLASS): ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 1, 4, 50);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE PASSENGER'S TYPE (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
					if(confirmation=='s')
					{
						Passenger_setTipoPasajero(pAuxPassenger, auxTypePassenger);
						printf("\nPASSENGER TYPE HAS BEEN UPDATED TO %d\n",auxTypePassenger);
					}
					else
					{
						printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
					}
					todoOk=1;
					system("Pause");
				break;
				case 6:
					printf("\nEXIT MENU MODIFICATIONS.....");
					system("Pause");
				break;
			}
		}
	}
    return todoOk;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	Passenger *pPassenger;

	int index;
	int idPassenger;
	int obtainedID;
	char confirmation;
	int maxID;
	obtainID(&maxID);
	if(pArrayListPassenger!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                        PASSENGER REMOVE                                  |\n");
		printf("__________________________________________________________________________|");
		controller_ListPassenger(pArrayListPassenger);//PRINT LIST
		utn_getNumero(&idPassenger, "\nENTER THE PASSENGER'S ID THAT YOU WANT TO REMOVE FROM THE LIST: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, (maxID-1), 500);

		index = Passenger_searchForId(pArrayListPassenger, idPassenger);//VERIFYING THAT THE ID EXISTS AND WHERE IT IS LOCATED

		pPassenger = ll_get(pArrayListPassenger, index); //GET THE ELEMENT FROM THE LIST
		Passenger_getId(pPassenger, &obtainedID); //GET THE ID

		if(obtainedID == idPassenger)
		{
			printf("\n\n");
			printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|						             PASSENGERS LIST                                                                                        ");
			printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|  ID |	    NAME       |	  LAST NAME       |     PRICE       |       CODE FLIGHT        |    TYPE PASSENGER   |   STATUS FLIGHT |\n");
			printf("|-----|----------------|--------------------------|-----------------|--------------------------|---------------------|-----------------|\n");
			Passenger_ShowOnlyOne(pPassenger);
			getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO REMOVE THE PASSENGER FROM THE LIST (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN PRESSING (S/N): ");
			if(confirmation=='s')
			{
				ll_remove(pArrayListPassenger, index);//PASAR INDICE A ll_remove
				Passenger_delete(pPassenger);
				printf("\nTHE PASSENGER HAS BEEN REMOVED SUCCESSFULLY!");
			}
			else
			{
				printf("\nTHE PASSENGER'S REMOVAL HAS BEEN CANCELLED!");
			}
			todoOk=1;
		}
	}
    return todoOk;
}


int controller_showOptionMenuSort()
{
	int opcion;
	printf("\n___________________________________________________");
	printf("\n                                                   |");
	printf("\n            SORT MENU                              |\n");
	printf("___________________________________________________|\n");
	printf("________________________");
	printf("\n|1)BY NAME              |\n|"
			"2)BY LAST NAME         |\n|"
			"3)BY PRICE             |\n|"
			"4)BY TYPE PASSENGER    |\n|"
			"5)BY STATUS FLIGHT     |\n|"
			"6)BY CODE FLIGHT       |\n");
	printf("|_______________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN] ", 1, 6, 10);

	return opcion;
}



int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	if(pArrayListPassenger!=NULL)
	{
		switch(controller_showOptionMenuSort())
		{
			case 1:
				printf("\n\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByName, 1);
				printf("\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 2:
				printf("\n\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByLastName, 1);
				printf("\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 3:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByPrice, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 4:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByTypePassenger, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 5:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByStatusFlight, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 6:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListPassenger, Passenger_sortByCodeFlight, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
		}
		todoOk=1;
	}
	return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;
	Passenger *pAuxPassenger;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"wb");//OPEN FILE AS BINARY

		for(int i=0;i<ll_len(pArrayListPassenger);i++)
		{
			pAuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);//CAST IF ERROR
			fwrite(pAuxPassenger,sizeof(Passenger),1,pFile);//WRITE ON THE FILE
		}
		fclose(pFile);//CLOSE FILE
		ll_clear(pArrayListPassenger);//CLEAR LIST
		todoOk=1;
	}
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int i;

	FILE* fpArchivo;

	Passenger *pPassenger;
	int id;
	char name[5000];
	char lastName[5000];
	char flightCode[1000];
	int typePassenger;
	float flightPrice;
	int statusFlight;
	int len_ll;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		//ABRIMOS ARCHIVO:
		//fopen RECIBE EL ARCHIVO Y EL MODO
		fpArchivo = fopen(path,"w");//LA RUTA Y COMO LO ABRE EN ESTE CASO COMO TXT

		if(fpArchivo!=NULL)
		{//SI ABRI EL ARCHIVO TODO OK
			retorno=0;
			len_ll = ll_len(pArrayListPassenger);
			for(i=0;i<len_ll;i++)
			{
				//CARGAMOS INFORMACION MEDIANTE GETTERS
            	pPassenger=(Passenger*)ll_get(pArrayListPassenger,i);
                Passenger_getId(pPassenger, &id);
                Passenger_getNombre(pPassenger, name);
                Passenger_getApellido(pPassenger, lastName);
                Passenger_getPrecio(pPassenger, &flightPrice);
                Passenger_getCodigoVuelo(pPassenger, flightCode);
                Passenger_getTipoPasajero(pPassenger, &typePassenger);
                Passenger_getStatusFlight(pPassenger, &statusFlight);
				fprintf(fpArchivo,"%d,%s,%s,%f,%s,%d,%d\n",id,name,lastName,flightPrice,flightCode,typePassenger,statusFlight);
			}
		}
			//CERRAMOS ARCHIVO Y LO GUARDAMOS!
			fclose(fpArchivo);
	}
	return retorno;
}




