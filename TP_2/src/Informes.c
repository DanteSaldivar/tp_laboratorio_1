/*
 * Informes.c
 *
 *
 */

#include "Informes.h"

//ME TRAIGO LAS FUNCIONES DE OBTENER ID DE LOS OTROS .H

static int ePassenFly_Passenger_ObtenerID(void);
static int ePassenFly_Passenger_ObtenerID(void)
{
	static int Passenger_IdIncremental = 0;
	return Passenger_IdIncremental++;
}
static int ePassenFly_Vuelo_ObtenerID(void);
static int ePassenFly_Vuelo_ObtenerID(void)
{
	static int Vuelos_IdIncremental = 0;
	return Vuelos_IdIncremental++;
}

int ePassenFly_CargaDatos(ePassenger ArrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen)
{
	int retorno = -1;
	ePassenger auxPassenger;
	eVuelo auxVuelo;
	puts("=====================================Ingrese los datos del Pasajero=====================================");
	if (!utn_getString("Ingrese El nombre: ", "~~Error~Re-", 2, MAX_TAM_CHAR, auxPassenger.name))
	{
		if (!utn_getString("Ingrese el Apellido: ", "~~Error~Re-", 2, MAX_TAM_CHAR, auxPassenger.lastname))
		{
			if (!utn_GetNumeroFlotante("Ingrese el precio del vuelo: ", 2, 0, 999999, "~~Error~El numero no es valido,Re-", &auxPassenger.price))
			{
				if (get_AlfaNumerico(auxVuelo.flyCode, MAX_FLY_CODE, "Ingrese el codigo del vuelo: ") == 0)
				{
					if (!utn_GetNumero("Ingrese el tipo de pasajero (1-clase Turista o economica;"
							"2-Clase ejecutiva; 3-Primera Clase)", 3, 0, 4, "~~Error~ La opcion no es valida,Re-", &auxPassenger.typePassenger))
					{
						retorno = ePassenFly_addPassengers(ArrayPassengers, passengerLen, ArrayVuelos, vuelosLen, 25, auxPassenger.name, auxPassenger.lastname, auxPassenger.price,
								auxPassenger.typePassenger, auxVuelo.flyCode);
					}
				}
			}
		}
	}
	return retorno;
}

int ePassenFly_addPassengers(ePassenger *arrayPassenger, int passengerLen, eVuelo ArrayVuelos[], int vuelosLen, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
	int retorno = -1;
	int indexPassenger;
	int indexVuelo;
	int auxiliarComprobacion;

	//CARGO LOS DATOS DE PASAJEROS JUNTO A VUELOS ASI LOGRO RELACIONARLOS SIN PERDER EL DATO;

	if (arrayPassenger != NULL && ArrayVuelos != NULL && name != NULL && lastName != NULL && flyCode != NULL && passengerLen > 0 && vuelosLen > 0 && price > -1
			&& (typePassenger > 0 || typePassenger < 5) && id > -1)
	{
		indexPassenger = ePassenger_ObtenerIndexLibre(arrayPassenger, passengerLen);
		indexVuelo = eVuelo_ObtenerIndexLibre(ArrayVuelos, vuelosLen);

		if (indexPassenger != -1 && indexVuelo != -1)
		{
			//CARGO DATOS GENERICOS
			arrayPassenger[indexPassenger].idPassenger = ePassenFly_Passenger_ObtenerID();
			arrayPassenger[indexPassenger].isEmpty = OCUPADO;

			ArrayVuelos[indexVuelo].flightStatus = ACTIVO;
			//ME FIJO SI YA TENGO ESE CODIGO DE VUELO, LOS PASAJEROS CON EL MISMO CODIGO COMPARTEN FK

			auxiliarComprobacion = eVuelo_ComprobacionCodigo(ArrayVuelos, vuelosLen, flyCode);
			if (auxiliarComprobacion == -1)
			{
				ArrayVuelos[indexVuelo].idVuelo = ePassenFly_Vuelo_ObtenerID();
			}
			else
			{
				ArrayVuelos[indexVuelo].idVuelo = auxiliarComprobacion;
			}

			arrayPassenger[indexPassenger].typePassenger = typePassenger;
			strncpy(arrayPassenger[indexPassenger].name, name, sizeof(arrayPassenger[indexPassenger].name));
			strncpy(arrayPassenger[indexPassenger].lastname, lastName, sizeof(arrayPassenger[indexPassenger].lastname));
			arrayPassenger[indexPassenger].price = price;

			strncpy(ArrayVuelos[indexVuelo].flyCode, flyCode, sizeof(ArrayVuelos[indexVuelo].flyCode));

			arrayPassenger[indexPassenger].FK_Vuelo = ArrayVuelos[indexVuelo].idVuelo;
			retorno = 0;
		}
	}
	return retorno;
}

