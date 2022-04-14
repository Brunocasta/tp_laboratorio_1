/*
 * funcionesCalcular.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Lenovo
 */

#ifndef FUNCIONESCALCULAR_H_
#define FUNCIONESCALCULAR_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @fn float CalcularPrecioConDescuento(float, float)
/// @brief toma un numero flotante para aplicarle un descuento ya establecido
/// @param precioTotal es el valor ingresado por el usuario en la consola
/// 	   el resultado es el producto entre el valor ingresado y el descuento
/// @param descuento es la cantidad a aplicar sobre el valor
/// @return un flotante con el resultado de dicha cuenta
float CalcularPrecioConDescuento(float precioTotal,float descuento);

/// @fn float CalcularPrecioConInteres(float, float)
/// @brief toma un numero flotante para aplicarle un un interes ya establecido
/// @param precioTotal es el valor ingresado por el usuario en la consola
///  	   el resultado es el producto entre el valor ingresaado y el interes
/// @param interes es la cantidad a aplicar sobre el valor
/// @return un flotante con el resultado de dicha cuemta
float CalcularPrecioConInteres(float precioTotal,float interes);

/// @fn double CalcularValorBitcoins(float)
/// @brief calcula la convertibilidad de pesos a bitcoins
/// @param precioTotal es el valor ingresado por el usuario en la consola
/// @return el valor de la cantidad bitcoins obtenidos
double CalcularValorBitcoins(float precioTotal);

/// @fn float CalcularPrecioKilometroUnitario(int, float)
/// @brief calcula el precio unitario entre el valor ingresado sobre la cantidad de kilometros del recorrido
/// @param kilometros es la cantidad recorrida del viaje
/// @param precioTotales el valor total del vuelo que se ingreso
/// @return el resultado de la cuento devolviendo el valor unitario
float CalcularPrecioKilometroUnitario ( int kilometros,float precioTotal);

/// @fn float DiferenciaPreciosTotales(float, float)
/// @brief calcula la diferencia entre los precios totales de los viajes ingresados
/// @param total1 primer precio de vuelo ingresado
/// @param total2 segundo precio de vuelo ingresado
/// @return el resultado de la resta entre ambos valores
float DiferenciaPreciosTotales(float total1, float total2);

#endif /* FUNCIONESCALCULAR_H_ */
