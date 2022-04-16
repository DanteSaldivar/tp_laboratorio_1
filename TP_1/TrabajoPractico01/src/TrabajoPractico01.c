/*
 ============================================================================

 * Programa: Calculadora de costos Agencia de viaje
 *
 * Objetivo:
   Al ingresar por cada vuelo los KMs totales y el precio total del mismo,
   mostrar las diferences opciones de pagos a sus clientes.
 *
 *
 *
 * Autor : Dante Saldivar

 Division 1-H
 ============================================================================
 */

#include "BibliotecaOperaciones.h"
#define PRICE_TEST_AEROLINEAS 162965
#define PRICE_TEST_LATAM 159339
#define KILOMETERS_TEST	7090

int main (void)
{
  int opcionElegida;
  int numeroDeError;
  float kilometrosIngresados;
  float precioAerolineas;
  float precioLatam;
  float aerolineasDebito;
  float aerolineasCredito;
  float aerolineasBitcoin;
  float aerolineasPrecioKilometros;
  float latamDebito;
  float latamCredito;
  float latamBitcoin;
  float latamPrecioKilometros;

  kilometrosIngresados = 0;
  precioAerolineas = 0;
  precioLatam = 0;
  numeroDeError = 0;

  do
  {
    numeroDeError = VuelosMenu (&opcionElegida, "\t\t\t Menu Principal\n", 3, 6, 1, "1-Ingresar Kilometros", "2-Ingresar Precio de Vuelos",
				"3-Calcular Todos los costos\n4-Informar Resultados\n5-Carga Forzada\n6-Salir", kilometrosIngresados, precioAerolineas, precioLatam);

    switch (opcionElegida)
    {
      case 1:
	numeroDeError = GetFloatPositivo ("Ingrese los Kilometros: ", &kilometrosIngresados, "La distancia no es valida, reintente: ", 3);
	break;
      case 2:
	numeroDeError += GetFloatPositivo ("Ingrese el precio de Aerolineas: ", &precioAerolineas, "El valor ingresado no es valido: ", 3);
	numeroDeError += GetFloatPositivo ("Ingrese el precio de Latam: ", &precioLatam, "El valor ingresado no es valido: ", 3);
	break;
      case 3:
	numeroDeError += CalcularOperacionesVuelos (kilometrosIngresados, precioAerolineas, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasPrecioKilometros);
	numeroDeError += CalcularOperacionesVuelos (kilometrosIngresados, precioLatam, &latamDebito, &latamCredito, &latamBitcoin, &latamPrecioKilometros);
	break;
      case 4:
	numeroDeError += ImprimirResultadosVuelos ("Aerolineas", precioAerolineas, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasPrecioKilometros);
	numeroDeError += ImprimirResultadosVuelos ("Latam", precioLatam, latamDebito, latamCredito, latamBitcoin, latamPrecioKilometros);
	if (precioAerolineas != 0 || precioLatam != 0)
	{
	  ImprimirDiferencia (precioAerolineas, precioLatam, "\nLa diferencia de precio es: $ ");
	}
	break;
      case 5:
	numeroDeError = CargaForzadaVuelos (KILOMETERS_TEST, PRICE_TEST_AEROLINEAS, PRICE_TEST_LATAM);
	break;
      default:
	puts ("=====================================================================================");
	break;
    }

    if (numeroDeError != 0)
    {
      puts ("\n\n\t\tOcurrio un Error, un dato no pudo ser validado. Reincie el programa.");
      break; 		// "Para evitar Que entre en bucle para siempre al ingresar una Letra en las distintas funciones."
    }
  }
  while (opcionElegida != 5 && opcionElegida != 6);
}
