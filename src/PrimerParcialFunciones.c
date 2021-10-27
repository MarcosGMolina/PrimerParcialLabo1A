/*
 * PrimerParcialFunciones.c
 *
 *  Created on: 20 oct. 2021
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
int inicializarMascotas(Mascota lasMascotas[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		lasMascotas[i].isEmpty=0;
	}

	return 0;
}

int buscarEspacioLibre(Mascota lasMascotas[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(lasMascotas[i].isEmpty==0)
		{
			break;
		}
	}
	return i;
}
int ocuparEspacioLibre(Mascota lasMascotas[],int tam)
{
	int i;
	i=buscarEspacioLibre(lasMascotas,tam);
	if(i!=-1)
	{
		lasMascotas[i]=datosMascota();
		lasMascotas[i].isEmpty=1;
	}
	return i;
}

Mascota datosMascota()
{
	Mascota miMascota;

	printf("\nIngrese el id de la mascota:  ");
	scanf("%d",&miMascota.id);
	fflush(stdin);


	printf("\nIngrese el nombre de la mascota:  ");
	gets(miMascota.nombre);
	fflush(stdin);

	printf("\nIngrese el id del Tipo de mascota, debe ser mayor a 1000:  ");
	scanf("%d",&miMascota.idTipo);
	while(miMascota.idTipo<1000)
	{
		printf("\nError, reingrese el id del tipo, debe ser mayor a 1000:  ");
		scanf("%d",&miMascota.idTipo);
	}

	printf("\nIngrese el id del Color, debe ser mayor a 5000:  ");
	scanf("%d",&miMascota.idColor);
	while(miMascota.idColor<5000)
	{
		printf("\nError, reingrese el id del color, debe ser mayor a 5000:  ");
		scanf("%d",&miMascota.idColor);
	}

	printf("\nIngrese la edad de la mascota:  ");
	scanf("%d",&miMascota.edad);
	while(miMascota.edad<0)
		{
			printf("\nError, reingrese la edad de la mascota:  ");
			scanf("%d",&miMascota.edad);
		}

	fflush(stdin);
	printf("\nIngrese el estado de vacunado s/n:  ");
	scanf("%c",&miMascota.vacunado);

	return miMascota;
}

int encontrarMascota(Mascota lasMascotas[],int tam,int id)
{
	int i;
	int MascotaEncontrada;
	MascotaEncontrada=0;

	for(i=0;i<tam;i++)
	{
		if(id==lasMascotas[i].id)
		{
			printf("\nSe encontró la mascota.  ");
			MascotaEncontrada=1;
			break;
		}

	}
	if(MascotaEncontrada==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int modificarMascota(Mascota lasMascotas[],int tam, int indice)
{

	printf("\nIngrese el nuevo valor del Tipo:  ");
	scanf("%d",&lasMascotas[indice].idTipo);
	while(lasMascotas[indice].idTipo<1000)
	{
		printf("\nError, reingrese el id del tipo:  ");
		scanf("%d",&lasMascotas[indice].idTipo);
	}

	fflush(stdin);
	printf("\nIngrese el nuevo estado del vacunado s/n:  ");
	scanf("%c",&lasMascotas[indice].vacunado);

	printf("\nLos datos se han modificado.  ");
	return 0;
}
int bajaMascota(Mascota lasMascotas[],int tam,int indice)
{
	int opcionIngresada;

	printf("¿Esta seguro que desea dar de baja a la mascota? Presione 1 para confirmar o 2 para cancelar: ");
	scanf("%d",&opcionIngresada);
	if(opcionIngresada==1)
	{
		lasMascotas[indice].isEmpty=0;
		printf("\nMascota dada de baja.  ");
	}
	else
	{
		printf("\nOperación cancelada. \n");
	}
	return 0;
}
int ordenarMascotas(Mascota lasMascotas[],int tam)
{
	int i;
	int j;
	int retorno=-1;
	Mascota auxId;
	Mascota auxNombre;
	for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(lasMascotas[i].id>lasMascotas[j].id)
				{
					auxId=lasMascotas[i];
					lasMascotas[i]=lasMascotas[j];
					lasMascotas[j]=auxId;
				}
				if(strcmp(lasMascotas[i].nombre, lasMascotas[j].nombre)>0)
				{
					auxNombre=lasMascotas[i];
					lasMascotas[i]=lasMascotas[j];
					lasMascotas[j]=auxNombre;
				}
			}
		}
	retorno=0;
	return retorno;
}
int mostrarMascotas(Mascota lasMascotas[],int tam,Cliente losClientes[],int tamClientes)
{
	int i;
	int j;
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tamClientes;j++)
		{
			if(lasMascotas[i].isEmpty!=0)
			{
				if(lasMascotas[i].idCliente==losClientes[i].id)
				{
					printf("%d  %s  %d  %d  %d  %c  %s", lasMascotas[i].id, lasMascotas[i].nombre, lasMascotas[i].idTipo,
														lasMascotas[i].idColor, lasMascotas[i].edad, lasMascotas[i].vacunado
														,losClientes[j].nombre);
				}

			}
		}


	}
	return 0;
}
int mostrarTipos(Tipo losTipos[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  ",losTipos[i].descripcion);
	}
	return 0;
}
int mostrarColores(Color losColores[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  ",losColores[i].nombreColor);
	}
	return 0;
}
int mostrarServicios(Servicio misServicios[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  %d  ",misServicios[i].descripcion, misServicios[i].precio);
	}
	return 0;
}
int mostrarMascotasColores(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores)
{
	int i;
	int j;
	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamColores;j++)
		{
			if(losColores[j].id==lasMascotas[i].idColor)
			{
				printf("Id Color: %d  Color: %s Mascotas:  %s", losColores[i].id,losColores[i].nombreColor,lasMascotas[i].nombre);
			}

		}
	}

	return 0;
}
int mascotasVacunadas(Mascota lasMascotas[],int tamMascotas, int contadorTotal)
{
	int i;
	int mascotasVacunadas=0;
	int promedioVacunado=0;
	char miChar="s";


	for(i=0;i<tamMascotas;i++)
	{
		if(strcmp(lasMascotas[i].vacunado,miChar)==0)
		{
			mascotasVacunadas++;
			promedioVacunado=mascotasVacunadas/ contadorTotal;
			printf("El promedio de mascotas vacunadas sobre el total ingresado es de:  %d",promedioVacunado);
		}
	}
	return 0;
}
int mascotasMenores(Mascota lasMascotas[],int tamMascotas)
{
	int i;
	int contadorEdad;
	for(i=0;i<tamMascotas;i++)
	{
		if(lasMascotas[i].edad<6)
		{
			contadorEdad++;
			printf("Las mascotas menores de edad son: %d", contadorEdad);
		}
	}
	return 0;
}
int mostrarMascotasTipo(Mascota lasMascotas[],int tamMascotas,Tipo LosTipos[],int tamTipos)
{
	int i;
	int j;
	int tipos=0;;
	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamTipos;j++)
		{
			switch(tipos)
			{
				case 1000:
					printf("%d %s %s", LosTipos[j].id, LosTipos[j].descripcion, lasMascotas[i].nombre);
				break;

				case 1001:
					printf("%d %s %s", LosTipos[j].id, LosTipos[j].descripcion, lasMascotas[i].nombre);
				break;

				case 1002:
					printf("%d %s %s", LosTipos[j].id, LosTipos[j].descripcion, lasMascotas[i].nombre);
				break;

				case 1003:
					printf("%d %s %s", LosTipos[j].id, LosTipos[j].descripcion, lasMascotas[i].nombre);
				break;

				case 1004:
					printf("%d %s %s", LosTipos[j].id, LosTipos[j].descripcion, lasMascotas[i].nombre);
				break;
			}
		}
	}
	return 0;
}
int mostrarColorTipo(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores,Tipo LosTipos[],int tamTipos)
{
	int i;
	int j;
	int k;
	int contador;
	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamColores;j++)
		{
			for(k=0;k<tamTipos;k++)
			{
				if(lasMascotas[i].idTipo==1003)
				{
					if(lasMascotas[i].idColor==5003)
					{
						contador++;
						printf("La cantidad de gatos de color gris es de:  %d",contador);
					}
				}
			}

		}
	}
	return 0;
}
int colorMayorCantidad(Mascota lasMascotas[],int tamMascotas,Color losColores[],int tamColores)
{
	int i;
	int j;
	int colores=0;
	int contadorNegro=0;
	int contadorBlanco=0;
	int contadorRojo=0;
	int contadorGris=0;
	int contadorAzul=0;
	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamColores;j++)
		{
			switch(colores)
			{
				case 5000:
					contadorNegro++;
				break;

				case 5001:
					contadorBlanco++;
				break;

				case 5002:
					contadorRojo++;
				break;

				case 5003:
					contadorGris++;
				break;

				case 5004:
					contadorAzul++;
				break;
			}
			if(contadorNegro>contadorBlanco && contadorNegro>contadorRojo && contadorNegro> contadorGris && contadorNegro>contadorAzul)
			{
				printf("El color con mas cantidad de mascotas es el negro.  ");
			}
			else
			{
				if(contadorBlanco>contadorRojo && contadorBlanco>contadorGris && contadorBlanco>contadorAzul)
				{
					printf("El color con más cantidad de mascotas es el blanco.  ");
				}
				else
				{
					if(contadorRojo>contadorGris && contadorRojo>contadorAzul)
					{
						printf("El color con más cantidad de mascotas es el rojo.  ");
					}
					else
					{
						if(contadorGris>contadorAzul)
						{
							printf("El color con más cantidad de mascotas es el rojo.  ");
						}
						else
						{
							printf("El color con más cantidad de mascotas es el azul.  ");
						}
					}
				}
			}
		}
	}

	return 0;
}
int servicioFecha(Mascota lasMascotas[],int tamMascotas,Servicio losServicios[],int tamServicios,Trabajo losTrabajos[],int tamTrabajos)
{
	int miServicio;
	int i;
	int j;
	int k;
	printf("Ingrese el servicio a buscar:  ");
	scanf("%d", &miServicio);
	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamServicios;j++)
		{
			for(k=0;k<tamTrabajos;k++)
			{
				if(miServicio==losServicios[j].id)
				{
					printf("Id de la mascota:%d   Nombre de la mascota:%s   Día:%d  Mes:%d  Año:%d",
													lasMascotas[i].id, lasMascotas[i].nombre, losTrabajos[k].mifecha.dia
													,losTrabajos[k].mifecha.mes, losTrabajos[k].mifecha.anio);
				}
			}

		}
	}

	return 0;
}
