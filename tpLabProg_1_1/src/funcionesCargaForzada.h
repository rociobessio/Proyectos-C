/*
 * funcionesCargaForzada.h
 *
 *  Created on: 9 abr. 2022
 *      Author: claudia
 */

#ifndef FUNCIONESCARGAFORZADA_H_
#define FUNCIONESCARGAFORZADA_H_

///FUNCIONES DE CARGA FORZADA:
/** \brief Funcion punto 5 donde se le informa al usuario los valores de LATAM y Aerolineas mediante la CARGA FORZADA
 * \param float kmCargaForzada los kms que pusimos nosotros
 * \param float precioAerolineasCarga el precio de aerolineas que pusimos nosotros
 * \param float precioLatamCarga el precio de LATAM que pusimos nosotros
 * \param float devCargaAeroDeb el precio de Aero con descuento
 * \param float devCargaLatDeb el precio de Latam con descuento
 * \param float devCargaAeroInt el precio de Aerolineas con interes del 25
 * \param float devCargaAeroBit el precio de cuantos BTCs equivalen al precio del vuelo Aero
 * \param float devCargaAeroUnit el precio de Aerolineas unitario
 * \param float davCargaLatInt el precio de Latam con interes del 25
 * \param float devCargaLatBit el precio de cuantos BTCs equivalen al precio del vuelo Latam
 * \param float devCargaLatUnit el precio de Latam unitario
 * \param float devCargaDif la diferencia entre Latam y Aerolineas
 * \return imprime en pantalla los resultados
 */
void funcionCargaForzadaInforma(float kmCargaForzada,float precioAerolineasCarga, float precioLatamCarga,float devCargaAeroDeb, float devCargaLatDeb, float devCargaAeroInt,float devCargaAeroBit, float devCargaAeroUnit,float davCargaLatInt, float devCargaLatBit,float devCargaLatUnit,float devCargaDif);

/** \brief Calcula la carga forzada de Aerolineas con el descuento
 * \param float devCargaAeroDeb el precio de Aerolineas
 * \return devuelve el resultado
 */
float funcionCargaAeroDeb(float devCargaAeroDeb);

/** \brief Calcula la carga forzada de Aerolineas con el interes del 25
 * \param float devCargadevCargaAeroInt el precio de Aerolineas
 * \return devuelve el resultado
 */
float funcionCargaAeroInt(float devCargaAeroInt);

/** \brief Calcula la carga forzada de Aerolineas cuantos Btcs serian
 * \param float devCargaAeroBit el precio de Aerolineas
 * \return devuelve el resultado
 */
float funcionCargaAeroBit(float devCargaAeroBit);

/** \brief Calcula la carga forzada de Aerolineas y cuanto es el precio unitario
 * \param float devCargaAeroUnit el precio de Aerolineas
 * \param float devCargaKm el total de Kms
 * \return devuelve el resultado
 */
float funcionCargaAeroUnit(float devCargaAeroUnit, float devCargaKm);

/** \brief Calcula la carga forzada de LATAM y cuanto es es con descuento del 10
 * \param float devCargaLatDeb el precio de Latam
 * \return devuelve el resultado
 */
float funcionCargaLatamDeb(float devCargaLatDeb);

/** \brief Calcula la carga forzada de LATAM y cuanto es con interes del 25
 * \param float devCargaLatInt el precio de Latam
 * \return devuelve el resultado
 */
float  funcionCargaLatInt (float devCargaLatInt);

/** \brief Calcula la carga forzada de LATAM y cuantos Btcs serian
 * \param float devCargaLatBit el precio de LATAM
 * \return devuelve el resultado
 */
float funcionCargaLatBit (float devCargaLatBit);

/** \brief Calcula la carga forzada de LATAM y cuanto es el precio unitario
 * \param float devCargaLatUnit el precio de LATAM
 * \param float kmsCarga el total de Kms
 * \return devuelve el resultado
 */
float funcionCargaLatUnit (float devCargaLatUnit, float kmsCarga);

/** \brief Calcula DIFERENCIA de LATAM y AEROLINEAS
 * \param float devCargaPrecioLat el precio de LATAM
 * \param float devCargaPrecioAero el precio de AEROLINEAS
 * \return devuelve el resultado
 */
float funcionCargaDif (float devCargaPrecioLat, float devCargaPrecioAero);



#endif /* FUNCIONESCARGAFORZADA_H_ */
