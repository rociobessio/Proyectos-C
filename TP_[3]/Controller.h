
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);///[DONE]

/**
 * @fn int controller_selectMenuOption()
 * @brief MUESTRA UN MENU DE OPCIONES DE LAS MODIFICACIONES DISPONIBLES
 *
 * @return la opcion int
 */
int controller_selectMenuOption();

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_showOptionMenuSort()
 * @brief MUESTRA UN SUBMENU DE OPCIONES PARA EL SORT
 *
 * @return opcion int
 */
int controller_showOptionMenuSort();

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

//CONTROLLERS DE  ID
/**
 * \brief Obtenemos una id
 * \param int* id POINTER TO ID
 * \return	Retorna 1 si pudo, sino 0.
 */
int obtainID(int* id);

/**
 * \brief UPGRADES THE IDs
 * \param int id
 * \return	Retorna 1 si pudo, sino 0.
 */
int upgradeID(int id);

/**
 * @fn int controller_saveBinaryLastId(FILE*, char*, LinkedList*)
 * @brief ESCRIBE LA ID MAXIMA DE LA LISTA EN BINARIO
 *
 * @param pFile
 * @param path
 * @param pArrayListPassenger
 * @return 1 si todo salio bien, 0 si ocurrio algo
 */
int controller_saveBinaryLastId(FILE* pFile,char* path, LinkedList* pArrayListPassenger);

/**
 * @fn int saveAsBinary_LastID(FILE*, char*, LinkedList*)
 * @brief GUARDA LA ID MAXIMA DE LA LISTA EN BINARIO!
 *
 * @param pFile
 * @param path
 * @param pArrayListPassenger
 * @return 1 si todo salio bien, 0 si ocurrio algo
 */
int saveAsBinary_LastID(FILE* pFile, LinkedList* pArrayListPassenger,int* maxID);




