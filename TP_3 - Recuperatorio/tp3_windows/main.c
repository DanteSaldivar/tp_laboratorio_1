/****************************************************
   TRABAJO PRACTICO N3
   DANTE SALDIVAR
   DIVISION H
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "biblioteca.h"




int main()
{
	setbuf(stdout, NULL);

	int opcionMenu;
	int banderaCargaText = 1;
	int banderaCargaBin = 1;
	int banderaGuardado = 1;
	int validarAux;

	LinkedList* listaPasajeros = ll_newLinkedList();
	controller_findLastId("DataPassengers.txt", "LastId.bin");

	do
	{
		puts("----------------------------------------------------------------------------------------------------");
		if(!utn_GetNumero("\t\tBienvenido\n\nMenu opciones:\n1)Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2)Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3)Alta de pasajero.\n"
				"4)Modificar datos de pasajero.\n5)Baja de pasajero.\n6)Listar pasajeros.\n7)Ordenar pasajeros.\n"
				"8)Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9)Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10)Salir\nOpcion: ", 3, 0, 11, "\nNUMERO NO VALID0\n", &opcionMenu))
		{
			switch(opcionMenu)
			{
			case 1:
				do
				{
					if(banderaCargaText)
					{
						if(controller_loadFromText("DataPassengers.txt", listaPasajeros))
						{
							puts("No se pudo Cargar Datos.");
						}
						else
						{
							puts("\nCarga de datos Completada.");
							banderaCargaText = 0;
							break;
						}
					}
					else
					{
						validarAux = validar_Salida_SN("\nLos datos ya han sido cargados anteriormente.\nDesea volver a"
								" Cargar los datos? S/N", "\nOpcion no valida\n", 3);
						if(validarAux)
						{
							banderaCargaText = 1;
						}
					}
				}while(validarAux != 0);
				break;
			case 2:
				do
				{
					if(banderaCargaBin)
					{
						if(controller_loadFromBinary("DataPassengers.bin", listaPasajeros))
						{
							puts("No se pudo Cargar Datos.");
						}
						else
						{
							puts("\nCarga de datos Completada.");
							banderaCargaBin = 0;
							break;
						}
					}
					else
					{
						validarAux = validar_Salida_SN("\nLos datos ya han sido cargados anteriormente.\nDesea volver a"
								" Cargar los datos? S/N", "\nOpcion no valida\n", 3);
						if(validarAux)
						{
							banderaCargaBin = 1;
						}
					}
				}while(validarAux != 0);
				break;
			case 3:
				if(controller_addPassenger(listaPasajeros))
				{
					puts("\nHubo un error al Agregar el Pasajero.\n");
				}
				break;
			case 4:
				if(controller_editPassenger(listaPasajeros))
				{
					puts("\nNo se encontro o no se pudo Editar el Pasajero.\n");
				}
				else
				{
					puts("\nModificacion completa.");
				}
				break;
			case 5:
				if(controller_removePassenger(listaPasajeros))
				{
					puts("\nNo se encontro o no se pudo remover el Pasajero.");
				}
				else
				{
					puts("\nSe ha eliminado el Pasajero.");
				}
				break;
			case 6:
				if(controller_ListPassenger(listaPasajeros))
				{
					puts("No hay datos para Listar.");

				}
				break;
			case 7:
				if(controller_sortPassenger(listaPasajeros))
				{
					puts("No fue posible ordenar.");
				}
				break;
			case 8:
			case 9:
				controller_saveAsText("DataPassengers.txt",listaPasajeros);
				controller_saveAsBinary("DataPassengers.bin",listaPasajeros);
				banderaGuardado = 0;
				break;
			case 10:
				if(banderaGuardado)
				{
					puts("Necesita guardar antes de salir\n");
					opcionMenu = 11;
				}
				break;
			}
		}
		else
		{
			break; // PARA QUE DEJE DE ITERAR
		}

	}while(opcionMenu != 10);


return 0;
}

