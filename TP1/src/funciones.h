/*
 * funciones.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Gonza
 */

#include <stdio.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief Permite realizar una operacion matematica basica, devolviendo el resultado de la misma
/// @param numeroUno Es el primer operando de la operacion
/// @param numeroDos Es el segundo operando de la operacion
/// @param operador Es el indicador de tipo caracter, que determinara que operacion se realizara
/// @return Es el resultado de la operacion entre los numeros
double OperacionesLogicas(int numeroUno, int numeroDos, char operador);


/// @brief Nos permite ingresar un numero y calcular su factorial
/// @param  valorAFactorear
/// @return Nos devuelve el factorial del numero ingresado
int Factorial(int valorAFactorear);

#endif /* FUNCIONES_H_ */
