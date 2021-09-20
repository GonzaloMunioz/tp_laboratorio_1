/*
 * library.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Gonza
 */

#include "biblioteca.h"

////// INGRESO //////

float IngresarNumero(char mensaje[])
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

char IngresarCaracter(char mensaje[])
{
	char caracterIngresado;

	printf("%s", mensaje);
	scanf("%c", &caracterIngresado);

	return caracterIngresado;
}


float IngresarNumeroValidado(char mensaje[], int min, int max)
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("El numero ingresado no corresponde con los parámetros. Debe estar en un rango entre %d hasta %d: ", min, max);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

////// SALIDA //////

void ImprimirNumero(char mensaje[], int numeroIngresado)
{
	printf("%s", mensaje);
	printf("\n\t- %d", numeroIngresado);
}

void ImprimirVector(char mensaje[], int numeroIngresado[], int T, char caracter)
{
	int i;

	printf("%s", mensaje);

	for(i = 0 ; i < T ; i++)
	{
		switch(caracter)
		{
			case 'T':
				printf("\n\t- %d", numeroIngresado[i]);
				break;

			case 'P':
				if(ValidarPar(numeroIngresado[i]) == 1)
				{
					printf("\n\t- %d", numeroIngresado[i]);
				}
				break;

			case 'I':
				if(ValidarPar(numeroIngresado[i]) == 0)
				{
					printf("\n\t- %d", numeroIngresado[i]);
				}
				break;

			case '+':
				if(ValidarPositivo(numeroIngresado[i]) == 1)
				{
					printf("\n\t- %d", numeroIngresado[i]);
				}
				break;

			case '-':
				if(ValidarPositivo(numeroIngresado[i]) == -1)
				{
					printf("\n\t- %d", numeroIngresado[i]);
				}
				break;

			case '0':
				if(ValidarPositivo(numeroIngresado[i]) == 0)
				{
					printf("\n\t- %d", numeroIngresado[i]);
				}
				break;
		}
	}
}

void ImprimirVectorPosicionParImpar(char mensaje[], int numeroIngresado[], int T, char caracter)
{
	int i;

	printf("%s", mensaje);

	for(i = 0 ; i < T ; i++)
	{
		while(caracter != 'P' && caracter != 'I')
		{
			printf("Error, el caracter ingresado no corresponde, indique 'P' (par) o 'I' (impar): ");
			scanf("%c", &caracter);
		}
		switch(caracter)
		{
			case 'P':
				if(ValidarPar(i) == 1)
				{
					printf("\n\t- El valor de la posicion par [%d] es: %d", i, numeroIngresado[i]);
				}
				break;

			case 'I':
				if(ValidarPar(i) == 0)
				{
					printf("\n\t- El valor de la posicion impar [%d] es: %d", i, numeroIngresado[i]);
				}
				break;
		}
	}
}


////// FUNCIONES LOGICAS //////

int ValidarPositivo(int numeroIngresado)
{
	int resultado;

	if(numeroIngresado > 0)
	{
		resultado = 1;
	}
	else
	{
		if(numeroIngresado < 0)
		{
			resultado = -1;
		}
		else
		{
			resultado = 0;
		}
	}

	return resultado;
}

int ValidarPar(int numeroIngresado)
{
	int respuesta;

	if((numeroIngresado % 2) == 0)
	{
		respuesta = 1;
	}
	else
	{
		respuesta = 0;
	}

	return respuesta;
}

int ValidarFlotante(float numeroIngresado)
{
	int enteroDeNumeroIngresado;
	float resultado;
	int respuesta;

	enteroDeNumeroIngresado = numeroIngresado;
	resultado = numeroIngresado - enteroDeNumeroIngresado;

	if(resultado != 0)
	{
		respuesta = 1;
	}
	else
	{
		respuesta = 0;
	}

	return respuesta;
}

int ContadorVector(int numeroIngresado[], int T, char caracter)
{
	int i;
	int contador;

	contador = 0;

	for(i = 0 ; i < T ; i++)
	{
		while(caracter != 'T' && caracter != 'P' && caracter != 'I' && caracter != '+' && caracter != '-' && caracter != '0')
		{
			printf("Error, el caracter ingresado no corresponde, indique 'T' (todos), 'P' (par) o 'I' (impar), '+' (positivo), '-' (negativo) o '0' (neutro): ");
			scanf("%c", &caracter);
		}
		switch(caracter)
		{
		case 'T':
			contador++;
			break;

		case 'P':
			if(ValidarPar(numeroIngresado[i]) == 1)
			{
				contador++;
			}
			break;

		case 'I':
			if(ValidarPar(numeroIngresado[i]) == 0)
			{
				contador++;
			}
			break;

		case '+':
			if(ValidarPositivo(numeroIngresado[i]) == 1)
			{
				contador++;
			}
			break;

		case '-':
			if(ValidarPositivo(numeroIngresado[i]) == -1)
			{
				contador++;
			}
			break;

		case '0':
			if(ValidarPositivo(numeroIngresado[i]) == 0)
			{
				contador++;
			}
			break;
		}
	}

	return contador;
}

int AcumuladorVector(int numeroIngresado[], int T, char caracter)
{
	int i;
	int acumulador;

	acumulador = 0;

	for(i = 0 ; i < T ; i++)
	{
		switch(caracter)
		{
		case 'T':
			acumulador+=numeroIngresado[i];
			break;

		case 'P':
			if(ValidarPar(numeroIngresado[i]) == 1)
			{
				acumulador+=numeroIngresado[i];
			}
			break;

		case 'I':
			if(ValidarPar(numeroIngresado[i]) == 0)
			{
				acumulador+=numeroIngresado[i];
			}
			break;

		case '+':
			if(ValidarPositivo(numeroIngresado[i]) == 1)
			{
				acumulador+=numeroIngresado[i];
			}
			break;

		case '-':
			if(ValidarPositivo(numeroIngresado[i]) == -1)
			{
				acumulador+=numeroIngresado[i];
			}
			break;

		case '0':
			if(ValidarPositivo(numeroIngresado[i]) == 0)
			{
				acumulador+=numeroIngresado[i];
			}
			break;
		}
	}

	return acumulador;
}


int MayorMenorNumero(int i, int numeroIngresado, int mayorMenorNumero, char caracter)
{
	int resultado;

	resultado = mayorMenorNumero;

	switch(caracter)
	{
		case '<':
			if(i == 0 || mayorMenorNumero < numeroIngresado)
			{
				resultado = numeroIngresado;
			}
			break;

		case '>':
			if(i == 0 || mayorMenorNumero > numeroIngresado)
			{
				resultado = numeroIngresado;
			}
			break;
	}

	return resultado;
}

////// FUNCIONES MATEMATICAS //////

double OperacionesLogicas(float numeroUno, float numeroDos, char operacion)
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
			resultado = numeroUno * numeroDos;
			break;

		case '/':
			if(numeroDos == 0)
			{
				resultado = -999;
			}
			else
			{
				resultado = numeroUno / numeroDos;
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

long double Factorial(int valor)
{
	long double respuesta;

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
