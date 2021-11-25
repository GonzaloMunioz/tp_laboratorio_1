/*
 * library.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Gonza
 */

#include "biblioteca.h"

////// INGRESO //////

int IngresarEntero(char mensaje[], int* numeroIngresado)
{
	int retorno;
	char cadena[4096];

	retorno = 0;

	printf("%s", mensaje);
	scanf("%s", cadena);
	while(ValidarNumero(cadena) == 0)
	{
		printf("Error, ingrese un valor numerico: ");
		scanf("%s", cadena);
	}

	retorno = 1;
	*numeroIngresado = atoi(cadena);

	return retorno;
}

int IngresarFlotante(char mensaje[], float* numeroIngresado)
{
	int retorno;
	char cadena[4096];

	retorno = 0;

	printf("%s", mensaje);
	scanf("%s", cadena);
	while(ValidarNumero(cadena) == 0)
	{
		printf("Error, ingrese un valor numerico: ");
		scanf("%s", cadena);
	}

	retorno = 1;
	*numeroIngresado = atof(cadena);

	return retorno;
}

int IngresarCaracter(char mensaje[], char* caracter)
{
	int retorno;

	retorno = 1;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", caracter);

	return retorno;
}

int IngresarEnteroValidado(char mensaje[], int min, int max, int* pNumeroIngresado)
{
	int numeroIngresado;
	int retorno;

	retorno = 0;

	IngresarEntero(mensaje, &numeroIngresado);
	*pNumeroIngresado = numeroIngresado;
	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("El numero ingresado no corresponde con los parametros. Debe estar en un rango entre %d hasta %d\n", min, max);
		IngresarEntero(mensaje, &numeroIngresado);
		*pNumeroIngresado = numeroIngresado;
	}

	retorno = 1;

	return retorno;
}

int IngresarFlotanteValidado(char mensaje[], int min, int max, float* pNumeroIngresado)
{
	float numeroIngresado;
	int retorno;

	retorno = 0;

	IngresarFlotante(mensaje, &numeroIngresado);
	*pNumeroIngresado = numeroIngresado;
	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("El numero ingresado no corresponde con los parametros. Debe estar en un rango entre %d hasta %d\n", min, max);
		IngresarFlotante(mensaje, &numeroIngresado);
		*pNumeroIngresado = numeroIngresado;
	}

	retorno = 1;

	return retorno;
}

int IngresarCadena(char mensaje[], char* cadena)
{
	int retorno;

	retorno = 0;

	if(mensaje != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
		retorno = 1;
	}

	return retorno;
}

int IngresarNombre(char mensaje[], char mensajeError[], char* cadena)
{
	int retorno;

	retorno = 0;

	if(mensaje != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
		while(ValidarAlfa(cadena) == -1)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", cadena);
		}
		retorno = 1;
	}

	return retorno;
}

int IngresarVector(int* numeros, int tam)
{
	int i;
	int retorno;

	retorno = 0;

	for(i = 0 ; i < tam ; i++)
	{
		IngresarEntero("Ingrese un numero: ", &numeros[i]);
	}

	return retorno;
}

int IngresarCargaAleatoria(int* numeros, int tam)
{
	int i;
	int retorno;
	int pos;
	int seguir;

	seguir = 's';
	retorno = 0;

	do
	{
		numeros[i] = 0;
		for(i = 0 ; i < tam ; i++)
		{
			IngresarEntero("Ingrese posicion: ", &pos);
			IngresarEntero("Ingrese valor a cargar en el vector: ", &numeros[pos-1]);
			IngresarEntero("¿Desea seguir ingresando valores? Indique '1' o '0': ", &seguir);
		}
	}
	while(seguir == '1');

	return retorno;
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


////// FUNCIONES LOGICAS //////

int ValidarPositivo(float numeroIngresado)
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

void IntercambiarValores(int* numeroUno, int* numeroDos, int primerNumero, int segundoNumero)
{
	int auxiliar;

	auxiliar = primerNumero;
	*numeroUno = segundoNumero;
	*numeroDos = auxiliar;
}

void OrdenarDatos(int valor[], int tam)
{
	int i;
	int j;
	int auxInt;

	for(i = 0 ; i < tam - 1 ; i++)
	{
		for(j = i + 1; j < tam ; j++)
		{
			if(valor[i] < valor[j])
			{
				auxInt = valor[i];
				valor[i] = valor[j];
				valor[j] = auxInt;
			}
		}
	}
}

int RetornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[])
{
	int retorno;

	retorno = 0;

	if(nombre != NULL && apellido != NULL)
	{
		strcpy(nombreCompleto, apellido);
		strcat(nombreCompleto,", ");
		strcat(nombreCompleto, nombre);
		retorno = 1;
	}

	return retorno;
}

int FormatearCadena(char cadena[])
{
	int i;
	int tam;
	int retorno;

	retorno = 0;
	tam = strlen(cadena);

	strlwr(cadena);

	if(cadena != NULL)
	{
		for(i = 0 ; i < tam ; i++)
		{
			if(i == 0 || cadena[i-1] == 32)
			{
				cadena[i] = toupper(cadena[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}

int ValidarNumero(char *cadena)
{
	int i;
	int retorno;
	int contadorPuntos;

	i = 0;
	retorno = 1;
	contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0)
	{
		for (i = 0; cadena[i] != '\0'; i++)
		{
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0')
			{
				if (cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int ValidarAlfa(char *cadena)
{
	int i;
	int retorno;
	int banderaNoAlfabetico;

	i = 0;
	banderaNoAlfabetico = 0;
	retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while((i < strlen(cadena) || cadena[i] != '\0') && banderaNoAlfabetico == 0)
		{
			if(!isalpha(cadena[i]))
			{
				banderaNoAlfabetico = 1;
				retorno = -1;
			}
			else
			{
				i++;
			}
		}
	}

	return retorno;
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

		case 'P':
			resultado = numeroUno / numeroDos;
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
