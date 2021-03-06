/*
 * Biblioteca.c
 *
 *  Created on: Apr 9, 2022
 *      Author: dante
 */

#include "BibliotecaOperaciones.h"

//PEDIR DATOS E IMPRIMIR DATOS

int GetInt (char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
  int retorno = -1;
  int auxiliarInt;
  int retornoScanf;

  if (mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
  {
    printf ("%s", mensaje);
    retornoScanf = scanf ("%d", &auxiliarInt);

    do
    {
      if (retornoScanf != 1 || auxiliarInt > maximo || auxiliarInt < minimo)
      {
	printf ("%s", mensajeError);
	retornoScanf = scanf ("%d", &auxiliarInt);
	reintentos--;
      }
      else
      {
	reintentos = 0;
	*pNumeroIngresado = auxiliarInt;
	retorno = 0;
      }
    }
    while (reintentos > 0);
  }
  return retorno;
}
int GetFloat (char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado)
{
  int retorno = -1;
  float auxiliarInt;
  int retornoScanf;

  if (mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
  {
    printf ("%s", mensaje);
    retornoScanf = scanf ("%f", &auxiliarInt);

    do
    {
      if (retornoScanf != 1 || auxiliarInt > maximo || auxiliarInt < minimo)
      {
	printf ("%s", mensajeError);
	retornoScanf = scanf ("%f", &auxiliarInt);
	reintentos--;
      }
      else
      {
	reintentos = 0;
	*pNumeroIngresado = auxiliarInt;
	retorno = 0;
      }
    }
    while (reintentos > 0);
  }
  return retorno;
}
int VuelosMenu (int *pNumeroIngresado, char mensaje[], int reintentos, int maximo, int minimo, char opcion1[], char opcion2[], char opcion3[], float kilometros, float precioAerolineas,
		float precioLatam)
{
  int auxiliarInt;
  int retornoScanf;
  int retorno;

  retorno = -1;

  puts ("=====================================================================================");

  if (mensaje != NULL && opcion1 != NULL && opcion2 != NULL && opcion3 != NULL && reintentos > 0 && minimo < maximo)
  {
    printf ("%s", mensaje);
    printf ("\n%s(km = %.2f)\n%s (Aerolineas = $ %.2f/Latam = $ %.2f)\n%s\n ", opcion1, kilometros, opcion2, precioAerolineas, precioLatam, opcion3);
    retornoScanf = scanf ("%d", &auxiliarInt);

    do
    {
      if (retornoScanf != 1 || auxiliarInt > maximo || auxiliarInt < minimo)
      {
	printf ("La opcion no es valida ingrese nuevamente:  ");
	retornoScanf = scanf ("%d", &auxiliarInt);
	reintentos--;
      }
      else
      {
	reintentos = 0;
	*pNumeroIngresado = auxiliarInt;
	retorno = 0;
      }
    }
    while (reintentos > 0);
  }
  return retorno;
}
int GetFloatPositivo (char mensaje[], float *pNumeroIngresado, char mensajeError[], int reintentos)
{
  int retorno = -1;
  float auxiliarInt;
  int retornoScanf;

  if (mensaje != NULL && mensajeError != NULL && reintentos > 0 && pNumeroIngresado != NULL)
  {
    printf ("%s", mensaje);
    retornoScanf = scanf ("%f", &auxiliarInt);
    do
    {
      if (retornoScanf != 1 || auxiliarInt < 0)
      {
	printf ("%s", mensajeError);
	retornoScanf = scanf ("%f", &auxiliarInt);
	reintentos--;
      }
      else
      {
	reintentos = 0;
	*pNumeroIngresado = auxiliarInt;
	retorno = 0;
      }
    }
    while (reintentos > 0);
  }

  return retorno;
}
int ImprimirDiferencia (float primerNumero, float segundoNumero, char mensaje[])
{
  float diferencia;
  int retorno;
  retorno = -1;

  if (mensaje != NULL)
  {
    if (primerNumero > segundoNumero)
    {
      diferencia = Restar (primerNumero, segundoNumero);
      retorno = 0;
    }
    else
    {
      diferencia = Restar (segundoNumero, primerNumero);
      retorno = 0;
    }
  }
  printf ("%s%.2f\n\n", mensaje, diferencia);
  return retorno;
}
int ImprimirResultadosVuelos (char mensaje[], float precioVuelo, float gastoDebito, float gastoCredito, float gastoBitcoin, float gastoPorKilometro)
{
  int retorno;

  retorno = -1;

  if (precioVuelo > 0 && gastoDebito > 0 && gastoCredito > 0 && gastoBitcoin > 0 && gastoPorKilometro > 0)
  {
    printf ("\n%s : $ %.2f", mensaje, precioVuelo);
    printf ("\na) Precio con tarjeta de Debito: $ %.2f", gastoDebito);
    printf ("\nb) Precio con tarjeta de Credito: $ %.2f", gastoCredito);
    printf ("\nc) Precio pagando con Bitcoin: %.2f BTC", gastoBitcoin);
    printf ("\nd) Precio unitario (precio por Km): $ %.2f\n", gastoPorKilometro);

    retorno = 0;
  }
  else
  {
    printf ("\nNo se encontradon resultados de %s\n", mensaje);
    retorno = 0;
  }
  return retorno;
}
int CargaForzadaVuelos (float kilometrosPrueba, float precioAerolineasPrueba, float precioLatamPrueba)
{
  int retorno;
  float aerolineasDebito;
  float aerolineasCredito;
  float aerolineasBitcoin;
  float aerolineasKilometros;
  float latamDebito;
  float latamCredito;
  float latamBitcoin;
  float latamPrecioKilometros;

  retorno = 0;

  retorno += CalcularOperacionesVuelos (kilometrosPrueba, precioAerolineasPrueba, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasKilometros);
  retorno += CalcularOperacionesVuelos (kilometrosPrueba, precioLatamPrueba, &latamDebito, &latamCredito, &latamBitcoin, &latamPrecioKilometros);
  printf ("\nKMs Ingresados: %.0f km\n", kilometrosPrueba);
  retorno += ImprimirResultadosVuelos ("Aerolineas", precioAerolineasPrueba, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasKilometros);
  retorno += ImprimirResultadosVuelos ("Latam", precioLatamPrueba, latamDebito, latamCredito, latamBitcoin, latamPrecioKilometros);
  retorno += ImprimirDiferencia (precioAerolineasPrueba, precioLatamPrueba, "\nLa diferencia de precio es de $ ");

  if (retorno != 0)
  {
    puts ("Hubo un error al cargar los datos Forzadamente.");
  }
  return retorno;
}

//CALCULOS

float Sumar (float numero1, float numero2)
{
  float resultado;
  resultado = numero1 + numero2;
  return resultado;
}
float Restar (float numero1, float numero2)
{
  float resultado;
  resultado = numero1 - numero2;
  return resultado;
}
float Multiplicar (float numero1, float numero2)
{
  float resultado;
  resultado = numero1 * numero2;
  return resultado;
}
float Dividir (float divisor, float dividendo)
{
  float cociente;
  if (dividendo != 0)
  {
    cociente = divisor / dividendo;
  }
  else
  {
    cociente = 0;
  }
  return cociente;
}
int CalcularPorReglaSimple (float primerNumero, float segundoNumero, float tercerNumero, float *resultado)
{
  int retorno;
  float resultadoMultiplicacion;
  float resultadoAuxiliar;

  retorno = -1;

  if (primerNumero != 0 && resultado != NULL)
  {
    resultadoMultiplicacion = Multiplicar (tercerNumero, segundoNumero);
    resultadoAuxiliar = Dividir (resultadoMultiplicacion, primerNumero);
    *resultado = resultadoAuxiliar;
    retorno = 0;
  }

  return retorno;
}
int CalcularOperacionesVuelos (float kilometros, float precioVuelo, float *costoDebito, float *costoCredito, float *costoBitcoin, float *costoPorKilometro)
{
  float retorno;
  float descuentoDebito;
  float aumentoCredito;
  float precioBitcoin;
  float precioKilometro;
  float descuento;
  float aumento;
  float bitcoin;

  retorno = 0;
  descuento = 10;
  aumento = 25;
  bitcoin = 4606954.55;

  if (kilometros > 0 && precioVuelo > 0 && costoDebito != NULL && costoCredito != NULL && costoBitcoin != NULL && costoPorKilometro != NULL)
  {
    retorno += CalcularPorReglaSimple (100, precioVuelo, descuento, &descuentoDebito);
    retorno += CalcularPorReglaSimple (100, precioVuelo, aumento, &aumentoCredito);
    retorno += CalcularPorReglaSimple (bitcoin, 1, precioVuelo, &precioBitcoin);
    retorno += CalcularPorReglaSimple (kilometros, precioVuelo, 1, &precioKilometro);

    if (retorno == 0)
    {
      *costoDebito = Restar (precioVuelo, descuentoDebito);
      *costoCredito = Sumar (precioVuelo, aumentoCredito);
      *costoBitcoin = precioBitcoin;
      *costoPorKilometro = precioKilometro;
      retorno = 0;
    }
    else
    {
      puts ("\n\n Hubo un error al calcular los datos.");
      retorno = -1;
    }
  }
  else
  {
    puts ("No se Ingresaron o faltan datos.");
  }

  return retorno;
}

