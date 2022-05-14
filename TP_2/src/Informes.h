/*
 * Informes.h
 *

 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "arrayPassenger.h"
#include "vuelos.h"

/**
 * \brief Carga los datos no genericos para el alta
 * @param ArrayPassengers Array de pasajeros a trabajar
 * @param passengerLen Tamanio del array
 * @param ArrayVuelos array de Vuelos a trabajar
 * @param vuelosLen tamanio del array
 * @return devuelve un -1 si hubo un error, un 0 si no hubo errores
 */
int ePassenFly_CargaDatos(ePassenger ArrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);


/***
 * \brief Imprime un solo pasajero que reciba
 * @param Passenger es la variable tipo ePassenger
 * @param Vuelo es la variable tipo eVuelo
 * @return Retorna un -1 si hubo un error, un 0 si no hubo errores
 */
int ePassenFly_printPassenger_Fly(ePassenger Passenger, eVuelo Vuelo);


/***
 * \breif Recibe e imprime un array de Pasajeros
 * @param arrayPassengers  es el array tipo ePassenger
 * @param passengerLen es el tamanio del array
 * @param ArrayVuelos es el array tipo eVuelo
 * @param vuelosLen es el tamanio del array
 * @return Retorna un -1 si hubo un error, un 0 si no hubo errores
 */
int ePassenFly_printPassengers_Flys(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);


/***
 * \brief Funcion que Carga los datos del Pasajero
 * @param ArrayPassengers Es el array tipo ePassenger
 * @param passengerLen Es el tamanio del array
 * @param ArrayVuelos Es el array tipo eVuelo
 * @param vuelosLen Es el tamanio del array
 * @param id Es el id que recibe la variable
 * @param name Nombre del Pasajero
 * @param lastName Apellido del pasajero
 * @param price Precio del vuelo
 * @param typePassenger Tipo de pasajero
 * @param flyCode Codigo del vuelo
 ** @return Retorna un -1 si hubo un error, un 0 si no hubo errores
 */
int ePassenFly_addPassengers(ePassenger *arrayPassenger, int passengerLen,eVuelo ArrayVuelos[], int vuelosLen, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]);


/***
 * \brief Se encarga Elegir y modificar los campos de la variable
 * @param ArrayPassengers Es el array tipo ePassenger
 * @param passengerLen Es el tamanio del array
 * @param ArrayVuelos Es el array tipo eVuelo
 * @param vuelosLen Es el tamanio del array
 * @return Retorna un -1 si hubo un error, un 0 si no hubo errores
 */
int ePassenFly_PassengerModification(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);


/***
 * \brief Es la funcion que Hardcodea los datos Como prueba
 * @param ArrayPassengers Es el array tipo ePassenger
 * @param passengerLen Es el tamanio del array
 * @param ArrayVuelos Es el array tipo eVuelo
 * @param vuelosLen Es el tamanio del array
 */
void ePassenFly_Hardcodeo(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);

/***
 * \brief Se encarga de Ordenar el Array por codigo de Vuelo utilizando los array de Vuelo (((FUNCION INACABADA)))
* @param ArrayPassengers Es el array tipo ePassenger
 * @param passengerLen Es el tamanio del array
 * @param ArrayVuelos Es el array tipo eVuelo
 * @param vuelosLen Es el tamanio del array
 * @param order El orden que decidas darle Ascendente o Descendente
 * @return
 */
int ePassenFly_SortPassengerByCode(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen , int order);

#endif /* INFORMES_H_ */
