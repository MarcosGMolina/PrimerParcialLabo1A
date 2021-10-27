/*
 ============================================================================
 Name        : PrimerParcialLabo2021.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "TrabajoFecha.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicio.h"
#include <string.h>


#define TAMANIO 100
#define TAM 5

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int alta;
	int modificacion;
	int iEncontrado=0;
	int orden;
	int espacioLibre;
	int idTrabajo;
	int validacionPrimerPaso=-1;
	int opcionInformes;
	int contadorTotal=0;
	Mascota misMascotas[TAMANIO];
	Trabajo misTrabajos[TAMANIO];
	Cliente misClientes[TAM]={{30,"Ricardo","m"},{31,"Andrea","f"},{32,"Sandra","f"},{33,"Martín","m"},{34,"Cristina","f"}};
	Tipo misTipos[TAM]={{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};
	Color misColores[TAM]={{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};
	Servicio misServicios[3]={{20000,"Corte",450},{20001,"Desparasitado",800},{20002,"Castrado",600}};

	inicializarTrabajos(misTrabajos,TAMANIO);
	inicializarMascotas(misMascotas,TAMANIO);
	do
	{
		utn_getNumero(&opcion,"\nBienvenido al menú  \n1:Alta Mascota  \n2:Modificar Mascota  \n3:Baja Mascota  "
				"   \n4:Listar Mascotas  \n5:Listar Tipos  \n6:Listar Colores  \n7:Listar Servicios  \n8:Alta trabajo  "
				"\n9:Listar Trabajos:","Error, reingrese la opción nuevamente:",1,20,3);
		switch(opcion)
		{
			case 1:
				alta=ocuparEspacioLibre(misMascotas,TAMANIO);

				if(alta!=-1)
				{
					printf("\nAlta realizada con éxito  \n");
					contadorTotal++;
				}
				else
				{
					printf("\nNo se pudo realizar el alta");
				}
				validacionPrimerPaso=0;
			break;

			case 2:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					printf("\nIngrese el id de la mascota a encontrar:  ");
					scanf("%d",&modificacion);
					iEncontrado=encontrarMascota(misMascotas,TAMANIO,modificacion);
					if(iEncontrado!=-1)
					{
						modificarMascota(misMascotas,TAMANIO,iEncontrado);
					}
					else
					{
						printf("\nEl id de la mascota no fue encontrada.  ");
					}
				}

			break;

			case 3:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					printf("\nIngrese el id de la mascota a encontrar:  ");
					scanf("%d",&modificacion);
					iEncontrado=encontrarMascota(misMascotas,TAMANIO,modificacion);
					if(iEncontrado!=-1)
					{
						bajaMascota(misMascotas,TAMANIO,iEncontrado);
					}
					else
					{
						printf("\nEl id de la mascota no fue encontrada.  \n");
					}
				}

			break;

			case 4:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					orden=ordenarMascotas(misMascotas,TAMANIO);
					if(orden!=1)
					{

						mostrarMascotas(misMascotas,TAMANIO,misClientes,TAM);
					}
					else
					{
						printf("\nNo se puede mostrar las mascotas.  ");
					}

				}

			break;

			case 5:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					mostrarTipos(misTipos,TAM);
				}

			break;

			case 6:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					mostrarColores(misColores,TAM);
				}

			break;

			case 7:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					mostrarServicios(misServicios,TAM);
				}

			break;

			case 8:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					idTrabajo=buscarEspacioLibreTrabajo(misTrabajos,TAMANIO);

					printf("Id del trabajo:  %d\n",idTrabajo);

					espacioLibre=buscarEspacioLibreTrabajo(misTrabajos,TAMANIO);
					datosTrabajo(misTrabajos,TAMANIO,misMascotas,TAMANIO,misServicios,3,espacioLibre,idTrabajo);
					validarFecha(misTrabajos,espacioLibre);
					printf("\nAlta del trabajo realizada con éxito.  \n");
				}

			break;

			case 9:
				if(validacionPrimerPaso==-1)
				{
					printf("\nError, debe realizar el alta de una mascota.  \n");
				}
				else
				{
					mostrarTrabajos(misTrabajos,TAMANIO);
				}

			break;
			case 10:
				{
					printf("Elegir el informe a ver: "
							"1:Mostrar mascotas según color \n 2:Promedio de mascotas vacunadas sobre el total  "
							" \n3:Informar mascotas menores de edad  \n4:Mascotas separadas por tipo  "
							"\n5:Cantidad de mascotas de tipo gato color gris  \n6:Mostrar los colores con más cantidad de mascotas: ");
					scanf("%d",&opcionInformes);
					switch(opcionInformes)
					{
						case 1:
							mostrarMascotasColores(misMascotas,TAMANIO,misColores,TAM);
						break;

						case 2:
							mascotasVacunadas(misMascotas,TAMANIO,contadorTotal);
						break;

						case 3:
							mascotasMenores(misMascotas,TAMANIO);
						break;

						case 4:
							mostrarMascotasTipo(misMascotas,TAMANIO,misTipos,TAM);
						break;

						case 5:
							mostrarColorTipo(misMascotas,TAMANIO,misColores,TAM,misTipos,TAM);
						break;

						case 6:
							colorMayorCantidad(misMascotas,TAMANIO,misColores,TAM);
						break;

						case 9:
							servicioFecha(misMascotas,TAMANIO,misServicios,3,misTrabajos,TAM);

					}
				}
			break;
			case 11:
				printf("Salir del menú.  ");
			break;
		}
	}while(opcion!=11);




	return EXIT_SUCCESS;
}
