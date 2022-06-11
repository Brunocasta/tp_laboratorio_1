/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}
Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* priceStr,char* flycodeStr,char* typePassengerStr,char* statusFlightStr)
{
	Passenger* passenger;
	passenger=(Passenger*)malloc(sizeof(Passenger));

	if(passenger!=NULL)
	{
		Passenger_setId(passenger,idStr);
		Passenger_setNombre(passenger,nameStr);
		Passenger_setApellido(passenger,lastNameStr);
		Passenger_setPrecio(passenger,priceStr);
		Passenger_setCodigoVuelo(passenger,flycodeStr);
		Passenger_setTipoPasajero(passenger,typePassengerStr);
		Passenger_setEstadoVuelo(passenger,statusFlightStr);
		return passenger;
	}
	return NULL;
}
void Passenger_delete(Passenger* this)
{
	free(this);
}
unsigned int Passenger_getIdTxt(void)
{
	unsigned int idAux;
	FILE* pFile=fopen("idPassenger.txt","r");
	while(!feof(pFile))
	{
		fscanf(pFile,"%d",&idAux);
		idAux++;
	}
	fclose(pFile);

	pFile=fopen("idPassenger.txt","w");
	fprintf(pFile,"%d",idAux);
	fclose(pFile);
	return idAux;

}

//setters
int Passenger_setId(Passenger* this,char* id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = atoi(id);
        retorno = 1;
    }
    return retorno;

}
int Passnger_setIdTxt(Passenger* this,int id)
{
	int retorno = -1;
	    if(this != NULL && id > 0)
	    {
	        this->id = id;
	        retorno = 1;
	    }
	    return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		retorno = 1;
	}
	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 1;
	}
	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
char Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->tipoPasajero,estadoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this,char* precio)
{
	float retorno = 0;
	if(this != NULL && precio > 0)
	{
		this->precio = atof(precio);
		retorno = 1;
	}
	return retorno;
}
 // getters
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;
	if(this != NULL)
	{
		*id= this->id;
		 retorno =1;
	}
	return retorno;
}
char Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=0;

	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}
char Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=0;

	if(this != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 1;
	}
	return retorno;
}
float Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;
	if(this != NULL)
	{
		*precio= this->precio;
		 retorno =1;
	}
	return retorno;
}
char Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=0;
	if(this != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}
char Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=0;
	if(this != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
char Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno=0;
	if(this != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}
int CreatePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	passenger=Passenger_new();
	int retorno;
	retorno=0;
	int idAux;
	char name[51];
	char lastName[51];
	char price[40];
	char flycode[10];
	char typePassenger[40];
	char statusFlight[40];

	if(passenger!=NULL)
	{
		idAux=Passenger_getIdTxt();

		if(CharIngresada(name,51,"Ingrese Nombre Pasajero : \n","Error...Ingrese Nombre Pasajerocorrecto\n")==1)
		{
			Passenger_setNombre(passenger,name);
		}
		if(CharIngresada(lastName,51,"Ingrese Apellido Pasajero : \n","Error...Ingrese Apellido Pasajero correcto\n")==1)
		{
			Passenger_setApellido(passenger,lastName);
		}
		if(CharIngresada(price,51,"Ingrese Precio de vuelo correcto : \n","Error...Ingrese un valor correcto\n")==1)
		{
			Passenger_setPrecio(passenger,price);
		}
		if(CharIngresada(flycode,51,"Ingrese Codigo de Vuelo : \n","Error...Ingrese un valor correcto\n")==1)
		{
			Passenger_setCodigoVuelo(passenger,flycode);
		}
		if(CharIngresada(typePassenger,51,"\nIngrese el Tipo Pasajero : \n","Error...Ingrese un valor correcto\n")==1)
		{
			Passenger_setTipoPasajero(passenger,typePassenger);
		}
		if(CharIngresada(statusFlight,51,"\nIngrese Estado de Vuelo : \n","Error...Ingrese un valor correcto\n")==1)
		{
			Passenger_setEstadoVuelo(passenger,statusFlight);
		}

		Passnger_setIdTxt(passenger,idAux);

		ll_add(pArrayListPassenger,passenger);
		retorno= 1;
	}
	return retorno;
}
int Passenger_CompareByName(void* p1,void* p2)
{
	int retorno=0;

    Passenger* unPasajero;
    Passenger* otroPasajero;

    char nombreUno[40];
    char nombreDos[40];

    unPasajero = (Passenger*) p1;
    otroPasajero = (Passenger*) p2;
    Passenger_getNombre(unPasajero,nombreUno);
    Passenger_getNombre(otroPasajero,nombreDos);
    if(nombreUno!=0 && nombreDos!=0)
    {
    	retorno=strcmp(nombreUno,nombreDos);
    }
    return retorno;
}

