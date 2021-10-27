/*
 * Tipo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef TIPO_H_
#define TIPO_H_
#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "TrabajoFecha.h"
#include "Color.h"
#include "Servicio.h"
#include <string.h>

typedef struct
{
	int id;//comienza en 1000
	char descripcion[20];
}Tipo;

/**
 * @fn int mostrarTipos(Tipo[], int)
 * @brief muestra los tipos
 *
 * @param losTipos
 * @param tam
 * @return 0
 */
int mostrarTipos(Tipo losTipos[],int tam);

#endif /* TIPO_H_ */
