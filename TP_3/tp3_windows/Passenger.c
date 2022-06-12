#include "Passenger.h"

Passenger* Passenger_new(void)
{
	Passenger *auxiliarP = NULL;

	auxiliarP = (Passenger*) malloc(sizeof(Passenger));
	return auxiliarP;
}

void* Passenger_getById(LinkedList* pArrayListPassenger, int id)
{
	Passenger* pAux = NULL;
	int lengthArray;
	int auxId;

	lengthArray = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && id > 0)
	{
		for(int i = 0; i < lengthArray; i++)
		{
			pAux = (Passenger*)ll_get(pArrayListPassenger, i);
			if(pAux != NULL)
			{

				Passenger_getId(pAux, &auxId);
				if(auxId == id)
				{
					break;
				}
				else
				{
					pAux = NULL;
				}
			}
		}
	}
	return pAux;
}

Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr, char *codigoVueloStr, char *tipoPasajeroStr, char *EstadoVueloStr)
{
	Passenger *auxiliar = Passenger_new();
	int banderaCompletado = 0;
	int auxTipo;
	int auxEstado;

	if (auxiliar != NULL)
	{
		///FALTA VALIDAR APELLiDO
		if (esNumerica(idStr, sizeof(idStr)) && esNombre(nombreStr, sizeof(nombreStr)) && esNombre(tipoPasajeroStr, sizeof(tipoPasajeroStr)) && esFlotante(precioStr, sizeof(precioStr))
				&& esAlfaNumerica(codigoVueloStr, sizeof(codigoVueloStr)) && esAlfaNumerica(EstadoVueloStr, sizeof(EstadoVueloStr)))
		{

			if(!Passenger_setId(auxiliar, atoi(idStr)) && !Passenger_setNombre(auxiliar, nombreStr) && !Passenger_setApellido(auxiliar, apellidoStr)
					&& !Passenger_setPrecio(auxiliar, atof(precioStr)) && !Passenger_setCodigoVuelo(auxiliar, codigoVueloStr))
			{
				auxTipo = convertirTipoPasajeroInt(tipoPasajeroStr);
				auxEstado = convertirEstadoVueloInt(EstadoVueloStr);

				if(!Passenger_setTipoPasajero(auxiliar, auxTipo) && !Passenger_setEstadoVuelo(auxiliar, auxEstado))
				{
					banderaCompletado = 1;
				}
			}
		}
	}
	if (banderaCompletado == 0)
	{
		Passenger_delete(auxiliar);
		auxiliar = NULL;
	}

	return auxiliar;
}

void Passenger_ImprimirUno(Passenger *this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;

	char auxTipo[15];
	char auxEstado[20];
	if (this != NULL)
	{
		///id,name,lastname,price,flycode,typePassenger,statusFlight
			if(!Passenger_getId(this, &id) && !Passenger_getNombre(this, nombre) && !Passenger_getApellido(this, apellido)
					&& !Passenger_getPrecio(this, &precio) && !Passenger_getCodigoVuelo(this, codigoVuelo)
					&& !Passenger_getTipoPasajero(this, &tipoPasajero) && !Passenger_getEstadoVuelo(this, &estadoVuelo))
			{
				convertirTipoPasajeroChar(tipoPasajero, auxTipo);
				convertirEstadoVueloChar(estadoVuelo,auxEstado);

				printf("%d\t%-15s\t%-15s\t%-7.2f%13s\t\t%-15s\t%s\n", id, nombre, apellido, precio, codigoVuelo, auxTipo, auxEstado);
				puts("----------------------------------------------------------------------------------------------------");

		}
	}

}

void Passenger_delete(Passenger *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger *this, int id)
{
	int retorno = -1;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger *this, int *id)
{
	int retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido)
{
	int retorno = -1;

	if (this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;

	}
	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido)
{
	int retorno = -1;

	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;

	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero)
{
	int retorno = -1;

	if (this != NULL && tipoPasajero > 0 && tipoPasajero < 4)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}