void ePassenFly_Hardcodeo(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen)
{
	char misNombres[10][15] =
	{ "DANTE", "SANTI", "BENJAMIN", "THIAGO", "AGUSTIN", "GIAN", "BRUNO", "EZEQUIEL", "RODRIGO", "RAND" };
	char misApellidos[10][15] =
	{ "SALDIVAR", "CATHOUN", "SALDIVAR", "ZABALA", "PYTON", "ISIDRO", "SEDAI", "BENEDETTO", "VEGA", "AL'TOHR" };
	char misCodigosVuelo[10][10] =
	{ "SAEZ8416", "SAAR12373", "BRON9546", "SAVG6815", "DUST0216", "JJP3588", "SBGR9871", "BCN5674", "OSL6847", "PET8466" };

	//ePassenger auxPassenger;
	//eVuelo auxVuelo;

	int i;
	int banderaDeTipos = 1;
	for (i = 0; i < 10; i++)
	{
		//EL ID INGRESADO CON i ES PISADO POR LA FUNCION DE ADD PASSENGERS EL CUAL BUSCA UN ID LIBRE
		if (banderaDeTipos == 4)
		{
			//ASI SIEMPRE INGRESAN LOS NUMEROS 1 2 Y 3
			banderaDeTipos = 1;
		}
		ePassenFly_addPassengers(arrayPassengers, passengerLen, ArrayVuelos, vuelosLen, i, misNombres[rand() % 10], misApellidos[rand() % 10], rand() % 1000, banderaDeTipos,
				misCodigosVuelo[rand() % 10]);
		banderaDeTipos++;
	}
}

