/*
 * ArrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Lenovo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT 2000
#define CANTTIPO 2
#define CANTESTADO 3
typedef struct{
	int idEstadoVuelo;
	char descripcionEstado[51];
}eEstadoVuelo;
typedef struct{
	int idTypePassenger;
	char typePassenger[20];
}TypePassenger;
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	TypePassenger TipoPasajero;
	int idTypePassenger;
	eEstadoVuelo estadoVuelo;
	int idEstadoVuelo;
	int isEmpty;
}ePassenger;

/// @fn int initPassengers(ePassenger*, int)
/// @brief
///
/// @param list pasajeros
/// @param len cantidad pasajeros
/// @return 0 si es ok y -1 si es error
int initPassengers(ePassenger * list, int len);
/// @fn int findFirstFreePosition(ePassenger*, int)
/// @brief busca una posicion vacia de larray
///
/// @param passengers
/// @param cant
/// @return la posicion de i si es ok si es error -1
int findFirstFreePosition(ePassenger * passengers, int cant);
/// @fn void HardcodePassengers(ePassenger[], TypePassenger[], eEstadoVuelo[])
/// @brief son datos hardcodeados de pasajeros y los muestra en consola
///
/// @param passengers
/// @param tipoPasajero
/// @param estado
void HardcodePassengers(ePassenger passengers[],TypePassenger tipoPasajero[],eEstadoVuelo estado[]);
/// @fn int addPassenger(ePassenger*, int, char[], char[], float, int, char[], eEstadoVuelo, int, TypePassenger, int)
/// @brief  toma los valores que se le ppasa por parametro y si hay espacio vacio los carga
///
/// @param passengers
/// @param cant
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @param estadoVuelo
/// @param idEstadoVuelo
/// @param tipoPasajero
/// @param id
/// @return 0 si es ok si es error -1
int addPassenger(ePassenger* passengers, int cant, char name[],char lastName[],float price,int typePassenger, char flycode[],eEstadoVuelo estadoVuelo,int idEstadoVuelo,TypePassenger tipoPasajero, int id);
/// @fn int findPassengerById(ePassenger*, int, int)
/// @brief  busca un id de pasajero
///
/// @param passengers
/// @param cant
/// @param id
/// @return la posicion de i si es ok si es error -1
int findPassengerById(ePassenger * passengers, int cant,int id);
/// @fn int ModifyPassenger(ePassenger*, int, int, TypePassenger[], eEstadoVuelo[])
/// @brief modifica los datos que el pasajero necesite
///
/// @param passengers
/// @param cant
/// @param id
/// @param tipoPasajero
/// @param estado
/// @return 0 si es ok si es error -1
int ModifyPassenger(ePassenger * passengers, int cant,int id,TypePassenger tipoPasajero[],eEstadoVuelo estado[]);
/// @fn int removePassenger(ePassenger*, int, int)
/// @brief busca un pasajero y lo elimina si se desea
///
/// @param passengers
/// @param cant
/// @param id se tomapor parametro
/// @return 0 si es ok si es error -1
int removePassenger(ePassenger* passengers, int cant, int id);
/// @fn int sortPassengersByLastName(ePassenger*, int, int)
/// @brief ordena a los pasajeros primero por apellido y despues por tipo pasajero
///
/// @param passengers
/// @param cant
/// @param order 1 si es ascendente el orden o si es descendente
/// @return 0 si es ok
int sortPassengersByLastNameAndType(ePassenger* passengers, int cant, int order);
/// @fn int sortPassengersByCodeAndActive(ePassenger*, int, int)
/// @brief ordena a los pasajeros primero por codigo vuelo y despues por activos
///
/// @param passengers
/// @param cant
/// @param order  1 si es ascendente el orden o si es descendente
/// @return o si es ok
int sortPassengersByCodeAndActive(ePassenger* passengers, int cant, int order);
/// @fn int printPassenger(ePassenger*, int)
/// @brief muestra listado de pasajeros
///
/// @param passengers
/// @param cant
/// @return o si es ok
int printPassenger(ePassenger* passengers, int cant);
/// @fn int CreatePassenger(ePassenger*, int, TypePassenger[], eEstadoVuelo[], int)
/// @brief crea un nuevo pasajero para la carga de datos
///
/// @param passengers
/// @param cant
/// @param tipoPasajeros
/// @param estadoVuelos
/// @param idPasajero
/// @return la carga de un pasajero para que addPassenger lo valide
int CreatePassenger(ePassenger* passengers, int cant, TypePassenger tipoPasajeros[],eEstadoVuelo estadoVuelos[], int idPasajero);
/// @fn void PrintOnePassenger(ePassenger)
/// @brief muestra los datos de un pasajero determinado
///
/// @param passengers
void PrintOnePassenger(ePassenger passengers);
#endif /* ARRAYPASSENGER_H_ */
