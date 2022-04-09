
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

///PUNTO 5 CARGA FORZADA
void funcionCargaForzadaInforma(float kmCargaForzada,float precioAerolineasCarga, float precioLatamCarga,float devCargaAeroDeb, float devCargaLatDeb, float devCargaAeroInt,float devCargaAeroBit, float devCargaAeroUnit,float davCargaLatInt, float devCargaLatBit,float devCargaLatUnit,float devCargaDif)
{
	printf("\nKMS: %.2f",kmCargaForzada);
    printf("\nAEROLINEAS:");
    printf("\nVALOR: $%.2f",precioAerolineasCarga);
    printf("\nA)Precio con tarjeta de debito: $%.2f",devCargaAeroDeb);
    printf("\nB)Precio con tarjeta de credito: $%.2f",devCargaAeroInt);
    printf("\nC)Precio pagando con Bitcoin: %.6f BTC",devCargaAeroBit);
    printf("\nD)Precio unitario: $%.2f",devCargaAeroUnit);

    printf("\n\nLATAM:");
    printf("\nVALOR: $%.2f",precioLatamCarga);
    printf("\nA)Precio con tarjeta de debito: $%.2f",devCargaLatDeb);
    printf("\nB)Precio con tarjeta de credito: $%.2f",davCargaLatInt);
    printf("\nC)Precio pagando con Bitcoin: %.6f BTC",devCargaLatBit);
    printf("\nD)Precio unitario: $%.2f",devCargaLatUnit);
    printf("\n\nLa diferencia de precio es: $%.2f",devCargaDif);

    printf("\n");

    system("pause");
}
///AEROLINEAS:
float funcionCargaAeroDeb(float devCargaAeroDeb)
{
    float descuento;
    float precioFinal;

    descuento =  ((devCargaAeroDeb*10)/100);
    precioFinal = devCargaAeroDeb - descuento;

    return precioFinal;
}
float funcionCargaAeroInt(float devCargaAeroInt)
{
    float precioAeroInt;
    float precioFinalAeroInte;

    precioAeroInt = ((devCargaAeroInt*25)/100);
    precioFinalAeroInte = precioAeroInt + devCargaAeroInt;

    return precioFinalAeroInte;
}
float funcionCargaAeroBit(float devCargaAeroBit)
{
    int bitcoin = 1;
    float pesosArgentinosEquivalente = 4606954.55;
    float conversionFinal;

    conversionFinal = ((devCargaAeroBit* bitcoin) / pesosArgentinosEquivalente);

    return conversionFinal;
}
float funcionCargaAeroUnit(float devCargaAeroUnit, float devCargaKm)
{
    float precioUnitarioAero;
   precioUnitarioAero= devCargaAeroUnit / devCargaKm;

   return precioUnitarioAero;
}
///LATAM
float funcionCargaLatamDeb(float devCargaLatDeb)
{
    float descuento;
    float precioFinal;

    descuento = ((devCargaLatDeb*10)/100);
    precioFinal = devCargaLatDeb - descuento;

    return precioFinal;
}
float  funcionCargaLatInt (float devCargaLatInt)
{
     float precioLatInt;
    float precioFinalLatInte;

    precioLatInt = ((devCargaLatInt*25)/100);
    precioFinalLatInte = precioLatInt + devCargaLatInt;

    return precioFinalLatInte;
}
float funcionCargaLatBit (float devCargaLatBit)
{
    int bitcoin = 1;
    float pesosArgentinosEquivalente = 4606954.55;
    float conversionFinal;

    conversionFinal = ((devCargaLatBit * bitcoin)/ pesosArgentinosEquivalente);

    return conversionFinal;
}
float funcionCargaLatUnit (float devCargaLatUnit, float kmsCarga)
{
    float precioUnitarioLat;

    precioUnitarioLat = devCargaLatUnit/kmsCarga;

    return precioUnitarioLat;
}

float funcionCargaDif (float devCargaPrecioLat, float devCargaPrecioAero)
{
    float diferenciaPrecios;

    diferenciaPrecios = devCargaPrecioLat - devCargaPrecioAero;

    return diferenciaPrecios;
}

