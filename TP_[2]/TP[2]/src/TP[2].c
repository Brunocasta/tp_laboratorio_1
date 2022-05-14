/*
 ============================================================================
 Name        : TP[2].c
 Author      : Bruno Castagnola 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacionesFunciones.h"
#include "ArrayPassenger.h"

#define CANT 2000
#define CANTTIPO 2
#define CANTESTADO 3

int main() {
	setbuf(stdout,NULL);

	int opcion,opcion2,idPasajeros,auxId,order;
	int cantidadPassengers=0;

	idPasajeros=1;
	ePassenger passengers[CANT];
	TypePassenger tipoPasajero[CANTTIPO]={{1,"TURISTA"},{2,"PRIMERA CLASE"}};
	eEstadoVuelo estadoVuelo[CANTESTADO]={{1,"DEMORADO"},{2,"ATERRIZADO"},{3,"ACTIVO"}};
	initPassengers(passengers,CANT);
	do{
		opcion=MostrarMenu();
		switch(opcion)
		{
			case 1:
				if(CreatePassenger(passengers,CANT,tipoPasajero,estadoVuelo,idPasajeros)==0)
				{
					cantidadPassengers++;
					idPasajeros++;
				}
			break;
			case 2:
				if(cantidadPassengers>0)
				{
					auxId=MenuDeOpciones("Ingrese el numero de ID del pasajero a modificar: ");
					ModifyPassenger(passengers,CANT,auxId,tipoPasajero,estadoVuelo);
				}else{
					printf("ERROR... No hay Datos Cargados");
				}
			break;
			case 3:
				if(cantidadPassengers>0)
				{
					auxId=MenuDeOpciones("Ingrese el numero de ID del pasajero a eliminar: ");
					if(removePassenger(passengers,CANT,auxId)==0){
					cantidadPassengers--;
					}
				}else{
					printf("ERROR... No hay Datos Cargados");
				}
			break;
			case 4:
				if(cantidadPassengers>0)
				{
					do{
						opcion2=MostrarSubMenu();
						switch(opcion2){
						case 1:

							order=MenuDeOpciones("\n 0-De manera Descentede ingrese \n 1-De manera Ascendente ingrese");
							sortPassengersByLastNameAndType(passengers,CANT,order);
						break;
						case 2:
							PromedioYTotalPasajes(passengers,tipoPasajero,CANT);
						break;
						case 3:

							order=MenuDeOpciones("\n 0-De manera Descentede ingrese \n 1-De manera Ascendente ingrese");
							sortPassengersByCodeAndActive(passengers,CANT,order);
						break;
						case 4:
							HardcodePassengers(passengers,tipoPasajero,estadoVuelo);
						break;
						case 5:
						break;
						default:
							printf("ERROR... Ingrese la opcion correcta");
						break;
						}
					}while(opcion2!=5);
				}else{
					printf("ERROR... No hay Datos Cargados");
				}
			break;
			case 5:
				printf("Gracias por utilizar BrunoTech");
			break;
			default:
				printf("ERROR... Ingrese la opcion correcta");
			break;
		}

	}while(opcion!=5);

	return 0;
}
