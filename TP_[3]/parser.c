#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	char idAux[20],nomAux[20],apellidoAux[20],precioAux[20],codigoVueloAux[20],tipoPasajeroAux[20],estadoVueloAux[20];
	if(pFile!= NULL&&pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",idAux,nomAux,apellidoAux,precioAux,codigoVueloAux,tipoPasajeroAux,estadoVueloAux);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",idAux,nomAux,apellidoAux,precioAux,codigoVueloAux,tipoPasajeroAux,estadoVueloAux)==7)
			{
				passenger =Passenger_newParametros(idAux,nomAux,apellidoAux,precioAux,codigoVueloAux,tipoPasajeroAux,estadoVueloAux);
				if(passenger!=NULL)
				{
					ll_add(pArrayListPassenger,passenger);
				}
			}
		}
	}
    return 1;
}
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	passenger=Passenger_new();
	int retorno=0;

	if(pFile!= NULL && pArrayListPassenger!=NULL)
	{
		while(!feof(pFile))
		{
			if(fread(&passenger,sizeof(passenger),1,pFile)==1)
			{
				ll_add(pArrayListPassenger,passenger);
				retorno=1;
			}
		}
	}
	return retorno;
}
int parser_TextFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	int i,passengersCount;
	int id;
	char nombre[40];
	char apellido[40];
	float precio;
	char codigoVuelo[40];
	char tipoPasajero[40];
	char estadoVuelo[40];

	if(pFile!= NULL && pArrayListPassenger!=NULL)
	{
		passengersCount=ll_len(pArrayListPassenger);
		for(i=0;i<passengersCount;i++)
		{
			passenger=ll_get(pArrayListPassenger,i);
			Passenger_getId(passenger,&id);
			Passenger_getNombre(passenger,nombre);
			Passenger_getApellido(passenger,apellido);
			Passenger_getPrecio(passenger,&precio);
			Passenger_getCodigoVuelo(passenger,codigoVuelo);
			Passenger_getTipoPasajero(passenger,tipoPasajero);
			Passenger_getEstadoVuelo(passenger,estadoVuelo);
			fprintf(pFile,"%4d %-10s %-10s %14.2f %-14s %-14s %10s \n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		}
	}
    return 1;
}
int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger)
{
 // tomar los datos y cargarlos en binario
	Passenger* passenger;
	passenger = Passenger_new();
	if(pFile!= NULL && pArrayListPassenger!=NULL)
	{
		int i, passengersCount;
		passengersCount=ll_len(pArrayListPassenger);

		for(i=0;i<passengersCount;i++)
		{
			passenger=ll_get(pArrayListPassenger,i);
			if(passenger!=NULL)
			{
				fwrite(&passenger,sizeof(Passenger),1,pFile);
			}
		}
	}
    return 1;

}
int parser_listPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	int i,passengersCount,retorno=0;
	int id;


	if(pArrayListPassenger!=NULL)
	{
		passengersCount=ll_len(pArrayListPassenger);
		for(i=0;i<passengersCount;i++)
		{
			passenger=ll_get(pArrayListPassenger,i);

			if(passenger!=NULL)
			{
				if(Passenger_getId(passenger,&id)==1)
				{
					parser_printOnePassenger(pArrayListPassenger,id);
				}
			}
		}
		retorno=1;
	}
	return retorno;
}
int parser_FindOnePassenger(LinkedList* pArrayListPassenger,int id)
{
	Passenger* passenger;
	passenger = Passenger_new();
	int estado,passengersCount,i,idAux;
	estado=0;
	passengersCount=ll_len(pArrayListPassenger);

	if(passengersCount>0 && id >0)
	{
		for(i=0;i<passengersCount;i++)
		{
			passenger=ll_get(pArrayListPassenger,i);
			if(passenger!=NULL)
			{
				Passenger_getId(passenger,&idAux);

				if(idAux==id)
				{
					estado=i;
					break;
				}
			}
		}
	}


	return estado;

}
int parser_printOnePassenger(LinkedList* pArrayListPassenger,int id)
{
	Passenger* passenger;
	int retorno=0;
	int idBuscar;
	char nombre[40];
	char apellido[40];
	float precio;
	char codigoVuelo[40];
	char tipoPasajero[40];
	char estadoVuelo[40];

	if(pArrayListPassenger!=NULL)
	{
		idBuscar=parser_FindOnePassenger(pArrayListPassenger,id);
		if(idBuscar!=0)
		{
			passenger=ll_get(pArrayListPassenger,idBuscar);

			Passenger_getId(passenger,&id);
			Passenger_getNombre(passenger,nombre);
			Passenger_getApellido(passenger,apellido);
			Passenger_getPrecio(passenger,&precio);
			Passenger_getCodigoVuelo(passenger,codigoVuelo);
			Passenger_getTipoPasajero(passenger,tipoPasajero);
			Passenger_getEstadoVuelo(passenger,estadoVuelo);
			retorno =1;
			printf("\n%4d %-10s %-10s %10.2f %10s %10s %10s \n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

		}
	}
	return retorno;

}

