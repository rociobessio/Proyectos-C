/*
 * funcionMenuIngreso.h
 *
 *  Created on: 9 abr. 2022
 *      Author: claudia
 */

#ifndef FUNCIONMENUINGRESO_H_
#define FUNCIONMENUINGRESO_H_

///FUNCIONES DE MENUS
/** \brief Se envia al usuario a la funcion para ingresar los kms
 * \param float* enviamos a direccion en memoria de los kms de main
 * \return retornamos los kms ingresados en la direccion de memoria de la variable
 */
float funcionMenuKm(float* punteroKms);

/** \brief como system("cls") no funciona los \n corren la pantalla para que no quede junto
 * \return espacios
 */
void funcionLimpiarPantallaEclipse();

/** \brief el usuario ingresa ambos valores de los vuelos
 * \param float* punteroValorAero direccion en memoria de la variable que recibe
 * \param float* punteroValorLatam direccion en memoria de la variable que recibe
 * \return lo ingresado por el usuario y los guarda en esa direccion de memoria indicada
 */
float funcionMenuIngresoValores(float* punteroValorAero, float* punteroValorLatam);



/** \brief le informa al usuario los valores ingresados por el
 * \param float kmIngresado
 * \param float precioLatam
 * \param float precioAero
 * \return imprime en pantalla
 */
void funcionInformarDatosActualizados(float kmIngresado, float precioLatam, float precioAero);

#endif /* FUNCIONMENUINGRESO_H_ */
