/*
 * validacionesPassengers.h
 *
 *  Created on: 11 jun. 2022
 *      Author: Lenovo
 */

#ifndef VALIDACIONESPASSENGERS_H_
#define VALIDACIONESPASSENGERS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
/// @fn float getFloat(float*)
/// @brief
///
/// @param pResultado
/// @return 1 si es ok
float getFloat(float* pResultado);
/// @fn int getInt(int*)
/// @brief
/// toma y pasa el chaar en int
/// @param pResultado
/// @return
int getInt(int* pResultado);
/// @fn float utn_getNumeroFloat(float*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
float utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/// @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
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
/// @fn int MenuPrincipal(void)
/// @brief
///
/// @return
int MenuPrincipal (void);
/// @fn int MenuDeOpciones(char[])
/// @brief
///
/// @param mensaje
/// @return
int MenuDeOpciones(char mensaje[]);


#endif /* VALIDACIONESPASSENGERS_H_ */
