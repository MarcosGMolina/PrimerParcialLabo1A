/*
 * InputPrimerParcial.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */
#include <string.h>
#include <stdio.h>
#include "TrabajoFecha.h"
int utn_getNumero(int* pResultado,char* mensaje, char*mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		printf("%s",mensaje);
		scanf("%d", &bufferInt);
		if(bufferInt >= minimo && bufferInt<= maximo)
		{
			*pResultado= bufferInt;
			retorno=0;
		}
		else
		{
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
int validarFecha(Trabajo misTrabajos[],int i)
{
	int dia;
	int mes;
	int anio;
	printf("Ingrese un día: ");
	scanf("%d",&dia);

	/*do
	{
		printf("Error al ingresar el día");
		scanf("%d",&dia);
	}while(dia<1 || dia>31);*/
	while(dia<1 || dia>31)
	{
		printf("\nError al ingresar el día. Intente nuevamente:  ");
		scanf("%d",&dia);
	}

	/*printf("Ingrese un mes de 01 a 12");
	scanf("%d",&mes);
	do
	{
		printf("Error al ingresar el mes");
		scanf("%d",&mes);
	}while(mes<1 || mes>12);*/

	printf("\nIngrese un mes de 01 a 12: ");
	scanf("%d",&mes);

	while(mes<1 || mes>12)
		{
			printf("\nError al ingresar el mes");
			scanf("%d",&mes);
		}

	/*printf("Ingrese un año de 00 a 99");
	scanf("%d",&anio);
	do
	{
		printf("Error al ingresar el año");
		scanf("%d",&anio);
	}while(anio<00);*/

	printf("\nIngrese un año de 00 a 99: ");
	scanf("%d",&anio);
	while(anio<00)
			{
				printf("\nError al ingresar el año");
				scanf("%d",&anio);
			}

	while(mes==2 && dia>28)
	{
		printf("\nError, Febrero tiene solo 28 días. Ingrese el día primero y luego el  mes nuevamente.");
		scanf("%d   %d",&dia, &mes);
	}

	while((mes==4 || mes==6 || mes==9 || mes==11 ) && dia>30)
	{
		printf("\nError, El mes ingresado posee 30 días unicamente. Ingrese el día primero y luego el mes nuevamente: ");
		scanf("%d   %d",&dia, &mes);
	}

	misTrabajos[i].mifecha.dia=dia;
	misTrabajos[i].mifecha.mes=mes;
	misTrabajos[i].mifecha.anio=anio;

	return 0;
}