int Passenger_setEstadoVuelo(Passenger *this, int EstadoVuelo)
{
	int retorno = -1;

	if (this != NULL && EstadoVuelo > 0 && EstadoVuelo < 4)
	{
		this->estadoVuelo = EstadoVuelo;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger *this, int *EstadoVuelo)
{
	int retorno = -1;
	if (this != NULL && EstadoVuelo != NULL)
	{
		*EstadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}


int Passenger_setPrecio(Passenger *this, float precio)
{
	int retorno = -1;
	if (this != NULL && precio > -1)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio)
{
	int retorno = -1;
	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

Passenger* Passenger_addPassenger(void)
{
	char id[5];
	char nombre[50];
	char apellido[50];
	char precio[10];
	char tipoPasajero[20];
	char codigoVuelo[5];
	char estadoVuelo[20];

	int auxTipo;
	int auxId;
	int auxEstado;
	int banderaCompleto = 1;
	Passenger* pAux = NULL;


	if(!utn_getString("\nIngrese el nombre del Pasajero: ", "\nEl nombre no es valido", 3, sizeof(nombre),nombre))
	{
		if(!utn_getString("Ingrese el apellido del Pasajero: ", "\nEl apellido no es valido\n", 3, sizeof(apellido), apellido))
		{
			if(!utn_GetAlfaNumerico("Ingrese el precio del Pasaje: ", "\nEl precio no es valido\n" , 3, sizeof(precio), precio))
			{
				if(!utn_GetAlfaNumerico("Ingrese el codigo del Vuelo: ", "\nEl codigo de vuelo no es valido\n", 3, sizeof(codigoVuelo), codigoVuelo))
				{
					if(!utn_GetNumero("Ingrese el tipo Pasajero ('1'ExecutiveClass, '2'FirstClass,'3'EconomyClass): ", 3, 0, 4, "\nEsa opcion no es valida\n", &auxTipo))
					{
						if(!utn_GetNumero("Ingrese el estado del Vuelo ('1'Aterrizado, '2'Demorado,'3'En horario): ", 3, 0, 4, "\nEsa opcion no es valida\n", &auxEstado))
						{
							convertirTipoPasajeroChar(auxTipo, tipoPasajero);
							convertirEstadoVueloChar(auxEstado, estadoVuelo);
							auxId = controller_SetLastId("LastId.bin");
							sprintf(id,"%d",auxId);


							pAux = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
							if(pAux != NULL)
							{
								banderaCompleto = 0;
							}

						}
					}
				}
			}
		}

	}
	if(banderaCompleto)
	{
		Passenger_delete(pAux);
		pAux = NULL;
	}
	return pAux;
}

int Passenger_editPassenger(Passenger *this)
{
	int retorno = -1;
	int auxOpcion;

	char nombre[50];
	char apellido[50];
	char precio[10];
	char codigoVuelo[5];
	int tipoPasajero;
	int estadoVuelo;

	if(this != NULL)
	{
		do
		{
			int banderaModificacion = 0;

			if(!utn_GetNumero("Que desea modificar?\n1)Nombre\n2)Apellido\n3)Precio\n4)Codigo Vuelo\n5)Tipo Pasajero\n6)Estado Vuelo\nOpcion: ", 3, 0, 7, "La opcion no es valida\n", &auxOpcion))
			{
				switch(auxOpcion)
				{
				case 1:
					if(!utn_getString("\nIngrese el nombre del Pasajero: ", "\nEl nombre no es valido", 3, sizeof(nombre),nombre))
					{
						if(!Passenger_setNombre(this, nombre))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				case 2:
					if(!utn_getString("Ingrese el apellido del Pasajero: ", "\nEl apellido no es valido", 3, sizeof(apellido), apellido))
					{
						if(!Passenger_setApellido(this, apellido))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				case 3:
					if(!utn_GetAlfaNumerico("Ingrese el precio del Pasaje: ", "\nEl precio no es valido" , 3, sizeof(precio), precio))
					{
						if(!Passenger_setPrecio(this, atof(precio)))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				case 4:
					if(!utn_GetAlfaNumerico("Ingrese el codigo del Vuelo: ", "\nEl codigo de vuelo no es valido", 3, sizeof(codigoVuelo), codigoVuelo))
					{
						if(!Passenger_setCodigoVuelo(this, codigoVuelo))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				case 5:
					if(!utn_GetNumero("Ingrese el tipo Pasajero ('1'ExecutiveClass, '2'FirstClass,'3'EconomyClass): ", 3, 0, 4, "\nEsa opcion no es valida", &tipoPasajero))
					{
						if(!Passenger_setTipoPasajero(this, tipoPasajero))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				case 6:
					if(!utn_GetNumero("Ingrese el estado del Vuelo ('1'Aterrizado, '2'Demorado,'3'En horario): ", 3, 0, 4, "\nEsa opcion no es valida", &estadoVuelo))
					{
						if(!Passenger_setEstadoVuelo(this, estadoVuelo))
						{
							retorno = 0;
							banderaModificacion = 1;
						}
					}
					break;
				}
			}

			if(!banderaModificacion)
			{
				retorno = -1;
				puts("Modificacion no Valida.\n");
			}

		}while(validar_Salida_SN("\nDesea editar otro campo? S/N", "\nOpcion no valida.\n", 3));

	}
	return retorno;
}

int Passenger_parametrosChar(Passenger* this,char *idStr, char *nombreStr, char *apellidoStr, char *precioStr, char *codigoVueloStr, char *tipoPasajeroStr, char *EstadoVueloStr)
{
	int retorno = -1;
	float auxPrecio;
	int auxTipo;
	int auxEstado;
	int auxId;

	if(this != NULL)
	{

		if(!Passenger_getId(this, &auxId) && !Passenger_getNombre(this, nombreStr) && !Passenger_getApellido(this, apellidoStr) && !Passenger_getPrecio(this, &auxPrecio)
				&& !Passenger_getCodigoVuelo(this, codigoVueloStr) && !Passenger_getTipoPasajero(this, &auxTipo) && !Passenger_getEstadoVuelo(this, &auxEstado))
		{
			sprintf(precioStr,"%.0f",auxPrecio);
			sprintf(idStr,"%d",auxId);
			convertirTipoPasajeroChar(auxTipo, tipoPasajeroStr);
			convertirEstadoVueloChar(auxEstado, EstadoVueloStr);

			retorno = 0;
		}
	}


	return retorno;
}

/// PARA LA FUNCION SORT

int Passenger_criteroNombre(void* pasajeroA, void* pasajeroB)
{
	int retorno = 0;
	char auxNombreA[50];
	char auxNombreB[50];

	Passenger* pAuxA;
	Passenger* pAuxB;

	if(pasajeroA != NULL && pasajeroB != NULL)
	{
		pAuxA = (Passenger*)pasajeroA;
		pAuxB = (Passenger*)pasajeroB;
		if(!Passenger_getNombre(pAuxA, auxNombreA) && !Passenger_getNombre(pAuxB, auxNombreB))
		{
			if(strncmp(auxNombreA,auxNombreB,sizeof(auxNombreA)) > 0)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int Passenger_criteroCodigoVuelo(void* pasajeroA, void* pasajeroB)
{
	int retorno = 0;
	char auxCodigoVueloA[10];
	char auxCodigoVueloB[10];

	Passenger* pAuxA;
	Passenger* pAuxB;

	if(pasajeroA != NULL && pasajeroB != NULL)
	{
		pAuxA = (Passenger*)pasajeroA;
		pAuxB = (Passenger*)pasajeroB;
		if(!Passenger_getCodigoVuelo(pAuxA, auxCodigoVueloA) && !Passenger_getCodigoVuelo(pAuxB, auxCodigoVueloB))
		{
			if(strncmp(auxCodigoVueloA,auxCodigoVueloB,sizeof(auxCodigoVueloA)) > 0)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
int Passenger_criteroPrecio(void* pasajeroA, void* pasajeroB)
{
	int retorno = 0;
	float auxPrecioA;
	float auxPrecioB;

	Passenger* pAuxA;
	Passenger* pAuxB;

	if(pasajeroA != NULL && pasajeroB != NULL)
	{
		pAuxA = (Passenger*)pasajeroA;
		pAuxB = (Passenger*)pasajeroB;
		if(!Passenger_getPrecio(pAuxA, &auxPrecioA) && !Passenger_getPrecio(pAuxB, &auxPrecioB))
		{
			if(auxPrecioA > auxPrecioB)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
int Passenger_criteroEstadoVuelo(void* pasajeroA, void* pasajeroB)
{
	int retorno = 0;
	int auxEstadoA;
	int auxEstadoB;

	Passenger* pAuxA;
	Passenger* pAuxB;

	if(pasajeroA != NULL && pasajeroB != NULL)
	{
		pAuxA = (Passenger*)pasajeroA;
		pAuxB = (Passenger*)pasajeroB;
		if(!Passenger_getEstadoVuelo(pAuxA, &auxEstadoA) && !Passenger_getEstadoVuelo(pAuxB, &auxEstadoB))
		{
			if(auxEstadoA > auxEstadoB)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}









