
#include "LinkedList.h"

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	int legajo;
	char nombre[50];
	char apellido[50];
	char sexo;
	float promedio;
	int materia;

}eAlumno;

//CONTRUCTORS
/**
 * @fn eAlumno Alumno_new*()
 * @brief ES EL CONSTRUCTOR DONDE PEDIMOS ESPACIO EN LA MEMORIA DINAMICA
 *
 * @return esa direccion que encontro
 */
eAlumno* Alumno_new();
/**
 * @fn eAlumno Alumno_newParametros*(char*, char*, char*, char*, char*, char*)
 * @brief ANIADE NUEVOS PARAMETROS A LOS ALUMNOS
 *
 * @param legajoStr
 * @param nombreStr
 * @param apellidoStr
 * @param materiaStr
 * @param promedioStr
 * @param sexoStr
 * @return
 */
eAlumno* Alumno_newParametros(char* legajoStr,char* nombreStr,char* apellidoStr,char* materiaStr,char* promedioStr);//LE AGREGUE apellidoStr y STATUSFKIGHT

//DESTRUCTOR
/**
 * @fn void Alumno_delete(eAlumno*)
 * @brief LO QUE HACE ES ELIMINAR A UN ALUMNO DE LA LISTA CON FREE();
 *
 * @param this
 */
void Alumno_delete(eAlumno* this);

//SETTERS
/**
 * @fn int Alumno_setLegajo(eAlumno*, int)
 * @brief SETTER DEL LEGAJO
 *
 * @param this
 * @param id
 * @return
 */
int Alumno_setLegajo(eAlumno* this,int legajo);//[HECHA]
/**
 * @fn int Alumno_setNombre(eAlumno*, char*)
 * @brief settea nombre del alumno
 *
 * @param this
 * @param nombre
 * @return
 */
int Alumno_setNombre(eAlumno* this,char* nombre);//[HECHA]
/**
 * @fn int Alumno_setApellido(eAlumno*, char*)
 * @brief settea un nombre
 *
 * @param this
 * @param apellido
 * @return
 */
int Alumno_setApellido(eAlumno* this,char* apellido);//[HECHA]
/**
 * @fn int Alumno_setSexo(eAlumno*, char*)
 * @brief setea sexo
 *
 * @param this
 * @param sexo
 * @return
 */
int Alumno_setSexo(eAlumno* this,char* sexo);//[HECHA]
/**
 * @fn int Alumno_setMateria(eAlumno*, int)
 * @brief setea materia
 *
 * @param this
 * @param materia
 * @return
 */
int Alumno_setMateria(eAlumno* this,int materia);//[HECHA]
/**
 * @fn int Alumno_setPromedio(eAlumno*, float)
 * @brief setea el promedio del alumno
 *
 * @param this
 * @param promedio
 * @return
 */
int Alumno_setPromedio(eAlumno* this,float promedio);//[HECHA]

//GETTERS
/**
 * @fn int eAlumno_getLegajo(eAlumno*, int*)
 * @brief  OBTIENE UN LEGAJO
 *
 * @param this
 * @param legajo
 * @return
 */
int Alumno_getLegajo(eAlumno* this,int* legajo);//[HECHA]
/**
 * @fn int Alumno_getHigherLegajo(eAlumno*, int*)
 * @brief obtiene el legajo mas alto de la lista
 *
 * @param this
 * @param legajo
 * @return
 */
int Alumno_getHigherLegajo(eAlumno* this,int* legajo);
/**
 * @fn int Alumno_getNombre(eAlumno*, char*)
 * @brief obtiene un nombre
 *
 * @param this
 * @param nombre
 * @return
 */
int Alumno_getNombre(eAlumno* this,char* nombre);//[HECHA]
/**
 * @fn int Alumno_getApellido(eAlumno*, char*)
 * @brief obtiene un apellido
 *
 * @param this
 * @param apellido
 * @return
 */
int Alumno_getApellido(eAlumno* this,char* apellido);//[HECHA]
/**
 * @fn int Alumno_getSexo(eAlumno*, char*)
 * @brief obtiene el sexo
 *
 * @param this
 * @param sexo
 * @return
 */
int Alumno_getSexo(eAlumno* this,char* sexo);//[HECHA]
/**
 * @fn int Alumno_getTipoPasajero(eAlumno*, int*)
 * @brief obtiene una a¡materia
 *
 * @param this
 * @param materia
 * @return
 */
