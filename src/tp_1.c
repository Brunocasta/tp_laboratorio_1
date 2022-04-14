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
#include <string.h>
#include "funcionesValidar.h"
#include "funcionesCalcular.h"

int main() {
	setbuf(stdout,NULL);

	int opcion;
	float precioTotalAA=0,precioTotalLatam=0,totalKilometros=0
		 ,descuentoAerolineas,interesAerolineas,bitcoinsAerolineas
		 ,precioUnitarioAerolineas,diferenciaPrecioIngresados
		 ,descuentoLatam,interesLatam
		 ,bitcoinsLatam,precioUnitarioLatam;
	float porcientoDescuento= 0.9;
	float porcientoInteres= 1.25;
	int realizoCalculos=0;
	char salir;

	do{
		opcion= MostrarMenu();
			switch(opcion)
			{
			case 1:
				totalKilometros=PedirEntero("Ingresar Kilometros :");
			break;
			case 2 :
				if(totalKilometros!=0)
				{
					precioTotalAA = PedirFlotante("Precio vuelo Aerolineas :\n");
					precioTotalLatam = PedirFlotante("Precio vuelo Latam: \n");
				}else
				{
					printf("\nPor favor,Ingresar KMs de Vuelo.Gracias\n");
				}
			break;
			case 3:
				if(totalKilometros > 0 && precioTotalAA>0 && precioTotalLatam>0)
				{
					descuentoAerolineas = CalcularPrecioConDescuento(precioTotalAA,porcientoDescuento);
					interesAerolineas = CalcularPrecioConInteres(precioTotalAA,porcientoInteres);
					bitcoinsAerolineas = CalcularValorBitcoins(precioTotalAA);
					precioUnitarioAerolineas = CalcularPrecioKilometroUnitario(totalKilometros,precioTotalAA);

					descuentoLatam = CalcularPrecioConDescuento(precioTotalLatam,porcientoDescuento);
					interesLatam = CalcularPrecioConInteres(precioTotalLatam,porcientoInteres);
					bitcoinsLatam = CalcularValorBitcoins(precioTotalLatam);
					precioUnitarioLatam = CalcularPrecioKilometroUnitario(totalKilometros,precioTotalLatam);

					diferenciaPrecioIngresados = DiferenciaPreciosTotales(precioTotalAA,precioTotalLatam);

					realizoCalculos=1;
				}
				else
				{
					printf("\nPor favor,Ingresar KMs de Vuelo y/o Precios de vuelo.Gracias\n");
				}

			break;
			case 4:
				if(realizoCalculos==1)
				{
					printf("\n**Precio Latam**");
					printf("\nPrecio con Tarjeta de Debito :$%2.f",descuentoLatam);
					printf("\nPrecio con Tarjeta de Credito :$%2.f",interesLatam);
					printf("\nEl Precio pagando con Bitcoin:%f BTC",bitcoinsLatam);
					printf("\nEl Precio Unitario es:$%.3f\n",precioUnitarioLatam);

					printf("\n**Precio Aerolineas**");
					printf("\nPrecio con Tarjeta de Debito :$%2.f",descuentoAerolineas);
					printf("\nPrecio con Tarjeta de Credito :$%2.f",interesAerolineas);
					printf("\nEl Precio pagando con Bitcoin:%f BTC",bitcoinsAerolineas);
					printf("\nEl Precio Unitario es:$%.3f",precioUnitarioAerolineas);

					printf("\nLa diferencia de precios es:$%.2f",diferenciaPrecioIngresados);

					totalKilometros=0;
					precioTotalAA=0;
					precioTotalLatam=0;
				}
				else
				{
					printf("\nPor favor,Ingresar KMs de Vuelo y/o precios de vuelo\n y luego asegurese de elegir la opcion 3.Gracias\n");
				}

			break;
			case 5:
				totalKilometros=7090;

				precioTotalAA=162965;
				precioTotalLatam=159339;

				descuentoAerolineas = CalcularPrecioConDescuento(precioTotalAA,porcientoDescuento);
				interesAerolineas = CalcularPrecioConInteres(precioTotalAA,porcientoInteres);
				bitcoinsAerolineas = CalcularValorBitcoins(precioTotalAA);
				precioUnitarioAerolineas = CalcularPrecioKilometroUnitario(totalKilometros,precioTotalAA);

				descuentoLatam = CalcularPrecioConDescuento(precioTotalLatam,porcientoDescuento);
				interesLatam = CalcularPrecioConInteres(precioTotalLatam,porcientoInteres);
				bitcoinsLatam = CalcularValorBitcoins(precioTotalLatam);
				precioUnitarioLatam = CalcularPrecioKilometroUnitario(totalKilometros,precioTotalLatam);

				diferenciaPrecioIngresados = DiferenciaPreciosTotales(precioTotalAA,precioTotalLatam);

				printf("\nKMs Ingresados: %2.f km\n",totalKilometros);
				printf("\na)Precio Aerolineas:$%2.f",precioTotalAA);
				printf("\nb)Precio con Tarjeta de Debito :$ %2.f",descuentoAerolineas);
				printf("\nc)Precio con Tarjeta de Credito :$ %2.f",interesAerolineas);
				printf("\nd)El Precio pagando con Bitcoin: %f BTC",bitcoinsAerolineas);
				printf("\ne)El Precio Unitario es:$ %.3f\n",precioUnitarioAerolineas);

				printf("\na)Precio Latam:$%2.f",precioTotalLatam);
				printf("\nb)Precio con Tarjeta de Debito :$ %2.f",descuentoLatam);
				printf("\nc)Precio con Tarjeta de Credito :$ %2.f",interesLatam);
				printf("\nd)El Precio pagando con Bitcoin: %f BTC",bitcoinsLatam);
				printf("\ne)El Precio Unitario es:$ %.3f\n",precioUnitarioLatam);

				printf("\nLa diferencia de precio es:$ %.2f\n",diferenciaPrecioIngresados);

				totalKilometros=0;
				precioTotalAA=0;
				precioTotalLatam=0;

			break;
			case 6:
				printf("Esta seguro que deseea salir? y/n\n");
				scanf("%c",&salir);
				if(salir!= 'y'){
					opcion =3;
				}else{
					printf("\nGracias por utilizar BrunoServices\n");
				}

			break;
			default:
				printf("ERROR. Ingrese una Opción correcta\n");
			break;
			}
	}while(opcion!=6);

	return 0;
}
