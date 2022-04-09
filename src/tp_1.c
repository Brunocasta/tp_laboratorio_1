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

int PedirEntero(char mensaje[]);
int ValidarLimite(int numero,int limiteInferior);
void Descuento(int a,float descuento);
void Interes(int b,float interes);
void BitcoinValor(int c);
void PrecioUnitario ( int numero,float precioUnitario);

int main() {
	setbuf(stdout,NULL);
	int x,y,z;

	//kilometros
	x=PedirEntero("Ingresar Kilometros :");
	//printf("\nKms Ingresados: %d kms",x);
	//ValidarLimite(x,-1);
	/*printf("Ingresar Kilometros :");
	scanf("%d",&x);
	x=ValidarLimite(x,1);
	/*printf("Precio vuelo Aerolineas: ");
	scanf("%d",&y);
	printf("Precio vuelo Latam: ");
	scanf("%d",&z);*/
	y=PedirEntero("Precio vuelo Aerolineas :");

	z=PedirEntero("Precio vuelo Latam: ");




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

	return 0;
}
int PedirEntero(char mensaje[])//establezco para mostrar un mensaje,y los limite
{
    int numero;

    printf("%s", mensaje);
    scanf("%d",&numero);
    numero=ValidarLimite(numero,1);

    return numero;
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
	printf("\nEl total con descuento es :$%2.f",descuentoTotal);
}
void Interes(int b,float interes)
{
	float interesTotal;
	interesTotal= b * interes;
	printf("\nEl total con Interese es :$%2.f",interesTotal);
}
void BitcoinValor(int c)
{
	double bitcoin
		, totalBitcoin;
	bitcoin= 4606954.55;

	totalBitcoin= c/bitcoin;
	printf("\nEl valor en Bitcoin es :%f BTN",totalBitcoin);

}
void PrecioUnitario ( int numero,float precioUnitario)
{
	float totalUnitario;
	totalUnitario =numero /precioUnitario;
	printf("\nEl precio unitario del vuelo es:%f",totalUnitario);


}