int Alumno_getMateria(eAlumno* this,int* materia);//[HECHA]
/**
 * @fn int Passenger_getDescripcionTipoPasajero(int, char*)
 * @brief CARGA LA DESCRIPCION CORRESPONDIENTE AL TIPO DE PASAJERO
 *
 * @param typePassenger
 * @param desc
 * @return
 */
int Alumno_getDescripcionMateria(int materia,char* desc);
/**
 * @fn int Alumno_getPromedio(eAlumno*, float*)
 * @brief setea el promedio del alumno
 *
 * @param this
 * @param promedio
 * @return
 */
int Alumno_getPromedio(eAlumno* this,float* promedio);//[HECHA]
/**
 * @fn int Alumno_getAll(eAlumno*, char*, char*, float*, int*, int*, int*)
 * @brief obtengo todos los getters en una unica funcion
 *
 * @param this
 * @param name
 * @param lastname
 * @param promedio
 * @param materia
 * @param sexo
 * @param legajo
 * @return
 */
int Alumno_getAll(eAlumno* this,char* name,char* lastname,float* promedio,int* materia,char* sexo,int* legajo);//[HECHA] - [MY ADDITION]

//AGREGADAS:
/**
 * @fn int Alumno_searchForLegajo(LinkedList*, int)
 * @brief BUSCA A UN ALUMNO MEDIANTE SU LEGAJO
 *
 * @param pArrayAlumnos
 * @param legajo
 * @return si encontro retorna la posicion, si no -1
 */
int Alumno_searchForLegajo(LinkedList* pArrayAlumnos, int legajo);

//MOSTAR
/**
 * @fn int Alumno_ShowOnlyOne(eAlumno*)
 * @brief IMPRIME A UN UNICO ALUMNO
 *
 * @param alumno
 * @return
 */
int Alumno_ShowOnlyOne(eAlumno *alumno);

//SORT ALUMNOS:
/**
 * @fn int Alumnos_sortByName(void*, void*)
 * @brief ORDENA LA LISTA DE ALUMNOS DE FORMA ASCENDENTE POR NOMBRES
 *
 * @param name1 void*
 * @param name2 void*
 * @return 0 si no pudo, 1 si pudo, -1 si es menor
 */
int Alumnos_sortByName(void* name1,void* name2); //[CUMPLE SU FUNCION]
/**
 * @fn int Alumnos_sortByLastName(void*, void*)
 * @brief ORDENA LA LISTA DE ALUMNOS DE FORMA ASCENDENTE POR APELLIDOS
 *
 * @param lastName1 void*
 * @param lastName2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Alumnos_sortByLastName(void* lastName1,void* lastName2); //[CUMPLE SU FUNCION]
/**
 * @fn int Alumno_sortByPromedio(void*, void*)
 * @brief ORDENA LA LISTA DE ALUMNOS DE FORMA ASCENDENTE POR PROMEDIO
 *
 * @param promedio1 void*
 * @param promedio2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Alumno_sortByPromedio(void* promedio1,void* promedio2); //[CUMPLE SU FUNCION]
/**
 * @fn int Alumno_sortByMateria(void*, void*)
 * @brief ORDENA LA LISTA DE ALUMNOS DE FORMA ASCENDENTE POR MATERIA
 *
 * @param materia1 void*
 * @param materia2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Alumno_sortByMateria(void* materia1,void* materia2); //[CUMPLE SU FUNCION]
/**
 * @fn int Alumno_sortBySexo(void*, void*)
 * @brief ORDENA LA LISTA DE ALUMNOS DE FORMA ASCENDENTE POR SEXO
 *
 * @param sexo1 void*
 * @param sexo2 void*
 * @return  0 si no pudo, 1 si pudo, -1 si es menor
 */
int Alumno_sortBySexo(void* sexo1,void* sexo2); //[CUMPLE SU FUNCION]

//FILTROS
/**
 * @fn int filterByLaboratorio(void*)
 * @brief FILTRA A LOS ALUMNOS QUE CURSAN LABORATORIO
 *
 * @param pElement
 * @return
 */
int filterByLaboratorio(void* pElement);
/**
 * @fn int filterBySPD(void*)
 * @brief FILTRA A LOS ALUMNOS QUE CURSAN SPD
 *
 * @param pElement
 * @return
 */
int filterBySPD(void* pElement);
/**
 * @fn int filterByPromedio(void*)
 * @brief FILTRA A LOS ALUMNOS CUYO PROMEDIO ES MAYOR O IGUAL A 6
 *
 * @param pElement
 * @return
 */
int filterByPromedio(void* pElement);

#endif /* ALUMNO_H_ */
