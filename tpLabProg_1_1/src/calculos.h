
#ifndef CALCULOS_H_
#define CALCULOS_H_

#endif /* CALCULOS_H_ */




/**
 * @fn float calcularDebito(float)
 * @brief CALCULA DESCUENTO DEL 10
 *
 * @param precioRecibido
 * @return
 */
float calcularDebito(float precioRecibido);

/**
 * @fn float calcularCredito(float)
 * @brief CALCULA EL INTERES
 *
 * @param precioRecibido
 * @return
 */
float calcularCredito(float precioRecibido);

/**
 * @fn float calcularBtc(float)
 * @brief CALCULA CONVERSION DE PESOS A BTC
 *
 * @param precioRecibido
 * @return
 */
float calcularBtc(float precioRecibido);

/**
 * @fn float calcularPrecioUnitario(float, float)
 * @brief CALCULA EL PRECIO UNITARIO
 *
 * @param precioRecibido
 * @param kmRecibido
 * @return
 */
float calcularPrecioUnitario(float precioRecibido, float kmRecibido);

/**
 * @fn float calcularDiferenciaPrecios(float, float)
 * @brief CALCULA LA DIFERENCIA ENTRE DOS VALORES
 *
 * @param precioAero
 * @param precioLat
 * @return
 */
float calcularDiferenciaPrecios(float precioAero, float precioLat);

/**
 * @fn int calculosInformes(float, float, float, float, float, float, float, float, float)
 * @brief INFORMA LOS VALORES FINALES AL USUARIO
 *
 * @param resultDebAero
 * @param resultDebLat
 * @param resultCredAero
 * @param resultCredLat
 * @param resultBtcAero
 * @param resultBtcLat
 * @param resultUnitAero
 * @param resultUnitLat
 * @param resultDifPrecios
 * @return
 */
int calculosInformes(float resultDebAero,float resultDebLat,float resultCredAero,float resultCredLat,float resultBtcAero,float resultBtcLat,float resultUnitAero,float resultUnitLat,float resultDifPrecios);

/**
 * @fn void cargaForzada(float, float, float)
 * @brief REALIZA LA CARGA FORZADA DE DATOS
 *
 * @param kmsForzada
 * @param precioLatForzada
 * @param precioAeroForzada
 */
void cargaForzada(float kmsForzada,float precioLatForzada,float precioAeroForzada);
