
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Biblioteca.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	//LA FUNCION FOPEN LO HACE LA QUE LLAMA A ESTA
	int cantidadDeDatosLeidos;
	char id[10];
	char nombre[50];
	char apellido[50];
	char precio[10];
	char tipoPasejero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasejero,estadoVuelo);
		do
		{
			cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasejero,estadoVuelo);

			if(cantidadDeDatosLeidos == 7)
			{
				Passenger* auxiliarPassenger = Passenger_newParametros(id, nombre,apellido,precio,codigoVuelo,tipoPasejero,estadoVuelo);
				if(auxiliarPassenger != NULL)
				{
					ll_add(pArrayListPassenger, auxiliarPassenger);
					retorno = 0;

				}
			}
		}while(feof(pFile) == 0);
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	int cantidadDeDatosLeidos;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			Passenger* auxiliarPassenger = Passenger_new();
			if(auxiliarPassenger != NULL)
			{
				cantidadDeDatosLeidos = fread(auxiliarPassenger,sizeof(Passenger),1,pFile);
				if(cantidadDeDatosLeidos == 1)
				{
					ll_add(pArrayListPassenger, auxiliarPassenger);
					retorno = 0;
				}
			}

		}while(feof(pFile) == 0);

	}
	return retorno;
}


int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	char idStr[10];
	char nombreStr[50];
	char apellidoStr[50];
	char precioStr[10];
	char tipoPasajeroStr[20];
	char codigoVueloStr[10];
	char estadoVueloStr[20];

	int lengthList;

	lengthList = ll_len(pArrayListPassenger);

	Passenger* pAux;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n","id","name","lastname","price","flycode","typePassenger","statusFlight");
		for(int i = 0; i < lengthList; i++)
		{
			pAux = ll_get(pArrayListPassenger, i);

			if(pAux != NULL)
			{
				if(!Passenger_parametrosChar(pAux, idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr))
				{
					fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int lengthList;

	lengthList = ll_len(pArrayListPassenger);

	Passenger* pAux = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		for(int i = 0; i < lengthList ; i++)
		{
			pAux = ll_get(pArrayListPassenger,i);

			if(pAux != NULL)
			{
				fwrite(pAux,sizeof(Passenger),1,pFile);
			}
		}
		retorno = 0;
	}
	return retorno;
}
