/*
 * funciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Lenovo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>

int PedirEntero(char mensaje[]);
int MostrarMenu(void);
int ValidarLimite(int numero,int limiteInferior);
float PedirFlotante(char mensaje[]);
float ValidarLimiteFlotante(float numero,int limiteInferior);
float CalcularPrecioConDescuento(float precioTotal,float descuento);
float CalcularPrecioConInteres(float precioTotal,float interes);
double CalcularValorBitcoins(float precioTotal);
float CalcularPrecioKilometroUnitario ( int kilometros,float precioTotal);
float DiferenciaPreciosTotales(float total1, float total2);



#endif /* FUNCIONES_H_ */
