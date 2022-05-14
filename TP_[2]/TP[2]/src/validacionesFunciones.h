/*
 * validacionesFunciones.h
 *
 *  Created on: 23 abr. 2022
 *      Author: Lenovo
 */

#ifndef VALIDACIONESFUNCIONES_H_
#define VALIDACIONESFUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

/// @fn int MostrarMenu(void)
/// @brief listado con menu de opciones
///
/// @return el numero elejido para la seleccion de opcion
int MostrarMenu(void);
/// @fn int MostrarSubMenu(void)
/// @brief listado con menu de opciones
///
/// @return el numero elejido para la seleccion de opcion
int MostrarSubMenu(void);
/// @fn int MenuDeOpciones(char[])
/// @brief listado con menu de opciones
///
/// @param mensaje
/// @return el numero elejido para la seleccion de opcion
int MenuDeOpciones(char mensaje[]);
/// @fn void PromedioYTotalPasajes(ePassenger[], TypePassenger[], int)
/// @brief informa el promedio y y el acumulador total de los precios de los pasajeros
///
/// @param passengers
/// @param tipoPasajero
/// @param cant
void PromedioYTotalPasajes(ePassenger passengers[],TypePassenger tipoPasajero[],int cant);
/// @fn void PasajerosQueSuperanElPromedio(ePassenger[], TypePassenger[], int, float)
/// @brief  informa el promedio del pasajeros que superan el promedio recaudado
///
/// @param passengers
/// @param tipoPasajero
/// @param cant
/// @param promedio
void PasajerosQueSuperanElPromedio(ePassenger passengers[],TypePassenger tipoPasajero[],int cant,float promedio);
/// @fn void ListadoEstadoActivoYCodigoVuelo(ePassenger[], TypePassenger[], eEstadoVuelo[], int)
/// @brief
///
/// @param passengers
/// @param tipoPasajero
/// @param estado
/// @param cant
void ListadoEstadoActivoYCodigoVuelo(ePassenger passengers[],TypePassenger tipoPasajero[],eEstadoVuelo estado[],int cant);

/// @fn float getFloat(float*)
/// @brief verifica y pasa un char a numero flotante
///
/// @param pResultado
/// @return 1 si es ok
float getFloat(float* pResultado);
/// @fn int getInt(int*)
/// @brief verifica y pasa un char a numero entero
///
/// @param pResultado
/// @return  1 si es ok
int getInt(int* pResultado);
/// @fn float utn_getNumeroFloat(float*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo de selaccion
/// @param maximo de seleccion
/// @param reintentos cant determinada
/// @return 0 si ess ok o -1 si es error
float utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/// @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo de seleccion
/// @param maximo de seleccion
/// @param reintentos cant determinada
/// @return  0 si ess ok o -1 si es error
int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/// @fn int CharIngresada(char[], int, char*, char*)
/// @brief
///
/// @param pCharIngresado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @return 1 si es ok 0 si es error
int CharIngresada(char pCharIngresado[],int longitud, char* mensaje, char* mensajeError);
/// @fn int myGets(char*, int)
/// @brief
///
/// @param charIngreso
/// @param longitud
/// @return 1 si es valido 0 si es error
int myGets(char* charIngreso, int longitud);
#endif /* VALIDACIONESFUNCIONES_H_ */
