/*
 * funcionInformarUsuario.h
 *
 *  Created on: 9 abr. 2022
 *      Author: claudia
 */

#ifndef FUNCIONINFORMARUSUARIO_H_
#define FUNCIONINFORMARUSUARIO_H_

//-----------------------------------------------------------------
/** \brief Funcion punto 4 donde se le informa al usuario los valores de Aero
 * \param float devAeroDesc el precio final de Aerolineas con decuento del 10
 * \param float devAeroInt el precio final de Aerolineas con interes del 25
 * \param float devAeroBtc el precio de cuantos BTCs son los que puede abonar con lo que ingreso
 * \param float devAeroUnitario el precio unitario
 * \return imprime en pantalla los resultados
 */
void funcionInformarUsuarioAero(float devAeroDesc, float devAeroInt, float devAeroBtc, float devAeroUnitario);

/** \brief Funcion punto 4 donde se le informa al usuario los valores de LATAM y la diferencia entre Aerolineas y LATAM
 * \param float devAeroDesc el precio final de LATAM con decuento del 10
 * \param float devAeroInt el precio final de LATAM con interes del 25
 * \param float devAeroBtc el precio de cuantos BTCs son los que puede abonar con lo que ingreso
 * \param float devAeroUnitario el precio unitario
 * \param float devDifPrecio la diferencia entre Aerolineas y Latam
 * \return imprime en pantalla los resultados
 */
void funcionInformarUsuarioLatam(float devLatamDesc, float devLatamInt, float devLatamBtc, float devLatamUnitario, float devDifPrecio);

//-----------------------------------------------------------------


#endif /* FUNCIONINFORMARUSUARIO_H_ */
