/*
 * ArrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Lenovo
 */
#include "ArrayPassenger.h"
#include "validacionesFunciones.h"

int initPassengers(ePassenger * passengers, int len)
{
	int i;
	if(passengers!=NULL&&len>0){
		for (i=0;i<len;i++)
		{
			passengers[i].isEmpty=1;
		}
		return 0;
	}
	return -1;
}
int CreatePassenger(ePassenger* passengers, int cant, TypePassenger tipoPasajeros[],eEstadoVuelo estadoVuelos[], int idPasajero)
{
	int i;
	float respuestaFlotante;
	int respuestaEntero;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idTypePassenger;
	int idEstadoVuelo;
	eEstadoVuelo estadoVuelo;
	TypePassenger tipoPasajero;

	CharIngresada(name,51,"Ingrese Nombre Pasajero : \n","Error...Ingrese Nombre Pasajerocorrecto\n");

	CharIngresada(lastName,51,"Ingrese Apellido Pasajero : \n","Error...Ingrese Apellido Pasajero correcto\n");

	respuestaFlotante=utn_getNumeroFloat(&price,"Ingrese Precio de vuelo : \n","Error...Ingrese un valor correcto\n",0,50000,3);
	while(respuestaFlotante<0)
	{
		respuestaFlotante=utn_getNumeroFloat(&price,"Ingrese Precio de vuelo correcto : \n","Error...Ingrese un valor correcto\n",0,50000,3);
	}

	CharIngresada(flycode,51,"Ingrese Codigo de Vuelo : \n","Error...Ingrese un valor correcto\n");


	for(i=0;i<CANTTIPO;i++)
	{
		printf("\n%d-%4s"	,tipoPasajeros[i].idTypePassenger
						,tipoPasajeros[i].typePassenger);
	}
	respuestaEntero=utn_getNumeroInt(&idTypePassenger,"\nElija el Tipo Pasajero : \n","Error...Ingrese un valor correcto\n",1,2,3);
	while(respuestaEntero<0)
	{
		respuestaEntero=utn_getNumeroInt(&idTypePassenger,"\nElija el Tipo Pasajero correcto : \n","Error...Ingrese un valor correcto\n",1,2,3);
	}
	for(i=0;i<CANTTIPO;i++){
		if(idTypePassenger==tipoPasajeros[i].idTypePassenger){
			tipoPasajero=tipoPasajeros[i];
		}
	}

	for(i=0;i<CANTESTADO;i++){
		printf("\n%d-%4s"  ,estadoVuelos[i].idEstadoVuelo
							,estadoVuelos[i].descripcionEstado);
	}
	respuestaEntero=utn_getNumeroInt(&idEstadoVuelo,"\nIngrese Estado de Vuelo : \n","Error...Ingrese un valor correcto\n",1,3,3);
	while(respuestaEntero<0)
	{
		respuestaEntero=utn_getNumeroInt(&idEstadoVuelo,"\nIngrese Estado de Vuelo correcto : \n","Error...Ingrese un valor correcto\n",1,3,3);
	}
	for(i=0;i<CANTESTADO;i++){
		if(idEstadoVuelo==estadoVuelos[i].idEstadoVuelo){
			estadoVuelo=estadoVuelos[i];
		}
	}

	return addPassenger(passengers,CANT,name,lastName,price,idTypePassenger,flycode,estadoVuelo,idEstadoVuelo,tipoPasajero,idPasajero);


}
int addPassenger(ePassenger* passengers, int cant, char name[],char lastName[],float price,int typePassenger, char flycode[],eEstadoVuelo estadoVuelo,int idEstadoVuelo,TypePassenger tipoPasajero, int id)
{
	int position=findFirstFreePosition(passengers,cant);

	if(position!=-1)
	{
	passengers[position].id=id;
	passengers[position].idEstadoVuelo=idEstadoVuelo;
	passengers[position].estadoVuelo=estadoVuelo;
	passengers[position].TipoPasajero=tipoPasajero;
	passengers[position].idTypePassenger=typePassenger;
	strcpy(passengers[position].name, name);
	strcpy(passengers[position].lastName,lastName);
	passengers[position].price=price;
	strcpy(passengers[position].flycode,flycode);
	passengers[position].isEmpty=0;

	printf("\n Se cargo correctmente el Pasajero");
	return 0;

	}else{
		printf("No se cargo el Pasajero");
		return -1;
	}
	return -1;
}
void HardcodePassengers(ePassenger passengers[],TypePassenger tipoPasajero[],eEstadoVuelo estado[])
{

	int i;
	int id[]={33,34,35,36,37};
	char name[][51]={"Diego","Martin","Pablo","Ricardo","Gustavo"};
	char lastName[][51]={"Maradona","Palermo","Lescano","Mollo","Ceratti"};
	float price[]={10000,20000,30000,15000,24000};
	char flycode[][10]={"23400","12365","4567","123","7766"};
	int idTypePassenger[]={1,2,2,1,1};
	int idEstadoVuelo[]={3,3,3,1,2};

	for(i=0;i<5;i++)
	{

		passengers[i].id=id[i];
		strcpy(passengers[i].name, name[i]);
		strcpy(passengers[i].lastName,lastName[i]);
		passengers[i].price=price[i];
		strcpy(passengers[i].flycode,flycode[i]);
		passengers[i].idEstadoVuelo=idEstadoVuelo[i];
		passengers[i].estadoVuelo=estado[i];
		passengers[i].TipoPasajero=tipoPasajero[i];
		passengers[i].idTypePassenger=idTypePassenger[i];
		passengers[i].isEmpty=0;
	}
	printPassenger(passengers,5);

}
int findPassengerById(ePassenger * passengers, int cant,int id)
{
	int auxPasajero,i;
	auxPasajero=-1;
	if(passengers != NULL && cant > 0)
	{
		for(i=0;i<cant;i++)
		{
			if(id==passengers[i].id&&passengers[i].isEmpty==0){

				auxPasajero=i;
				break;
			}
		}
	}
	return auxPasajero;
}
int findFirstFreePosition(ePassenger * passengers, int cant)
{
	int auxPasajero,i;
	auxPasajero=-1;
	if(passengers != NULL && cant > 0)
	{
		for(i=0;i<cant;i++)
		{
			if(passengers[i].isEmpty==1){

				auxPasajero=i;
				break;
			}
		}
	}
	return auxPasajero;
}
int ModifyPassenger(ePassenger * passengers, int cant,int id,TypePassenger tipoPasajero[],eEstadoVuelo estado[])
{
	int passengerPosition,opcion,i;
	float respuestaFlotante;
	int respuestaEntero;
	passengerPosition=findPassengerById(passengers,CANT,id);
	if(passengerPosition!=-1)
	{
		PrintOnePassenger(passengers[passengerPosition]);
		do{
			opcion=MenuDeOpciones("\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Código de vuelo \n6. Salir \nOpcion:");
				switch(opcion){
				case 1 :
					CharIngresada(passengers[passengerPosition].name,51,"Ingrese Nombre Pasajero : \n","Error...Ingrese Nombre Pasajerocorrecto\n");
					break;
				case 2 :
					CharIngresada(passengers[passengerPosition].lastName,51,"Ingrese Apellido Pasajero : \n","Error...Ingrese Apellido Pasajero correcto\n");
					break;
				case 3 :
					respuestaFlotante=utn_getNumeroFloat(&passengers[passengerPosition].price,"Ingrese Precio de vuelo : \n","Error...Ingrese un valor correcto\n",0,50000,3);
					while(respuestaFlotante<0)
					{
						respuestaFlotante=utn_getNumeroFloat(&passengers[passengerPosition].price,"Ingrese Precio de vuelo correcto : \n","Error...Ingrese un valor correcto\n",0,50000,3);
					}

					break;
				case 4 :
					for(i=0;i<CANTTIPO;i++)
					{
						printf("\n%d-%4s"	,tipoPasajero[i].idTypePassenger
										,tipoPasajero[i].typePassenger);
					}
					respuestaEntero=utn_getNumeroInt(&passengers[i].idTypePassenger,"\nElija el Tipo Pasajero : \n","Error...Ingrese un valor correcto\n",1,2,3);
					while(respuestaEntero<0)
					{
						respuestaEntero=utn_getNumeroInt(&passengers[i].idTypePassenger,"\nElija el Tipo Pasajero correcto : \n","Error...Ingrese un valor correcto\n",1,2,3);
					}
					for(i=0;i<CANTTIPO;i++){
						if(passengers[i].idTypePassenger==tipoPasajero[i].idTypePassenger){
							passengers[i].TipoPasajero=tipoPasajero[i];
						}
					}
					break;
				case 5:
					CharIngresada(passengers[i].flycode,51,"Ingrese Codigo de Vuelo : \n","Error...Ingrese un valor correcto\n");
					break;
				case 6:
					printf("Se modifico con exito el pasajero");

					return 0;
				break;
				}
		}while(opcion!=6);
		}
	else
	{
		printf("No se encontro el pasejero que desea modificar");
		return -1;
	}
	return -1;
}
int removePassenger(ePassenger* passengers, int cant, int id)
{
	int passengerPosition;
	char respuesta;

	passengerPosition=findPassengerById(passengers,CANT,id);


	if(passengerPosition!=-1)
	{
		PrintOnePassenger(passengers[passengerPosition]);

		printf("\nDesea eliminar este Pasajero? S/N");
		fflush(stdin);
		scanf("%c",&respuesta);
		 respuesta=toupper(respuesta);

		if(respuesta=='S')
		{
			passengers[passengerPosition].isEmpty=1;
			printf("\nYa se elimino el Pasajero");
			return 0;

		}
		else
		{
			printf("Usted ha decidido no borra los datos");
			return -1;
		}
	}


		printf("No se encontro el pasejero que desea eliminar");
		return -1;
}
int sortPassengersByLastNameAndType(ePassenger* passengers, int cant, int order)
{

	int i,j;
	ePassenger apellidoAlfabetico;

	if(order ==1)
	{
		for(i=0;i<cant-1;i++)
			{
				for(j=i+1;j<cant;j++)
				{
					if((strcmp(passengers[i].lastName,passengers[j].lastName))>0)
					{
						apellidoAlfabetico=passengers[i];
						passengers[i]=passengers[j];
						passengers[j]=apellidoAlfabetico;
					}
				}

			}

		for(i=0;i<cant-1;i++)
		{
			for(j=i+1;j<cant;j++)
			{
				if((strcmp(passengers[i].lastName,passengers[j].lastName))>0 && strcmp(passengers[i].TipoPasajero.typePassenger,passengers[j].TipoPasajero.typePassenger)>0)
				{
					apellidoAlfabetico=passengers[i];
					passengers[i]=passengers[j];
					passengers[j]=apellidoAlfabetico;
				}
			}

		}
	}
	else
	{
		for(i=0;i<cant-1;i++)
			{
				for(j=i+1;j<cant;j++)
				{
					if((strcmp(passengers[i].lastName,passengers[j].lastName))<0)
					{
						apellidoAlfabetico=passengers[i];
						passengers[i]=passengers[j];
						passengers[j]=apellidoAlfabetico;
					}
				}

			}

		for(i=0;i<cant-1;i++)
		{
			for(j=i+1;j<cant;j++)
			{
				if((strcmp(passengers[i].lastName,passengers[j].lastName))<0 && strcmp(passengers[i].TipoPasajero.typePassenger,passengers[j].TipoPasajero.typePassenger)<0)
				{
					apellidoAlfabetico=passengers[i];
					passengers[i]=passengers[j];
					passengers[j]=apellidoAlfabetico;
				}
			}

		}
	}
	printPassenger(passengers,CANT);
	return 0;
}
int sortPassengersByCodeAndActive(ePassenger* passengers,int cant, int order)
{

	int i,j;
	ePassenger auxPassenger;

	if(order==1)
	{

		for(i=0;i<cant-1;i++)
		{
			for(j=i+1;j<cant;j++)
			{
				if(strcmp(passengers[i].flycode,passengers[j].flycode)>0)
				{
							auxPassenger=passengers[i];
							passengers[i]=passengers[j];
							passengers[j]=auxPassenger;
				}
			}
		}

		for(i=0;i<cant-1;i++)
			{
				for(j=i+1;j<cant;j++)
				{
					if(strcmp(passengers[i].flycode,passengers[j].flycode)>0 && strcmp(passengers[i].estadoVuelo.descripcionEstado,passengers[j].estadoVuelo.descripcionEstado)>0)
					{
								auxPassenger=passengers[i];
								passengers[i]=passengers[j];
								passengers[j]=auxPassenger;
					}
				}
			}
	}
	else
	{
		for(i=0;i<cant-1;i++)
		{
			for(j=i+1;j<cant;j++)
			{
				if(strcmp(passengers[i].flycode,passengers[j].flycode)<0)
				{
							auxPassenger=passengers[i];
							passengers[i]=passengers[j];
							passengers[j]=auxPassenger;
				}
			}
		}
		for(i=0;i<cant-1;i++)
		{
			for(j=i+1;j<cant;j++)
			{
				if(strcmp(passengers[i].flycode,passengers[j].flycode)<0 && strcmp(passengers[i].estadoVuelo.descripcionEstado,passengers[j].estadoVuelo.descripcionEstado)<0)
				{
							auxPassenger=passengers[i];
							passengers[i]=passengers[j];
							passengers[j]=auxPassenger;
				}
			}
		}
	}



	printPassenger(passengers,CANT);
	return 0;
}
int printPassenger(ePassenger* passengers, int cant)
{
	int i;
	printf("%4s %10s %10s %10s %10s %10s %10s ","ID","Nombre","Apellido","Precio","Cod.Vuelo","Tipo Pasaj.","Estado Vuelo");
	for(i=0;i<CANT;i++)
	{
		if(passengers[i].isEmpty==0)
		{
			printf("\n\n%4d %10s %10s %10.2f %10s %10s %10s "	,passengers[i].id
																,passengers[i].name
																,passengers[i].lastName
																,passengers[i].price
																,passengers[i].flycode
																,passengers[i].TipoPasajero.typePassenger
																,passengers[i].estadoVuelo.descripcionEstado);

		}
	}

	return 0;
}
void PrintOnePassenger(ePassenger passengers)
{	printf("\n%4s %10s %10s %10s %10s %10s %10s ","ID","Nombre","Apellido","Precio","Cod.Vuelo","Tipo Pasaj.","Estado Vuelo");
	printf("\n\n%4d %10s %10s %10.2f %10s %10s %10s "	,passengers.id
													,passengers.name
													,passengers.lastName
													,passengers.price
													,passengers.flycode
													,passengers.TipoPasajero.typePassenger
													,passengers.estadoVuelo.descripcionEstado);
}
