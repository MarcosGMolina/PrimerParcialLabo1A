/*
 * Color.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "TrabajoFecha.h"
#include "Tipo.h"
#include "Servicio.h"
#include <string.h>

typedef struct
{
	int id;
	char nombreColor[20];

}Color;

/**
 * @fn int mostrarColores(Color[], int)
 * @brief muestra los colores
 *
 * @param losColores
 * @param tam
 * @return 0
 */
int mostrarColores(Color losColores[],int tam);

#endif /* COLOR_H_ */
