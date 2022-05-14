/**
 *  Passenger.c
 *
 *
 *
 */

#include "ArrayPassenger.h"

void ePassenger_initPassengers(ePassenger arrayDePassenger[], int tam)
{
	int i;

	if (arrayDePassenger != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			arrayDePassenger[i].isEmpty = LIBRE;
		}
	}
}

int ePassenger_ObtenerIndexLibre(ePassenger arrayPassengers[], int tam)
{
	int retorno = -1;
	int i;

	if (arrayPassengers != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayPassengers[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ePassenger_FindPassengerById(ePassenger arrayPassengers[], int tam, int ID)
{
	int retorno = -1;
	int i;

	if (arrayPassengers != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayPassengers[i].idPassenger == ID && arrayPassengers[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


void ePassenger_PrintOnePassenger(ePassenger Passenger)
{
	char tipoAuxiliar[18];
	printf("%d\t%-13s\t%-20s%3.2f", Passenger.idPassenger, Passenger.name, Passenger.lastname, Passenger.price);

	// fly code %25s
	switch (Passenger.typePassenger)
	{
	case 1:
		strncpy(tipoAuxiliar, "TURISTA/ECONOMICA", sizeof(tipoAuxiliar));
		break;
	case 2:
		strncpy(tipoAuxiliar, "EJECUTIVO", sizeof(tipoAuxiliar));
		break;
	case 3:
		strncpy(tipoAuxiliar, "PRIMERA CLASE", sizeof(tipoAuxiliar));
		break;
	}
	printf("\t\t%2s\n", tipoAuxiliar);
	puts("===================================================================================");
}

int ePassenger_PrintPassengers(ePassenger arrayPassengers[], int lenght)
{
	int retorno = -1;
	int i;
	int banderaMensaje = 1;

	puts("\n\t> LISTADO Passengers");
	if (arrayPassengers != NULL && lenght > 0)
	{
		for (i = 0; i < lenght; i++)
		{
			if (arrayPassengers[i].isEmpty == OCUPADO)
			{
				if (banderaMensaje)
				{
					printf("%2s%12s%18s%23s%25s\n", "ID", "NOMBRE", "APELLIDO", "GASTO VUELO", "TIPO DE PASAJERO");
					//,%25s "CODIGO DE VUELO"
					puts("===================================================================================");
					banderaMensaje = 0;
				}
				ePassenger_PrintOnePassenger(arrayPassengers[i]);
				retorno = 0;
			}
		}

	}
	return retorno;
}

ePassenger ePassenger_CargarDatos(void)
{
	ePassenger auxiliar;
	ePassenger auxiliarError;
	ePassenger retorno = auxiliarError;
	//todo HACER LA CARGA DE DATOS
	puts("=====================================Ingrese los datos del Pasajero=====================================");
	if (!utn_getString("Ingrese El nombre: ", "~~Error~Re-", 2, MAX_TAM_CHAR, auxiliar.name))
	{
		if (!utn_getString("Ingrese el Apellido: ", "~~Error~Re-", 2, MAX_TAM_CHAR, auxiliar.lastname))
		{
			if (!utn_GetNumeroFlotante("Ingrese el precio del vuelo: ", 2, 0, 999999, "~~Error~El numero no es valido,Re-", &auxiliar.price))
			{
				//(!utn_getString("Ingrese el codigo de vuelo: ", "~~Error~El codigo de vuelo no es valido,Re-", 2, MAX_FLY_CODE, auxiliar.flycode)
				if (!utn_GetNumero("Ingrese el tipo de pasajero (1-clase Turista o economica;"
						"2-Clase ejecutiva; 3-Primera Clase)", 3, 0, 4, "~~Error~ La opcion no es valida,Re-", &auxiliar.typePassenger))
				{
					retorno = auxiliar;
				}
			}
		}
	}
	return retorno;
}

ePassenger ePassenger_ModificarUno(ePassenger Passenger)
{
	ePassenger aux;
	// SE ENCUENTRA EN INFORMES.H
	return aux;
}

int ePassenger_Alta(ePassenger arrayPassengers[], int tam)
{
	int retorno = -1;

	return retorno;
}

int ePassenger_RemovePassenger(ePassenger arrayPassengers[], int tam)
{
	int retorno = -1;
	int idPassenger;
	int index;
	int banderaAltas;

	if (!ePassenger_PrintPassengers(arrayPassengers, tam))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID del pasajero que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idPassenger);

		index = ePassenger_FindPassengerById(arrayPassengers, tam, idPassenger);
		while (index == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID del pasajero que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idPassenger);
			index = ePassenger_FindPassengerById(arrayPassengers, tam, idPassenger);
		}
		if (validar_Salida_SN("Esta seguro que quiere dar de BAJA? 'S' continuar , 'N' cancelar", "Opcion no valida\n", 3))
		{
			arrayPassengers[index].isEmpty = BAJA;
		}
		retorno = 0;
	}
	return retorno;
}

int ePassenger_Modificacion(ePassenger arrayPassengers[], int tam)
{
	int retorno = -1;
	int idPassenger;
	int index;
	int banderaAltas;
	ePassenger auxiliar;

	if (!ePassenger_PrintPassengers(arrayPassengers, tam))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID para modificar", 3, -1, 2001, "Error ID no es valido\n", &idPassenger);

		index = ePassenger_FindPassengerById(arrayPassengers, tam, idPassenger);
		while (index == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID para modificar", 3, -1, 2001, "Error ID no valida", &idPassenger);
		}
		auxiliar = ePassenger_ModificarUno(arrayPassengers[index]);
		if (validar_Salida_SN("Esta seguro que quiere Modificar? 'S' continuar , 'N' cancelar", "Opcion no valida\n", 3))
		{
			arrayPassengers[index] = auxiliar;
		}
	}
	return retorno;
}

int ePassenger_SortPassenger(ePassenger arrayPassengers[], int tam, int criterio)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int nuevoLimite;
	ePassenger buffer;

	if (arrayPassengers != NULL && tam > 0)
	{
		nuevoLimite = tam - 1;
		//CRITERIO ES 1 MENOR A MAYOR, -1 MAYOR A MENOR
		switch (criterio)
		{
		case 1:
			//ORDENO LOS TIPOS DE PASAJEROS
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayPassengers[i].isEmpty == OCUPADO && arrayPassengers[i + 1].isEmpty == OCUPADO)
					{
						if (arrayPassengers[i].typePassenger > arrayPassengers[i + 1].typePassenger)
						{
							flagSwap = 1;
							buffer = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[i + 1];
							arrayPassengers[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);

			//ORDENO ALFABETICAMENTE CUANDO LOS TIPOS SEAN IGUALES
			do
			{
				flagSwap = 0;
				for (i = 0; i < tam; i++)
				{
					if (arrayPassengers[i].isEmpty == OCUPADO && arrayPassengers[i + 1].isEmpty == OCUPADO)
					{
						if (strncmp(arrayPassengers[i].lastname, arrayPassengers[i + 1].lastname, sizeof(arrayPassengers->lastname)) > 0)
						{
							if (arrayPassengers[i].typePassenger == arrayPassengers[i + 1].typePassenger)
							{
								flagSwap = 1;
								buffer = arrayPassengers[i];
								arrayPassengers[i] = arrayPassengers[i + 1];
								arrayPassengers[i + 1] = buffer;
							}
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);
			break;
		case -1:
			//ORDENO LOS TIPOS DE PASAJEROS
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayPassengers[i].isEmpty == OCUPADO && arrayPassengers[i + 1].isEmpty == OCUPADO)
					{
						if (arrayPassengers[i].typePassenger < arrayPassengers[i + 1].typePassenger)
						{
							flagSwap = 1;
							buffer = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[i + 1];
							arrayPassengers[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);

			//ORDENO ALFABETICAMENTE CUANDO LOS TIPOS SEAN IGUALES
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayPassengers[i].isEmpty == OCUPADO && arrayPassengers[i + 1].isEmpty == OCUPADO)
					{
						if (strncmp(arrayPassengers[i].lastname, arrayPassengers[i + 1].lastname, sizeof(arrayPassengers->lastname)) < 0)
						{
							flagSwap = 1;
							buffer = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[i + 1];
							arrayPassengers[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);
			break;
		default:
			retorno = 0;
			break;
		}
	}
	return retorno;
}


int ePassenger_Promedios(ePassenger arrayPassengers[], int passengerLen)
{
	int retorno = -1;
	int i;
	float gastoTotal = 0;
	int contadorPasajeros = 0;
	float promedioTotal;
	int banderaMensaje = 0;
	if(arrayPassengers != NULL && passengerLen > 0)
	{
		for(i = 0; i < passengerLen; i++)
		{
			if( arrayPassengers[i].isEmpty != LIBRE)
			{
				gastoTotal += arrayPassengers[i].price;
				contadorPasajeros++;
			}
		}
		promedioTotal = gastoTotal / contadorPasajeros;
		puts("===================================================================================");
		printf("\nEl importe total de los pasajeros es: $%.2f\n",gastoTotal);
		printf("\nEl promedio de importes es : $%.2f\n",promedioTotal);

		for(i = 0; i < passengerLen; i++)
		{
			if(arrayPassengers[i].isEmpty != LIBRE)
			{
				if(arrayPassengers[i].price > promedioTotal - 1)
				{
					if(banderaMensaje == 0)
					{
						puts("\nLos Pasajeros que superan el importe promedio son los siguientes:");
						puts("-----------------------------------------------------------------------------------");
						printf("%2s%12s%18s%23s%25s\n", "ID", "NOMBRE", "APELLIDO", "GASTO VUELO", "TIPO DE PASAJERO");
						puts("===================================================================================");

						banderaMensaje = 1;
					}
					ePassenger_PrintOnePassenger(arrayPassengers[i]);
				}
			}
		}
	}
	return retorno;
}
