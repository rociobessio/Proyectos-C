#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

#ifndef PRINCIPALMENU_H_
#define PRINCIPALMENU_H_

#endif /* PRINCIPALMENU_H_ */

/**
 * @fn void goingToMainMenu()
 * @brief LLEVA AL USUARIO AL TP_3 LIMPIANDO EL MAIN
 *
 */
void goingToMainMenu();

/**
 * @fn int menu()
 * @brief MUESTRA EL MENU PRINCIPAL CON LAS OPCIONES
 *
 * @return opcion int
 */
int menu();

/**
 * @brief 	Puntero a funcion, donde se cargan parametros, mensajes de error y exito y actualiza un puntero.
 * @param messageError1
 * @param messageError2
 * @param messageSucess
 * @param flag
 * @param flagValue
 * @param NewflagValue
 * @param path
 * @param array
 * @param pFunction
 */
void pFunctionCheckValues(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
	int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*));


/**
 * @brief 	Puntero a funcion, donde se cargan parametros, mensajes de error y exito.
 * @param messageError1
 * @param messageError2
 * @param messageSucess
 * @param flag
 * @param flagValue
 * @param array
 * @param pFunction
 */
void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
				LinkedList* array,int(*pFunction)(LinkedList*));
