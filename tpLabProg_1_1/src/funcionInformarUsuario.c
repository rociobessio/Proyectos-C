#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

///FUNCION PARA INFORMARLE AL USUARIO PUNTO 4
void funcionInformarUsuarioAero(float devAeroDesc, float devAeroInt, float devAeroBtc, float devAeroUnitario)
{
    printf("\nINFORMACION DE RESULTADOS DE AEROLINEAS: ");
    printf("\n------------------------------------");

    printf("\nA)Precio con tarjeta de debito: $%.2f",devAeroDesc);
    printf("\nB)Precio con tarjeta de credito: $%.2f",devAeroInt);
    printf("\nC)Precio pagando con Bitcoin: %.6f BTC",devAeroBtc);
    printf("\nD)Precio unitario: $%.2f",devAeroUnitario);
}
void funcionInformarUsuarioLatam(float devLatamDesc, float devLatamInt, float devLatamBtc, float devLatamUnitario, float devDifPrecio)
{
    printf("\n------------------------------------");
    printf("\nINFORMACION DE RESULTADOS DE LATAM: ");
    printf("\n------------------------------------");

    printf("\nA)Precio con tarjeta de debito: $%.2f",devLatamDesc);
    printf("\nB)Precio con tarjeta de credito: $%.2f",devLatamInt);
    printf("\nC)Precio pagando con Bitcoin: %.6f BTC",devLatamBtc);
    printf("\nD)Precio unitario: $%.2f",devLatamUnitario);
    printf("\n\nLa diferencia de precio es: $%.2f",devDifPrecio);
    printf("\n");
}
