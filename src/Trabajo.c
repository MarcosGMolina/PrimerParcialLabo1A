/*
 * Trabajo.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Marcos
 */
#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicio.h"
#include <string.h>
#include "TrabajoFecha.h"
//TRABAJOS
int inicializarTrabajos(Trabajo losTrabajos[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		losTrabajos[i].isEmpty=0;
	}

	return 0;
}

int buscarEspacioLibreTrabajo(Trabajo losTrabajos[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(losTrabajos[i].isEmpty==0)
		{
			break;
		}
	}
	return i;
}
int datosTrabajo(Trabajo losTrabajos[],int tamTrabajos,Mascota lasMascotas[],int tamMascotas,Servicio losServicios[],int tamServicios,int i,int idTrabajo)
{
	int idMascota;
	int verificacionId;
	int idServicio;
	int flagServicio=-1;


	printf("Ingrese el id de la mascota:  ");
	scanf("%d",&idMascota);
	verificacionId=encontrarMascota(lasMascotas,100,idMascota);
	while(verificacionId==-1)
	{
		printf("Error, reingrese el id de la mascota:  \n");
		scanf("%d",&idMascota);
		verificacionId=encontrarMascota(lasMascotas,tamMascotas,idMascota);
	}

	losTrabajos[i].idMascota=idMascota;
	printf("\nIngrese el id del servicio, debe ser mayor a 20000: ");
	scanf("%d",&idServicio);
	while(flagServicio==-1)
	{

		for(int j=0;j<tamServicios;j++)
		{
			if(idServicio==losServicios[j].id)
			{
				losTrabajos[i].idServicio=idServicio;
				flagServicio=0;
				break;

			}
		}
		if(flagServicio!=0)
		{
			printf("Error, reingrese el id del servicio, debe ser mayor a 20000:  ");
			scanf("%d",&idServicio);
		}

	}

	losTrabajos[i].idServicio=idServicio;

	losTrabajos[i].id=idTrabajo;

	losTrabajos[i].isEmpty=1;

	return 0;
}
int mostrarTrabajos(Trabajo losTrabajos[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(losTrabajos[i].isEmpty!=0)
		{
			printf("Id trabajo:%d  Id mascota:%d  Id Servicio:%d  Día:%d  Mes:%d  Año:%.2d  ",losTrabajos[i].id, losTrabajos[i].idMascota, losTrabajos[i].idServicio,
											losTrabajos[i].mifecha.dia,losTrabajos[i].mifecha.mes,losTrabajos[i].mifecha.anio);
		}

	}
	return 0;
}


