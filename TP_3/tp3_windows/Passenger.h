/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[5];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger*Passenger_newParametros(char *idStr, char *nombreStr,char *apellidoStr,char *precioStr,char *codigoVueloStr,char *tipoPasajeroStr,char *EstadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger *this, int EstadoVuelo);
int Passenger_getEstadoVuelo(Passenger *this, int *EstadoVuelo);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);


void Passenger_ImprimirUno(Passenger *this);
Passenger* Passenger_addPassenger(void);
void* Passenger_getById(LinkedList* pArrayListPassenger, int id);
int Passenger_editPassenger(Passenger *this);
int Passenger_parametrosChar(Passenger* this,char *idStr, char *nombreStr, char *apellidoStr, char *precioStr, char *codigoVueloStr, char *tipoPasajeroStr, char *EstadoVueloStr);

///PARA FUNCION SORT

int Passenger_criteroNombre(void* pasajeroA, void* pasajeroB);
int Passenger_criteroCodigoVuelo(void* pasajeroA, void* pasajeroB);
int Passenger_criteroPrecio(void* pasajeroA, void* pasajeroB);
int Passenger_criteroEstadoVuelo(void* pasajeroA, void* pasajeroB);




#endif /* PASSENGER_H_ */
