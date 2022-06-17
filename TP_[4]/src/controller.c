
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/LinkedList.h"
#include "utn.h"
#include "Alumno.h"
#include "parser.h"


int saveAsBinary_LastLegajo(FILE* pFile, LinkedList* pArrayListAlumnos,int* maxLegajo)
{
    eAlumno* Alumno;

    int id;
    int len_LL;
    int todoOk = 0;
    int maxleg;
    int flag = 0;

    if(pFile != NULL && pArrayListAlumnos != NULL)
    {
        len_LL = ll_len(pArrayListAlumnos);

        for(int i=0; i<len_LL; i++)
        {
        	Alumno = ll_get(pArrayListAlumnos,i);
        	if(Alumno!=NULL)
        	{
                Alumno_getHigherLegajo(Alumno,&id);
                if(flag==0 || id>maxleg)
                {
                	maxleg = id;
                	flag=1;
                }
                todoOk = 1;
        	}
        }
    }
    *maxLegajo = maxleg;
    return todoOk;
}

int controller_saveBinaryLastLegajo(FILE* pFile,char* path, LinkedList* pArrayListAlumnos)
{
    int todoOk = 0;
    int maxLegajo;

    if(pFile !=NULL && saveAsBinary_LastLegajo(pFile,pArrayListAlumnos,&maxLegajo))
    {
        todoOk = 1;
        fprintf(pFile,"%d\n",maxLegajo+1);
    }
    return todoOk;
}

int controller_loadFromNewText(char* path , LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	FILE* pFile;//SAVE PASSENGERS
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "w");
	pFile2=fopen("ultimoLegajo.bin","wb");

	if(pFile != NULL)
	{
		parser_AlumnoFromText(pFile, pArrayListAlumnos);
		fclose(pFile);
		todoOk=1;
	}
	if(controller_saveBinaryLastLegajo(pFile2,"ultimoLegajo.bin", pArrayListAlumnos))
	{
		fclose(pFile2);
	}

    return todoOk;
}

int controller_loadFromText(char* path , LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	FILE* pFile;//SAVE PASSENGERS
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "r");
	pFile2=fopen("ultimoLegajo.bin","wb");

	if(pFile != NULL)
	{
		parser_AlumnoFromText(pFile, pArrayListAlumnos);
		fclose(pFile);
		todoOk=1;
	}
	if(controller_saveBinaryLastLegajo(pFile2,"ultimoLegajo.bin", pArrayListAlumnos))
	{
		fclose(pFile2);
	}

    return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList *pArrayListAlumnos)
{
	int todoOk=0;

	FILE* pFile;//SAVE PASSENGERS
	FILE* pFile2;//UPDATE NEXT ID

	pFile=fopen(path, "rb");//OPEN IN BINARY
	pFile2=fopen("ultimoLegajo.bin","wb");

	if(pFile != NULL)
	{
		parser_AlumnoFromBinary(pFile, pArrayListAlumnos);
		fclose(pFile);//CLOSE THE FILE
		todoOk=1;
	}

	if(controller_saveBinaryLastLegajo(pFile2,"ultimoLegajo.bin", pArrayListAlumnos))
	{
		fclose(pFile2);//CLOSE ID BIN
	}

    return todoOk;
}


//				CONTROLLERS DE LEGAJO
int obtainLegajo(int* legajo)
{
	int todoOk = 0;
	int newLegajo;
	FILE* pFile;
	pFile = fopen("ultimoLegajo.bin","rb"); //OPEN FILE
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newLegajo);//LEO LA ID
		*legajo = newLegajo;
		fclose(pFile); //IF CAN BE OPENED THEN CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}

int upgradeLegajo(int legajo)
{
	int nextLegajo = ++legajo; //UPGRADE'S ID
	int todoOk = 0;
	FILE* pFile;
	pFile = fopen("ultimoLegajo.bin","wb"); //OPEN
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",nextLegajo);//LA ESCRIBO EN EL ARCHIVO
		fclose(pFile); //IF CAN BE OPENED THE CLOSE IT AT THE END
		todoOk = 1;
	}
	return todoOk;
}

