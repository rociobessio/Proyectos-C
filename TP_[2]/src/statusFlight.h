

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct{

	int id;
	char descripcion[20];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */

/// @brief LISTA LOS IDs y SU DESCRIPCION
/// @param status PUNTERO al array de tipos de pasajeros
/// @param tam int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int listarStatusFlight(eStatusFlight status[], int tam);

/// @brief CARGA/MODIFICA EL INT DE STATUS FLIGHT A UNA STRING
/// @param status PUNTERO al array de tipos de pasajeros
/// @param tam int array tamaño
/// @param id int la id que representa
/// @param descripcion char lo qye representa como string
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int cargarDescripcionStatus(eStatusFlight status[], int tam, int id,char descripcion[]);
