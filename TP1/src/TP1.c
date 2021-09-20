/*
 ============================================================================
 Name        : TP1.c
 Author      : Gonza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"
#include "conio.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	float operandoUno;
	int banderaOperandoUno;
	float operandoDos;
	int banderaOperandoDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	long double resultadoFactorialA;
	long double resultadoFactorialB;
	int banderaCaseTres;

	banderaOperandoUno = 1;
	banderaOperandoDos = 1;
	banderaCaseTres = 1;

	do
	{
		if(banderaOperandoUno == 1)
		{
			printf("1. Ingresar 1er operando (A = X): ");
		}
		else
		{
			printf("1. Ingresar 1er operando (A = %.2f): ", operandoUno);
		}
		if(banderaOperandoDos == 1)
		{
			printf("\n2. Ingresar 2do operando (B = Y): ");
		}
		else
		{
			printf("\n2. Ingresar 2do operando (B = %.2f): ", operandoDos);
		}
		opcion = IngresarNumero("\n3. Calcular todas las operaciones: \n4. Informar resultados: \n5. Salir: \nIngrese la opcion deseada: ");
		system("cls");
		switch(opcion)
		{
			case 1:
				operandoUno = IngresarNumero("Ingrese un 1er operando: ");
				banderaOperandoUno = 0;
				system("cls");
				break;

			case 2:
				operandoDos = IngresarNumero("Ingrese un 2do operando: ");
				banderaOperandoDos = 0;
				system("cls");
				break;

			case 3:
				if(banderaOperandoUno == 1)
				{
					operandoUno = IngresarNumero("Para realizar las operaciones, por favor ingrese un 1er operando: ");
					banderaOperandoUno = 0;
				}
				if(banderaOperandoDos == 1)
				{
					operandoDos = IngresarNumero("Para realizar las operaciones, por favor ingrese un 2do operando: ");
					banderaOperandoDos = 0;
				}
				system("cls");
				resultadoSuma = OperacionesLogicas(operandoUno, operandoDos, '+');
				resultadoResta = OperacionesLogicas(operandoUno, operandoDos, '-');
				resultadoMultiplicacion = OperacionesLogicas(operandoUno, operandoDos, '*');
				resultadoDivision = OperacionesLogicas(operandoUno, operandoDos, '/');
				resultadoFactorialA = OperacionesLogicas(operandoUno, 0, '!');
				resultadoFactorialB = OperacionesLogicas(operandoDos, 0, '!');
				banderaCaseTres = 0;
				printf("a) Calcular la suma (A + B)\nb) Calcular la resta (A - B)\nd) Calcular la multiplicacion (A * B)\nc) Calcular la division (A / B)\ne) Calcular el factorial (A!)\nTodas las operaciones han sido calculadas, volver atras");
				getch();
				system("cls");
				break;

			case 4:
				if(banderaCaseTres == 1)
				{
					printf("Por favor, primero calcule las operaciones antes de mostrar los resultados");
					getch();
					system("cls");
				}
				else
				{
					printf("El resultado de A + B es: %.2f\nEl resultado de A - B es: %.2f\nEl resultado de A * B es: %.2f", resultadoSuma, resultadoResta, resultadoMultiplicacion);
					if(operandoDos == 0)
					{
						printf("\nEl resultado de A / B es: la division sobre 0 no es posible");
					}
					else
					{
						printf("\nEl resultado de A / B es: %.2f", resultadoDivision);
					}
					if(operandoUno < 0 || ValidarFlotante(operandoUno) == 1)
					{
						printf("\nEl factorial de A es: no es posible realizar el factorial de un numero con decimales o negativo");
					}
					else
					{
						printf("\nEl factorial de A es: %.0Lf", resultadoFactorialA);
					}
					if(operandoDos < 0 || ValidarFlotante(operandoDos) == 1)
					{
						printf("\nEl factorial de B es: no es posible realizar el factorial de un numero con decimales o negativo");
					}
					else
					{
						printf("\nEl factorial de B es: %.0Lf", resultadoFactorialB);
					}
					getch();
					system("cls");
				}
				break;
		}
	}
	while(opcion != 5);

	return EXIT_SUCCESS;
}
