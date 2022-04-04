/*
 ============================================================================
 Name        : tp_1.c
 Author      : Bruno Castagnola 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int ValidarLimite(int numero,int limiteInferior);
void Descuento(int a,float descuento);
void Interes(int b,float interes);
void BitcoinValor(int c);

int main() {
	setbuf(stdout,NULL);
	int x,y,z;

	printf("Ingresar Kilometros :");
	scanf("%d",&x);
	x=ValidarLimite(x,0);

	printf("Precio vuelo Aerolineas: ");
	scanf("%d",&y);

	printf("Precio vuelo Latam: ");
	scanf("%d",&z);

	//DESCUENTO AEROLINEAS
	Descuento(y,0.9);
	//DESCUENTO LATAM
	Descuento(z,0.9);
	//INTERES AEROLINEAS
	Interes(y,1.25);
	//INTERES AEROLINEAS
	Interes(z,1.25);

	BitcoinValor(y);

	return 0;
}

int ValidarLimite(int numero,int limiteInferior)
{

    while(numero<limiteInferior)
    {
        printf("ERROR, Ingrese nuevamente los datos : ");
        scanf("%d",&numero);
    }
    return numero;
}
void Descuento(int a,float descuento)
{
	float descuentoTotal;

	descuentoTotal = a * descuento;
	printf("\nEl total con descuento es :%2.f",descuentoTotal);
}
void Interes(int b,float interes)
{
	float interesTotal;
	interesTotal= b * interes;
	printf("\nEl total con Interese es :%2.f",interesTotal);
}
void BitcoinValor(int c)
{
	float bitcoin
		, totalBitcoin;
	bitcoin= 4606954.55;

	totalBitcoin= c/bitcoin;
	printf("\nEl valor en Bitcoin es :%2.f",totalBitcoin);

}



