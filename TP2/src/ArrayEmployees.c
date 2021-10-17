/*
 * employee.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Gonza
 */

#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0 ; i < len ; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int findFirstEmptyPosition(Employee* list, int len)
{
	int i;
	int flagFound;
	int retorno;

	i = 0;
	flagFound = FALSE;
	retorno = -1;

	while(flagFound == FALSE && i < len)
	{
		if(list[i].isEmpty == TRUE)
		{
			flagFound = TRUE;
			retorno = i;
		}
		else
		{
			i++;
		}
	}

	return retorno;
}

int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int i;
	int retorno;

	retorno = -1;
	i = findFirstEmptyPosition(list, len);
	FormatearCadena(name);
	FormatearCadena(lastName);

	if(i != -1 && len > 0 && list != NULL)
	{
		list[i].id = id;
		strcpy(list[i].name, name);
		strcpy(list[i].lastName, lastName);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error, revise los campos requeridos");
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int i;
	int retorno;
	int flagFound;

	i = 0;
	retorno = -1;
	flagFound = FALSE;

	if(list != NULL && len > 0)
	{
		while(flagFound == FALSE && i < len)
		{
			if(list[i].id == id && list[i].isEmpty != TRUE)
			{
				retorno = i;
				flagFound = TRUE;
			}
			else
			{
				i++;
			}
		}
	}

	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int i;
	int retorno;

	retorno = -1;

	i = findEmployeeById(list, len, id);

	if(i != -1 && len > 0 && list != NULL)
	{
		list[i].isEmpty = TRUE;
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	int retorno;
	Employee aux;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(i = 0 ; i < len ; i++)
		{
			for(j = i + 1 ; j < len ; j++)
			{
				if(order == 1)
				{
					if((list[i].lastName < list[j].lastName) && (list[i].sector < list[j].sector) && (list[i].isEmpty == FALSE) && (list[j].isEmpty == FALSE))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
				else
				{
					if((list[i].lastName > list[j].lastName) && (list[i].sector > list[j].sector) && (list[i].isEmpty == FALSE) && (list[j].isEmpty == FALSE))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}

	return retorno;
}

int printEmployees(Employee* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("======================================================\n ID      APELLIDO     NOMBRE      SALARIO      SECTOR\n");
		for(i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty != TRUE)
			{
				printf("%3d %12s %11s %12.2f %9d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
			}
		}
		printf("======================================================\n");
		getch();
		retorno = 0;
	}

	return retorno;
}

int registerEmployee(Employee* list, int len, int* id)
{
	int retorno;
	Employee employeeOne;

	retorno = -1;

	IngresarNombre("Ingrese su nombre: ", "Por favor, ingrese un nombre real: ", employeeOne.name);
	IngresarNombre("Ingrese su apellido: ", "Por favor, ingrese un apellido real: ", employeeOne.lastName);
	IngresarFlotanteValidado("Ingrese su salario: ", 1000, 500000, &employeeOne.salary);
	IngresarEnteroValidado("Ingrese el sector: ", 0, 1000, &employeeOne.sector);

	if(addEmployees(list, len, *id, employeeOne.name, employeeOne.lastName, employeeOne.salary, employeeOne.sector) != -1)
	{
		*id = *id + 1;
		retorno = 0;
	}
	else
	{
		printf("\nOcurrio un error, revise los campos requeridos");
	}

	return retorno;
}

int modifyEmployee(Employee* list, int len)
{
	int id;
	int indexEmployee;
	int option;
	int retorno;

	retorno = -1;

	IngresarEntero("Ingrese el ID del empleado que desea modificar: ", &id);
	system("cls");
	indexEmployee = findEmployeeById(list, len, id);

	if(indexEmployee != -1 && list != NULL)
	{
		IngresarEnteroValidado("1. Nombre\n2. Apellido\n3. Salario\n4. Sector\nIndique la opcion que desea modificar: ", 1, 4, &option);
		system("cls");
		switch(option)
		{
			case 1:
				IngresarNombre("Ingrese su nombre modificado: ", "Por favor, ingrese un nombre real: ", list[indexEmployee].name);
				break;

			case 2:
				IngresarNombre("Ingrese su apellido modificado: ", "Por favor, ingrese un nombre real: ", list[indexEmployee].lastName);
				break;

			case 3:
				IngresarFlotanteValidado("Ingrese su nuevo salario: ", 1000, 500000, &list[indexEmployee].salary);
				break;

			case 4:
				IngresarEnteroValidado("Ingrese su nuevo sector: ", 0, 1000, &list[indexEmployee].sector);
				break;
		}
		retorno = 0;
	}

	return retorno;
}

int deleteEmployee(Employee* list, int len)
{
	int id;
	int retorno;

	retorno = -1;

	if(list != NULL)
	{
		IngresarEntero("Ingrese el ID del empleado que desea dar de baja: ", &id);
		removeEmployee(list, len, id);
		retorno = 0;
	}

	return retorno;
}

int printEmployeeListAndAverageSalary(Employee* list, int len)
{
	int order;
	int retorno;
	float salaryAccumulator;
	float averageSalary;
	int aboveAverageSalaryCounter;
	int option;

	retorno = -1;
	salaryAccumulator = 0;
	aboveAverageSalaryCounter = 0;

	if(list != NULL && len > 0)
	{
		IngresarEnteroValidado("Que desea informar?\n1. Listado de empleados ordenados alfabeticamente por apellido y sector\n2. Total y promedio de salarios, y cuantos empleados superan el salario promedio\nIndique: ", 1, 2, &option);
		system("cls");
		switch(option)
		{
			case 1:
				IngresarEnteroValidado("Como desea ordenar el listado de empleados?\n1. Ascendente\n0. Descendente\nIndique: ", 0, 1, &order);
				sortEmployees(list, len, order);
				printEmployees(list, len);
				break;

			case 2:
				calculateAverageSalary(list, len, &salaryAccumulator, &averageSalary, &aboveAverageSalaryCounter);
				printf("El total de los salarios es: %.2f\n", salaryAccumulator);
				printf("El promedio de los salarios es: %.2f\n", averageSalary);
				printf("La cantidad de empleados que superan el salario promedio es: %d\n", aboveAverageSalaryCounter);
				getch();
				break;
		}

		retorno = 0;
	}

	return retorno;
}

int calculateAverageSalary(Employee* list, int len, float* salaryAccumulator, float* averageSalary, int* aboveAverageSalaryCounter)
{
	int i;
	int employeeCounter;
	int retorno;

	retorno = -1;
	employeeCounter = 0;

	if(list != NULL && len > 0)
	{
		for(i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty != TRUE)
			{
				*salaryAccumulator += list[i].salary;
				employeeCounter++;
			}
		}
		*averageSalary = *salaryAccumulator / employeeCounter;
		for(i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty != TRUE && list[i].salary > *averageSalary)
			{
				*aboveAverageSalaryCounter = *aboveAverageSalaryCounter + 1;
			}
		}
		retorno = 0;
	}

	return retorno;
}










