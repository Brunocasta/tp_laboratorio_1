/*
 * validacionesPassengers.c
 *
 *  Created on: 11 jun. 2022
 *      Author: Lenovo
 */
#include "validacionesPassengers.h"

float getFloat(float* pResultado)
{
	char buffer[64];
	scanf("%s",buffer);
	*pResultado = atoi(buffer);
	return 1;
}
int getInt(int* pResultado)
{
	char buffer[64];
	scanf("%s",buffer);
	*pResultado = atoi(buffer);
	return 1;
}
float utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	float retorno;
	float numeroValido;
	while(reintentos>0)
	{
		printf(mensaje);
		if(getFloat(&numeroValido)==1)
		{
			if(numeroValido<=maximo && numeroValido>=minimo){
				break;
			}
		}
			fflush(stdin);
			reintentos--;
			printf(mensajeError);
	}
	if(reintentos==0)
	{
		retorno=-1;
	}else{
		retorno=0;
		*pResultado = numeroValido;
	}
	return retorno;
}
int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno;
	int numeroValido;
	while(reintentos>0)
	{
		printf(mensaje);
		if(getInt(&numeroValido)==1)
		{
			if(numeroValido<=maximo && numeroValido>=minimo){
				break;
			}
		}
			fflush(stdin);
			reintentos--;
			printf(mensajeError);
	}
	if(reintentos==0)
	{
		retorno=-1;
	}else{
		retorno=0;
		*pResultado = numeroValido;
	}
	return retorno;
}
int CharIngresada(char pCharIngresado[],int longitud, char* mensaje, char* mensajeError)
{
	int status = 1;

	if(mensaje!= NULL&&mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		while(myGets(pCharIngresado, longitud)==0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
		}
	}

	return status;
}
int myGets(char* charIngreso, int longitud)
{
	int status=0;
	if(charIngreso != NULL && longitud >0 && fgets(charIngreso,longitud,stdin)==charIngreso)
	{
		fflush(stdin);
		if(charIngreso[strlen(charIngreso)-1] == '\n')
		{
			charIngreso[strlen(charIngreso)-1] = '\0';
		}
		status= 1;
	}

	return status;
}

int MenuPrincipal (void)
	{
		int opcion;
		printf("\n 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
		printf("\n 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)");
		printf("\n 3. Alta de pasajero");
		printf("\n 4. Modificar datos de pasajero");
		printf("\n 5. Baja de pasajero");
		printf("\n 6. Listar pasajeros");
		printf("\n 7. Ordenar pasajeros");
		printf("\n 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)");
		printf("\n 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)");
		printf("\n 10. Salir del Programa. ");
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		return opcion;
	}
int MenuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

