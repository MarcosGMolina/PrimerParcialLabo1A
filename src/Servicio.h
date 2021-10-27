/*
 * Servicio.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "TrabajoFecha.h"
#include "Color.h"
#include "Tipo.h"
#include <string.h>

typedef struct
{
	int id;
	char descripcion[25];
	int precio;
}Servicio;

/**
 * @fn int mostrarServicios(Servicio[], int)
 * @brief muestra los servicios
 *
 * @param misServicios
 * @param tam
 * @return 0
 */
int mostrarServicios(Servicio misServicios[],int tam);


#endif /* SERVICIO_H_ */