int controller_addAlumno(LinkedList *pArrayListAlumnos)
{
	int todoOk=0;

	eAlumno *pAuxAlumno;
	pAuxAlumno = Alumno_new();
	char confirmation;

	//AUXILIARIES
	int auxLegajo;
	char auxName[50];
	char auxLastName[50];
	int materia;
	float promedio;

	if(pArrayListAlumnos!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                           STUDENT ADD                                    |\n");
		printf("__________________________________________________________________________|");
		obtainLegajo(&auxLegajo);
		utn_getNombre(auxName, 48, "\nENTER STUDENT NAME'S: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.] ", 50);
		convertFirstLetterStringUpper(auxName);

		utn_getNombre(auxLastName, 48, "\nENTER STUDENT'S LAST NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]. ", 50);
		convertFirstLetterStringUpper(auxLastName);

		utn_getNumero(&materia, "\nENTER SUBJECT (1-INGLES I,2-LABORATORIO I,3-PROGRAMACION I,4-SPD): ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 4, 50);

		utn_getNumeroFlotante(&promedio, "\nENTER THE PROMEDY OF THE STUDENT (1-10): ", "\n[INVALID VALUE, TRY AGAIN.]", 1, 10, 50);

		getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO ADD THE STUDENT (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
		if(confirmation=='s')
		{
			if(pAuxAlumno!=NULL)//UPDATE VALUES
			{
				Alumno_setLegajo(pAuxAlumno, auxLegajo);
				Alumno_setNombre(pAuxAlumno, auxName);
				Alumno_setApellido(pAuxAlumno, auxLastName);
				Alumno_setPromedio(pAuxAlumno, promedio);
				Alumno_setMateria(pAuxAlumno, materia);
				ll_add(pArrayListAlumnos, pAuxAlumno);//ADDS THEM TO THE LIST
				upgradeLegajo(auxLegajo);//UPGRADE STUDENT ID
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


int controller_ListAlumnos(LinkedList* pArrayListAlumno)
{
	int todoOk = 0;

	eAlumno *pAuxAlumno;
	int sizeOf;

	if(ll_isEmpty(pArrayListAlumno)==1)//si devuelve 1 no hay students en la lista
	{
		printf("\nNO STUDENTS REGISTERED!");
	}
	else
	{
		printf("\n\n");
		printf("|-----------------------------------------------------------------------------------------------|\n");
		printf("|				 STUDENTS LIST                                                  | \n");
		printf("|-----------------------------------------------------------------------------------------------|\n");
		printf("|  ID |	    NAME       |	  LAST NAME       |           SUBJECT        |   PROMEDY        |\n");
		printf("|-----|----------------|--------------------------|--------------------------|------------------|\n");
		todoOk=1;
		sizeOf = ll_len(pArrayListAlumno);
		for(int i=0;i<sizeOf;i++)
		{
			pAuxAlumno = (eAlumno*) ll_get(pArrayListAlumno, i);
			if(pAuxAlumno!=NULL)//PUEDE DEVOLVER NULL
			{
				Alumno_ShowOnlyOne(pAuxAlumno);
			}
		}
	}
    return todoOk;
}

int controller_selectMenuOption()//USER CAN MODIFY EVERYTHING BESIDES PROMEDY!
{
	int opcion;

	printf("____________________________");
	printf("\n|1)NAME                    |\n|"
			"2)LAST NAME               |\n|"
			"3)SUBJECT                 |\n|"
			"4)EXIT                    |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nENTER OPTION: ", "\n[INVALID VALUE, PLEASE TRY AGAIN.]", 1, 4, 50);
	return opcion;
}


int controller_editAlumnos(LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	//AUXILIARIES
	eAlumno *pAuxAlumno;
	int materia;
	char auxName[50];
	char auxLastName[50];

	int index;
	int maxId;
	int idSearch;
	char confirmation;

	if(pArrayListAlumnos!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                      STUDENT MODIFICATION                                |\n");
		printf("__________________________________________________________________________|");
		obtainLegajo(&maxId);
		controller_ListAlumnos(pArrayListAlumnos);
		utn_getNumero(&idSearch, "\nENTER STUDENT IDs TO MODIFY: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 1, (maxId-1), 50);

		index = Alumno_searchForLegajo(pArrayListAlumnos, idSearch);
		pAuxAlumno = ll_get(pArrayListAlumnos, index);
		if(ll_contains(pArrayListAlumnos, pAuxAlumno)==1)
		{
			printf("\n[THE STUDENT IS ON THE LIST!]");
			if(pAuxAlumno!=NULL)//VALIDO PORQUE PUEDE DEVOLVER NULL
			{
				printf("\n\n");
				printf("|-----------------------------------------------------------------------------------------------|\n");
				printf("|				 STUDENTS LIST                                                  | \n");
				printf("|-----------------------------------------------------------------------------------------------|\n");
				printf("|  ID |	    NAME       |	  LAST NAME       |           SUBJECT        |   PROMEDY        |\n");
				printf("|-----|----------------|--------------------------|--------------------------|------------------|\n");
				Alumno_ShowOnlyOne(pAuxAlumno);//SHOW THE PASSENGER

				switch(controller_selectMenuOption())
				{
					case 1:
						utn_getNombre(auxName, 48, "\nENTER THE STUDENT'S NEW NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]  ", 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE STUDENT'S NAME (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
						if(confirmation=='s')
						{
							convertFirstLetterStringUpper(auxName);
							printf("\nSTUDENT NAME HAS BEEN UPDATED TO %s\n",auxName);
							Alumno_setNombre(pAuxAlumno, auxName);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 2:
						utn_getNombre(auxLastName, 48, "\nENTER THE STUDENT'S NEW LAST NAME: ", "\n[ERROR ONLY LETTERS, A MAX OF 48 CHARACTERS & NO SPACES.]  ", 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE STUDENT'S LAST NAME (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
						if(confirmation=='s')
						{
							convertFirstLetterStringUpper(auxLastName);
							printf("\nSTUDENT LAST NAME HAS BEEN UPDATED TO %s\n",auxLastName);
							Alumno_setApellido(pAuxAlumno, auxLastName);
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 3:
						utn_getNumero(&materia, "\nENTER SUBJECT (1-INGLES I,2-LABORATORIO I,3-PROGRAMACION I,4-SPD): ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 4, 50);
						getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO CHANGE THE STUDENT'S SUBJECT (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN (S/N): ");
						if(confirmation=='s')
						{
							printf("\nTHE STUDENT'S SUBJECT HAS BEEN CHANGED! ");
						}
						else
						{
							printf("\nTHE MODIFICATION HAS BEEN CANCELLED!");
						}
						todoOk=1;
						system("Pause");
					break;
					case 4:
						printf("\nEXIT MENU MODIFICATIONS.....\n");
						todoOk=1;
						system("Pause");
					break;
				}
			}
		}
		else
		{
			printf("\n[THE STUDENT ISN'T ON THE LIST!]");
			todoOk=1;
		}
	}
    return todoOk;
}


int controller_removeAlumno(LinkedList* pArrayListAlumno)
{
	int todoOk=0;

	eAlumno *pAlumno;

	int index;
	int legajoAlumno;
	int obtainedLegajo;
	char confirmation;
	int maxLegajo;
	int indexToDelete;

	obtainLegajo(&maxLegajo);
	if(pArrayListAlumno!=NULL)
	{
		printf("\n__________________________________________________________________________");
		printf("\n                                                                          |");
		printf("\n                        STUDENT REMOVE                                    |\n");
		printf("__________________________________________________________________________|");
		controller_ListAlumnos(pArrayListAlumno);//PRINT LIST
		utn_getNumero(&legajoAlumno, "\nENTER THE PASSENGER'S ID THAT YOU WANT TO REMOVE FROM THE LIST: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, (maxLegajo-1), 500);

		index = Alumno_searchForLegajo(pArrayListAlumno, legajoAlumno);//VERIFYING THAT THE ID EXISTS AND WHERE IT IS LOCATED

		pAlumno = ll_get(pArrayListAlumno, index); //GET THE ELEMENT FROM THE LIST

		indexToDelete = ll_indexOf(pArrayListAlumno, pAlumno);//me devuelve la primer ocurrencia de ese elemento
		if(ll_contains(pArrayListAlumno, pAlumno)==1)
		{
			printf("\n[THE STUDENT IS ON THE LIST!]");

			if(pAlumno!=NULL)//ME PUEDE DEVOLVER NULL
			{
				Alumno_getLegajo(pAlumno, &obtainedLegajo); //GET THE ID

				if(obtainedLegajo == legajoAlumno)
				{
					printf("\n\n");
					printf("|-----------------------------------------------------------------------------------------------|\n");
					printf("|				 STUDENTS LIST                                                  | \n");
					printf("|-----------------------------------------------------------------------------------------------|\n");
					printf("|  ID |	    NAME       |	  LAST NAME       |           SUBJECT        |   PROMEDY        |\n");
					printf("|-----|----------------|--------------------------|--------------------------|------------------|\n");
					Alumno_ShowOnlyOne(pAlumno);
					getUserConfirmation(&confirmation, "\nDO YOU REALLY WANT TO REMOVE THE PASSENGER FROM THE LIST (S/N)?: ", "\nINVALID VALUE, PLEASE TRY AGAIN PRESSING (S/N): ");
					if(confirmation=='s')
					{
						ll_remove(pArrayListAlumno, indexToDelete);//paso esa primer ocurrencia para eliminarla
						if(pArrayListAlumno!=NULL)//ME PUEDE DEVOLVER NULL
						{
							Alumno_delete(pAlumno);
							printf("\nTHE PASSENGER HAS BEEN REMOVED SUCCESSFULLY!");
						}
					}
					else
					{
						printf("\nTHE PASSENGER'S REMOVAL HAS BEEN CANCELLED!");
					}
					todoOk=1;
				}
			}
		}
		else
		{
			printf("\n[THE STUDENT ISN'T ON THE LIST!]");
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
			"3)BY PROMEDY           |\n|"
			"4)BY SUBJECT           |\n");
	printf("|_______________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN] ", 1, 4, 10);

	return opcion;
}


int controller_sortAlumnos(LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	if(pArrayListAlumnos!=NULL)
	{
		switch(controller_showOptionMenuSort())
		{
			case 1:
				printf("\n\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListAlumnos,Alumnos_sortByName, 1);
				printf("\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 2:
				printf("\n\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListAlumnos, Alumnos_sortByLastName, 1);
				printf("\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 3:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListAlumnos, Alumno_sortByPromedio, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
			case 4:
				printf("\nPLEASE WAIT, THE LIST IS BEING SORTED...!\n");
				ll_sort(pArrayListAlumnos, Alumno_sortByMateria, 1);
				printf("\n\nNOW YOU CAN SEE THE LIST!\n");
				system("Pause");
			break;
		}
		todoOk=1;
	}
	return todoOk;
}



int controller_saveAsBinary(char* path , LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	FILE* pFile;
	eAlumno *pAuxAlumno;
	int sizeOfList;

	if(path!=NULL && pArrayListAlumnos!=NULL)
	{
		pFile = fopen(path,"wb");//OPEN FILE AS BINARY
		sizeOfList = ll_len(pArrayListAlumnos);
		for(int i=0;i<sizeOfList;i++)
		{
			pAuxAlumno = (eAlumno*) ll_get(pArrayListAlumnos, i);//CAST IF ERROR
			if(pAuxAlumno!=NULL)
			{
				fwrite(pAuxAlumno,sizeof(eAlumno),1,pFile);//WRITE ON THE FILE
			}
		}
		fclose(pFile);//CLOSE FILE
		ll_clear(pArrayListAlumnos);//CLEAR LIST
		todoOk=1;
	}
    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListAlumnos)
{
	int retorno=-1;
	int i;

	FILE* fpArchivo;

	eAlumno *pAlumno;
	int legajo;
	char name[5000];
	char lastName[5000];
	int materia;
	float promedio;
	int sizeOfList;

	if(pArrayListAlumnos != NULL && path != NULL)
	{
		//ABRIMOS ARCHIVO:
		//fopen RECIBE EL ARCHIVO Y EL MODO
		fpArchivo = fopen(path,"w");//LA RUTA Y COMO LO ABRE EN ESTE CASO COMO TXT

		if(fpArchivo!=NULL)
		{//SI ABRI EL ARCHIVO TODO OK
			retorno=0;
			sizeOfList = ll_len(pArrayListAlumnos);
			for(i=0;i<sizeOfList;i++)
			{
				//CARGAMOS INFORMACION MEDIANTE GETTERS
				pAlumno=(eAlumno*)ll_get(pArrayListAlumnos,i);
            	if(pAlumno!=NULL)//PUEDE DEVOLVER NULL
            	{
                    Alumno_getLegajo(pAlumno, &legajo);
                    Alumno_getNombre(pAlumno, name);
                    Alumno_getApellido(pAlumno, lastName);
                    Alumno_getPromedio(pAlumno, &promedio);
                    Alumno_getMateria(pAlumno, &materia);
    				fprintf(fpArchivo,"%d,%s,%s,%d,%f\n",legajo,name,lastName,materia,promedio);
            	}
			}
		}
			//CERRAMOS ARCHIVO Y LO GUARDAMOS!
			fclose(fpArchivo);
	}
	return retorno;
}


int controller_showOptionMenuFilter()
{
	int opcion;
	printf("\n___________________________________________________");
	printf("\n                                                   |");
	printf("\n            FILTER MENU                            |\n");
	printf("___________________________________________________|\n");
	printf("_______________________________");
	printf("\n|1)BY SUBJECT LABORATORIO      |\n|"
			"2)BY PROMEDY                  |\n|"
			"3)BY SPD & PROMEDY>=6         |\n");
	printf("|______________________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN] ", 1, 3, 10);

	return opcion;
}


int controller_FilterAlumnos(LinkedList* pArrayListAlumnos)
{
	int todoOk=0;
	char confirma;
	char path[1000];

	LinkedList* listaLabo = ll_newLinkedList();
	LinkedList* listaSpdPromedio = ll_newLinkedList();
	LinkedList* listaPromedio = ll_newLinkedList();

	if(pArrayListAlumnos!=NULL)
	{
		switch(controller_showOptionMenuFilter())
		{
			case 1:
				listaLabo = ll_filter(pArrayListAlumnos, filterByLaboratorio);
				if(listaLabo!=NULL)
				{
					controller_ListAlumnos(listaLabo);
					getUserConfirmation(&confirma, "\nDO YOU WISH TO SAVE THE FILE IN TXT MODE (S/N)?", "\n[INVALID VALUE, PLEASE TRY AGAIN]: ");
					if(confirma=='s')
					{
						getValidStringAlpha("\nPLEASE ENTER THE FILE NAME: ", "\n[INVALID LENGHT, TRY AGAIN] ", path, 3, 15);
						controller_saveAsText(path, listaLabo);
						printf("\nFILE GENERATED SUCCESSFULLY!\n");
					}
					else
					{
						printf("\nTHE FILE HASN'T BEEN SAVED!\n");
					}
					todoOk=1;
				}
			break;
			case 2:
				listaPromedio = ll_filter(pArrayListAlumnos, filterByPromedio);
				if(listaPromedio!=NULL)
				{
					controller_ListAlumnos(listaPromedio);
					getUserConfirmation(&confirma, "\nDO YOU WISH TO SAVE THE FILE IN TXT MODE (S/N)?", "\n[INVALID VALUE, PLEASE TRY AGAIN]: ");
					if(confirma=='s')
					{
						getValidStringAlpha("\nPLEASE ENTER THE FILE'S NAME: ", "\n[INVALID LENGHT, TRY AGAIN] ", path, 3, 15);
						controller_saveAsText(path, listaPromedio);
						printf("\nFILE GENERATED SUCCESSFULLY!\n");
					}
					else
					{
						printf("\nTHE FILE HASN'T BEEN SAVED!\n");
					}
					todoOk=1;
				}
			break;
			case 3:
				listaSpdPromedio = ll_filter(pArrayListAlumnos, filterBySPD);
				listaSpdPromedio = ll_filter(listaSpdPromedio, filterByPromedio);
				if(listaSpdPromedio!=NULL)
				{
					controller_ListAlumnos(listaSpdPromedio);
					getUserConfirmation(&confirma, "\nDO YOU WISH TO SAVE THE FILE IN TXT MODE (S/N)?", "\n[INVALID VALUE, PLEASE TRY AGAIN]: ");
					if(confirma=='s')
					{
						getValidStringAlpha("\nPLEASE ENTER THE FILE NAME: ", "\n[INVALID LENGHT, TRY AGAIN] ", path, 3, 15);
						controller_saveAsText(path, listaSpdPromedio);
						printf("\nFILE GENERATED SUCCESSFULLY!\n");
					}
					else
					{
						printf("\nTHE FILE HASN'T BEEN SAVED!\n");
					}
					todoOk=1;
				}
			break;
		}
	}
	return todoOk;
}

int controller_createANewSublist(LinkedList* pArrayListAlumnos)
{
	int todoOk=0;
	LinkedList* subList;

	char confirma;
	char path[5000];

	int maxId;

	int indexFrom;
	int idSearchFrom;

	int indexTo;
	int idSearchTo;

	if(pArrayListAlumnos!=NULL)
	{
		controller_ListAlumnos(pArrayListAlumnos);
		obtainLegajo(&maxId);
		utn_getNumero(&idSearchFrom, "\nPLEASE ENTER FROM WHERE YOU WANT TO CREATE A SUBLIST: ", "\n[INVALID VALUE, TRY AGAIN]: ", 1,(maxId-1) , 12);
		utn_getNumero(&idSearchTo, "\nPLEASE ENTER TO WHERE YOU WANT TO CREATE A SUBLIST: ", "\n[INVALID VALUE, TRY AGAIN]: ", 1,(maxId-1) , 12);

		indexFrom = Alumno_searchForLegajo(pArrayListAlumnos, idSearchFrom);
		indexTo = Alumno_searchForLegajo(pArrayListAlumnos, idSearchTo);

		if(indexFrom==-1)
		{
			printf("\nTHE INDEX FROM DOESN'T EXIT");
		}
		else if(indexTo==-1)
		{
			printf("\nTHE INDEX TO DOESN'T EXIT");
		}
		else
		{
			indexTo+=1;
			subList = ll_subList(pArrayListAlumnos, indexFrom, indexTo);
			if(subList!=NULL)
			{
				printf("\nTHE SUBLIST HAS BEEN CREATED!");
				controller_ListAlumnos(subList);
				getUserConfirmation(&confirma, "\nDO YOU WISH TO SAVE THE LIST (S/N)? ", "\nINVALID VALUE, TRY AGAIN (S/N): ");
				if(confirma=='s')
				{
					getValidStringAlpha("\nPLEASE ENTER THE FILE NAME: ", "\n[INVALID LENGHT, TRY AGAIN] ", path, 3, 15);
					if(controller_saveAsText(path, subList)==0)
					{
						printf("\nFILE GENERATED SUCCESSFULLY!\n");
					}
					else
					{
						printf("\nERROR WHILE TRYING TO SAVE THE NEW FILE!\n");
					}
				}
				else
				{
					printf("\nTHE FILE HASN'T BEEN SAVED!\n");
				}
				todoOk=1;
			}
		}

	}

	return todoOk;
}

int controller_MakeAPush(LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	//AUXILIARIES
	eAlumno *pAuxAlumno;
	eAlumno *pAuxAlumno2;

	int index;
	int maxId;
	int idSearch;
	int indexToPush;
	int auxIndexPush;

	if(pArrayListAlumnos!=NULL)
	{
		obtainLegajo(&maxId);
		controller_ListAlumnos(pArrayListAlumnos);
		utn_getNumero(&idSearch, "\nENTER STUDENT ID THAT YOU WANT TO MOVE: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 1, (maxId-1), 50);
		utn_getNumero(&indexToPush, "\nENTER THE INDEX IDs WHERE TO PUSH: ", "\n[INVALID VALUES, PLEASE TRY AGAIN.]", 1, (maxId-1), 50);

		index = Alumno_searchForLegajo(pArrayListAlumnos, idSearch);
		auxIndexPush = Alumno_searchForLegajo(pArrayListAlumnos, indexToPush);


		pAuxAlumno = ll_get(pArrayListAlumnos, index); //GET THE ELEMENT FROM THE LIST
		pAuxAlumno2 = ll_get(pArrayListAlumnos, auxIndexPush); //GET THE ELEMENT FROM THE LIST

		if(ll_contains(pArrayListAlumnos, pAuxAlumno)==0)
		{
			printf("\n[THE LIST DOESN'T CONTAINS A STUDENT WITH ID Nº%d]",idSearch);
			todoOk=1;
		}
		else if(ll_contains(pArrayListAlumnos, pAuxAlumno2)==0)
		{
			printf("\n[THE LIST DOESN'T CONTAINS AN STUDEN WITH INDEX Nº%d SO IT IS IMPOSIBLE TO PUSH IT]",indexToPush);
			todoOk=1;
		}
		else
		{
			indexToPush-=1;
			pAuxAlumno = ll_pop(pArrayListAlumnos, index);
			if(pAuxAlumno!=NULL)//VALIDO PORQUE PUEDE DEVOLVER NULL
			{
				ll_push(pArrayListAlumnos, indexToPush, pAuxAlumno);
				todoOk=1;
				controller_ListAlumnos(pArrayListAlumnos);
				printf("\nTHE PUSH HAS BEEN DONE!\n");
			}
		}
	}
    return todoOk;
}
