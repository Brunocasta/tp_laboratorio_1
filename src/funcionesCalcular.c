/*
 * funcionesCalcular.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Lenovo
 */
#include "funcionesCalcular.h"


float CalcularPrecioConDescuento(float precioTotal,float descuento)
{
	float totalDescuento;
	totalDescuento=precioTotal * descuento;
	return totalDescuento;
}

float CalcularPrecioConInteres(float precioTotal,float interes)
{
	float interesTotal;
	interesTotal= precioTotal * interes;
	return interesTotal;
}

double CalcularValorBitcoins(float precioTotal)
{
	double bitcoin
		, totalBitcoin;
	bitcoin= 4765477.37;
	totalBitcoin= precioTotal/bitcoin;

	return totalBitcoin;
}

float CalcularPrecioKilometroUnitario ( int kilometros,float precioTotal)
{
	float totalPrecioUnitario;
	totalPrecioUnitario=precioTotal / kilometros;
	return totalPrecioUnitario;
}

float DiferenciaPreciosTotales(float total1, float total2)
{
	float totalDiferencia;
	totalDiferencia=total1-total2;

	if(totalDiferencia<0)
	{
		return totalDiferencia*-1;
	}
	return totalDiferencia;
}
