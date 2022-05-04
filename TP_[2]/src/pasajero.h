
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "utn.h"
#include "menuPrincipal.h"
#include "statusFlight.h"
#include "typePassenger.h"

#ifndef PASAJERO_H_
#define PASAJERO_H_




typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

#endif /* PASAJERO_H_ */
/// @brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
///			(isEmpty) en TRUE en todas las posiciones del array.					2.1
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int initPassanger(ePassenger list[], int len);


/// @brief Busca un lugar libre dentro del array
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int searchFreeSpacePassenger(ePassenger list[], int len);

/// @brief Agrega en un array de pasajero existente los valores recibidos como parametros en la
/// 		primera posicion libre.													2.2
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param id int* puntero al id
/// @param name char al campo de nombre
/// @param lastname char campo de apellido
/// @param price float precio del vuelo
/// @param flycode char codigo de vuelo
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 1 si todoOk
int addPassenger(ePassenger* list,int len,char name[],char lastName[],float price,char flycode[],int typePassenger,int statusFlight,int id,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger);

/// @brief Busca un pasajero recibiendo como parametro de busqueda su ID			2.3
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param id int id ingresada a buscar
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int findPassengerById(ePassenger list[], int len,int pId,int* pIndex);



/// @brief Remueve de MANERA LOGICA a un pasajero, recibiendo como parametro su ID	2.4
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param id int id ingresada a buscar
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int removePassenger(ePassenger list[],int len,int id,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger);


/// @brief MODIFICA EL CAMPO DE un pasajero
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int modifyPassenger(ePassenger list[], int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger2[],int tamPassenger);


/// @brief HARDCODEO DE PASAJEROS
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param cant int cantidad de pasajeros a mostrar en menu
/// @param id int* PUNTERO a las ids
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int altaForzadaPassengers(ePassenger* list, int len, int cant,int* id);


//INFORMES:

/// @brief Ordena el array de pasajeros por apellido y tipo de pasajero 	2.5
///	de forma ascendente (1) o descendente (0).
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param order int criterio de ordenamiento
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int sortPassengers(ePassenger* list, int len, int order);

/// @brief ES UN SUBMENU CON LOS ORDENAMIENTOS
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int submenueInform(ePassenger list[],int len,eStatusFlight status[], int tam_status,eTypeFlight typePassenger[],int tamPassenger);


/// @brief MUESTRA A UN PASAJERO
/// @param list PUNTERO al array de pasajeros
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
void showOnePassenger(ePassenger list,eStatusFlight status[],int tam,eTypeFlight typePassenger[],int tamPassenger);


/// @brief Imprime el array de pasajeros de forma encolumnada.				2.6
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
void printPassengers(ePassenger list[], int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger);

//																			2.7
/// @brief Ordena el array de pasajeros por PRECIO DE VUELO
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param order int criterio de ordenamiento
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int sortPassengersByPrice(ePassenger list[],int len,float* acumPrecio,int* cantPassengers, int* contPassengerSuperior,float* promedioPrecios);

//																			2.7
/// @brief Ordena el array de pasajeros por codigo de vuelo y estado de vuelo
/// @param list PUNTERO al array de pasajeros
/// @param len int array tamaño
/// @param order int criterio de ordenamiento
/// @param status eStatusFlight al array de status
/// @param tam_status int array tamaño
/// @param typePassenger2 PUNTERO al array de tipos de pasajeros
/// @param tamPassenger int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int sortPassengersByCode(ePassenger* list,int len,eStatusFlight status[],int tam_status,eTypeFlight typePassenger[],int tamPassenger);
