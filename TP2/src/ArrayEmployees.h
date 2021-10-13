/*
 * employee.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Gonza
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "biblioteca.h"

#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int findFirstEmptyPosition(Employee* list, int len);
int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int len);
int registerEmployee(Employee* list, int len, int* id);
int modifyEmployee(Employee* list, int len);
int deleteEmployee(Employee* list, int len);
int printEmployeeListAndAverageSalary(Employee* list, int len);
int calculateAverageSalary(Employee* list, int len, float* salaryAccumulator, float* averageSalary, int* aboveAverageSalaryCounter);

#endif /* EMPLOYEE_H_ */
