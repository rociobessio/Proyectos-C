
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
///FUNCIONES DE AEROLINEAS:
float funcionAerolineasDebito(float reciboDeValorAerolineasDeb)
{
   float precioConDescuento = 0;
   float precioFinalAeroDescuento = 0;

    precioConDescuento =((reciboDeValorAerolineasDeb*10)/100);
    precioFinalAeroDescuento = reciboDeValorAerolineasDeb-precioConDescuento;

   return  precioFinalAeroDescuento;
}
float funcionAeroInteres(float recibeAeroPrecio)
{
    ///VER SI LA FORMULA ESTA BIEN IGUALMENTE
    float precioConInteres;
    float precioFinalConInteres;

    precioConInteres =((recibeAeroPrecio*25)/100);
    precioFinalConInteres = recibeAeroPrecio + precioConInteres;

    return precioFinalConInteres;
}
float funcionAeroBitcoin(float recibeAeroPrecioBit)
{
    int bitcoin = 1;
    float pesosArgentinosEquivalente = 4606954.55;
    float conversionFinal;

    conversionFinal = ((recibeAeroPrecioBit* bitcoin) / pesosArgentinosEquivalente);

    return conversionFinal;
}
float funcionAeroUnitario (float recibeAeroPrecioUnit, float kmAeroUnit)
{
   float precioUnitarioAero;
   precioUnitarioAero= recibeAeroPrecioUnit / kmAeroUnit;

   return precioUnitarioAero;
}




///FUNCIONES DE LATAM:
float funcionLatamDebito(float reciboDeValorLatamDeb)
{
    float precioConDescuento = 0;
    float precioFinalLatamDescuento = 0;

    precioConDescuento =((reciboDeValorLatamDeb*10)/100);
    precioFinalLatamDescuento = reciboDeValorLatamDeb-precioConDescuento;

   return  precioFinalLatamDescuento;
}
float funcionLatamInte(float recibeLatValorInt)
{
    float precioLatInt;
    float precioFinalLatInte;

    precioLatInt = ((recibeLatValorInt*25)/100);
    precioFinalLatInte = precioLatInt + recibeLatValorInt;

    return precioFinalLatInte;
}

float funcionLatamBtc (float recibeLatValorBtc)
{
    int bitcoin = 1;
    float pesosArgentinosEquivalente = 4606954.55;
    float conversionFinal;

    conversionFinal = ((recibeLatValorBtc * bitcoin)/ pesosArgentinosEquivalente);

    return conversionFinal;
}
float funcionLatamUnitario(float recibeLatValorUnit, float kmLatUnit)
{
    float precioUnitarioLat;

    precioUnitarioLat = recibeLatValorUnit/kmLatUnit;

    return precioUnitarioLat;
}

float funcionDifPrecios(float recibevalorAeroDif, float recibeValorLatamDif)
{
    float diferenciaPrecios;

    diferenciaPrecios = recibevalorAeroDif - recibeValorLatamDif;

    return diferenciaPrecios;
}
