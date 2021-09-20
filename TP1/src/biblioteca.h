/*
 * library.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Gonza
 */

#include <stdio.h>
#include <ctype.h>
#include "conio.h"
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

////// INGRESO //////

/// @fn float IngresarNumero(char[])
/// @brief
///
/// @param mensaje
/// @return
float IngresarNumero(char mensaje[]);

char IngresarCaracter(char mensaje[]);

float IngresarNumeroValidado(char mensaje[], int min, int max);

////// SALIDA //////

void ImprimirNumero(char mensaje[] , int numeroIngresado);
-
void ImprimirVector(char mensaje[], int numeroIngresado[], int T, char caracter);

void ImprimirVectorPosicionParImpar(char mensaje[], int numeroIngresado[], int T, char caracter);


////// FUNCIONES LOGICAS //////

int ValidarPositivo(int numeroIngresado);

int ValidarPar(int numeroIngresado);

int ValidarFlotante(float numeroIngresado);

int ContadorVector(int numeroIngresado[], int T, char caracter);

int MayorMenorNumero(int i, int numeroIngresado, int mayorMenorNumero, char caracter);

////// FUNCIONES MATEMATICAS //////

/// @brief Permite realizar una operacion matematica basica, devolviendo el resultado de la misma
/// @param numeroUno Es el primer operando de la operacion
/// @param numeroDos Es el segundo operando de la operacion
/// @param operador Es el indicador de tipo caracter, que determinara que operacion se realizara
/// @return Es el resultado de la operacion entre los numeros
double OperacionesLogicas(float numeroUno, float numeroDos, char operador);

/// @brief Nos permite ingresar un numero y calcular su factorial
/// @param  valorAFactorear Es el valor que factorizaremos, deberá ser entero
/// @return Nos devuelve el factorial del numero ingresado
long double Factorial(int valorAFactorear);


#endif /* BIBLIOTECA_H_ */
