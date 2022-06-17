/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Alumno.h"
#include "parser.h"
#include "controller.h"

#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


#define STATE_FILE_OPEN 1
#define STATE_FILE_CLOSED 0

int menu()
{
	int opcion;

	printf("\n__________________________________________________________________________");
	printf("\n                                                                          |");
	printf("\n                       WELCOME TO THE UTN                                 |\n");
	printf("__________________________________________________________________________|\n");
	printf("_________________________________________________________________________________");
	printf("\n|1)LOAD THE STUDENTS DATA FROM THE FILE alumnos.csv (IN TEXT MODE)              |\n|"
			"2)LOAD THE STUDENTS DATA FROM THE FILE alumnos.csv (IN BINARY MODE)            |\n|"
			"3)ADD STUDENT                                                                  |\n|"
			"4)MODIFY STUDENT                                                               |\n|"
			"5)REMOVE STUDENT                                                               |\n|"
			"6)LIST STUDENTS                                                                |\n|"
			"7)SORT STUDENTS                                                                |\n|"
			"8)CLONE LIST STUDENTS                                                          |\n|"
			"9)FILTER LIST STUDENTS                                                         |\n|"
			"10)DOES THE CLONED LIST CONTAINS ALL THE ELEMENTS FROM THE MAIN LIST?          |\n|"
			"11)CREATE A NEW SUBLIST                                                        |\n|"
			"12)MAKE A PUSH ON THE LIST                                                     |\n|"
			"13)SAVE THE STUDENTS DATA FROM A FILE (IN TEXT MODE)                           |\n|"
			"14)SAVE THE STUDENTS DATA FROM A FILE (IN BINARY MODE)                         |\n|"
			"15)SHOW TESTING LINKEDLIST                                                     |\n|"
			"16)EXIT APP                                                                    |\n");
	printf("|_______________________________________________________________________________|");
	utn_getNumero(&opcion, "\nENTER AN OPTION: ", "\n[INVALID VALUE, TRY AGAIN.] ", 1, 16, 10);
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

int main(void)
{
	setbuf(stdout,NULL);


	char confirmation = 'n';
	int fileState = 0;
	int binaryState=0;
	char path[50000];
	int flag = 0;

	LinkedList* clonarListaAlumnos = ll_newLinkedList(); //creo nueva lista

    LinkedList* listaAlumnos = ll_newLinkedList(); //creo nueva lista
    //validar q no sea NULL
    if(listaAlumnos!=NULL)
    {
    	 if(ll_isEmpty(listaAlumnos)){//se verifica que la lista este vacia...
    	    	printf("\n[LISTA INICIALIZADA!]");
    	    }

    	    do
    	    {
    	    	limpioPantalla();
    	    	switch(menu())
    	    	{
    				case 1://ABRIR ARCHIVO DE TEXTO
    					limpioPantalla();
    					if(controller_loadFromText("alumnos.csv", listaAlumnos) == 1)
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
    				case 2://ABRIR ARCHIVO BINARIO
    					limpioPantalla();
    					if(binaryState==0)
    					{
    						printf("\nBEFORE LOADING THE FILE IN BINARY MODE YOU NEED TO OPEN IT IN TEXT MODE AND SAVE IT IN BINARY TO BE ABLE TO USE IT!\n");
    					}
    					else
    					{
    						if(controller_loadFromBinary("alumnos.bin", listaAlumnos) == 1)
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
    				case 3://ANIADIR UN ALUMNO
    					limpioPantalla();
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR WHILE TRYING TO ADD THE STUDENT! ",
    							"\nYOU HAVE EXITED THE ADD!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_addAlumno);
    					system("Pause");
    				break;
    				case 4://EDITAR UN ALUMNO
    					limpioPantalla();
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR WHILE TRYING TO MODIFY THE STUDENT! ",
    							"\nYOU HAVE EXITED THE MODIFICATIONS MENU!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_editAlumnos);
    					system("Pause");
    				break;
    				case 5://ELIMINAR UN ALUMNO
    					limpioPantalla();
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR WHILE TRYING TO REMOVE THE STUDENT! ",
    							"\nYOU HAVE EXITED THE REMOVAL MENU!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_removeAlumno);
    					system("Pause");
    				break;
    				case 6://LISTAR A LOS ALUMNOS
    					limpioPantalla();
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR TRYING TO LIST THE STUDENTS, TRY AGAIN! ",
    							"\nTHE LIST OF STUDENTS HAS BEEN SHOWED SUCCESFULLY!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_ListAlumnos);
    					system("Pause");
    				break;
    				case 7://ORDENAR A LOS ALUMNOS
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR TRYING TO SORT THE STUDENTS, TRY AGAIN! ",
    							"\nTHE STUDENTS HAVE BEEN SORTED SUCCESFULLY!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_sortAlumnos);
    				break;
    				case 8://CLONAR LA LISTA
    					clonarListaAlumnos = ll_clone(listaAlumnos);
    					if(clonarListaAlumnos==NULL)
    					{
    						printf("\nTHERE WAS AN ERROR WHILE TRYING TO CLONE THE LIST!");
    						ll_deleteLinkedList(clonarListaAlumnos);
    					}
    					else
    					{
							getValidStringAlpha("\nENTER THE FILE'S NAME: ", "\n[INVALID VALUES, TRY AGAIN]\n", path, 3, 15);
    						controller_ListAlumnos(clonarListaAlumnos);
    						printf("\nTHE LIST HAS BEEN CLONED AND SAVED SUCCESFULLY!\n");
    						controller_saveAsText(path, clonarListaAlumnos);
    						flag=1;
    					}
    					system("Pause");
    				break;
    				case 9://FILTRAR A LOS ALUMNOS
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR TRYING TO SORT THE STUDENTS, TRY AGAIN! ",
								"\nTHE STUDENTS HAVE BEEN FILTERED SUCCESFULLY!",
								&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_FilterAlumnos);
    					system("Pause");
    				break;
    				case 10://LA LISTA CLONADA CONTIENE A TODOS LOS ELEMENTOS DE LA PRINCIPAL?
    					if(flag==1)
    					{
    						if(ll_containsAll(clonarListaAlumnos,listaAlumnos)==1)
    						{
    							printf("\nTHE CLONED LIST CONTAINS ALL THE ELEMENTS!\n");
    						}
    						else
    						{
    							printf("\nTHE CLONED LIST DOESN'T CONTAINS ALL THE ELEMENTS\n");
    						}
    					}
    					else
    					{
    						printf("\nFIRST YOU NEED TO CLONE THE LIST!\n");
    					}
    					system("Pause");
    				break;
    				case 11://CREAR UNA SUB LISTA
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR WHILE TRYING TO MAKE THE SUBIST, TRY AGAIN! ",
								"\nYOU HAVE EXITED THE SUB LIST MENU!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_createANewSublist);
    					system("Pause");
    				break;
    				case 12://HACER UN PUSH
    					pFunction("\nYOU NEED TO LOAD THE FILE FIRST!",
    							"\nTHERE WAS AN ERROR WHILE TRYING TO PUSH, TRY AGAIN! ",
								"\nYOU HAVE EXITED THE PUSH SECTION!",
    							&fileState, STATE_FILE_CLOSED, listaAlumnos, controller_MakeAPush);
    					system("Pause");
    				break;
    				case 13://GUARDAR EN FORMATO TXT
    					limpioPantalla();
    					if(fileState==1)
    					{
    						if(!controller_saveAsText("alumnos.csv", listaAlumnos))//"alumnos.csv"
    						{
    							fileState = 0;
    							printf("\nTHE FILE HAS BEEN CLOSED AND SAVED SUCCESSFULLY IN TEXT MODE!\n");
    						}
    						else
    						{
    							printf("\nERROR WHILE TRYING TO SAVE THE FILE!\n");
    						}
    					}
    					else
    					{
    						printf("\nYOU NEED TO LOAD THE FILE FIRST!\n");
    					}
    					system("Pause");
    				break;
    				case 14://GUARDAR EN BINARIO
    					limpioPantalla();
    					if(fileState==1)
    					{
    						if(controller_saveAsBinary("alumnos.bin", listaAlumnos)==1)
    						{
    							fileState = 0;
    							printf("\nTHE FILE HAS BEEN CLOSED AND SAVED SUCCESSFULLY IN BINARY MODE!\n");
    							binaryState=1;
    						}
    						else
    						{
    							printf("\nERROR WHILE TRYING TO SAVE THE FILE!\n");
    						}
    					}
    					else
    					{
    						printf("\nYOU NEED TO LOAD THE FILE FIRST!\n");
    					}
    					system("Pause");
    				break;
    				case 15://TEST
    					startTesting(1);  // ll_newLinkedList [HECHA]
    					startTesting(2);  // ll_len [HECHA]
    				    startTesting(3);  // getNode - test_getNode [HECHA]
    					startTesting(4);  // addNode - test_addNode [HECHA]
    					startTesting(5);  // ll_add [HECHA]
    					startTesting(6);  // ll_get [HECHA]
    					startTesting(7);  // ll_set [HECHA]
    					startTesting(8);  // ll_remove [HECHA]
    					startTesting(9);  // ll_clear [HECHA]
    					startTesting(10); // ll_deleteLinkedList [HECHA]
    					startTesting(11); // ll_indexOf [HECHA]
    					startTesting(12); // ll_isEmpty [HECHA]
    					startTesting(13); // ll_push [HECHA]
    					startTesting(14); // ll_pop [HECHA]
    					startTesting(15); // ll_contains [HECHA]
    					startTesting(16); // ll_containsAll [HECHA]
    					startTesting(17); // ll_subList [HECHA]
    					startTesting(18); // ll_clone [HECHA]
    					startTesting(19); // ll_sort [HECHA]
    					system("Pause");
    				break;
    				case 16://SALIR DE LA APLICACION
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
    							ll_deleteLinkedList(listaAlumnos);//borro la lista
    							ll_deleteLinkedList(clonarListaAlumnos);
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

    return 0;
}

































