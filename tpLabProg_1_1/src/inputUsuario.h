

#ifndef INPUTUSUARIO_H_
#define INPUTUSUARIO_H_



#endif /* INPUTUSUARIO_H_ */

/**
 * @fn int pedirKms(float*)
 * @brief LE PIDE LOS KMS AL USUARIO
 *
 * @param km
 * @return
 */
int pedirKms(float* km);

/**
 * @fn int funcionInformarDatosActualizados(float, float, float)
 * @brief INFORMA LOS DATOS ACTUALIZADOS DE LOS VALORES INGRESADOS
 *
 * @param kmIngresado
 * @param precioLatam
 * @param precioAero
 * @return
 */
int funcionInformarDatosActualizados(float kmIngresado, float precioLatam, float precioAero);

/**
 * @fn int pedirPreciosLatamYAero(float*, float*)
 * @brief PIDE LOS VALORES DE LATAM Y AEROLINEAS
 *
 * @param precioLatam
 * @param precioAero
 * @return
 */
int pedirPreciosLatamYAero(float* precioLatam,float* precioAero);


