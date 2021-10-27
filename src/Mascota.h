/*
 * PrimerParcial.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_
#include <stdio.h>
#include <stdlib.h>
#include "TrabajoFecha.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Color.h"
#include <string.h>

typedef struct
{
	int id;
	char nombre[25];
	char sexo;
}Cliente;

typedef struct
{
	int id;
	char nombre[20];
	int idCliente;
	int idTipo;
	int idColor;
	int edad;
	char vacunado; //s o n
	int isEmpty;
}Mascota;

/**
 * @fn int inicializarMascotas(Mascota[], int)
 * @brief inicializa las posiciones de la lista de mascotas en 0
 *
 * @param lasMascotas
 * @param tam
 * @return 0
 */
int inicializarMascotas(Mascota lasMascotas[],int tam);
/**
 * @fn int buscarEspacioLibre(Mascota[], int)
 * @brief Busca el primer espacio libre con isEmpty
 *
 * @param lasMascotas
 * @param tam
 * @return i
 */
int buscarEspacioLibre(Mascota lasMascotas[],int tam);
/**
 * @fn int ocuparEspacioLibre(Mascota[], int)
 * @brief Luego de haber encontrado el espacio libre
 * pide los datos y realiza el alta
 *
 * @param lasMascotas
 * @param tam
 * @return i
 */
int ocuparEspacioLibre(Mascota lasMascotas[],int tam);
/**
 * @fn Mascota datosMascota()
 * @brief pide los datos a guardar
 *
 *
 * @return miMascota
 */
Mascota datosMascota();
/**
 * @fn int encontrarMascota(Mascota[], int, int)
 * @brief busca la mascota segun si id dentro de la lista
 *
 * @param lasMascotas
 * @param tam
 * @param id
 * @return i o -1 según encuentre o no a la mascota
 */
int encontrarMascota(Mascota lasMascotas[],int tam,int id);
/**
 * @fn int modificarMascota(Mascota[], int, int)
 * @brief pide el reingreso del vacunado y el idTipo
 *
 * @param lasMascotas
 * @param tam
 * @param indice
 * @return 0
 */
int modificarMascota(Mascota lasMascotas[],int tam, int indice);
/**
 * @fn int bajaMascota(Mascota[], int, int)
 * @brief Realiza la baja de la mascota
 *
 * @param lasMascotas
 * @param tam
 * @param indice
 * @return 0
 */
int bajaMascota(Mascota lasMascotas[],int tam,int indice);
/**
 * @fn int ordenarMascotas(Mascota[], int)
 * @brief ordena las mascotas según su id y nombre
 *
 * @param lasMascotas
 * @param tam
 * @return retorno
 */
int ordenarMascotas(Mascota lasMascotas[],int tam);
/**
 * @fn int mostrarMascotas(Mascota[], int)
 * @brief muestra los datos de las mascotas
 *
 * @param lasMascotas
 * @param tam
 * @param losClientes
 * @param tamClientes
 * @return 0
 */
int mostrarMascotas(Mascota lasMascotas[],int tam,Cliente losClientes[],int tamClientes);
/**
 * @fn int utn_getNumero(int*, char*, char*, int, int, int)
 * @brief valida un numero ingresado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return retorno
 */
int utn_getNumero(int* pResultado,char* mensaje, char*mensajeError,int minimo,int maximo,int reintentos);


int mostrarMascotasColores(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores);
int mascotasVacunadas(Mascota lasMascotas[],int tamMascotas, int contadorTotal);
int mascotasMenores(Mascota lasMascotas[],int tamMascotas);
int mostrarMascotasTipo(Mascota lasMascotas[],int tamMascotas,Tipo LosTipos[],int tamTipos);
int mostrarColorTipo(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores,Tipo LosTipos[],int tamTipos);
int colorMayorCantidad(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores);

#endif /* MASCOTA_H_ */
