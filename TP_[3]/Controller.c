#include "Controller.h"
#include "Passenger.h"
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	FILE* pFile;
	pFile=fopen(path,"r");

	if(pFile!=NULL)
	{
		parser_PassengerFromText(pFile,pArrayListPassenger);
		retorno= 1;
	}
	fclose(pFile);
   return retorno;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno=0;
	pFile=fopen(path,"rb");

	if(pFile!=NULL)
	{
		if(parser_PassengerFromBinary(pFile,pArrayListPassenger)==1){
			retorno=1;
		}
		fclose(pFile);
	}
	else
	{
		retorno=0;
	}

    return retorno;
}
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	if(pArrayListPassenger!=NULL)
	{
		CreatePassenger(pArrayListPassenger);
		retorno=1;
	}

    return retorno;
}
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int OptionId,idModificar,optionModificar,retorno=0;
	char respuesta;
	Passenger* passenger;
	char name[51];
	char lastName[51];
	char price[40];
	char flycode[10];
	char typePassenger[40];
	char statusFlight[40];

	if(pArrayListPassenger!=0)
	{
		parser_listPassenger(pArrayListPassenger);

		OptionId=MenuDeOpciones("\nIngrese el ID del Pasajero a Modificar :\n");
		idModificar=parser_FindOnePassenger(pArrayListPassenger,OptionId);

		if(idModificar!=0)
		{
			passenger=ll_get(pArrayListPassenger,idModificar);
			parser_printOnePassenger(pArrayListPassenger,OptionId);

			printf("\n Si desea Modificar un pasajero ingrese una respuesta...S/N \n");
			fflush(stdin);
			scanf("%c",&respuesta);
			respuesta=toupper(respuesta);

			if(respuesta =='S')
			{

				do{
					optionModificar=MenuDeOpciones("\n1. Nombre\n2. Apellido\n3. Precio\n4. Código de vuelo \n5. Tipo de pasajero  \n6. Estado de Vuelo \n7. Salir a Menu principal \nOpcion:\n");
					switch(optionModificar)
					{
					case 1:
						if(CharIngresada(name,51,"Ingrese Nombre Pasajero : \n","Error...Ingrese Nombre Pasajerocorrecto\n")==1)
						{
							Passenger_setNombre(passenger,name);
						}
					break;
					case 2:
						if(CharIngresada(lastName,51,"Ingrese Apellido Pasajero : \n","Error...Ingrese Apellido Pasajero correcto\n")==1)
						{
							Passenger_setApellido(passenger,lastName);
						}
					break;
					case 3:
						if(CharIngresada(price,51,"Ingrese Precio de vuelo correcto : \n","Error...Ingrese un valor correcto\n")==1)
						{
							Passenger_setPrecio(passenger,price);
						}
					break;
					case 4:
						if(CharIngresada(flycode,51,"Ingrese Codigo de Vuelo : \n","Error...Ingrese un valor correcto\n")==1)
						{
							Passenger_setCodigoVuelo(passenger,flycode);
						}
					break;
					case 5:
						if(CharIngresada(typePassenger,51,"\nIngrese el Tipo Pasajero : \n","Error...Ingrese un valor correcto\n")==1)
						{
							Passenger_setTipoPasajero(passenger,typePassenger);
						}
					break;
					case 6:
						if(CharIngresada(statusFlight,51,"\nIngrese Estado de Vuelo : \n","Error...Ingrese un valor correcto\n")==1)
						{
							Passenger_setEstadoVuelo(passenger,statusFlight);
						}
					break;
					case 7:
						printf("\n El Pasajero ha sido modificado\n");
					break;
					}
					parser_printOnePassenger(pArrayListPassenger,OptionId);
					retorno=1;
				}while(optionModificar!=7);
			}
			else
			{
				printf("No se Modificao el pasajero");
				retorno=-1;
			}
		}
	}
    return retorno;
}
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int OptionId,idBaja,retorno=0;
	char respuesta;
	Passenger* passenger;

	OptionId=MenuDeOpciones("\nIngrese el ID del Pasajero a dar de Baja :\n");
	idBaja=parser_FindOnePassenger(pArrayListPassenger,OptionId);

	if(idBaja!=0)
	{
		passenger=ll_get(pArrayListPassenger,idBaja);
		printf("\n Si desea eliminar el pasajero ingrese una respuesta...S/N \n");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		if(respuesta =='S')
		{
			ll_remove(pArrayListPassenger,idBaja);
			Passenger_delete(passenger);
			retorno=1;
		}
		else
		{
			printf("No se elimino el pasajero");
			retorno=-1;
		}
	}
    return retorno;
}
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	if(pArrayListPassenger!=NULL)
	{
		parser_listPassenger(pArrayListPassenger);
		retorno=1;
	}

    return retorno;
}
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int estado=0,OptionOrder;
	char respuesta;
	if(ll_len(pArrayListPassenger)>0)
	{
		OptionOrder=MenuDeOpciones("\n1. Orden de A a Z \n0. Orden de Z a A \n");
		printf("Aguarde unos segundos despues de la eleccion... Gracias\n");
		estado=ll_sort(pArrayListPassenger, Passenger_CompareByName, OptionOrder);

		printf("\nSe Ordeno con exito la Lista...Desea Mostrarla? S/N ");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		if(respuesta=='S')
		{
			parser_listPassenger(pArrayListPassenger);
		}
		else
		{
			printf("No se pudo ordenar la lista...");
		}
	}

    return estado;
}
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	pFile=fopen(path,"w");
	if(pArrayListPassenger!=NULL)
	{
		parser_TextFromPassenger(pFile,pArrayListPassenger);
	}
	fclose(pFile);

    return 1;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	pFile=fopen(path,"wb");
	if(pArrayListPassenger!=NULL)
	{
		parser_BinaryFromPassenger(pFile,pArrayListPassenger);
	}
	fclose(pFile);

	return 1;
}
