/*
 * Biblioteca.h
 *
 *  Created on: Apr 9, 2022
 *      Author: dante
 */

#ifndef BIBLOTECAOPERACIONES_H_
#define BIBLOTECAOPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Pide un numero entero y realiza las comprovaciones
 * @param mensaje Guarda el mensaje que queres mostrar al usuario
 * @param reintentos La cantidad maxima de veces que se puede repetir un error
 * @param minimo El numero minimo que se puede ingresar
 * @param maximo El numero maximo que se puede ingresar
 * @param mensajeError	mensaje que se muestra en caso de error
 * @param pNumeroIngresado puntero donde enviara la variable pedida
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int GetInt (char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);


/**
 * \brief Variable de GetFloat, solo pide y obtiene numeros positivos
 * @param mensaje Mensaje dirigido al ususario
 * @param pNumeroIngresado Puntero donde se guarda el numero ingresado
 * @param mensajeError	mensaje que se muestra en caso de error
 * @param reintentos cantidad de reintentos en caso de error
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int GetFloatPositivo (char mensaje[], float *pNumeroIngresado, char mensajeError[], int reintentos);

/**
 * \brief Pide y obtiene un numero Float
 * @param mensaje Mensaje dirigido al Usuario
 * @param reintentos eintentos La cantidad maxima de veces que se puede repetir un error
 * @param minimo minimo El numero minimo que se puede ingresar
 * @param maximo El numero maximo que se puede ingresar
 * @param mensajeError Mensaje que se muestra en caso de error
 * @param pNumeroIngresado Puntero donde se guarda el numero ingresado
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int GetFloat (char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);

/**
 * \brief Funcion que muestra un Menu y pide datos
 * @param pNumeroIngresado Puntero donde se guarda la opcion elegida
 * @param mensaje muestra el mensaje principal del menu
 * @param reintentos cantidad maxima que se puede repetir un error
 * @param maximo El numero minimo que se puede ingresar
 * @param minimo El numero maximo que se puede ingresar
 * @param opcion1 Primera opcion del menu (Se muestra con un dato variable)
 * @param opcion2 Segunda opcion del menu (Se muestra con un dato variable)
 * @param opcion3 Tercera opcion del menu (Se muestra con un dato variable)
 * @param kilometros variable que acompaña la opcion 1
 * @param precioAerolineas variable que acompaña la opcion 2
 * @param precioLatam variable que acompaña la opcion 3
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */

int VuelosMenu (int *pNumeroIngresado, char mensaje[], int reintentos, int maximo, int minimo, char opcion1[], char opcion2[], char opcion3[],
		float kilometros, float precioAerolineas, float precioLatam);

/**
 * \brief Funcion que realiza una suma
 * @param numero1 Primer numero Ingresado, se espera un float
 * @param numero2 Segundo numero Ingreado, se espera un float
 * @return El resultado de la cuenta
 */
float Sumar (float numero1, float numero2);

/**
 * \brief Funcion que realiza una resta
 * @param Numero1 Primer numero Ingresado, se espera un float
 * @param Numero2 Segundo numero Ingresado, se espera un float
 * @return El resultado de la cuenta
 */
float Restar (float numero1, float numero2);

/**
 * \brief Funcion que realiza una multiplicacion
 * @param numero1 Primer numero Ingresado, se espera un float
 * @param numero2 Segundo numero Ingresado, se espera un float
 * @return El resultado de la cuenta
 */
float Multiplicar (float numero1, float numero2);

/**
 * \brief Funcion que realiza una division, no calcula una division por 0
 * @param divisor El numero que se desea dividir
 * @param dividendo el numero por el cual se va a dividir
 * @return El resultado de la division
 */
float Dividir (float divisor, float dividendo);

/**
 * \brief Funcion que recibe los datos del vuelo y devuelve su costos en
 * 	  varios medios de pago(Sin los datos ingresados previamente no comienza)
 *
 * @param kilometros Distancia del viaje que ingreso el usuario previamente
 * @param precioVuelo Precio total del viaje
 * @param costoDebito variable donde se guarda el precio con Tarjeta de Debito
 * @param costoCredito variable donde se guarda el precio con Tarjeta de Credito
 * @param costoBitcoin variable donde se guarda el precio en Bitcoins
 * @param costoPorKilometro variable donde se guarda el precio unitario por Kilometro
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 *
 * * * "En caso que haya un Error en uno o varios calculos dentro, el numero de errores se suman
 *    	y devuelve un mensaje de Error."
 */
int CalcularOperacionesVuelos (float kilometros, float precioVuelo, float *costoDebito, float *costoCredito, float *costoBitcoin,
			       float *costoPorKilometro);

/**
 * \brief Funcion que aplica la regla de 3 simple
 * @param primerNumero Es el numero A en la regla
 * @param segundoNumero Es el numero B en la regla
 * @param tercerNumero Es el numero C en la regla
 * @param resultado variable donde se guarda el resultado de los calculos
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int CalcularPorReglaSimple (float primerNumero, float segundoNumero, float tercerNumero, float *resultado);

/**
 * \brief Funcion que solo imprime los resultados de la funcion CalcularOperacionesVuelos
 * @param mensaje Viariable que guarda el nombre de la Aerolinea
 * @param precioVuelo Variable que guarda el precio del vuelo Ingresado previamente
 * @param gastoDebito Variable que guarda el precio con Tarjeta de Debito
 * @param gastoCredito Variable que guarda el precio con Tarjeta de Credito
 * @param gastoBitcoin Variable que guarda el precio en bitcoins
 * @param gastoPorKilometro variable que guarda el precio unitario por Kilometro
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 *
 *  * * "Si el precioDeVuelo o demas variables son iguales a 0, no muestra los resultados,
 *  	 sino un mensaje/"
 */
int ImprimirResultadosVuelos (char mensaje[],float precioVuelo, float gastoDebito, float gastoCredito, float gastoBitcoin, float gastoPorKilometro);

/**
 * \brief Funcion que Imprime una diferencia, muestra el resultado en positivo
 * @param primerNumero Primer numero Ingresado, se espera un float
 * @param segundoNumero Segundo numero Ingresado, se espera un float
 * @param mensaje Mensaje que acompaña al resultado de la diferencia
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int ImprimirDiferencia (float primerNumero, float segundoNumero, char mensaje[]);

/**
 * \brief Funcion que Carga forzadamente los datos del programa, llama a la funcion CalcularOperacionesvuelos
 * 	  y a la funcion ImprimirResultadosVuelo
 * @param kilometrosPrueba Es la variable de distancia escito por defecto
 * @param precioAerolineasPrueba Es el precio de 'Aerolineas' por defecto
 * @param precioLatamPrueba Es el precio de 'Latam' por defecto
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int CargaForzadaVuelos(float kilometrosPrueba, float precioAerolineasPrueba, float precioLatamPrueba);


#endif /* BIBLIOTECA_H_ */
