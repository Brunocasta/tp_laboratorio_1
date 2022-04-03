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
