/*
 * Informes.h
 *

 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "arrayPassenger.h"
#include "vuelos.h"


int ePassenFly_CargaDatos(ePassenger ArrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);
int ePassenFly_printPassenger_Fly(ePassenger Passenger, eVuelo Vuelo);
int ePassenFly_printPassengers_Flys(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);
int ePassenFly_addPassengers(ePassenger *arrayPassenger, int passengerLen,eVuelo ArrayVuelos[], int vuelosLen, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]);
int ePassenFly_PassengerModification(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);




void ePassenFly_Hardcodeo(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen);
int ePassenFly_SortPassengerByCode(ePassenger arrayPassengers[], int passengerLen, eVuelo ArrayVuelos[], int vuelosLen , int order);

#endif /* INFORMES_H_ */
