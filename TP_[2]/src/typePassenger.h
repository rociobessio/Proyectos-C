

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_


typedef struct{

	int id;
	char descripcion[20];
}eTypeFlight;

#endif /* TYPEPASSENGER_H_ */

/// @brief CARGA/MODIFICA EL INT DE TYPEPASSENGER A UNA STRING
/// @param type PUNTERO al array de tipos de pasajeros
/// @param tam int array tamaño
/// @param id int la id que representa
/// @param descripcion char lo qye representa como string
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int cargarDescripcionStatusTypePassenger(eTypeFlight type[], int tam, int id,char descripcion[]);

/// @brief LISTA LOS IDs y SU DESCRIPCION
/// @param type PUNTERO al array de tipos de pasajeros
/// @param tam int array tamaño
/// @return -1 si hay error (Invalid length o NULL pointer), 0 si todoOk
int listarTypePassenger(eTypeFlight type[], int tam);
