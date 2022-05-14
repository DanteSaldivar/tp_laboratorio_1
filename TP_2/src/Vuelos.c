/**
 *  Vuelos.c
 *
 *
 *
 */

#include "Vuelos.h"

void eVuelo_Inicializar(eVuelo arrayDeVuelos[], int tam)
{
	int i;

	if (arrayDeVuelos != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			arrayDeVuelos[i].flightStatus = INACTIVO;
			strncpy(arrayDeVuelos[i].flyCode, "PEPE1", sizeof(arrayDeVuelos[i].flyCode));
		}
	}
}

int eVuelo_ObtenerIndexLibre(eVuelo arrayDeVuelos[], int tam)
{
	int retorno = -1;
	int i;

	if (arrayDeVuelos != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayDeVuelos[i].flightStatus == INACTIVO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eVuelo_BuscarIndexPorID(eVuelo arrayDeVuelos[], int tam, int ID)
{
	int retorno = -1;
	int i;

	if (arrayDeVuelos != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayDeVuelos[i].idVuelo == ID)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eVuelo_MostrarUno(eVuelo Vuelos)
{

	char estadoAuxiliar[10];

	printf("%1d%20s", Vuelos.idVuelo, Vuelos.flyCode);

	switch (Vuelos.flightStatus)
	{
	case -3:
		strncpy(estadoAuxiliar, "ACTIVO", sizeof(estadoAuxiliar));
		break;
	case -2:
		strncpy(estadoAuxiliar, "VOLANDO", sizeof(estadoAuxiliar));
		break;
	case -1:
		strncpy(estadoAuxiliar, "INACTIVO", sizeof(estadoAuxiliar));
		break;
	}
	printf("%26s\n", estadoAuxiliar);
	puts("========================================================");
}

int eVuelo_ImprimirVuelosPorEstado(eVuelo arrayVuelos[], int tam, int estado)
{
	int retorno = -1;
	int i;
	int banderaMensaje = 1;
	int ultimoId;
	int banderaPrimerIngreso = 1;

	puts("\n\t> LISTADO VUELOS");
	if (arrayVuelos != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayVuelos[i].flightStatus == estado)
			{
				if (banderaMensaje)
				{
					printf("%2s%25s%26s\n", "ID", "CODIGO DE VUELO", "ESTADO DE VUELO");
					//,%25s "CODIGO DE VUELO"
					puts("========================================================");
					banderaMensaje = 0;
				}
				if (banderaPrimerIngreso)
				{
					ultimoId = arrayVuelos[i].idVuelo;
					eVuelo_MostrarUno(arrayVuelos[i]);
					banderaPrimerIngreso = 0;

				}
				else
				{
					if (ultimoId != arrayVuelos[i].idVuelo)
					{
						eVuelo_MostrarUno(arrayVuelos[i]);
						ultimoId = arrayVuelos[i].idVuelo;
					}
				}
			}
		}
	}
	return retorno;
}

eVuelo eVuelo_CargarDatos(void)
{
	eVuelo auxiliar;
	eVuelo auxiliarError;

	eVuelo retorno = auxiliarError;

	if (get_AlfaNumerico(auxiliar.flyCode, MAX_FLY_CODE, "Ingrese el codigo de vuelo:") == 0)
	{
		retorno = auxiliar;
	}

	return retorno;
}


int eVuelo_Sort(eVuelo arrayDeVuelos[], int tam, int criterio)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int nuevoLimite;
	eVuelo buffer;

	if (arrayDeVuelos != NULL && tam > 0)
	{
		nuevoLimite = tam - 1;
		//CRITERIO ES 1 ORDENA POR ID, -1 ALFANUMERICO
		switch (criterio)
		{
		case 1:
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayDeVuelos[i].flightStatus != INACTIVO && arrayDeVuelos[i + 1].flightStatus != INACTIVO)
					{
						if (arrayDeVuelos[i].idVuelo > arrayDeVuelos[i + 1].idVuelo)
						{
							flagSwap = 1;
							buffer = arrayDeVuelos[i];
							arrayDeVuelos[i] = arrayDeVuelos[i + 1];
							arrayDeVuelos[i + 1] = buffer;
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
					if (arrayDeVuelos[i].flightStatus != INACTIVO && arrayDeVuelos[i + 1].flightStatus != INACTIVO)
					{
						if (arrayDeVuelos[i].idVuelo < arrayDeVuelos[i + 1].idVuelo)
						{
							flagSwap = 1;
							buffer = arrayDeVuelos[i];
							arrayDeVuelos[i] = arrayDeVuelos[i + 1];
							arrayDeVuelos[i + 1] = buffer;
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



int eVuelo_ComprobacionCodigo(eVuelo *arrayVuelos, int lenght, char *cadena)
{
	int retorno = -1;

	if (arrayVuelos != NULL && cadena != NULL && lenght > 0)
	{
		for (int i = 0; i < lenght; i++)
		{
			if (arrayVuelos[i].flightStatus != INACTIVO)
			{
				if (strncmp(arrayVuelos[i].flyCode, cadena, sizeof(arrayVuelos[i].flyCode)) == 0)
				{
					retorno = arrayVuelos[i].idVuelo;
					break;
				}
			}
		}
	}
	return retorno;
}

