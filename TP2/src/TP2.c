/*
 ============================================================================
 Name        : TP2.c
 Author      : Gonza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);

	int seguir;
	int id;
	int flagRegistered;
	Employee arrayEmployees[TAM];

	id = 0;
	seguir = 0;
	flagRegistered = 0;
	initEmployees(arrayEmployees, TAM);

	do
	{
		system("cls");
		printf("1) ALTA empleado:\n2) MODIFICAR empleado:\n3) BAJA empleado:\n4) INFORMAR:");
		IngresarEnteroValidado("\nIndique la opcion deseada: ", 1, 4, &seguir);
		system("cls");
		switch(seguir)
		{
			case 1:
				if(registerEmployee(arrayEmployees, TAM, &id) == -1)
				{
					printf("Ocurrio un error, revise los campos requeridos");
					getch();
				}
				else
				{
					printf("El empleado fue dado de alta con exito\n");
					flagRegistered = 1;
					getch();
				}

				break;

			case 2:
				if(flagRegistered == 1)
				{
					if(modifyEmployee(arrayEmployees, TAM) == -1)
					{
						printf("Ocurrio un error, revise los campos requeridos");
						getch();
					}
					else
					{
						printf("El empleado fue modificado con exito\n");
						getch();
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado\n");
					getch();
				}

				break;

			case 3:
				if(flagRegistered == 1)
				{
					if(deleteEmployee(arrayEmployees, TAM) == -1)
					{
						printf("Ocurrio un error, revise los campos requeridos");
						getch();
					}
					else
					{
						printf("El empleado fue dado de baja con exito\n");
						getch();
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado\n");
					getch();
				}

				break;

			case 4:
				if(flagRegistered == 1)
				{
					if(printEmployeeListAndAverageSalary(arrayEmployees, TAM) == -1)
					{
						printf("Ocurrio un error, revise los campos requeridos");
						getch();
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado\n");
					getch();
				}

				break;

		}
	}
	while(seguir != 0);

	return EXIT_SUCCESS;
}
