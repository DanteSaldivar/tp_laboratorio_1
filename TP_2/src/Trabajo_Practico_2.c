/*
 ============================================================================
		TRABAJO PRACTICO LABORATORIO 2

		DANTE SALDIVAR
		1-H

Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.

 ============================================================================
 */

#include "Biblioteca.h"
#include "ArrayPassenger.h"
#include "Informes.h"
#define MAX_PASSENGERS 2000
#define MAX_VUELOS 200

int main(void)
{
	setbuf(stdout, NULL);

	int opcionElegida;
	int banderaArranque = 0;
	ePassenger arrayPassengers[MAX_PASSENGERS];
	eVuelo arrayVuelos[MAX_VUELOS];

	ePassenger_initPassengers(arrayPassengers, MAX_PASSENGERS);
	eVuelo_Inicializar(arrayVuelos, MAX_VUELOS);

	do
	{
		if (!utn_GetNumero("==========================MENU==========================\n\n1-Alta de pasajero\n2-Modificar datos de Pasajeros\n"
				"3-Dar de Baja a un pasajero\n4-Informar(Lista de pasajeros):\n5-Carga forzada de Datos\n6-Salir\n\n"
				"Opcion: ", 3, 0, 7, "Esa opcion no es valida\n", &opcionElegida))
		{
			switch (opcionElegida)
			{
			case 1:
				if (banderaArranque || banderaArranque == 0)
				{
					ePassenFly_CargaDatos(arrayPassengers, MAX_PASSENGERS, arrayVuelos, MAX_VUELOS);
					banderaArranque = 1;
				}
				else
				{
					puts("ESA OPCION NO ESTA DISPONIBLE");
				}
				break;
			case 2:
				if (banderaArranque)
				{
					ePassenFly_PassengerModification(arrayPassengers, MAX_PASSENGERS, arrayVuelos, MAX_VUELOS);
				}
				else
				{
					puts("ESA OPCION NO ESTA DISPONIBLE");
				}
				break;
			case 3:
				if (banderaArranque)
				{
					ePassenger_RemovePassenger(arrayPassengers, MAX_PASSENGERS);
				}
				else
				{
					puts("ESA OPCION NO ESTA DISPONIBLE");
				}
				break;
			case 4:
				if (banderaArranque)
				{
					if (!utn_GetNumero("\n=====================INFORMAR SUBMENU=====================\n"
							"1-Listado de los pasajeros ordenados\nalfabeticamente por Apellido y tipo de pasajero.\n"
							"2-Total y promedios de los precios de los pasajes,\ny cuantos pasajeros superan el precio promedio.\n"
							"3-Listado de los pasajeros por Codigo de vuelo y\nestados de vuelos 'ACTIVO'.\n4-Salir\n\n "
							"Opcion: ", 3, 0, 5, "ERROR, Esa opcion no es valida\n", &opcionElegida))
					{
						switch (opcionElegida)
						{
						case 1:
							ePassenger_SortPassenger(arrayPassengers, MAX_PASSENGERS, 1);

							ePassenger_PrintPassengers(arrayPassengers, MAX_PASSENGERS);

							break;
						case 2:
							ePassenger_Promedios(arrayPassengers, MAX_PASSENGERS);
							break;
						case 3:
							eVuelo_Sort(arrayVuelos, MAX_VUELOS, 1);
							// ORDENO POR ID
							ePassenFly_SortPassengerByCode(arrayPassengers, MAX_PASSENGERS, arrayVuelos, MAX_VUELOS, -1);
							// ORDENO DE MENOR A MAYOR
							ePassenFly_printPassengers_Flys(arrayPassengers, MAX_PASSENGERS, arrayVuelos, MAX_VUELOS);
							break;
						}
					}
				}
				else
				{
					puts("ESA OPCION NO ESTA DISPONIBLE");
				}
				break;
			case 5:
				ePassenFly_Hardcodeo(arrayPassengers, MAX_PASSENGERS, arrayVuelos, MAX_VUELOS);
				ePassenger_PrintPassengers(arrayPassengers, MAX_PASSENGERS);
				banderaArranque = 1 ;
				break;
			}
		}
	} while (opcionElegida != 6);

	return 0;
}
