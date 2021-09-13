/*
 * funciones.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Gonza
 */

#include "funciones.h"

double OperacionesLogicas(int numeroUno , int numeroDos , char operacion)
{
	double resultado;

	switch(operacion)
	{
		case '+':
			resultado = numeroUno + numeroDos;
			break;

		case '-':
			resultado = numeroUno - numeroDos;
			break;

		case '*':
			resultado = (float)numeroUno * (float)numeroDos;
			break;

		case '/':
			if(numeroDos == 0)
			{
				resultado = -999;
			}
			else
			{
				resultado = (float)numeroUno / (float)numeroDos;
			}
			break;

		case '!':
			if(numeroUno == 0)
			{
				resultado = 1;
			}
			else
			{
				if(numeroUno > 0)
				{
					resultado = Factorial(numeroUno);
				}
				else
				{
					resultado = -1;
				}
			}
			break;
	}


	return resultado;
}

int Factorial(int valor)
{
	int respuesta;

	if(valor == 1)
	{
		respuesta = 1;
	}
	else
	{
		respuesta = valor * Factorial(valor-1);
	}

	return respuesta;
}
