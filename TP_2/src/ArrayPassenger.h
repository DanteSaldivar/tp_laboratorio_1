#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "Biblioteca.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define MAX_TAM_CHAR 51
#define MAX_FLY_CODE 10

typedef struct{
	int idPassenger;
	char name[MAX_TAM_CHAR];
	char lastname[MAX_TAM_CHAR];
	float price;
	int typePassenger;
	int FK_Vuelo;
	int isEmpty;

}ePassenger;


/***
 * \brief Se encarga de cambiar el parametro isEmpty a libre
 * @param arrayPassengers Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 */
void ePassenger_initPassengers(ePassenger arrayPassengers[], int tam);


/***
 * \brief Se encarga de buscar en el array el index donde isEmpty se encuentra con valor 'LIBRE'
 * @param arrayPassengers arrayPassengers Array con los contenidos a modificar y trabajar
 * @param tam  Tamanio del Array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int ePassenger_ObtenerIndexLibre(ePassenger arrayPassengers[], int tam);

/***
 *\brief Busca un index, dentro del array, asosiado al ID
 * @param arrayPassengers Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @param ID Valor que identifica los elementos del array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int ePassenger_FindPassengerById(ePassenger arrayPassengers[], int tam, int ID);


/***
 * \brief Imprime todos los campos de una variable
 * @param Passenger Es una variable terminada
 */
void ePassenger_PrintOnePassenger(ePassenger Passenger);



/***
 * \brief Imprime todos los campos de los distintos elementos de un array
 * 			se puede elegir un estado en concreto
 * @param arrayPassengers  Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @param estado valor que determina si el elemento se encuentra 'libre', 'ocupado', 'baja'
 * @return Retorna el total dependiendo del estado al mostar los datos o un -1 si no hay nada que mostrar
 */
int ePassenger_PrintPassengers(ePassenger arrayPassengers[], int lenght);


/***
 * \brief Se encarga de pedir los datos que se quieran ingrear en un determinado elemento
 * @return Retorna los datos de los campos de un elemento
 */
ePassenger ePassenger_CargarDatos(void);


/***
 * \brief Hace una baja logica de un elemento que decida el usuario y cambiando su estado a 'BAJA'
 * @param arrayPassengers Array con los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int ePassenger_RemovePassenger(ePassenger arrayPassengers[], int tam);


/***
 * \brief Selecciona un elemento del Array que decida el usuario y modifica los campos seleccionados
 * @param arrayPassengerscon los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int ePassenger_Modificacion(ePassenger arrayPassengers[], int tam);


/**
 * \brief Se encarga de Calcular el total promedio de gastos de los pasajeros e imprime los superiores al promedio
 * @param arrayPassengers Cadena que guarda a los pasajeros
 * @param passengerLen	Tamanio de la Cadena
 * @return Retorna un -1 si hubo un error, o un 0 si salio bien
 */
int ePassenger_Promedios(ePassenger arrayPassengers[], int passengerLen);

/* Ordenamiento*/


/***
 * \brief Se encarga de ordenar los elementos de un array dependiendo del criterio elegido
 * @param arrayPassengerss arrayPassengerscon los contenidos a modificar y trabajar
 * @param tam Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int ePassenger_SortPassenger(ePassenger arrayPassengerss[], int tam, int criterio);




#endif
