/*
 * ingresoDatos.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Gonza
 */

#include <stdio.h>
#ifndef INGRESODATOS_H_
#define INGRESODATOS_H_

/// @brief Nos permite ingresar un valor numerico y retornarlo para almacenarlo
/// @param mensaje Es el array de caracteres que imprimira en pantalla para especificar que valor debemos ingresar
/// @return Es el valor que ingresamos, devuelto para que sea posible almacenarlo
int NumeroIngresado(char mensaje[]);

char CaracterIngresado(char mensaje[]);

#endif /* INGRESODATOS_H_ */
