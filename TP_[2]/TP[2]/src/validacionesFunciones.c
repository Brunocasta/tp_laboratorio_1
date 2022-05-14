/*
 * validacionesFunciones.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Lenovo
 */

#include "validacionesFunciones.h"
#include "ArrayPassenger.h"

#define CANT 2000
#define CANTTIPO 2
#define CANTESTADO 3

int MostrarMenu(void)
{
	int opcion;
		printf("\n*****Menu*****");
		printf("\n1-Altas");
		printf("\n2-Modificar");
		printf("\n3-Baja");
		printf("\n4-Informar");
		printf("\n5-Salir");
		printf("\nIngrese una opcion :");
		scanf("%d",&opcion);
	return opcion;
}
int MostrarSubMenu(void)
{
	int opcion;
		printf("\n*****Sub-Menu*****");
		printf("\n1-Listado Pasajeros");
		printf("\n2-Total y Promedio Precios y Pasajeros que superan promedio");
		printf("\n3-Listado de Pasajeros por Codigo y estado Activo");
		printf("\n4-Alta Forzada de Pasajeros");
		printf("\n5-Salir");
		printf("\nIngrese una opcion :");
		scanf("%d",&opcion);
	return opcion;
}
int MenuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
void ListadoEstadoActivoYCodigoVuelo(ePassenger passengers[],TypePassenger tipoPasajero[],eEstadoVuelo estado[],int cant)
{
	int i,j;

	for(i=0;i<cant;i++)
	{
		if(passengers[i].isEmpty==0&&passengers[i].estadoVuelo.idEstadoVuelo==3)
		{
			for(j=0;j<CANTESTADO;j++)
			{
				if(estado[j].idEstadoVuelo==3)
				{
					printf("\n\n%4d %10s %10s %10.2f %10s %10s %10s "	,passengers[i].id
																	,passengers[i].name
																	,passengers[i].lastName
																	,passengers[i].price
																	,passengers[i].flycode
																	,passengers[i].TipoPasajero.typePassenger
																	,estado[j].descripcionEstado);
				}
			}
		}
	}

}
void PromedioYTotalPasajes(ePassenger passengers[],TypePassenger tipoPasajero[],int cant)
{
	float promedio,acumuladorPasajes;
	int contadorPasajes,i;
	contadorPasajes=0;
	acumuladorPasajes=0;

	for(i=0;i<cant;i++)
	{
		if(passengers[i].isEmpty==0)
		{
			acumuladorPasajes+=passengers[i].price;
			contadorPasajes++;
		}
	promedio = acumuladorPasajes/contadorPasajes;
	}
	printf("\nEl promedio de pasajes es : %.2f \n\nEl total de pasajes es : %.2f",promedio,acumuladorPasajes);

	PasajerosQueSuperanElPromedio(passengers,tipoPasajero,CANT,promedio);
}
void PasajerosQueSuperanElPromedio(ePassenger passengers[],TypePassenger tipoPasajero[],int cant,float promedio)
{
	int i,contadorQueSuperaPromedio;
	contadorQueSuperaPromedio=0;
	for(i=0;i<cant;i++)
	{
		if(passengers[i].isEmpty==0&&passengers[i].price>promedio)
		{
			contadorQueSuperaPromedio++;
		}
	}
	printf("\n\nLos pasajeros que Superan el precio promedio de pasajes es :%d \n",contadorQueSuperaPromedio);
}

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