int ePassenFly_SortPassengerByCode(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen, int order)
{
	int retorno = -1;
	int flagSwap;
	int nuevoLimite;
	int i;
	eVuelo buffer;

	//ORDENO EL ARRAY DE VUELOS DE MANERA DESCENDENTE Y ASCENDETE 1 -1
	if (arrayPassengers != NULL && ArrayVuelos != NULL && passengerLen > 0 && vuelosLen > 0 && order > 0)
	{
		nuevoLimite = vuelosLen;

		switch (order)
		{
		case 1:
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (ArrayVuelos[i].flightStatus != INACTIVO && ArrayVuelos[i + 1].flightStatus != INACTIVO)
					{
						if (strncasecmp(ArrayVuelos[i].flyCode, ArrayVuelos[i + 1].flyCode, sizeof(ArrayVuelos[i].flyCode)) < 0)
						{
							flagSwap = 1;
							buffer = ArrayVuelos[i];
							ArrayVuelos[i] = ArrayVuelos[i + 1];
							ArrayVuelos[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);
			break;
		case -1:
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (ArrayVuelos[i].flightStatus != INACTIVO && ArrayVuelos[i + 1].flightStatus != INACTIVO)
					{
						if (strncasecmp(ArrayVuelos[i].flyCode, ArrayVuelos[i + 1].flyCode, sizeof(ArrayVuelos[i].flyCode)) > 0)
						{
							flagSwap = 1;
							buffer = ArrayVuelos[i];
							ArrayVuelos[i] = ArrayVuelos[i + 1];
							ArrayVuelos[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);
			break;
		}
	}

	return retorno;
}

int ePassenFly_ModificarUno(ePassenger *Passenger, eVuelo *vuelos)
{
	int retorno = -1;
	int opcion;
	ePassenger *auxiliarPassenger = Passenger;
	eVuelo *auxiliarVuelos = vuelos;
	int respuesta;

	while (respuesta != 0)
	{
		puts("=========================================================================================================");
		if (!utn_GetNumero("Elija la opcion que quiera modificar\n1-Nombre\n2-Apellido\n3-Precio de vuelo\n4-Tipo de pasajero\n"
				"5-Codigo de vuelo\nOpcion: ", 3, 0, 6, "Error Opcion no valida.\n", &opcion))
		{
			switch (opcion)
			{
			case 1:
				if (!utn_getString("Ingrese el nombre del pasajero: ", "Error.", 2, MAX_TAM_CHAR, auxiliarPassenger->name))
				{
					break;
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;
			case 2:
				if (!utn_getString("Ingrese el apellido del pasajero: ", "Error.Re-", 2, MAX_TAM_CHAR, auxiliarPassenger->lastname))
				{
					break;
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;
			case 3:
				if (!utn_GetNumeroFlotante("Ingrese el precio: ", 2, 0, 10000, "Error Re-", &auxiliarPassenger->price))
				{
					break;
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;
			case 4:
				if (!utn_GetNumero("Ingrese el tipo de pasajero (1-clase Turista o economica;"
						"2-Clase ejecutiva; 3-Primera Clase): ", 3, 0, 4, "~~Error~ La opcion no es valida,Re-", &auxiliarPassenger->typePassenger))
				{
					break;
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;
			case 5:
				if (!get_AlfaNumerico(auxiliarVuelos->flyCode, MAX_FLY_CODE, "Ingrese el codigo del vuelo: "))
				{
					break;
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;
			}
			puts("---------------------------------------------------------------------------------------------------------");
		}
		respuesta = validar_Salida_SN("Desea efectuar otra modificacion? 'S' seguir 'N' salir.", "Error, Reintente ", 3);
		puts("=========================================================================================================");
		retorno = 0;
	}
	Passenger = auxiliarPassenger;
	vuelos = auxiliarVuelos;
	return retorno;
}

int ePassenFly_PassengerModification(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen)
{
	int retorno = -1;
	int idPassenger;
	int indexPassenger;
	int indexVuelo;
	int banderaAltas;

	if (!ePassenger_PrintPassengers(arrayPassengers, passengerLen))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID para modificar ", 3, -1, 2001, "Error ID no es valido\n", &idPassenger);

		indexPassenger = ePassenger_FindPassengerById(arrayPassengers, passengerLen, idPassenger);
		while (indexPassenger == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID para modificar ", 3, -1, 2001, "Error ID no valida", &idPassenger);
		}
		indexVuelo = arrayPassengers[indexPassenger].FK_Vuelo;
		if (!ePassenFly_ModificarUno(&arrayPassengers[indexPassenger], &ArrayVuelos[indexVuelo]))
		{
			puts("SE HA REALIZADO LA MODIFICACION CON EXITO");
		}
	}
	return retorno;
}

int ePassenFly_printPassenger_Fly(ePassenger Passenger, eVuelo Vuelo)
{
	int retorno = -1;
	char tipoAuxiliar[18];
	printf("%d\t%-13s\t%-20s%3.2f%25s", Passenger.idPassenger, Passenger.name, Passenger.lastname, Passenger.price, Vuelo.flyCode);
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
	puts("=========================================================================================================");

	return retorno;
}

int ePassenFly_printPassengers_Flys(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen)
{
	int retorno = -1;
	int i;
	int banderaMensaje = 1;
	//int FkID;
	int indexPassenger;
	int banderaPrimerIngreso;
	int ultimoID;

	puts("\n\t> LISTADO PASAJEROS Y VUELOS");
	if (arrayPassengers != NULL && ArrayVuelos != NULL && passengerLen > 0 && vuelosLen > 0)
	{
		for (i = 0; i < passengerLen; i++)
		{
			if (arrayPassengers[i].isEmpty == OCUPADO)
			{
				if (banderaMensaje)
				{
					printf("%2s%12s%18s%23s%25s%24s\n", "ID", "NOMBRE", "APELLIDO", "GASTO VUELO", "CODIGO DE VUELO", "TIPO DE PASAJERO");
					puts("=========================================================================================================");
					banderaMensaje = 0;
				}
				indexPassenger = ePassenger_FindPassengerById(arrayPassengers, passengerLen, ArrayVuelos[i].idVuelo);
				if (banderaPrimerIngreso)
				{
					ultimoID = arrayPassengers[indexPassenger].idPassenger;
					ePassenFly_printPassenger_Fly(arrayPassengers[indexPassenger], ArrayVuelos[i]);
					banderaPrimerIngreso = 0;
				}
				else
				{
					if (ultimoID != indexPassenger)
					{
						//indexPassenger = ePassenger_FindPassengerById(arrayPassengers, passengerLen, ArrayVuelos[i].idVuelo);
						ePassenFly_printPassenger_Fly(arrayPassengers[indexPassenger], ArrayVuelos[i]);
						ultimoID = indexPassenger;
					}
				}
				retorno = 0;
			}
		}

	}
	return retorno;
}
