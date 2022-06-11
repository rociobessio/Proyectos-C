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
 * @brief Recibe mensajes de error, de exito, recibe las banderas pertinentes para verificar los valores, recibe como parametro ademas
 * 		  una funcion.
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
