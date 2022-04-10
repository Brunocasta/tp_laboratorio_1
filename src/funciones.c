
#include "funciones.h"


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
        printf("ERROR...Por Favor,ingrese nuevamente los datos : ");
        scanf("%d",&numero);
    }
    return numero;
}

void Descuento(int a,float descuento)
{
	float descuentoTotal;

	descuentoTotal = a * descuento;
	printf("\nPrecio con Tarjeta de Debito  :$%2.f",descuentoTotal);
}

void Interes(int b,float interes)
{
	float interesTotal;
	interesTotal= b * interes;
	printf("\nPrecio con Tarjeta de Credito :$%2.f",interesTotal);
}

void BitcoinValor(int c)
{
	double bitcoin
		, totalBitcoin;
	bitcoin= 4765477.37;

	totalBitcoin= c/bitcoin;
	printf("\nEl Precio pagando con Bitcoin:%f BTC",totalBitcoin);

}

void PrecioUnitario ( int numero,float precioUnitario)
{
	float totalUnitario;
	totalUnitario =numero /precioUnitario;
	printf("\nEl Precio Unitario es:$%.3f",totalUnitario);
}

void DiferenciaEnteros(int numero1, int numero2)
{
	float totalDiferencia;
	if(numero1>numero2){
		totalDiferencia=numero1-numero2;
	}else{
		totalDiferencia=numero2-numero1;
	}
	printf("\nLa diferencia de precios es:$%.2f",totalDiferencia);
}
