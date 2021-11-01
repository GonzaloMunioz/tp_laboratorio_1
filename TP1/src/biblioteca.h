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

/// @brief Nos permite el ingreso de un numero flotante, devolviendo este mismo
/// @param mensaje Es el mensaje que imprimiremos en pantalla
/// @return Es el numero flotante ingresado
float IngresarNumero(char mensaje[]);

/// @brief Nos permite ingresar un caracter, retornando este mismo
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @return Es el caracter que ingresamos
char IngresarCaracter(char mensaje[]);

/// @brief Misma funcion que IngresarNumero, pero validando el numero en un rango maximo y minimo
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param min Valor minimo que puede ser ingresado
/// @param max Valor maximo que puede ser ingresado
/// @return Es el valor validado entre el rango
float IngresarNumeroValidado(char mensaje[], int min, int max);


////// SALIDA //////

/// @brief Imprime un numero entero en pantalla que recibe como parametro
/// @param mensaje Es el mensaje que se imprimira antes de imprimir el numero
/// @param numeroIngresado Es el numero que imprimiremos en pantalla
void ImprimirNumero(char mensaje[] , int numeroIngresado);

/// @brief Imprime un vector de enteros, en un formato de listado
/// @param mensaje Es el mensaje que se imprimira antes de imprimir el listado de numeros
/// @param numeroIngresado Es el vector que recibira como parametro para imprimirlo en pantalla
/// @param T Es el tamaño del vector
/// @param caracter Es un caracter identificativo para especializar la funcion,  'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
void ImprimirVector(char mensaje[], int numeroIngresado[], int T, char caracter);


////// FUNCIONES LOGICAS //////

/// @brief Valida la positividad, negatividad o neutralidad de un numero que recibe como parametro
/// @param numeroIngresado Es el numero que recibe como parametro para validar su signo
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = positivo, 0 = neutro, -1 = negativo
int ValidarPositivo(float numeroIngresado);

/// @brief Valida la paridad de un numero que recibe como parametro
/// @param numeroIngresado Es el numero que recibe como parametro para validar su paridad
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = par, 0 = impar
int ValidarPar(int numeroIngresado);

/// @brief Valida si un numero es entero o flotante, con decimales
/// @param numeroIngresado Es el numero que recibe como parametro para validar si tiene decimales, o no
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = flotante, 0 = entero
int ValidarFlotante(float numeroIngresado);

/// @brief Funcion que nos permite especializar los contadores para un vector
/// @param numeroIngresado Es el vector que recibe como parametro para contar
/// @param T Es el tamaño del vector
/// @param caracter Es el caracter que nos sirve para especializar la funcion,  'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
/// @return Devuelve contador, de esta forma sera posible almacenar el resultado
int ContadorVector(int numeroIngresado[], int T, char caracter);

/// @brief Funcion que nos permite especializar los acumuladores de un vector
/// @param numeroIngresado Es el vector que recibe como parametro para acumular
/// @param T Es el tamaño del vector
/// @param caracter Es el caracter que nos sirve para especializar la funcion, 'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
/// @return Devuelve acumulador, de esta forma sera posible almacenar el resultado
int AcumuladorVector(int numeroIngresado[], int T, char caracter);

/// @brief Es una funcion que nos permite identificar el mayor o menor numero ingresado en una estructura repetitiva
/// @param i Es el indice que nos ayudara a identificar si es la primer iteracion, o no
/// @param numeroIngresado Es el numero que queremos identificar si es el maximo o el minimo
/// @param mayorMenorNumero Es el mayor o menor numero actual, que utilizaremos para comparar y reasignar de ser necesario
/// @param caracter Es el caracter identificativo para especializar la funcion, '<' = menor, '>' = mayor
/// @return Devuelve el mayor o menor numero reasignado, si es necesario
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
