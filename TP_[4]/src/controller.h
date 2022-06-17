#include "../inc/LinkedList.h"
#include "utn.h"
#include "Alumno.h"
#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

//LEGAJOS
/**
 * @fn int saveAsBinary_LastLegajo(FILE*, LinkedList*, int*)
 * @brief RECORRE LA LISTA BUSCANDO EL LEGAJO MAS ALTO
 *
 * @param pFile
 * @param pArrayListAlumnos
 * @param maxLegajo
 * @return
 */
int saveAsBinary_LastLegajo(FILE* pFile, LinkedList* pArrayListAlumnos,int* maxLegajo);
/**
 * @fn int controller_saveBinaryLastLegajo(FILE*, char*, LinkedList*)
 * @brief GUARDA EL ULTIMO LEGAJO EN MODO BINARIO
 *
 * @param pFile
 * @param path
 * @param pArrayListAlumnos
 * @return
 */
int controller_saveBinaryLastLegajo(FILE* pFile,char* path, LinkedList* pArrayListAlumnos);
/**
 * @fn int obtainLegajo(int*)
 * @brief ABRE EL ARCHIVO DEL ULTIMO LEGAJO Y LO OBTIENE
 *
 * @param legajo
 * @return
 */
int obtainLegajo(int* legajo);
/**
 * @fn int upgradeLegajo(int)
 * @brief INCREMETA LOS LEGAJOS
 *
 * @param legajo
 * @return
 */
int upgradeLegajo(int legajo);

//LOAD
/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief CARGA UN ARCHIVO EN MODO TEXTO
 *
 * @param path
 * @param pArrayListAlumnos
 * @return
 */
int controller_loadFromText(char* path , LinkedList* pArrayListAlumnos);
/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief CARGA UN ARCHIVO EN MODO BINARIO
 *
 * @param path
 * @param pArrayListAlumnos
 * @return
 */
int controller_loadFromBinary(char* path , LinkedList *pArrayListAlumnos);

//ALUMNOS CONTROLLERS
/**
 * @fn int controller_addAlumno(LinkedList*)
 * @brief ANIADE A LA LISTA UN NUEVO ALUMNO
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_addAlumno(LinkedList *pArrayListAlumnos);
/**
 * @fn int controller_ListAlumnos(LinkedList*)
 * @brief LISTA A TODOS LOS ALUMNOS
 *
 * @param pArrayListAlumno
 * @return
 */
int controller_ListAlumnos(LinkedList* pArrayListAlumno);
/**
 * @fn int controller_selectMenuOption()
 * @brief MENU PARA SELECCIONAR UNA MODIFICACION
 *
 * @return
 */
int controller_selectMenuOption();
/**
 * @fn int controller_editAlumnos(LinkedList*)
 * @brief CONTROLLER PARA EDITAR A UN ALUMNO
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_editAlumnos(LinkedList* pArrayListAlumnos);
/**
 * @fn int controller_removeAlumno(LinkedList*)
 * @brief CONTROLLER PARA ELIMINAR A UN ALUMNO
 *
 * @param pArrayListAlumno
 * @return
 */
int controller_removeAlumno(LinkedList* pArrayListAlumno);

//SORT MENU
/**
 * @fn int controller_showOptionMenuSort()
 * @brief MUESTRA LAS OPCIONES DEL SORT
 *
 * @return
 */
int controller_showOptionMenuSort();
/**
 * @fn int controller_sortAlumnos(LinkedList*)
 * @brief SE ENCARGA DE LLAMAR A LAS FUNCIONES PARA HACER EL SORT
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_sortAlumnos(LinkedList* pArrayListAlumnos);

//FILTRAR MENU
/**
 * @fn int controller_showOptionMenuFilter()
 * @brief MUESTRA OPCIONES PARA HACER LISTAS FILTRADAS
 *
 * @return
 */
int controller_showOptionMenuFilter();
/**
 * @fn int controller_FilterAlumnos(LinkedList*)
 * @brief LLAMA A LAS FUNCIONES ELEGIDAS PARA HACER LOS FILTROS
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_FilterAlumnos(LinkedList* pArrayListAlumnos);

//GUARDAR
/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief GUARDA UN ARCHIVO EN MODO BINARIO
 *
 * @param path
 * @param pArrayListAlumnos
 * @return
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListAlumnos);
/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief GUARDA UN ARCHIVO EN MODO TEXTO
 *
 * @param path
 * @param pArrayListAlumnos
 * @return
 */
int controller_saveAsText(char* path , LinkedList* pArrayListAlumnos);

//OTROS
/**
 * @fn int controller_createANewSublist(LinkedList*)
 * @brief FUNCION QUE CREA UNA NUEVA SUB LISTA
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_createANewSublist(LinkedList* pArrayListAlumnos);
/**
 * @fn int controller_MakeAPush(LinkedList*)
 * @brief HACE UN PUSH ENTRE POSICIONES INDICADAS POR EL USUARIO
 *
 * @param pArrayListAlumnos
 * @return
 */
int controller_MakeAPush(LinkedList* pArrayListAlumnos);
