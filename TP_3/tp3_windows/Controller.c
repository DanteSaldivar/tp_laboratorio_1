#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
				fclose(pFile);
			}
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
				fclose(pFile);
			}
		}
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAuxiliar;

	if(pArrayListPassenger != NULL)
	{
		puts("----------------------------------------------------------------------------------------------------");
		pAuxiliar = Passenger_addPassenger();
		if(pAuxiliar != NULL)
		{
			ll_add(pArrayListPassenger, pAuxiliar);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxId;
	Passenger* pAux = NULL;

	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger))
	{
		puts("----------------------------------------------------------------------------------------------------");
		if(!utn_GetNumero("Ingrese el ID del Pasajero a modificar: ", 3, 0, 10000, "\nNumero no valido\n", &auxId))
		{
			pAux = (Passenger*)Passenger_getById(pArrayListPassenger, auxId);

			if(pAux != NULL)
			{
				Passenger_ImprimirUno(pAux);
				if(!Passenger_editPassenger(pAux))
				{
					retorno = 0;
				}
			}
		}
	}


    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxId;
	int auxIndex;
	Passenger* pAux = NULL;

	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger))
	{
		puts("----------------------------------------------------------------------------------------------------");
		if(!utn_GetNumero("Ingrese el ID del Pasajero que desea Eliminar: ", 3, 0, 10000, "\nNumero no valido\n", &auxId))
		{
			pAux = (Passenger*)Passenger_getById(pArrayListPassenger, auxId);
			if(pAux != NULL)
			{
				auxIndex = ll_indexOf(pArrayListPassenger, pAux);
				if(auxIndex > -1)
				{
					Passenger_ImprimirUno(pAux);

					if(validar_Salida_SN("\nEsta seguro que quiere eliminar el Pasajero? S/N ", "\nOpcion no valida\n", 3))
					{
						ll_remove(pArrayListPassenger, auxIndex);
						Passenger_delete(pAux);
						retorno = 0;
					}

				}
			}
		}
	}





    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int banderaPrimero = 1;
	Passenger* pAux;

	int lengthArray;

	lengthArray = ll_len(pArrayListPassenger);
	if(pArrayListPassenger != NULL)
	{

		for(int i = 0; i < lengthArray;i++)
		{
			pAux = ll_get(pArrayListPassenger, i);
			if(pAux != NULL)
			{
				if (banderaPrimero)
				{
					puts("ID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\tESTADO VUELO");
					puts("----------------------------------------------------------------------------------------------------");
					banderaPrimero = 0;
				}
				Passenger_ImprimirUno(pAux);
				retorno = 0;
			}
		}

	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxOpcion;
	int banderaCompletado = 0;
	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger))
	{
		LinkedList* pAux = ll_clone(pArrayListPassenger);
		if(pAux != NULL)
		{
			puts("----------------------------------------------------------------------------------------------------");
			if(!utn_GetNumero("\nDesea ordenar por:\n1)Nombre\n2)Codigo de Vuelo\n"
					"3)Precios\n4)Estado vuelo\nOpcion: ", 3, 0, 5, "Error opcion no valida.\n", &auxOpcion))
			{
				switch(auxOpcion)
				{
				case 1:
					if(!ll_sort(pAux,(Passenger_criteroNombre), 1))
					{
						retorno = 0;
						banderaCompletado = 1;
					}
					break;
				case 2:
					if(!ll_sort(pAux,(Passenger_criteroCodigoVuelo), 1))
					{
						retorno = 0;
						banderaCompletado = 1;
					}
					break;
				case 3:
					if(!ll_sort(pAux,(Passenger_criteroPrecio), 1))
					{
						retorno = 0;
						banderaCompletado = 1;
					}
					break;
				case 4:
					if(!ll_sort(pAux,(Passenger_criteroEstadoVuelo), 1))
					{
						retorno = 0;
						banderaCompletado = 1;
					}
					break;
				}
			}
			if(banderaCompletado)
			{
				controller_ListPassenger(pAux);
				ll_clear(pAux);
			}
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger))
	{
		FILE* pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			if(!parser_PassengerToText(pFile, pArrayListPassenger))
			{
				retorno = 0;
				fclose(pFile);

			}

		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger))
	{
		FILE* pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			if(!parser_PassengerToBinary(pFile, pArrayListPassenger))
			{
				retorno = 0;
				fclose(pFile);
				ll_clear(pArrayListPassenger);
			}

		}
	}
    return retorno;
}

int controller_SetLastId(char* pathLastId)
{
	int retorno  = -1;
	int lastId;
	int totalDatos;
	if(pathLastId != NULL)
	{
		FILE* fLastId = fopen(pathLastId,"rb");
		if(fLastId != NULL)
		{
			totalDatos = fread(&lastId,sizeof(int),1,fLastId);
			if(totalDatos == 1)
			{
				retorno = lastId + 1;
				if(!fclose(fLastId))
				{
					fLastId = fopen(pathLastId,"wb");
					if(fLastId != NULL)
					{
						fwrite(&retorno,sizeof(int),1,fLastId);
						fclose(fLastId);
					}
				}

			}
		}
	}
	return retorno;
}

int controller_findLastId(char* path,char* pathLastId)
{
	int retorno = -1;
	int maxId;
	int lengthList;
	Passenger* pAux;
	LinkedList* lAux = ll_newLinkedList();
	if(path != NULL && pathLastId != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_PassengerFromText(pFile, lAux) == 0)
			{
				lengthList = ll_len(lAux);
				pAux = (Passenger*)ll_get(lAux, lengthList - 1);
				if(pAux != NULL)
				{
					Passenger_getId(pAux, &maxId);
					ll_clear(lAux);
					fclose(pFile);
				}
			}
			FILE* pFileLastId = fopen(pathLastId,"wb");
			{
				if(pFileLastId != NULL)
				{
					fwrite(&maxId,sizeof(int),1,pFileLastId);
					fclose(pFileLastId);
				}
			}
		}
	}

	return retorno;
}
