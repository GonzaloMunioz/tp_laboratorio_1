/*
 * ingresoDatos.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Gonza
 */

#include "ingresoDatos.h"

int NumeroIngresado(char mensaje[])
{
	int numeroIngresado;

	printf("%s" , mensaje);
	scanf("%d" , &numeroIngresado);

	return numeroIngresado;
}

char CaracterIngresado(char mensaje[])
{
	char caracterIngresado;

	printf("%s" , mensaje);
	scanf("%c" , &caracterIngresado);

	return caracterIngresado;
}

