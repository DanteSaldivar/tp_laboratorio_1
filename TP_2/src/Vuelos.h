#ifndef VUELOS_H_
#define VUELOS_H_
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

#define ACTIVO -3
#define VOLANDO -2
#define INACTIVO -4

#define MAX_FLY_CODE 10

typedef struct{
	int idVuelo;

	int	flightStatus;
	char flyCode[MAX_FLY_CODE];
}eVuelo;


/***
 * \brief Se encarga de cambiar el parametro flightStatus a libre
 * @param arrayVueloss Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 */
void eVuelo_Inicializar(eVuelo arrayDeVuelo[], int tam);


/***
 * \brief Se encarga de buscar en el array el index donde flightStatus se encuentra con valor 'LIBRE'
 * @param arrayVueloss arrayVueloss Array con los contenidos a modificar y trabajar
 * @param tam  Tamanio del Array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eVuelo_ObtenerIndexLibre(eVuelo arrayVueloss[], int tam);

/***
 *\brief Busca un index, dentro del array, asosiado al ID
 * @param arrayVueloss Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @param ID Valor que identifica los elementos del array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eVuelo_BuscarIndexPorID(eVuelo arrayVueloss[], int tam, int ID);


/***
 * \brief Imprime todos los campos de una variable
 * @param Vuelos Es una variable terminada
 */
void eVuelo_MostrarUno(eVuelo Vuelos);


/***
 * \brief Imprime todos los campos de los distintos elementos de un array
 * 			se puede elegir un estado en concreto
 * @param arrayVueloss  Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @param estado valor que determina si el elemento se encuentra 'INACTIVO', 'VOLANDO', 'ACTIVO'
 * @return Retorna el total dependiendo del estado al mostar los datos o un -1 si no hay nada que mostrar
 */
int eVuelo_ImprimirVuelosPorEstado(eVuelo arrayVuelos[], int tam, int estado);

/***
 * \brief Se encarga de pedir los datos que se quieran ingrear en un determinado elemento
 * @return Retorna los datos de los campos de un elemento
 */
eVuelo eVuelo_CargarDatos(void);



/***
 * \brief Se encarga de ordenar los elementos de un array dependiendo del criterio elegido
 * @param arrayDeVuelos arrayVuelosscon los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eVuelo_Sort(eVuelo arrayDeVuelos[], int tam, int criterio);


/***
 * \brief Recibe un codigo de vuelo, compara con otros codigos de Aviones ya registrados
 * @param arrayVuelos array de vuelos a trabajar
 * @param lenght tamanio de la array
 * @param cadena Variable que recibe el codigo de vuelo
 * @return retorna un -1 si no encontro ninguna coincidencia, o el ID del Vuelo coincidente
 */

int eVuelo_ComprobacionCodigo(eVuelo* arrayVuelos, int lenght,char* cadena);

#endif
