

#ifndef FUNCIONESCALCULOS_H_
#define FUNCIONESCALCULOS_H_
///DECLARACION DE FUNCIONES AEROLINEAS:
/** \brief Lo que hace es recibir el precio del vuelo de Aerolineas y realizar el descuento.
 * \param float precioAerolineasDescuento
 * \return el resultado del descuento
 */
float funcionAerolineasDebito(float reciboDeValorAerolineasDeb);

/** \brief recibe el valor ingresado de aerolineas y calcula el interes.
 * \param float recibeAeroPrecio
 * \return el resultado del interes
 */
float funcionAeroInteres(float recibeAeroPrecio);

/** \brief recibe el valor de aerolineas y calcula el pasaje a BTC
 * \param float recibeAeroPrecioBit
 * \return el equivalente
 */
float funcionAeroBitcoin(float recibeAeroPrecioBit);

/** \brief Lo que hace es calcular el precio por KM
 * \param float recibeAeroPrecioUnit
  * \param float kmAeroUnit
 * \return el precio unitario
 */
float funcionAeroUnitario (float recibeAeroPrecioUnit, float kmAeroUnit);


//-----------------------------------------------------------------
///DECLARACION DE FUNCIONES LATAM:
/** \brief Se envia el valor ingresado del vuelo de LATAM y se hace un descuento del 10
 * \param float reciboDeValorLatamDeb se envia el valor ingresado por el usuario
 * \return retorna el resultado
 */
float funcionLatamDebito(float reciboDeValorLatamDeb);

/** \brief recibe el  valor de Latam y calcula el precio con interes
 * \param float recibeLatValorInt
 * \return retorna el precio de latam con 25 de interes
 */
float funcionLatamInte(float recibeLatValorInt);

/** \brief calcula cuanto es el equivalente de los pesos Latam a BTC
 * \param float recibeLatValorBtc
 * \return equivalente
 */
float funcionLatamBtc (float recibeLatValorBtc);

/** \brief Lo que hace es calcular el precio por KM de Latam
 * \param float recibeLatValorUnit
 * \param float kmLatUnit
 * \return el precio unitario
 */
float funcionLatamUnitario(float recibeLatValorUnit, float kmLatUnit);

/** \brief SACA LA DIFERENCIA ENTRE AMBOS VALORES
 * \param float recibeLatValorDif
 * \param float recibeAeroValorDif
 * \return la diferencia
 */
float funcionDifPrecios(float recibevalorAeroDif, float recibeValorLatamDif);



#endif /* FUNCIONESCALCULOS_H_ */
