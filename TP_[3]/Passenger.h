/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "validacionesPassengers.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[4];
	char estadoVuelo[20];
}Passenger;
/// @fn Passenger Passenger_new*()
/// @brief
/// crea un nuevo pasajero en memoria
/// @return el espacio en memoria
Passenger* Passenger_new();
/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief
/// carga los datos de la lista de psajeros
/// @param idStr
/// @param nameStr
/// @param lastNameStr
/// @param priceStr
/// @param flycodeStr
/// @param typePassengerStr
/// @param statusFlightStr
/// @return el pasajero
Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* priceStr,char* flycodeStr,char* typePassengerStr,char* statusFlightStr);
/// @fn void Passenger_delete(Passenger*)
/// @brief
/// borra un pasajero cargado en la memoria
/// @param this pasajero a borrar
void Passenger_delete(Passenger* this);
/// @fn int CreatePassenger(LinkedList*)
/// @brief
///
/// @param pArrayListPassenger
/// @return 1 si es ok o 0 si eror
int CreatePassenger(LinkedList* pArrayListPassenger);
/// @fn int Passenger_setId(Passenger*, char*)
/// @brief
/// setttea un id
/// @param this
/// @param id
/// @return si es ok o 0 si es error
int Passenger_setId(Passenger* this,char* id);
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief
/// get de id
/// @param this
/// @param id
/// @return si es ok o 0 si es error
int Passenger_getId(Passenger* this,int* id);
/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief
/// settea un nombre
/// @param this
/// @param nombre
/// @return si es ok o 0 si es error
int Passenger_setNombre(Passenger* this,char* nombre);
/// @fn char Passenger_getNombre(Passenger*, char*)
/// @brief
/// get de un nombre
/// @param this
/// @param nombre
/// @return si es ok o 0 si es error
char Passenger_getNombre(Passenger* this,char* nombre);
/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief
/// settea de apellido
/// @param this
/// @param apellido
/// @return si es ok o 0 si es error
int Passenger_setApellido(Passenger* this,char* apellido);
/// @fn char Passenger_getApellido(Passenger*, char*)
/// @brief
/// get de un apellido
/// @param this
/// @param apellido
/// @return si es ok o 0 si es error
char Passenger_getApellido(Passenger* this,char* apellido);
/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief
/// setea el codigo de vuelo
/// @param this
/// @param codigoVuelo
/// @return si es ok o 0 si es error
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @fn char Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief
/// get del codigo de vuelo
/// @param this
/// @param codigoVuelo
/// @return si es ok o 0 si es error
char Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @fn int Passenger_setTipoPasajero(Passenger*, char*)
/// @brief
/// setea un tipo de pasajero
/// @param this
/// @param tipoPasajero
/// @return si es ok o 0 si es error
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/// @fn char Passenger_getTipoPasajero(Passenger*, char*)
/// @brief
/// get de tipo de pasajero
/// @param this
/// @param tipoPasajero
/// @return si es ok o 0 si es error
char Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
/// @fn char Passenger_setEstadoVuelo(Passenger*, char*)
/// @brief
/// setea un estado de vuelo
/// @param this
/// @param estadoVuelo
/// @return si es ok o 0 si es error
char Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
/// @fn char Passenger_getEstadoVuelo(Passenger*, char*)
/// @brief
/// get de estadod evuelo
/// @param this
/// @param estadoVuelo
/// @return si es ok o 0 si es error
char Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);
/// @fn int Passenger_setPrecio(Passenger*, char*)
/// @brief
/// setea un precio
/// @param this
/// @param precio
/// @return si es ok o 0 si es error
int Passenger_setPrecio(Passenger* this,char* precio);
/// @fn float Passenger_getPrecio(Passenger*, float*)
/// @brief
/// get de el precio
/// @param this
/// @param precio
/// @return si es ok o 0 si es error
float Passenger_getPrecio(Passenger* this,float* precio);
/// @fn int Passenger_CompareByName(void*, void*)
/// @brief
/// compara por nombre
/// @param p1
/// @param p2
/// @return la comparacion de los nombres
int Passenger_CompareByName(void* p1,void* p2);
/// @fn unsigned int Passenger_getIdTxt(void)
/// @brief
/// toma un id desde archivo y lo suma a la lista
///
/// @return si es ok o 0 si es error
unsigned int Passenger_getIdTxt(void);
/// @fn int Passnger_setIdTxt(Passenger*, int)
/// @brief
/// setea el id
/// @param this
/// @param id
/// @return  si es ok o 0 si es error
int Passnger_setIdTxt(Passenger* this,int id);


#endif /* PASSENGER_H_ */
