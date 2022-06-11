#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
    int option= 0;
    int flagSalida=0;
    int flagText=0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	option=MenuPrincipal();
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros)==1)
                {
                	flagText=1;
					printf("Esta cargado el Archivo");
				}
				else
				{
					printf("No esta cargado el Archivo");
				}
            break;
            case 2:
            	if(controller_loadFromBinary("data.csv",listaPasajeros)==1)
				{
            		printf("Esta cargado el Archivo");
				}
				else
				{
					printf("No esta cargado el Archivo");
				}
			break;
            case 3:
            	if(ll_len(listaPasajeros)>0&&flagText==1)
            	{
					if(controller_addPassenger(listaPasajeros)==1)
					{
						printf("Esta cargado el Archivo");
					}
            	}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
            break;
            case 4:
				if(ll_len(listaPasajeros)>0&&flagText==1)
				{
					if(controller_editPassenger(listaPasajeros)==1)
					{
						printf("Se ha modificado el Pasajero");
					}
				}
				else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
			break;
            case 5:
            	if(ll_len(listaPasajeros)>0&&flagText==1)
            	{
            		if(controller_removePassenger(listaPasajeros)==1)
					{
            			printf("\nSe elimino con exito el pasajero\n");
					}
            	}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
            break;
            case 6:
            	if(ll_len(listaPasajeros)>0&&flagText==1)
            	{
            		if(controller_ListPassenger(listaPasajeros)==1)
            		{
            			printf("\nSe imprimio correctamente el archivo\n");
            		}
            	}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
            break;
            case 7:
            	if(ll_len(listaPasajeros)>0&&flagText==1)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
			break;
            case 8:
            	if(ll_len(listaPasajeros)>0&&flagSalida==0)
            	{
            		controller_saveAsText("dataText.txt",listaPasajeros);
            		flagSalida=1;
            		printf("\nEsta cargado el Archivo\n");
				}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1 \n");
				}
            break;
            case 9:
            	if(ll_len(listaPasajeros)>0&&flagSalida==0)
            	{
            		controller_saveAsBinary("dataBinary.bin",listaPasajeros);
            		flagSalida=1;
            		printf("\nEsta cargado el Archivo\n");
				}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 2\n");
				}
			break;
            case 10:
            	if(ll_len(listaPasajeros)>0&&flagSalida==1)
            	{
            		printf("\nGracias por utilizar el programa");

            	}
            	else
				{
					printf("\nNo esta cargado el Archivo... Ingrese la opcion 1  o la opcion 8/9 para guardar\n");
					option=11;
				}
            break;
            default:
            	printf("Ingrese una opcion  correcta ...Gracias");
			break;

        }
    }while(option != 10);
    return 0;
}

