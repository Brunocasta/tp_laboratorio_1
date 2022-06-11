#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief
///  lee un dato.csv en binario
/// @param path
/// @param pArrayListPassenger
/// @return 1 si es ok o 0 si es error
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_addPassenger(LinkedList*)
/// @brief
/// toma los datos obtenidos del parsser para cargar un pasajero
/// @param pArrayListPassenger
/// @return  1 si es ok o 0 si es error
int controller_addPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_editPassenger(LinkedList*)
/// @brief
/// edita un pasajero ya cargado en la lista
/// @param pArrayListPassenger
/// @return 1 si es ok o 0 si es error
int controller_editPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_removePassenger(LinkedList*)
/// @brief
/// remueve un pasajero de la lista
/// @param pArrayListPassenger
/// @return 1 si es ok o 0 si es error
int controller_removePassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_ListPassenger(LinkedList*)
/// @brief
/// lista los pasajeros
/// @param pArrayListPassenger
/// @return1 si es ok o 0 si es error
int controller_ListPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_sortPassenger(LinkedList*)
/// @brief
/// ordena de manera creciente o decreceinte los pasajeros
/// @param pArrayListPassenger
/// @return la eleccion del ordenamiento
int controller_sortPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief
/// carga los datos en un documento de texto
/// @param path
/// @param pArrayListPassenger
/// @return  si es ok o 0 si es error
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief
/// carga los datos en un documento binario
/// @param path
/// @param pArrayListPassenger
/// @return  si es ok o 0 si es error
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
