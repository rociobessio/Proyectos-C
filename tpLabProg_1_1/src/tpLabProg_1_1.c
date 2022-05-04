/*
 * Alumn@: Bessio Rocio Soledad
 * TP_1
 * DNI: 45013997
 * 1ro A
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

///BIBLIOTECA
#include "funcionesCalculos.h"
#include "funcionMenuIngreso.h"
#include "funcionesCargaForzada.h"
#include "funcionInformarUsuario.h"


int main()
{
	setbuf(stdout, NULL);

    ///Declaro esta variables en el  main para pasarlas por las distintas funciones
    float kmIngresados=0;
    float ingresoValorAerolineas=0;
    float ingresoValorLatam=0;

    ///BANDERAS DE VALIDACIONES:
    int banderaKmIngresados=0;
    int banderaPrecioIngresado=0;
    int banderaTerceraOpcion=0;
    int banderaCuartaOpcion=0;

    ///OPERACIONES AERO:
    float devolucionAerolineasDescuento;
    float devolucionAeroInte;
    float devolucionAeroBtc;
    float devolucionAeroUnit;

   ///OPERACIONES LATAM:
    float devolucionLatamDescuento;
    float devolucionLatamInte;
    float devolucionLatamBtc;
    float devolucionLatUnit;

    float devolucionDifValores;

    ///CARGA FORZADA DATOS:
    int kmCargaForzada = 7090;
    float precioAerolineasCarga = 162965;
    float precioLatamCarga = 159339;
    ///CARGA FORZADA CALCULOS AEROLINEAS:
    float devCargaAeroDeb;
    float devCargaAeroInt;
    float devCargaAeroBit;
    float devCargaAeroUnit;
    ///LATAM
    float devCargaLatDeb;
    float devCargaLatInt;
    float devCargaLatBit;
    float devCargaLatUnit;

    float devCargaDif;

    int menuPrincipal = 0;

    do
    {
        printf("\nBienvenid@ a la Agencia de viajes");
        printf("\n---------------------------------------");
        printf("\nPresiona:\n");
        printf("\n1)Ingresar KM\n2)Ingresar Precio de Vuelo\n3)Calcular todos los costos\n4)Informar resultado\n5)Carga forzada de datos\n6)Salir\nOpcion: ");
        scanf("%d", &menuPrincipal);
        while(menuPrincipal<=0 || menuPrincipal > 6)
        {
            printf("\n\n\nOPCION INVALIDA, volve a intentarlo: ");
            printf("\n---------------------------------------------");
            printf("\nPresiona:\n");
            printf("1)Ingresar KM\n2)Ingresar Precio de Vuelo\n3)Calcular todos los costos\n4)Informar resultado\n5)Carga forzada de datos\n6)Salir\nOpcion: ");
            scanf("%d", &menuPrincipal);
        }
        funcionLimpiarPantallaEclipse();

        switch(menuPrincipal)
        {
            case 1:
                if(banderaKmIngresados==0)
               {
                   funcionMenuKm(&kmIngresados);
                    banderaKmIngresados=1;
               }
               else
                {
                    printf("\n¡YA INGRESASTE LOS KM!");
                    printf("\n---------------------\n");
                }
                system("pause");
            break;
            case 2:
                if(banderaKmIngresados==0)
                {
                    ///SI NO INGRESO LOS KMs NO PUEDE INGRESAR EL VALOR DE LOS VUELOS
                    printf("\n¡NO INGRESASTE LOS KILOMETROS!");
                    printf("\n-------------------------------------------------------\n");
                }
                else
                {

                    if(banderaPrecioIngresado==0)
                    {
                         funcionMenuIngresoValores(&ingresoValorAerolineas,&ingresoValorLatam);
                        banderaPrecioIngresado=1;
                    }
                    else
                    {
                        printf("\n¡YA INGRESASTE EL VALOR DE AMBOS VUELOS!");
                        printf("\n-------------------------------------------\n");
                    }
                }
                system("pause");
            break;
            case 3:
                    if(banderaPrecioIngresado==0)
                    {
                        printf("\n¡NO INGRESASTE NINGUN VALOR A LOS VUELOS!");
                        printf("\n---------------------------------------------------\n");
                    }
                    else
                    {
                        if(banderaTerceraOpcion==0)
                        {
                        	printf("\n-------------------------------------------------------------------------------------------------");
                            printf("\nA continuacion se realizaran los calculos del vuelo mostrando los distintos metodos de pago: ");
                            printf("\nA)Tarjeta de debito (descuento del 10)\nB)Tarjeta de credito (25 de interes)\nC)Bitcoin\nD)Precio Unitario\nE)Diferencia de precios\n");
                            ///LLAMADO A FUNCIONES DE AEROLINEAS:
                            devolucionAerolineasDescuento = funcionAerolineasDebito(ingresoValorAerolineas);
                            devolucionAeroInte = funcionAeroInteres(ingresoValorAerolineas);
                            devolucionAeroBtc = funcionAeroBitcoin(ingresoValorAerolineas);
                            devolucionAeroUnit = funcionAeroUnitario(ingresoValorAerolineas,kmIngresados);

                            devolucionDifValores = funcionDifPrecios(ingresoValorAerolineas,ingresoValorLatam);

                            ///LLAMADO A FUNCIONES DE LATAM:
                            devolucionLatamDescuento = funcionLatamDebito(ingresoValorLatam);
                            devolucionLatamInte = funcionLatamInte(ingresoValorLatam);
                            devolucionLatamBtc = funcionLatamBtc (ingresoValorLatam);
                            devolucionLatUnit = funcionLatamUnitario(ingresoValorLatam, kmIngresados);

                            banderaTerceraOpcion=1;
                        }
                        else
                        {
                            printf("\n¡YA SE HICIERON LOS CACULOS! PRESIONA 4 PARA VERLOS");
                            printf("\n-----------------------------------------------------\n");
                        }
                    }
                    system("pause");
            break;
            case 4:
                if(banderaTerceraOpcion==0)
                {
                    printf("\n¡NO INGRESASTE AL APARTADO DE CALCULAR!");
                    printf("\n--------------------------------------------------\n");
                }
                else
                {
                    if(banderaCuartaOpcion==0)
                    {
                        funcionInformarUsuarioAero(devolucionAerolineasDescuento,devolucionAeroInte,devolucionAeroBtc,devolucionAeroUnit);
                        funcionInformarUsuarioLatam(devolucionLatamDescuento,devolucionLatamInte,devolucionLatamBtc,devolucionLatUnit,devolucionDifValores);

                        banderaCuartaOpcion=1;
                    }
                }
                system("pause");
            break;
            case 5:
                    devCargaAeroDeb = funcionCargaAeroDeb(precioAerolineasCarga);
                    devCargaLatDeb = funcionCargaLatamDeb(precioLatamCarga);
                    devCargaAeroInt = funcionCargaAeroInt(precioAerolineasCarga);
                    devCargaAeroBit = funcionCargaAeroBit(precioAerolineasCarga);
                    devCargaAeroUnit = funcionCargaAeroUnit(precioAerolineasCarga,kmCargaForzada);
                    devCargaLatInt = funcionCargaLatInt(precioLatamCarga);
                    devCargaLatBit = funcionCargaLatBit(precioLatamCarga);
                    devCargaLatUnit = funcionCargaLatUnit(precioLatamCarga, kmCargaForzada);
                    devCargaDif = funcionCargaDif(precioLatamCarga,precioAerolineasCarga);
                    funcionCargaForzadaInforma(kmCargaForzada,precioAerolineasCarga,precioLatamCarga, devCargaAeroDeb,devCargaLatDeb,devCargaAeroInt,devCargaAeroBit,devCargaAeroUnit,devCargaLatInt,devCargaLatBit,devCargaLatUnit,devCargaDif);
            break;
            default:
                printf("\nDecidiste finalizar la operacion. Gracias!\n");
                system("pause");
            break;
        }

        funcionInformarDatosActualizados(kmIngresados, ingresoValorLatam,ingresoValorAerolineas);


    }while(menuPrincipal !=6 );

    return 0;
}

