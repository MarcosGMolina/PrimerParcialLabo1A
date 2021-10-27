/*
 * Trabajo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef TRABAJOFECHA_H_
#define TRABAJOFECHA_H_


#include <stdio.h>
#include <stdlib.h>
#include "Color.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Mascota.h"
#include <string.h>

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int id;
	int idMascota;
	int idServicio;
	Fecha mifecha;
	int isEmpty;
}Trabajo;


/**
 * @fn int validarFecha(Trabajo[], int)
 * @brief valida el día, mes y año que se ingresen
 *
 * @param losTrabajos
 * @param i
 * @return 0
 */
int validarFecha(Trabajo losTrabajos[],int i);
/**
 * @fn int inicializarTrabajos(Trabajo[], int)
 * @brief inicializa todas las posiciones de la lista en 0
 *
 * @param losTrabajos
 * @param tam
 * @return 0
 */
int inicializarTrabajos(Trabajo losTrabajos[],int tam);
/**
 * @fn int buscarEspacioLibreTrabajo(Trabajo[], int)
 * @brief busca el primer espacio libre disponible
 *
 * @param losTrabajos
 * @param tam
 * @return i
 */
int buscarEspacioLibreTrabajo(Trabajo losTrabajos[],int tam);

/**
 * @fn int datosTrabajo(Trabajo[], int, Mascota[], int, Servicio[], int, int, int)
 * @brief
 *
 * @param losTrabajos
 * @param tamTrabajos
 * @param lasMascotas
 * @param tamMascotas
 * @param losServicios
 * @param tamServicios
 * @param i
 * @param idTrabajo
 * @return 0
 */
int datosTrabajo(Trabajo losTrabajos[],int tamTrabajos,Mascota lasMascotas[],int tamMascotas,Servicio losServicios[],int tamServicios,int i,int idTrabajo);
/**
 * @fn int mostrarTrabajos(Trabajo[], int)
 * @brief muestra la lista de trabajos con sus datos
 *
 * @param losTrabajos
 * @param tam
 * @return 0
 */
int mostrarTrabajos(Trabajo losTrabajos[],int tam);



#endif /* TRABAJOFECHA_H_ */
