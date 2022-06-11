#ifndef PARSER_H_
#define PARSER_H_
#include <stdlib.h>
#include <string.h>
#include <string.h>
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si ok o 0 si error
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
/// @fn int parser_TextFromPassenger(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_TextFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger);
/// @fn int parser_BinaryFromPassenger(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger);
/// @fn int parser_listPassenger(LinkedList*)
/// @brief
///lista los pasajeros en la consola
/// @param pArrayListPassenger
/// @return
int parser_listPassenger(LinkedList* pArrayListPassenger);
/// @fn int parser_FindOnePassenger(LinkedList*, int)
/// @brief
///busca el pasajero en la lista
/// @param pArrayListPassenger
/// @param id
/// @return la posicion i si es ok sino 0
int parser_FindOnePassenger(LinkedList* pArrayListPassenger,int id);
/// @fn int parser_printOnePassenger(LinkedList*, int)
/// @brief
/// muestra los datos de un pasajero
/// @param pArrayListPassenger
/// @param id
/// @return 1 si es ok o 0 si esta mal
int parser_printOnePassenger(LinkedList* pArrayListPassenger,int id);
#endif /* PARSER_H_ */
