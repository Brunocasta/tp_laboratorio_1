/*
 ============================================================================
 Name        : tp_1.c
 Author      : Bruno Castagnola 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include "funciones.h"

int main() {
	setbuf(stdout,NULL);
	int x,y,z
		,opcion,opcion2;



	do{
		printf("           Menú");
		printf("\n1) Ingresar KMs de Vuelo");
		printf("\n2) Ingresar Precios de Vuelos");
		printf("\n3) Calcular costos de los Vuelos");
		printf("\n4) Informacion de Resultados");
		printf("\n5) Resultados Generales");
		printf("\n6) Salir de Menú ");
		printf("\nElegir una Opción:");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			PedirEntero("Ingresar Kilometros :");
			break;
		case 2 :
			//INGRESO DE VUELOS
			y=PedirEntero("Precio vuelo Aerolineas :\n");
			z=PedirEntero("Precio vuelo Latam: \n");
		break;
		case 3:
			do{
					printf("\n1) Costos de vuelos con Aerolineas");
					printf("\n2) Costos de Vuelos con Latam");
					printf("\n3) Regresar a Menú ");
					printf("\nElegir una Opción:");
					scanf("%d",&opcion2);

					switch(opcion2)
					{
					case 1:
							printf("Costos de vuelos con Aerolineas");
							//DESCUENTO AEROLINEAS
								Descuento(y,0.9);
							//INTERES AEROLINEAS
								Interes(y,1.25);
							//	BIT AEROLINEAS
								BitcoinValor(y);
							//UNITARIO AEROLINEAS
								PrecioUnitario(y,x);
								DiferenciaEnteros(y,z);
					break;
					}
			}while(opcion2!=3);

		break;

		default:
			printf("ERROR. Ingrese una Opción correcta\n");
			break;
		}

	}while(opcion!=6);


	//printf("\nKms Ingresados: %d kms",x);


	//DESCUENTO AEROLINEAS
	Descuento(y,0.9);
	//DESCUENTO LATAM
	Descuento(z,0.9);

	//INTERES AEROLINEAS
	Interes(y,1.25);
	//INTERES LATAM
	Interes(z,1.25);

	//	BIT AEROLINEAS
	BitcoinValor(y);
	//BIT LATAM
	BitcoinValor(z);

	//UNITARIO AEROLINEAS
	PrecioUnitario(y,x);
	//UNITARIO LATAM
	PrecioUnitario(z,x);

	DiferenciaEnteros(y,z);

	return 0;
}
