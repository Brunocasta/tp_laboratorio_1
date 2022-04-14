
#include "funcionesValidar.h"


int PedirEntero(char mensaje[])//establezco para mostrar un mensaje,y los limite
{
    int numero;

    printf("%s", mensaje);
    scanf("%d",&numero);
    numero=ValidarLimite(numero,1);

    return numero;
}
float PedirFlotante(char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f",&numero);
	numero=ValidarLimiteFlotante(numero,1);

	return numero;
}
float ValidarLimiteFlotante(float numero,int limiteInferior)
{

    while(numero<limiteInferior)
    {
        printf("ERROR...Por Favor,ingrese nuevamente los datos : ");
        scanf("%f",&numero);
    }
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

int MostrarMenu(void)
{
	int opcion;
	printf("\n           Men%c",151);
	printf("\n1) Ingresar KMs de Vuelo");
	printf("\n2) Ingresar Precios de Vuelos");
	printf("\n3) Calcular costos de los Vuelos");
	printf("\n4) Informaci%cn de Resultados",149);
	printf("\n5) Carga Forzada de Datos");
	printf("\n6) Salir del Programa ");
	printf("\nElegir una Opci%cn:",149);
	scanf("%d",&opcion);

	return opcion;
}
