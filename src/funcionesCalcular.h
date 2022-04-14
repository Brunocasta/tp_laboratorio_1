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


float CalcularPrecioConDescuento(float precioTotal,float descuento);
float CalcularPrecioConInteres(float precioTotal,float interes);
double CalcularValorBitcoins(float precioTotal);
float CalcularPrecioKilometroUnitario ( int kilometros,float precioTotal);
float DiferenciaPreciosTotales(float total1, float total2);

#endif /* FUNCIONESCALCULAR_H_ */
