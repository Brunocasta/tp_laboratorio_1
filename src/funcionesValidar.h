/*
 * funciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Lenovo
 */

#ifndef FUNCIONESVALIDAR_H_
#define FUNCIONESVALIDAR_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @fn int PedirEntero(char[])
/// @brief pide un numero entero ya validado por medio de otra funcion
/// que valida enteros y los devuelve
/// @param mensaje es una cadena de caracteres que escribimos que necesitamos pedir
/// @return numero entero validado dentro de los parametros solicitados
int PedirEntero(char mensaje[]);

/// @fn float PedirFlotante(char[])
/// @brief pide un numero flotante ya validado por medio de otra funcion
/// que valida los flotantes y los devuelve
/// @param mensaje es una cadena de caracteres que escribimos que necesitamos pedir
/// @return numero flotante validado dentro de los parametros solicitados
float PedirFlotante(char mensaje[]);

/// @fn int MostrarMenu(void)
/// @brief Imprime en consola el menú con las opciones a elegir
/// @return un valor de la variable Opcion creada dentro de la misma para la eleccion del trabajo a realizar
int MostrarMenu(void);

/// @fn int ValidarLimite(int, int)
/// @brief pide un numero desde consola
/// y los valida entre parametros
/// @param numero se ingresa por consola
/// @param limiteInferior es el numero-limite a tener en cuenta en el momento de la validacion
/// @return un numero entero validado
int ValidarLimite(int numero,int limiteInferior);

/// @fn float ValidarLimiteFlotante(float, int)
/// @brief pide un numero desde consola
/// y los valida entre parametros
/// @param numero es ingresado por consola
/// @param limiteInferior es el numero-limite a tener en cuenta en el momento de la validacion
/// @return un numero flotante validado
float ValidarLimiteFlotante(float numero,int limiteInferior);


#endif /* FUNCIONESVALIDAR_H_ */
